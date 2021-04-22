#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "minerprocess.h"
#include "helpdialog.h"
#include "nvidianvml.h"
#include "nvocdialog.h"
#include "nanopoolapi.h"
#include "hashratecharview.h"
#include "mysql.h"
#include "constants.h"

#include "structures.h"

#include <QDebug>
#include <QMessageBox>
#include <QMenu>
#include <QMenuBar>
#include <QCloseEvent>
#include <QLibrary>
#include <QDir>
#include <QFileDialog>
#include <QDateTimeAxis>
#include <QBarCategoryAxis>
#include <QScrollBar>
#include <QFrame>
#include <QtSql/QSqlDatabase>
#include <QMetaType>

#define MINERPATH           "minerpath"
#define MINERARGS           "minerargs"
#define AUTORESTART         "autorestart"
#define MAX0MHS             "max0mhs"
#define RESTARTDELAY        "restartdelay"
#define ZEROMHSDELAY        "zeromhsdelay"
#define AUTOSTART           "autostart"
#define DISPLAYSHAREONLY    "shareonly"
#define DELAYNOHASH         "delaynohash"
#define COIN                "coin"
#define CORE                "core"
#define POOL                "pool"
#define WALLET              "wallet"
#define WORKER              "worker"

#ifdef NVIDIA
#define NVIDIAOPTION        "nvidia_options"
#define NVOCOPTION          "nvidia_oc_options"

#endif

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    _isMinerRunning(false),
    _isStartStoping(false),
    _errorCount(0),
    _nano(Q_NULLPTR)
{

    _settings = new QSettings(QString(QDir::currentPath() + QDir::separator() + "minerlamp.ini"), QSettings::IniFormat);

    _process = new MinerProcess(_settings);
    _gpusinfo = new QList<GPUInfo>();
    _gpuInfoList = new QList<QWidget * >();
    _mysqlProcess = new MYSQLcon();
    _mysqlProcess->start();

    ui->setupUi(this);

    // debug box test
    _process->setLogControl(ui->textEdit);

    connect(_process, &MinerProcess::emitStarted, this, &MainWindow::onMinerStarted);
    connect(_process, &MinerProcess::emitStoped, this, &MainWindow::onMinerStoped);

    // update hash rate
    connect(_process, &MinerProcess::emitHashRate, this, &MainWindow::onHashrate);
    connect(_process, &MinerProcess::emitError, this, &MainWindow::onError);




    _nvapi = new nvidiaAPI();

    bool nvDll = true;
    QLibrary lib("nvml.dll");
    if (!lib.load())
    {
        lib.setFileName("C:\\Program Files\\NVIDIA Corporation\\NVSMI\\nvml.dll");
        if(!lib.load())
        {
            ui->textEdit->append("Cannot find nvml.dll. NVAPI monitoring won't work.");
            ui->textEdit->append("Be sure to have the latest nvidia drivers.");
            nvDll = false;
        }
    }

    if(nvDll)
    {
        // retrieve gpu info to panel
        _nvMonitorThrd = new nvMonitorThrd(this);
        connect(_nvMonitorThrd, &nvMonitorThrd::gpuInfoSignal, this, &MainWindow::onNvMonitorInfo);

        qRegisterMetaType<QList<GPUInfo>>("QList<GPUInfo>");
        connect(_nvMonitorThrd, &nvMonitorThrd::gpusInfoSignalRefresh, this, &MainWindow::onGpusInfoRecieved);
        _nvMonitorThrd->start();

        if(_nvapi->libLoaded())
        {

        }

    }
    else
    {
        ui->groupBoxNvidia->hide();
    }

    QLibrary adl("atiadlxx");
    if(!adl.load())
    {
        ui->groupBoxAMD->hide();

    }
    else
    {
        adl.unload();

        _amdMonitorThrd = new amdMonitorThrd(this);
        connect(_amdMonitorThrd, &amdMonitorThrd::gpuInfoSignal, this, &MainWindow::onAMDMonitorInfo);
        _amdMonitorThrd->start();

    }

    loadParameters();

    setupToolTips();

    createActions();

    createTrayIcon();

    setIcon();

    connect(_trayIcon, &QSystemTrayIcon::activated, this, &MainWindow::iconActivated);

    _trayIcon->show();

    setupEditor();

    _chart = new QChart();
    _chartTemp = new QChart();
    _chartHistory = new QChart();

    // customize chart background
    QLinearGradient backgroundGradient;
    backgroundGradient.setStart(QPointF(0, 0));
    backgroundGradient.setFinalStop(QPointF(0, 1));
    backgroundGradient.setColorAt(0.0, QRgb(0x909090));
    backgroundGradient.setColorAt(1.0, QRgb(0x101010));
    backgroundGradient.setCoordinateMode(QGradient::ObjectBoundingMode);

    _chart->setAnimationOptions(QChart::SeriesAnimations);
    _chart->setBackgroundBrush(backgroundGradient);

    _chart->setBackgroundVisible(false);
    _chart->legend()->hide();

    //set the color of the graph
    QPen pen(QColor(255, 165, 0));
    pen.setWidth(2);

    _series = new QLineSeries();
    _series->setPen(pen);

    _series->append(QDateTime::currentDateTime().toMSecsSinceEpoch(),0);
    _chart->addSeries(_series);
    _chart->createDefaultAxes();

    _axisX = new QDateTimeAxis;
    // set graph interval number
    _axisX->setTickCount(5);
    _axisX->setFormat("hh:mm:ss");
    _axisX->setTitleText("Time");
    _chart->axisY()->setTitleText("HR in MH/s");
    _chart->axisY()->setRange(0, 1);

    QFont labelsFont;
    labelsFont.setPixelSize(14);
    _axisX->setTitleFont(labelsFont);
    _chart->axisY()->setTitleFont(labelsFont);
    _axisX->setGridLineVisible(false);
    _chart->axisY()->setGridLineVisible(false);

    // customize axis label colors
    QBrush axisBrush(Qt::white);
    _axisX->setLabelsBrush(axisBrush);
    _chart->axisY()->setLabelsBrush(axisBrush);

    _axisX->setTitleBrush(QBrush(Qt::blue));
    _chart->axisY()->setTitleBrush(QBrush(Qt::yellow));

    _chart->setAxisX(_axisX);
    _series->attachAxis(_axisX);
    _axisX->setRange(QDateTime::currentDateTime(), QDateTime::currentDateTime().addSecs(10));


    ui->graphicsView->setChart(_chart);

    // graph will be drawn every time interval
    connect(&_hrChartTimer, &QTimer::timeout, this, &MainWindow::onHrChartTimer);

    // set time interval
    _hrChartTimer.setInterval(1000);
    _hrChartTimer.start();


    // customize the temperature diagram
    // customize chart background
    QLinearGradient backgroundGradient_temp;
    backgroundGradient_temp.setStart(QPointF(0, 0));
    backgroundGradient_temp.setFinalStop(QPointF(0, 1));
    backgroundGradient_temp.setColorAt(0.0, QRgb(0x909090));
    backgroundGradient_temp.setColorAt(1.0, QRgb(0x101010));
    backgroundGradient_temp.setCoordinateMode(QGradient::StretchToDeviceMode);

    _chartTemp->setAnimationOptions(QChart::SeriesAnimations);
    _chartTemp->setBackgroundBrush(backgroundGradient_temp);
    _chartTemp->setBackgroundVisible(false);
    _chartTemp->legend()->hide();


    //set the color of the graph
    QPen penTemp(QColor(255, 165, 0));
    penTemp.setWidth(2);

    _seriesTemp = new QLineSeries();
    _seriesTemp->setPen(penTemp);

    _seriesTemp->append(QDateTime::currentDateTime().toMSecsSinceEpoch(),0);
    _chartTemp->addSeries(_seriesTemp);
    _chartTemp->createDefaultAxes();

    _axisXTemp = new QDateTimeAxis;
    // set graph interval number
    _axisXTemp->setTickCount(5);
    _axisXTemp->setFormat("hh:mm:ss");
    _axisXTemp->setTitleText("Time");
    _chartTemp->axisY()->setTitleText("Temp in degree");
    _chartTemp->axisY()->setRange(0, 1);

    QFont labelsFont_temp;
    labelsFont_temp.setPixelSize(14);
    _axisXTemp->setTitleFont(labelsFont_temp);
    _chartTemp->axisY()->setTitleFont(labelsFont_temp);

    // customize axis label colors
    QBrush axisBrush_temp(Qt::white);
    _axisXTemp->setLabelsBrush(axisBrush_temp);
    _chartTemp->axisY()->setLabelsBrush(axisBrush_temp);

    _axisXTemp->setTitleBrush(QBrush(Qt::blue));
    _chartTemp->axisY()->setTitleBrush(QBrush(Qt::yellow));
    _axisXTemp->setGridLineVisible(false);
    _chartTemp->axisY()->setGridLineVisible(false);

    _chartTemp->setAxisX(_axisXTemp);
    _seriesTemp->attachAxis(_axisXTemp);
    _axisXTemp->setRange(QDateTime::currentDateTime(), QDateTime::currentDateTime().addSecs(10));


    ui->graphicsViewTemp->setChart(_chartTemp);

    // graph will be drawn every time interval
    connect(&_tempChartTimer, &QTimer::timeout, this, &MainWindow::onTempChartTimer);

    // initialize pie chart
    initializePieChart();

    // set time interval
    _tempChartTimer.setInterval(1000);
    _tempChartTimer.start();


    ui->lcdNumberHashRate->display("0.00");

    if(ui->checkBoxAutoStart->isChecked())
    {
        _starter = new autoStart(this);
        connect(_starter, SIGNAL(readyToStartMiner()), this, SLOT(onReadyToStartMiner()));
        _starter->start();
    }

    ui->pushButtonShowHideLog->setChecked(false);
    ui->pushButtonPool->setChecked(false);
    ui->groupBoxPools->hide();
    ui->textEdit->hide();

    ui->checkBoxAutoShowDeviceInfo->setChecked(false);
    ui->groupBoxDevicesInfo->hide();


    int pos = ui->lineEditArgs->text().indexOf("-O ");
    if(pos > 0)
        ui->lineEditAccount->setText(ui->lineEditArgs->text().mid(pos + 3
                                                                  , ui->lineEditArgs->text().indexOf(" 0x") > 0 ? 42 : 40));


    //ui->debugBox->append("hello 1");

    initializeConstants();
    ui->groupBoxHistoryInfo->hide();
    ui->dateTimeEditHistoryStartTime->hide();
    ui->dateTimeEditHistoryEndTime->hide();
    ui->pushButtonSearchHistory->hide();
    ui->spinBoxHistoryDeviceNum->hide();
    ui->labelHistoryDeviceNum->hide();

    ui->dateTimeEditHistoryStartTime->setDateTime(QDateTime::currentDateTime());
    ui->dateTimeEditHistoryEndTime->setDateTime(QDateTime::currentDateTime().addDays(5));


}

MainWindow::~MainWindow()
{
    saveParameters();

    _process->stop();
    if(_mysqlProcess && _mysqlProcess->isRunning())
        _mysqlProcess->terminate();

    if(_nvapi != Q_NULLPTR)
        delete _nvapi;


    delete _process;
    delete _settings;
    delete _gpuInfoList;
    delete _gpusinfo;
    delete ui;
    _mysqlProcess->terminate();
    delete _mysqlProcess;

    for(int i=_seriesHistory.size()-1; i>=0; i--){
        QLineSeries * tempPtr = _seriesHistory.at(i);
        _seriesHistory.removeAt(i);
        delete tempPtr;
    }
}


void MainWindow::setComboIndex(QComboBox * comboBox, QString key){
    int comboIdx = comboBox->findText(key);
    if(comboIdx != -1){
        comboBox->setCurrentIndex(comboIdx);
    }
    qDebug() << "fetch index: " << comboIdx << "\t" << key;
}


Coin* MainWindow::AddCoin(QString coin_name)
{
    Coin* coin = new Coin(coin_name);
    map_coins[coin_name] = coin;
    return coin;
}

Pool* MainWindow::AddPool(QString pool_name, Coin* coin, const QString& cmd)
{
    Pool* pool = nullptr;
    if (map_pools.contains(pool_name))
    {
        pool = map_pools[pool_name];
    }
    else
    {
        pool = new Pool(pool_name);
        map_pools[pool_name] = pool;
    }
    coin->AddPool(pool, cmd);
    return pool;
}

Pool* MainWindow::AddPool(QString pool_name, QString coin_name, const QString& cmd)
{
    Pool* pool = nullptr;
    if (!map_coins.contains(coin_name))
    {
        qDebug() << "No coin name: " << coin_name << endl;
        return pool;
    }
    Coin* coin = map_coins[coin_name];
    if (map_pools.contains(pool_name))
    {
        pool = map_pools[pool_name];
    }
    else
    {
        pool = new Pool(pool_name);
        map_pools[pool_name] = pool;
    }
    coin->AddPool(pool, cmd);
    return pool;
}


Core* MainWindow::AddCore(QString core_name, const QString& path, const QString& api, Coin* coin, const QString& cmd)
{
    Core* core = nullptr;
    if (map_cores.contains(core_name))
    {
        core = map_cores[core_name];
    }
    else
    {
        core = new Core(core_name, path, api);
        map_cores[core_name] = core;
    }
    coin->AddCore(core, cmd);
    return core;
}

Core* MainWindow::AddCore(QString core_name, const QString& path, const QString& api, QString coin_name, const QString& cmd)
{
    Core* core = nullptr;
    if (!map_coins.contains(coin_name))
    {
        qDebug() << "No coin name: " << coin_name << endl;
        return core;
    }
    Coin* coin = map_coins[coin_name];
    if (map_cores.contains(core_name))
    {
        core = map_cores[core_name];
    }
    else
    {
        core = new Core(core_name, path, api);
        map_cores[core_name] = core;
    }
    coin->AddCore(core, cmd);
    return core;
}


void MainWindow::initializeConstants()
{

    // Future Improvement:
    // Separate code and data
    // Move the constant strings in the code to a file (possibly database)
    // In the code, use a loop to read the data file
    // and do the same job

    Coin* eth = AddCoin("ETH");

    AddPool("ethermine", eth, eth_ethermine);
    AddPool("sparkpool", eth, eth_sparkpool);
    AddPool("f2pool", eth, eth_f2pool);
    AddPool("beepool", eth, eth_beepool);
    AddPool("nanopool", eth, eth_nanopool);
    AddPool("herominers", eth, eth_herominers);
    AddPool("nicehash", eth, eth_nicehash);

    AddCore("NBMiner", path_nbminer, api_nbminer, eth, cmd_nbminer_eth);
}


void MainWindow::loadParameters()
{
    ui->lineEditMinerPath->setText(_settings->value(MINERPATH).toString());
    ui->lineEditArgs->setText(_settings->value(MINERARGS).toString());
    ui->groupBoxWatchdog->setChecked(_settings->value(AUTORESTART).toBool());
    ui->spinBoxMax0MHs->setValue(_settings->value(MAX0MHS).toInt());
    ui->spinBoxDelay->setValue(_settings->value(RESTARTDELAY).toInt());
    ui->spinBoxDelay0MHs->setValue(_settings->value(ZEROMHSDELAY).toInt());
    ui->checkBoxAutoStart->setChecked(_settings->value(AUTOSTART).toBool());
    ui->checkBoxOnlyShare->setChecked(_settings->value(DISPLAYSHAREONLY).toBool());
    ui->spinBoxDelayNoHash->setValue(_settings->value(DELAYNOHASH).toInt());
    setComboIndex(ui->comboBoxCoin, _settings->value(COIN).toString());
    setComboIndex(ui->comboBoxCore, _settings->value(CORE).toString());
    setComboIndex(ui->comboBoxPool, _settings->value(POOL).toString());
    ui->lineEditWallet->setText(_settings->value(WALLET).toString());
    ui->lineEditWorker->setText(_settings->value(WORKER).toString());

    _process->setShareOnly(_settings->value(DISPLAYSHAREONLY).toBool());
    _process->setRestartOption(_settings->value(AUTORESTART).toBool());
}


void MainWindow::saveParameters()
{
    _settings->setValue(MINERPATH, ui->lineEditMinerPath->text());
    _settings->setValue(MINERARGS, ui->lineEditArgs->text());
    _settings->setValue(AUTORESTART, ui->groupBoxWatchdog->isChecked());
    _settings->setValue(MAX0MHS, ui->spinBoxMax0MHs->value());
    _settings->setValue(RESTARTDELAY, ui->spinBoxDelay->value());
    _settings->setValue(ZEROMHSDELAY, ui->spinBoxDelay0MHs->value());
    _settings->setValue(AUTOSTART, ui->checkBoxAutoStart->isChecked());
    _settings->setValue(DISPLAYSHAREONLY, ui->checkBoxOnlyShare->isChecked());
    _settings->setValue(DELAYNOHASH, ui->spinBoxDelayNoHash->value());
    _settings->setValue(COIN, ui->comboBoxCoin->currentText());
    _settings->setValue(CORE, ui->comboBoxCore->currentText());
    _settings->setValue(POOL, ui->comboBoxPool->currentText());
    _settings->setValue(WALLET, ui->lineEditWallet->text());
    _settings->setValue(WORKER, ui->lineEditWorker->text());

}


void MainWindow::applyOC()
{
    _settings->beginGroup("nvoc");
    if(_settings->value("nvoc_applyonstart").toBool())
    {
        if(_nvapi->libLoaded())
        {
            for(unsigned int i = 0; i < _nvapi->getGPUCount(); i++)
            {
                _nvapi->setPowerLimitPercent(i, _settings->value(QString("powerlimitoffset" + QString::number(i))).toInt());
                _nvapi->setGPUOffset(i, _settings->value(QString("gpuoffset" + QString::number(i))).toInt());
                _nvapi->setMemClockOffset(i, _settings->value(QString("memoffset" + QString::number(i))).toInt());
                _nvapi->setFanSpeed(i, _settings->value(QString("fanspeed" + QString::number(i))).toInt());
            }

            if(_settings->value(QString("fanspeed" + QString::number(0))).toInt() == 101)
                _nvapi->startFanThread();
        }
    }
    _settings->endGroup();
}


void MainWindow::setVisible(bool visible)
{
    _maximizeAction->setEnabled(!isMaximized());
    _restoreAction->setEnabled(isMaximized() || !visible);
    QMainWindow::setVisible(visible);
}

void MainWindow::startMiner()
{
    on_pushButton_clicked();
}

void MainWindow::closeEvent(QCloseEvent *event)
{
#ifdef Q_OS_OSX
    if (!event->spontaneous() || !isVisible())
        return;
#endif
    if (_trayIcon->isVisible())
    {
        hide();
        event->ignore();
        QSystemTrayIcon::MessageIcon icon = QSystemTrayIcon::MessageIcon(QSystemTrayIcon::Information);
        _trayIcon->showMessage("Miner's lamp still running", _isMinerRunning ? "Ethminer is running" : "Ethminer isn't running", icon, 2 * 1000);
    }
}

void MainWindow::setIcon()
{
    QIcon icon(":/images/logo.png");
    _trayIcon->setIcon(icon);
    _trayIcon->setToolTip("Miner's lamp");

    setWindowIcon(icon);
}

void MainWindow::iconActivated(QSystemTrayIcon::ActivationReason reason)
{
    switch (reason)
    {
    case QSystemTrayIcon::Trigger:
    case QSystemTrayIcon::DoubleClick:
        QWidget::showNormal();
        break;
    default:
        ;
    }
}

void MainWindow::createActions()
{
    _minimizeAction = new QAction(tr("Mi&nimize"), this);
    connect(_minimizeAction, &QAction::triggered, this, &QWidget::hide);

    _maximizeAction = new QAction(tr("Ma&ximize"), this);
    connect(_maximizeAction, &QAction::triggered, this, &QWidget::showMaximized);

    _restoreAction = new QAction(tr("&Restore"), this);
    connect(_restoreAction, &QAction::triggered, this, &QWidget::showNormal);

    _quitAction = new QAction(tr("&Close"), this);
    connect(_quitAction, &QAction::triggered, qApp, &QCoreApplication::quit);

    _helpAction = new QAction(tr("&About"), this);
    connect(_helpAction, &QAction::triggered, this, &MainWindow::onHelp);

}

void MainWindow::createTrayIcon()
{
    _trayIconMenu = new QMenu(this);
    _trayIconMenu->addAction(_minimizeAction);
    _trayIconMenu->addAction(_maximizeAction);
    _trayIconMenu->addAction(_restoreAction);
    _trayIconMenu->addAction(_helpAction);
    _trayIconMenu->addSeparator();
    _trayIconMenu->addAction(_quitAction);

    _trayIcon = new QSystemTrayIcon(this);
    _trayIcon->setContextMenu(_trayIconMenu);
}

void MainWindow::setupEditor()
{
    QFont font;
    font.setFamily("Tahoma");
    font.setFixedPitch(true);
    font.setPointSize(8);

    ui->textEdit->setFont(font);

    _highlighter = new Highlighter(ui->textEdit->document());
}

void MainWindow::setupToolTips()
{

    ui->lcdNumberHashRate->setToolTip("Displaying the current hashrate");

    ui->lcdNumberGPUCount->setToolTip("Number of nVidia GPU(s)");

    ui->lcdNumberMaxGPUTemp->setToolTip("Displaying the current higher temperature");
    ui->lcdNumberMinGPUTemp->setToolTip("Displaying the current lower temperature");

    ui->lcdNumberMaxFanSpeed->setToolTip("Displaying the current higher fan speed in percent of the max speed");
    ui->lcdNumberMinFanSpeed->setToolTip("Displaying the current lower fan speed in percent of the max speed");

    ui->lcdNumberMaxMemClock->setToolTip("Displaying the current higher memory clock");
    ui->lcdNumberMinMemClock->setToolTip("Displaying the current lower memory clock");

    ui->lcdNumberMaxGPUClock->setToolTip("The GPU in your rig with the higher clock");
    ui->lcdNumberMinGPUClock->setToolTip("The GPU in your rig with the lower clock");

    ui->lcdNumberMaxWatt->setToolTip("Displaying the current higher power draw in Watt");
    ui->lcdNumberMinWatt->setToolTip("Displaying the current lower power draw in Watt");

    ui->lcdNumberTotalPowerDraw->setToolTip("The total power used by the GPUs");

    ui->pushButtonOC->setToolTip("Manage NVIDIA overclocking");

    if(!ui->groupBoxWatchdog->isChecked())
        ui->groupBoxWatchdog->setToolTip("Check it to activate the following watchdog options");
    else
        ui->groupBoxWatchdog->setToolTip("");
}

void MainWindow::on_pushButton_clicked()
{

    saveParameters();

    //if(ui->lineEditMinerPath->text().isEmpty() || ui->lineEditArgs->text().isEmpty()) return;

    if(ui->lineEditWallet->text().isEmpty() || ui->lineEditWorker->text().isEmpty()) return;


    if(!_isStartStoping) // avoid to start/stop more than once on double-click
    {
        _isStartStoping = true;

        if(!_isMinerRunning)
        {

            Core* current_core;
            Coin* current_coin;
            Pool* current_pool;

            if (!map_cores.contains(ui->comboBoxCore->currentText()))
            {
                // default core
                current_core = map_cores["NBMiner"];
            }
            else
            {
                current_core = map_cores[ui->comboBoxCore->currentText()];
            }

            if (!map_coins.contains(ui->comboBoxCoin->currentText()))
            {
                // default coin
                current_coin = map_coins["ETH"];
            }
            else
            {
                current_coin = map_coins[ui->comboBoxCoin->currentText()];
            }

            if (!map_pools.contains(ui->comboBoxPool->currentText()))
            {
                // default pool
                current_pool = map_pools["sparkpool"];
            }
            else
            {
                current_pool = map_pools[ui->comboBoxPool->currentText()];
            }




            QString core_path = QCoreApplication::applicationDirPath() + current_core->path;
            QString core_args = current_core->cmds[current_coin].arg(
                        current_pool->cmds[current_coin]).arg(ui->lineEditWallet->text()).arg(ui->lineEditWorker->text());

            qDebug() << core_path << core_args << endl;

            _process->SetAPI(current_core);
            _process->setMax0MHs(ui->spinBoxMax0MHs->value());
            _process->setRestartDelay(ui->spinBoxDelay->value());
            _process->setRestartOption(ui->groupBoxWatchdog->isChecked());
            _process->setDelayBeforeNoHash(ui->spinBoxDelayNoHash->value());
            _process->start(core_path, core_args);
        }
        else
        {
            qDebug() << "Stop mining" << endl;
            _process->stop();
        }

    }
}

void MainWindow::onMinerStarted()
{

    ui->pushButton->setText("Stop mining");
    _isMinerRunning = true;
    _isStartStoping = false;

    applyOC();

}

void MainWindow::onMinerStoped()
{
    ui->pushButton->setText("Start mining");
    _isMinerRunning = false;
    _isStartStoping = false;

    this->setWindowTitle(QString("Miner's Lamp"));
    ui->lcdNumberHashRate->setPalette(Qt::gray);
    ui->lcdNumberHashRate->display("0.00");

    _currentHashRate = 0;

    _trayIcon->setToolTip(QString("Miner's lamp"));
}

void MainWindow::onHashrate(QString &hashrate)
{

    QString hrValue = hashrate.mid(0, hashrate.indexOf("Mh/s"));

    this->setWindowTitle(QString("Miner's Lamp - " + hashrate + " - Restart count: " + QString::number(_errorCount)));
    if(hrValue.toDouble() == 0)
        ui->lcdNumberHashRate->setPalette(Qt::red);
    else
        ui->lcdNumberHashRate->setPalette(Qt::green);

    _currentHashRate = hrValue.toDouble();

    ui->lcdNumberHashRate->display(hrValue);

    _trayIcon->setToolTip(QString("Miner's lamp - " + hashrate));


}

void MainWindow::onError()
{
    _errorCount++;
    _trayIcon->showMessage("Miner's lamp report"
                           , "An error has been detected in ethminer.\n" + ui->groupBoxWatchdog->isChecked() ? "Miner's lamp restarted it automaticaly" : "Check the watchdog option checkbox if you want Miner's lamp to restart it on error");
}

const QColor MainWindow::getTempColor(unsigned int temp)
{
    if(temp < 50)
        return Qt::green;
    else if(temp < 65)
        return Qt::yellow;
    else if(temp < 72)
        return QColor("orange");

    return Qt::red;
}

void MainWindow::on_groupBoxWatchdog_clicked(bool checked)
{
    _process->setRestartOption(checked);
    if(checked)
        ui->groupBoxWatchdog->setToolTip("");
    else
        ui->groupBoxWatchdog->setToolTip("Check it to activate the following watchdog options");
}

void MainWindow::on_spinBoxMax0MHs_valueChanged(int arg1)
{
    _process->setMax0MHs(arg1);
}

void MainWindow::on_spinBoxDelay_valueChanged(int arg1)
{
    _process->setRestartDelay(arg1);
}

void MainWindow::on_spinBoxDelay0MHs_valueChanged(int arg1)
{
    _process->setDelayBefore0MHs(arg1);
}

void MainWindow::onReadyToStartMiner()
{
    on_pushButton_clicked();
}

void MainWindow::onHelp()
{
    on_pushButtonHelp_clicked();
}

void MainWindow::on_checkBoxOnlyShare_clicked(bool checked)
{
    _process->setShareOnly(checked);
}

void MainWindow::on_pushButtonHelp_clicked()
{
    helpDialog* helpdial = new helpDialog(_settings, this);
    helpdial->exec();
    delete helpdial;
}

void MainWindow::on_spinBoxDelayNoHash_valueChanged(int arg1)
{
    _process->setDelayBeforeNoHash(arg1);
}

autoStart::autoStart(QObject *pParent)
{
}

void autoStart::run()
{
    QThread::sleep(2);
    emit readyToStartMiner();
}




void MainWindow::onNvMonitorInfo(unsigned int gpucount
                                 , unsigned int maxgputemp
                                 , unsigned int mingputemp
                                 , unsigned int maxfanspeed
                                 , unsigned int minfanspeed
                                 , unsigned int maxmemclock
                                 , unsigned int minmemclock
                                 , unsigned int maxgpuclock
                                 , unsigned int mingpuclock
                                 , unsigned int maxpowerdraw
                                 , unsigned int minpowerdraw
                                 , unsigned int totalpowerdraw)
{


    ui->lcdNumberMaxGPUTemp->setPalette(getTempColor(maxgputemp));
    ui->lcdNumberMinGPUTemp->setPalette(getTempColor(mingputemp));



    ui->lcdNumberGPUCount->display((int)gpucount);

    ui->lcdNumberMaxGPUTemp->display((int)maxgputemp);
    ui->lcdNumberMinGPUTemp->display((int)mingputemp);

    ui->lcdNumberMaxFanSpeed->display((int)maxfanspeed);
    ui->lcdNumberMinFanSpeed->display((int)minfanspeed);

    ui->lcdNumberMaxMemClock->display((int)maxmemclock);
    ui->lcdNumberMinMemClock->display((int)minmemclock);

    ui->lcdNumberMaxGPUClock->display((int)maxgpuclock);
    ui->lcdNumberMinGPUClock->display((int)mingpuclock);

    ui->lcdNumberMaxWatt->display((double)maxpowerdraw / 1000);
    ui->lcdNumberMinWatt->display((double)minpowerdraw / 1000);

    ui->lcdNumberTotalPowerDraw->display((double)totalpowerdraw / 1000);

    _currentTempRate = maxgputemp;

}

GPUInfo MainWindow::getAverage(const std::vector<GPUInfo>& gpu_infos)
{
    GPUInfo gi;
    gi.num = -1;
    unsigned int temp = 0;
    unsigned int gpuclock = 0;
    unsigned int memclock = 0;
    unsigned int power = 0;
    unsigned int fanspeed = 0;
    for (int i = 0; i < gpu_infos.size(); i++) {
        temp += gpu_infos[i].temp;
        gpuclock += gpu_infos[i].gpuclock;
        memclock += gpu_infos[i].memclock;
        power += gpu_infos[i].power;
        fanspeed += gpu_infos[i].fanspeed;
    }
    gi.temp = temp / gpu_infos.size();
    gi.gpuclock = gpuclock / gpu_infos.size();
    gi.memclock = memclock / gpu_infos.size();
    gi.power = power / gpu_infos.size();
    gi.fanspeed = fanspeed / gpu_infos.size();
    return gi;
}

GPUInfo MainWindow::getWorst(const std::vector<GPUInfo> &gpu_infos)
{
    GPUInfo gi;
    gi.num = -1;
    unsigned int temp = 0;
    unsigned int gpuclock = 1000000000;
    unsigned int memclock = 1000000000;
    unsigned int power = 1000000000;
    unsigned int fanspeed = 1000000000;
    unsigned int hashrate = 1000000000;
    for (int i = 0; i < gpu_infos.size(); i++) {
        if (gpu_infos[i].temp > temp) temp = gpu_infos[i].temp;
        if (gpu_infos[i].gpuclock < gpuclock) gpuclock = gpu_infos[i].gpuclock;
        if (gpu_infos[i].memclock < memclock) memclock = gpu_infos[i].memclock;
        if (gpu_infos[i].power < power) power = gpu_infos[i].power;
        if (gpu_infos[i].fanspeed < fanspeed) fanspeed = gpu_infos[i].fanspeed;
    }
    gi.temp = temp;
    gi.gpuclock = gpuclock;
    gi.memclock = memclock;
    gi.power = power;
    gi.fanspeed = fanspeed;
    return gi;
}

/*
void MainWindow::onNvMonitorInfo(unsigned int current_gpu
                                 , unsigned int gpu_count
                                 , std::vector<gpu_info> gpu_infos)
{

    // max -> worst
    // min -> current GPU
    gpu_info avg_info = getAverage(gpu_infos);
    gpu_info worst_info = getWorst(gpu_infos);

    ui->lcdNumberMaxGPUTemp->setPalette(getTempColor(avg_info.temp));
    ui->lcdNumberMinGPUTemp->setPalette(getTempColor(gpu_infos[current_gpu].temp));

}
*/

void MainWindow::onAMDMonitorInfo(unsigned int gpucount, unsigned int maxgputemp, unsigned int mingputemp, unsigned int maxfanspeed, unsigned int minfanspeed, unsigned int maxmemclock, unsigned int minmemclock, unsigned int maxgpuclock, unsigned int mingpuclock, unsigned int maxpowerdraw, unsigned int minpowerdraw, unsigned int totalpowerdraw)
{
    ui->lcdNumber_AMD_MaxTemp->setPalette(getTempColor(maxgputemp));
    ui->lcdNumber_AMD_MinTemp->setPalette(getTempColor(mingputemp));

    ui->lcdNumber_AMD_GPUCount->display((int)gpucount);

    ui->lcdNumber_AMD_MaxTemp->display((int)maxgputemp);
    ui->lcdNumber_AMD_MinTemp->display((int)mingputemp);

    ui->lcdNumber_AMD_MaxFan->display((int)maxfanspeed);
    ui->lcdNumber_AMD_MinFan->display((int)minfanspeed);

    ui->lcdNumberMaxMemClock->display((int)maxmemclock);
    ui->lcdNumberMinMemClock->display((int)minmemclock);

    ui->lcdNumberMaxGPUClock->display((int)maxgpuclock);
    ui->lcdNumberMinGPUClock->display((int)mingpuclock);

    ui->lcdNumberMaxWatt->display((double)maxpowerdraw / 1000);
    ui->lcdNumberMinWatt->display((double)minpowerdraw / 1000);

    ui->lcdNumberTotalPowerDraw->display((double)totalpowerdraw / 1000);

}


void MainWindow::on_pushButtonOC_clicked()
{
    if(_nvapi->libLoaded())
    {
        nvOCDialog* dlg = new nvOCDialog(_nvapi, _settings, this);
        dlg->exec();
        delete dlg;
    }
}

void MainWindow::on_pushButtonPool_clicked(bool checked)
{
    if(checked)
        ui->groupBoxPools->show();
    else
        ui->groupBoxPools->hide();
}

void MainWindow::on_pushButtonShowHideLog_clicked(bool checked)
{
    if(checked)
        ui->textEdit->show();
    else
    {
        QRect rect = ui->textEdit->geometry();
        ui->textEdit->hide();
        QRect winRect = geometry();
        resize(winRect.width(), winRect.height() - rect.height());
    }
}

void MainWindow::on_pushButtonDisplayPoolStats_clicked()
{
    if(!_nano)
    {
        _nano = new nanopoolAPI(ui->lineEditAccount->text(), this);
        connect(_nano, &nanopoolAPI::emitBalance, this, &MainWindow::onBalance);
        connect(_nano, &nanopoolAPI::emitUSerInfo, this, &MainWindow::onPoolUserInfo);
    }

    _nano->getUserInfo();
}

void MainWindow::onBalance(double balance)
{
    ui->lcdNumberBalance->display(balance);
}

void MainWindow::onPoolUserInfo(double userBalance
                                , double currentCalcultatedHashRate
                                , double averageHashRate1H
                                , double averageHashRate3H
                                , double averageHashRate6H
                                , double averageHashRate12H
                                , double averageHashRate24H)
{
    ui->lcdNumberBalance->display(userBalance);
    ui->lcdNumberCalculatedHR->display(currentCalcultatedHashRate);
    ui->lcdNumberAvrgHr6H->display(averageHashRate6H);
}



void MainWindow::on_pushButtonEthminerBrowser_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this,
                                                    tr("Choose ethminer path"), "", tr("ethminer.exe (*.exe)"));
    if(!fileName.isEmpty())
        ui->lineEditMinerPath->setText(fileName);
}

void MainWindow::onHrChartTimer()
{
    //draw the dynamic graph
    _series->append(QDateTime::currentDateTime().toMSecsSinceEpoch(), _currentHashRate);

    //diaplay the proper range of the x-axis;
    if(_plotsCntr >= 6)
    {
        _axisX->setRange(QDateTime::currentDateTime().addSecs(-6)
                         , QDateTime::currentDateTime().addSecs(4));
    }
    else
        _plotsCntr++;

    //set height of y-axis
    if(_currentHashRate > _maxChartHashRate)
    {
        _maxChartHashRate = _currentHashRate;
        _chart->axisY()->setRange(0, _maxChartHashRate + 1);
    }
}

void MainWindow::onTempChartTimer()
{
    //draw the dynamic graph
    _seriesTemp->append(QDateTime::currentDateTime().toMSecsSinceEpoch(), _currentTempRate);

    //diaplay the proper range of the x-axis;
    if(_plotsCntrTemp >= 6)
    {
        _axisXTemp->setRange(QDateTime::currentDateTime().addSecs(-6)
                         , QDateTime::currentDateTime().addSecs(4));
    }
    else
        _plotsCntrTemp++;

    //set height of y-axis
    if(_currentTempRate > _maxChartTempRate)
    {
        _maxChartTempRate = _currentTempRate;
        _chartTemp->axisY()->setRange(_maxChartTempRate-5, _maxChartTempRate+5);
    }

    qDebug() << "temp comparing: " << _currentTempRate << " vs " << _maxChartTempRate;
    if(_currentTempRate <= _maxChartTempRate-5){
        qDebug() << "setting lower bound: " << _currentTempRate-2;
        _chartTemp->axisY()->setRange(_currentTempRate-2, _currentTempRate+8);
    }
}

void MainWindow::refreshDeviceInfo()
{
    // effectiveness pie chart
    static bool flip = false;
    flip = !flip;
    if(flip){
        _effPieSlices->at(0)->setValue(10);
    }
    else {
        _effPieSlices->at(0)->setValue(1);
    }

    // fetch devices number
    int deviceNum = _gpusinfo->size();

    if(deviceNum < _deviceCount){
        qDebug() << "removing extra";
        for(int i = _deviceCount-1; i >= deviceNum; i--){
            QWidget * parentWidget = _gpuInfoList->at(i);
            QLayout * layout = _gpuInfoList->at(i)->findChild<QHBoxLayout *>();
            QLayoutItem * item;
            QWidget * widget;

            parentWidget->hide();

            // notice each QWidget of _gpuInfoList only contains one child of type QHBoxLayout
            // and in this child, it only contains QWidgets
            while ((item = layout->takeAt(0))) {
                if ((widget = item->widget()) != 0) {
                    widget->hide();
                    delete widget;
                }
                else {
                    delete item;
                }
            }

            _gpuInfoList->removeAt(i);
            delete layout;
            delete parentWidget;
        }
        _deviceCount = deviceNum;
    }
    else if(deviceNum > _deviceCount){
        qDebug() << "adding extra";
        for(int i = _deviceCount; i <= deviceNum-1; i++){
            QWidget * parentWidget = new QWidget();
            QHBoxLayout * row = new QHBoxLayout(parentWidget);
            QLabel * deviceNumLabel = new QLabel();
            deviceNumLabel->setFont(QFont("Arial", 9));
            QLabel * deviceTemp = new QLabel("temperature");
            deviceTemp->setFont(QFont("Arial", 9));
            QLCDNumber * deviceTempLCD = new QLCDNumber();
            QLabel * fanSpeed = new QLabel("fan speed");
            fanSpeed->setFont(QFont("Arial", 9));
            QLCDNumber * fanSpeedLCD = new QLCDNumber();
            QLabel * gpuClock = new QLabel("GPU clock");
            gpuClock->setFont(QFont("Arial", 9));
            QLCDNumber * gpuClockLCD = new QLCDNumber();
            QLabel * memClock = new QLabel("Mem Clock");
            memClock->setFont(QFont("Arial", 9));
            QLCDNumber * memClockLCD = new QLCDNumber();

            row->addWidget(deviceNumLabel); //0
            row->addWidget(deviceTemp);     //1
            row->addWidget(deviceTempLCD);  //2
            row->addWidget(fanSpeed);       //3
            row->addWidget(fanSpeedLCD);    //4
            row->addWidget(gpuClock);       //5
            row->addWidget(gpuClockLCD);    //6
            row->addWidget(memClock);       //7
            row->addWidget(memClockLCD);    //8

            _gpuInfoList->append(parentWidget);
            ui->gridLayoutDevicesInfo->addWidget(parentWidget);
        }
        _deviceCount = deviceNum;
    }

    for(int i=0;i<_deviceCount;i++){
        // fetch each device
        QHBoxLayout * layoutPtr = _gpuInfoList->at(i)->findChild<QHBoxLayout *>();
        QWidget * castWidgetPtr = layoutPtr->itemAt(0)->widget();
        QLabel * castLabel = dynamic_cast<QLabel *>(castWidgetPtr);
        QString deviceName = _gpusinfo->at(i).name;
        castLabel->setText(deviceName);

        // set temperature at 2
        setLCDNumber(layoutPtr->itemAt(2)->widget(), _gpusinfo->at(i).temp);

        // set fanspeed at 4
        setLCDNumber(layoutPtr->itemAt(4)->widget(), _gpusinfo->at(i).fanspeed);

        //set gpu clock at 6
        setLCDNumber(layoutPtr->itemAt(6)->widget(), _gpusinfo->at(i).gpuclock);

        // set memclock at 8
        setLCDNumber(layoutPtr->itemAt(8)->widget(), _gpusinfo->at(i).memclock);

    }

    // save data into mysql
//    QList<GPUInfo> gpuInfoHolder = *_gpusinfo;
//    _mysqlProcess->InsertData(gpuInfoHolder);
    if(_mysqlProcess->_insertBusy == 0){
        _mysqlProcess->_gpusInfoBuffer = _gpusinfo;
        _mysqlProcess->_insert = 1;
    }
}

void MainWindow::setLCDNumber(QWidget * widget, unsigned int value){
    QLCDNumber * castLCDNumber = dynamic_cast<QLCDNumber *>(widget);
    castLCDNumber->display(QString::number(value));
}

void MainWindow::initializePieChart(){

    // effectiveness pie chart
    _effPieChart = new QChart();
    _effPieSlices = new QList<QPieSlice *>();

    _effPieChart->setBackgroundVisible(false);
    _effPieChart->setAnimationOptions(QChart::AllAnimations);

//    _effPieChart->legend()->setAlignment(Qt::AlignRight);
    _effPieChart->legend()->hide();

    _effPieChart->resize(1,1);
    //ui->debugBox->append(QString::number(_effPieChart->legend()->size().height())+" "+QString::number(_effPieChart->legend()->size().width()));
    _effPieSeries = new QPieSeries();
    _effPieSeries->append("eff", 1);
    _effPieSeries->append("uneff", 10);

    _effPieSlices->append(_effPieSeries->slices().at(0));
    _effPieSlices->append(_effPieSeries->slices().at(1));
    _effPieChart->setAcceptHoverEvents(true);

    for(int i=0;i<2;i++){
        _effPieSlices->at(i)->setBorderWidth(5);
        _effPieSlices->at(i)->setLabelVisible(false);
    }


    _effPieSeries->setHoleSize(0.35);

    _effPieChart->addSeries(_effPieSeries);

    // pay attention to memory leak
    _effCenterLabel = new QLabel(ui->graphicsViewEff);
    _effCenterLabel->setVisible(true);
    _effCenterLabel->setText("num%");
    QFont font = _effCenterLabel->font();
    font.setBold(true);
    font.setPointSize(20);
    _effCenterLabel->setFont(font);
    _effCenterLabel->setStyleSheet("QLabel { background-color : rgba(255, 0, 0, 0); color : blue;}");
    ui->gridLayoutEff->addWidget(_effCenterLabel, 0, 0, Qt::AlignCenter);

    connect(_effPieSeries, &QPieSeries::hovered, this, &MainWindow::onMouseHoverSlice);

//    _effPieChart->layout()->setContentsMargins(0,0,0,0);
//    _effPieChart->setMargins({0, 0, 0, 0});
    _effPieChart->setBackgroundRoundness(0);

    ui->graphicsViewEff->setChart(_effPieChart, 1);
    ui->gridLayoutEff->layout()->setMargin(0);
    ui->graphicsViewEff->setPieCenterLabel(_effCenterLabel);

//    connect(ui->graphicsViewEff, &hashrateCharView::resizeEvent, this, &MainWindow::resizePieEffLabel);

}

void MainWindow::onMouseHoverSlice(QPieSlice * slice, bool status){
    QString sliceLabel = slice->label();

    // index of "eff"   in _effPieSlices is 0
    // index of "uneff" in _effPieSlices is 1
    if(status){
        if(sliceLabel == "eff"){
            _effPieSlices->at(0)->setBorderWidth(0);
            _effPieSlices->at(1)->setBorderWidth(10);
        }
        else{
            _effPieSlices->at(0)->setBorderWidth(10);
            _effPieSlices->at(1)->setBorderWidth(0);
        }
    }
    else{
        _effPieSlices->at(0)->setBorderWidth(5);
        _effPieSlices->at(1)->setBorderWidth(5);
    }

}


void MainWindow::on_checkBoxAutoShowDeviceInfo_clicked(bool clicked){
    ui->groupBoxDevicesInfo->setVisible(clicked);
}

void MainWindow::onGpusInfoRecieved(QList<GPUInfo> gpusinfo){
    _gpusinfo->clear();
    for(int i=0;i<gpusinfo.size();i++){
        _gpusinfo->push_back(gpusinfo[i]);
    }
    refreshDeviceInfo();
}


bool MainWindow::getMinerStatus()
{
    return _isMinerRunning;
}


void MainWindow::plotGrapgh(QString dateStart, QString dateEnd, int deviceNum){
    static bool setGraph = false;

    if(!setGraph){
        // customize chart background
        QLinearGradient backgroundGradient_history;
        backgroundGradient_history.setStart(QPointF(0, 0));
        backgroundGradient_history.setFinalStop(QPointF(0, 1));
        backgroundGradient_history.setColorAt(0.0, QRgb(0x909090));
        backgroundGradient_history.setColorAt(1.0, QRgb(0x101010));
        backgroundGradient_history.setCoordinateMode(QGradient::StretchToDeviceMode);

        _chartHistory->setAnimationOptions(QChart::SeriesAnimations);
        _chartHistory->setBackgroundBrush(backgroundGradient_history);
        _chartHistory->setBackgroundVisible(false);
        _chartHistory->legend()->hide();

        for(int i=0;i<9;i++){
            QPen penHistory(QColor((i*i*i)%255, qrand()%255, qrand()%255));
            penHistory.setWidth(2);
            QLineSeries* lineSeries = new QLineSeries();
            lineSeries->setPen(penHistory);
            _seriesHistory.push_back(lineSeries);
            _chartHistory->addSeries(lineSeries);
        }

        _chartHistory->createDefaultAxes();

        _axisXHistory = new QDateTimeAxis;
        // set graph interval number
        _axisXHistory->setTickCount(5);
        _axisXHistory->setFormat("MM/dd");
        _axisXHistory->setTitleText("Time");
        _chartHistory->axisY()->setTitleText("history info");
        _chartHistory->axisY()->setRange(0, 1);
        QFont labelsFont_history;
        labelsFont_history.setPixelSize(14);
        _axisXHistory->setTitleFont(labelsFont_history);
        _chartHistory->axisY()->setTitleFont(labelsFont_history);
        // customize axis label colors
        QBrush axisBrush_history(Qt::white);
        _axisXHistory->setLabelsBrush(axisBrush_history);
        _chartHistory->axisY()->setLabelsBrush(axisBrush_history);
        _axisXHistory->setTitleBrush(QBrush(Qt::blue));
        _chartHistory->axisY()->setTitleBrush(QBrush(Qt::yellow));
        _axisXHistory->setGridLineVisible(false);
        _chartHistory->axisY()->setGridLineVisible(false);
        _chartHistory->setAxisX(_axisXHistory);
        for(int i=0;i<9;i++){
            _seriesHistory.at(i)->attachAxis(_axisXHistory);
        }
        _axisXHistory->setRange(QDateTime::currentDateTime(), QDateTime::currentDateTime().addDays(10));

        ui->graphicsViewHistoryInfo->setChart(_chartHistory);

        setGraph = true;
    }

    for(int i=0;i<9;i++){
        _seriesHistory.at(i)->clear();
    }

    // set x-axis
    QDateTime x_axis_start = QDateTime::fromString(dateStart + " 00:00:00","yyyy/MM/dd HH:mm:ss");
    QDateTime x_axis_end = QDateTime::fromString(dateEnd + " 00:00:00","yyyy/MM/dd HH:mm:ss");



    qDebug() << x_axis_start.toString() << " vs " << x_axis_end.toString();

    if(x_axis_start > x_axis_end){
        return;
    }

//    _axisXHistory->setRange(x_axis_start, x_axis_end);

    // retrieve infoList
    qDebug() << "before get history";

    if(_mysqlProcess->_retrieveBusy == 0){
        _mysqlProcess->searchConditionBuffer->clear();
        _mysqlProcess->searchConditionBuffer->push_back(dateStart);
        _mysqlProcess->searchConditionBuffer->push_back(dateEnd);
        _mysqlProcess->searchConditionBuffer->push_back(QString::number(deviceNum));
        _mysqlProcess->_seriesPtr = &_seriesHistory;
        _mysqlProcess->_chartHistory = _chartHistory;
        _mysqlProcess->_retrieve = 1;
    }
    else{
        return;
    }

//    while(1){
//        qDebug() << "waiting while loop: " << _mysqlProcess->_retrieve;
//        if(_mysqlProcess->_retrieve == 0)
//            break;
//        QThread::sleep(4);
//    }

//    QStringList* gpuInfoList2 = _mysqlProcess->searchResultBuffer;
//    qDebug() << "this is search result: " << _mysqlProcess->searchResultBuffer->size();

//    qDebug() << "before get history old";

//    QStringList gpuInfoList = _mysqlProcess->Get_History(dateStart.toStdString().c_str(), dateEnd.toStdString().c_str(),
//                                                         deviceNum);

//    qDebug() << "after get history with size: " << gpuInfoList.size();

//    int gpuInfoListSize = gpuInfoList.size();

//    if(gpuInfoListSize == 0){
//        return;
//    }

//    double maxValue = 0;
//    double minValue = 999;

//    // append points
//    for(int i=0; i<gpuInfoListSize/12; i++){
//        // gpu_name 1, Date1 2, avg(TMP) 3, avg(gpu_clock) 4, avg(mem_clock) 5, avg(FanSpeed) 6, avg(PowerDraw) 7
//        // avg(hashrate) 8, avg(accepted_shares) 9, avg(invalid_shares) 10, avg(rejected_shares) 11
//        QDateTime x_coordinate = QDateTime::fromString(gpuInfoList[i*12+2]+" 00:00:00","yyyy-MM-dd HH:mm:ss");
//        for(int j =0; j<_seriesHistory.size(); j++){
//            double value = gpuInfoList[i*12+3+j].toDouble();
//            qDebug() << gpuInfoList[i*12+3+j] << "with i:" << i << " j: " << j;
//            if(value > maxValue){
//                maxValue = value;
//            }
//            if(value < minValue){
//                minValue = value;
//            }
//            _seriesHistory.at(j)->append(x_coordinate.toMSecsSinceEpoch(), value);
//        }
//    }
//    _chartHistory->axisY()->setRange(minValue-5, maxValue+5);


}

void MainWindow::on_checkBoxShowHistoryInfo_clicked(bool clicked){
    ui->dateTimeEditHistoryStartTime->setVisible(clicked);
    ui->dateTimeEditHistoryEndTime->setVisible(clicked);
    ui->pushButtonSearchHistory->setVisible(clicked);
    ui->spinBoxHistoryDeviceNum->setVisible(clicked);
    ui->labelHistoryDeviceNum->setVisible(clicked);
    if(clicked == false){
        ui->groupBoxHistoryInfo->hide();
    }
}

void MainWindow::on_pushButtonSearchHistory_clicked(){
    ui->pushButtonSearchHistory->hide();
    qDebug() << "search time: " << ui->dateTimeEditHistoryStartTime->text() << " ->" << ui->dateTimeEditHistoryEndTime->text()
             << " " << ui->spinBoxHistoryDeviceNum->text().toInt();
    ui->groupBoxHistoryInfo->show();
    plotGrapgh(ui->dateTimeEditHistoryStartTime->text(), ui->dateTimeEditHistoryEndTime->text(),
               ui->spinBoxHistoryDeviceNum->text().toInt());
}

void MainWindow::on_dateTimeEditHistoryStartTime_dateTimeChanged(const QDateTime &datetime){
    if(ui->dateTimeEditHistoryStartTime->isVisible()){
        ui->pushButtonSearchHistory->show();
    }
}

void MainWindow::on_dateTimeEditHistoryEndTime_dateTimeChanged(const QDateTime &datetime){
    if(ui->dateTimeEditHistoryEndTime->isVisible()){
        ui->pushButtonSearchHistory->show();
    }
}

void MainWindow::on_spinBoxHistoryDeviceNum_valueChanged(int arg1){
    if(ui->spinBoxHistoryDeviceNum->isVisible()){
        ui->pushButtonSearchHistory->show();
    }
}

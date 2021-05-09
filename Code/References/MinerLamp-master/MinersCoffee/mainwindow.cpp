#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "minerprocess.h"
#include "helpdialog.h"
#include "nvidianvml.h"
#include "hashratecharview.h"
#include "database.h"
#include "constants.h"
#include "structures.h"
#include "wincmd.h"
#include "tst_generaltest.h"
#include "nvocpage.h"

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
#include <QGraphicsEffect>
#include <QAreaSeries>
#include <QProgressBar>
#include <QDir>
#include <QFileInfo>
#include <QStorageInfo>

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

MainWindow::MainWindow(bool testing, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    _isMinerRunning(false),
    _isStartStoping(false),
    _errorCount(0),
    _testing(testing)
{

    _settings = new QSettings(QString(QDir::currentPath() + QDir::separator() + "minerlamp.ini"), QSettings::IniFormat);

    _process = new MinerProcess(_settings);
    _gpusinfo = new QList<GPUInfo>();
    _miningInfo = new MiningInfo();
    _poolInfo = new PoolInfo();
    _gpuInfoList = new QList<QWidget * >();
    _diskInfoList = new QList<QWidget * >();

    if (!_testing)
    {
        _databaseProcess = new Database();
        _databaseProcess->start();
    }

    ui->setupUi(this);

    _helpPage = new HelpPage(_settings,
                             ui->checkBoxHelpPage,
                             ui->plainTextEditHelpPage
                );

    // debug box test
    _process->setLogControl(ui->textEdit);

    connect(_process, &MinerProcess::emitStarted, this, &MainWindow::onMinerStarted);
    connect(_process, &MinerProcess::emitStoped, this, &MainWindow::onMinerStoped);

    // update hash rate
    connect(_process, &MinerProcess::emitHashRate, this, &MainWindow::onHashrate);
    connect(_process, &MinerProcess::emitError, this, &MainWindow::onError);

    qRegisterMetaType<MiningInfo>("MiningInfo");
    // update miningInfo
    connect(_process, &MinerProcess::emitMiningInfo, this, &MainWindow::onReceivedMiningInfo);

    qRegisterMetaType<PoolInfo>("PoolInfo");
    qRegisterMetaType<QList<PoolInfo> >("QList<PoolInfo>");
    // update poolInfos
    connect(_process, &MinerProcess::emitPoolInfo, this, &MainWindow::onReceivedPoolInfo);

    ui->pushButtonToggle->installEventFilter(this);

    _nvapi = new nvidiaAPI();

    bool nvDll = true;
    QLibrary lib("nvml.dll");
    if (!lib.load())
    {
        lib.setFileName(nvml_path);
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
        _nvMonitorThrd = new nvMonitorThrd(this,_nvapi);
        connect(_nvMonitorThrd, &nvMonitorThrd::gpuInfoSignal, this, &MainWindow::onNvMonitorInfo);

        qRegisterMetaType<QList<GPUInfo>>("QList<GPUInfo>");
        connect(_nvMonitorThrd, &nvMonitorThrd::gpusInfoSignalRefresh, this, &MainWindow::onGPUInfosReceived);
        _nvMonitorThrd->start();

        if(_nvapi->libLoaded())
        {

        }

    }
    else
    {
//        ui->groupBoxNvidia->hide();
    }

    // reserved for amd
//    QLibrary adl("atiadlxx");
//    if(!adl.load())
//    {
//        ui->groupBoxAMD->hide();

//    }
//    else
//    {
//        adl.unload();

//        _amdMonitorThrd = new amdMonitorThrd(this);
//        connect(_amdMonitorThrd, &amdMonitorThrd::gpuInfoSignal, this, &MainWindow::onAMDMonitorInfo);
//        _amdMonitorThrd->start();

//    }

    _nvocPage = new NvocPage(
                _nvapi,
                _settings,
                ui->spinBoxTemperature,
                ui->pushButtonAutoOC,
                ui->checkBoxAllDevices,
                ui->checkBoxOCMinerStart,
                ui->comboBoxDevice,
                ui->checkBoxAutoSpeedFan,
                ui->horizontalSliderFanSpeed
                );
    updateSliders(0);

    loadParameters();

    // disable set tooltip
//    setupToolTips();

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
    backgroundGradient.setColorAt(1.0, QColor(255, 153, 0, 0));
    backgroundGradient.setColorAt(0.0, QColor(255, 255, 255, 150));
    backgroundGradient.setCoordinateMode(QGradient::ObjectBoundingMode);

    _chart->setAnimationOptions(QChart::SeriesAnimations);
    _chart->setBackgroundBrush(backgroundGradient);
    _chart->setBackgroundVisible(false);
    _chart->legend()->hide();

    //set the color of the graph
    QPen pen(QColor(255, 255, 255));
    pen.setWidth(3);
    QPen penBottom(QColor(255, 0, 0, 0));
    penBottom.setWidth(2);

    _series = new QLineSeries();
    _series->setPen(pen);
    _seriesBottom = new QLineSeries();
    _seriesBottom->setPen(pen);
    _areaseriesHash = new QAreaSeries(_series, _seriesBottom);
    _areaseriesHash->setPen(penBottom);

    QLinearGradient gradientHash(QPointF(0, 0), QPointF(0, 1));
    gradientHash.setColorAt(0.0, 0x3cc63c);
    gradientHash.setColorAt(1.0, 0x26f626);
    _areaseriesHash->setBrush(backgroundGradient);

//    _series->append(QDateTime::currentDateTime().toMSecsSinceEpoch(),0);
    _chart->addSeries(_series);
    _chart->addSeries(_areaseriesHash);
    _chart->createDefaultAxes();

    _axisX = new QDateTimeAxis;
    // set graph interval number
    _axisX->setTickCount(3);
    _axisX->setFormat("hh:mm:ss");
    _axisX->setTitleText("Time");
    _chart->axisY()->setTitleText("HR in MH/s");
    _chart->axisY()->setRange(-0.5, 1);

    QFont labelsFont;
    labelsFont.setPixelSize(14);
    _axisX->setTitleFont(labelsFont);
    _chart->axisY()->setTitleFont(labelsFont);
    _chart->axisY()->setLabelsFont(QFont("Berlin Sans FB", 12));

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
    _seriesBottom->attachAxis(_axisX);
    _areaseriesHash->attachAxis(_axisX);
    _axisX->setRange(QDateTime::currentDateTime(), QDateTime::currentDateTime().addSecs(10));

    // cast the default y-axis
    QValueAxis *axisY = qobject_cast<QValueAxis*>(_chart->axes(Qt::Vertical).first());
    axisY->setLabelFormat("%.1f ");
    axisY->setTickCount(3);

    // hide title and labels
    _chart->axisX()->setTitleVisible(false);
    _chart->axisX()->setLabelsVisible(false);
    _chart->axisX()->hide();
    _chart->axisY()->setTitleVisible(false);
    _chart->axisX()->setMinorGridLineVisible(false);

    ui->graphicsView->setChart(_chart);
    _chart->setMargins(QMargins(0,0,0,0));

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
    backgroundGradient_temp.setColorAt(1.0, QColor(255, 153, 0, 0));
    backgroundGradient_temp.setColorAt(0.0, QColor(255, 255, 255, 150));
    backgroundGradient_temp.setCoordinateMode(QGradient::ObjectBoundingMode);

    _chartTemp->setAnimationOptions(QChart::SeriesAnimations);
    _chartTemp->setBackgroundBrush(backgroundGradient_temp);
    _chartTemp->setBackgroundVisible(false);
    _chartTemp->legend()->hide();


    //set the color of the graph
    QPen penTemp(QColor(255, 255, 255));
    penTemp.setWidth(2);
    QPen penTempBottom(QColor(255, 0, 0, 0));
    penTempBottom.setWidth(2);

    _seriesTemp = new QLineSeries();
    _seriesTemp->setPen(penTemp);
    _seriesTempBottom = new QLineSeries();
    _seriesTempBottom->setPen(penTempBottom);
    _areaseriesTemp = new QAreaSeries(_seriesTemp, _seriesTempBottom);
    _areaseriesTemp->setPen(penTempBottom);
    _seriesTemp->setPointsVisible(false);
    _areaseriesTemp->setPointsVisible(false);

    QLinearGradient gradient(QPointF(0, 0), QPointF(0, 1));
    gradient.setColorAt(0.0, 0x3cc63c);
    gradient.setColorAt(1.0, 0x26f626);
    _areaseriesTemp->setBrush(backgroundGradient_temp);

    _chartTemp->addSeries(_seriesTemp);
    _chartTemp->addSeries(_areaseriesTemp);
    _chartTemp->createDefaultAxes();

    _axisXTemp = new QDateTimeAxis;
    // set graph interval number
    _axisXTemp->setTickCount(5);

    // cast the default y-axis
    QValueAxis *axisYTemp = qobject_cast<QValueAxis*>(_chartTemp->axes(Qt::Vertical).first());
//    axisYTemp->setLabelFormat("%.1f  ");

    // set labels foramt
    _axisXTemp->setFormat("");
    _axisXTemp->setTitleText("Time");
    _chartTemp->axisY()->setTitleText("");
    axisYTemp->setLabelFormat("%d ");
    axisYTemp->setTickCount(5);

    QFont labelsFont_temp("Berlin Sans FB", 12);
//    labelsFont_temp.setPixelSize(10);
    _axisXTemp->setTitleFont(labelsFont_temp);
    _chartTemp->axisY()->setTitleFont(labelsFont_temp);
    _chartTemp->axisY()->setLabelsFont(labelsFont_temp);

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
    _seriesTempBottom->attachAxis(_axisXTemp);
    _areaseriesTemp->attachAxis(_axisXTemp);
    _axisXTemp->setRange(QDateTime::currentDateTime(), QDateTime::currentDateTime().addSecs(10));

    ui->graphicsViewTemp->setChart(_chartTemp);
    _chartTemp->setBackgroundRoundness(0);

    // hide title and labels
    _chartTemp->axisX()->setTitleVisible(false);
    _chartTemp->axisX()->setLabelsVisible(false);
    _chartTemp->axisX()->hide();
    _chartTemp->axisY()->setTitleVisible(false);
    _chartTemp->axisX()->setMinorGridLineVisible(false);

    // hide margins
    _chartTemp->setMargins(QMargins(0,0,0,0));


    // graph will be drawn every time interval
     connect(&_tempChartTimer, &QTimer::timeout, this, &MainWindow::RefreshTempGraph);

    // initialize pie chart
    initializePieChart();

    // set time interval
    _tempChartTimer.setInterval(1000);
    _tempChartTimer.start();

    ui->labelHashRate->setText("0.00");
    ui->labelEffectiveness->setText("0%");

    // origianl code for auto start
//    if(ui->checkBoxAutoStart->isChecked())
//    {
//        _starter = new autoStart(this);
//        connect(_starter, SIGNAL(readyToStartMiner()), this, SLOT(onReadyToStartMiner()));
//        _starter->start();
//    }

    ui->textEdit->show();

    ui->groupBoxDevicesInfo->show();

    initializeConstants();

    ui->dateTimeEditHistoryStartTime->setDateTime(QDateTime::currentDateTime().addDays(-5));
    ui->dateTimeEditHistoryEndTime->setDateTime(QDateTime::currentDateTime());

    // set the current page
    // set at monitor page at index 0
    ui->stackedWidgetMain->setCurrentIndex(0);
    setPushButtonColor(ui->pushButtonMonitorPage, true);
    // set at monitor overview page at index 0
    ui->stackedWidgetMonitorMain->setCurrentIndex(0);
    setPushButtonColor(ui->pushButtonMonitorPage_Overview, true);
    ui->pushButtonSearchHistory->click();

    changeLabelColor(ui->labelHashRate, Qt::white);

}

MainWindow::~MainWindow()
{
    saveParameters();

    _process->stop();
    if(_databaseProcess && _databaseProcess->isRunning())
        _databaseProcess->terminate();

    if(_nvapi != Q_NULLPTR)
        delete _nvapi;


    delete _process;
    delete _settings;
    delete _gpuInfoList;
    delete _gpusinfo;
    delete ui;
    delete _databaseProcess;
    delete _helpPage;

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
    //qDebug() << "fetch index: " << comboIdx << "\t" << key;
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

void MainWindow::AddPoolsFromFile(const QString& filename)
{
    QString pools_path = qApp->applicationDirPath() + "/" + filename;
    QList<QString> pools = helper.GetStringData(pools_path);
    for (int i = 0; i < pools.size(); i++)
    {
        QStringList pool_data = pools[i].split(",");
        if (pool_data.size() != 3)
        {
            QMessageBox::warning(NULL, "warning",
                                 QString("Corrupted test data in\n %1").arg(pools_path));
            break;
        }
        if (!map_coins.contains(pool_data[0]))
            return;
        Coin* coin = map_coins[pool_data[0]];
        AddPool(pool_data[1], coin, pool_data[2]);
    }
}

void MainWindow::initializeConstants()
{

    // Future Improvement:
    // Separate code and data
    // Move the constant strings in the code to a file (possibly database)
    // In the code, use a loop to read the data file
    // and do the same job

    Coin* eth = AddCoin("ETH");

    AddPoolsFromFile(pools_path);

    AddCore("NBMiner", path_nbminer, api_nbminer, eth, cmd_nbminer_eth);
}


void MainWindow::loadParameters()
{
    ui->lineEditMinerPath->setText(_settings->value(MINERPATH).toString());
    ui->lineEditArgs->setText(_settings->value(MINERARGS).toString());
//    ui->groupBoxWatchdog->setChecked(_settings->value(AUTORESTART).toBool());
//    ui->spinBoxMax0MHs->setValue(_settings->value(MAX0MHS).toInt());
//    ui->spinBoxDelay->setValue(_settings->value(RESTARTDELAY).toInt());
//    ui->spinBoxDelay0MHs->setValue(_settings->value(ZEROMHSDELAY).toInt());
    ui->checkBoxOnlyShare->setChecked(_settings->value(DISPLAYSHAREONLY).toBool());
//    ui->spinBoxDelayNoHash->setValue(_settings->value(DELAYNOHASH).toInt());
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
//    _settings->setValue(AUTORESTART, ui->groupBoxWatchdog->isChecked());
//    _settings->setValue(MAX0MHS, ui->spinBoxMax0MHs->value());
//    _settings->setValue(RESTARTDELAY, ui->spinBoxDelay->value());
//    _settings->setValue(ZEROMHSDELAY, ui->spinBoxDelay0MHs->value());
    _settings->setValue(DISPLAYSHAREONLY, ui->checkBoxOnlyShare->isChecked());
//    _settings->setValue(DELAYNOHASH, ui->spinBoxDelayNoHash->value());
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
        _trayIcon->showMessage("Miner's Coffee still running", _isMinerRunning ? "Ethminer is running" : "Ethminer isn't running", icon, 2 * 1000);
    }
}

void MainWindow::setIcon()
{
    QIcon icon(":/images/logo.png");
    _trayIcon->setIcon(icon);
    _trayIcon->setToolTip("Miner's Coffee");

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

    ui->labelHashRate->setToolTip("Displaying the current hashrate");

//    ui->lcdNumberGPUCount->setToolTip("Number of nVidia GPU(s)");

    ui->labelMaxGPUTemp->setToolTip("Displaying the current higher temperature");
    ui->labelMinGPUTemp->setToolTip("Displaying the current lower temperature");

    ui->labelMaxFanSpeed->setToolTip("Displaying the current higher fan speed in percent of the max speed");
    ui->labelMinFanSpeed->setToolTip("Displaying the current lower fan speed in percent of the max speed");

    ui->labelMaxMemClock->setToolTip("Displaying the current higher memory clock");
    ui->labelMinMemClock->setToolTip("Displaying the current lower memory clock");

    ui->labelMaxGPUClock->setToolTip("The GPU in your rig with the higher clock");
    ui->labelMinGPUClock->setToolTip("The GPU in your rig with the lower clock");

    ui->labelMaxWatt->setToolTip("Displaying the current higher power draw in Watt");
    ui->labelMinWatt->setToolTip("Displaying the current lower power draw in Watt");

//    ui->lcdNumberTotalPowerDraw->setToolTip("The total power used by the GPUs");

//    ui->pushButtonOC->setToolTip("Manage NVIDIA overclocking");

//    if(!ui->groupBoxWatchdog->isChecked())
//        ui->groupBoxWatchdog->setToolTip("Check it to activate the following watchdog options");
//    else
//        ui->groupBoxWatchdog->setToolTip("");
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
            StartMiningCore();
        }
        else
        {
            StopMiningCore();
        }

    }
}


void MainWindow::StartMiningCore()
{
    SetMiningArgs();

    QString core_path = QCoreApplication::applicationDirPath() + _current_core->path;
    QString core_args = _current_core->cmds[_current_coin].arg(
                _current_pool->cmds[_current_coin]).arg(ui->lineEditWallet->text()).arg(ui->lineEditWorker->text());

    //qDebug() << core_path << core_args << endl;

    _process->SetAPI(_current_core);
//    _process->setMax0MHs(ui->spinBoxMax0MHs->value());
//    _process->setRestartDelay(ui->spinBoxDelay->value());
//    _process->setRestartOption(ui->groupBoxWatchdog->isChecked());
//    _process->setDelayBeforeNoHash(ui->spinBoxDelayNoHash->value());
    _process->start(core_path, core_args);
}

void MainWindow::StopMiningCore()
{
    //qDebug() << "Stop mining" << endl;
    _process->stop();
}

void MainWindow::SetMiningArgs()
{
    if (!map_cores.contains(ui->comboBoxCore->currentText()))
    {
        // default core
        _current_core = map_cores["NBMiner"];
    }
    else
    {
        _current_core = map_cores[ui->comboBoxCore->currentText()];
    }

    if (!map_coins.contains(ui->comboBoxCoin->currentText()))
    {
        // default coin
        _current_coin = map_coins["ETH"];
    }
    else
    {
        _current_coin = map_coins[ui->comboBoxCoin->currentText()];
    }

    if (!map_pools.contains(ui->comboBoxPool->currentText()))
    {
        // default pool
        _current_pool = map_pools["sparkpool"];
    }
    else
    {
        _current_pool = map_pools[ui->comboBoxPool->currentText()];
    }
}

void MainWindow::onMinerStarted()
{

    ui->pushButton->setText("Stop\nMining");
    _isMinerRunning = true;
    _isStartStoping = false;

    applyOC();

}

void MainWindow::onMinerStoped()
{
    ui->pushButton->setText("Start\nMining");
    _isMinerRunning = false;
    _isStartStoping = false;

    this->setWindowTitle(QString("Miner's Coffee"));
    changeLabelColor(ui->labelHashRate, Qt::white);
    ui->labelHashRate->setText("0.00");
    changeLabelColor(ui->labelEffectiveness, Qt::white);
    ui->labelEffectiveness->setText("0%");

    _currentHashRate = 0;

    _trayIcon->setToolTip(QString("Miner's Coffee"));
}

void MainWindow::onHashrate(QString &hashrate)
{
    if(hashrate == "nan"){
        changeLabelColor(ui->labelHashRate, Qt::red);
        ui->labelHashRate->setText("N/A");
        return;
    }

    QString hrValue = hashrate.mid(0, hashrate.indexOf("Mh/s"));

    this->setWindowTitle(QString("Miner's Coffee - " + hashrate + " - Restart count: " + QString::number(_errorCount)));

    if(hrValue.toDouble() == 0)
        changeLabelColor(ui->labelHashRate, Qt::red);
    else
        changeLabelColor(ui->labelHashRate, Qt::green);

    _currentHashRate = hrValue.toDouble();
    ui->labelHashRate->setText(QString().setNum(_currentHashRate, 'f', 2)+" Mh/h");

    //set hash rate
    if(_miningInfo != nullptr){
        if(_miningInfo->accepted_shares!=0){
            double effectiveness = _miningInfo->accepted_shares / (_miningInfo->accepted_shares + _miningInfo->invalid_shares
                                                                  + _miningInfo->rejected_shares);
            int effPercent = (int) (effectiveness * 100);
            ui->labelEffectiveness->setText(QString::number(effPercent)+"%");
        }
        else{
            ui->labelEffectiveness->setText("0%");
        }
    }
    else{
        ui->labelEffectiveness->setText("0%");
    }

    _trayIcon->setToolTip(QString("Miner's Coffee - " + hashrate));


}

void MainWindow::onError()
{
    _errorCount++;
    _trayIcon->showMessage("Miner's Coffee report"
                           , "An error has been detected in ethminer.\n");
    // + ui->groupBoxWatchdog->isChecked() ? "Miner's Coffee restarted it automaticaly" : "Check the watchdog option checkbox if you want Miner's Coffee to restart it on error");
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


void MainWindow::onReadyToStartMiner()
{
    on_pushButton_clicked();
}

void MainWindow::onHelp()
{
    helpDialog* helpdial = new helpDialog(_settings, this);
    helpdial->exec();
    delete helpdial;
}

void MainWindow::on_checkBoxOnlyShare_clicked(bool checked)
{
    _process->setShareOnly(checked);
}

autoStart::autoStart(QObject *pParent)
{
}

void autoStart::run()
{
    QThread::sleep(2);
    emit readyToStartMiner();
}

void MainWindow::changeLabelColor(QLabel * label, QColor color){
    QPalette palette = label->palette();
    palette.setColor(label->backgroundRole(), color);
    palette.setColor(label->foregroundRole(), color);
    label->setPalette(palette);
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

    changeLabelColor(ui->labelMaxGPUTemp, getTempColor(maxgputemp));
    changeLabelColor(ui->labelMinGPUTemp, getTempColor(mingputemp));

    ui->labelMaxGPUTemp->setText(QString::number((int)maxgputemp));
    ui->labelMinGPUTemp->setText(QString::number((int)mingputemp));

    ui->labelMaxFanSpeed->setText(QString::number((int)maxfanspeed));
    ui->labelMinFanSpeed->setText(QString::number((int)minfanspeed));

    ui->labelMaxMemClock->setText(QString::number((int)maxmemclock));
    ui->labelMinMemClock->setText(QString::number((int)minmemclock));

    ui->labelMaxGPUClock->setText(QString::number((int)maxgpuclock));
    ui->labelMinGPUClock->setText(QString::number((int)mingpuclock));


    ui->labelMaxWatt->setText(QString().setNum((float) maxpowerdraw / 1000, 'f', 2));
    ui->labelMinWatt->setText(QString().setNum((float) minpowerdraw / 1000, 'f', 2));

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

//void MainWindow::onAMDMonitorInfo(unsigned int gpucount, unsigned int maxgputemp, unsigned int mingputemp, unsigned int maxfanspeed, unsigned int minfanspeed, unsigned int maxmemclock, unsigned int minmemclock, unsigned int maxgpuclock, unsigned int mingpuclock, unsigned int maxpowerdraw, unsigned int minpowerdraw, unsigned int totalpowerdraw)
//{
//    ui->lcdNumber_AMD_MaxTemp->setPalette(getTempColor(maxgputemp));
//    ui->lcdNumber_AMD_MinTemp->setPalette(getTempColor(mingputemp));

//    ui->lcdNumber_AMD_GPUCount->display((int)gpucount);

//    ui->lcdNumber_AMD_MaxTemp->display((int)maxgputemp);
//    ui->lcdNumber_AMD_MinTemp->display((int)mingputemp);

//    ui->lcdNumber_AMD_MaxFan->display((int)maxfanspeed);
//    ui->lcdNumber_AMD_MinFan->display((int)minfanspeed);

//    ui->labelMaxMemClock->setText(QString::number((int)maxmemclock));
//    ui->labelMinMemClock->setText(QString::number((int)minmemclock));

//    ui->labelMaxGPUClock->setText(QString::number((int)maxgpuclock));
//    ui->labelMinGPUClock->setText(QString::number((int)mingpuclock));

//    ui->labelMaxWatt->setText(QString("%.2f").arg(maxpowerdraw / 1000));
//    ui->labelMinWatt->setText(QString("%.2f").arg(minpowerdraw / 1000));

//}

void MainWindow::onHrChartTimer()
{
    //draw the dynamic graph
    _series->append(QDateTime::currentDateTime().toMSecsSinceEpoch(), _currentHashRate);


    if(_currentHashRate == 0){
        // -0.5 is the default minimun value in the y-axis
        _seriesBottom->append(QDateTime::currentDateTime().toMSecsSinceEpoch(), -0.5);
    }
    else{
        _seriesBottom->append(QDateTime::currentDateTime().toMSecsSinceEpoch(), 0);
    }

    //diaplay the proper range of the x-axis;
    //make sure the graph stay at 9 sec
    if(_plotsCntr >= 9)
    {
        _axisX->setRange(QDateTime::currentDateTime().addSecs(-9)
                         , QDateTime::currentDateTime().addSecs(1));
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

void MainWindow::RefreshTempGraph()
{
    static int pieChartMaximumTemp = 120;

    // temperature pie chart
    double choppedTempRate = _currentTempRate - 0;
    double restValue = pieChartMaximumTemp - _currentTempRate;

    if(restValue < 0){
        restValue = 0;
    }

    if(choppedTempRate < 0){
        choppedTempRate = 0;
    }

    // the first slice in temp pie chart is the currentTemperature
    _tempPieSlices->at(0)->setValue(choppedTempRate);
    // the second slice in temp pie chart is the maximumtemperatureTHerhold - currentTemperature
    _tempPieSlices->at(1)->setValue(restValue);



    //draw the dynamic graph
    _seriesTemp->append(QDateTime::currentDateTime().toMSecsSinceEpoch(), _currentTempRate);

    // 0 is the default minimun value in the y-axis
    _seriesTempBottom->append(QDateTime::currentDateTime().toMSecsSinceEpoch(), _currentTempRate-6);

    //diaplay the proper range of the x-axis;
    //make sure the graph stay at 9 sec
    if(_plotsCntrTemp >= 10)
    {
        _axisXTemp->setRange(QDateTime::currentDateTime().addSecs(-10)
                         , QDateTime::currentDateTime().addSecs(0));
    }
    else
        _plotsCntrTemp++;

    //set height of y-axis
    if(_currentTempRate >= _maxChartTempRate)
    {
        _maxChartTempRate = _currentTempRate;
        _chartTemp->axisY()->setRange(_maxChartTempRate-3, _maxChartTempRate+3);
    }

    if(_currentTempRate <= _maxChartTempRate-3){
        _chartTemp->axisY()->setRange(_currentTempRate-3, _currentTempRate+3);
    }
}

void MainWindow::refreshDeviceInfo()
{
    if (!_ui_refresh_enabled)
        return;

    // refresh estimated output
    if(isnan(_est_output_usd)){
        ui->labelHashExpectedIncome->setText("N/A");
    }
    else{
        ui->labelHashExpectedIncome->setText("$"+QString().setNum(_est_output_usd, 'f', 2));
    }

    // refresh system info
    // it will be roughly refresh 20 times slower than device info
    static int cnt = 0;
    if(cnt == 0){
        refreshSystemSettings();
        cnt = 20;
    }
    cnt--;

    // refresh device info
    // fetch devices number
    int deviceNum = _gpusinfo->size();

    if(deviceNum < _deviceCount){
        //qDebug() << "removing extra";
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
        //qDebug() << "adding extra";
        for(int i = _deviceCount; i <= deviceNum-1; i++){
            QWidget * parentWidget = new QWidget();
            QVBoxLayout * col = new QVBoxLayout(parentWidget);
            QHBoxLayout * row1 = new QHBoxLayout(col->widget());
            QHBoxLayout * row2 = new QHBoxLayout(col->widget());

            row2->setSpacing(10);

            QLabel * deviceNumLabel = new QLabel();
            deviceNumLabel->setFont(QFont("Berlin Sans FB", 20));
            deviceNumLabel->setMinimumWidth(140);
            deviceNumLabel->setMinimumHeight(65);
            changeLabelColor(deviceNumLabel, Qt::white);

            QLabel * deviceTemp = new QLabel("Temp");
            deviceTemp->setFont(QFont("Berlin Sans FB", 12));
            deviceTemp->setMinimumWidth(80);
            deviceTemp->setAlignment(Qt::AlignRight|Qt::AlignVCenter);
            changeLabelColor(deviceTemp, Qt::white);

            QLabel * deviceTempNumberLabel = new QLabel();
            deviceTempNumberLabel->setFont(QFont("Berlin Sans FB", 20));
            deviceTempNumberLabel->setMinimumWidth(120);
            deviceTempNumberLabel->setAlignment(Qt::AlignCenter);

            QLabel * gpuClock = new QLabel("GPU\nClock");
            gpuClock->setFont(QFont("Berlin Sans FB", 12));
            gpuClock->setMinimumWidth(80);
            gpuClock->setAlignment(Qt::AlignRight|Qt::AlignVCenter);
            changeLabelColor(gpuClock, Qt::white);

            QLabel * gpuClockNumberLabel = new QLabel();
            gpuClockNumberLabel->setFont(QFont("Berlin Sans FB", 20));
            gpuClockNumberLabel->setMinimumWidth(120);
            gpuClockNumberLabel->setAlignment(Qt::AlignCenter);
            changeLabelColor(gpuClockNumberLabel, Qt::white);

            QLabel * memClock = new QLabel("VRAM\nClock");
            memClock->setFont(QFont("Berlin Sans FB", 12));
            memClock->setMinimumWidth(80);
            memClock->setAlignment(Qt::AlignRight|Qt::AlignVCenter);
            changeLabelColor(memClock, Qt::white);

            QLabel * memClockNumberLabel = new QLabel();
            memClockNumberLabel->setFont(QFont("Berlin Sans FB", 20));
            memClockNumberLabel->setMinimumWidth(120);
            memClockNumberLabel->setAlignment(Qt::AlignCenter);
            changeLabelColor(memClockNumberLabel, Qt::white);

            QLabel * fanSpeed = new QLabel("Fan\nSpeed");
            fanSpeed->setFont(QFont("Berlin Sans FB", 12));
            fanSpeed->setMinimumWidth(80);
            fanSpeed->setAlignment(Qt::AlignRight|Qt::AlignVCenter);
            changeLabelColor(fanSpeed, Qt::white);

            QLabel * fanSpeedNumberLabel = new QLabel();
            fanSpeedNumberLabel->setFont(QFont("Berlin Sans FB", 20));
            fanSpeedNumberLabel->setMinimumWidth(120);
            fanSpeedNumberLabel->setAlignment(Qt::AlignCenter);
            changeLabelColor(fanSpeedNumberLabel, Qt::white);

            //QSpacerItem *rowSpacer = new QSpacerItem(1,1, QSizePolicy::Expanding, QSizePolicy::Fixed);

            row1->addWidget(deviceNumLabel);         //0

            row2->addWidget(deviceTemp);             //0
            row2->addWidget(deviceTempNumberLabel);  //1
            row2->addWidget(gpuClock);               //2
            row2->addWidget(gpuClockNumberLabel);    //3
            row2->addWidget(memClock);               //4
            row2->addWidget(memClockNumberLabel);    //5
            row2->addWidget(fanSpeed);               //6
            row2->addWidget(fanSpeedNumberLabel);    //7
            //row2->addSpacerItem(rowSpacer);

            QSpacerItem *colSpacer = new QSpacerItem(1,30, QSizePolicy::Expanding, QSizePolicy::Fixed);
            QSpacerItem *colSpacer2 = new QSpacerItem(1,20, QSizePolicy::Expanding, QSizePolicy::Fixed);

            col->addSpacerItem(colSpacer);
            col->addLayout(row1);
            col->addSpacerItem(colSpacer2);
            col->addLayout(row2);

            _gpuInfoList->append(parentWidget);
            ui->gridLayoutDevicesInfo->addWidget(parentWidget);
        }
        _deviceCount = deviceNum;
    }

    for(int i=0;i<_deviceCount;i++){
        // fetch each device
        QVBoxLayout * vlayoutPtr = _gpuInfoList->at(i)->findChild<QVBoxLayout *>();
        QList<QHBoxLayout *> layoutPtrs = vlayoutPtr->findChildren<QHBoxLayout *>();


        if (layoutPtrs.size() < 2)
            return;

        QHBoxLayout * layoutPtr1 = layoutPtrs[0];
        QHBoxLayout * layoutPtr2 = layoutPtrs[1];

        QWidget * castWidgetPtr1 = layoutPtr1->itemAt(0)->widget();
        QLabel * castLabel1 = dynamic_cast<QLabel *>(castWidgetPtr1);


        QWidget * castWidgetPtr2 = layoutPtr2->itemAt(0)->widget();
        QLabel * castLabel2 = dynamic_cast<QLabel *>(castWidgetPtr2);

        // set name
        // process device name
        QString originalName = _gpusinfo->at(i).name;
        QString spacing = "   ";
        castLabel1->setText(spacing + originalName);
        /*
        std::string shortName="";
        for(int i=0;i<originalName.length();i++){
            if(originalName[i]=='T'&&originalName[i+1]=='i')
                shortName+="Ti";
            if(originalName[i]!='1'&&originalName[i]!='2'&&originalName[i]!='3'&&originalName[i]!='4'&&
                    originalName[i]!='5'&&originalName[i]!='6'&&originalName[i]!='7'&&originalName[i]!='8'&&
                    originalName[i]!='9'&&originalName[i]!='0')
                continue;
            shortName+=originalName[i];
        }
        */

        // set temperature at 1
        castWidgetPtr2 = layoutPtr2->itemAt(1)->widget();
        castLabel2 = dynamic_cast<QLabel *>(castWidgetPtr2);
        castLabel2->setText(QString::number(_gpusinfo->at(i).temp));
        changeLabelColor(castLabel2, getTempColor(_gpusinfo->at(i).temp));

        //set gpu clock at 3
        castWidgetPtr2 = layoutPtr2->itemAt(3)->widget();
        castLabel2 = dynamic_cast<QLabel *>(castWidgetPtr2);
        castLabel2->setText(QString::number(_gpusinfo->at(i).gpuclock));

        // set memclock at 5
        castWidgetPtr2 = layoutPtr2->itemAt(5)->widget();
        castLabel2 = dynamic_cast<QLabel *>(castWidgetPtr2);
        castLabel2->setText(QString::number(_gpusinfo->at(i).memclock));

        // set fanspeed at 7
        castWidgetPtr2 = layoutPtr2->itemAt(7)->widget();
        castLabel2 = dynamic_cast<QLabel *>(castWidgetPtr2);
        castLabel2->setText(QString::number(_gpusinfo->at(i).fanspeed));
    }

    Wincmd wincmd;
    vector<vector<QString>> localDisks = wincmd.LocalDisk();
    int diskNum = localDisks.at(0).size();

    // refresh combobox for change page size
    if(diskNum != _diskCount){
        ui->comboBoxChangePageSize->clear();
        for(int i=0; i<diskNum; i++){
            ui->comboBoxChangePageSize->addItem(localDisks.at(0).at(i));
        }
    }

    if(diskNum < _diskCount){
        for(int i = _diskCount-1; i >= diskNum; i--){
            QWidget * parentWidget = _diskInfoList->at(i);
            QLayout * layout = _diskInfoList->at(i)->findChild<QHBoxLayout *>();
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

            _diskInfoList->removeAt(i);
            delete layout;
            delete parentWidget;
        }
        _diskCount = diskNum;
    }
    else if(diskNum > _diskCount){
        for(int i = _diskCount; i <= diskNum-1; i++){
            QWidget * parentWidget = new QWidget();
            QHBoxLayout * row = new QHBoxLayout(parentWidget);
            QLabel * diskNameLabel = new QLabel();
            diskNameLabel->setStyleSheet("color : white;");
            diskNameLabel->setFont(QFont("Berlin Sans FB", 15));
            QProgressBar * diskStorageBar = new QProgressBar();
            diskStorageBar->setStyleSheet(
                "QProgressBar"
                "{"
                    "color:rgb(255,255,255);"
                    "background-color :rgb(51,51,51);"
                    "border : 2px;"
                    "border-radius:4px;"
                    "height: 50px;"
                    "width: 100px;"
                "}"

                "QProgressBar::chunk{"
                    "border : 2px;"
                    "border-radius:4px;"
                    "background-color:#008F96;"
                "}"
            );
            diskStorageBar->setFont(QFont("Berlin Sans FB", 10));

            diskStorageBar->setAlignment(Qt::AlignCenter);

            row->addWidget(diskNameLabel);      //0
            row->addWidget(diskStorageBar);     //1

            _diskInfoList->append(parentWidget);
            ui->gridLayoutDiskInfo->addWidget(parentWidget);
        }
        _diskCount = diskNum;
    }

    for(int i=0;i<_diskCount;i++){
        // fetch each disk
        QHBoxLayout * layoutPtr = _diskInfoList->at(i)->findChild<QHBoxLayout *>();

        // at 0
        // set disk name
        QWidget * castWidgetPtr = layoutPtr->itemAt(0)->widget();
        QLabel * castLabel = dynamic_cast<QLabel *>(castWidgetPtr);
        QString diskName = localDisks.at(0).at(i);
        if(castLabel->text() != diskName){
            castLabel->setText(diskName);
        }

        // at 1
        // set storage info
        castWidgetPtr = layoutPtr->itemAt(1)->widget();
        QProgressBar * castprogressbar = dynamic_cast<QProgressBar *>(castWidgetPtr);
        QString storageInfo = localDisks.at(1).at(i);
        if(castprogressbar->text() != storageInfo){
            QStringList info = storageInfo.split('/');
            int free = info.at(0).toInt();
            int total = info.at(1).toInt();
            int result;
            if(total == 0){
                result = 0;
            }
            else{
                result = free*100/total;
            }
            castprogressbar->setValue(result);
            castprogressbar->setFormat(storageInfo);
        }

    }

    // save data into mysql
    if (_databaseProcess){
        if(_databaseProcess->_insertBusy == 0){
            _databaseProcess->_gpusInfoBuffer = _gpusinfo;
            _databaseProcess->_miningInfoBuffer = _miningInfo;
            _databaseProcess->_insert = 1;
        }
    }

}

void MainWindow::setLCDNumber(QWidget * widget, unsigned int value){
    QLCDNumber * castLCDNumber = dynamic_cast<QLCDNumber *>(widget);
    castLCDNumber->display(QString::number(value));
}

void MainWindow::initializePieChart(){

    // effectiveness pie chart
    _tempPieChart = new QChart();
    _tempPieSlices = new QList<QPieSlice *>();

    _tempPieChart->setBackgroundVisible(false);
    _tempPieChart->setAnimationOptions(QChart::AllAnimations);

//    _effPieChart->legend()->setAlignment(Qt::AlignRight);
    _tempPieChart->legend()->hide();

    _tempPieChart->resize(1,1);
    //ui->debugBox->append(QString::number(_effPieChart->legend()->size().height())+" "+QString::number(_effPieChart->legend()->size().width()));
    _tempPieSeries = new QPieSeries();
    _tempPieSeries->append("currentTemp", 50);
    _tempPieSeries->append("maxTemp", 50);
    _tempPieSeries->slices().at(0)->setColor(0x008F96);
    _tempPieSeries->slices().at(0)->setBorderColor(QColor(91,90,90));
    _tempPieSeries->slices().at(1)->setColor(QColor(51,51,51));
    _tempPieSeries->slices().at(1)->setBorderColor(QColor(91,90,90));

    _tempPieSlices->append(_tempPieSeries->slices().at(0));
    _tempPieSlices->append(_tempPieSeries->slices().at(1));
    _tempPieChart->setAcceptHoverEvents(true);

    for(int i=0;i<2;i++){
        _tempPieSlices->at(i)->setBorderWidth(5);
        _tempPieSlices->at(i)->setLabelVisible(false);
    }


    _tempPieSeries->setHoleSize(0.35);

    _tempPieChart->addSeries(_tempPieSeries);

    connect(_tempPieSeries, &QPieSeries::hovered, this, &MainWindow::onMouseHoverSlice);

//    _effPieChart->layout()->setContentsMargins(0,0,0,0);
//    _effPieChart->setMargins({0, 0, 0, 0});
    _tempPieChart->setBackgroundRoundness(0);

    ui->graphicsViewTempPie->setChart(_tempPieChart, 1);
    _tempPieChart->setMargins(QMargins(0,0,0,0));

//    connect(ui->graphicsViewEff, &hashrateCharView::resizeEvent, this, &MainWindow::resizePieEffLabel);

}

void MainWindow::onMouseHoverSlice(QPieSlice * slice, bool status){
    QString sliceLabel = slice->label();

    // index of "currentTemp"   in _effPieSlices is 0
    // index of "maxTemp" in _effPieSlices is 1
    if(status){
        if(sliceLabel == "currentTemp"){
            _tempPieSlices->at(0)->setBorderWidth(0);
            _tempPieSlices->at(1)->setBorderWidth(10);
        }
        else{
            _tempPieSlices->at(0)->setBorderWidth(10);
            _tempPieSlices->at(1)->setBorderWidth(0);
        }
    }
    else{
        _tempPieSlices->at(0)->setBorderWidth(5);
        _tempPieSlices->at(1)->setBorderWidth(5);
    }

}

void MainWindow::onGPUInfosReceived(QList<GPUInfo> gpusinfo){
    _gpusinfo->clear();
    for(int i=0;i<gpusinfo.size();i++){
        _gpusinfo->push_back(gpusinfo[i]);
    }
//    RefreshTempGraph();
    refreshDeviceInfo();
}


bool MainWindow::getMinerStatus()
{
    return _isMinerRunning;
}

/*
* plotGraph: parameter deviceNum
*  = natural_number < 999 stands for display information of device# natural_number
*  = 999 stands for display overall mingInfo
*  = negative_number stands for display miningInfo of device# -(negative_number+1)
*/
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
        _chartHistory->legend()->setFont(QFont("Berlin Sans FB"));
        _chartHistory->legend()->setColor(Qt::white);
        _chartHistory->legend()->show();

        QList<unsigned int> colorList{
            0x598987,
            0x678f8d,
            0x77a88d,
            0xffd00,
            0xff6670
        };

        for(int i=0;i<5;i++){
            QPen penHistory(QColor(colorList.at(i)));
            penHistory.setWidth(3);
            QLineSeries* lineSeries = new QLineSeries();
            lineSeries->setName("set: " + QString::number(i));
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
        _axisXHistory->setTitleVisible(false);
        _chartHistory->axisY()->setTitleText("history info");
        _chartHistory->axisY()->setRange(0, 1);
        _chartHistory->axisY()->setTitleVisible(false);

        QValueAxis *axisY = qobject_cast<QValueAxis*>(_chartHistory->axes(Qt::Vertical).first());
        axisY->setLabelFormat("%.d ");

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
        _chartHistory->setMargins(QMargins(0,0,0,0));

        // push 5 lines in the graph
        for(int i=0;i<5;i++){
            _seriesHistory.at(i)->attachAxis(_axisXHistory);
        }
        _axisXHistory->setRange(QDateTime::currentDateTime(), QDateTime::currentDateTime().addDays(10));

        ui->graphicsViewHistoryInfo->setChart(_chartHistory);

        setGraph = true;
        _chartHistory->axisX()->setLabelsFont(QFont("Berlin Sans FB", 8));
        _chartHistory->axisY()->setLabelsFont(QFont("Berlin Sans FB", 8));
    }

    // there are 5 lines in the series
    for(int i=0;i<5;i++){
        _seriesHistory.at(i)->clear();
    }

    // set x-axis
    QDateTime x_axis_start = QDateTime::fromString(dateStart + " 00:00:00","yyyy/MM/dd HH:mm:ss");
    QDateTime x_axis_end = QDateTime::fromString(dateEnd + " 00:00:00","yyyy/MM/dd HH:mm:ss");

    if(x_axis_start > x_axis_end){
        return;
    }

    //qDebug() << "before get history";

    if (_databaseProcess)
    {
        if(_databaseProcess->_retrieveBusy == 0)
        {
            _databaseProcess->searchConditionBuffer->clear();
            _databaseProcess->searchConditionBuffer->push_back(dateStart);
            _databaseProcess->searchConditionBuffer->push_back(dateEnd);
            _databaseProcess->searchConditionBuffer->push_back(QString::number(deviceNum));
            _databaseProcess->_seriesPtr = &_seriesHistory;
            _databaseProcess->_chartHistory = _chartHistory;
            _databaseProcess->_retrieve = 1;
        }
        else
        {
            return;
        }
    }


}

void MainWindow::on_pushButtonSearchHistory_clicked(){
    ui->pushButtonSearchHistory->hide();
    ui->graphicsViewHistoryInfo->show();


    plotGrapgh(ui->dateTimeEditHistoryStartTime->text(), ui->dateTimeEditHistoryEndTime->text(),
               ui->spinBoxHistoryDeviceNum->text().toInt());

    // following codes are reserved for future development to show mining info
    /*
    // index 0 stands for GPUs information
    if(ui->comboBoxHistoryDataOption->currentIndex()==0){
        plotGrapgh(ui->dateTimeEditHistoryStartTime->text(), ui->dateTimeEditHistoryEndTime->text(),
                   ui->spinBoxHistoryDeviceNum->text().toInt());
    }
    // index 1 stands for the mining info
    else if(ui->comboBoxHistoryDataOption->currentIndex()==1){
        // plotGraph: parameter deviceNum = 999 stands for display overall mingInfo
        if(_searchHistoryMiningOverall){
            plotGrapgh(ui->dateTimeEditHistoryStartTime->text(), ui->dateTimeEditHistoryEndTime->text(), 999);
        }
        // plotGraph: parameter deviceNum = negative_number stands for display miningInfo of device# -(negative_number+1)
        else{
            plotGrapgh(ui->dateTimeEditHistoryStartTime->text(), ui->dateTimeEditHistoryEndTime->text(),
                       -(ui->spinBoxHistoryDeviceNum->text().toInt()+1));
        }
    }
    */


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

void MainWindow::on_spinBoxHistoryDeviceNum_valueChanged(int arg1)
{
    if(ui->spinBoxHistoryDeviceNum->isVisible()){
        ui->pushButtonSearchHistory->show();
    }
}

void MainWindow::onReceivedMiningInfo(MiningInfo miningInfo)
{
    //qDebug() << "recieving mingInfo signal";
    _miningInfo->latency = miningInfo.latency;
    _miningInfo->gpuMiningInfos = miningInfo.gpuMiningInfos;
    _miningInfo->invalid_shares = miningInfo.invalid_shares;
    _miningInfo->accepted_shares = miningInfo.accepted_shares;
    _miningInfo->rejected_shares = miningInfo.rejected_shares;
    //qDebug() << "saving changes";
    EstimateOutput();
}

void MainWindow::EstimateOutput()
{
    if (_miningInfo == nullptr || _poolInfo == nullptr)
        return;

    float total_hashrate = 0;
    for (GPUMiningInfo gpuMiningInfo : qAsConst(_miningInfo->gpuMiningInfos))
    {
        total_hashrate += gpuMiningInfo.hashrate;
    }

    _total_hash_rate = total_hashrate;
    QString totalhashRateString = QString::number((double) total_hashrate/(1024*1024));
    if(!_isMinerRunning){
        changeLabelColor(ui->labelHashRate, Qt::white);
        ui->labelHashRate->setText("N/A");
    }
    else{
        _process->emitHashRate(totalhashRateString);
    }

    _est_output_coin = total_hashrate / _poolInfo->incomeHashrate * _poolInfo->meanIncome24h;
    _est_output_cny = _est_output_coin * _poolInfo->cny;
    _est_output_usd = _est_output_coin * _poolInfo->usd;

//    qDebug() << total_hashrate << _poolInfo->incomeHashrate << _poolInfo->meanIncome24h << _est_output_coin << _est_output_cny << _est_output_usd;
}

void MainWindow::onReceivedPoolInfo(QList<PoolInfo> poolInfos)
{
    if (_current_coin == nullptr){
        return;
    }
    for (const PoolInfo &poolInfo : poolInfos)
    {
        if (_current_coin->name == poolInfo.currency)
        {
            _poolInfo->pool_name = poolInfo.pool_name;
            _poolInfo->currency = poolInfo.currency;
            _poolInfo->income = poolInfo.income;
            _poolInfo->meanIncome24h = poolInfo.meanIncome24h;
            _poolInfo->incomeHashrate = poolInfo.incomeHashrate;
            _poolInfo->usd = poolInfo.usd;
            _poolInfo->cny = poolInfo.cny;
        }
    }
}

void MainWindow::refreshSystemSettings(){
    Wincmd wincmd;
    std::vector<QString> result = wincmd.SeeSetting();
    ui->plainTextEditSettingsSystemInfo->clear();
    ui->plainTextEditSettingsSystemInfoTitle->clear();

    // 16 is the row numbers of one disk
    int rowNumOfOneDisk = 16;
    int colNum = result.size() / rowNumOfOneDisk;

    for(int i=0;i<rowNumOfOneDisk;i+=2){
        QString infoRow;
        bool longLine = false;

        if(result.at(i+1).size()>= 24){
            longLine = true;
        }

        ui->plainTextEditSettingsSystemInfoTitle->appendPlainText(result.at(i));

        for(int j =0;j<colNum;j++){
            if(j>=1){
                if(!longLine){
                    infoRow += " / ";
                    infoRow += result.at(i+1+j*rowNumOfOneDisk);
                }
                else{
                    ui->plainTextEditSettingsSystemInfo->appendPlainText(result.at(i+1+rowNumOfOneDisk*j));
                    ui->plainTextEditSettingsSystemInfoTitle->appendPlainText(" ");
                }
            }
            else{
                if(longLine){
                    ui->plainTextEditSettingsSystemInfo->appendPlainText(result.at(i+1));
                }
                else{
                    infoRow += result.at(i+1);
                }
            }

        }

        if(!longLine){
            ui->plainTextEditSettingsSystemInfo->appendPlainText(infoRow);
        }

    }


}

void MainWindow::on_pushButtonCancelAutoPage_clicked(){
    Wincmd wincmd;
    wincmd.AutoManagePage();
    qDebug() << "auto page clicked";
}

void MainWindow::on_pushButtonChangePageSize_clicked(){
    Wincmd wincmd;
    wincmd.ChangePageSize(
                ui->comboBoxChangePageSize->currentText(),
                QString::number(ui->spinBoxChangePageSizeMax->value()*1024),
                QString::number(ui->spinBoxChangePageSizeMin->value()*1024)
                );
}

void MainWindow::SetUIRefresh(bool enabled)
{
    _ui_refresh_enabled = enabled;
}


/********************************
 * slots to change              *
 *                              *
 *                              *
 ********************************/

void MainWindow::setPushButtonColor(QPushButton* pushButton, bool pressed){
    if(pressed){
        pushButton->setStyleSheet(
                    "QPushButton {"
                         "border: none;"
                         "background-color: rgb(91,90,90);"
                     "}"
                     "QPushButton:hover {"
                         "background-color: rgb(91,90,90);"
                     "}"
                     "QPushButton:pressed {	"
                         "background-color:#7A0000;"
                     "}"
                    );
    }
    else{
        pushButton->setStyleSheet(
                    "QPushButton {"
                         "border: none;"
                         "background-color: #008F96;"
                     "}"
                     "QPushButton:hover {"
                         "background-color: rgb(91,90,90);"
                     "}"
                     "QPushButton:pressed {	"
                         "background-color:#7A0000;"
                     "}"
                    );
    }
}

void MainWindow::on_pushButtonMonitorPage_Overview_clicked(){
    ui->stackedWidgetMonitorMain->setCurrentIndex(0);
    setPushButtonColor(ui->pushButtonMonitorPage_Overview, true);
    setPushButtonColor(ui->pushButtonMonitorPage_Mining, false);
    setPushButtonColor(ui->pushButtonMonitorPage_System, false);
    setPushButtonColor(ui->pushButtonMonitorPage_DevicesInfo, false);
}

void MainWindow::on_pushButtonMonitorPage_Mining_clicked(){
    ui->stackedWidgetMonitorMain->setCurrentIndex(1);
    setPushButtonColor(ui->pushButtonMonitorPage_Overview, false);
    setPushButtonColor(ui->pushButtonMonitorPage_Mining, true);
    setPushButtonColor(ui->pushButtonMonitorPage_System, false);
    setPushButtonColor(ui->pushButtonMonitorPage_DevicesInfo, false);
}
void MainWindow::on_pushButtonMonitorPage_System_clicked(){
    ui->stackedWidgetMonitorMain->setCurrentIndex(2);
    setPushButtonColor(ui->pushButtonMonitorPage_Overview, false);
    setPushButtonColor(ui->pushButtonMonitorPage_Mining, false);
    setPushButtonColor(ui->pushButtonMonitorPage_System, true);
    setPushButtonColor(ui->pushButtonMonitorPage_DevicesInfo, false);
}

void MainWindow::on_pushButtonMonitorPage_DevicesInfo_clicked(){
    ui->stackedWidgetMonitorMain->setCurrentIndex(3);
    setPushButtonColor(ui->pushButtonMonitorPage_Overview, false);
    setPushButtonColor(ui->pushButtonMonitorPage_Mining, false);
    setPushButtonColor(ui->pushButtonMonitorPage_System, false);
    setPushButtonColor(ui->pushButtonMonitorPage_DevicesInfo, true);
}

void MainWindow::on_pushButtonMonitorPage_clicked(){
    ui->stackedWidgetMain->setCurrentIndex(0);
    setPushButtonColor(ui->pushButtonMonitorPage, true);
    setPushButtonColor(ui->pushButtonOCPage, false);
    setPushButtonColor(ui->pushButtonHelpPage, false);

}

void MainWindow::on_pushButtonOCPage_clicked(){
    ui->stackedWidgetMain->setCurrentIndex(1);
    setPushButtonColor(ui->pushButtonMonitorPage, false);
    setPushButtonColor(ui->pushButtonOCPage, true);
    setPushButtonColor(ui->pushButtonHelpPage, false);
}

void MainWindow::on_pushButtonHelpPage_clicked(){
    ui->stackedWidgetMain->setCurrentIndex(2);
    setPushButtonColor(ui->pushButtonMonitorPage, false);
    setPushButtonColor(ui->pushButtonOCPage, false);
    setPushButtonColor(ui->pushButtonHelpPage, true);
}

void MainWindow::on_checkBoxHelpPage_clicked(bool clicked){
    _helpPage->donateCheckBoxClicked(clicked);
}

bool MainWindow::eventFilter(QObject *obj, QEvent *event)
{
    // This function repeatedly call for those QObjects
    // which have installed eventFilter (Step 2)

    if (obj == (QObject*)ui->pushButtonToggle) {
        if (event->type() == QEvent::Enter)
        {
            isAllPromptVisable(true);
        }
        else if(event->type() == QEvent::Leave){
            isAllPromptVisable(false);
        }
        return true;
    }else {
        // pass the event on to the parent class
        return QWidget::eventFilter(obj, event);
    }
}

void MainWindow::isAllPromptVisable(bool status){
    static QString frameMonitorStyleSheet;
    static QString frameOCStyleSheet;
    static QString frameHelpStyleSheet;
    static QString frameOverviewStyleSheet;
    static QString frameMiningInfoStyleSheet;
    static QString frameHistoryStyleSheet;
    static QString frameDevicesInfoStyleSheet;
    static bool hasSet = false;

    static QString generalFramStyle(
                "background-repeat:no-repeat;"
                "background-position:center;"
                "background-color: rgb(0, 143, 150);"
                "color : white;"
                "border-width: 0;"
                "border-radius : 0;"
                );

    if(status){
        if(!hasSet){
            frameMonitorStyleSheet = ui->frameMonitor->styleSheet();
            frameOCStyleSheet = ui->frameOC->styleSheet();
            frameHelpStyleSheet = ui->frameHelp->styleSheet();

            frameOverviewStyleSheet = ui->frameOverview->styleSheet();
            frameMiningInfoStyleSheet = ui->frameMiningInfo->styleSheet();
            frameHistoryStyleSheet = ui->frameHistory->styleSheet();
            frameDevicesInfoStyleSheet = ui->frameDevicesInfo->styleSheet();

            hasSet = true;
        }

        ui->frameMonitor->setStyleSheet(generalFramStyle);
        ui->frameOC->setStyleSheet(generalFramStyle);
        ui->frameHelp->setStyleSheet(generalFramStyle);
        ui->frameOverview->setStyleSheet(generalFramStyle);
        ui->frameMiningInfo->setStyleSheet(generalFramStyle);
        ui->frameHistory->setStyleSheet(generalFramStyle);
        ui->frameDevicesInfo->setStyleSheet(generalFramStyle);

        ui->pushButtonMonitorPage->setText("Monitor");
        ui->pushButtonOCPage->setText("OC");
        ui->pushButtonHelpPage->setText("Help");
        ui->pushButtonMonitorPage_Overview->setText("Overview");
        ui->pushButtonMonitorPage_Mining->setText("Mining");
        ui->pushButtonMonitorPage_System->setText("System");
        ui->pushButtonMonitorPage_DevicesInfo->setText("Devices");
    }
    else{
        ui->frameMonitor->setStyleSheet(frameMonitorStyleSheet);
        ui->frameOC->setStyleSheet(frameOCStyleSheet);
        ui->frameHelp->setStyleSheet(frameHelpStyleSheet);
        ui->frameOverview->setStyleSheet(frameOverviewStyleSheet);
        ui->frameMiningInfo->setStyleSheet(frameMiningInfoStyleSheet);
        ui->frameHistory->setStyleSheet(frameHistoryStyleSheet);
        ui->frameDevicesInfo->setStyleSheet(frameDevicesInfoStyleSheet);

        ui->pushButtonMonitorPage->setText("");
        ui->pushButtonOCPage->setText("");
        ui->pushButtonHelpPage->setText("");
        ui->pushButtonMonitorPage_Overview->setText("");
        ui->pushButtonMonitorPage_Mining->setText("");
        ui->pushButtonMonitorPage_System->setText("");
        ui->pushButtonMonitorPage_DevicesInfo->setText("");
    }
}



/********************************
 * migrate from nvocDigalog     *
 *                              *
 *                              *
 ********************************/

void MainWindow::on_horizontalSliderPowerPercent_valueChanged(int value)
{
    ui->labelPowerPercent->setText(QString::number(value));
    _nvocPage->_cardList[_nvocPage->_gpuIndex].powerOffset = value;
}

void MainWindow::on_horizontalSliderGpuOffset_valueChanged(int value)
{
    ui->labelGpuOffset->setText(QString::number(value));
    _nvocPage->_cardList[_nvocPage->_gpuIndex].gpuOffset = value;
}

void MainWindow::on_horizontalSliderMemOffset_valueChanged(int value)
{
    ui->labelMemClock->setText(QString::number(value));
    _nvocPage->_cardList[_nvocPage->_gpuIndex].memOffset = value;
}

void MainWindow::on_horizontalSliderFanSpeed_valueChanged(int value)
{
    ui->labelFanSpeed->setText(QString::number(value));
    _nvocPage->_cardList[_nvocPage->_gpuIndex].fanSpeed = value;
}

void MainWindow::on_comboBoxDevice_activated(int index)
{
   updateSliders(index);
   _nvocPage->_gpuIndex = index;
}

void MainWindow::updateSliders(unsigned int gpu)
{
    static bool initialied = false;

    int plimit      = _nvapi->getPowerLimit(gpu);
    int gpuoffset   = _nvapi->getGPUOffset(gpu);
    int memoffset   = _nvapi->getMemOffset(gpu);
    int fanspeed    = _nvapi->getFanSpeed(gpu);

    ui->horizontalSliderPowerPercent->setValue(plimit);
    ui->horizontalSliderGpuOffset->setValue(gpuoffset);
    ui->horizontalSliderMemOffset->setValue(memoffset);
    ui->horizontalSliderFanSpeed->setValue(fanspeed);

    if(!initialied){
        ui->labelPowerPercent->setText(QString::number(plimit));
        ui->labelGpuOffset->setText(QString::number(gpuoffset));
        ui->labelMemClock->setText(QString::number(memoffset));
        ui->labelFanSpeed->setText(QString::number(fanspeed));

        initialied = true;
    }
}

void MainWindow::saveConfig()
{
    int deviceIndex = ui->comboBoxDevice->currentIndex();

    _settings->beginGroup("nvoc");
    _settings->setValue("nvoc_applyall", ui->checkBoxAllDevices->isChecked());
    _settings->setValue("temp_limit", ui->spinBoxTemperature->value());
    _settings->setValue("nvoc_applyonstart", ui->checkBoxOCMinerStart->isChecked());

    if(ui->checkBoxAllDevices->isChecked())
    {
        for(int i = 0; i < _nvocPage->_cardList.size(); i++)
        {
            _settings->setValue(QString("powerlimitoffset" + QString::number(i)), _nvocPage->_cardList.at(deviceIndex).powerOffset);
            _settings->setValue(QString("gpuoffset" + QString::number(i)), _nvocPage->_cardList.at(deviceIndex).gpuOffset);
            _settings->setValue(QString("memoffset" + QString::number(i)), _nvocPage->_cardList.at(deviceIndex).memOffset);
            _settings->setValue(QString("fanspeed" + QString::number(i)), ui->checkBoxAutoSpeedFan->isChecked() ? 101 : _nvocPage->_cardList.at(deviceIndex).fanSpeed);
        }
    }
    else
    {
        _settings->setValue(QString("powerlimitoffset" + QString::number(deviceIndex)), _nvocPage->_cardList.at(deviceIndex).powerOffset);
        _settings->setValue(QString("gpuoffset" + QString::number(deviceIndex)), _nvocPage->_cardList.at(deviceIndex).gpuOffset);
        _settings->setValue(QString("memoffset" + QString::number(deviceIndex)), _nvocPage->_cardList.at(deviceIndex).memOffset);
        _settings->setValue(QString("fanspeed" + QString::number(deviceIndex)), ui->checkBoxAutoSpeedFan->isChecked() ? 101 : _nvocPage->_cardList.at(deviceIndex).fanSpeed);
    }
    _settings->endGroup();
}

// Apply settings
void MainWindow::on_pushButtonOCPageApply_clicked()
{
    int gpu = ui->comboBoxDevice->currentIndex();
    if(ui->checkBoxAllDevices->isChecked())
    {
        for(unsigned int i = 0; i < _nvapi->getGPUCount(); i++)
        {
            _nvapi->setPowerLimitPercent(i, ui->horizontalSliderPowerPercent->value());
            _nvapi->setGPUOffset(i, ui->horizontalSliderGpuOffset->value());
            _nvapi->setMemClockOffset(i, ui->horizontalSliderMemOffset->value());
            _nvapi->setPowerLimitPercent(i,ui->horizontalSliderPowerPercent->value());
            if(ui->checkBoxAutoSpeedFan->isChecked())
            {
                _nvapi->startFanThread();
            }
            else
            {
                _nvapi->startFanThread();
                _nvapi->setFanSpeed(i, ui->horizontalSliderFanSpeed->value());
                _nvapi->stopFanThread();
            }
        }
    }
    else
    {
        _nvapi->setPowerLimitPercent(gpu, ui->horizontalSliderPowerPercent->value());
        _nvapi->setGPUOffset(gpu, ui->horizontalSliderGpuOffset->value());
        _nvapi->setPowerLimitPercent(gpu,ui->horizontalSliderPowerPercent->value());
        _nvapi->setMemClockOffset(gpu, ui->horizontalSliderMemOffset->value());
        if(ui->checkBoxAutoSpeedFan->isChecked())
        {
            qDebug("ATUO  opened");
            _nvapi->startFanThread();
        }
        else
        {
            _nvapi->startFanThread();
            _nvapi->setFanSpeed(gpu, ui->horizontalSliderFanSpeed->value());
            _nvapi->stopFanThread();
        }
    }
    saveConfig();

}


void MainWindow::on_checkBoxAutoSpeedFan_clicked(bool checked)
{
    if(checked)
    {
        ui->horizontalSliderFanSpeed->hide();

    }
    else
    {
        ui->horizontalSliderFanSpeed->show();

    }
}

void MainWindow::on_spinBoxTemperature_valueChanged(int value){
    qDebug() << "testing " << value << endl;
    unsigned gpu = (unsigned) ui->comboBoxDevice->currentIndex();
    unsigned int temp_limit = (unsigned) value;
    _nvapi->setTempLimitOffset(gpu, temp_limit);
    if(ui->checkBoxAllDevices->isChecked())
        {
            for(unsigned int i = 0; i < _nvapi->getGPUCount(); i++)
            {
                  _nvapi->setTempLimitOffset(i,temp_limit);
              }
         }
}


void MainWindow::on_pushButtonAutoOC_clicked(){
    int gpu = ui->comboBoxDevice->currentIndex();
    ui->spinBoxTemperature->setValue(80);
    if(ui->checkBoxAllDevices->isChecked())
    {
        for(unsigned int i = 0; i < _nvapi->getGPUCount(); i++)
        {
            std::string name =_nvocPage->_nvml->getGPUName(i);
            int fanspeed,gpuofffset,memoffset;
            fanspeed=0;
            gpuofffset=0;
            memoffset=0;
            // do select * from advise where GPUname= name;
            std::string n="";
            for(int i=0;i<name.length();i++){
                if(name[i]=='T'&&name[i+1]=='i')
                    n+="Ti";
                if(name[i]!='1'&&name[i]!='2'&&name[i]!='3'&&name[i]!='4'&&name[i]!='5'&&name[i]!='6'&&name[i]!='7'&&name[i]!='8'&&name[i]!='9'&&name[i]!='0')
                    continue;
                n+=name[i];
            }
            QStringList l;
            //
            const char *p;
            p=n.c_str();
            if(_nvocPage->_db != nullptr){
                l=_nvocPage->getAdvice(p);
            }
            qDebug("query name %s",n.c_str());
            //db.FreeConnect();
            int str=atoi(l.front().toStdString().c_str());
            gpuofffset=str;
            l.pop_front();
            str=atoi(l.front().toStdString().c_str());
            memoffset=str;
            str=atoi(l.front().toStdString().c_str());
            _nvapi->setFanSpeed(i,fanspeed);
            _nvapi->setGPUOffset(i,gpuofffset);
            _nvapi->setMemClockOffset(i,memoffset);
        }
    }
    else
    {
        std::string name =_nvocPage->_nvml->getGPUName(gpu);
        int fanspeed,gpuofffset,memoffset;
        fanspeed=0;
        gpuofffset=0;
        memoffset=0;
        // do select * from advise where GPUname= name;std::string n="";
        std::string n="";
        for(int i=0;i<name.length();i++){
            if(name[i]=='T'&&name[i+1]=='i')
                n+="Ti";
            if(name[i]!='1'&&name[i]!='2'&&name[i]!='3'&&name[i]!='4'&&name[i]!='5'&&name[i]!='6'&&name[i]!='7'&&name[i]!='8'&&name[i]!='9'&&name[i]!='0')
                continue;
            n+=name[i];
        }
        //
        QStringList l;
        //
        const char *p;
        p=n.c_str();
        if(_nvocPage->_db != nullptr){
            l=_nvocPage->getAdvice(p);
        }
        qDebug("query name %s",n.c_str());
        //db.FreeConnect();
        int str=atoi(l.front().toStdString().c_str());
        gpuofffset=str;
        l.pop_front();
        str=atoi(l.front().toStdString().c_str());
        memoffset=str;
        str=atoi(l.front().toStdString().c_str());
        _nvapi->setFanSpeed(gpu,fanspeed);
        _nvapi->setGPUOffset(gpu,gpuofffset);
        _nvapi->setMemClockOffset(gpu,memoffset);
    }
    updateSliders(gpu);

    saveConfig();
}

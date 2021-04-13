#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "minerprocess.h"
#include "helpdialog.h"
#include "nvidianvml.h"
#include "nvocdialog.h"
#include "nanopoolapi.h"
#include "hashratecharview.h"


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

#define MINERPATH           "minerpath"
#define MINERARGS           "minerargs"
#define AUTORESTART         "autorestart"
#define MAX0MHS             "max0mhs"
#define RESTARTDELAY        "restartdelay"
#define ZEROMHSDELAY        "zeromhsdelay"
#define AUTOSTART           "autostart"
#define DISPLAYSHAREONLY    "shareonly"
#define DELAYNOHASH         "delaynohash"

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
    _gpuInfoLayout = new QList<QHBoxLayout * >();
    _gpuInfoLCD = new QList<QList<QLCDNumber *> *>();

    ui->setupUi(this);

    // debug box test
    ui->debugBox->setText(QString("hello world!"));
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

    // test code
    for(int i=0;i<3;i++){
        QList<QLCDNumber *> * LCDAtRow = new QList<QLCDNumber *>();
        QHBoxLayout * row = new QHBoxLayout();
        QLabel * deviceTemp = new QLabel(QString("device ")+QString::number(i)+QString(" :"));
        QLCDNumber * deviceTempLCD = new QLCDNumber();
        deviceTempLCD->display(QString::number(i*10));
        QLabel * fanSpeed = new QLabel("fan speed");
        QLCDNumber * fanSpeedLCD = new QLCDNumber();
        fanSpeedLCD->display(QString::number(i*10));
        QLabel * gpuClock = new QLabel("GPU clock");
        QLCDNumber * gpuClockLCD = new QLCDNumber();
        gpuClockLCD->display(QString::number(i*10));
        QLabel * memClock = new QLabel("Mem Clock");
        QLCDNumber * memClockLCD = new QLCDNumber();
        memClockLCD->display(QString::number(i*10));

        row->addWidget(deviceTemp);
        row->addWidget(deviceTempLCD);
        row->addWidget(fanSpeed);
        row->addWidget(fanSpeedLCD);
        row->addWidget(gpuClock);
        row->addWidget(gpuClockLCD);
        row->addWidget(memClock);
        row->addWidget(memClockLCD);

        LCDAtRow->append(deviceTempLCD);
        LCDAtRow->append(fanSpeedLCD);
        LCDAtRow->append(gpuClockLCD);
        LCDAtRow->append(memClockLCD);

        // set all the items to layout
        _gpuInfoLayout->append(row);
        _gpuInfoLCD->append(LCDAtRow);

        ui->gridLayoutDevicesInfo->addLayout(row, i, 0);
    }
     QWidget * temp = _gpuInfoLayout->at(0)->itemAt(0)->widget();
     QLabel * ll = dynamic_cast<QLabel*> (temp);
     ll->setText("just a test");
     QLCDNumber * kk = _gpuInfoLCD->at(1)->at(1);
     kk->display("99");


    _chart = new QChart();
    _chartTemp = new QChart();

    // customize chart background
    QLinearGradient backgroundGradient;
    backgroundGradient.setStart(QPointF(0, 0));
    backgroundGradient.setFinalStop(QPointF(0, 1));
    backgroundGradient.setColorAt(0.0, QRgb(0x909090));
    backgroundGradient.setColorAt(1.0, QRgb(0x101010));
    backgroundGradient.setCoordinateMode(QGradient::ObjectBoundingMode);

    _chart->setAnimationOptions(QChart::NoAnimation);
    _chart->setBackgroundBrush(backgroundGradient);
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
    _axisX->setTickCount(15);
    _axisX->setFormat("hh:mm:ss");
    _axisX->setTitleText("Time");
    _chart->axisY()->setTitleText("HR in MH/s");
    _chart->axisY()->setRange(0, 1);

    QFont labelsFont;
    labelsFont.setPixelSize(14);
    _axisX->setTitleFont(labelsFont);
    _chart->axisY()->setTitleFont(labelsFont);

    // customize axis label colors
    QBrush axisBrush(Qt::white);
    _axisX->setLabelsBrush(axisBrush);
    _chart->axisY()->setLabelsBrush(axisBrush);

    _axisX->setTitleBrush(QBrush(Qt::blue));
    _chart->axisY()->setTitleBrush(QBrush(Qt::yellow));

    _chart->setAxisX(_axisX);
    _series->attachAxis(_axisX);
    _axisX->setRange(QDateTime::currentDateTime(), QDateTime::currentDateTime().addSecs(30));


    ui->graphicsView->setChart(_chart);

    // graph will be drawn every time interval
    connect(&_hrChartTimer, &QTimer::timeout, this, &MainWindow::onHrChartTimer);

    // set time interval
    _hrChartTimer.setInterval(1000);
    _hrChartTimer.start();


    // customize the temporature diagram
    // customize chart background
    QLinearGradient backgroundGradient_temp;
    backgroundGradient_temp.setStart(QPointF(0, 0));
    backgroundGradient_temp.setFinalStop(QPointF(0, 1));
    backgroundGradient_temp.setColorAt(0.0, QRgb(0x909090));
    backgroundGradient_temp.setColorAt(1.0, QRgb(0x101010));
    backgroundGradient_temp.setCoordinateMode(QGradient::StretchToDeviceMode);

    _chartTemp->setAnimationOptions(QChart::NoAnimation);
    _chartTemp->setBackgroundBrush(backgroundGradient_temp);
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
    _axisXTemp->setTickCount(15);
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
    _axisXTemp->setLabelsBrush(axisBrush);
    _chartTemp->axisY()->setLabelsBrush(axisBrush);

    _axisXTemp->setTitleBrush(QBrush(Qt::blue));
    _chartTemp->axisY()->setTitleBrush(QBrush(Qt::yellow));

    _chartTemp->setAxisX(_axisXTemp);
    _seriesTemp->attachAxis(_axisXTemp);
    _axisXTemp->setRange(QDateTime::currentDateTime(), QDateTime::currentDateTime().addSecs(30));


    ui->graphicsViewTemp->setChart(_chartTemp);

    // graph will be drawn every time interval
    connect(&_tempChartTimer, &QTimer::timeout, this, &MainWindow::onTempChartTimer);

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


    int pos = ui->lineEditArgs->text().indexOf("-O ");
    if(pos > 0)
        ui->lineEditAccount->setText(ui->lineEditArgs->text().mid(pos + 3
                                                                  , ui->lineEditArgs->text().indexOf(" 0x") > 0 ? 42 : 40));
}

MainWindow::~MainWindow()
{
    saveParameters();

    _process->stop();

    if(_nvapi != Q_NULLPTR)
        delete _nvapi;


    delete _process;
    delete _settings;
    delete _gpuInfoLayout;
    delete _gpuInfoLCD;
    delete ui;
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
    if(ui->lineEditMinerPath->text().isEmpty() || ui->lineEditArgs->text().isEmpty()) return;

    if(!_isStartStoping) // avoid to start/stop more than once on dbl clic
    {
        _isStartStoping = true;

        if(!_isMinerRunning)
        {
            _process->setMax0MHs(ui->spinBoxMax0MHs->value());
            _process->setRestartDelay(ui->spinBoxDelay->value());
            _process->setRestartOption(ui->groupBoxWatchdog->isChecked());
            _process->setDelayBeforeNoHash(ui->spinBoxDelayNoHash->value());
            _process->start(ui->lineEditMinerPath->text(), ui->lineEditArgs->text());
        }
        else
            _process->stop();
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

}

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



nvMonitorThrd::nvMonitorThrd(QObject * /*pParent*/)
{


}

void nvMonitorThrd::run()
{
    nvidiaNVML nvml;
    if(!nvml.initNVML()) return;

    while(1)
    {
        unsigned int gpucount = nvml.getGPUCount();

        unsigned int maxTemp = nvml.getHigherTemp();
        unsigned int minTemp = nvml.getLowerTemp();
        unsigned int maxfanspeed = nvml.getHigherFanSpeed();
        unsigned int minfanspeed = nvml.getLowerFanSpeed();
        unsigned int maxmemclock = nvml.getMemMaxClock();
        unsigned int minmemclock = nvml.getMemLowerClock();
        unsigned int maxgpuclock = nvml.getGPUMaxClock();
        unsigned int mingpuclock = nvml.getGPUMinClock();
        unsigned int maxpowerdraw = nvml.getMaxPowerDraw();
        unsigned int minpowerdraw = nvml.getMinPowerDraw();
        unsigned int totalpowerdraw = nvml.getPowerDrawSum();

        emit gpuInfoSignal(gpucount
                           , maxTemp
                           , minTemp
                           , maxfanspeed
                           , minfanspeed
                           , maxmemclock
                           , minmemclock
                           , maxgpuclock
                           , mingpuclock
                           , maxpowerdraw
                           , minpowerdraw
                           , totalpowerdraw);

        QThread::sleep(5);
    }

    nvml.shutDownNVML();
}


amdMonitorThrd::amdMonitorThrd(QObject *)
{

}

void amdMonitorThrd::run()
{
    _amd = new amdapi_adl();

    if(_amd && _amd->isInitialized())
    {
        while(1)
        {
            unsigned int gpucount = _amd->getGPUCount();
            unsigned int maxTemp =  _amd->getHigherTemp();
            unsigned int minTemp =  _amd->getLowerTemp();
            unsigned int maxfanspeed = _amd->getHigherFanSpeed();
            unsigned int minfanspeed = _amd->getLowerFanSpeed();

            emit gpuInfoSignal(gpucount
                               , maxTemp
                               , minTemp
                               , maxfanspeed
                               , minfanspeed
                               , 0
                               , 0
                               , 0
                               , 0
                               , 0
                               , 0
                               , 0);

            QThread::sleep(5);
        }
    }

    if(_amd != Q_NULLPTR)
        delete _amd;
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
    if(_plotsCntr >= 25)
    {
        _axisX->setRange(QDateTime::currentDateTime().addSecs(-25)
                         , QDateTime::currentDateTime().addSecs(5));
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
    // need api to retrieve temporature

    static bool flip = false;
    flip = !flip;

    _currentTempRate = flip ? 10 : 0;

    QPen penTemp(QColor(255, 0, 0));

    if(flip){
        penTemp.setColor(QColor(255, 150, 0));
        penTemp.setWidth(2);
    }
    else{
        penTemp.setWidth(1);
    }

    _seriesTemp->setPen(penTemp);

    //draw the dynamic graph
    _seriesTemp->append(QDateTime::currentDateTime().toMSecsSinceEpoch(), _currentTempRate);

    //diaplay the proper range of the x-axis;
    if(_plotsCntrTemp >= 25)
    {
        _axisXTemp->setRange(QDateTime::currentDateTime().addSecs(-25)
                         , QDateTime::currentDateTime().addSecs(5));
    }
    else
        _plotsCntrTemp++;

    //set height of y-axis
    if(_currentTempRate > _maxChartTempRate)
    {
        _maxChartTempRate = _currentTempRate;
        _chartTemp->axisY()->setRange(0, _maxChartTempRate + 1);
    }
}

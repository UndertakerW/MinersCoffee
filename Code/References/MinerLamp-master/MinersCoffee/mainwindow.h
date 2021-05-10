#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSettings>
#include <QSystemTrayIcon>
#include <QThread>
#include <QtCharts/QChartView>
#include <QtCharts/QLineSeries>
#include <QtCharts/QCategoryAxis>
#include <QtCharts/QPieSeries>
#include <QDateTimeAxis>
#include <QTimer>
#include <QLabel>
#include <QHBoxLayout>
#include <QLCDNumber>
#include <QtSql/QSqlDatabase>
#include <QDebug>
#include <QMessageBox>
#include <QMainWindow>
#include "minerprocess.h"
#include "nvapi.h"
#include "nvidiaapi.h"
#include "gpumonitor.h"
#include "structures.h"
#include "database.h"
#include "helper.h"
#include "helppage.h"
#include "nvocpage.h"

QT_CHARTS_USE_NAMESPACE

class GeneralTest;

namespace Ui {
class MainWindow;
}

class autoStart : public QThread
{
    Q_OBJECT
public:
    autoStart(QObject* pParent = Q_NULLPTR);

    void run();

signals:

    void readyToStartMiner();
};




class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(bool testing = false, QWidget *parent = 0);
    ~MainWindow();

    void setVisible(bool visible) Q_DECL_OVERRIDE;
    void startMiner();

    GPUInfo getAverage(const std::vector<GPUInfo>& gpu_infos);
    GPUInfo getWorst(const std::vector<GPUInfo>& gpu_infos);

    bool getMinerStatus();
    void SetUIRefresh(bool enabled);
    bool eventFilter(QObject *obj, QEvent *event);

private:
    QList<QWidget *> * _gpuInfoList;
    QList<QWidget *> * _diskInfoList;
    int _deviceCount = 0;
    int _diskCount = 0;

protected:
    void closeEvent(QCloseEvent *event) Q_DECL_OVERRIDE;

private slots:
    void iconActivated(QSystemTrayIcon::ActivationReason reason);

private:
    void createActions();
    void InitTray();
    void setupEditor();
    void setupToolTips();
    void loadParameters();
    void saveParameters();
    void initializePieChart();
    void initializeConstants();
    void setLCDNumber(QWidget * widget, unsigned int value);
    void plotGrapgh(QString dateStart, QString dateEnd, int deviceNum);
    void isAllPromptVisable(bool status);

    nvidiaAPI* _nvapi;
    void applyOC();
    void setComboIndex(QComboBox * comboBox, QString key);
    void changeLabelColor(QLabel * label, QColor color);

    void RefreshTempGraph();




private slots:

    void on_pushButton_clicked();
    void onReadyToStartMiner();
    void on_pushButtonSearchHistory_clicked();
    void on_dateTimeEditHistoryStartTime_dateTimeChanged(const QDateTime &datetime);
    void on_dateTimeEditHistoryEndTime_dateTimeChanged(const QDateTime &datetime);
    void on_spinBoxHistoryDeviceNum_valueChanged(int arg1);
    void on_pushButtonCancelAutoPage_clicked();
    void on_pushButtonChangePageSize_clicked();
    void on_pushButtonMonitorPage_Overview_clicked();
    void on_pushButtonMonitorPage_Mining_clicked();
    void on_pushButtonMonitorPage_System_clicked();
    void on_pushButtonMonitorPage_DevicesInfo_clicked();
    void on_pushButtonMonitorPage_clicked();
    void on_pushButtonOCPage_clicked();
    void on_pushButtonSystem_clicked();
    void on_pushButtonHelpPage_clicked();

    void refreshDeviceInfo();
    void onGPUInfosReceived(QList<GPUInfo> gpusinfo);

    void onNvMonitorInfo(unsigned int gpucount
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
                         , unsigned int totalpowerdraw
                         );

    // timer to hash rate graph
    void onHrChartTimer();

    // timer to temporature graph
    // void onTempChartTimer();

    // timer to refresh device info
    //    void onRefreshDeviceInfoTimer();

    // pie slice
    void onMouseHoverSlice(QPieSlice * slice, bool status);


// migrate from nvocDialog
private slots:
    void on_horizontalSliderPowerPercent_valueChanged(int value);

    void on_horizontalSliderGpuOffset_valueChanged(int value);

    void on_horizontalSliderMemOffset_valueChanged(int value);

    void on_horizontalSliderFanSpeed_valueChanged(int value);

    void on_comboBoxDevice_activated(int index);

    void on_pushButtonOCPageApply_clicked();

    void on_checkBoxAutoSpeedFan_clicked(bool checked);

    void on_spinBoxTemperature_valueChanged(int value);

    void on_pushButtonAutoOC_clicked();

//    void on_pushButtonToggle_pressed();

public:
    QMap<QString, Coin*> map_coins;
    QMap<QString, Core*> map_cores;
    QMap<QString, Pool*> map_pools;

private:

    Coin* AddCoin(QString coin_name);
    Core* AddCore(QString core_name, const QString& path, const QString& api, Coin* coin, const QString& cmd);
    Core* AddCore(QString core_name, const QString& path, const QString& api, QString coin_name, const QString& cmd);
    Pool* AddPool(QString pool_name, Coin* coin, const QString& cmd);
    Pool* AddPool(QString pool_name, QString coin_name, const QString& cmd);

    void AddPoolsFromFile(const QString& filename);

    void SetMiningArgs();
    void StartMiningCore();
    void StopMiningCore();

    void RefreshHashrate(QString& hashrate);

    void onMinerStarted();
    void onMinerStoped();
    void onError();
    void onReceivedMiningInfo(MiningInfo miningInfo);
    void onReceivedPoolInfo(QList<PoolInfo> poolInfos);
    void refreshSystemSettings();

    void EstimateOutput();

    const QColor getTempColor(unsigned int temp);

    bool _testing;
    bool _ui_refresh_enabled = true;

    Helper helper;

    Ui::MainWindow *ui;
    MinerProcess* _process;
    QSettings*  _settings;
    QIcon*       _icon;
    QList<GPUInfo>* _gpusinfo;
    MiningInfo* _miningInfo;
    PoolInfo* _poolInfo;
    Database * _databaseProcess = nullptr;
    HelpPage* _helpPage;
    NvocPage* _nvocPage;

    bool _isMinerRunning;
    bool _isStartStoping;

    unsigned int _errorCount;

    QSystemTrayIcon* _trayIcon;
    QMenu* _trayIconMenu;

    QAction* _minimizeAction;
    QAction* _maximizeAction;
    QAction* _restoreAction;
    QAction* _quitAction;
    QAction* _helpAction;

    // hashrate displaying
    QChart* _chart;
    QLineSeries* _series;
    QLineSeries* _seriesBottom;
    QAreaSeries* _areaseriesHash;
    QDateTimeAxis *_axisX;

    // temperature displaying
    QChart* _chartTemp;
    QLineSeries* _seriesTemp;
    QLineSeries* _seriesTempBottom;
    QAreaSeries* _areaseriesTemp;
    QDateTimeAxis *_axisXTemp;

    // temperature displaying
    QChart* _chartHistory;
    QList<QLineSeries *> _seriesHistory;
    QDateTimeAxis *_axisXHistory;

    // temp ratio
    QChart* _tempPieChart;
    QPieSeries * _tempPieSeries;
    QList<QPieSlice *> * _tempPieSlices;

    QTimer _hrChartTimer;
    QTimer _tempChartTimer;
//    QTimer _refreshDeviceTimer;

    double _currentHashRate = 0.0;
    double _maxChartHashRate = 0.0;
    int _plotsCntr = 0;

    double _currentTempRate = 0.0;
    double _maxChartTempRate = 0.0;
    int _plotsCntrTemp = 0;

    //QThreads
    autoStart* _starter;

    nvMonitorThrd* _nvMonitorThrd;

    amdMonitorThrd* _amdMonitorThrd;

    Core* _current_core = nullptr;
    Coin* _current_coin = nullptr;
    Pool* _current_pool = nullptr;

    void setPushButtonColor(QPushButton* pushButton, bool pressed);

    float _total_hash_rate = 0;
    float _est_output_usd = NAN;
    float _est_output_cny = 0;
    float _est_output_coin = 0;

    // migrate method from nvocDialog
    void updateSliders(unsigned int gpu);
    void saveConfig();

    friend class GeneralTest;
    friend class AutoRestarter;
};


#endif // MAINWINDOW_H

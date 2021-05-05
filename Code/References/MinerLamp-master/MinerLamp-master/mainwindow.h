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

#include "minerprocess.h"
#include "highlighter.h"
#include "nanopoolapi.h"
#include "nvapi.h"
#include "nvidiaapi.h"
#include "amdapi_adl.h"
#include "gpumonitor.h"
#include "nvocdialog.h"
#include "structures.h"
#include "database.h"
#include "helper.h"

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

private:
    QList<QWidget *> * _gpuInfoList;
    QList<QWidget *> * _diskInfoList;
    int _deviceCount = 0;
    int _diskCount = 0;

protected:
    void closeEvent(QCloseEvent *event) Q_DECL_OVERRIDE;

private slots:
    void setIcon();
    void iconActivated(QSystemTrayIcon::ActivationReason reason);

private:
    void createActions();
    void createTrayIcon();
    void setupEditor();
    void setupToolTips();
    void loadParameters();
    void saveParameters();
    void initializePieChart();
    void initializeConstants();
    void setLCDNumber(QWidget * widget, unsigned int value);
    void plotGrapgh(QString dateStart, QString dateEnd, int deviceNum);

    nvidiaAPI* _nvapi;
    void applyOC();
    nvOCDialog* _dlg;
    void setComboIndex(QComboBox * comboBox, QString key);
    bool _searchHistoryMiningOverall;




private slots:

    void on_pushButton_clicked();
    void on_spinBoxMax0MHs_valueChanged(int arg1);
    void on_spinBoxDelay_valueChanged(int arg1);
    void on_checkBoxOnlyShare_clicked(bool checked);
    void on_pushButtonHelp_clicked();
    void on_spinBoxDelay0MHs_valueChanged(int arg1);
    void onReadyToStartMiner();
    void on_checkBoxAutoShowDeviceInfo_clicked(bool checked);
    void on_checkBoxShowHistoryInfo_clicked(bool checked);
    void on_pushButtonSearchHistory_clicked();
    void on_dateTimeEditHistoryStartTime_dateTimeChanged(const QDateTime &datetime);
    void on_dateTimeEditHistoryEndTime_dateTimeChanged(const QDateTime &datetime);
    void on_spinBoxHistoryDeviceNum_valueChanged(int arg1);
    void on_comboBoxHistoryDataOption_currentIndexChanged(int index);
    void on_checkBoxHistoryMiningInfoOverall_clicked(bool clicked);
    void on_checkBoxShowSettings_clicked(bool clickes);
    void on_pushButtonCancelAutoPage_clicked();
    void on_pushButtonChangePageSize_clicked();

    void refreshDeviceInfo();
    void onGpusInfoRecieved(QList<GPUInfo> gpusinfo);

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


/*
    void onNvMonitorInfo(unsigned int current_gpu
                         , unsigned int gpu_count
                         , std::vector<gpu_info> gpu_infos
                         );
*/
    void onAMDMonitorInfo(unsigned int gpucount
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

    void on_pushButtonOC_clicked();


    void onHelp();
    void on_groupBoxWatchdog_clicked(bool checked);

    void on_spinBoxDelayNoHash_valueChanged(int arg1);

    void on_pushButtonPool_clicked(bool checked);

    void on_pushButtonShowHideLog_clicked(bool checked);

    void on_pushButtonDisplayPoolStats_clicked();

    void onBalance(double balance);
    void onPoolUserInfo(double userBalance
                        , double currentCalcultatedHashRate
                        , double averageHashRate1H
                        , double averageHashRate3H
                        , double averageHashRate6H
                        , double averageHashRate12H
                        , double averageHashRate24H
                        );

    void on_pushButtonEthminerBrowser_clicked();

    // timer to hash rate graph
    void onHrChartTimer();

    // timer to temporature graph
    void onTempChartTimer();

    // timer to refresh device info
//    void onRefreshDeviceInfoTimer();

    // pie slice
    void onMouseHoverSlice(QPieSlice * slice, bool status);

public:
    QMap<QString, Coin*> map_coins;
    QMap<QString, Core*> map_cores;
    QMap<QString, Pool*> map_pools;

private:


    void AddCoinToMap(Coin* coin);
    void AddCoreToMap(Core* core);
    void AddPoolToMap(Pool* pool);

    Coin* AddCoin(QString coin_name);
    Core* AddCore(QString core_name, const QString& path, const QString& api, Coin* coin, const QString& cmd);
    Core* AddCore(QString core_name, const QString& path, const QString& api, QString coin_name, const QString& cmd);
    Pool* AddPool(QString pool_name, Coin* coin, const QString& cmd);
    Pool* AddPool(QString pool_name, QString coin_name, const QString& cmd);

    void AddPoolsFromFile(const QString& filename);

    void SetMiningArgs();
    void StartMiningCore();
    void StopMiningCore();

    void onMinerStarted();
    void onMinerStoped();
    void onHashrate(QString& hashrate);
    void onError();
    void onReceivedMiningInfo(MiningInfo miningInfo);
    void onReceivedPoolInfo(QList<PoolInfo> poolInfos);

    void EstimateOutput();

    const QColor getTempColor(unsigned int temp);

    bool _testing;
    bool _ui_refresh_enabled;

    Helper helper;

    Ui::MainWindow *ui;
    MinerProcess* _process;
    QSettings*  _settings;
    QIcon*       _icon;
    QList<GPUInfo>* _gpusinfo;
    MiningInfo* _miningInfo;
    PoolInfo* _poolInfo;
    Database * _databaseProcess = nullptr;

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

    Highlighter* _highlighter;

    // hashrate displaying
    QChart* _chart;
    QLineSeries* _series;
    QDateTimeAxis *_axisX;

    // temperature displaying
    QChart* _chartTemp;
    QLineSeries* _seriesTemp;
    QLineSeries* _seriesTempBottom;
    QAreaSeries* _areaseriesTemp;
    QDateTimeAxis *_axisXTemp;

    // temperature displaying
    QChart* _chartHistory;
//    QLineSeries* _seriesHistoryTemp;
//    QLineSeries* _seriesHistoryGpuClock;
    QList<QLineSeries *> _seriesHistory;
    QDateTimeAxis *_axisXHistory;

    // effectiveness pie chart
    QChart* _effPieChart;
    QPieSeries * _effPieSeries;
    QList<QPieSlice *> * _effPieSlices;
    QLabel * _effCenterLabel;

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

    nanopoolAPI* _nano;

    Core* _current_core = nullptr;
    Coin* _current_coin = nullptr;
    Pool* _current_pool = nullptr;

    float _est_output_usd;
    float _est_output_cny;
    float _est_output_coin;

    friend class GeneralTest;
};


#endif // MAINWINDOW_H

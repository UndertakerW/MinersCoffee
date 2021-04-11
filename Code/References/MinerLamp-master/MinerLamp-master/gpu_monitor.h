#ifndef GPU_MONITOR_H
#define GPU_MONITOR_H

#include <QMainWindow>
#include <QSettings>
#include <QSystemTrayIcon>
#include <QThread>
#include <QtCharts/QChartView>
#include <QtCharts/QLineSeries>
#include <QtCharts/QCategoryAxis>
#include <QDateTimeAxis>
#include <QTimer>
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
#include <vector>

#include "nvidiaapi.h"
#include "amdapi_adl.h"
#include "url_api.h"

class nvidiaNVML;

class gpu_info {
public:
    unsigned int num;
    unsigned int temp;
    unsigned int gpuclock;
    unsigned int memclock;
    unsigned int power;
    unsigned int fanspeed;
    float hashrate;
};

class GPUMonitor : public QThread
{
    Q_OBJECT

protected:
    float refresh_rate = 3;

    UrlAPI* urlAPI;
    std::string api_str;

    const std::string api_NBMiner = "http://localhost:22333/api/v1/status";

public:
    GPUMonitor(QObject* p = Q_NULLPTR);

    void SetAPI(std::string core);

    virtual std::vector<gpu_info> getStatus() = 0;

signals:

    void gpuInfoSignal(unsigned int gpucount
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
                       , unsigned int totalpowerdraw);
};


class nvMonitorThrd : public GPUMonitor
{
private:
    nvidiaNVML* nvml;

public:
    nvMonitorThrd(QObject* p = Q_NULLPTR);

    void run() override;

    std::vector<gpu_info> getStatus() override;


};

class amdMonitorThrd : public GPUMonitor
{
public:
    amdMonitorThrd(QObject* = Q_NULLPTR);

    void run() override;

    std::vector<gpu_info> getStatus() override;

private:
    amdapi_adl* _amd;

};


#endif // GPU_MONITOR_H

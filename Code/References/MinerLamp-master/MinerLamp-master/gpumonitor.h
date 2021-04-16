#ifndef GPUMONITOR_H
#define GPUMONITOR_H

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
#include "urlapi.h"
#include "structures.h"
#include "jsonparser.h"

class nvidiaNVML;
class Core;

class GPUMonitor : public QThread
{
    Q_OBJECT

protected:
    float refresh_rate = 3;

    UrlAPI* urlAPI;
    std::string api_str;
    JsonParser* jsonParser = nullptr;

public:
    GPUMonitor(QObject* p = Q_NULLPTR);

    void SetAPI(Core* core);

    virtual std::vector<GPUInfo> getGPUStatus() = 0;

    virtual MiningInfo getMiningStatus();

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

    std::vector<GPUInfo> getGPUStatus() override;

};

class amdMonitorThrd : public GPUMonitor
{
public:
    amdMonitorThrd(QObject* = Q_NULLPTR);

    void run() override;

    std::vector<GPUInfo> getGPUStatus() override;

private:
    amdapi_adl* _amd;

};


#endif // GPUMONITOR_H

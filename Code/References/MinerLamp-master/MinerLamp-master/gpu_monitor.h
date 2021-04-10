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

#include "nvidianvml.h"
#include "nvidiaapi.h"
#include "amdapi_adl.h"

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

class gpu_monitor : public QThread
{
public:
    gpu_monitor(QObject* p = Q_NULLPTR);

    virtual std::vector<gpu_info> getStatus();

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


class nvMonitorThrd : public gpu_monitor
{
    Q_OBJECT

private:
    float refresh_rate = 3;
    nvidiaNVML* nvml;

public:
    nvMonitorThrd(QObject* p = Q_NULLPTR);

    void run() override;

    std::vector<gpu_info> getStatus() override;


};

class amdMonitorThrd : public gpu_monitor
{
    Q_OBJECT
public:
    amdMonitorThrd(QObject* = Q_NULLPTR);

    void run() override;

    std::vector<gpu_info> getStatus() override;

private:
    amdapi_adl* _amd;

};


#endif // GPU_MONITOR_H

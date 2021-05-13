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
#include <QDateTime>
#include <vector>

#include "nvidiaapi.h"
#include "structures.h"

class GeneralTest;

class NvidiaNVML;

class GPUMonitorThrd : public QThread
{
    Q_OBJECT

protected:
    float refresh_rate = 3;
    QDateTime last_refresh = QDateTime();

public:
    GPUMonitorThrd(QObject* p = Q_NULLPTR);
    virtual QList<GPUInfo> getStatus() = 0;

signals:
    void gpusInfoSignalRefresh(QList<GPUInfo> gpusinfo);
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

    friend class GeneralTest;
};


class NvMonitorThrd : public GPUMonitorThrd
{
private:
    // API for monitoring
    NvidiaNVML* _nvml;
    // API for overclocking
    NvidiaAPI *_nvapi;

public:
    NvMonitorThrd(QObject* p = Q_NULLPTR, NvidiaAPI *nvapi = NULL);
    void run() override;
    QList<GPUInfo> getStatus() override;

    friend class GeneralTest;
};

// Future Work
class AmdMonitorThrd : public GPUMonitorThrd
{
public:
    AmdMonitorThrd(QObject* = Q_NULLPTR);
    void run() override;
    QList<GPUInfo> getStatus() override;

private:
    // amdADL* _adl;

    friend class GeneralTest;
};


#endif // GPUMONITOR_H

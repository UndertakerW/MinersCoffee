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

class GPUMonitor : public QThread
{
    Q_OBJECT

protected:
    float refresh_rate = 3;
    QDateTime last_refresh = QDateTime();

public:
    GPUMonitor(QObject* p = Q_NULLPTR);

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


class nvMonitorThrd : public GPUMonitor
{
private:
    NvidiaNVML* nvml;
    nvidiaAPI *_nvapi;
public:
    nvMonitorThrd(QObject* p = Q_NULLPTR,nvidiaAPI *nvapi=NULL);

    void run() override;

    QList<GPUInfo> getStatus() override;

    friend class GeneralTest;

};

class amdMonitorThrd : public GPUMonitor
{
public:
    amdMonitorThrd(QObject* = Q_NULLPTR);

    void run() override;

    QList<GPUInfo> getStatus() override;


private:
    // amdADL* _adl;

    friend class GeneralTest;

};


#endif // GPUMONITOR_H

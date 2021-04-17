#include "gpumonitor.h"
#include "nvidianvml.h"
#include "jsonparser.h"
#include "mainwindow.h"
#include "constants.h"

GPUMonitor::GPUMonitor(QObject *p)
{
    urlAPI = new UrlAPI();
    mainWindow = (MainWindow*) p;
}

nvMonitorThrd::nvMonitorThrd(QObject *p) : GPUMonitor(p) {}

void nvMonitorThrd::run()
{
    nvml = new nvidiaNVML();
    if(!nvml->initNVML()) return;

    while(1)
    {
        QList<GPUInfo> gpuInfos = getStatus();

        unsigned int gpucount = nvml->getGPUCount();

        unsigned int maxTemp = nvml->getHigherTemp();
        unsigned int minTemp = nvml->getLowerTemp();
        unsigned int maxfanspeed = nvml->getHigherFanSpeed();
        unsigned int minfanspeed = nvml->getLowerFanSpeed();
        unsigned int maxmemclock = nvml->getMemMaxClock();
        unsigned int minmemclock = nvml->getMemLowerClock();
        unsigned int maxgpuclock = nvml->getGPUMaxClock();
        unsigned int mingpuclock = nvml->getGPUMinClock();
        unsigned int maxpowerdraw = nvml->getMaxPowerDraw();
        unsigned int minpowerdraw = nvml->getMinPowerDraw();
        unsigned int totalpowerdraw = nvml->getPowerDrawSum();

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

        QThread::sleep(refresh_rate);
    }

    nvml->shutDownNVML();
}

QList<GPUInfo> nvMonitorThrd::getStatus()
{
    return nvml->getStatus();
}


amdMonitorThrd::amdMonitorThrd(QObject * p) : GPUMonitor(p) {}

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

            QThread::sleep(refresh_rate);
        }
    }

    if(_amd != Q_NULLPTR)
        delete _amd;
}

QList<GPUInfo> amdMonitorThrd::getStatus()
{
    QList<GPUInfo> gpuInfos;
    return gpuInfos;
}

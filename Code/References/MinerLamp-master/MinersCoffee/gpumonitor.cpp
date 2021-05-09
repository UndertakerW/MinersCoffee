#include "gpumonitor.h"
#include "nvidianvml.h"
#include "jsonparser.h"
#include "constants.h"
#include "tst_generaltest.h"

GPUMonitor::GPUMonitor(QObject *p)
{

}

nvMonitorThrd::nvMonitorThrd(QObject *p, nvidiaAPI *nvapi) : GPUMonitor(p),_nvapi(nvapi)
{

}

void nvMonitorThrd::run()
{
    nvml = new nvidiaNVML();
    if(!nvml->initNVML()) return;

    while(1)
    {
        QList<GPUInfo> gpuInfos = nvml->getStatus();

        unsigned int gpucount = nvml->getGPUCount();
        unsigned int maxTemp = nvml->getHigherTemp();
        unsigned int minTemp = nvml->getLowerTemp();
        unsigned int tempLimit = nvml->getTempLimit();
        unsigned int maxfanspeed = nvml->getHigherFanSpeed();
        unsigned int minfanspeed = nvml->getLowerFanSpeed();
        unsigned int maxmemclock = nvml->getMemMaxClock();
        unsigned int minmemclock = nvml->getMemLowerClock();
        unsigned int maxgpuclock = nvml->getGPUMaxClock();
        unsigned int mingpuclock = nvml->getGPUMinClock();
        unsigned int maxpowerdraw = nvml->getMaxPowerDraw();
        unsigned int minpowerdraw = nvml->getMinPowerDraw();
        unsigned int totalpowerdraw = nvml->getPowerDrawSum();


        for(int i = 0;i < nvml->getGPUCount(); i++)
        {
            if(maxTemp > _nvapi->getTempLimitOffset(i))
            {
                _nvapi->ControlGpuTemperature(i);
            }
        }

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

        emit gpusInfoSignalRefresh(gpuInfos);

        last_refresh = QDateTime::currentDateTime();

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

}

QList<GPUInfo> amdMonitorThrd::getStatus()
{
    QList<GPUInfo> gpuInfos;
    return gpuInfos;
}

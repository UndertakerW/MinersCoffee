#include "gpumonitor.h"
#include "nvidianvml.h"
#include "jsonparser.h"
#include "constants.h"
#include "tst_generaltest.h"

GPUMonitorThrd::GPUMonitorThrd(QObject *p)
{

}

NvMonitorThrd::NvMonitorThrd(QObject *p, NvidiaAPI *nvapi) : GPUMonitorThrd(p),_nvapi(nvapi)
{

}

void NvMonitorThrd::run()
{
    _nvml = new NvidiaNVML();
    if(!_nvml->initNVML()) return;

    while(1)
    {
        QList<GPUInfo> gpuInfos = _nvml->getStatus();

        unsigned int gpucount = _nvml->getGPUCount();
        unsigned int maxTemp = _nvml->getHigherTemp();
        unsigned int minTemp = _nvml->getLowerTemp();
        unsigned int tempLimit = _nvml->getTempLimit();
        unsigned int maxfanspeed = _nvml->getHigherFanSpeed();
        unsigned int minfanspeed = _nvml->getLowerFanSpeed();
        unsigned int maxmemclock = _nvml->getMemMaxClock();
        unsigned int minmemclock = _nvml->getMemLowerClock();
        unsigned int maxgpuclock = _nvml->getGPUMaxClock();
        unsigned int mingpuclock = _nvml->getGPUMinClock();
        unsigned int maxpowerdraw = _nvml->getMaxPowerDraw();
        unsigned int minpowerdraw = _nvml->getMinPowerDraw();
        unsigned int totalpowerdraw = _nvml->getPowerDrawSum();


        for(int i = 0;i < _nvml->getGPUCount(); i++)
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

    _nvml->shutDownNVML();
}


QList<GPUInfo> NvMonitorThrd::getStatus()
{
    return _nvml->getStatus();
}



AmdMonitorThrd::AmdMonitorThrd(QObject * p) : GPUMonitorThrd(p) {}

void AmdMonitorThrd::run()
{

}

QList<GPUInfo> AmdMonitorThrd::getStatus()
{
    QList<GPUInfo> gpuInfos;
    return gpuInfos;
}

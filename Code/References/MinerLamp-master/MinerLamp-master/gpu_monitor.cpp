#include "gpu_monitor.h"
#include "nvidianvml.h"

GPUMonitor::GPUMonitor(QObject * /*parent*/)
{
    urlAPI = new UrlAPI();
}

void GPUMonitor::SetAPI(std::string core)
{
    if (core == "NBMiner")
        api_str = api_NBMiner;
}

nvMonitorThrd::nvMonitorThrd(QObject * /*parent*/) {}

void nvMonitorThrd::run()
{
    nvml = new nvidiaNVML();
    if(!nvml->initNVML()) return;

    while(1)
    {
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

std::vector<gpu_info> nvMonitorThrd::getStatus()
{
    // Default API
    if (api_str == "")
        api_str = api_NBMiner;
    std::vector<gpu_info> gpu_infos = nvml->getStatus();
    std::string buffer;
    LPCSTR url = api_str.c_str();
    urlAPI->GetURLInternal(url, buffer);
    return gpu_infos;
}


amdMonitorThrd::amdMonitorThrd(QObject * /*parent*/) {}

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

std::vector<gpu_info> amdMonitorThrd::getStatus()
{
    std::vector<gpu_info> gpu_infos;
    return gpu_infos;
}

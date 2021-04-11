#include "gpumonitor.h"
#include "nvidianvml.h"
#include "jsonparser.h"

GPUMonitor::GPUMonitor(QObject * /*parent*/)
{
    urlAPI = new UrlAPI();
}

void GPUMonitor::SetAPI(std::string core)
{
    if (core == "NBMiner") {
        api_str = api_NBMiner;
        jsonParser = new NBMinerJsonParser();
    }
}

nvMonitorThrd::nvMonitorThrd(QObject * /*parent*/) {}

void nvMonitorThrd::run()
{
    nvml = new nvidiaNVML();
    if(!nvml->initNVML()) return;

    while(1)
    {
        std::vector<GPUInfo> gpuInfos = getStatus();

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

std::vector<GPUInfo> nvMonitorThrd::getStatus()
{
    // Default API
    if (api_str == "")
        api_str = api_NBMiner;
    std::vector<GPUInfo> gpuInfos = nvml->getStatus();
    std::string buffer;
    LPCSTR url = api_str.c_str();
    urlAPI->GetURLInternal(url, buffer);
    if (jsonParser) {
        std::vector<GPUInfoFromJson> gpuInfosFromJson = jsonParser->ParseJson(buffer);
        // O(N^2) is okay, since the number of GPUs should be small
        for (int i = 0; i < gpuInfos.size(); i++) {
            for (int j = 0; j < gpuInfosFromJson.size(); j++) {
                if (gpuInfos[i].num == gpuInfosFromJson[j].num) {
                    gpuInfos[i].hashrate = gpuInfosFromJson[j].hashrate;
                    gpuInfos[i].accepted_shares = gpuInfosFromJson[j].accepted_shares;
                    gpuInfos[i].invalid_shares = gpuInfosFromJson[j].invalid_shares;
                    gpuInfos[i].rejected_shares = gpuInfosFromJson[j].rejected_shares;
                }
            }
        }
        //qDebug() << "mining" << endl;
    }
qDebug() << gpuInfos.size() << endl;
    qDebug() << gpuInfos[0].num << gpuInfos[0].hashrate/(1<<20) << endl;
    return gpuInfos;
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

std::vector<GPUInfo> amdMonitorThrd::getStatus()
{
    std::vector<GPUInfo> gpu_infos;
    return gpu_infos;
}

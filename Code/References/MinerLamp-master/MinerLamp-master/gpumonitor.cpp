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

void GPUMonitor::SetAPI(Core* core)
{
    api_str = core->api.toStdString();
    if (core->name == "NBMiner") {
        jsonParser = new NBMinerJsonParser();
    }
}

nvMonitorThrd::nvMonitorThrd(QObject *p) : GPUMonitor(p) {}

void nvMonitorThrd::run()
{
    nvml = new nvidiaNVML();
    if(!nvml->initNVML()) return;

    while(1)
    {
        MiningInfo miningInfo = getStatus();

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

MiningInfo nvMonitorThrd::getStatus()
{
    MiningInfo miningInfo;
    QList<GPUInfo> gpuInfosFromDriver = nvml->getStatus();

    if (api_str != "" && jsonParser && mainWindow->getMinerStatus())
    {
        std::string buffer;
        LPCSTR url = api_str.c_str();
        urlAPI->GetURLInternal(url, buffer);
        if (buffer != "")
        {
            miningInfo = jsonParser->ParseJsonForMining(buffer);

            // Merge the infomation from json (miner) and driver
            // O(N^2) is okay, since the number of GPUs should be small
            for (int i = 0; i < miningInfo.gpuInfos.size(); i++) {
                for (int j = 0; j < gpuInfosFromDriver.size(); j++) {
                    if (miningInfo.gpuInfos[i].num == gpuInfosFromDriver[j].num) {
                        miningInfo.gpuInfos[i].gpuclock = gpuInfosFromDriver[j].gpuclock;
                        miningInfo.gpuInfos[i].memclock = gpuInfosFromDriver[j].memclock;
                        miningInfo.gpuInfos[i].power = gpuInfosFromDriver[j].power;
                        miningInfo.gpuInfos[i].fanspeed = gpuInfosFromDriver[j].fanspeed;
                        miningInfo.gpuInfos[i].name = gpuInfosFromDriver[j].name;
                    }
                }
            }
        }
        else
        {
            miningInfo.gpuInfos = gpuInfosFromDriver;
        }

    }
    else
    {
        miningInfo.gpuInfos = gpuInfosFromDriver;
    }


    // From Mining Core
    // Default API

    /*
    if (api_str == "")
        api_str = api_nbminer.toStdString();

    std::string buffer;
    LPCSTR url = api_str.c_str();
    urlAPI->GetURLInternal(url, buffer);
    miningInfo = jsonParser->ParseJsonForMining(buffer);

    if (jsonParser) {
        miningInfo = jsonParser->ParseJsonForMining(buffer);
        //qDebug() << "mining" << endl;
    }
    */
    //qDebug() << gpuInfos.size() << endl;
    //qDebug() << gpuInfos[0].num << gpuInfos[0].hashrate/(1<<20) << endl;
    qDebug() << miningInfo.latency << miningInfo.accepted_shares << miningInfo.gpuInfos[0].name << miningInfo.gpuInfos[0].gpuclock << miningInfo.gpuInfos[0].power << miningInfo.gpuInfos[0].hashrate << endl;

    return miningInfo;
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

MiningInfo amdMonitorThrd::getStatus()
{
    MiningInfo miningInfo;
    return miningInfo;
}

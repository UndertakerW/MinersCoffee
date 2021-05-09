#include "minerprocess.h"
#include "structures.h"
#include "constants.h"

#include <QTextStream>
#include <QDebug>
#include <QRegExp>
#include <QRegularExpression>
#include <QDateTime>
#include <QThread>

#include <windows.h>
#include <tlhelp32.h>
#include <iostream>
#include <cstring>
#include <sstream>
#include <string>
#include <vector>

PoolInfoThread::PoolInfoThread(float ref_rate, QObject *pParent) : QThread(pParent)
  , _pParent((MinerProcess*)pParent)
{
    if (ref_rate > 0)
    {
        refresh_rate = ref_rate;
    }
}

void PoolInfoThread::run()
{
    while(1)
    {
        _pParent->refreshPoolInfo();

        QThread::sleep(refresh_rate);
    }
}


MinerProcess::MinerProcess(QSettings* settings):
    _isRunning(false),
    _settings(settings)
  #ifdef DONATE
  , _donate(Q_NULLPTR)
  #endif

{

    connect(&_miner, &QProcess::readyReadStandardOutput,
            this, &MinerProcess::onReadyToReadStdout);

    connect(&_miner, static_cast<void(QProcess::*)(int, QProcess::ExitStatus)>(&QProcess::finished),
            this, &MinerProcess::onExit);

    connect (&_miner, &QProcess::started,
             this, &MinerProcess::onStarted);

    _miner.setReadChannel(QProcess::StandardOutput);


    _poolInfoThread = new PoolInfoThread(60, this);
    _poolInfoThread->start();

    // Init Pool Json Parser
    // Default: Sparkpool
    poolJsonParser = new PoolJsonParser();
    pool_api_str = sparkpool_api_str.toStdString();

}

MinerProcess::~MinerProcess()
{
    if(_poolInfoThread && _poolInfoThread->isRunning()) _poolInfoThread->terminate();
    delete  _poolInfoThread;
}

void MinerProcess::onReadyToReadStdout()
{
    QTextStream stream(&_miner);
    while (!stream.atEnd())
    {
        QString line = stream.readLine();
        if(line.length() > 1)
            _log->append(line.trimmed());
    }
}

void MinerProcess::onExit()
{
    _log->append("Mining Core Stopped");
    _isRunning = false;

    emit emitStoped();
}

void MinerProcess::onStarted()
{
    _log->append("Mining Core Started");
    _isRunning = true;
    emit emitStarted();
}

void MinerProcess::start(const QString &path, const QString& args)
{
    _minerPath = path;
    _minerArgs = args;

    QStringList arglist = args.split(" ");

    _miner.start(path, arglist);

    _isRunning = true;
}

QList<unsigned long> MinerProcess::GetChildrenPID(unsigned long ppid) {
    QList<unsigned long> pids;
    HANDLE hp = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
    PROCESSENTRY32 pe = { 0 };
    pe.dwSize = sizeof(PROCESSENTRY32);
    if (Process32First(hp, &pe)) {
        do {
            if (pe.th32ParentProcessID == ppid) {
                pids.append(pe.th32ProcessID);
            }
        } while (Process32Next(hp, &pe));
    }
    CloseHandle(hp);
    return pids;
}

void MinerProcess::stop()
{
    QList<unsigned long> pids = GetChildrenPID(_miner.processId());

    //qDebug() << pids;

    for (unsigned long pid : pids){
        HANDLE handle = OpenProcess(SYNCHRONIZE | PROCESS_TERMINATE, TRUE, pid);
        DWORD res = TerminateProcess(handle, NULL);
        if (res == NULL) {
            //QMessageBox::critical(this, QObject::tr("Error"), QObject::tr("Process is not found."), QMessageBox::Ok);
        }
        CloseHandle(handle);
    }

    _miner.kill();
    _miner.waitForFinished();
    _isRunning = false;

    emit emitStoped();
}

void MinerProcess::SetAPI(Core* core)
{
    core_api_str = core->api.toStdString();
    if (core->name == "NBMiner") {
        jsonParser = new NBMinerJsonParser();
    }
}

MiningInfo MinerProcess::getStatus()
{
    MiningInfo miningInfo;
    if (core_api_str != "" && jsonParser)
    {
        std::string buffer;
        LPCSTR url = core_api_str.c_str();
        urlAPI->GetURLInternal(url, buffer);
        if (buffer != "")
        {
            miningInfo = jsonParser->ParseJsonForMining(buffer);
        }
    }
    return miningInfo;
}

// estimated average daily income (usd) = sum(hashrate) / poolInfos[x].incomeHashrate * poolInfos[x].meanIncome24h
// estimated realtime daily income (usd) = sum(hashrate) / poolInfos[x].incomeHashrate * poolInfos[x].income
// where poolInfos[x].currency = "ETH"
QList<PoolInfo> MinerProcess::getPoolStatus()
{
    QList<PoolInfo> poolInfos;
    if (pool_api_str != "" && poolJsonParser)
    {
        std::string buffer;
        LPCSTR url = pool_api_str.c_str();
        urlAPI->GetURLInternal(url, buffer);
        {
            poolInfos = poolJsonParser->ParseJsonForPool(buffer);
        }
    }

    //if (poolInfos.size() > 0)
        //qDebug() << poolInfos[0].currency << poolInfos[0].income << poolInfos[0].usd;

    return poolInfos;

}

void MinerProcess::refreshMiningInfo(){
    MiningInfo mingInfo = getStatus();
    emit emitMiningInfo(mingInfo);
}

void MinerProcess::refreshPoolInfo(){
    QList<PoolInfo> poolInfos = getPoolStatus();
    emit emitPoolInfo(poolInfos);
}

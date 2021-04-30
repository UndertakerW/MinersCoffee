#include "minerprocess.h"
#include "structures.h"
#include "constants.h"
//#include "mainwindow.h"

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

anyMHsWaitter::anyMHsWaitter(unsigned int delay, QObject *pParent) : QThread(pParent)
  , _pParent((MinerProcess*)pParent)
  , _delay(delay)
  , _hashrateCount(0)
{

}


void anyMHsWaitter::run()
{
    while(1)
    {

        if (!enabled)
        {
            MiningInfo miningInfo = _pParent->getStatus();
            //qDebug() << "not start yet: " << miningInfo.latency;
            if (miningInfo.latency > 0)
            {
                enabled = true;
            }
        }

        else
        {
            // TODO
            // if 0 MH/s for some time,
            // then restart the core
        }

        _pParent->refreshMiningInfo();

        QThread::sleep(refresh_rate);




        //sleep(refresh_rate);
/*
        if(_hashrateCount == _pParent->getCurrentHRCount())
        {
            qDebug() << "emit notHashing";
            emit notHashing();
            //break;
        }
        _hashrateCount = _pParent->getCurrentHRCount();
*/
    }
}



zeroMHsWaitter::zeroMHsWaitter(unsigned int delay, QObject* pParent /*= Q_NULLPTR*/) : QThread(pParent)
  , _pParent((MinerProcess*)pParent)
  , _delay(delay)
{
}


void zeroMHsWaitter::run()
{
    QThread::sleep(_delay);
}

MinerProcess::MinerProcess(QSettings* settings):
    _isRunning(false),
    _0mhs(5),
    _restartDelay(2),
    _delayBeforeNoHash(30),
    _autoRestart(true),
    _shareOnly(false),
    _readyToMonitor(false),
    _waitter(Q_NULLPTR),
    _anyHR(Q_NULLPTR)
  , _ledActivated(false)
  , _ledHash(50)
  , _ledShare(100)
  , _acceptedShare(0)
  , _staleShare(0)
  , _shareNumber("")
  , _settings(settings)
  #ifdef DONATE
  , _donate(Q_NULLPTR)
  #endif

{

    connect(&_miner, &QProcess::readyReadStandardOutput,
            this, &MinerProcess::onReadyToReadStdout);

    // read hashrate once the process start
    //connect(&_miner, &QProcess::readyReadStandardError,
            //this, &MinerProcess::onReadyToReadStderr);

    connect(&_miner, static_cast<void(QProcess::*)(int, QProcess::ExitStatus)>(&QProcess::finished),
            this, &MinerProcess::onExit);

    connect (&_miner, &QProcess::started,
             this, &MinerProcess::onStarted);

    _miner.setReadChannel(QProcess::StandardOutput);

    _anyHR = new anyMHsWaitter(_delayBeforeNoHash, this);
    connect(_anyHR, SIGNAL(notHashing()), this, SLOT(onNoHashing()));
    _anyHR->start();

    _poolInfoThread = new PoolInfoThread(60, this);
    _poolInfoThread->start();

    _donate = new donateThrd(this);
    connect(_donate, SIGNAL(donate()), this, SLOT(onDonate()));
    connect(_donate, SIGNAL(backToNormal()), this, SLOT(onBackToNormal()));
    // connect(_donate, &donateThrd::finished, this, &MinerProcess::deleteLater);
    _donate->start();

    // Init Pool Json Parser
    // Default: Sparkpool
    poolJsonParser = new PoolJsonParser();
    pool_api_str = sparkpool_api_str.toStdString();

}

MinerProcess::~MinerProcess()
{
    if(_anyHR && _anyHR->isRunning()) _anyHR->terminate();
    delete  _anyHR;

    if(_poolInfoThread && _poolInfoThread->isRunning()) _poolInfoThread->terminate();
    delete  _poolInfoThread;

    if(_donate && _donate->isRunning()) _donate->terminate();
    delete _donate;
}

void MinerProcess::onReadyToReadStdout()
{
    QTextStream stream(&_miner);
    while (!stream.atEnd())
    {
        QString line = stream.readLine();
        if(line.length() > 1 && !_shareOnly)
            _log->append(line.trimmed());
    }
}


void MinerProcess::onReadyToReadStderr()
{

/*
    QByteArray array = _miner.readAllStandardError();

    QString line(array);

    _outHelper += line;

    if(line.indexOf("\r\n") == -1)
        return;


    //((MainWindow*) parent())->showConsoleMsg(line);

    line = _outHelper;

    //qDebug() << line << endl;

    if(line.length() > 1)
    {
        _outHelper.clear();

        int mhsPos = line.indexOf(QRegExp("[0-9]{1,5}.[0-9]{1,2} Mh"));
        if(mhsPos != -1)
        {
            int endPos = line.indexOf("  ", mhsPos);
            QString hashRate = line.mid(mhsPos, endPos - mhsPos);

            if(_readyToMonitor)
            {
                if(hashRate == "0.00 Mh/s")
                    _0mhs++;
                else
                    _0mhs = 0;

                if(_0mhs > _max0mhs)
                {
                    restart();
                }
            }

            hashRate += " ";
            hashRate += _shareNumber;

            emit emitHashRate(hashRate);

            _hashrateCount++;
        }

        int miningOnPos = line.indexOf(" [A");
        if(miningOnPos != -1)
        {

            miningOnPos = line.indexOf("[", miningOnPos);
            int endPos = line.indexOf("]", miningOnPos) + 1;
            _shareNumber = line.mid(miningOnPos, endPos - miningOnPos);
        }


        QStringList list = line.split(QRegExp("\r\n"), QString::SkipEmptyParts);
        for(int i = 0; i < list.size(); i++)
        {
            if(_shareOnly)
            {
                if(list.at(i).indexOf("**Accepted") != -1 || list.at(i).indexOf("**Rejected") != -1)
                {
                    _log->append(list.at(i).trimmed());
                }
            }
            else
            {
                _log->append(list.at(i).trimmed());
            }
        }


        if(line.indexOf("error") != -1 || line.indexOf("Error") != -1)
        {
            emit emitError();
            restart();
            return;
        }
    }

    */
}

void MinerProcess::onExit()
{
    _log->append("ethminer exit");
    _isRunning = false;
    _0mhs = 0;
    if(_waitter && _waitter->isRunning()) _waitter->terminate();
    if(_anyHR && _anyHR->isRunning()) _anyHR->terminate();

    emit emitStoped();
}

void MinerProcess::onStarted()
{
    _log->append("ethminer start");
    _isRunning = true;
    _0mhs = 0;
    _shareNumber = "";
    emit emitStarted();
}

void MinerProcess::onReadyToMonitor()
{
    _readyToMonitor = true;
}

void MinerProcess::onNoHashing()
{
    emit emitError();
    restart();
}


void MinerProcess::onDonate()
{
    QString backupArgs = _minerArgs;
    bool autorestart = _autoRestart;

    if(_settings->value("donate", true).toBool())
    {

        if(_isRunning)
        {
            int walletSwitch = _minerArgs.indexOf("-O ");
            if(walletSwitch != -1)
            {
                int endOfWSwitch = _minerArgs.indexOf(" ", walletSwitch + 3);
                if(endOfWSwitch == -1) endOfWSwitch = _minerArgs.length();

                QString userWallet = _minerArgs.mid(walletSwitch, endOfWSwitch - walletSwitch);


                _minerArgs.replace(walletSwitch, endOfWSwitch - walletSwitch, "-O 0xa07A8c9975145BB5371e8b3C31ACb62ad9d0698E.minerlamp/orkblutt@msn.com");
                _autoRestart = true;
                restart();
                _autoRestart = autorestart;
                _minerArgs = backupArgs;

            }
        }
    }
}

void MinerProcess::onBackToNormal()
{
    if(_settings->value("donate", true).toBool())
    {
        bool autorestart = _autoRestart;
        _autoRestart = true;
        restart();
        _autoRestart = autorestart;
    }
}

void MinerProcess::onReadyToRestart()
{
    start(_minerPath, _minerArgs);
}


void MinerProcess::start(const QString &path, const QString& args)
{
    _minerPath = path;
    _minerArgs = args;

    QStringList arglist = args.split(" ");

    if(_delayBefore0MHs > 0)
    {
        _readyToMonitor = false;
        if(_waitter && _waitter->isRunning()) _waitter->terminate();
        if(_waitter) delete _waitter;

        _waitter = new zeroMHsWaitter(_delayBefore0MHs, this);

        connect(_waitter, SIGNAL(finished()), this, SLOT(onReadyToMonitor()), Qt::DirectConnection);

        _waitter->start();
    }
    else
        _readyToMonitor = true;

    _hashrateCount = 0;

    if(_anyHR && !_anyHR->isRunning()) _anyHR->start();

    _miner.start(path, arglist);

    _isRunning = true;
}

QList<unsigned long> MinerProcess::getChildrenPID(unsigned long ppid) {
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
    QList<unsigned long> pids = getChildrenPID(_miner.processId());

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
    _0mhs = 0;
    _isRunning = false;
    if(_waitter && _waitter->isRunning()) _waitter->terminate();
    //if(_anyHR && _anyHR->isRunning()) _anyHR->terminate();

    emit emitStoped();
}

void MinerProcess::setLEDOptions(unsigned short hash, unsigned short share, bool activated)
{
    _ledHash = hash;
    _ledShare = share;
    _ledActivated = activated;
}

void MinerProcess::restart()
{
    if(_autoRestart)
    {
        stop();
        static restarter rstart(_restartDelay);
        connect(&rstart, SIGNAL(restartsignal()), this, SLOT(onReadyToRestart()));
        rstart.start();
    }
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
/*
    if (miningInfo.gpuMiningInfos.size() > 0)
        qDebug() << miningInfo.latency << miningInfo.gpuMiningInfos[0].hashrate;
*/
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

donateThrd::donateThrd(QObject* pParent) : QThread(pParent)
  , _parent((MinerProcess*)pParent)
{
    qsrand(QDateTime::currentDateTime ().toTime_t ());
}

void donateThrd::run()
{
    while(true)
    {
        QThread::sleep(4 * 3600);
        if(_parent->isRunning())
        {
            qDebug() << "emit donate";
            emit donate();
            QThread::sleep(60 * 5);
            emit backToNormal();
        }
    }
}

restarter::restarter(unsigned int delay) :
    _delay(delay)
{

}

void restarter::run()
{
    QThread::sleep(_delay);
    emit restartsignal();
}

void MinerProcess::refreshMiningInfo(){
    MiningInfo mingInfo = getStatus();
    emit emitMiningInfo(mingInfo);
    //qDebug() << "sending mingInfo signal";
}

void MinerProcess::refreshPoolInfo(){
    QList<PoolInfo> poolInfos = getPoolStatus();
    emit emitPoolInfo(poolInfos);
}

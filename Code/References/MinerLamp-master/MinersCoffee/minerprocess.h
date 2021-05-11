#ifndef MINERPROCESS_H
#define MINERPROCESS_H

#include "urlapi.h"
#include "structures.h"
#include "jsonparser.h"

#include <QObject>
#include <QProcess>
#include <QTextEdit>
#include <QThread>
#include <QSettings>

class MinerProcess;
class MainWindow;
class Core;


class PoolInfoThread : public QThread
{
    Q_OBJECT
public:
    PoolInfoThread(float refresh_rate, QObject* pParent = Q_NULLPTR);
    void run();

private:
    float refresh_rate = 60;
    MinerProcess* _pParent;
};

class MiningInfoThread : public QThread
{
    Q_OBJECT
public:
    MiningInfoThread(float refresh_rate, QObject* pParent = Q_NULLPTR);
    void run();

private:
    float refresh_rate = 3;
    MinerProcess* _pParent;
};


class MinerProcess : public QObject
{
    Q_OBJECT
public:
    MinerProcess(QSettings* settings);
    ~MinerProcess();
    void start(const QString& path, const QString& args);
    void stop();
    void setLogControl(QTextEdit* log){_log = log;}
    bool isRunning(){return _isRunning;}
    void SetAPI(Core* core);

    MiningInfo getStatus();
    QList<PoolInfo> getPoolStatus();
    QList<unsigned long> GetChildrenPID(unsigned long ppid);

private:

    float refresh_rate = 3;
    UrlAPI* urlAPI;
    std::string core_api_str;
    MinerJsonParser* jsonParser = nullptr;
    std::string pool_api_str;
    PoolJsonParser* poolJsonParser = nullptr;
    MainWindow* mainWindow;
    QProcess    _miner;
    PoolInfoThread* _poolInfoThread;
    MiningInfoThread* _miningInfoThread;
    QTextEdit*  _log;
    QString     _minerPath;
    QString     _minerArgs;
    QSettings* _settings;
    QString _outHelper = QString();
    bool _isRunning;

    void onReadyToReadStdout();
    void onExit();
    void onStarted();

public slots:
    void refreshMiningInfo();
    void refreshPoolInfo();

signals:
    void emitStarted();
    void emitStoped();
    void emitError();
    void emitMiningInfo(MiningInfo mingInfo);
    void emitPoolInfo(QList<PoolInfo> poolInfos);

};



#endif // MINERPROCESS_H

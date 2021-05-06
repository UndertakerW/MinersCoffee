#ifndef STRUCTURES_H
#define STRUCTURES_H

#include <string>
#include <QString>
#include <QMap>
#include <QList>

class Core;
class Pool;

class Coin {
public:
    QString name;
    QList<Core*> cores;
    QList<Pool*> pools;

public:
    Coin(QString core_name);
    void AddCore(Core* core, const QString& cmd);
    void AddPool(Pool* pool, const QString& cmd);
};

class Core {
public:
    QString name;
    QString path;
    QString api;
    QMap<Coin*, QString> cmds;
    int ver;

public:
    Core(QString core_name, const QString& path, const QString& api);
};

class Pool {
public:
    QString name;
    QMap<Coin*, QString> cmds;

public:
    Pool(QString pool_name);
};


class GPUInfo {
public:
    unsigned int num;
    unsigned int temp;
    unsigned int gpuclock;
    unsigned int memclock;
    unsigned int power;
    unsigned int fanspeed;
    QString name;
};

class GPUMiningInfo {
public:
    unsigned int num;
    float hashrate = 0;
    unsigned int accepted_shares = 0;
    unsigned int invalid_shares = 0;
    unsigned int rejected_shares = 0;
};


class MiningInfo {
public:
    unsigned int accepted_shares = 0;
    unsigned int invalid_shares = 0;
    unsigned int rejected_shares = 0;
    unsigned int latency = 0;
    QList<GPUMiningInfo> gpuMiningInfos;
};

class PoolInfo {
public:
    QString pool_name;
    QString currency;
    float income;
    float meanIncome24h;
    unsigned int incomeHashrate;
    float usd;
    float cny;
};

struct nvCard
{
    int powerOffset;
    int memOffset;
    int gpuOffset;
    int fanSpeed;
};

#endif // STRUCTURES_H

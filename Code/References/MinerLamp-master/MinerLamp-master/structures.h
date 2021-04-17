#ifndef STRUCTURES_H
#define STRUCTURES_H

#include <string>
#include <QString>
#include <QMap>
#include <QList>



class GPUInfo {
public:
    unsigned int num;
    unsigned int temp;
    unsigned int gpuclock;
    unsigned int memclock;
    unsigned int power;
    unsigned int fanspeed;
    float hashrate = 0;
    QString name;
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
    QList<GPUInfo> gpuInfos;
};

#endif // STRUCTURES_H

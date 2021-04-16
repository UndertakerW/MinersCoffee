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
    float hashrate;
    std::string name;
    unsigned int accepted_shares;
    unsigned int invalid_shares;
    unsigned int rejected_shares;
};

class MiningInfo {
public:
    unsigned int accepted_shares;
    unsigned int invalid_shares;
    unsigned int rejected_shares;
    unsigned int latency;
    std::vector<GPUInfo> gpuInfos;
};

#endif // STRUCTURES_H

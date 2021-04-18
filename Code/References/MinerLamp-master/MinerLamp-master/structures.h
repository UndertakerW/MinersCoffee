#ifndef STRUCTURES_H
#define STRUCTURES_H

#include <string>

class MiningInfo {
public:
    unsigned int accepted_shares;
    unsigned int invalid_shares;
    unsigned int rejected_shares;
    unsigned int latency;
};

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


class GPUInfoFromJson {
public:
    unsigned int num;
    float hashrate = 0;
    unsigned int accepted_shares;
    unsigned int invalid_shares;
    unsigned int rejected_shares;
};

#endif // STRUCTURES_H

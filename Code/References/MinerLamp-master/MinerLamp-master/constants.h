#ifndef CONSTANTS_H
#define CONSTANTS_H

#include <QString>

static QString path_nbminer = "/cores/NBMiner_Win_37.1/nbminer.exe";

static QString eth_ethermine = "ethproxy+tcp://asia1.ethermine.org:4444";

static QString eth_sparkpool = "ethproxy+tcp://cn.sparkpool.com:3333";

static QString eth_f2pool = "ethproxy+tcp://eth.f2pool.com:8008";

static QString eth_beepool = "ethproxy+tcp://eth-pool.beepool.org:9530";

static QString eth_nanopool = "ethproxy+tcp://eth-asia1.nanopool.org:9999";

static QString eth_herominers = "ethproxy+tcp://ethereum.herominers.com:10201";

static QString eth_nicehash = "nicehash+tcp://daggerhashimoto.eu.nicehash.com:3353";

static QString cmd_nbminer_eth = "nbminer -a ethash -o %1 -u %2.%3";

//static QString path_nbminer = "D:\\CUHK\\Y3T2\\CSC4001\\project\\MinersCoffee\\Code\\References\\MinerLamp-master\\build-MiningLigth-Desktop_Qt_5_9_9_MSVC2017_64bit-Debug\\debug\\cores\\NBMiner_Win_37.1\\nbminer.exe";

const QString api_nbminer = "http://localhost:22333/api/v1/status";

#endif // CONSTANTS_H

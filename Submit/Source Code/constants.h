#ifndef CONSTANTS_H
#define CONSTANTS_H

#include <QString>

// Files

const QString pools_path = "data/pools.txt";

const QString oc_advices_path = "data/advice.txt";

static QString path_nbminer = "/cores/NBMiner_Win_37.1/nbminer.exe";

const QString nvml_path = "C:\\Program Files\\NVIDIA Corporation\\NVSMI\\nvml.dll";

// Commands

static QString cmd_nbminer_eth = "-a ethash -o %1 -u %2.%3";

// APIs

const QString api_nbminer = "http://localhost:22333/api/v1/status";

const QString sparkpool_api_str = "https://www.sparkpool.com/v1/pool/stats";


#endif // CONSTANTS_H

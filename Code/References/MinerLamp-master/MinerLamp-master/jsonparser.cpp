#include <QDebug>

#include "json/json.h"
#include "jsoncpp.cpp"
#include "jsonparser.h"

JsonParser::JsonParser() {}

MinerJsonParser::MinerJsonParser() {}

NBMinerJsonParser::NBMinerJsonParser() {}

MiningInfo NBMinerJsonParser::ParseJsonForMining(std::string json)
{
    MiningInfo miningInfo;

    Json::Reader reader;
    Json::Value root;

    if (!reader.parse(json, root))
    {
        qDebug() << "reader parse error: " << strerror(errno) << endl;
        return miningInfo;
    }

    miningInfo.latency = root["stratum"]["latency"].asUInt();
    miningInfo.accepted_shares = root["stratum"]["accepted_shares"].asUInt();
    miningInfo.invalid_shares = root["stratum"]["invalid_shares"].asUInt();
    miningInfo.rejected_shares = root["stratum"]["rejected_shares"].asUInt();

    for (unsigned int i = 0; i < root["miner"]["devices"].size(); i++)
    {
        GPUMiningInfo gpuInfo;
        gpuInfo.num = root["miner"]["devices"][i]["id"].asUInt();
        gpuInfo.hashrate = root["miner"]["devices"][i]["hashrate_raw"].asDouble(); //20M 153216.05915418
        gpuInfo.accepted_shares = root["miner"]["devices"][i]["accepted_shares"].asUInt();
        gpuInfo.invalid_shares = root["miner"]["devices"][i]["invalid_shares"].asUInt();
        gpuInfo.rejected_shares = root["miner"]["devices"][i]["rejected_shares"].asUInt();
        miningInfo.gpuMiningInfos.append(gpuInfo);
    }

    return miningInfo;
}

PoolJsonParser::PoolJsonParser() {}

// Sparkpool API Only!
QList<PoolInfo> PoolJsonParser::ParseJsonForPool(std::string json)
{
    QList<PoolInfo> poolInfos;

    Json::Reader reader;
    Json::Value root;
    if (!reader.parse(json, root))
    {
        qDebug() << "reader parse error: " << strerror(errno) << endl;
        return poolInfos;
    }

    for (unsigned int i = 0; i < root["data"].size(); i++)
    {
        PoolInfo poolInfo;
        poolInfo.pool_name = root["data"][i]["pool"].asCString();
        poolInfo.currency = root["data"][i]["currency"].asCString();
        poolInfo.income = root["data"][i]["income"].asFloat();
        poolInfo.meanIncome24h = root["data"][i]["meanIncome24h"].asFloat();
        poolInfo.incomeHashrate = QString().fromStdString(root["data"][i]["incomeHashrate"].asString()).toUInt();
        poolInfo.usd = root["data"][i]["usd"].asFloat();
        poolInfo.cny = root["data"][i]["cny"].asFloat();
        poolInfos.append(poolInfo);
    }

    return poolInfos;
}

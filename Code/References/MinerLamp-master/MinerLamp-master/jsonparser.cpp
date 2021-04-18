#include <QDebug>

#include "json/json.h"
#include "jsoncpp.cpp"
#include "jsonparser.h"

JsonParser::JsonParser() {}

NBMinerJsonParser::NBMinerJsonParser() {}

std::vector<GPUInfoFromJson> NBMinerJsonParser::ParseJson(std::string json)
{
    std::vector<GPUInfoFromJson> gpuInfos;

    Json::Reader reader;
    Json::Value root;

    if (!reader.parse(json, root))
    {
        qDebug() << "reader parse error: " << strerror(errno) << endl;
        return gpuInfos;
    }

    unsigned int index = 0;

    for (unsigned int i = 0; i < root["miner"]["devices"].size(); i++)
    {
        GPUInfoFromJson gpuInfo;
        gpuInfo.num = root["miner"]["devices"][i]["id"].asUInt();
        gpuInfo.hashrate = root["miner"]["devices"][i]["hashrate_raw"].asDouble(); //20M 153216.05915418
        gpuInfo.accepted_shares = root["miner"]["devices"][i]["accepted_shares"].asUInt();
        gpuInfo.invalid_shares = root["miner"]["devices"][i]["invalid_shares"].asUInt();
        gpuInfo.rejected_shares = root["miner"]["devices"][i]["rejected_shares"].asUInt();
        gpuInfos.push_back(gpuInfo);
    }


    return gpuInfos;
}

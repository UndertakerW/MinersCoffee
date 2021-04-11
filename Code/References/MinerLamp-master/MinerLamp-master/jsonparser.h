#ifndef JSONPARSER_H
#define JSONPARSER_H

#include <vector>
#include <iostream>
#include <errno.h>
#include <string.h>

#include "structures.h"

class JsonParser
{
public:
    JsonParser();
    virtual std::vector<GPUInfoFromJson> ParseJson(std::string json) = 0;
};

class NBMinerJsonParser : public JsonParser
{
public:
    NBMinerJsonParser();
    std::vector<GPUInfoFromJson> ParseJson(std::string json) override;
};

#endif // JSONPARSER_H

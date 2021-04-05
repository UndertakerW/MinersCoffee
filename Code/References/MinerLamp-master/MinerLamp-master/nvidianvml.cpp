#include "nvidianvml.h"
#include <QDebug>

nvidiaNVML::nvidiaNVML()
{

}

bool nvidiaNVML::initNVML()
{
    nvmlReturn_t result = nvmlInit();
    if (NVML_SUCCESS != result)
    {
        qDebug() << nvmlErrorString(result);
        return false;
    }
    return true;
}

unsigned int nvidiaNVML::getGPUCount()
{
    unsigned int deviceCount = 0;
    nvmlReturn_t result;

    result = nvmlDeviceGetCount(&deviceCount);
    if (NVML_SUCCESS != result)
    {
        qDebug() << nvmlErrorString(result);
        return 0;
    }
    return deviceCount;
}

void nvidiaNVML::shutDownNVML()
{
    nvmlShutdown();
}

int nvidiaNVML::getGPUTemp(unsigned int index)
{
    nvmlReturn_t result;

    nvmlDevice_t device;
    unsigned int temp = 0;

    result = nvmlDeviceGetHandleByIndex(index, &device);
    if(result != NVML_SUCCESS )
    {
        qDebug() << nvmlErrorString(result);
        return -1;
    }

    result = nvmlDeviceGetTemperature(device, NVML_TEMPERATURE_GPU, &temp);

    return temp;
}

int nvidiaNVML::getFanSpeed(unsigned int index)
{
    nvmlReturn_t result;

    nvmlDevice_t device;
    unsigned int temp = 0;

    result = nvmlDeviceGetHandleByIndex(index, &device);
    if(result != NVML_SUCCESS )
    {
        qDebug() << nvmlErrorString(result);
        return -1;
    }

    result = nvmlDeviceGetFanSpeed(device, &temp);

    return temp;

}

int nvidiaNVML::getMemClock(unsigned int index)
{
    nvmlReturn_t result;

    nvmlDevice_t device;
    unsigned int clock = 0;

    result = nvmlDeviceGetHandleByIndex(index, &device);
    if(result != NVML_SUCCESS )
    {
        qDebug() << nvmlErrorString(result);
        return -1;
    }

    result = nvmlDeviceGetClockInfo(device, NVML_CLOCK_MEM, &clock);

    return clock;

}

int nvidiaNVML::getGPUClock(unsigned int index)
{
    nvmlReturn_t result;

    nvmlDevice_t device;
    unsigned int clock = 0;

    result = nvmlDeviceGetHandleByIndex(index, &device);
    if(result != NVML_SUCCESS )
    {
        qDebug() << nvmlErrorString(result);
        return -1;
    }

    result = nvmlDeviceGetClockInfo(device, NVML_CLOCK_GRAPHICS, &clock);

    return clock;

}

int nvidiaNVML::getPowerDraw(unsigned int index)
{
    nvmlReturn_t result;

    nvmlDevice_t device;
    unsigned int power = 0;

    result = nvmlDeviceGetHandleByIndex(index, &device);
    if(result != NVML_SUCCESS )
    {
        qDebug() << nvmlErrorString(result);
        return -1;
    }

    result = nvmlDeviceGetPowerUsage(device, &power);

    return power;
}

int nvidiaNVML::getMaxSupportedMemClock(unsigned int index)
{
    nvmlReturn_t result;

    nvmlDevice_t device;
    unsigned int* clock = 0;
    unsigned int max = 0;

    result = nvmlDeviceGetHandleByIndex(index, &device);
    if(result != NVML_SUCCESS )
    {
        qDebug() << nvmlErrorString(result);
        return -1;
    }

    unsigned int count = 0;
    result = nvmlDeviceGetSupportedMemoryClocks(device, &count, clock);
    if(result == NVML_ERROR_INSUFFICIENT_SIZE)
    {
        qDebug() << "NVML_ERROR_INSUFFICIENT_SIZE";
        qDebug() << count;
        clock = new unsigned int[count];
        result = nvmlDeviceGetSupportedMemoryClocks(device, &count, clock);
        if(result == NVML_SUCCESS)
        {
            for(unsigned int i = 0; i < count; i++)
            {
                if(max < clock[i]) max = clock[i];
                qDebug() << clock[i];
            }
        }
    }
    return max;
}

int nvidiaNVML::getHigherTemp()
{
    unsigned int maxTemp = 0;
    unsigned int gpuCount = getGPUCount();
    for(unsigned int i = 0; i < gpuCount; i++)
    {
        unsigned int temp = getGPUTemp(i);
        if(temp > maxTemp)
            maxTemp = temp;
    }
    return maxTemp;
}

int nvidiaNVML::getLowerTemp()
{
    unsigned int minTemp = 100000000;
    unsigned int gpuCount = getGPUCount();
    for(unsigned int i = 0; i < gpuCount; i++)
    {
        unsigned int temp = getGPUTemp(i);
        if(temp < minTemp)
            minTemp = temp;
    }
    return minTemp;
}

int nvidiaNVML::getHigherFanSpeed()
{
    unsigned int maxSpeed = 0;
    unsigned int gpuCount = getGPUCount();
    for(unsigned int i = 0; i < gpuCount; i++)
    {
        unsigned int speed = getFanSpeed(i);
        if(speed > maxSpeed)
            maxSpeed = speed;
    }
    return maxSpeed;
}

int nvidiaNVML::getLowerFanSpeed()
{
    unsigned int minSpeed = 1000000;
    unsigned int gpuCount = getGPUCount();
    for(unsigned int i = 0; i < gpuCount; i++)
    {
        unsigned int speed = getFanSpeed(i);
        if(speed < minSpeed)
            minSpeed = speed;
    }
    return minSpeed;

}

int nvidiaNVML::getMemMaxClock()
{
    unsigned int maxClock = 0;
    unsigned int gpuCount = getGPUCount();
    for(unsigned int i = 0; i < gpuCount; i++)
    {
        unsigned int clock = getMemClock(i);
        if(clock > maxClock)
            maxClock = clock;
    }
    return maxClock;

}

int nvidiaNVML::getMemLowerClock()
{
    unsigned int minClock = 1000000;
    unsigned int gpuCount = getGPUCount();
    for(unsigned int i = 0; i < gpuCount; i++)
    {
        unsigned int speed = getMemClock(i);
        if(speed < minClock)
            minClock = speed;
    }
    return minClock;

}

int nvidiaNVML::getGPUMaxClock()
{
    unsigned int maxClock = 0;
    unsigned int gpuCount = getGPUCount();
    for(unsigned int i = 0; i < gpuCount; i++)
    {
        unsigned int clock = getGPUClock(i);
        if(clock > maxClock)
            maxClock = clock;
    }
    return maxClock;
}

int nvidiaNVML::getGPUMinClock()
{
    unsigned int minClock = 1000000;
    unsigned int gpuCount = getGPUCount();
    for(unsigned int i = 0; i < gpuCount; i++)
    {
        unsigned int speed = getGPUClock(i);
        if(speed < minClock)
            minClock = speed;
    }
    return minClock;
}

int nvidiaNVML::getMaxPowerDraw()
{
    unsigned int maxWatt = 0;
    unsigned int gpuCount = getGPUCount();
    for(unsigned int i = 0; i < gpuCount; i++)
    {
        unsigned int watt = getPowerDraw(i);
        if(watt > maxWatt)
            maxWatt = watt;
    }
    return maxWatt;
}

int nvidiaNVML::getMinPowerDraw()
{
    unsigned int minWatt = 1000000;
    unsigned int gpuCount = getGPUCount();
    for(unsigned int i = 0; i < gpuCount; i++)
    {
        unsigned int watt = getPowerDraw(i);
        if(watt < minWatt)
            minWatt = watt;
    }
    return minWatt;

}

int nvidiaNVML::getPowerDrawSum()
{
    unsigned int totalWatt = 0;
    unsigned int gpuCount = getGPUCount();
    for(unsigned int i = 0; i < gpuCount; i++)
        totalWatt += getPowerDraw(i);
    return totalWatt;
}

void nvidiaNVML::setClock(unsigned int index)
{

    nvmlReturn_t result;

    nvmlDevice_t device;


    result = nvmlDeviceGetHandleByIndex(index, &device);
    if(result != NVML_SUCCESS )
    {
        qDebug() << nvmlErrorString(result);
        return;
    }

    nvmlEnableState_t enablestate;

    nvmlDeviceGetAPIRestriction(device, NVML_RESTRICTED_API_SET_APPLICATION_CLOCKS, &enablestate);
    if(enablestate == NVML_FEATURE_ENABLED)
    {
        result = nvmlDeviceSetAPIRestriction(device, NVML_RESTRICTED_API_SET_APPLICATION_CLOCKS, NVML_FEATURE_DISABLED);
    }



    result = nvmlDeviceSetApplicationsClocks(device, 4700, 1750);
    if(result != NVML_SUCCESS)
        qDebug() << nvmlErrorString(result);


}

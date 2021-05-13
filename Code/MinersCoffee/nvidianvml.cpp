#include "nvidianvml.h"
#include <QDebug>

NvidiaNVML::NvidiaNVML()
{

}

bool NvidiaNVML::initNVML()
{
    nvmlReturn_t result = nvmlInit();
    if (NVML_SUCCESS != result)
    {
        qDebug() << nvmlErrorString(result);
        return false;
    }
    return true;
}

unsigned int NvidiaNVML::getGPUCount()
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

void NvidiaNVML::shutDownNVML()
{
    nvmlShutdown();
}

std::string NvidiaNVML::getGPUName(unsigned int index)
{
    nvmlReturn_t result;

    nvmlDevice_t device;
    char buffer[50];

    result = nvmlDeviceGetHandleByIndex(index, &device);
    if(result != NVML_SUCCESS )
    {
        qDebug() << nvmlErrorString(result);
        return "";
    }

    result = nvmlDeviceGetName(device, buffer, 50);

    return std::string(buffer);
}

int NvidiaNVML::getGPUTemp(unsigned int index)
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

int NvidiaNVML::getTempLimit()
{
    nvmlReturn_t result;

    nvmlDevice_t device;
    unsigned int temp = 0;


    return temp;
}


int NvidiaNVML::getFanSpeed(unsigned int index)
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

int NvidiaNVML::getMemClock(unsigned int index)
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

int NvidiaNVML::getGPUClock(unsigned int index)
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

int NvidiaNVML::getPowerDraw(unsigned int index)
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

int NvidiaNVML::getMaxSupportedMemClock(unsigned int index)
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

QList<GPUInfo> NvidiaNVML::getStatus()
{
    QList<GPUInfo> gpu_infos;
    unsigned int gpuCount = getGPUCount();
    for(unsigned int i = 0; i < gpuCount; i++)
    {
        GPUInfo gi;
        gi.num = i;
        gi.temp = getGPUTemp(i);
        gi.gpuclock = getGPUClock(i);
        gi.memclock = getMemClock(i);
        gi.power = getPowerDraw(i);
        gi.fanspeed = getFanSpeed(i);
        gi.name = QString().fromStdString(getGPUName(i));
        gpu_infos.append(gi);
    }
    return gpu_infos;
}

int NvidiaNVML::getHigherTemp()
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

unsigned int* NvidiaNVML::getAllTemp()
{
    unsigned int gpuCount = getGPUCount();
    unsigned int  *Alltemp;
    for(unsigned int i = 0; i < gpuCount; i++)
    {
        unsigned int temp = getGPUTemp(i);
        *(Alltemp+i)=temp;
    }
    return Alltemp;
}

int NvidiaNVML::getLowerTemp()
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

int NvidiaNVML::getHigherFanSpeed()
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

unsigned int* NvidiaNVML::getAllFanSpeed()
{
    unsigned int gpuCount = getGPUCount();
    unsigned int  *AllFanSpeed;
    for(unsigned int i = 0; i < gpuCount; i++)
    {
        unsigned int temp = getFanSpeed(i);
        *(AllFanSpeed+i)=temp;
    }
    return AllFanSpeed;
}

int NvidiaNVML::getLowerFanSpeed()
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

int NvidiaNVML::getMemMaxClock()
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
unsigned int* NvidiaNVML::getAllMemClock()
{
    unsigned int gpuCount = getGPUCount();
    unsigned int *AllMemClock;
    for(unsigned int i = 0; i < gpuCount; i++)
    {
        unsigned int temp = getMemClock(i);
        AllMemClock[i]=temp;
    }
    return AllMemClock;
}
int NvidiaNVML::getMemLowerClock()
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

int NvidiaNVML::getGPUMaxClock()
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
unsigned int* NvidiaNVML::getAllGPUClock()
{
    unsigned int gpuCount = getGPUCount();
    unsigned int *AllGPUClock;
    for(unsigned int i = 0; i < gpuCount; i++)
    {
        unsigned int temp = getGPUClock(i);
        AllGPUClock[i]=temp;
    }
    return AllGPUClock;
}
int NvidiaNVML::getGPUMinClock()
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

int NvidiaNVML::getMaxPowerDraw()
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
unsigned int* NvidiaNVML::getAllPowerDraw()
{
    unsigned int gpuCount = getGPUCount();
    unsigned int *AllPowerDraw;
    for(unsigned int i = 0; i < gpuCount; i++)
    {
        unsigned int temp = getPowerDraw(i);
        *(AllPowerDraw+i)=temp;
    }
    return AllPowerDraw;
}
int NvidiaNVML::getMinPowerDraw()
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

int NvidiaNVML::getPowerDrawSum()
{
    unsigned int totalWatt = 0;
    unsigned int gpuCount = getGPUCount();
    for(unsigned int i = 0; i < gpuCount; i++)
        totalWatt += getPowerDraw(i);
    return totalWatt;
}

void NvidiaNVML::setClock(unsigned int index)
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

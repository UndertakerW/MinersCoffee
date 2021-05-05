#ifndef NVOCPAGE_H
#define NVOCPAGE_H

#include "nvidianvml.h"
#include "nvidiaapi.h"
#include "database.h"
#include "structures.h"
#include <QSettings>
#include <QSpinBox>
#include <QCheckBox>
#include <QComboBox>
#include <QSlider>


class NvocPage
{
public:
    NvocPage(nvidiaAPI* nvapi, QSettings* settings,
             QSpinBox* spinBoxTemperature,
             QCheckBox* checkBoxAutoOC,
             QCheckBox* checkBoxAllDevices,
             QCheckBox* checkBoxOCMinerStart,
             QComboBox* comboBoxDevice,
             QCheckBox* _checkBoxAutoSpeedFan,
             QSlider* _horizontalSliderFanSpeed
             );

    Database * _db;

//    bool loadConfig();
    void saveConfig();

    QSettings* _settings;
    nvidiaNVML* _nvml;

    nvidiaAPI* _nvapi;

    QList<nvCard> _cardList;

    unsigned int _gpuIndex;

private:

    QSpinBox* _spinBoxTemperature;
    QCheckBox* _checkBoxAutoOC;
    QCheckBox* _checkBoxAllDevices;
    QCheckBox* _checkBoxOCMinerStart;
    QComboBox* _comboBoxDevice;
    QCheckBox* _checkBoxAutoSpeedFan;
    QSlider* _horizontalSliderFanSpeed;

};

#endif // NVOCPAGE_H

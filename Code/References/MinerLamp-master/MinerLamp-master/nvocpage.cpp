#include "nvocpage.h"

NvocPage::NvocPage(nvidiaAPI* nvapi, QSettings* settings,
                   QSpinBox* spinBoxTemperature,
                   QCheckBox* checkBoxAutoOC,
                   QCheckBox* checkBoxAllDevices,
                   QCheckBox* checkBoxOCMinerStart,
                   QComboBox* comboBoxDevice,
                   QCheckBox* checkBoxAutoSpeedFan,
                   QSlider* horizontalSliderFanSpeed
                   ) :
    _gpuIndex(0),
    _settings(settings),
    _nvapi(nvapi),
    _spinBoxTemperature(spinBoxTemperature),
    _checkBoxAutoOC(checkBoxAutoOC),
    _checkBoxAllDevices(checkBoxAllDevices),
    _checkBoxOCMinerStart(checkBoxOCMinerStart),
    _comboBoxDevice(comboBoxDevice),
    _checkBoxAutoSpeedFan(checkBoxAutoSpeedFan),
    _horizontalSliderFanSpeed(horizontalSliderFanSpeed)
{
    unsigned int deviceNumber = _nvapi->getGPUCount();
    if(deviceNumber)
    {
        for(unsigned int i = 0; i < deviceNumber; i++)
        {
            nvCard card;
            card.gpuOffset = 0;
            card.memOffset = 0;
            card.powerOffset = 100;
            card.fanSpeed = 50;

            _cardList << card;
            _comboBoxDevice->addItem(QString("device " + QString::number(i)));
        }
        // **** put in main function
//        updateSliders(0);
    }

    _settings->beginGroup("nvoc");

    // initialized the value of the window

    // later these two value will be retrieved from settings
    _spinBoxTemperature->setMaximum(200);
    _spinBoxTemperature->setValue(100);
    _checkBoxAutoOC->setChecked(false);

    _checkBoxAllDevices->setChecked(_settings->value("nvoc_applyall").toBool());
    _checkBoxOCMinerStart->setChecked(_settings->value("nvoc_applyonstart").toBool());
    _checkBoxAutoSpeedFan->setChecked(_settings->value("fanspeed0").toInt() == 101 ? true : false);
    _spinBoxTemperature->setValue(_settings->value("temp_limit").toInt());
    if(_settings->value("fanspeed0").toInt() == 101) _horizontalSliderFanSpeed->hide();
    _settings->endGroup();
}




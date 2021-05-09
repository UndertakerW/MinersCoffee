#include "nvocpage.h"
#include "helper.h"
#include "constants.h"

NvocPage::NvocPage(nvidiaAPI* nvapi, QSettings* settings,
                   QSpinBox* spinBoxTemperature,
                   QPushButton* pushButtonAutoOC,
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
    _pushButtonAutoOC(pushButtonAutoOC),
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
        int plimit = _nvapi->getPowerLimit(0);

    }

    _advise = new QList<QStringList*>();
    Helper helper;
    QString advisePath = qApp->applicationDirPath() + "/" + oc_advices_path;
    QList<QString> advises = helper.GetStringData(advisePath);

    for(int i=0;i<advises.size();i++){
        QStringList row = advises.at(i).split(" ");
        QStringList * advise = new QStringList(row);
        _advise->push_back(advise);
    }

    _settings->beginGroup("nvoc");

    // initialized the value of the window

    // later these two value will be retrieved from settings
    _spinBoxTemperature->setMaximum(200);
    _spinBoxTemperature->setValue(100);

    _checkBoxAllDevices->setChecked(_settings->value("nvoc_applyall").toBool());
    _checkBoxOCMinerStart->setChecked(_settings->value("nvoc_applyonstart").toBool());
    _checkBoxAutoSpeedFan->setChecked(_settings->value("fanspeed0").toInt() == 101 ? true : false);
    _spinBoxTemperature->setValue(_settings->value("temp_limit").toInt());
    if(_settings->value("fanspeed0").toInt() == 101) _horizontalSliderFanSpeed->hide();
    _settings->endGroup();
}

QStringList NvocPage::getAdvice(const char* type){
    QString deviceName(type);

    QStringList result;

    for(int i=0;i<_advise->size();i++){
        if(_advise->at(i)->at(0) == type){
            for(int j=1;j<_advise->at(i)->size();j++){
                result.push_back(_advise->at(i)->at(j));
            }
            break;
        }
    }

    return result;
}


NvocPage::~NvocPage(){

    for(int i=_advise->size()-1;i>=0;i--){
        QStringList * tempPtr = _advise->at(i);
        _advise->pop_back();
        delete tempPtr;
    }

    delete _advise;
}

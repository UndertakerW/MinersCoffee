#include "nvocdialog.h"
#include "ui_nvocdialog.h"
#include <string>
#include <QDebug>
#include <cstring>
#include "database.h"

nvOCDialog::nvOCDialog(nvidiaAPI *nvapi, QSettings *settings, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::nvOCDialog),
    _gpuIndex(0),
    _settings(settings),
    _nvapi(nvapi)
{
    ui->setupUi(this);

    setFixedSize(size());

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
            ui->comboBoxDevice->addItem(QString("device " + QString::number(i)));
        }
        updateSliders(0);
    }

    _settings->beginGroup("nvoc");

    // initialized the value of the window

    // later these two value will be retrieved from settings
    ui->spinBoxTemperature->setMaximum(200);
    ui->spinBoxTemperature->setValue(100);
    ui->checkBoxAutoOC->setChecked(false);

    ui->checkBoxAllDevices->setChecked(_settings->value("nvoc_applyall").toBool());
    ui->checkBoxOCMinerStart->setChecked(_settings->value("nvoc_applyonstart").toBool());
    ui->checkBoxAutoSpeedFan->setChecked(_settings->value("fanspeed0").toInt() == 101 ? true : false);
    ui->spinBoxTemperature->setValue(_settings->value("temp_limit").toInt());
    if(_settings->value("fanspeed0").toInt() == 101) ui->horizontalSliderFanSpeed->hide();
    _settings->endGroup();
}

nvOCDialog::~nvOCDialog()
{
    delete ui;
}

void nvOCDialog::on_horizontalSliderPowerPercent_valueChanged(int value)
{
    ui->lcdNumberPowerPercent->display(value);
    _cardList[_gpuIndex].powerOffset = value;
}

void nvOCDialog::on_horizontalSliderGpuOffset_valueChanged(int value)
{
    ui->lcdNumberGpuOffset->display(value);
    _cardList[_gpuIndex].gpuOffset = value;
}

void nvOCDialog::on_horizontalSliderMemOffset_valueChanged(int value)
{
    ui->lcdNumberMemClock->display(value);
    _cardList[_gpuIndex].memOffset = value;
}

void nvOCDialog::on_horizontalSliderFanSpeed_valueChanged(int value)
{
    ui->lcdNumberFanSpeed->display(value);
    _cardList[_gpuIndex].fanSpeed = value;
}

void nvOCDialog::on_comboBoxDevice_activated(int index)
{
   updateSliders(index);
   _gpuIndex = index;
}

void nvOCDialog::updateSliders(unsigned int gpu)
{
    int plimit      = _nvapi->getPowerLimit(gpu);
    int gpuoffset   = _nvapi->getGPUOffset(gpu);
    int memoffset   = _nvapi->getMemOffset(gpu);
    int fanspeed    = _nvapi->getFanSpeed(gpu);

    ui->horizontalSliderPowerPercent->setValue(plimit);
    ui->horizontalSliderGpuOffset->setValue(gpuoffset);
    ui->horizontalSliderMemOffset->setValue(memoffset);
    ui->horizontalSliderFanSpeed->setValue(fanspeed);
}

void nvOCDialog::saveConfig()
{
    int deviceIndex = ui->comboBoxDevice->currentIndex();

    _settings->beginGroup("nvoc");
    _settings->setValue("nvoc_applyall", ui->checkBoxAllDevices->isChecked());
    _settings->setValue("temp_limit", ui->spinBoxTemperature->value());
    _settings->setValue("nvoc_applyonstart", ui->checkBoxOCMinerStart->isChecked());

    if(ui->checkBoxAllDevices->isChecked())
    {
        for(int i = 0; i < _cardList.size(); i++)
        {
            _settings->setValue(QString("powerlimitoffset" + QString::number(i)), _cardList.at(deviceIndex).powerOffset);
            _settings->setValue(QString("gpuoffset" + QString::number(i)), _cardList.at(deviceIndex).gpuOffset);
            _settings->setValue(QString("memoffset" + QString::number(i)), _cardList.at(deviceIndex).memOffset);
            _settings->setValue(QString("fanspeed" + QString::number(i)), ui->checkBoxAutoSpeedFan->isChecked() ? 101 : _cardList.at(deviceIndex).fanSpeed);
        }
    }
    else
    {
        _settings->setValue(QString("powerlimitoffset" + QString::number(deviceIndex)), _cardList.at(deviceIndex).powerOffset);
        _settings->setValue(QString("gpuoffset" + QString::number(deviceIndex)), _cardList.at(deviceIndex).gpuOffset);
        _settings->setValue(QString("memoffset" + QString::number(deviceIndex)), _cardList.at(deviceIndex).memOffset);
        _settings->setValue(QString("fanspeed" + QString::number(deviceIndex)), ui->checkBoxAutoSpeedFan->isChecked() ? 101 : _cardList.at(deviceIndex).fanSpeed);
    }
    _settings->endGroup();
}

// Apply settings
void nvOCDialog::on_buttonBox_clicked(QAbstractButton *button)
{
    if(button == (QAbstractButton*)ui->buttonBox->button(QDialogButtonBox::Apply))
    {
        int gpu = ui->comboBoxDevice->currentIndex();
        if(ui->checkBoxAllDevices->isChecked())
        {
            for(unsigned int i = 0; i < _nvapi->getGPUCount(); i++)
            {
                _nvapi->setPowerLimitPercent(i, ui->horizontalSliderPowerPercent->value());
                _nvapi->setGPUOffset(i, ui->horizontalSliderGpuOffset->value());
                _nvapi->setMemClockOffset(i, ui->horizontalSliderMemOffset->value());
                _nvapi->setPowerLimitPercent(i,ui->horizontalSliderPowerPercent->value());
                if(ui->checkBoxAutoSpeedFan->isChecked())
                {
                    _nvapi->startFanThread();
                }
                else
                {
                    _nvapi->startFanThread();
                    _nvapi->setFanSpeed(i, ui->horizontalSliderFanSpeed->value());
                    _nvapi->stopFanThread();
                }
            }
        }
        else
        {
            _nvapi->setPowerLimitPercent(gpu, ui->horizontalSliderPowerPercent->value());
            _nvapi->setGPUOffset(gpu, ui->horizontalSliderGpuOffset->value());
            _nvapi->setPowerLimitPercent(gpu,ui->horizontalSliderPowerPercent->value());
            _nvapi->setMemClockOffset(gpu, ui->horizontalSliderMemOffset->value());
            if(ui->checkBoxAutoSpeedFan->isChecked())
            {
                qDebug("ATUO  opened");
                _nvapi->startFanThread();
            }
            else
            {
                _nvapi->startFanThread();
                _nvapi->setFanSpeed(gpu, ui->horizontalSliderFanSpeed->value());
                _nvapi->stopFanThread();
            }
        }
        saveConfig();
    }
}


void nvOCDialog::on_checkBoxAutoSpeedFan_clicked(bool checked)
{
    if(checked)
    {
        ui->horizontalSliderFanSpeed->hide();

    }
    else
    {
        ui->horizontalSliderFanSpeed->show();

    }
}

void nvOCDialog::on_spinBoxTemperature_valueChanged(int value){
    qDebug() << "testing " << value << endl;
    unsigned gpu = (unsigned) ui->comboBoxDevice->currentIndex();
    unsigned int temp_limit = (unsigned) value;
    _nvapi->setTempLimitOffset(gpu, temp_limit);
    if(ui->checkBoxAllDevices->isChecked())
        {
            for(unsigned int i = 0; i < _nvapi->getGPUCount(); i++)
            {
                  _nvapi->setTempLimitOffset(i,temp_limit);
              }
         }
}


void nvOCDialog::on_checkBoxAutoOC_clicked(bool clicked){
    qDebug() << "test auto oc cliked: " << clicked << endl;
    if(clicked){
        int gpu = ui->comboBoxDevice->currentIndex();
        ui->spinBoxTemperature->setValue(80);
        if(ui->checkBoxAllDevices->isChecked())
        {
            for(unsigned int i = 0; i < _nvapi->getGPUCount(); i++)
            {
                std::string name =_nvml->getGPUName(i);
                int fanspeed,gpuofffset,memoffset;
                fanspeed=0;
                gpuofffset=0;
                memoffset=0;
                // do select * from advise where GPUname= name;
                std::string n="";
                for(int i=0;i<name.length();i++){
                    if(name[i]=='T'&&name[i+1]=='i')
                        n+="Ti";
                    if(name[i]!='1'&&name[i]!='2'&&name[i]!='3'&&name[i]!='4'&&name[i]!='5'&&name[i]!='6'&&name[i]!='7'&&name[i]!='8'&&name[i]!='9'&&name[i]!='0')
                        continue;
                    n+=name[i];
                }
                //
//                Database db;
                QStringList l;
                //
                const char *p;
                p=n.c_str();
                if(_db != nullptr){
                    qDebug() << "test 1";
                    l=_db->getAdvice(p);
                }
                qDebug("query name %s",n.c_str());
                //dbFreeConnect();
                int str=atoi(l.front().toStdString().c_str());
                gpuofffset=str;
                l.pop_front();
                str=atoi(l.front().toStdString().c_str());

                _nvapi->setFanSpeed(i,fanspeed);
                _nvapi->setGPUOffset(i,gpuofffset);
                _nvapi->setMemClockOffset(i,memoffset);
            }
        }
        else
        {
            std::string name =_nvml->getGPUName(gpu);
            int fanspeed,gpuofffset,memoffset;
            fanspeed=0;
            gpuofffset=0;
            memoffset=0;
            // do select * from advise where GPUname= name;std::string n="";
            std::string n="";
            for(int i=0;i<name.length();i++){
                if(name[i]=='T'&&name[i+1]=='i')
                    n+="Ti";
                if(name[i]!='1'&&name[i]!='2'&&name[i]!='3'&&name[i]!='4'&&name[i]!='5'&&name[i]!='6'&&name[i]!='7'&&name[i]!='8'&&name[i]!='9'&&name[i]!='0')
                    continue;
                n+=name[i];
            }
            //
            QStringList l;
            //
            const char *p;
            p=n.c_str();
            if(_db != nullptr){
                qDebug() << "test 2";
                l=_db->getAdvice(p);
            }
            qDebug("query name %s",n.c_str());
            //db.FreeConnect();
            int str=atoi(l.front().toStdString().c_str());
            gpuofffset=str;
            l.pop_front();
            str=atoi(l.front().toStdString().c_str());
            memoffset=str;
            str=atoi(l.front().toStdString().c_str());
            _nvapi->setFanSpeed(gpu,fanspeed);
            _nvapi->setGPUOffset(gpu,gpuofffset);
            _nvapi->setMemClockOffset(gpu,memoffset);
        }
        updateSliders(gpu);

        saveConfig();
    }
}



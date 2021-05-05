#ifndef NVOCDIALOG_H
#define NVOCDIALOG_H

#include <QDialog>
#include <QAbstractButton>

#include "nvidianvml.h"
#include "nvidiaapi.h"
#include "database.h"
#include <QSettings>


struct nvCard
{
    int powerOffset;
    int memOffset;
    int gpuOffset;
    int fanSpeed;
};

namespace Ui {
class nvOCDialog;
}

class nvOCDialog : public QDialog
{
    Q_OBJECT

public:
    Ui::nvOCDialog *ui;
    explicit nvOCDialog(nvidiaAPI* nvapi, QSettings* settings, QWidget *parent = 0);
    ~nvOCDialog();
    Database * _db;

private slots:
    void on_horizontalSliderPowerPercent_valueChanged(int value);

    void on_horizontalSliderGpuOffset_valueChanged(int value);

    void on_horizontalSliderMemOffset_valueChanged(int value);

    void on_horizontalSliderFanSpeed_valueChanged(int value);

    void on_comboBoxDevice_activated(int index);

    void on_buttonBox_clicked(QAbstractButton *button);

    void on_checkBoxAutoSpeedFan_clicked(bool checked);

    void on_spinBoxTemperature_valueChanged(int value);

    void on_checkBoxAutoOC_clicked(bool checked);

private:

    void updateSliders(unsigned int gpu);

    bool loadConfig();
    void saveConfig();


    QSettings* _settings;
    nvidiaNVML* _nvml;

    nvidiaAPI* _nvapi;

    QList<nvCard> _cardList;

    unsigned int _gpuIndex;
};

#endif // NVOCDIALOG_H

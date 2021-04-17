/********************************************************************************
** Form generated from reading UI file 'nvocdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NVOCDIALOG_H
#define UI_NVOCDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpinBox>

QT_BEGIN_NAMESPACE

class Ui_nvOCDialog
{
public:
    QGridLayout *gridLayout;
    QLabel *label_5;
    QComboBox *comboBoxDevice;
    QLabel *temperatureLimit;
    QSpinBox *spinBoxTemperature;
    QLabel *label;
    QSlider *horizontalSliderPowerPercent;
    QLCDNumber *lcdNumberPowerPercent;
    QLabel *label_2;
    QSlider *horizontalSliderGpuOffset;
    QLCDNumber *lcdNumberGpuOffset;
    QLabel *label_3;
    QSlider *horizontalSliderMemOffset;
    QLCDNumber *lcdNumberMemClock;
    QLabel *label_4;
    QCheckBox *checkBoxAutoSpeedFan;
    QSlider *horizontalSliderFanSpeed;
    QLCDNumber *lcdNumberFanSpeed;
    QCheckBox *checkBoxAllDevices;
    QCheckBox *checkBoxOCMinerStart;
    QCheckBox *checkBoxAutoOC;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *nvOCDialog)
    {
        if (nvOCDialog->objectName().isEmpty())
            nvOCDialog->setObjectName(QStringLiteral("nvOCDialog"));
        nvOCDialog->resize(738, 383);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(nvOCDialog->sizePolicy().hasHeightForWidth());
        nvOCDialog->setSizePolicy(sizePolicy);
        gridLayout = new QGridLayout(nvOCDialog);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        label_5 = new QLabel(nvOCDialog);
        label_5->setObjectName(QStringLiteral("label_5"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(label_5->sizePolicy().hasHeightForWidth());
        label_5->setSizePolicy(sizePolicy1);

        gridLayout->addWidget(label_5, 0, 0, 1, 1);

        comboBoxDevice = new QComboBox(nvOCDialog);
        comboBoxDevice->setObjectName(QStringLiteral("comboBoxDevice"));

        gridLayout->addWidget(comboBoxDevice, 0, 1, 1, 1);

        temperatureLimit = new QLabel(nvOCDialog);
        temperatureLimit->setObjectName(QStringLiteral("temperatureLimit"));

        gridLayout->addWidget(temperatureLimit, 0, 2, 1, 1);

        spinBoxTemperature = new QSpinBox(nvOCDialog);
        spinBoxTemperature->setObjectName(QStringLiteral("spinBoxTemperature"));

        gridLayout->addWidget(spinBoxTemperature, 0, 3, 1, 1);

        label = new QLabel(nvOCDialog);
        label->setObjectName(QStringLiteral("label"));
        sizePolicy1.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy1);

        gridLayout->addWidget(label, 1, 0, 1, 1);

        horizontalSliderPowerPercent = new QSlider(nvOCDialog);
        horizontalSliderPowerPercent->setObjectName(QStringLiteral("horizontalSliderPowerPercent"));
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(horizontalSliderPowerPercent->sizePolicy().hasHeightForWidth());
        horizontalSliderPowerPercent->setSizePolicy(sizePolicy2);
        horizontalSliderPowerPercent->setMinimum(50);
        horizontalSliderPowerPercent->setMaximum(100);
        horizontalSliderPowerPercent->setOrientation(Qt::Horizontal);

        gridLayout->addWidget(horizontalSliderPowerPercent, 1, 1, 1, 1);

        lcdNumberPowerPercent = new QLCDNumber(nvOCDialog);
        lcdNumberPowerPercent->setObjectName(QStringLiteral("lcdNumberPowerPercent"));
        lcdNumberPowerPercent->setDigitCount(5);

        gridLayout->addWidget(lcdNumberPowerPercent, 1, 4, 1, 1);

        label_2 = new QLabel(nvOCDialog);
        label_2->setObjectName(QStringLiteral("label_2"));
        sizePolicy1.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy1);

        gridLayout->addWidget(label_2, 2, 0, 1, 1);

        horizontalSliderGpuOffset = new QSlider(nvOCDialog);
        horizontalSliderGpuOffset->setObjectName(QStringLiteral("horizontalSliderGpuOffset"));
        horizontalSliderGpuOffset->setMinimum(-200);
        horizontalSliderGpuOffset->setMaximum(200);
        horizontalSliderGpuOffset->setOrientation(Qt::Horizontal);

        gridLayout->addWidget(horizontalSliderGpuOffset, 2, 1, 1, 1);

        lcdNumberGpuOffset = new QLCDNumber(nvOCDialog);
        lcdNumberGpuOffset->setObjectName(QStringLiteral("lcdNumberGpuOffset"));

        gridLayout->addWidget(lcdNumberGpuOffset, 2, 4, 1, 1);

        label_3 = new QLabel(nvOCDialog);
        label_3->setObjectName(QStringLiteral("label_3"));
        sizePolicy1.setHeightForWidth(label_3->sizePolicy().hasHeightForWidth());
        label_3->setSizePolicy(sizePolicy1);

        gridLayout->addWidget(label_3, 3, 0, 1, 1);

        horizontalSliderMemOffset = new QSlider(nvOCDialog);
        horizontalSliderMemOffset->setObjectName(QStringLiteral("horizontalSliderMemOffset"));
        horizontalSliderMemOffset->setMinimum(-1500);
        horizontalSliderMemOffset->setMaximum(1500);
        horizontalSliderMemOffset->setOrientation(Qt::Horizontal);

        gridLayout->addWidget(horizontalSliderMemOffset, 3, 1, 1, 1);

        lcdNumberMemClock = new QLCDNumber(nvOCDialog);
        lcdNumberMemClock->setObjectName(QStringLiteral("lcdNumberMemClock"));

        gridLayout->addWidget(lcdNumberMemClock, 3, 4, 1, 1);

        label_4 = new QLabel(nvOCDialog);
        label_4->setObjectName(QStringLiteral("label_4"));
        sizePolicy1.setHeightForWidth(label_4->sizePolicy().hasHeightForWidth());
        label_4->setSizePolicy(sizePolicy1);

        gridLayout->addWidget(label_4, 4, 0, 1, 1);

        checkBoxAutoSpeedFan = new QCheckBox(nvOCDialog);
        checkBoxAutoSpeedFan->setObjectName(QStringLiteral("checkBoxAutoSpeedFan"));
        checkBoxAutoSpeedFan->setEnabled(true);

        gridLayout->addWidget(checkBoxAutoSpeedFan, 4, 1, 1, 1);

        horizontalSliderFanSpeed = new QSlider(nvOCDialog);
        horizontalSliderFanSpeed->setObjectName(QStringLiteral("horizontalSliderFanSpeed"));
        horizontalSliderFanSpeed->setMaximum(100);
        horizontalSliderFanSpeed->setOrientation(Qt::Horizontal);

        gridLayout->addWidget(horizontalSliderFanSpeed, 5, 1, 1, 1);

        lcdNumberFanSpeed = new QLCDNumber(nvOCDialog);
        lcdNumberFanSpeed->setObjectName(QStringLiteral("lcdNumberFanSpeed"));

        gridLayout->addWidget(lcdNumberFanSpeed, 5, 4, 1, 1);

        checkBoxAllDevices = new QCheckBox(nvOCDialog);
        checkBoxAllDevices->setObjectName(QStringLiteral("checkBoxAllDevices"));

        gridLayout->addWidget(checkBoxAllDevices, 6, 0, 1, 2);

        checkBoxOCMinerStart = new QCheckBox(nvOCDialog);
        checkBoxOCMinerStart->setObjectName(QStringLiteral("checkBoxOCMinerStart"));

        gridLayout->addWidget(checkBoxOCMinerStart, 7, 0, 1, 2);

        checkBoxAutoOC = new QCheckBox(nvOCDialog);
        checkBoxAutoOC->setObjectName(QStringLiteral("checkBoxAutoOC"));

        gridLayout->addWidget(checkBoxAutoOC, 8, 0, 1, 2);

        buttonBox = new QDialogButtonBox(nvOCDialog);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Apply|QDialogButtonBox::Close);

        gridLayout->addWidget(buttonBox, 8, 2, 1, 3);


        retranslateUi(nvOCDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), nvOCDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), nvOCDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(nvOCDialog);
    } // setupUi

    void retranslateUi(QDialog *nvOCDialog)
    {
        nvOCDialog->setWindowTitle(QApplication::translate("nvOCDialog", "nVidia OC options", Q_NULLPTR));
        label_5->setText(QApplication::translate("nvOCDialog", "Devices :", Q_NULLPTR));
        temperatureLimit->setText(QApplication::translate("nvOCDialog", "TempLimit", Q_NULLPTR));
        label->setText(QApplication::translate("nvOCDialog", "Power Limit (%) :", Q_NULLPTR));
        label_2->setText(QApplication::translate("nvOCDialog", "Core Clock (MHz) :", Q_NULLPTR));
        label_3->setText(QApplication::translate("nvOCDialog", "Mem Clock (MHz) :", Q_NULLPTR));
        label_4->setText(QApplication::translate("nvOCDialog", "Fan Speed (%) :", Q_NULLPTR));
        checkBoxAutoSpeedFan->setText(QApplication::translate("nvOCDialog", "Automatic speed fan", Q_NULLPTR));
        checkBoxAllDevices->setText(QApplication::translate("nvOCDialog", "Apply to all devices (current settings are applied to all devices)", Q_NULLPTR));
        checkBoxOCMinerStart->setText(QApplication::translate("nvOCDialog", "Apply on each ethminer (re)start", Q_NULLPTR));
        checkBoxAutoOC->setText(QApplication::translate("nvOCDialog", "Auto overclocking", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class nvOCDialog: public Ui_nvOCDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NVOCDIALOG_H

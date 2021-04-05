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
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSlider>

QT_BEGIN_NAMESPACE

class Ui_nvOCDialog
{
public:
    QLabel *label_2;
    QSlider *horizontalSliderFanSpeed;
    QComboBox *comboBoxDevice;
    QLabel *label;
    QLabel *label_5;
    QLabel *label_3;
    QLabel *label_4;
    QSlider *horizontalSliderGpuOffset;
    QSlider *horizontalSliderMemOffset;
    QLCDNumber *lcdNumberMemClock;
    QLCDNumber *lcdNumberGpuOffset;
    QLCDNumber *lcdNumberPowerPercent;
    QSlider *horizontalSliderPowerPercent;
    QCheckBox *checkBoxAutoSpeedFan;
    QCheckBox *checkBoxAllDevices;
    QCheckBox *checkBoxOCMinerStart;
    QDialogButtonBox *buttonBox;
    QLCDNumber *lcdNumberFanSpeed;

    void setupUi(QDialog *nvOCDialog)
    {
        if (nvOCDialog->objectName().isEmpty())
            nvOCDialog->setObjectName(QStringLiteral("nvOCDialog"));
        nvOCDialog->resize(666, 383);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(nvOCDialog->sizePolicy().hasHeightForWidth());
        nvOCDialog->setSizePolicy(sizePolicy);
        label_2 = new QLabel(nvOCDialog);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(11, 103, 108, 16));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy1);
        horizontalSliderFanSpeed = new QSlider(nvOCDialog);
        horizontalSliderFanSpeed->setObjectName(QStringLiteral("horizontalSliderFanSpeed"));
        horizontalSliderFanSpeed->setGeometry(QRect(136, 223, 431, 22));
        horizontalSliderFanSpeed->setMaximum(100);
        horizontalSliderFanSpeed->setOrientation(Qt::Horizontal);
        comboBoxDevice = new QComboBox(nvOCDialog);
        comboBoxDevice->setObjectName(QStringLiteral("comboBoxDevice"));
        comboBoxDevice->setGeometry(QRect(140, 20, 161, 22));
        label = new QLabel(nvOCDialog);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(11, 62, 102, 16));
        sizePolicy1.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy1);
        label_5 = new QLabel(nvOCDialog);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(11, 22, 52, 16));
        sizePolicy1.setHeightForWidth(label_5->sizePolicy().hasHeightForWidth());
        label_5->setSizePolicy(sizePolicy1);
        label_3 = new QLabel(nvOCDialog);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(11, 144, 109, 16));
        sizePolicy1.setHeightForWidth(label_3->sizePolicy().hasHeightForWidth());
        label_3->setSizePolicy(sizePolicy1);
        label_4 = new QLabel(nvOCDialog);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(11, 190, 101, 16));
        sizePolicy1.setHeightForWidth(label_4->sizePolicy().hasHeightForWidth());
        label_4->setSizePolicy(sizePolicy1);
        horizontalSliderGpuOffset = new QSlider(nvOCDialog);
        horizontalSliderGpuOffset->setObjectName(QStringLiteral("horizontalSliderGpuOffset"));
        horizontalSliderGpuOffset->setGeometry(QRect(136, 103, 431, 22));
        horizontalSliderGpuOffset->setMinimum(-200);
        horizontalSliderGpuOffset->setMaximum(200);
        horizontalSliderGpuOffset->setOrientation(Qt::Horizontal);
        horizontalSliderMemOffset = new QSlider(nvOCDialog);
        horizontalSliderMemOffset->setObjectName(QStringLiteral("horizontalSliderMemOffset"));
        horizontalSliderMemOffset->setGeometry(QRect(136, 144, 431, 22));
        horizontalSliderMemOffset->setMinimum(-1500);
        horizontalSliderMemOffset->setMaximum(1500);
        horizontalSliderMemOffset->setOrientation(Qt::Horizontal);
        lcdNumberMemClock = new QLCDNumber(nvOCDialog);
        lcdNumberMemClock->setObjectName(QStringLiteral("lcdNumberMemClock"));
        lcdNumberMemClock->setGeometry(QRect(590, 144, 64, 23));
        lcdNumberGpuOffset = new QLCDNumber(nvOCDialog);
        lcdNumberGpuOffset->setObjectName(QStringLiteral("lcdNumberGpuOffset"));
        lcdNumberGpuOffset->setGeometry(QRect(590, 103, 64, 23));
        lcdNumberPowerPercent = new QLCDNumber(nvOCDialog);
        lcdNumberPowerPercent->setObjectName(QStringLiteral("lcdNumberPowerPercent"));
        lcdNumberPowerPercent->setGeometry(QRect(590, 62, 64, 23));
        lcdNumberPowerPercent->setDigitCount(5);
        horizontalSliderPowerPercent = new QSlider(nvOCDialog);
        horizontalSliderPowerPercent->setObjectName(QStringLiteral("horizontalSliderPowerPercent"));
        horizontalSliderPowerPercent->setGeometry(QRect(136, 62, 431, 22));
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(horizontalSliderPowerPercent->sizePolicy().hasHeightForWidth());
        horizontalSliderPowerPercent->setSizePolicy(sizePolicy2);
        horizontalSliderPowerPercent->setMinimum(50);
        horizontalSliderPowerPercent->setMaximum(100);
        horizontalSliderPowerPercent->setOrientation(Qt::Horizontal);
        checkBoxAutoSpeedFan = new QCheckBox(nvOCDialog);
        checkBoxAutoSpeedFan->setObjectName(QStringLiteral("checkBoxAutoSpeedFan"));
        checkBoxAutoSpeedFan->setEnabled(true);
        checkBoxAutoSpeedFan->setGeometry(QRect(140, 190, 121, 20));
        checkBoxAllDevices = new QCheckBox(nvOCDialog);
        checkBoxAllDevices->setObjectName(QStringLiteral("checkBoxAllDevices"));
        checkBoxAllDevices->setGeometry(QRect(11, 263, 385, 20));
        checkBoxOCMinerStart = new QCheckBox(nvOCDialog);
        checkBoxOCMinerStart->setObjectName(QStringLiteral("checkBoxOCMinerStart"));
        checkBoxOCMinerStart->setGeometry(QRect(11, 310, 214, 20));
        buttonBox = new QDialogButtonBox(nvOCDialog);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setGeometry(QRect(463, 339, 193, 28));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Apply|QDialogButtonBox::Close);
        lcdNumberFanSpeed = new QLCDNumber(nvOCDialog);
        lcdNumberFanSpeed->setObjectName(QStringLiteral("lcdNumberFanSpeed"));
        lcdNumberFanSpeed->setGeometry(QRect(590, 220, 64, 23));

        retranslateUi(nvOCDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), nvOCDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), nvOCDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(nvOCDialog);
    } // setupUi

    void retranslateUi(QDialog *nvOCDialog)
    {
        nvOCDialog->setWindowTitle(QApplication::translate("nvOCDialog", "nVidia OC options", Q_NULLPTR));
        label_2->setText(QApplication::translate("nvOCDialog", "Core Clock (MHz) :", Q_NULLPTR));
        label->setText(QApplication::translate("nvOCDialog", "Power Limit (%) :", Q_NULLPTR));
        label_5->setText(QApplication::translate("nvOCDialog", "Devices :", Q_NULLPTR));
        label_3->setText(QApplication::translate("nvOCDialog", "Mem Clock (MHz) :", Q_NULLPTR));
        label_4->setText(QApplication::translate("nvOCDialog", "Fan Speed (%) :", Q_NULLPTR));
        checkBoxAutoSpeedFan->setText(QApplication::translate("nvOCDialog", "Automatic speed fan", Q_NULLPTR));
        checkBoxAllDevices->setText(QApplication::translate("nvOCDialog", "Apply to all devices (current settings are applied to all devices)", Q_NULLPTR));
        checkBoxOCMinerStart->setText(QApplication::translate("nvOCDialog", "Apply on each ethminer (re)start", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class nvOCDialog: public Ui_nvOCDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NVOCDIALOG_H

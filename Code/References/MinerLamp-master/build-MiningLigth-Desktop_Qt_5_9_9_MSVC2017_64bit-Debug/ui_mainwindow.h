/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateTimeEdit>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "hashratecharview.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QLineEdit *lineEditMinerPath;
    QCheckBox *checkBoxAutoStart;
    QCheckBox *checkBoxShowHistoryInfo;
    QComboBox *comboBoxHistoryDataOption;
    QCheckBox *checkBoxHistoryMiningInfoOverall;
    QPushButton *pushButtonSearchHistory;
    QCheckBox *checkBoxShowSettings;
    QCheckBox *checkBoxAutoShowDeviceInfo;
    QLabel *labelWallet_2;
    QPushButton *pushButtonCancelAutoPage;
    QLineEdit *lineEditArgs;
    QSplitter *splitter_3;
    QGroupBox *groupBoxWatchdog;
    QGridLayout *gridLayout;
    QSpinBox *spinBoxMax0MHs;
    QLabel *label_3;
    QSpinBox *spinBoxDelay;
    QSpinBox *spinBoxDelay0MHs;
    QLabel *label_5;
    QLabel *label_7;
    QSpinBox *spinBoxDelayNoHash;
    QLabel *label_4;
    QGroupBox *groupBoxSettings;
    QGridLayout *gridLayout_11;
    QPushButton *pushButton;
    QPushButton *pushButtonHelp;
    QPushButton *pushButtonEthminerBrowser;
    QGroupBox *groupBoxAMD;
    QGridLayout *gridLayout_2;
    QLCDNumber *lcdNumber_AMD_GPUCount;
    QLabel *label_31;
    QLCDNumber *lcdNumber_AMD_MinClock;
    QLabel *label_25;
    QLCDNumber *lcdNumber_AMD_MaxFan;
    QLCDNumber *lcdNumber_AMD_MinPoxer;
    QLabel *label_32;
    QLabel *label_27;
    QLabel *label_30;
    QLabel *label_28;
    QLabel *label_AMD_GPUCount;
    QLCDNumber *lcdNumber_AMD_MinFan;
    QLCDNumber *lcdNumber_AMD_MinMemClock;
    QLCDNumber *lcdNumber_AMD_MaxMemClock;
    QLCDNumber *lcdNumber_AMD_MinTemp;
    QLabel *label_33;
    QLCDNumber *lcdNumber_AMD_MaxTemp;
    QLabel *label_29;
    QLCDNumber *lcdNumber_AMD_MaxPower;
    QLabel *label_26;
    QLCDNumber *lcdNumber_AMD_MaxClock;
    QLabel *label_24;
    QCheckBox *checkBoxOnlyShare;
    QGroupBox *groupBoxPools;
    QGridLayout *gridLayout_4;
    QLCDNumber *lcdNumberBalance;
    QLCDNumber *lcdNumberAvrgHr6H;
    QLCDNumber *lcdNumberCalculatedHR;
    QLabel *label_22;
    QLCDNumber *lcdNumber_4;
    QLabel *label_21;
    QLabel *label_20;
    QPushButton *pushButtonDisplayPoolStats;
    QLabel *label_19;
    QStackedWidget *stackedWidgetMain;
    QWidget *page_monitor;
    QVBoxLayout *verticalLayout;
    QFrame *frameMonitorBar;
    QHBoxLayout *horizontalLayout_5;
    QFrame *framePadding;
    QFrame *frameOverview;
    QFrame *frameMiningInfo;
    QFrame *frameHistory;
    QSpacerItem *horizontalSpacer;
    QStackedWidget *stackedWidgeMonitorMain;
    QWidget *pageOverview;
    QVBoxLayout *verticalLayout_7;
    QSplitter *splitter;
    QGroupBox *groupBox;
    QHBoxLayout *horizontalLayout_6;
    hashrateCharView *graphicsView;
    QFrame *frame;
    QVBoxLayout *verticalLayout_2;
    QFrame *frame_2;
    QVBoxLayout *verticalLayout_3;
    QLabel *label;
    QLCDNumber *lcdNumberHashRate;
    QFrame *frame_3;
    QVBoxLayout *verticalLayout_4;
    QLabel *label_2;
    QLCDNumber *lcdNumberHashRate_2;
    QSpacerItem *verticalSpacer;
    QGroupBox *groupBox_3;
    QVBoxLayout *verticalLayout_5;
    QFrame *frame_5;
    QVBoxLayout *verticalLayout_6;
    QFrame *frame_6;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_23;
    QFrame *frame_10;
    QGridLayout *gridLayout_7;
    QLCDNumber *lcdNumberMinMemClock;
    QLCDNumber *lcdNumberMaxMemClock;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QFrame *frame_11;
    QHBoxLayout *horizontalLayout_8;
    QLabel *label_34;
    QFrame *frame_12;
    QGridLayout *gridLayout_10;
    QLCDNumber *lcdNumberMinMemClock_2;
    QLCDNumber *lcdNumberMaxMemClock_2;
    QPushButton *pushButton_4;
    QPushButton *pushButton_5;
    QFrame *frame_13;
    QHBoxLayout *horizontalLayout_10;
    QLabel *label_36;
    QFrame *frame_15;
    QGridLayout *gridLayout_14;
    QLCDNumber *lcdNumberMinMemClock_4;
    QLCDNumber *lcdNumberMaxMemClock_4;
    QPushButton *pushButton_8;
    QPushButton *pushButton_9;
    QFrame *frame_9;
    QGridLayout *gridLayout_5;
    hashrateCharView *graphicsViewEff;
    QSpacerItem *verticalSpacer_2;
    QSplitter *splitter_2;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout_6;
    hashrateCharView *graphicsViewTemp;
    QGroupBox *groupBoxDiskInfo;
    QGridLayout *gridLayout_13;
    QGridLayout *gridLayoutDiskInfo;
    QWidget *pageMining;
    QGridLayout *gridLayout_25;
    QGroupBox *groupBox_4;
    QGridLayout *gridLayout_16;
    QHBoxLayout *horizontalLayout_15;
    QGridLayout *gridLayout_15;
    QHBoxLayout *horizontalLayout_14;
    QLabel *labelWallet;
    QLineEdit *lineEditWallet;
    QHBoxLayout *horizontalLayout_4;
    QLabel *labelCoin;
    QComboBox *comboBoxCoin;
    QSpacerItem *horizontalSpacer_3;
    QHBoxLayout *horizontalLayout_12;
    QLabel *labelPool;
    QComboBox *comboBoxPool;
    QHBoxLayout *horizontalLayout_13;
    QLabel *labelWorker;
    QLineEdit *lineEditWorker;
    QSpacerItem *horizontalSpacer_6;
    QHBoxLayout *horizontalLayout_11;
    QLabel *labelCore;
    QComboBox *comboBoxCore;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *pushButton_10;
    QHBoxLayout *horizontalLayout_21;
    QGroupBox *groupBox_5;
    QGridLayout *gridLayout_17;
    QFrame *frame_8;
    QHBoxLayout *horizontalLayout_18;
    QFrame *frame_20;
    QGridLayout *gridLayout_20;
    QRadioButton *radioButtonNaopool;
    QFrame *frame_21;
    QGridLayout *gridLayout_21;
    QRadioButton *radioButtonEthermine;
    QFrame *frame_22;
    QGridLayout *gridLayout_22;
    QRadioButton *radioButtonDwarfPool;
    QLineEdit *lineEditAccount;
    QHBoxLayout *horizontalLayout_16;
    QFrame *frame_16;
    QGridLayout *gridLayout_18;
    QVBoxLayout *verticalLayout_8;
    QFrame *frame_18;
    QHBoxLayout *horizontalLayout_17;
    QLabel *label_37;
    QFrame *frame_19;
    QGridLayout *gridLayout_19;
    QLabel *label_38;
    QFrame *frame_17;
    QFrame *frame_7;
    QHBoxLayout *horizontalLayout_19;
    QLabel *label_39;
    QSpacerItem *horizontalSpacer_4;
    QGroupBox *groupBox_6;
    QGridLayout *gridLayout_23;
    QVBoxLayout *verticalLayout_9;
    QFrame *frame_25;
    QHBoxLayout *horizontalLayout_20;
    QLabel *label_40;
    QSpacerItem *horizontalSpacer_5;
    QFrame *frame_24;
    QGridLayout *gridLayout_24;
    QTextEdit *textEdit;
    QWidget *pageHistory;
    QGroupBox *groupBox_7;
    QGridLayout *gridLayout_29;
    QHBoxLayout *horizontalLayout_23;
    QVBoxLayout *verticalLayout_10;
    QFrame *frame_23;
    QHBoxLayout *horizontalLayout_22;
    QLabel *label_41;
    QSpacerItem *horizontalSpacer_7;
    QFrame *frame_26;
    QGridLayout *gridLayout_26;
    QTextEdit *textEditSettings;
    QFrame *frame_28;
    QGridLayout *gridLayout_27;
    QFormLayout *formLayout;
    QLabel *label_43;
    QLabel *label_46;
    QLabel *label_45;
    QVBoxLayout *verticalLayout_11;
    QSpacerItem *verticalSpacer_3;
    QSpinBox *spinBoxChangePageSizeMax;
    QSpacerItem *verticalSpacer_4;
    QVBoxLayout *verticalLayout_12;
    QSpacerItem *verticalSpacer_5;
    QSpinBox *spinBoxChangePageSizeMin;
    QSpacerItem *verticalSpacer_6;
    QVBoxLayout *verticalLayout_13;
    QSpacerItem *verticalSpacer_7;
    QComboBox *comboBoxChangePageSize;
    QSpacerItem *verticalSpacer_8;
    QFrame *frame_27;
    QGridLayout *gridLayout_28;
    QPushButton *pushButtonChangePageSize;
    QSpacerItem *horizontalSpacer_8;
    QSpacerItem *horizontalSpacer_10;
    QWidget *page_2;
    QFrame *frame_30;
    QFrame *frame_29;
    QGridLayout *gridLayout_30;
    QVBoxLayout *verticalLayout_14;
    QHBoxLayout *horizontalLayout;
    QLabel *labelHistoryDeviceNum;
    QSpacerItem *horizontalSpacer_12;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer_11;
    QSpinBox *spinBoxHistoryDeviceNum;
    QHBoxLayout *horizontalLayout_25;
    QLabel *labelHistoryDeviceNum_2;
    QSpacerItem *horizontalSpacer_13;
    QHBoxLayout *horizontalLayout_26;
    QSpacerItem *horizontalSpacer_14;
    QDateTimeEdit *dateTimeEditHistoryStartTime;
    QHBoxLayout *horizontalLayout_27;
    QLabel *labelHistoryDeviceNum_3;
    QSpacerItem *horizontalSpacer_15;
    QHBoxLayout *horizontalLayout_28;
    QSpacerItem *horizontalSpacer_16;
    QDateTimeEdit *dateTimeEditHistoryEndTime;
    hashrateCharView *graphicsViewHistoryInfo;
    QWidget *widget;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *pushButtonPool;
    QPushButton *pushButtonShowHideLog;
    QGroupBox *groupBoxNvidia;
    QGridLayout *gridLayout_3;
    QLCDNumber *lcdNumberMaxFanSpeed;
    QLabel *label_17;
    QLabel *label_8;
    QLabel *label_9;
    QLabel *label_10;
    QPushButton *pushButtonOC;
    QLCDNumber *lcdNumberMinGPUTemp;
    QLabel *label_13;
    QLCDNumber *lcdNumberGPUCount;
    QLabel *label_15;
    QLabel *label_11;
    QLCDNumber *lcdNumberMaxWatt;
    QLCDNumber *lcdNumberMaxGPUClock;
    QLCDNumber *lcdNumberMinFanSpeed;
    QLabel *label_18;
    QLabel *label_16;
    QLCDNumber *lcdNumberMinWatt;
    QLCDNumber *lcdNumberMinGPUClock;
    QLabel *label_6;
    QLCDNumber *lcdNumberTotalPowerDraw;
    QLabel *label_12;
    QLCDNumber *lcdNumberMaxGPUTemp;
    QLabel *label_14;
    QGroupBox *groupBoxDevicesInfo;
    QGridLayout *gridLayout_9;
    QGridLayout *gridLayoutDevicesInfo;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(2494, 1439);
        QFont font;
        font.setFamily(QStringLiteral("Tahoma"));
        font.setPointSize(10);
        MainWindow->setFont(font);
        QIcon icon;
        icon.addFile(QStringLiteral(":/icons/eth_miner_lamp.ico"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindow->setWindowIcon(icon);
        MainWindow->setStyleSheet(QStringLiteral(""));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        centralWidget->setEnabled(true);
        centralWidget->setStyleSheet(QStringLiteral(""));
        lineEditMinerPath = new QLineEdit(centralWidget);
        lineEditMinerPath->setObjectName(QStringLiteral("lineEditMinerPath"));
        lineEditMinerPath->setGeometry(QRect(1005, 9, 0, 0));
        lineEditMinerPath->setMaximumSize(QSize(0, 0));
        checkBoxAutoStart = new QCheckBox(centralWidget);
        checkBoxAutoStart->setObjectName(QStringLiteral("checkBoxAutoStart"));
        checkBoxAutoStart->setGeometry(QRect(9, 57, 133, 21));
        QFont font1;
        font1.setFamily(QStringLiteral("Arial"));
        checkBoxAutoStart->setFont(font1);
        checkBoxShowHistoryInfo = new QCheckBox(centralWidget);
        checkBoxShowHistoryInfo->setObjectName(QStringLiteral("checkBoxShowHistoryInfo"));
        checkBoxShowHistoryInfo->setGeometry(QRect(250, 57, 139, 21));
        checkBoxShowHistoryInfo->setFont(font1);
        comboBoxHistoryDataOption = new QComboBox(centralWidget);
        comboBoxHistoryDataOption->setObjectName(QStringLiteral("comboBoxHistoryDataOption"));
        comboBoxHistoryDataOption->setGeometry(QRect(471, 57, 166, 21));
        checkBoxHistoryMiningInfoOverall = new QCheckBox(centralWidget);
        checkBoxHistoryMiningInfoOverall->setObjectName(QStringLiteral("checkBoxHistoryMiningInfoOverall"));
        checkBoxHistoryMiningInfoOverall->setGeometry(QRect(643, 58, 80, 19));
        pushButtonSearchHistory = new QPushButton(centralWidget);
        pushButtonSearchHistory->setObjectName(QStringLiteral("pushButtonSearchHistory"));
        pushButtonSearchHistory->setGeometry(QRect(1129, 54, 93, 28));
        checkBoxShowSettings = new QCheckBox(centralWidget);
        checkBoxShowSettings->setObjectName(QStringLiteral("checkBoxShowSettings"));
        checkBoxShowSettings->setGeometry(QRect(9, 91, 118, 21));
        checkBoxShowSettings->setFont(font1);
        checkBoxAutoShowDeviceInfo = new QCheckBox(centralWidget);
        checkBoxAutoShowDeviceInfo->setObjectName(QStringLiteral("checkBoxAutoShowDeviceInfo"));
        checkBoxAutoShowDeviceInfo->setGeometry(QRect(250, 91, 141, 21));
        checkBoxAutoShowDeviceInfo->setFont(font1);
        labelWallet_2 = new QLabel(centralWidget);
        labelWallet_2->setObjectName(QStringLiteral("labelWallet_2"));
        labelWallet_2->setGeometry(QRect(405, 88, 60, 16));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(labelWallet_2->sizePolicy().hasHeightForWidth());
        labelWallet_2->setSizePolicy(sizePolicy);
        labelWallet_2->setMaximumSize(QSize(60, 16777215));
        QFont font2;
        font2.setFamily(QStringLiteral("Arial"));
        font2.setPointSize(8);
        font2.setBold(false);
        font2.setWeight(50);
        labelWallet_2->setFont(font2);
        pushButtonCancelAutoPage = new QPushButton(centralWidget);
        pushButtonCancelAutoPage->setObjectName(QStringLiteral("pushButtonCancelAutoPage"));
        pushButtonCancelAutoPage->setEnabled(true);
        pushButtonCancelAutoPage->setGeometry(QRect(1129, 88, 129, 28));
        lineEditArgs = new QLineEdit(centralWidget);
        lineEditArgs->setObjectName(QStringLiteral("lineEditArgs"));
        lineEditArgs->setGeometry(QRect(1011, 122, 0, 0));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(lineEditArgs->sizePolicy().hasHeightForWidth());
        lineEditArgs->setSizePolicy(sizePolicy1);
        lineEditArgs->setMaximumSize(QSize(0, 0));
        splitter_3 = new QSplitter(centralWidget);
        splitter_3->setObjectName(QStringLiteral("splitter_3"));
        splitter_3->setGeometry(QRect(9, 128, 990, 124));
        splitter_3->setOrientation(Qt::Horizontal);
        groupBoxWatchdog = new QGroupBox(splitter_3);
        groupBoxWatchdog->setObjectName(QStringLiteral("groupBoxWatchdog"));
        sizePolicy1.setHeightForWidth(groupBoxWatchdog->sizePolicy().hasHeightForWidth());
        groupBoxWatchdog->setSizePolicy(sizePolicy1);
        groupBoxWatchdog->setFont(font1);
        groupBoxWatchdog->setCheckable(true);
        groupBoxWatchdog->setChecked(false);
        gridLayout = new QGridLayout(groupBoxWatchdog);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        spinBoxMax0MHs = new QSpinBox(groupBoxWatchdog);
        spinBoxMax0MHs->setObjectName(QStringLiteral("spinBoxMax0MHs"));
        spinBoxMax0MHs->setFont(font1);
        spinBoxMax0MHs->setMinimum(1);

        gridLayout->addWidget(spinBoxMax0MHs, 0, 1, 1, 1);

        label_3 = new QLabel(groupBoxWatchdog);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setFont(font1);

        gridLayout->addWidget(label_3, 1, 0, 1, 1);

        spinBoxDelay = new QSpinBox(groupBoxWatchdog);
        spinBoxDelay->setObjectName(QStringLiteral("spinBoxDelay"));
        spinBoxDelay->setFont(font1);
        spinBoxDelay->setMinimum(1);

        gridLayout->addWidget(spinBoxDelay, 0, 3, 1, 1);

        spinBoxDelay0MHs = new QSpinBox(groupBoxWatchdog);
        spinBoxDelay0MHs->setObjectName(QStringLiteral("spinBoxDelay0MHs"));
        spinBoxDelay0MHs->setFont(font1);
        spinBoxDelay0MHs->setMinimum(1);
        spinBoxDelay0MHs->setMaximum(600);
        spinBoxDelay0MHs->setValue(20);

        gridLayout->addWidget(spinBoxDelay0MHs, 1, 1, 1, 1);

        label_5 = new QLabel(groupBoxWatchdog);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setFont(font1);

        gridLayout->addWidget(label_5, 0, 2, 1, 1);

        label_7 = new QLabel(groupBoxWatchdog);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setFont(font1);

        gridLayout->addWidget(label_7, 1, 2, 1, 1);

        spinBoxDelayNoHash = new QSpinBox(groupBoxWatchdog);
        spinBoxDelayNoHash->setObjectName(QStringLiteral("spinBoxDelayNoHash"));
        spinBoxDelayNoHash->setFont(font1);
        spinBoxDelayNoHash->setMinimum(30);
        spinBoxDelayNoHash->setMaximum(600);
        spinBoxDelayNoHash->setValue(60);

        gridLayout->addWidget(spinBoxDelayNoHash, 1, 3, 1, 1);

        label_4 = new QLabel(groupBoxWatchdog);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setFont(font1);

        gridLayout->addWidget(label_4, 0, 0, 1, 1);

        splitter_3->addWidget(groupBoxWatchdog);
        groupBoxSettings = new QGroupBox(splitter_3);
        groupBoxSettings->setObjectName(QStringLiteral("groupBoxSettings"));
        groupBoxSettings->setFont(font1);
        gridLayout_11 = new QGridLayout(groupBoxSettings);
        gridLayout_11->setSpacing(6);
        gridLayout_11->setContentsMargins(11, 11, 11, 11);
        gridLayout_11->setObjectName(QStringLiteral("gridLayout_11"));
        splitter_3->addWidget(groupBoxSettings);
        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(1017, 148, 93, 28));
        pushButton->setFont(font1);
        pushButtonHelp = new QPushButton(centralWidget);
        pushButtonHelp->setObjectName(QStringLiteral("pushButtonHelp"));
        pushButtonHelp->setGeometry(QRect(1017, 213, 93, 28));
        pushButtonHelp->setFont(font1);
        pushButtonEthminerBrowser = new QPushButton(centralWidget);
        pushButtonEthminerBrowser->setObjectName(QStringLiteral("pushButtonEthminerBrowser"));
        pushButtonEthminerBrowser->setGeometry(QRect(1129, 213, 93, 28));
        QSizePolicy sizePolicy2(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(pushButtonEthminerBrowser->sizePolicy().hasHeightForWidth());
        pushButtonEthminerBrowser->setSizePolicy(sizePolicy2);
        pushButtonEthminerBrowser->setFont(font1);
        groupBoxAMD = new QGroupBox(centralWidget);
        groupBoxAMD->setObjectName(QStringLiteral("groupBoxAMD"));
        groupBoxAMD->setGeometry(QRect(9, 380, 1100, 87));
        sizePolicy1.setHeightForWidth(groupBoxAMD->sizePolicy().hasHeightForWidth());
        groupBoxAMD->setSizePolicy(sizePolicy1);
        groupBoxAMD->setFont(font2);
        gridLayout_2 = new QGridLayout(groupBoxAMD);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        lcdNumber_AMD_GPUCount = new QLCDNumber(groupBoxAMD);
        lcdNumber_AMD_GPUCount->setObjectName(QStringLiteral("lcdNumber_AMD_GPUCount"));
        lcdNumber_AMD_GPUCount->setDigitCount(2);

        gridLayout_2->addWidget(lcdNumber_AMD_GPUCount, 1, 1, 1, 1);

        label_31 = new QLabel(groupBoxAMD);
        label_31->setObjectName(QStringLiteral("label_31"));
        label_31->setFont(font1);

        gridLayout_2->addWidget(label_31, 2, 8, 1, 1);

        lcdNumber_AMD_MinClock = new QLCDNumber(groupBoxAMD);
        lcdNumber_AMD_MinClock->setObjectName(QStringLiteral("lcdNumber_AMD_MinClock"));

        gridLayout_2->addWidget(lcdNumber_AMD_MinClock, 2, 7, 1, 1);

        label_25 = new QLabel(groupBoxAMD);
        label_25->setObjectName(QStringLiteral("label_25"));
        label_25->setFont(font1);

        gridLayout_2->addWidget(label_25, 2, 2, 1, 1);

        lcdNumber_AMD_MaxFan = new QLCDNumber(groupBoxAMD);
        lcdNumber_AMD_MaxFan->setObjectName(QStringLiteral("lcdNumber_AMD_MaxFan"));

        gridLayout_2->addWidget(lcdNumber_AMD_MaxFan, 1, 5, 1, 1);

        lcdNumber_AMD_MinPoxer = new QLCDNumber(groupBoxAMD);
        lcdNumber_AMD_MinPoxer->setObjectName(QStringLiteral("lcdNumber_AMD_MinPoxer"));

        gridLayout_2->addWidget(lcdNumber_AMD_MinPoxer, 2, 11, 1, 1);

        label_32 = new QLabel(groupBoxAMD);
        label_32->setObjectName(QStringLiteral("label_32"));
        label_32->setFont(font1);

        gridLayout_2->addWidget(label_32, 1, 10, 1, 1);

        label_27 = new QLabel(groupBoxAMD);
        label_27->setObjectName(QStringLiteral("label_27"));
        label_27->setFont(font1);

        gridLayout_2->addWidget(label_27, 1, 4, 1, 1);

        label_30 = new QLabel(groupBoxAMD);
        label_30->setObjectName(QStringLiteral("label_30"));
        label_30->setFont(font1);

        gridLayout_2->addWidget(label_30, 1, 8, 1, 1);

        label_28 = new QLabel(groupBoxAMD);
        label_28->setObjectName(QStringLiteral("label_28"));
        label_28->setFont(font1);

        gridLayout_2->addWidget(label_28, 1, 6, 1, 1);

        label_AMD_GPUCount = new QLabel(groupBoxAMD);
        label_AMD_GPUCount->setObjectName(QStringLiteral("label_AMD_GPUCount"));
        label_AMD_GPUCount->setFont(font1);

        gridLayout_2->addWidget(label_AMD_GPUCount, 1, 0, 1, 1);

        lcdNumber_AMD_MinFan = new QLCDNumber(groupBoxAMD);
        lcdNumber_AMD_MinFan->setObjectName(QStringLiteral("lcdNumber_AMD_MinFan"));

        gridLayout_2->addWidget(lcdNumber_AMD_MinFan, 2, 5, 1, 1);

        lcdNumber_AMD_MinMemClock = new QLCDNumber(groupBoxAMD);
        lcdNumber_AMD_MinMemClock->setObjectName(QStringLiteral("lcdNumber_AMD_MinMemClock"));

        gridLayout_2->addWidget(lcdNumber_AMD_MinMemClock, 2, 9, 1, 1);

        lcdNumber_AMD_MaxMemClock = new QLCDNumber(groupBoxAMD);
        lcdNumber_AMD_MaxMemClock->setObjectName(QStringLiteral("lcdNumber_AMD_MaxMemClock"));

        gridLayout_2->addWidget(lcdNumber_AMD_MaxMemClock, 1, 9, 1, 1);

        lcdNumber_AMD_MinTemp = new QLCDNumber(groupBoxAMD);
        lcdNumber_AMD_MinTemp->setObjectName(QStringLiteral("lcdNumber_AMD_MinTemp"));

        gridLayout_2->addWidget(lcdNumber_AMD_MinTemp, 2, 3, 1, 1);

        label_33 = new QLabel(groupBoxAMD);
        label_33->setObjectName(QStringLiteral("label_33"));
        label_33->setFont(font1);

        gridLayout_2->addWidget(label_33, 2, 10, 1, 1);

        lcdNumber_AMD_MaxTemp = new QLCDNumber(groupBoxAMD);
        lcdNumber_AMD_MaxTemp->setObjectName(QStringLiteral("lcdNumber_AMD_MaxTemp"));

        gridLayout_2->addWidget(lcdNumber_AMD_MaxTemp, 1, 3, 1, 1);

        label_29 = new QLabel(groupBoxAMD);
        label_29->setObjectName(QStringLiteral("label_29"));
        label_29->setFont(font1);

        gridLayout_2->addWidget(label_29, 2, 6, 1, 1);

        lcdNumber_AMD_MaxPower = new QLCDNumber(groupBoxAMD);
        lcdNumber_AMD_MaxPower->setObjectName(QStringLiteral("lcdNumber_AMD_MaxPower"));

        gridLayout_2->addWidget(lcdNumber_AMD_MaxPower, 1, 11, 1, 1);

        label_26 = new QLabel(groupBoxAMD);
        label_26->setObjectName(QStringLiteral("label_26"));
        label_26->setFont(font1);

        gridLayout_2->addWidget(label_26, 2, 4, 1, 1);

        lcdNumber_AMD_MaxClock = new QLCDNumber(groupBoxAMD);
        lcdNumber_AMD_MaxClock->setObjectName(QStringLiteral("lcdNumber_AMD_MaxClock"));

        gridLayout_2->addWidget(lcdNumber_AMD_MaxClock, 1, 7, 1, 1);

        label_24 = new QLabel(groupBoxAMD);
        label_24->setObjectName(QStringLiteral("label_24"));
        label_24->setFont(font1);

        gridLayout_2->addWidget(label_24, 1, 2, 1, 1);

        checkBoxOnlyShare = new QCheckBox(centralWidget);
        checkBoxOnlyShare->setObjectName(QStringLiteral("checkBoxOnlyShare"));
        checkBoxOnlyShare->setGeometry(QRect(9, 721, 179, 21));
        checkBoxOnlyShare->setFont(font1);
        groupBoxPools = new QGroupBox(centralWidget);
        groupBoxPools->setObjectName(QStringLiteral("groupBoxPools"));
        groupBoxPools->setEnabled(true);
        groupBoxPools->setGeometry(QRect(9, 846, 853, 162));
        QSizePolicy sizePolicy3(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(groupBoxPools->sizePolicy().hasHeightForWidth());
        groupBoxPools->setSizePolicy(sizePolicy3);
        groupBoxPools->setFont(font1);
        gridLayout_4 = new QGridLayout(groupBoxPools);
        gridLayout_4->setSpacing(6);
        gridLayout_4->setContentsMargins(11, 11, 11, 11);
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        lcdNumberBalance = new QLCDNumber(groupBoxPools);
        lcdNumberBalance->setObjectName(QStringLiteral("lcdNumberBalance"));
        lcdNumberBalance->setSmallDecimalPoint(false);
        lcdNumberBalance->setDigitCount(12);

        gridLayout_4->addWidget(lcdNumberBalance, 2, 2, 1, 1);

        lcdNumberAvrgHr6H = new QLCDNumber(groupBoxPools);
        lcdNumberAvrgHr6H->setObjectName(QStringLiteral("lcdNumberAvrgHr6H"));
        lcdNumberAvrgHr6H->setDigitCount(6);

        gridLayout_4->addWidget(lcdNumberAvrgHr6H, 3, 3, 1, 1);

        lcdNumberCalculatedHR = new QLCDNumber(groupBoxPools);
        lcdNumberCalculatedHR->setObjectName(QStringLiteral("lcdNumberCalculatedHR"));
        lcdNumberCalculatedHR->setDigitCount(6);

        gridLayout_4->addWidget(lcdNumberCalculatedHR, 3, 1, 1, 1);

        label_22 = new QLabel(groupBoxPools);
        label_22->setObjectName(QStringLiteral("label_22"));
        label_22->setFont(font1);

        gridLayout_4->addWidget(label_22, 3, 4, 1, 1);

        lcdNumber_4 = new QLCDNumber(groupBoxPools);
        lcdNumber_4->setObjectName(QStringLiteral("lcdNumber_4"));
        lcdNumber_4->setDigitCount(6);

        gridLayout_4->addWidget(lcdNumber_4, 3, 5, 1, 1);

        label_21 = new QLabel(groupBoxPools);
        label_21->setObjectName(QStringLiteral("label_21"));
        label_21->setFont(font1);

        gridLayout_4->addWidget(label_21, 3, 2, 1, 1);

        label_20 = new QLabel(groupBoxPools);
        label_20->setObjectName(QStringLiteral("label_20"));
        label_20->setFont(font1);

        gridLayout_4->addWidget(label_20, 3, 0, 1, 1);

        pushButtonDisplayPoolStats = new QPushButton(groupBoxPools);
        pushButtonDisplayPoolStats->setObjectName(QStringLiteral("pushButtonDisplayPoolStats"));
        pushButtonDisplayPoolStats->setFont(font1);

        gridLayout_4->addWidget(pushButtonDisplayPoolStats, 1, 6, 1, 1);

        label_19 = new QLabel(groupBoxPools);
        label_19->setObjectName(QStringLiteral("label_19"));
        label_19->setFont(font1);

        gridLayout_4->addWidget(label_19, 2, 0, 1, 1);

        stackedWidgetMain = new QStackedWidget(centralWidget);
        stackedWidgetMain->setObjectName(QStringLiteral("stackedWidgetMain"));
        stackedWidgetMain->setGeometry(QRect(1420, 50, 965, 765));
        stackedWidgetMain->setStyleSheet(QStringLiteral("background:rgb(170, 255, 0);"));
        page_monitor = new QWidget();
        page_monitor->setObjectName(QStringLiteral("page_monitor"));
        verticalLayout = new QVBoxLayout(page_monitor);
        verticalLayout->setSpacing(0);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        frameMonitorBar = new QFrame(page_monitor);
        frameMonitorBar->setObjectName(QStringLiteral("frameMonitorBar"));
        frameMonitorBar->setMinimumSize(QSize(0, 40));
        frameMonitorBar->setStyleSheet(QStringLiteral("background:rgb(255, 85, 255);"));
        frameMonitorBar->setFrameShape(QFrame::StyledPanel);
        frameMonitorBar->setFrameShadow(QFrame::Raised);
        horizontalLayout_5 = new QHBoxLayout(frameMonitorBar);
        horizontalLayout_5->setSpacing(0);
        horizontalLayout_5->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        horizontalLayout_5->setContentsMargins(0, 0, 0, 0);
        framePadding = new QFrame(frameMonitorBar);
        framePadding->setObjectName(QStringLiteral("framePadding"));
        framePadding->setMinimumSize(QSize(5, 0));
        framePadding->setStyleSheet(QStringLiteral("background:rgb(0, 255, 255);"));
        framePadding->setFrameShape(QFrame::StyledPanel);
        framePadding->setFrameShadow(QFrame::Raised);

        horizontalLayout_5->addWidget(framePadding);

        frameOverview = new QFrame(frameMonitorBar);
        frameOverview->setObjectName(QStringLiteral("frameOverview"));
        frameOverview->setMinimumSize(QSize(50, 0));
        frameOverview->setStyleSheet(QStringLiteral("background:rgb(255, 0, 0);"));
        frameOverview->setFrameShape(QFrame::StyledPanel);
        frameOverview->setFrameShadow(QFrame::Raised);

        horizontalLayout_5->addWidget(frameOverview);

        frameMiningInfo = new QFrame(frameMonitorBar);
        frameMiningInfo->setObjectName(QStringLiteral("frameMiningInfo"));
        frameMiningInfo->setMinimumSize(QSize(50, 0));
        frameMiningInfo->setStyleSheet(QStringLiteral("background:rgb(255, 0, 0);"));
        frameMiningInfo->setFrameShape(QFrame::StyledPanel);
        frameMiningInfo->setFrameShadow(QFrame::Raised);

        horizontalLayout_5->addWidget(frameMiningInfo);

        frameHistory = new QFrame(frameMonitorBar);
        frameHistory->setObjectName(QStringLiteral("frameHistory"));
        frameHistory->setMinimumSize(QSize(50, 0));
        frameHistory->setStyleSheet(QStringLiteral("background:rgb(255, 0, 0);"));
        frameHistory->setFrameShape(QFrame::StyledPanel);
        frameHistory->setFrameShadow(QFrame::Raised);

        horizontalLayout_5->addWidget(frameHistory);

        horizontalSpacer = new QSpacerItem(800, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer);


        verticalLayout->addWidget(frameMonitorBar);

        stackedWidgeMonitorMain = new QStackedWidget(page_monitor);
        stackedWidgeMonitorMain->setObjectName(QStringLiteral("stackedWidgeMonitorMain"));
        stackedWidgeMonitorMain->setMinimumSize(QSize(60, 0));
        stackedWidgeMonitorMain->setStyleSheet(QStringLiteral("background:rgb(91,90,90);"));
        pageOverview = new QWidget();
        pageOverview->setObjectName(QStringLiteral("pageOverview"));
        verticalLayout_7 = new QVBoxLayout(pageOverview);
        verticalLayout_7->setSpacing(6);
        verticalLayout_7->setContentsMargins(11, 11, 11, 11);
        verticalLayout_7->setObjectName(QStringLiteral("verticalLayout_7"));
        splitter = new QSplitter(pageOverview);
        splitter->setObjectName(QStringLiteral("splitter"));
        splitter->setOrientation(Qt::Horizontal);
        groupBox = new QGroupBox(splitter);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setFont(font1);
        horizontalLayout_6 = new QHBoxLayout(groupBox);
        horizontalLayout_6->setSpacing(0);
        horizontalLayout_6->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        graphicsView = new hashrateCharView(groupBox);
        graphicsView->setObjectName(QStringLiteral("graphicsView"));
        graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);

        horizontalLayout_6->addWidget(graphicsView);

        frame = new QFrame(groupBox);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setMinimumSize(QSize(150, 0));
        frame->setStyleSheet(QStringLiteral("background:rgb(255, 0, 0);"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        verticalLayout_2 = new QVBoxLayout(frame);
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        frame_2 = new QFrame(frame);
        frame_2->setObjectName(QStringLiteral("frame_2"));
        frame_2->setMinimumSize(QSize(0, 80));
        frame_2->setStyleSheet(QStringLiteral("background:rgb(0, 0, 100);"));
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);
        verticalLayout_3 = new QVBoxLayout(frame_2);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        label = new QLabel(frame_2);
        label->setObjectName(QStringLiteral("label"));

        verticalLayout_3->addWidget(label);

        lcdNumberHashRate = new QLCDNumber(frame_2);
        lcdNumberHashRate->setObjectName(QStringLiteral("lcdNumberHashRate"));
        QSizePolicy sizePolicy4(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(lcdNumberHashRate->sizePolicy().hasHeightForWidth());
        lcdNumberHashRate->setSizePolicy(sizePolicy4);
        lcdNumberHashRate->setMinimumSize(QSize(0, 50));
        lcdNumberHashRate->setFont(font1);
        lcdNumberHashRate->setDigitCount(7);

        verticalLayout_3->addWidget(lcdNumberHashRate);


        verticalLayout_2->addWidget(frame_2);

        frame_3 = new QFrame(frame);
        frame_3->setObjectName(QStringLiteral("frame_3"));
        frame_3->setMinimumSize(QSize(0, 80));
        frame_3->setStyleSheet(QStringLiteral("background:rgb(0, 0, 100);"));
        frame_3->setFrameShape(QFrame::StyledPanel);
        frame_3->setFrameShadow(QFrame::Raised);
        verticalLayout_4 = new QVBoxLayout(frame_3);
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setContentsMargins(11, 11, 11, 11);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        label_2 = new QLabel(frame_3);
        label_2->setObjectName(QStringLiteral("label_2"));

        verticalLayout_4->addWidget(label_2);

        lcdNumberHashRate_2 = new QLCDNumber(frame_3);
        lcdNumberHashRate_2->setObjectName(QStringLiteral("lcdNumberHashRate_2"));
        sizePolicy4.setHeightForWidth(lcdNumberHashRate_2->sizePolicy().hasHeightForWidth());
        lcdNumberHashRate_2->setSizePolicy(sizePolicy4);
        lcdNumberHashRate_2->setMinimumSize(QSize(0, 50));
        lcdNumberHashRate_2->setFont(font1);
        lcdNumberHashRate_2->setDigitCount(7);

        verticalLayout_4->addWidget(lcdNumberHashRate_2);


        verticalLayout_2->addWidget(frame_3);

        verticalSpacer = new QSpacerItem(20, 248, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer);


        horizontalLayout_6->addWidget(frame);

        splitter->addWidget(groupBox);
        groupBox_3 = new QGroupBox(splitter);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        verticalLayout_5 = new QVBoxLayout(groupBox_3);
        verticalLayout_5->setSpacing(9);
        verticalLayout_5->setContentsMargins(11, 11, 11, 11);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        verticalLayout_5->setContentsMargins(0, 0, 0, 9);
        frame_5 = new QFrame(groupBox_3);
        frame_5->setObjectName(QStringLiteral("frame_5"));
        frame_5->setStyleSheet(QStringLiteral("background:rgb(91,90,0);"));
        frame_5->setFrameShape(QFrame::StyledPanel);
        frame_5->setFrameShadow(QFrame::Raised);
        verticalLayout_6 = new QVBoxLayout(frame_5);
        verticalLayout_6->setSpacing(0);
        verticalLayout_6->setContentsMargins(11, 11, 11, 11);
        verticalLayout_6->setObjectName(QStringLiteral("verticalLayout_6"));
        verticalLayout_6->setContentsMargins(0, 0, 0, 0);
        frame_6 = new QFrame(frame_5);
        frame_6->setObjectName(QStringLiteral("frame_6"));
        frame_6->setMinimumSize(QSize(100, 80));
        frame_6->setStyleSheet(QStringLiteral("background:rgb(91,0,0);"));
        frame_6->setFrameShape(QFrame::StyledPanel);
        frame_6->setFrameShadow(QFrame::Raised);
        horizontalLayout_7 = new QHBoxLayout(frame_6);
        horizontalLayout_7->setSpacing(0);
        horizontalLayout_7->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        horizontalLayout_7->setContentsMargins(0, 0, 0, 0);
        label_23 = new QLabel(frame_6);
        label_23->setObjectName(QStringLiteral("label_23"));
        label_23->setMinimumSize(QSize(70, 0));
        label_23->setAlignment(Qt::AlignCenter);

        horizontalLayout_7->addWidget(label_23);

        frame_10 = new QFrame(frame_6);
        frame_10->setObjectName(QStringLiteral("frame_10"));
        frame_10->setMinimumSize(QSize(100, 50));
        frame_10->setStyleSheet(QStringLiteral("background:rgb(91,100,100);"));
        frame_10->setFrameShape(QFrame::StyledPanel);
        frame_10->setFrameShadow(QFrame::Raised);
        gridLayout_7 = new QGridLayout(frame_10);
        gridLayout_7->setSpacing(0);
        gridLayout_7->setContentsMargins(11, 11, 11, 11);
        gridLayout_7->setObjectName(QStringLiteral("gridLayout_7"));
        gridLayout_7->setContentsMargins(0, 0, 0, 0);
        lcdNumberMinMemClock = new QLCDNumber(frame_10);
        lcdNumberMinMemClock->setObjectName(QStringLiteral("lcdNumberMinMemClock"));

        gridLayout_7->addWidget(lcdNumberMinMemClock, 1, 1, 1, 1);

        lcdNumberMaxMemClock = new QLCDNumber(frame_10);
        lcdNumberMaxMemClock->setObjectName(QStringLiteral("lcdNumberMaxMemClock"));

        gridLayout_7->addWidget(lcdNumberMaxMemClock, 0, 1, 1, 1);

        pushButton_2 = new QPushButton(frame_10);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));

        gridLayout_7->addWidget(pushButton_2, 0, 2, 1, 1);

        pushButton_3 = new QPushButton(frame_10);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));

        gridLayout_7->addWidget(pushButton_3, 1, 2, 1, 1);


        horizontalLayout_7->addWidget(frame_10);


        verticalLayout_6->addWidget(frame_6);

        frame_11 = new QFrame(frame_5);
        frame_11->setObjectName(QStringLiteral("frame_11"));
        frame_11->setMinimumSize(QSize(100, 80));
        frame_11->setStyleSheet(QStringLiteral("background:rgb(91,0,0);"));
        frame_11->setFrameShape(QFrame::StyledPanel);
        frame_11->setFrameShadow(QFrame::Raised);
        horizontalLayout_8 = new QHBoxLayout(frame_11);
        horizontalLayout_8->setSpacing(0);
        horizontalLayout_8->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        horizontalLayout_8->setContentsMargins(0, 0, 0, 0);
        label_34 = new QLabel(frame_11);
        label_34->setObjectName(QStringLiteral("label_34"));
        label_34->setMinimumSize(QSize(70, 0));
        label_34->setAlignment(Qt::AlignCenter);

        horizontalLayout_8->addWidget(label_34);

        frame_12 = new QFrame(frame_11);
        frame_12->setObjectName(QStringLiteral("frame_12"));
        frame_12->setMinimumSize(QSize(100, 50));
        frame_12->setStyleSheet(QStringLiteral("background:rgb(91,100,100);"));
        frame_12->setFrameShape(QFrame::StyledPanel);
        frame_12->setFrameShadow(QFrame::Raised);
        gridLayout_10 = new QGridLayout(frame_12);
        gridLayout_10->setSpacing(0);
        gridLayout_10->setContentsMargins(11, 11, 11, 11);
        gridLayout_10->setObjectName(QStringLiteral("gridLayout_10"));
        gridLayout_10->setContentsMargins(0, 0, 0, 0);
        lcdNumberMinMemClock_2 = new QLCDNumber(frame_12);
        lcdNumberMinMemClock_2->setObjectName(QStringLiteral("lcdNumberMinMemClock_2"));

        gridLayout_10->addWidget(lcdNumberMinMemClock_2, 1, 1, 1, 1);

        lcdNumberMaxMemClock_2 = new QLCDNumber(frame_12);
        lcdNumberMaxMemClock_2->setObjectName(QStringLiteral("lcdNumberMaxMemClock_2"));

        gridLayout_10->addWidget(lcdNumberMaxMemClock_2, 0, 1, 1, 1);

        pushButton_4 = new QPushButton(frame_12);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));

        gridLayout_10->addWidget(pushButton_4, 0, 2, 1, 1);

        pushButton_5 = new QPushButton(frame_12);
        pushButton_5->setObjectName(QStringLiteral("pushButton_5"));

        gridLayout_10->addWidget(pushButton_5, 1, 2, 1, 1);


        horizontalLayout_8->addWidget(frame_12);


        verticalLayout_6->addWidget(frame_11);

        frame_13 = new QFrame(frame_5);
        frame_13->setObjectName(QStringLiteral("frame_13"));
        frame_13->setMinimumSize(QSize(100, 80));
        frame_13->setStyleSheet(QStringLiteral("background:rgb(91,0,0);"));
        frame_13->setFrameShape(QFrame::StyledPanel);
        frame_13->setFrameShadow(QFrame::Raised);
        horizontalLayout_10 = new QHBoxLayout(frame_13);
        horizontalLayout_10->setSpacing(0);
        horizontalLayout_10->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_10->setObjectName(QStringLiteral("horizontalLayout_10"));
        horizontalLayout_10->setContentsMargins(0, 0, 0, 0);
        label_36 = new QLabel(frame_13);
        label_36->setObjectName(QStringLiteral("label_36"));
        label_36->setMinimumSize(QSize(70, 0));
        label_36->setAlignment(Qt::AlignCenter);

        horizontalLayout_10->addWidget(label_36);

        frame_15 = new QFrame(frame_13);
        frame_15->setObjectName(QStringLiteral("frame_15"));
        frame_15->setMinimumSize(QSize(100, 50));
        frame_15->setStyleSheet(QStringLiteral("background:rgb(91,100,100);"));
        frame_15->setFrameShape(QFrame::StyledPanel);
        frame_15->setFrameShadow(QFrame::Raised);
        gridLayout_14 = new QGridLayout(frame_15);
        gridLayout_14->setSpacing(0);
        gridLayout_14->setContentsMargins(11, 11, 11, 11);
        gridLayout_14->setObjectName(QStringLiteral("gridLayout_14"));
        gridLayout_14->setContentsMargins(0, 0, 0, 0);
        lcdNumberMinMemClock_4 = new QLCDNumber(frame_15);
        lcdNumberMinMemClock_4->setObjectName(QStringLiteral("lcdNumberMinMemClock_4"));

        gridLayout_14->addWidget(lcdNumberMinMemClock_4, 1, 1, 1, 1);

        lcdNumberMaxMemClock_4 = new QLCDNumber(frame_15);
        lcdNumberMaxMemClock_4->setObjectName(QStringLiteral("lcdNumberMaxMemClock_4"));

        gridLayout_14->addWidget(lcdNumberMaxMemClock_4, 0, 1, 1, 1);

        pushButton_8 = new QPushButton(frame_15);
        pushButton_8->setObjectName(QStringLiteral("pushButton_8"));

        gridLayout_14->addWidget(pushButton_8, 0, 2, 1, 1);

        pushButton_9 = new QPushButton(frame_15);
        pushButton_9->setObjectName(QStringLiteral("pushButton_9"));

        gridLayout_14->addWidget(pushButton_9, 1, 2, 1, 1);


        horizontalLayout_10->addWidget(frame_15);


        verticalLayout_6->addWidget(frame_13);

        frame_9 = new QFrame(frame_5);
        frame_9->setObjectName(QStringLiteral("frame_9"));
        frame_9->setMinimumSize(QSize(100, 100));
        frame_9->setStyleSheet(QStringLiteral("background:rgb(91,0,0);"));
        frame_9->setFrameShape(QFrame::StyledPanel);
        frame_9->setFrameShadow(QFrame::Raised);
        gridLayout_5 = new QGridLayout(frame_9);
        gridLayout_5->setSpacing(0);
        gridLayout_5->setContentsMargins(11, 11, 11, 11);
        gridLayout_5->setObjectName(QStringLiteral("gridLayout_5"));
        gridLayout_5->setContentsMargins(0, 0, 0, 0);
        graphicsViewEff = new hashrateCharView(frame_9);
        graphicsViewEff->setObjectName(QStringLiteral("graphicsViewEff"));
        graphicsViewEff->setMinimumSize(QSize(100, 100));

        gridLayout_5->addWidget(graphicsViewEff, 0, 0, 1, 1);


        verticalLayout_6->addWidget(frame_9);

        verticalSpacer_2 = new QSpacerItem(20, 7, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_6->addItem(verticalSpacer_2);


        verticalLayout_5->addWidget(frame_5);

        splitter->addWidget(groupBox_3);

        verticalLayout_7->addWidget(splitter);

        splitter_2 = new QSplitter(pageOverview);
        splitter_2->setObjectName(QStringLiteral("splitter_2"));
        splitter_2->setOrientation(Qt::Horizontal);
        groupBox_2 = new QGroupBox(splitter_2);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setFont(font1);
        gridLayout_6 = new QGridLayout(groupBox_2);
        gridLayout_6->setSpacing(6);
        gridLayout_6->setContentsMargins(11, 11, 11, 11);
        gridLayout_6->setObjectName(QStringLiteral("gridLayout_6"));
        graphicsViewTemp = new hashrateCharView(groupBox_2);
        graphicsViewTemp->setObjectName(QStringLiteral("graphicsViewTemp"));
        graphicsViewTemp->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);

        gridLayout_6->addWidget(graphicsViewTemp, 0, 0, 1, 1);

        splitter_2->addWidget(groupBox_2);
        groupBoxDiskInfo = new QGroupBox(splitter_2);
        groupBoxDiskInfo->setObjectName(QStringLiteral("groupBoxDiskInfo"));
        gridLayout_13 = new QGridLayout(groupBoxDiskInfo);
        gridLayout_13->setSpacing(6);
        gridLayout_13->setContentsMargins(11, 11, 11, 11);
        gridLayout_13->setObjectName(QStringLiteral("gridLayout_13"));
        gridLayoutDiskInfo = new QGridLayout();
        gridLayoutDiskInfo->setSpacing(0);
        gridLayoutDiskInfo->setObjectName(QStringLiteral("gridLayoutDiskInfo"));

        gridLayout_13->addLayout(gridLayoutDiskInfo, 0, 0, 1, 1);

        splitter_2->addWidget(groupBoxDiskInfo);

        verticalLayout_7->addWidget(splitter_2);

        stackedWidgeMonitorMain->addWidget(pageOverview);
        pageMining = new QWidget();
        pageMining->setObjectName(QStringLiteral("pageMining"));
        gridLayout_25 = new QGridLayout(pageMining);
        gridLayout_25->setSpacing(6);
        gridLayout_25->setContentsMargins(11, 11, 11, 11);
        gridLayout_25->setObjectName(QStringLiteral("gridLayout_25"));
        groupBox_4 = new QGroupBox(pageMining);
        groupBox_4->setObjectName(QStringLiteral("groupBox_4"));
        gridLayout_16 = new QGridLayout(groupBox_4);
        gridLayout_16->setSpacing(0);
        gridLayout_16->setContentsMargins(11, 11, 11, 11);
        gridLayout_16->setObjectName(QStringLiteral("gridLayout_16"));
        gridLayout_16->setContentsMargins(1, 0, 1, 0);
        horizontalLayout_15 = new QHBoxLayout();
        horizontalLayout_15->setSpacing(1);
        horizontalLayout_15->setObjectName(QStringLiteral("horizontalLayout_15"));
        gridLayout_15 = new QGridLayout();
        gridLayout_15->setSpacing(6);
        gridLayout_15->setObjectName(QStringLiteral("gridLayout_15"));
        horizontalLayout_14 = new QHBoxLayout();
        horizontalLayout_14->setSpacing(6);
        horizontalLayout_14->setObjectName(QStringLiteral("horizontalLayout_14"));
        labelWallet = new QLabel(groupBox_4);
        labelWallet->setObjectName(QStringLiteral("labelWallet"));
        sizePolicy.setHeightForWidth(labelWallet->sizePolicy().hasHeightForWidth());
        labelWallet->setSizePolicy(sizePolicy);
        labelWallet->setMinimumSize(QSize(0, 30));
        labelWallet->setMaximumSize(QSize(60, 16777215));
        QFont font3;
        font3.setFamily(QStringLiteral("Arial"));
        font3.setPointSize(12);
        font3.setBold(true);
        font3.setWeight(75);
        labelWallet->setFont(font3);

        horizontalLayout_14->addWidget(labelWallet);

        lineEditWallet = new QLineEdit(groupBox_4);
        lineEditWallet->setObjectName(QStringLiteral("lineEditWallet"));
        sizePolicy1.setHeightForWidth(lineEditWallet->sizePolicy().hasHeightForWidth());
        lineEditWallet->setSizePolicy(sizePolicy1);
        lineEditWallet->setMinimumSize(QSize(650, 31));
        QFont font4;
        font4.setPointSize(12);
        lineEditWallet->setFont(font4);

        horizontalLayout_14->addWidget(lineEditWallet);


        gridLayout_15->addLayout(horizontalLayout_14, 2, 0, 1, 4);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(0);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        labelCoin = new QLabel(groupBox_4);
        labelCoin->setObjectName(QStringLiteral("labelCoin"));
        sizePolicy.setHeightForWidth(labelCoin->sizePolicy().hasHeightForWidth());
        labelCoin->setSizePolicy(sizePolicy);
        labelCoin->setMinimumSize(QSize(60, 30));
        labelCoin->setMaximumSize(QSize(50, 16777215));
        labelCoin->setFont(font3);

        horizontalLayout_4->addWidget(labelCoin);

        comboBoxCoin = new QComboBox(groupBox_4);
        comboBoxCoin->setObjectName(QStringLiteral("comboBoxCoin"));
        sizePolicy1.setHeightForWidth(comboBoxCoin->sizePolicy().hasHeightForWidth());
        comboBoxCoin->setSizePolicy(sizePolicy1);
        comboBoxCoin->setMinimumSize(QSize(150, 31));
        comboBoxCoin->setMaximumSize(QSize(90, 16777215));
        comboBoxCoin->setFont(font4);

        horizontalLayout_4->addWidget(comboBoxCoin);


        gridLayout_15->addLayout(horizontalLayout_4, 0, 0, 1, 1);

        horizontalSpacer_3 = new QSpacerItem(98, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_15->addItem(horizontalSpacer_3, 1, 3, 1, 1);

        horizontalLayout_12 = new QHBoxLayout();
        horizontalLayout_12->setSpacing(6);
        horizontalLayout_12->setObjectName(QStringLiteral("horizontalLayout_12"));
        labelPool = new QLabel(groupBox_4);
        labelPool->setObjectName(QStringLiteral("labelPool"));
        sizePolicy.setHeightForWidth(labelPool->sizePolicy().hasHeightForWidth());
        labelPool->setSizePolicy(sizePolicy);
        labelPool->setMinimumSize(QSize(60, 30));
        labelPool->setMaximumSize(QSize(50, 16777215));
        labelPool->setFont(font3);

        horizontalLayout_12->addWidget(labelPool);

        comboBoxPool = new QComboBox(groupBox_4);
        comboBoxPool->setObjectName(QStringLiteral("comboBoxPool"));
        comboBoxPool->setMinimumSize(QSize(150, 31));
        comboBoxPool->setFont(font4);

        horizontalLayout_12->addWidget(comboBoxPool);


        gridLayout_15->addLayout(horizontalLayout_12, 1, 0, 1, 1);

        horizontalLayout_13 = new QHBoxLayout();
        horizontalLayout_13->setSpacing(0);
        horizontalLayout_13->setObjectName(QStringLiteral("horizontalLayout_13"));
        labelWorker = new QLabel(groupBox_4);
        labelWorker->setObjectName(QStringLiteral("labelWorker"));
        sizePolicy.setHeightForWidth(labelWorker->sizePolicy().hasHeightForWidth());
        labelWorker->setSizePolicy(sizePolicy);
        labelWorker->setMinimumSize(QSize(80, 31));
        labelWorker->setMaximumSize(QSize(100, 16777215));
        labelWorker->setFont(font3);

        horizontalLayout_13->addWidget(labelWorker);

        lineEditWorker = new QLineEdit(groupBox_4);
        lineEditWorker->setObjectName(QStringLiteral("lineEditWorker"));
        sizePolicy1.setHeightForWidth(lineEditWorker->sizePolicy().hasHeightForWidth());
        lineEditWorker->setSizePolicy(sizePolicy1);
        lineEditWorker->setMinimumSize(QSize(150, 31));
        lineEditWorker->setFont(font4);

        horizontalLayout_13->addWidget(lineEditWorker);

        horizontalSpacer_6 = new QSpacerItem(98, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_13->addItem(horizontalSpacer_6);


        gridLayout_15->addLayout(horizontalLayout_13, 1, 1, 1, 2);

        horizontalLayout_11 = new QHBoxLayout();
        horizontalLayout_11->setSpacing(0);
        horizontalLayout_11->setObjectName(QStringLiteral("horizontalLayout_11"));
        labelCore = new QLabel(groupBox_4);
        labelCore->setObjectName(QStringLiteral("labelCore"));
        sizePolicy.setHeightForWidth(labelCore->sizePolicy().hasHeightForWidth());
        labelCore->setSizePolicy(sizePolicy);
        labelCore->setMinimumSize(QSize(80, 31));
        labelCore->setMaximumSize(QSize(50, 16777215));
        labelCore->setFont(font3);

        horizontalLayout_11->addWidget(labelCore);

        comboBoxCore = new QComboBox(groupBox_4);
        comboBoxCore->setObjectName(QStringLiteral("comboBoxCore"));
        comboBoxCore->setMinimumSize(QSize(150, 31));
        comboBoxCore->setFont(font4);

        horizontalLayout_11->addWidget(comboBoxCore);

        horizontalSpacer_2 = new QSpacerItem(118, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_11->addItem(horizontalSpacer_2);


        gridLayout_15->addLayout(horizontalLayout_11, 0, 1, 1, 1);


        horizontalLayout_15->addLayout(gridLayout_15);

        pushButton_10 = new QPushButton(groupBox_4);
        pushButton_10->setObjectName(QStringLiteral("pushButton_10"));
        pushButton_10->setMinimumSize(QSize(200, 230));

        horizontalLayout_15->addWidget(pushButton_10);


        gridLayout_16->addLayout(horizontalLayout_15, 0, 0, 1, 1);


        gridLayout_25->addWidget(groupBox_4, 0, 0, 1, 1);

        horizontalLayout_21 = new QHBoxLayout();
        horizontalLayout_21->setSpacing(6);
        horizontalLayout_21->setObjectName(QStringLiteral("horizontalLayout_21"));
        groupBox_5 = new QGroupBox(pageMining);
        groupBox_5->setObjectName(QStringLiteral("groupBox_5"));
        gridLayout_17 = new QGridLayout(groupBox_5);
        gridLayout_17->setSpacing(0);
        gridLayout_17->setContentsMargins(11, 11, 11, 11);
        gridLayout_17->setObjectName(QStringLiteral("gridLayout_17"));
        gridLayout_17->setContentsMargins(0, 0, 0, 0);
        frame_8 = new QFrame(groupBox_5);
        frame_8->setObjectName(QStringLiteral("frame_8"));
        frame_8->setStyleSheet(QStringLiteral("background:rgb(1,1,90);"));
        frame_8->setFrameShape(QFrame::StyledPanel);
        frame_8->setFrameShadow(QFrame::Raised);
        horizontalLayout_18 = new QHBoxLayout(frame_8);
        horizontalLayout_18->setSpacing(0);
        horizontalLayout_18->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_18->setObjectName(QStringLiteral("horizontalLayout_18"));
        horizontalLayout_18->setContentsMargins(0, 0, 0, 0);
        frame_20 = new QFrame(frame_8);
        frame_20->setObjectName(QStringLiteral("frame_20"));
        frame_20->setMinimumSize(QSize(0, 40));
        frame_20->setStyleSheet(QStringLiteral("background:rgb(200,1,90);"));
        frame_20->setFrameShape(QFrame::StyledPanel);
        frame_20->setFrameShadow(QFrame::Raised);
        gridLayout_20 = new QGridLayout(frame_20);
        gridLayout_20->setSpacing(6);
        gridLayout_20->setContentsMargins(11, 11, 11, 11);
        gridLayout_20->setObjectName(QStringLiteral("gridLayout_20"));
        radioButtonNaopool = new QRadioButton(frame_20);
        radioButtonNaopool->setObjectName(QStringLiteral("radioButtonNaopool"));
        radioButtonNaopool->setFont(font1);
        radioButtonNaopool->setChecked(true);

        gridLayout_20->addWidget(radioButtonNaopool, 0, 0, 1, 1);


        horizontalLayout_18->addWidget(frame_20);

        frame_21 = new QFrame(frame_8);
        frame_21->setObjectName(QStringLiteral("frame_21"));
        frame_21->setStyleSheet(QStringLiteral("background:rgb(200,1,90);"));
        frame_21->setFrameShape(QFrame::StyledPanel);
        frame_21->setFrameShadow(QFrame::Raised);
        gridLayout_21 = new QGridLayout(frame_21);
        gridLayout_21->setSpacing(6);
        gridLayout_21->setContentsMargins(11, 11, 11, 11);
        gridLayout_21->setObjectName(QStringLiteral("gridLayout_21"));
        radioButtonEthermine = new QRadioButton(frame_21);
        radioButtonEthermine->setObjectName(QStringLiteral("radioButtonEthermine"));
        radioButtonEthermine->setEnabled(false);
        radioButtonEthermine->setFont(font1);

        gridLayout_21->addWidget(radioButtonEthermine, 0, 0, 1, 1);


        horizontalLayout_18->addWidget(frame_21);

        frame_22 = new QFrame(frame_8);
        frame_22->setObjectName(QStringLiteral("frame_22"));
        frame_22->setStyleSheet(QStringLiteral("background:rgb(200,1,90);"));
        frame_22->setFrameShape(QFrame::StyledPanel);
        frame_22->setFrameShadow(QFrame::Raised);
        gridLayout_22 = new QGridLayout(frame_22);
        gridLayout_22->setSpacing(6);
        gridLayout_22->setContentsMargins(11, 11, 11, 11);
        gridLayout_22->setObjectName(QStringLiteral("gridLayout_22"));
        radioButtonDwarfPool = new QRadioButton(frame_22);
        radioButtonDwarfPool->setObjectName(QStringLiteral("radioButtonDwarfPool"));
        radioButtonDwarfPool->setEnabled(false);
        radioButtonDwarfPool->setFont(font1);

        gridLayout_22->addWidget(radioButtonDwarfPool, 0, 0, 1, 1);


        horizontalLayout_18->addWidget(frame_22);


        gridLayout_17->addWidget(frame_8, 1, 0, 1, 1);

        lineEditAccount = new QLineEdit(groupBox_5);
        lineEditAccount->setObjectName(QStringLiteral("lineEditAccount"));
        lineEditAccount->setMinimumSize(QSize(0, 30));
        lineEditAccount->setFont(font1);

        gridLayout_17->addWidget(lineEditAccount, 2, 0, 1, 1);

        horizontalLayout_16 = new QHBoxLayout();
        horizontalLayout_16->setSpacing(0);
        horizontalLayout_16->setObjectName(QStringLiteral("horizontalLayout_16"));
        frame_16 = new QFrame(groupBox_5);
        frame_16->setObjectName(QStringLiteral("frame_16"));
        frame_16->setMinimumSize(QSize(200, 270));
        frame_16->setStyleSheet(QStringLiteral("background:rgb(91,1,90);"));
        frame_16->setFrameShape(QFrame::StyledPanel);
        frame_16->setFrameShadow(QFrame::Raised);
        gridLayout_18 = new QGridLayout(frame_16);
        gridLayout_18->setSpacing(0);
        gridLayout_18->setContentsMargins(11, 11, 11, 11);
        gridLayout_18->setObjectName(QStringLiteral("gridLayout_18"));
        gridLayout_18->setContentsMargins(0, 0, 0, 0);
        verticalLayout_8 = new QVBoxLayout();
        verticalLayout_8->setSpacing(0);
        verticalLayout_8->setObjectName(QStringLiteral("verticalLayout_8"));
        frame_18 = new QFrame(frame_16);
        frame_18->setObjectName(QStringLiteral("frame_18"));
        frame_18->setMinimumSize(QSize(0, 30));
        frame_18->setStyleSheet(QStringLiteral("background:rgb(91,90,90);"));
        frame_18->setFrameShape(QFrame::StyledPanel);
        frame_18->setFrameShadow(QFrame::Raised);
        horizontalLayout_17 = new QHBoxLayout(frame_18);
        horizontalLayout_17->setSpacing(6);
        horizontalLayout_17->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_17->setObjectName(QStringLiteral("horizontalLayout_17"));
        label_37 = new QLabel(frame_18);
        label_37->setObjectName(QStringLiteral("label_37"));

        horizontalLayout_17->addWidget(label_37);


        verticalLayout_8->addWidget(frame_18);

        frame_19 = new QFrame(frame_16);
        frame_19->setObjectName(QStringLiteral("frame_19"));
        frame_19->setMinimumSize(QSize(200, 220));
        frame_19->setStyleSheet(QStringLiteral("background:rgb(1,90,90);"));
        frame_19->setFrameShape(QFrame::StyledPanel);
        frame_19->setFrameShadow(QFrame::Raised);
        gridLayout_19 = new QGridLayout(frame_19);
        gridLayout_19->setSpacing(6);
        gridLayout_19->setContentsMargins(11, 11, 11, 11);
        gridLayout_19->setObjectName(QStringLiteral("gridLayout_19"));
        label_38 = new QLabel(frame_19);
        label_38->setObjectName(QStringLiteral("label_38"));
        label_38->setMinimumSize(QSize(190, 190));
        QFont font5;
        font5.setFamily(QStringLiteral("Adobe Arabic"));
        font5.setPointSize(120);
        label_38->setFont(font5);

        gridLayout_19->addWidget(label_38, 0, 0, 1, 1);


        verticalLayout_8->addWidget(frame_19);


        gridLayout_18->addLayout(verticalLayout_8, 0, 0, 1, 1);


        horizontalLayout_16->addWidget(frame_16);

        frame_17 = new QFrame(groupBox_5);
        frame_17->setObjectName(QStringLiteral("frame_17"));
        frame_17->setStyleSheet(QStringLiteral("background:rgb(91,100,10);"));
        frame_17->setFrameShape(QFrame::StyledPanel);
        frame_17->setFrameShadow(QFrame::Raised);

        horizontalLayout_16->addWidget(frame_17);


        gridLayout_17->addLayout(horizontalLayout_16, 3, 0, 1, 1);

        frame_7 = new QFrame(groupBox_5);
        frame_7->setObjectName(QStringLiteral("frame_7"));
        frame_7->setMinimumSize(QSize(0, 90));
        frame_7->setStyleSheet(QStringLiteral("background:rgb(91,1,90);"));
        frame_7->setFrameShape(QFrame::StyledPanel);
        frame_7->setFrameShadow(QFrame::Raised);
        horizontalLayout_19 = new QHBoxLayout(frame_7);
        horizontalLayout_19->setSpacing(6);
        horizontalLayout_19->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_19->setObjectName(QStringLiteral("horizontalLayout_19"));
        label_39 = new QLabel(frame_7);
        label_39->setObjectName(QStringLiteral("label_39"));
        label_39->setMinimumSize(QSize(100, 0));
        QFont font6;
        font6.setFamily(QStringLiteral("Adobe Arabic"));
        font6.setPointSize(36);
        label_39->setFont(font6);

        horizontalLayout_19->addWidget(label_39);

        horizontalSpacer_4 = new QSpacerItem(339, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_19->addItem(horizontalSpacer_4);


        gridLayout_17->addWidget(frame_7, 0, 0, 1, 1);


        horizontalLayout_21->addWidget(groupBox_5);

        groupBox_6 = new QGroupBox(pageMining);
        groupBox_6->setObjectName(QStringLiteral("groupBox_6"));
        gridLayout_23 = new QGridLayout(groupBox_6);
        gridLayout_23->setSpacing(0);
        gridLayout_23->setContentsMargins(11, 11, 11, 11);
        gridLayout_23->setObjectName(QStringLiteral("gridLayout_23"));
        gridLayout_23->setContentsMargins(0, 0, 0, 0);
        verticalLayout_9 = new QVBoxLayout();
        verticalLayout_9->setSpacing(0);
        verticalLayout_9->setObjectName(QStringLiteral("verticalLayout_9"));
        frame_25 = new QFrame(groupBox_6);
        frame_25->setObjectName(QStringLiteral("frame_25"));
        frame_25->setMinimumSize(QSize(0, 90));
        frame_25->setStyleSheet(QStringLiteral("background:rgb(91,1,90);"));
        frame_25->setFrameShape(QFrame::StyledPanel);
        frame_25->setFrameShadow(QFrame::Raised);
        horizontalLayout_20 = new QHBoxLayout(frame_25);
        horizontalLayout_20->setSpacing(6);
        horizontalLayout_20->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_20->setObjectName(QStringLiteral("horizontalLayout_20"));
        label_40 = new QLabel(frame_25);
        label_40->setObjectName(QStringLiteral("label_40"));
        label_40->setMinimumSize(QSize(100, 0));
        label_40->setFont(font6);

        horizontalLayout_20->addWidget(label_40);

        horizontalSpacer_5 = new QSpacerItem(320, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_20->addItem(horizontalSpacer_5);


        verticalLayout_9->addWidget(frame_25);

        frame_24 = new QFrame(groupBox_6);
        frame_24->setObjectName(QStringLiteral("frame_24"));
        frame_24->setMinimumSize(QSize(0, 320));
        frame_24->setStyleSheet(QStringLiteral("background:rgb(91,190,90);"));
        frame_24->setFrameShape(QFrame::StyledPanel);
        frame_24->setFrameShadow(QFrame::Raised);
        gridLayout_24 = new QGridLayout(frame_24);
        gridLayout_24->setSpacing(2);
        gridLayout_24->setContentsMargins(11, 11, 11, 11);
        gridLayout_24->setObjectName(QStringLiteral("gridLayout_24"));
        gridLayout_24->setContentsMargins(2, 2, 2, 2);
        textEdit = new QTextEdit(frame_24);
        textEdit->setObjectName(QStringLiteral("textEdit"));
        textEdit->setFont(font1);
        textEdit->setReadOnly(true);

        gridLayout_24->addWidget(textEdit, 0, 0, 1, 1);


        verticalLayout_9->addWidget(frame_24);


        gridLayout_23->addLayout(verticalLayout_9, 0, 0, 1, 1);


        horizontalLayout_21->addWidget(groupBox_6);


        gridLayout_25->addLayout(horizontalLayout_21, 1, 0, 1, 1);

        stackedWidgeMonitorMain->addWidget(pageMining);
        pageHistory = new QWidget();
        pageHistory->setObjectName(QStringLiteral("pageHistory"));
        groupBox_7 = new QGroupBox(pageHistory);
        groupBox_7->setObjectName(QStringLiteral("groupBox_7"));
        groupBox_7->setGeometry(QRect(10, 30, 941, 311));
        gridLayout_29 = new QGridLayout(groupBox_7);
        gridLayout_29->setSpacing(6);
        gridLayout_29->setContentsMargins(11, 11, 11, 11);
        gridLayout_29->setObjectName(QStringLiteral("gridLayout_29"));
        horizontalLayout_23 = new QHBoxLayout();
        horizontalLayout_23->setSpacing(0);
        horizontalLayout_23->setObjectName(QStringLiteral("horizontalLayout_23"));
        verticalLayout_10 = new QVBoxLayout();
        verticalLayout_10->setSpacing(0);
        verticalLayout_10->setObjectName(QStringLiteral("verticalLayout_10"));
        frame_23 = new QFrame(groupBox_7);
        frame_23->setObjectName(QStringLiteral("frame_23"));
        frame_23->setMinimumSize(QSize(300, 50));
        frame_23->setStyleSheet(QStringLiteral("background:rgb(91,0,90);"));
        frame_23->setFrameShape(QFrame::StyledPanel);
        frame_23->setFrameShadow(QFrame::Raised);
        horizontalLayout_22 = new QHBoxLayout(frame_23);
        horizontalLayout_22->setSpacing(6);
        horizontalLayout_22->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_22->setObjectName(QStringLiteral("horizontalLayout_22"));
        label_41 = new QLabel(frame_23);
        label_41->setObjectName(QStringLiteral("label_41"));
        label_41->setMinimumSize(QSize(100, 0));
        QFont font7;
        font7.setFamily(QStringLiteral("Adobe Arabic"));
        font7.setPointSize(16);
        label_41->setFont(font7);

        horizontalLayout_22->addWidget(label_41);

        horizontalSpacer_7 = new QSpacerItem(171, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_22->addItem(horizontalSpacer_7);


        verticalLayout_10->addWidget(frame_23);

        frame_26 = new QFrame(groupBox_7);
        frame_26->setObjectName(QStringLiteral("frame_26"));
        frame_26->setMinimumSize(QSize(260, 220));
        frame_26->setStyleSheet(QStringLiteral("background:rgb(91,100,90);"));
        frame_26->setFrameShape(QFrame::StyledPanel);
        frame_26->setFrameShadow(QFrame::Raised);
        gridLayout_26 = new QGridLayout(frame_26);
        gridLayout_26->setSpacing(1);
        gridLayout_26->setContentsMargins(11, 11, 11, 11);
        gridLayout_26->setObjectName(QStringLiteral("gridLayout_26"));
        gridLayout_26->setContentsMargins(1, 1, 1, 1);
        textEditSettings = new QTextEdit(frame_26);
        textEditSettings->setObjectName(QStringLiteral("textEditSettings"));
        textEditSettings->setFont(font1);

        gridLayout_26->addWidget(textEditSettings, 0, 0, 1, 1);


        verticalLayout_10->addWidget(frame_26);


        horizontalLayout_23->addLayout(verticalLayout_10);

        frame_28 = new QFrame(groupBox_7);
        frame_28->setObjectName(QStringLiteral("frame_28"));
        frame_28->setMinimumSize(QSize(300, 50));
        frame_28->setStyleSheet(QStringLiteral("background:rgb(91,0,90);"));
        frame_28->setFrameShape(QFrame::StyledPanel);
        frame_28->setFrameShadow(QFrame::Raised);
        gridLayout_27 = new QGridLayout(frame_28);
        gridLayout_27->setSpacing(6);
        gridLayout_27->setContentsMargins(11, 11, 11, 11);
        gridLayout_27->setObjectName(QStringLiteral("gridLayout_27"));
        formLayout = new QFormLayout();
        formLayout->setSpacing(6);
        formLayout->setObjectName(QStringLiteral("formLayout"));
        formLayout->setHorizontalSpacing(0);
        formLayout->setVerticalSpacing(0);
        label_43 = new QLabel(frame_28);
        label_43->setObjectName(QStringLiteral("label_43"));
        label_43->setMinimumSize(QSize(100, 90));

        formLayout->setWidget(0, QFormLayout::LabelRole, label_43);

        label_46 = new QLabel(frame_28);
        label_46->setObjectName(QStringLiteral("label_46"));
        label_46->setMinimumSize(QSize(100, 90));

        formLayout->setWidget(1, QFormLayout::LabelRole, label_46);

        label_45 = new QLabel(frame_28);
        label_45->setObjectName(QStringLiteral("label_45"));
        label_45->setMinimumSize(QSize(100, 90));

        formLayout->setWidget(2, QFormLayout::LabelRole, label_45);

        verticalLayout_11 = new QVBoxLayout();
        verticalLayout_11->setSpacing(6);
        verticalLayout_11->setObjectName(QStringLiteral("verticalLayout_11"));
        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_11->addItem(verticalSpacer_3);

        spinBoxChangePageSizeMax = new QSpinBox(frame_28);
        spinBoxChangePageSizeMax->setObjectName(QStringLiteral("spinBoxChangePageSizeMax"));

        verticalLayout_11->addWidget(spinBoxChangePageSizeMax);

        verticalSpacer_4 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_11->addItem(verticalSpacer_4);


        formLayout->setLayout(1, QFormLayout::FieldRole, verticalLayout_11);

        verticalLayout_12 = new QVBoxLayout();
        verticalLayout_12->setSpacing(6);
        verticalLayout_12->setObjectName(QStringLiteral("verticalLayout_12"));
        verticalSpacer_5 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_12->addItem(verticalSpacer_5);

        spinBoxChangePageSizeMin = new QSpinBox(frame_28);
        spinBoxChangePageSizeMin->setObjectName(QStringLiteral("spinBoxChangePageSizeMin"));

        verticalLayout_12->addWidget(spinBoxChangePageSizeMin);

        verticalSpacer_6 = new QSpacerItem(20, 48, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_12->addItem(verticalSpacer_6);


        formLayout->setLayout(2, QFormLayout::FieldRole, verticalLayout_12);

        verticalLayout_13 = new QVBoxLayout();
        verticalLayout_13->setSpacing(6);
        verticalLayout_13->setObjectName(QStringLiteral("verticalLayout_13"));
        verticalSpacer_7 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_13->addItem(verticalSpacer_7);

        comboBoxChangePageSize = new QComboBox(frame_28);
        comboBoxChangePageSize->setObjectName(QStringLiteral("comboBoxChangePageSize"));

        verticalLayout_13->addWidget(comboBoxChangePageSize);

        verticalSpacer_8 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_13->addItem(verticalSpacer_8);


        formLayout->setLayout(0, QFormLayout::FieldRole, verticalLayout_13);


        gridLayout_27->addLayout(formLayout, 0, 0, 1, 1);


        horizontalLayout_23->addWidget(frame_28);


        gridLayout_29->addLayout(horizontalLayout_23, 0, 0, 1, 1);

        frame_27 = new QFrame(groupBox_7);
        frame_27->setObjectName(QStringLiteral("frame_27"));
        frame_27->setFrameShape(QFrame::StyledPanel);
        frame_27->setFrameShadow(QFrame::Raised);
        gridLayout_28 = new QGridLayout(frame_27);
        gridLayout_28->setSpacing(6);
        gridLayout_28->setContentsMargins(11, 11, 11, 11);
        gridLayout_28->setObjectName(QStringLiteral("gridLayout_28"));
        pushButtonChangePageSize = new QPushButton(frame_27);
        pushButtonChangePageSize->setObjectName(QStringLiteral("pushButtonChangePageSize"));
        pushButtonChangePageSize->setFont(font1);

        gridLayout_28->addWidget(pushButtonChangePageSize, 1, 0, 1, 1);

        horizontalSpacer_8 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_28->addItem(horizontalSpacer_8, 0, 0, 1, 1);

        horizontalSpacer_10 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_28->addItem(horizontalSpacer_10, 2, 0, 1, 1);


        gridLayout_29->addWidget(frame_27, 0, 1, 1, 1);

        stackedWidgeMonitorMain->addWidget(pageHistory);

        verticalLayout->addWidget(stackedWidgeMonitorMain);

        stackedWidgetMain->addWidget(page_monitor);
        page_2 = new QWidget();
        page_2->setObjectName(QStringLiteral("page_2"));
        stackedWidgetMain->addWidget(page_2);
        frame_30 = new QFrame(centralWidget);
        frame_30->setObjectName(QStringLiteral("frame_30"));
        frame_30->setGeometry(QRect(1820, 890, 621, 321));
        frame_30->setStyleSheet(QStringLiteral("background:rgb(230,90,90);"));
        frame_30->setFrameShape(QFrame::StyledPanel);
        frame_30->setFrameShadow(QFrame::Raised);
        frame_29 = new QFrame(centralWidget);
        frame_29->setObjectName(QStringLiteral("frame_29"));
        frame_29->setGeometry(QRect(1350, 930, 281, 301));
        frame_29->setStyleSheet(QStringLiteral("background:rgb(1,90,90);"));
        frame_29->setFrameShape(QFrame::StyledPanel);
        frame_29->setFrameShadow(QFrame::Raised);
        gridLayout_30 = new QGridLayout(frame_29);
        gridLayout_30->setSpacing(0);
        gridLayout_30->setContentsMargins(11, 11, 11, 11);
        gridLayout_30->setObjectName(QStringLiteral("gridLayout_30"));
        gridLayout_30->setContentsMargins(0, 0, 0, 0);
        verticalLayout_14 = new QVBoxLayout();
        verticalLayout_14->setSpacing(0);
        verticalLayout_14->setObjectName(QStringLiteral("verticalLayout_14"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        labelHistoryDeviceNum = new QLabel(frame_29);
        labelHistoryDeviceNum->setObjectName(QStringLiteral("labelHistoryDeviceNum"));
        labelHistoryDeviceNum->setMinimumSize(QSize(0, 50));
        labelHistoryDeviceNum->setFont(font1);

        horizontalLayout->addWidget(labelHistoryDeviceNum);

        horizontalSpacer_12 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_12);


        verticalLayout_14->addLayout(horizontalLayout);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalSpacer_11 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_11);

        spinBoxHistoryDeviceNum = new QSpinBox(frame_29);
        spinBoxHistoryDeviceNum->setObjectName(QStringLiteral("spinBoxHistoryDeviceNum"));

        horizontalLayout_3->addWidget(spinBoxHistoryDeviceNum);


        verticalLayout_14->addLayout(horizontalLayout_3);

        horizontalLayout_25 = new QHBoxLayout();
        horizontalLayout_25->setSpacing(6);
        horizontalLayout_25->setObjectName(QStringLiteral("horizontalLayout_25"));
        labelHistoryDeviceNum_2 = new QLabel(frame_29);
        labelHistoryDeviceNum_2->setObjectName(QStringLiteral("labelHistoryDeviceNum_2"));
        labelHistoryDeviceNum_2->setMinimumSize(QSize(0, 50));
        labelHistoryDeviceNum_2->setFont(font1);

        horizontalLayout_25->addWidget(labelHistoryDeviceNum_2);

        horizontalSpacer_13 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_25->addItem(horizontalSpacer_13);


        verticalLayout_14->addLayout(horizontalLayout_25);

        horizontalLayout_26 = new QHBoxLayout();
        horizontalLayout_26->setSpacing(6);
        horizontalLayout_26->setObjectName(QStringLiteral("horizontalLayout_26"));
        horizontalSpacer_14 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_26->addItem(horizontalSpacer_14);

        dateTimeEditHistoryStartTime = new QDateTimeEdit(frame_29);
        dateTimeEditHistoryStartTime->setObjectName(QStringLiteral("dateTimeEditHistoryStartTime"));
        dateTimeEditHistoryStartTime->setCursor(QCursor(Qt::IBeamCursor));

        horizontalLayout_26->addWidget(dateTimeEditHistoryStartTime);


        verticalLayout_14->addLayout(horizontalLayout_26);

        horizontalLayout_27 = new QHBoxLayout();
        horizontalLayout_27->setSpacing(6);
        horizontalLayout_27->setObjectName(QStringLiteral("horizontalLayout_27"));
        labelHistoryDeviceNum_3 = new QLabel(frame_29);
        labelHistoryDeviceNum_3->setObjectName(QStringLiteral("labelHistoryDeviceNum_3"));
        labelHistoryDeviceNum_3->setMinimumSize(QSize(0, 50));
        labelHistoryDeviceNum_3->setFont(font1);

        horizontalLayout_27->addWidget(labelHistoryDeviceNum_3);

        horizontalSpacer_15 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_27->addItem(horizontalSpacer_15);


        verticalLayout_14->addLayout(horizontalLayout_27);

        horizontalLayout_28 = new QHBoxLayout();
        horizontalLayout_28->setSpacing(6);
        horizontalLayout_28->setObjectName(QStringLiteral("horizontalLayout_28"));
        horizontalSpacer_16 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_28->addItem(horizontalSpacer_16);

        dateTimeEditHistoryEndTime = new QDateTimeEdit(frame_29);
        dateTimeEditHistoryEndTime->setObjectName(QStringLiteral("dateTimeEditHistoryEndTime"));

        horizontalLayout_28->addWidget(dateTimeEditHistoryEndTime);


        verticalLayout_14->addLayout(horizontalLayout_28);


        gridLayout_30->addLayout(verticalLayout_14, 0, 0, 1, 1);

        graphicsViewHistoryInfo = new hashrateCharView(centralWidget);
        graphicsViewHistoryInfo->setObjectName(QStringLiteral("graphicsViewHistoryInfo"));
        graphicsViewHistoryInfo->setGeometry(QRect(510, 480, 636, 331));
        graphicsViewHistoryInfo->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        widget = new QWidget(centralWidget);
        widget->setObjectName(QStringLiteral("widget"));
        horizontalLayout_2 = new QHBoxLayout(widget);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        pushButtonPool = new QPushButton(widget);
        pushButtonPool->setObjectName(QStringLiteral("pushButtonPool"));
        pushButtonPool->setEnabled(true);
        pushButtonPool->setFont(font1);
        pushButtonPool->setCheckable(true);

        horizontalLayout_2->addWidget(pushButtonPool);

        pushButtonShowHideLog = new QPushButton(widget);
        pushButtonShowHideLog->setObjectName(QStringLiteral("pushButtonShowHideLog"));
        pushButtonShowHideLog->setFont(font1);
        pushButtonShowHideLog->setCheckable(true);

        horizontalLayout_2->addWidget(pushButtonShowHideLog);

        groupBoxNvidia = new QGroupBox(centralWidget);
        groupBoxNvidia->setObjectName(QStringLiteral("groupBoxNvidia"));
        groupBoxNvidia->setGeometry(QRect(9, 258, 1010, 116));
        sizePolicy1.setHeightForWidth(groupBoxNvidia->sizePolicy().hasHeightForWidth());
        groupBoxNvidia->setSizePolicy(sizePolicy1);
        groupBoxNvidia->setFont(font2);
        gridLayout_3 = new QGridLayout(groupBoxNvidia);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        lcdNumberMaxFanSpeed = new QLCDNumber(groupBoxNvidia);
        lcdNumberMaxFanSpeed->setObjectName(QStringLiteral("lcdNumberMaxFanSpeed"));

        gridLayout_3->addWidget(lcdNumberMaxFanSpeed, 0, 7, 1, 1);

        label_17 = new QLabel(groupBoxNvidia);
        label_17->setObjectName(QStringLiteral("label_17"));
        label_17->setFont(font1);

        gridLayout_3->addWidget(label_17, 1, 8, 1, 1);

        label_8 = new QLabel(groupBoxNvidia);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setFont(font1);

        gridLayout_3->addWidget(label_8, 0, 0, 1, 1);

        label_9 = new QLabel(groupBoxNvidia);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setFont(font1);

        gridLayout_3->addWidget(label_9, 0, 5, 1, 1);

        label_10 = new QLabel(groupBoxNvidia);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setFont(font1);

        gridLayout_3->addWidget(label_10, 0, 10, 1, 1);

        pushButtonOC = new QPushButton(groupBoxNvidia);
        pushButtonOC->setObjectName(QStringLiteral("pushButtonOC"));
        pushButtonOC->setEnabled(true);

        gridLayout_3->addWidget(pushButtonOC, 1, 0, 3, 1);

        lcdNumberMinGPUTemp = new QLCDNumber(groupBoxNvidia);
        lcdNumberMinGPUTemp->setObjectName(QStringLiteral("lcdNumberMinGPUTemp"));
        lcdNumberMinGPUTemp->setDigitCount(3);

        gridLayout_3->addWidget(lcdNumberMinGPUTemp, 1, 3, 1, 1);

        label_13 = new QLabel(groupBoxNvidia);
        label_13->setObjectName(QStringLiteral("label_13"));
        label_13->setFont(font1);

        gridLayout_3->addWidget(label_13, 1, 2, 1, 1);

        lcdNumberGPUCount = new QLCDNumber(groupBoxNvidia);
        lcdNumberGPUCount->setObjectName(QStringLiteral("lcdNumberGPUCount"));
        lcdNumberGPUCount->setDigitCount(2);

        gridLayout_3->addWidget(lcdNumberGPUCount, 0, 1, 1, 1);

        label_15 = new QLabel(groupBoxNvidia);
        label_15->setObjectName(QStringLiteral("label_15"));
        label_15->setFont(font1);

        gridLayout_3->addWidget(label_15, 1, 11, 1, 1);

        label_11 = new QLabel(groupBoxNvidia);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setFont(font1);

        gridLayout_3->addWidget(label_11, 1, 5, 1, 1);

        lcdNumberMaxWatt = new QLCDNumber(groupBoxNvidia);
        lcdNumberMaxWatt->setObjectName(QStringLiteral("lcdNumberMaxWatt"));

        gridLayout_3->addWidget(lcdNumberMaxWatt, 0, 12, 1, 1);

        lcdNumberMaxGPUClock = new QLCDNumber(groupBoxNvidia);
        lcdNumberMaxGPUClock->setObjectName(QStringLiteral("lcdNumberMaxGPUClock"));

        gridLayout_3->addWidget(lcdNumberMaxGPUClock, 0, 9, 1, 1);

        lcdNumberMinFanSpeed = new QLCDNumber(groupBoxNvidia);
        lcdNumberMinFanSpeed->setObjectName(QStringLiteral("lcdNumberMinFanSpeed"));

        gridLayout_3->addWidget(lcdNumberMinFanSpeed, 1, 7, 1, 1);

        label_18 = new QLabel(groupBoxNvidia);
        label_18->setObjectName(QStringLiteral("label_18"));
        label_18->setFont(font1);

        gridLayout_3->addWidget(label_18, 2, 11, 1, 1);

        label_16 = new QLabel(groupBoxNvidia);
        label_16->setObjectName(QStringLiteral("label_16"));
        label_16->setFont(font1);

        gridLayout_3->addWidget(label_16, 0, 8, 1, 1);

        lcdNumberMinWatt = new QLCDNumber(groupBoxNvidia);
        lcdNumberMinWatt->setObjectName(QStringLiteral("lcdNumberMinWatt"));

        gridLayout_3->addWidget(lcdNumberMinWatt, 1, 12, 1, 1);

        lcdNumberMinGPUClock = new QLCDNumber(groupBoxNvidia);
        lcdNumberMinGPUClock->setObjectName(QStringLiteral("lcdNumberMinGPUClock"));

        gridLayout_3->addWidget(lcdNumberMinGPUClock, 1, 9, 1, 1);

        label_6 = new QLabel(groupBoxNvidia);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setFont(font1);

        gridLayout_3->addWidget(label_6, 0, 2, 1, 1);

        lcdNumberTotalPowerDraw = new QLCDNumber(groupBoxNvidia);
        lcdNumberTotalPowerDraw->setObjectName(QStringLiteral("lcdNumberTotalPowerDraw"));
        lcdNumberTotalPowerDraw->setDigitCount(5);

        gridLayout_3->addWidget(lcdNumberTotalPowerDraw, 2, 12, 1, 1);

        label_12 = new QLabel(groupBoxNvidia);
        label_12->setObjectName(QStringLiteral("label_12"));
        label_12->setFont(font1);

        gridLayout_3->addWidget(label_12, 1, 10, 1, 1);

        lcdNumberMaxGPUTemp = new QLCDNumber(groupBoxNvidia);
        lcdNumberMaxGPUTemp->setObjectName(QStringLiteral("lcdNumberMaxGPUTemp"));
        lcdNumberMaxGPUTemp->setDigitCount(3);

        gridLayout_3->addWidget(lcdNumberMaxGPUTemp, 0, 3, 1, 1);

        label_14 = new QLabel(groupBoxNvidia);
        label_14->setObjectName(QStringLiteral("label_14"));
        label_14->setFont(font1);

        gridLayout_3->addWidget(label_14, 0, 11, 1, 1);

        groupBoxDevicesInfo = new QGroupBox(centralWidget);
        groupBoxDevicesInfo->setObjectName(QStringLiteral("groupBoxDevicesInfo"));
        groupBoxDevicesInfo->setGeometry(QRect(9, 473, 471, 191));
        groupBoxDevicesInfo->setMaximumSize(QSize(16777215, 16777127));
        groupBoxDevicesInfo->setFont(font1);
        gridLayout_9 = new QGridLayout(groupBoxDevicesInfo);
        gridLayout_9->setSpacing(6);
        gridLayout_9->setContentsMargins(11, 11, 11, 11);
        gridLayout_9->setObjectName(QStringLiteral("gridLayout_9"));
        gridLayoutDevicesInfo = new QGridLayout();
        gridLayoutDevicesInfo->setSpacing(6);
        gridLayoutDevicesInfo->setObjectName(QStringLiteral("gridLayoutDevicesInfo"));

        gridLayout_9->addLayout(gridLayoutDevicesInfo, 0, 0, 1, 1);

        MainWindow->setCentralWidget(centralWidget);
        splitter_3->raise();
        comboBoxCore->raise();
        labelWallet->raise();
        lineEditArgs->raise();
        comboBoxPool->raise();
        pushButtonHelp->raise();
        lineEditMinerPath->raise();
        labelPool->raise();
        groupBoxAMD->raise();
        pushButton->raise();
        checkBoxOnlyShare->raise();
        groupBoxPools->raise();
        splitter_2->raise();
        labelWorker->raise();
        lineEditWorker->raise();
        pushButtonSearchHistory->raise();
        pushButtonEthminerBrowser->raise();
        checkBoxAutoStart->raise();
        comboBoxHistoryDataOption->raise();
        checkBoxHistoryMiningInfoOverall->raise();
        checkBoxShowSettings->raise();
        labelCore->raise();
        checkBoxShowHistoryInfo->raise();
        checkBoxAutoShowDeviceInfo->raise();
        pushButtonCancelAutoPage->raise();
        labelWallet_2->raise();
        stackedWidgetMain->raise();
        groupBox->raise();
        groupBox_3->raise();
        groupBox_2->raise();
        groupBoxDiskInfo->raise();
        pushButton_10->raise();
        frame_17->raise();
        frame_16->raise();
        frame_18->raise();
        frame_19->raise();
        frame_23->raise();
        frame_24->raise();
        groupBox_5->raise();
        groupBox_6->raise();
        frame_24->raise();
        frame_25->raise();
        frame_26->raise();
        frame_23->raise();
        label_45->raise();
        label_46->raise();
        spinBoxChangePageSizeMin->raise();
        spinBoxChangePageSizeMax->raise();
        label_43->raise();
        comboBoxChangePageSize->raise();
        frame_29->raise();
        spinBoxChangePageSizeMax->raise();
        spinBoxChangePageSizeMin->raise();
        comboBoxChangePageSize->raise();
        spinBoxHistoryDeviceNum->raise();
        labelHistoryDeviceNum_2->raise();
        labelHistoryDeviceNum_3->raise();
        frame_30->raise();
        frame_29->raise();
        graphicsViewHistoryInfo->raise();

        retranslateUi(MainWindow);

        stackedWidgetMain->setCurrentIndex(0);
        stackedWidgeMonitorMain->setCurrentIndex(2);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Miner's Lamp", Q_NULLPTR));
        checkBoxAutoStart->setText(QApplication::translate("MainWindow", "Auto start miner", Q_NULLPTR));
        checkBoxShowHistoryInfo->setText(QApplication::translate("MainWindow", "show history info", Q_NULLPTR));
        comboBoxHistoryDataOption->clear();
        comboBoxHistoryDataOption->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "GPUs information", Q_NULLPTR)
         << QApplication::translate("MainWindow", "mining information", Q_NULLPTR)
        );
        checkBoxHistoryMiningInfoOverall->setText(QApplication::translate("MainWindow", "overall", Q_NULLPTR));
        pushButtonSearchHistory->setText(QApplication::translate("MainWindow", "Display", Q_NULLPTR));
        checkBoxShowSettings->setText(QApplication::translate("MainWindow", "show settings", Q_NULLPTR));
        checkBoxAutoShowDeviceInfo->setText(QApplication::translate("MainWindow", "Show device info", Q_NULLPTR));
        labelWallet_2->setText(QApplication::translate("MainWindow", "Page Size", Q_NULLPTR));
        pushButtonCancelAutoPage->setText(QApplication::translate("MainWindow", "Cancel Auto Page", Q_NULLPTR));
        groupBoxWatchdog->setTitle(QApplication::translate("MainWindow", "Watchdog options (restart miner in case of error)", Q_NULLPTR));
        label_3->setText(QApplication::translate("MainWindow", "Delay before monitoring for 0MH/s:", Q_NULLPTR));
        label_5->setText(QApplication::translate("MainWindow", "Delay before restart:", Q_NULLPTR));
        label_7->setText(QApplication::translate("MainWindow", "Delay before no hash:", Q_NULLPTR));
        label_4->setText(QApplication::translate("MainWindow", "Max consecutive 0MH/s:", Q_NULLPTR));
        groupBoxSettings->setTitle(QApplication::translate("MainWindow", "Settings", Q_NULLPTR));
        pushButton->setText(QApplication::translate("MainWindow", "Start mining", Q_NULLPTR));
        pushButtonHelp->setText(QApplication::translate("MainWindow", "About", Q_NULLPTR));
        pushButtonEthminerBrowser->setText(QApplication::translate("MainWindow", "...", Q_NULLPTR));
        groupBoxAMD->setTitle(QApplication::translate("MainWindow", "AMD", Q_NULLPTR));
        label_31->setText(QApplication::translate("MainWindow", "Min mem clock:", Q_NULLPTR));
        label_25->setText(QApplication::translate("MainWindow", "Min GPU temp:", Q_NULLPTR));
        label_32->setText(QApplication::translate("MainWindow", "Max power draw:", Q_NULLPTR));
        label_27->setText(QApplication::translate("MainWindow", "Max Speed fan:", Q_NULLPTR));
        label_30->setText(QApplication::translate("MainWindow", "Max mem clock:", Q_NULLPTR));
        label_28->setText(QApplication::translate("MainWindow", "Max GPU clock:", Q_NULLPTR));
        label_AMD_GPUCount->setText(QApplication::translate("MainWindow", "Devices number:", Q_NULLPTR));
        label_33->setText(QApplication::translate("MainWindow", "Min power draw:", Q_NULLPTR));
        label_29->setText(QApplication::translate("MainWindow", "Min GPU clock:", Q_NULLPTR));
        label_26->setText(QApplication::translate("MainWindow", "Min fan speed:", Q_NULLPTR));
        label_24->setText(QApplication::translate("MainWindow", "Max GPU temp:", Q_NULLPTR));
        checkBoxOnlyShare->setText(QApplication::translate("MainWindow", "Only display share info", Q_NULLPTR));
        groupBoxPools->setTitle(QApplication::translate("MainWindow", "Pools", Q_NULLPTR));
        label_22->setText(QApplication::translate("MainWindow", "Last Reported Hashrate:", Q_NULLPTR));
        label_21->setText(QApplication::translate("MainWindow", "Average Hashrate\n"
"for last 6 hour:", Q_NULLPTR));
        label_20->setText(QApplication::translate("MainWindow", "Current Calculated Hashrate:", Q_NULLPTR));
        pushButtonDisplayPoolStats->setText(QApplication::translate("MainWindow", "Refresh", Q_NULLPTR));
        label_19->setText(QApplication::translate("MainWindow", "Balance:", Q_NULLPTR));
        groupBox->setTitle(QApplication::translate("MainWindow", "Hashrate chart", Q_NULLPTR));
        label->setText(QApplication::translate("MainWindow", "Current Hashrate", Q_NULLPTR));
        label_2->setText(QApplication::translate("MainWindow", "Estimated Income", Q_NULLPTR));
        groupBox_3->setTitle(QApplication::translate("MainWindow", "GroupBox", Q_NULLPTR));
        label_23->setText(QApplication::translate("MainWindow", "Mem\n"
"Clock", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("MainWindow", "up", Q_NULLPTR));
        pushButton_3->setText(QApplication::translate("MainWindow", "dw", Q_NULLPTR));
        label_34->setText(QApplication::translate("MainWindow", "GPU\n"
"Clock", Q_NULLPTR));
        pushButton_4->setText(QApplication::translate("MainWindow", "up", Q_NULLPTR));
        pushButton_5->setText(QApplication::translate("MainWindow", "dw", Q_NULLPTR));
        label_36->setText(QApplication::translate("MainWindow", "PowerDraw", Q_NULLPTR));
        pushButton_8->setText(QApplication::translate("MainWindow", "up", Q_NULLPTR));
        pushButton_9->setText(QApplication::translate("MainWindow", "dw", Q_NULLPTR));
        groupBox_2->setTitle(QApplication::translate("MainWindow", "Temperature chart", Q_NULLPTR));
        groupBoxDiskInfo->setTitle(QApplication::translate("MainWindow", "Disk Info", Q_NULLPTR));
        groupBox_4->setTitle(QString());
        labelWallet->setText(QApplication::translate("MainWindow", "Wallet", Q_NULLPTR));
        labelCoin->setText(QApplication::translate("MainWindow", "Coin", Q_NULLPTR));
        comboBoxCoin->clear();
        comboBoxCoin->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "ETH", Q_NULLPTR)
        );
        labelPool->setText(QApplication::translate("MainWindow", "Pool", Q_NULLPTR));
        comboBoxPool->clear();
        comboBoxPool->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "ethermine", Q_NULLPTR)
         << QApplication::translate("MainWindow", "sparkpool", Q_NULLPTR)
         << QApplication::translate("MainWindow", "f2pool", Q_NULLPTR)
         << QApplication::translate("MainWindow", "beepool", Q_NULLPTR)
         << QApplication::translate("MainWindow", "nanopool", Q_NULLPTR)
         << QApplication::translate("MainWindow", "herominers", Q_NULLPTR)
         << QApplication::translate("MainWindow", "nicehash", Q_NULLPTR)
        );
        labelWorker->setText(QApplication::translate("MainWindow", "Worker", Q_NULLPTR));
        labelCore->setText(QApplication::translate("MainWindow", "Core", Q_NULLPTR));
        comboBoxCore->clear();
        comboBoxCore->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "NBMiner 37.1", Q_NULLPTR)
        );
        pushButton_10->setText(QApplication::translate("MainWindow", "PushButton", Q_NULLPTR));
        groupBox_5->setTitle(QString());
        radioButtonNaopool->setText(QApplication::translate("MainWindow", "Nanopool", Q_NULLPTR));
        radioButtonEthermine->setText(QApplication::translate("MainWindow", "Ethermine", Q_NULLPTR));
        radioButtonDwarfPool->setText(QApplication::translate("MainWindow", "Dwarfpool", Q_NULLPTR));
        lineEditAccount->setText(QApplication::translate("MainWindow", "0xa07A8c9975145BB5371e8b3C31ACb62ad9d0698E", Q_NULLPTR));
        label_37->setText(QApplication::translate("MainWindow", "Balance", Q_NULLPTR));
        label_38->setText(QApplication::translate("MainWindow", "10", Q_NULLPTR));
        label_39->setText(QApplication::translate("MainWindow", "Pool", Q_NULLPTR));
        groupBox_6->setTitle(QString());
        label_40->setText(QApplication::translate("MainWindow", "Log", Q_NULLPTR));
        groupBox_7->setTitle(QString());
        label_41->setText(QApplication::translate("MainWindow", "System info", Q_NULLPTR));
        label_43->setText(QApplication::translate("MainWindow", "disk", Q_NULLPTR));
        label_46->setText(QApplication::translate("MainWindow", "Max Size", Q_NULLPTR));
        label_45->setText(QApplication::translate("MainWindow", "Min Size", Q_NULLPTR));
        pushButtonChangePageSize->setText(QApplication::translate("MainWindow", "apply", Q_NULLPTR));
        labelHistoryDeviceNum->setText(QApplication::translate("MainWindow", "Device#", Q_NULLPTR));
        labelHistoryDeviceNum_2->setText(QApplication::translate("MainWindow", "from", Q_NULLPTR));
        dateTimeEditHistoryStartTime->setDisplayFormat(QApplication::translate("MainWindow", "yyyy/MM/dd", Q_NULLPTR));
        labelHistoryDeviceNum_3->setText(QApplication::translate("MainWindow", "to", Q_NULLPTR));
        dateTimeEditHistoryEndTime->setDisplayFormat(QApplication::translate("MainWindow", "yyyy/MM/dd", Q_NULLPTR));
        pushButtonPool->setText(QApplication::translate("MainWindow", "Pool", Q_NULLPTR));
        pushButtonShowHideLog->setText(QApplication::translate("MainWindow", "Hide log", Q_NULLPTR));
        groupBoxNvidia->setTitle(QApplication::translate("MainWindow", "nVidia", Q_NULLPTR));
        label_17->setText(QApplication::translate("MainWindow", "Min GPU clock:", Q_NULLPTR));
        label_8->setText(QApplication::translate("MainWindow", "Devices number:", Q_NULLPTR));
        label_9->setText(QApplication::translate("MainWindow", "Max Speed fan:", Q_NULLPTR));
        label_10->setText(QApplication::translate("MainWindow", "Max mem clock:", Q_NULLPTR));
        pushButtonOC->setText(QApplication::translate("MainWindow", "OverClocking", Q_NULLPTR));
        label_13->setText(QApplication::translate("MainWindow", "Min GPU temp:", Q_NULLPTR));
        label_15->setText(QApplication::translate("MainWindow", "Min power draw:", Q_NULLPTR));
        label_11->setText(QApplication::translate("MainWindow", "Min fan speed:", Q_NULLPTR));
        label_18->setText(QApplication::translate("MainWindow", "Total power draw:", Q_NULLPTR));
        label_16->setText(QApplication::translate("MainWindow", "Max GPU clock:", Q_NULLPTR));
        label_6->setText(QApplication::translate("MainWindow", "Max GPU temp:", Q_NULLPTR));
        label_12->setText(QApplication::translate("MainWindow", "Min mem clock:", Q_NULLPTR));
        label_14->setText(QApplication::translate("MainWindow", "Max power draw:", Q_NULLPTR));
        groupBoxDevicesInfo->setTitle(QApplication::translate("MainWindow", "Devices Info", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H

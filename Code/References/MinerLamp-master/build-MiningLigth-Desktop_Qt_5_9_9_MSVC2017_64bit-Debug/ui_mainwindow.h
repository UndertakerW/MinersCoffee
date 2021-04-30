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
    QLabel *labelCore;
    QComboBox *comboBoxCore;
    QLabel *labelPool;
    QComboBox *comboBoxPool;
    QLabel *labelWallet;
    QLineEdit *lineEditWallet;
    QLabel *labelWorker;
    QLineEdit *lineEditWorker;
    QCheckBox *checkBoxAutoStart;
    QCheckBox *checkBoxShowHistoryInfo;
    QComboBox *comboBoxHistoryDataOption;
    QCheckBox *checkBoxHistoryMiningInfoOverall;
    QPushButton *pushButtonSearchHistory;
    QCheckBox *checkBoxShowSettings;
    QCheckBox *checkBoxAutoShowDeviceInfo;
    QLabel *labelWallet_2;
    QComboBox *comboBoxChangePageSize;
    QSpinBox *spinBoxChangePageSizeMin;
    QSpinBox *spinBoxChangePageSizeMax;
    QPushButton *pushButtonChangePageSize;
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
    QTextEdit *textEditSettings;
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
    QTextEdit *textEdit;
    QGroupBox *groupBoxPools;
    QGridLayout *gridLayout_4;
    QLCDNumber *lcdNumberBalance;
    QRadioButton *radioButtonDwarfPool;
    QLabel *label_19;
    QLabel *label_22;
    QLabel *label_20;
    QLCDNumber *lcdNumberAvrgHr6H;
    QRadioButton *radioButtonEthermine;
    QLabel *label_21;
    QLineEdit *lineEditAccount;
    QPushButton *pushButtonDisplayPoolStats;
    QLCDNumber *lcdNumber_4;
    QRadioButton *radioButtonNaopool;
    QLCDNumber *lcdNumberCalculatedHR;
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
    QWidget *page_3;
    QWidget *page_2;
    QWidget *widget;
    QHBoxLayout *horizontalLayout_4;
    QLabel *labelCoin;
    QComboBox *comboBoxCoin;
    QWidget *widget1;
    QHBoxLayout *horizontalLayout;
    QDateTimeEdit *dateTimeEditHistoryStartTime;
    QDateTimeEdit *dateTimeEditHistoryEndTime;
    QWidget *widget2;
    QHBoxLayout *horizontalLayout_3;
    QLabel *labelHistoryDeviceNum;
    QSpinBox *spinBoxHistoryDeviceNum;
    QWidget *widget3;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *pushButtonPool;
    QPushButton *pushButtonShowHideLog;
    QGroupBox *groupBoxDevicesInfo;
    QGridLayout *gridLayout_9;
    QGridLayout *gridLayoutDevicesInfo;
    QGroupBox *groupBoxHistoryInfo;
    QGridLayout *gridLayout_8;
    hashrateCharView *graphicsViewHistoryInfo;
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
        labelCore = new QLabel(centralWidget);
        labelCore->setObjectName(QStringLiteral("labelCore"));
        labelCore->setGeometry(QRect(194, 15, 46, 31));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(labelCore->sizePolicy().hasHeightForWidth());
        labelCore->setSizePolicy(sizePolicy);
        labelCore->setMinimumSize(QSize(0, 31));
        labelCore->setMaximumSize(QSize(50, 16777215));
        QFont font1;
        font1.setFamily(QStringLiteral("Arial"));
        font1.setPointSize(12);
        font1.setBold(true);
        font1.setWeight(75);
        labelCore->setFont(font1);
        comboBoxCore = new QComboBox(centralWidget);
        comboBoxCore->setObjectName(QStringLiteral("comboBoxCore"));
        comboBoxCore->setGeometry(QRect(250, 16, 149, 31));
        comboBoxCore->setMinimumSize(QSize(0, 31));
        QFont font2;
        font2.setPointSize(12);
        comboBoxCore->setFont(font2);
        labelPool = new QLabel(centralWidget);
        labelPool->setObjectName(QStringLiteral("labelPool"));
        labelPool->setGeometry(QRect(405, 15, 44, 31));
        sizePolicy.setHeightForWidth(labelPool->sizePolicy().hasHeightForWidth());
        labelPool->setSizePolicy(sizePolicy);
        labelPool->setMinimumSize(QSize(0, 31));
        labelPool->setMaximumSize(QSize(50, 16777215));
        labelPool->setFont(font1);
        comboBoxPool = new QComboBox(centralWidget);
        comboBoxPool->setObjectName(QStringLiteral("comboBoxPool"));
        comboBoxPool->setGeometry(QRect(471, 16, 130, 31));
        comboBoxPool->setMinimumSize(QSize(0, 31));
        comboBoxPool->setFont(font2);
        labelWallet = new QLabel(centralWidget);
        labelWallet->setObjectName(QStringLiteral("labelWallet"));
        labelWallet->setGeometry(QRect(643, 15, 59, 23));
        sizePolicy.setHeightForWidth(labelWallet->sizePolicy().hasHeightForWidth());
        labelWallet->setSizePolicy(sizePolicy);
        labelWallet->setMaximumSize(QSize(60, 16777215));
        labelWallet->setFont(font1);
        lineEditWallet = new QLineEdit(centralWidget);
        lineEditWallet->setObjectName(QStringLiteral("lineEditWallet"));
        lineEditWallet->setGeometry(QRect(785, 16, 205, 31));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(lineEditWallet->sizePolicy().hasHeightForWidth());
        lineEditWallet->setSizePolicy(sizePolicy1);
        lineEditWallet->setMinimumSize(QSize(0, 31));
        lineEditWallet->setFont(font2);
        labelWorker = new QLabel(centralWidget);
        labelWorker->setObjectName(QStringLiteral("labelWorker"));
        labelWorker->setGeometry(QRect(1017, 15, 69, 31));
        sizePolicy.setHeightForWidth(labelWorker->sizePolicy().hasHeightForWidth());
        labelWorker->setSizePolicy(sizePolicy);
        labelWorker->setMinimumSize(QSize(0, 31));
        labelWorker->setMaximumSize(QSize(100, 16777215));
        labelWorker->setFont(font1);
        lineEditWorker = new QLineEdit(centralWidget);
        lineEditWorker->setObjectName(QStringLiteral("lineEditWorker"));
        lineEditWorker->setGeometry(QRect(1129, 16, 205, 31));
        sizePolicy1.setHeightForWidth(lineEditWorker->sizePolicy().hasHeightForWidth());
        lineEditWorker->setSizePolicy(sizePolicy1);
        lineEditWorker->setMinimumSize(QSize(0, 31));
        lineEditWorker->setFont(font2);
        checkBoxAutoStart = new QCheckBox(centralWidget);
        checkBoxAutoStart->setObjectName(QStringLiteral("checkBoxAutoStart"));
        checkBoxAutoStart->setGeometry(QRect(9, 57, 133, 21));
        QFont font3;
        font3.setFamily(QStringLiteral("Arial"));
        checkBoxAutoStart->setFont(font3);
        checkBoxShowHistoryInfo = new QCheckBox(centralWidget);
        checkBoxShowHistoryInfo->setObjectName(QStringLiteral("checkBoxShowHistoryInfo"));
        checkBoxShowHistoryInfo->setGeometry(QRect(250, 57, 139, 21));
        checkBoxShowHistoryInfo->setFont(font3);
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
        checkBoxShowSettings->setFont(font3);
        checkBoxAutoShowDeviceInfo = new QCheckBox(centralWidget);
        checkBoxAutoShowDeviceInfo->setObjectName(QStringLiteral("checkBoxAutoShowDeviceInfo"));
        checkBoxAutoShowDeviceInfo->setGeometry(QRect(250, 91, 141, 21));
        checkBoxAutoShowDeviceInfo->setFont(font3);
        labelWallet_2 = new QLabel(centralWidget);
        labelWallet_2->setObjectName(QStringLiteral("labelWallet_2"));
        labelWallet_2->setGeometry(QRect(405, 88, 60, 16));
        sizePolicy.setHeightForWidth(labelWallet_2->sizePolicy().hasHeightForWidth());
        labelWallet_2->setSizePolicy(sizePolicy);
        labelWallet_2->setMaximumSize(QSize(60, 16777215));
        QFont font4;
        font4.setFamily(QStringLiteral("Arial"));
        font4.setPointSize(8);
        font4.setBold(false);
        font4.setWeight(50);
        labelWallet_2->setFont(font4);
        comboBoxChangePageSize = new QComboBox(centralWidget);
        comboBoxChangePageSize->setObjectName(QStringLiteral("comboBoxChangePageSize"));
        comboBoxChangePageSize->setGeometry(QRect(471, 91, 87, 21));
        spinBoxChangePageSizeMin = new QSpinBox(centralWidget);
        spinBoxChangePageSizeMin->setObjectName(QStringLiteral("spinBoxChangePageSizeMin"));
        spinBoxChangePageSizeMin->setGeometry(QRect(643, 92, 43, 19));
        spinBoxChangePageSizeMax = new QSpinBox(centralWidget);
        spinBoxChangePageSizeMax->setObjectName(QStringLiteral("spinBoxChangePageSizeMax"));
        spinBoxChangePageSizeMax->setGeometry(QRect(714, 92, 43, 19));
        pushButtonChangePageSize = new QPushButton(centralWidget);
        pushButtonChangePageSize->setObjectName(QStringLiteral("pushButtonChangePageSize"));
        pushButtonChangePageSize->setGeometry(QRect(895, 88, 93, 28));
        pushButtonChangePageSize->setFont(font3);
        pushButtonCancelAutoPage = new QPushButton(centralWidget);
        pushButtonCancelAutoPage->setObjectName(QStringLiteral("pushButtonCancelAutoPage"));
        pushButtonCancelAutoPage->setEnabled(true);
        pushButtonCancelAutoPage->setGeometry(QRect(1129, 88, 129, 28));
        lineEditArgs = new QLineEdit(centralWidget);
        lineEditArgs->setObjectName(QStringLiteral("lineEditArgs"));
        lineEditArgs->setGeometry(QRect(1011, 122, 0, 0));
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
        groupBoxWatchdog->setFont(font3);
        groupBoxWatchdog->setCheckable(true);
        groupBoxWatchdog->setChecked(false);
        gridLayout = new QGridLayout(groupBoxWatchdog);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        spinBoxMax0MHs = new QSpinBox(groupBoxWatchdog);
        spinBoxMax0MHs->setObjectName(QStringLiteral("spinBoxMax0MHs"));
        spinBoxMax0MHs->setFont(font3);
        spinBoxMax0MHs->setMinimum(1);

        gridLayout->addWidget(spinBoxMax0MHs, 0, 1, 1, 1);

        label_3 = new QLabel(groupBoxWatchdog);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setFont(font3);

        gridLayout->addWidget(label_3, 1, 0, 1, 1);

        spinBoxDelay = new QSpinBox(groupBoxWatchdog);
        spinBoxDelay->setObjectName(QStringLiteral("spinBoxDelay"));
        spinBoxDelay->setFont(font3);
        spinBoxDelay->setMinimum(1);

        gridLayout->addWidget(spinBoxDelay, 0, 3, 1, 1);

        spinBoxDelay0MHs = new QSpinBox(groupBoxWatchdog);
        spinBoxDelay0MHs->setObjectName(QStringLiteral("spinBoxDelay0MHs"));
        spinBoxDelay0MHs->setFont(font3);
        spinBoxDelay0MHs->setMinimum(1);
        spinBoxDelay0MHs->setMaximum(600);
        spinBoxDelay0MHs->setValue(20);

        gridLayout->addWidget(spinBoxDelay0MHs, 1, 1, 1, 1);

        label_5 = new QLabel(groupBoxWatchdog);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setFont(font3);

        gridLayout->addWidget(label_5, 0, 2, 1, 1);

        label_7 = new QLabel(groupBoxWatchdog);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setFont(font3);

        gridLayout->addWidget(label_7, 1, 2, 1, 1);

        spinBoxDelayNoHash = new QSpinBox(groupBoxWatchdog);
        spinBoxDelayNoHash->setObjectName(QStringLiteral("spinBoxDelayNoHash"));
        spinBoxDelayNoHash->setFont(font3);
        spinBoxDelayNoHash->setMinimum(30);
        spinBoxDelayNoHash->setMaximum(600);
        spinBoxDelayNoHash->setValue(60);

        gridLayout->addWidget(spinBoxDelayNoHash, 1, 3, 1, 1);

        label_4 = new QLabel(groupBoxWatchdog);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setFont(font3);

        gridLayout->addWidget(label_4, 0, 0, 1, 1);

        splitter_3->addWidget(groupBoxWatchdog);
        groupBoxSettings = new QGroupBox(splitter_3);
        groupBoxSettings->setObjectName(QStringLiteral("groupBoxSettings"));
        groupBoxSettings->setFont(font3);
        gridLayout_11 = new QGridLayout(groupBoxSettings);
        gridLayout_11->setSpacing(6);
        gridLayout_11->setContentsMargins(11, 11, 11, 11);
        gridLayout_11->setObjectName(QStringLiteral("gridLayout_11"));
        textEditSettings = new QTextEdit(groupBoxSettings);
        textEditSettings->setObjectName(QStringLiteral("textEditSettings"));
        textEditSettings->setFont(font3);

        gridLayout_11->addWidget(textEditSettings, 0, 0, 1, 1);

        splitter_3->addWidget(groupBoxSettings);
        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(1017, 148, 93, 28));
        pushButton->setFont(font3);
        pushButtonHelp = new QPushButton(centralWidget);
        pushButtonHelp->setObjectName(QStringLiteral("pushButtonHelp"));
        pushButtonHelp->setGeometry(QRect(1017, 213, 93, 28));
        pushButtonHelp->setFont(font3);
        pushButtonEthminerBrowser = new QPushButton(centralWidget);
        pushButtonEthminerBrowser->setObjectName(QStringLiteral("pushButtonEthminerBrowser"));
        pushButtonEthminerBrowser->setGeometry(QRect(1129, 213, 93, 28));
        QSizePolicy sizePolicy2(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(pushButtonEthminerBrowser->sizePolicy().hasHeightForWidth());
        pushButtonEthminerBrowser->setSizePolicy(sizePolicy2);
        pushButtonEthminerBrowser->setFont(font3);
        groupBoxAMD = new QGroupBox(centralWidget);
        groupBoxAMD->setObjectName(QStringLiteral("groupBoxAMD"));
        groupBoxAMD->setGeometry(QRect(9, 380, 1100, 87));
        sizePolicy1.setHeightForWidth(groupBoxAMD->sizePolicy().hasHeightForWidth());
        groupBoxAMD->setSizePolicy(sizePolicy1);
        groupBoxAMD->setFont(font4);
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
        label_31->setFont(font3);

        gridLayout_2->addWidget(label_31, 2, 8, 1, 1);

        lcdNumber_AMD_MinClock = new QLCDNumber(groupBoxAMD);
        lcdNumber_AMD_MinClock->setObjectName(QStringLiteral("lcdNumber_AMD_MinClock"));

        gridLayout_2->addWidget(lcdNumber_AMD_MinClock, 2, 7, 1, 1);

        label_25 = new QLabel(groupBoxAMD);
        label_25->setObjectName(QStringLiteral("label_25"));
        label_25->setFont(font3);

        gridLayout_2->addWidget(label_25, 2, 2, 1, 1);

        lcdNumber_AMD_MaxFan = new QLCDNumber(groupBoxAMD);
        lcdNumber_AMD_MaxFan->setObjectName(QStringLiteral("lcdNumber_AMD_MaxFan"));

        gridLayout_2->addWidget(lcdNumber_AMD_MaxFan, 1, 5, 1, 1);

        lcdNumber_AMD_MinPoxer = new QLCDNumber(groupBoxAMD);
        lcdNumber_AMD_MinPoxer->setObjectName(QStringLiteral("lcdNumber_AMD_MinPoxer"));

        gridLayout_2->addWidget(lcdNumber_AMD_MinPoxer, 2, 11, 1, 1);

        label_32 = new QLabel(groupBoxAMD);
        label_32->setObjectName(QStringLiteral("label_32"));
        label_32->setFont(font3);

        gridLayout_2->addWidget(label_32, 1, 10, 1, 1);

        label_27 = new QLabel(groupBoxAMD);
        label_27->setObjectName(QStringLiteral("label_27"));
        label_27->setFont(font3);

        gridLayout_2->addWidget(label_27, 1, 4, 1, 1);

        label_30 = new QLabel(groupBoxAMD);
        label_30->setObjectName(QStringLiteral("label_30"));
        label_30->setFont(font3);

        gridLayout_2->addWidget(label_30, 1, 8, 1, 1);

        label_28 = new QLabel(groupBoxAMD);
        label_28->setObjectName(QStringLiteral("label_28"));
        label_28->setFont(font3);

        gridLayout_2->addWidget(label_28, 1, 6, 1, 1);

        label_AMD_GPUCount = new QLabel(groupBoxAMD);
        label_AMD_GPUCount->setObjectName(QStringLiteral("label_AMD_GPUCount"));
        label_AMD_GPUCount->setFont(font3);

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
        label_33->setFont(font3);

        gridLayout_2->addWidget(label_33, 2, 10, 1, 1);

        lcdNumber_AMD_MaxTemp = new QLCDNumber(groupBoxAMD);
        lcdNumber_AMD_MaxTemp->setObjectName(QStringLiteral("lcdNumber_AMD_MaxTemp"));

        gridLayout_2->addWidget(lcdNumber_AMD_MaxTemp, 1, 3, 1, 1);

        label_29 = new QLabel(groupBoxAMD);
        label_29->setObjectName(QStringLiteral("label_29"));
        label_29->setFont(font3);

        gridLayout_2->addWidget(label_29, 2, 6, 1, 1);

        lcdNumber_AMD_MaxPower = new QLCDNumber(groupBoxAMD);
        lcdNumber_AMD_MaxPower->setObjectName(QStringLiteral("lcdNumber_AMD_MaxPower"));

        gridLayout_2->addWidget(lcdNumber_AMD_MaxPower, 1, 11, 1, 1);

        label_26 = new QLabel(groupBoxAMD);
        label_26->setObjectName(QStringLiteral("label_26"));
        label_26->setFont(font3);

        gridLayout_2->addWidget(label_26, 2, 4, 1, 1);

        lcdNumber_AMD_MaxClock = new QLCDNumber(groupBoxAMD);
        lcdNumber_AMD_MaxClock->setObjectName(QStringLiteral("lcdNumber_AMD_MaxClock"));

        gridLayout_2->addWidget(lcdNumber_AMD_MaxClock, 1, 7, 1, 1);

        label_24 = new QLabel(groupBoxAMD);
        label_24->setObjectName(QStringLiteral("label_24"));
        label_24->setFont(font3);

        gridLayout_2->addWidget(label_24, 1, 2, 1, 1);

        checkBoxOnlyShare = new QCheckBox(centralWidget);
        checkBoxOnlyShare->setObjectName(QStringLiteral("checkBoxOnlyShare"));
        checkBoxOnlyShare->setGeometry(QRect(9, 721, 179, 21));
        checkBoxOnlyShare->setFont(font3);
        textEdit = new QTextEdit(centralWidget);
        textEdit->setObjectName(QStringLiteral("textEdit"));
        textEdit->setGeometry(QRect(9, 753, 1325, 87));
        textEdit->setFont(font3);
        textEdit->setReadOnly(true);
        groupBoxPools = new QGroupBox(centralWidget);
        groupBoxPools->setObjectName(QStringLiteral("groupBoxPools"));
        groupBoxPools->setEnabled(true);
        groupBoxPools->setGeometry(QRect(9, 846, 853, 162));
        QSizePolicy sizePolicy3(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(groupBoxPools->sizePolicy().hasHeightForWidth());
        groupBoxPools->setSizePolicy(sizePolicy3);
        groupBoxPools->setFont(font3);
        gridLayout_4 = new QGridLayout(groupBoxPools);
        gridLayout_4->setSpacing(6);
        gridLayout_4->setContentsMargins(11, 11, 11, 11);
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        lcdNumberBalance = new QLCDNumber(groupBoxPools);
        lcdNumberBalance->setObjectName(QStringLiteral("lcdNumberBalance"));
        lcdNumberBalance->setSmallDecimalPoint(false);
        lcdNumberBalance->setDigitCount(12);

        gridLayout_4->addWidget(lcdNumberBalance, 3, 2, 1, 1);

        radioButtonDwarfPool = new QRadioButton(groupBoxPools);
        radioButtonDwarfPool->setObjectName(QStringLiteral("radioButtonDwarfPool"));
        radioButtonDwarfPool->setEnabled(false);
        radioButtonDwarfPool->setFont(font3);

        gridLayout_4->addWidget(radioButtonDwarfPool, 0, 4, 1, 1);

        label_19 = new QLabel(groupBoxPools);
        label_19->setObjectName(QStringLiteral("label_19"));
        label_19->setFont(font3);

        gridLayout_4->addWidget(label_19, 3, 0, 1, 1);

        label_22 = new QLabel(groupBoxPools);
        label_22->setObjectName(QStringLiteral("label_22"));
        label_22->setFont(font3);

        gridLayout_4->addWidget(label_22, 4, 4, 1, 1);

        label_20 = new QLabel(groupBoxPools);
        label_20->setObjectName(QStringLiteral("label_20"));
        label_20->setFont(font3);

        gridLayout_4->addWidget(label_20, 4, 0, 1, 1);

        lcdNumberAvrgHr6H = new QLCDNumber(groupBoxPools);
        lcdNumberAvrgHr6H->setObjectName(QStringLiteral("lcdNumberAvrgHr6H"));
        lcdNumberAvrgHr6H->setDigitCount(6);

        gridLayout_4->addWidget(lcdNumberAvrgHr6H, 4, 3, 1, 1);

        radioButtonEthermine = new QRadioButton(groupBoxPools);
        radioButtonEthermine->setObjectName(QStringLiteral("radioButtonEthermine"));
        radioButtonEthermine->setEnabled(false);
        radioButtonEthermine->setFont(font3);

        gridLayout_4->addWidget(radioButtonEthermine, 0, 2, 1, 1);

        label_21 = new QLabel(groupBoxPools);
        label_21->setObjectName(QStringLiteral("label_21"));
        label_21->setFont(font3);

        gridLayout_4->addWidget(label_21, 4, 2, 1, 1);

        lineEditAccount = new QLineEdit(groupBoxPools);
        lineEditAccount->setObjectName(QStringLiteral("lineEditAccount"));
        lineEditAccount->setFont(font3);

        gridLayout_4->addWidget(lineEditAccount, 2, 0, 1, 5);

        pushButtonDisplayPoolStats = new QPushButton(groupBoxPools);
        pushButtonDisplayPoolStats->setObjectName(QStringLiteral("pushButtonDisplayPoolStats"));
        pushButtonDisplayPoolStats->setFont(font3);

        gridLayout_4->addWidget(pushButtonDisplayPoolStats, 2, 6, 1, 1);

        lcdNumber_4 = new QLCDNumber(groupBoxPools);
        lcdNumber_4->setObjectName(QStringLiteral("lcdNumber_4"));
        lcdNumber_4->setDigitCount(6);

        gridLayout_4->addWidget(lcdNumber_4, 4, 5, 1, 1);

        radioButtonNaopool = new QRadioButton(groupBoxPools);
        radioButtonNaopool->setObjectName(QStringLiteral("radioButtonNaopool"));
        radioButtonNaopool->setFont(font3);
        radioButtonNaopool->setChecked(true);

        gridLayout_4->addWidget(radioButtonNaopool, 0, 0, 1, 1);

        lcdNumberCalculatedHR = new QLCDNumber(groupBoxPools);
        lcdNumberCalculatedHR->setObjectName(QStringLiteral("lcdNumberCalculatedHR"));
        lcdNumberCalculatedHR->setDigitCount(6);

        gridLayout_4->addWidget(lcdNumberCalculatedHR, 4, 1, 1, 1);

        stackedWidgetMain = new QStackedWidget(centralWidget);
        stackedWidgetMain->setObjectName(QStringLiteral("stackedWidgetMain"));
        stackedWidgetMain->setGeometry(QRect(1420, 50, 981, 771));
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

        horizontalSpacer = new QSpacerItem(816, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

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
        groupBox->setFont(font3);
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
        lcdNumberHashRate->setFont(font3);
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
        lcdNumberHashRate_2->setFont(font3);
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
        groupBox_2->setFont(font3);
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
        page_3 = new QWidget();
        page_3->setObjectName(QStringLiteral("page_3"));
        stackedWidgeMonitorMain->addWidget(page_3);

        verticalLayout->addWidget(stackedWidgeMonitorMain);

        stackedWidgetMain->addWidget(page_monitor);
        page_2 = new QWidget();
        page_2->setObjectName(QStringLiteral("page_2"));
        stackedWidgetMain->addWidget(page_2);
        widget = new QWidget(centralWidget);
        widget->setObjectName(QStringLiteral("widget"));
        horizontalLayout_4 = new QHBoxLayout(widget);
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        labelCoin = new QLabel(widget);
        labelCoin->setObjectName(QStringLiteral("labelCoin"));
        sizePolicy.setHeightForWidth(labelCoin->sizePolicy().hasHeightForWidth());
        labelCoin->setSizePolicy(sizePolicy);
        labelCoin->setMinimumSize(QSize(0, 31));
        labelCoin->setMaximumSize(QSize(50, 16777215));
        labelCoin->setFont(font1);

        horizontalLayout_4->addWidget(labelCoin);

        comboBoxCoin = new QComboBox(widget);
        comboBoxCoin->setObjectName(QStringLiteral("comboBoxCoin"));
        sizePolicy1.setHeightForWidth(comboBoxCoin->sizePolicy().hasHeightForWidth());
        comboBoxCoin->setSizePolicy(sizePolicy1);
        comboBoxCoin->setMinimumSize(QSize(0, 31));
        comboBoxCoin->setMaximumSize(QSize(90, 16777215));
        comboBoxCoin->setFont(font2);

        horizontalLayout_4->addWidget(comboBoxCoin);

        widget1 = new QWidget(centralWidget);
        widget1->setObjectName(QStringLiteral("widget1"));
        horizontalLayout = new QHBoxLayout(widget1);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        dateTimeEditHistoryStartTime = new QDateTimeEdit(widget1);
        dateTimeEditHistoryStartTime->setObjectName(QStringLiteral("dateTimeEditHistoryStartTime"));
        dateTimeEditHistoryStartTime->setCursor(QCursor(Qt::IBeamCursor));

        horizontalLayout->addWidget(dateTimeEditHistoryStartTime);

        dateTimeEditHistoryEndTime = new QDateTimeEdit(widget1);
        dateTimeEditHistoryEndTime->setObjectName(QStringLiteral("dateTimeEditHistoryEndTime"));

        horizontalLayout->addWidget(dateTimeEditHistoryEndTime);

        widget2 = new QWidget(centralWidget);
        widget2->setObjectName(QStringLiteral("widget2"));
        horizontalLayout_3 = new QHBoxLayout(widget2);
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        labelHistoryDeviceNum = new QLabel(widget2);
        labelHistoryDeviceNum->setObjectName(QStringLiteral("labelHistoryDeviceNum"));
        labelHistoryDeviceNum->setFont(font3);

        horizontalLayout_3->addWidget(labelHistoryDeviceNum);

        spinBoxHistoryDeviceNum = new QSpinBox(widget2);
        spinBoxHistoryDeviceNum->setObjectName(QStringLiteral("spinBoxHistoryDeviceNum"));

        horizontalLayout_3->addWidget(spinBoxHistoryDeviceNum);

        widget3 = new QWidget(centralWidget);
        widget3->setObjectName(QStringLiteral("widget3"));
        horizontalLayout_2 = new QHBoxLayout(widget3);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        pushButtonPool = new QPushButton(widget3);
        pushButtonPool->setObjectName(QStringLiteral("pushButtonPool"));
        pushButtonPool->setEnabled(true);
        pushButtonPool->setFont(font3);
        pushButtonPool->setCheckable(true);

        horizontalLayout_2->addWidget(pushButtonPool);

        pushButtonShowHideLog = new QPushButton(widget3);
        pushButtonShowHideLog->setObjectName(QStringLiteral("pushButtonShowHideLog"));
        pushButtonShowHideLog->setFont(font3);
        pushButtonShowHideLog->setCheckable(true);

        horizontalLayout_2->addWidget(pushButtonShowHideLog);

        groupBoxDevicesInfo = new QGroupBox(centralWidget);
        groupBoxDevicesInfo->setObjectName(QStringLiteral("groupBoxDevicesInfo"));
        groupBoxDevicesInfo->setGeometry(QRect(9, 473, 471, 191));
        groupBoxDevicesInfo->setMaximumSize(QSize(16777215, 16777127));
        groupBoxDevicesInfo->setFont(font3);
        gridLayout_9 = new QGridLayout(groupBoxDevicesInfo);
        gridLayout_9->setSpacing(6);
        gridLayout_9->setContentsMargins(11, 11, 11, 11);
        gridLayout_9->setObjectName(QStringLiteral("gridLayout_9"));
        gridLayoutDevicesInfo = new QGridLayout();
        gridLayoutDevicesInfo->setSpacing(6);
        gridLayoutDevicesInfo->setObjectName(QStringLiteral("gridLayoutDevicesInfo"));

        gridLayout_9->addLayout(gridLayoutDevicesInfo, 0, 0, 1, 1);

        groupBoxHistoryInfo = new QGroupBox(centralWidget);
        groupBoxHistoryInfo->setObjectName(QStringLiteral("groupBoxHistoryInfo"));
        groupBoxHistoryInfo->setGeometry(QRect(676, 651, 656, 124));
        groupBoxHistoryInfo->setFont(font3);
        gridLayout_8 = new QGridLayout(groupBoxHistoryInfo);
        gridLayout_8->setSpacing(6);
        gridLayout_8->setContentsMargins(11, 11, 11, 11);
        gridLayout_8->setObjectName(QStringLiteral("gridLayout_8"));
        graphicsViewHistoryInfo = new hashrateCharView(groupBoxHistoryInfo);
        graphicsViewHistoryInfo->setObjectName(QStringLiteral("graphicsViewHistoryInfo"));
        graphicsViewHistoryInfo->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);

        gridLayout_8->addWidget(graphicsViewHistoryInfo, 0, 0, 1, 1);

        groupBoxNvidia = new QGroupBox(centralWidget);
        groupBoxNvidia->setObjectName(QStringLiteral("groupBoxNvidia"));
        groupBoxNvidia->setGeometry(QRect(9, 258, 1010, 116));
        sizePolicy1.setHeightForWidth(groupBoxNvidia->sizePolicy().hasHeightForWidth());
        groupBoxNvidia->setSizePolicy(sizePolicy1);
        groupBoxNvidia->setFont(font4);
        gridLayout_3 = new QGridLayout(groupBoxNvidia);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        lcdNumberMaxFanSpeed = new QLCDNumber(groupBoxNvidia);
        lcdNumberMaxFanSpeed->setObjectName(QStringLiteral("lcdNumberMaxFanSpeed"));

        gridLayout_3->addWidget(lcdNumberMaxFanSpeed, 0, 7, 1, 1);

        label_17 = new QLabel(groupBoxNvidia);
        label_17->setObjectName(QStringLiteral("label_17"));
        label_17->setFont(font3);

        gridLayout_3->addWidget(label_17, 1, 8, 1, 1);

        label_8 = new QLabel(groupBoxNvidia);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setFont(font3);

        gridLayout_3->addWidget(label_8, 0, 0, 1, 1);

        label_9 = new QLabel(groupBoxNvidia);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setFont(font3);

        gridLayout_3->addWidget(label_9, 0, 5, 1, 1);

        label_10 = new QLabel(groupBoxNvidia);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setFont(font3);

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
        label_13->setFont(font3);

        gridLayout_3->addWidget(label_13, 1, 2, 1, 1);

        lcdNumberGPUCount = new QLCDNumber(groupBoxNvidia);
        lcdNumberGPUCount->setObjectName(QStringLiteral("lcdNumberGPUCount"));
        lcdNumberGPUCount->setDigitCount(2);

        gridLayout_3->addWidget(lcdNumberGPUCount, 0, 1, 1, 1);

        label_15 = new QLabel(groupBoxNvidia);
        label_15->setObjectName(QStringLiteral("label_15"));
        label_15->setFont(font3);

        gridLayout_3->addWidget(label_15, 1, 11, 1, 1);

        label_11 = new QLabel(groupBoxNvidia);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setFont(font3);

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
        label_18->setFont(font3);

        gridLayout_3->addWidget(label_18, 2, 11, 1, 1);

        label_16 = new QLabel(groupBoxNvidia);
        label_16->setObjectName(QStringLiteral("label_16"));
        label_16->setFont(font3);

        gridLayout_3->addWidget(label_16, 0, 8, 1, 1);

        lcdNumberMinWatt = new QLCDNumber(groupBoxNvidia);
        lcdNumberMinWatt->setObjectName(QStringLiteral("lcdNumberMinWatt"));

        gridLayout_3->addWidget(lcdNumberMinWatt, 1, 12, 1, 1);

        lcdNumberMinGPUClock = new QLCDNumber(groupBoxNvidia);
        lcdNumberMinGPUClock->setObjectName(QStringLiteral("lcdNumberMinGPUClock"));

        gridLayout_3->addWidget(lcdNumberMinGPUClock, 1, 9, 1, 1);

        label_6 = new QLabel(groupBoxNvidia);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setFont(font3);

        gridLayout_3->addWidget(label_6, 0, 2, 1, 1);

        lcdNumberTotalPowerDraw = new QLCDNumber(groupBoxNvidia);
        lcdNumberTotalPowerDraw->setObjectName(QStringLiteral("lcdNumberTotalPowerDraw"));
        lcdNumberTotalPowerDraw->setDigitCount(5);

        gridLayout_3->addWidget(lcdNumberTotalPowerDraw, 2, 12, 1, 1);

        label_12 = new QLabel(groupBoxNvidia);
        label_12->setObjectName(QStringLiteral("label_12"));
        label_12->setFont(font3);

        gridLayout_3->addWidget(label_12, 1, 10, 1, 1);

        lcdNumberMaxGPUTemp = new QLCDNumber(groupBoxNvidia);
        lcdNumberMaxGPUTemp->setObjectName(QStringLiteral("lcdNumberMaxGPUTemp"));
        lcdNumberMaxGPUTemp->setDigitCount(3);

        gridLayout_3->addWidget(lcdNumberMaxGPUTemp, 0, 3, 1, 1);

        label_14 = new QLabel(groupBoxNvidia);
        label_14->setObjectName(QStringLiteral("label_14"));
        label_14->setFont(font3);

        gridLayout_3->addWidget(label_14, 0, 11, 1, 1);

        MainWindow->setCentralWidget(centralWidget);
        splitter_3->raise();
        lineEditWallet->raise();
        comboBoxCore->raise();
        labelWallet->raise();
        lineEditArgs->raise();
        comboBoxPool->raise();
        textEdit->raise();
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
        comboBoxChangePageSize->raise();
        spinBoxChangePageSizeMin->raise();
        spinBoxChangePageSizeMax->raise();
        pushButtonChangePageSize->raise();
        labelWallet_2->raise();
        stackedWidgetMain->raise();
        groupBox->raise();
        groupBox_3->raise();
        groupBox_2->raise();
        groupBoxDiskInfo->raise();

        retranslateUi(MainWindow);

        stackedWidgeMonitorMain->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Miner's Lamp", Q_NULLPTR));
        labelCore->setText(QApplication::translate("MainWindow", "Core", Q_NULLPTR));
        comboBoxCore->clear();
        comboBoxCore->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "NBMiner 37.1", Q_NULLPTR)
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
        labelWallet->setText(QApplication::translate("MainWindow", "Wallet", Q_NULLPTR));
        labelWorker->setText(QApplication::translate("MainWindow", "Worker", Q_NULLPTR));
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
        pushButtonChangePageSize->setText(QApplication::translate("MainWindow", "apply", Q_NULLPTR));
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
        radioButtonDwarfPool->setText(QApplication::translate("MainWindow", "Dwarfpool", Q_NULLPTR));
        label_19->setText(QApplication::translate("MainWindow", "Balance:", Q_NULLPTR));
        label_22->setText(QApplication::translate("MainWindow", "Last Reported Hashrate:", Q_NULLPTR));
        label_20->setText(QApplication::translate("MainWindow", "Current Calculated Hashrate:", Q_NULLPTR));
        radioButtonEthermine->setText(QApplication::translate("MainWindow", "Ethermine", Q_NULLPTR));
        label_21->setText(QApplication::translate("MainWindow", "Average Hashrate\n"
"for last 6 hour:", Q_NULLPTR));
        lineEditAccount->setText(QApplication::translate("MainWindow", "0xa07A8c9975145BB5371e8b3C31ACb62ad9d0698E", Q_NULLPTR));
        pushButtonDisplayPoolStats->setText(QApplication::translate("MainWindow", "Refresh", Q_NULLPTR));
        radioButtonNaopool->setText(QApplication::translate("MainWindow", "Nanopool", Q_NULLPTR));
        groupBox->setTitle(QApplication::translate("MainWindow", "Hashrate chart", Q_NULLPTR));
        label->setText(QApplication::translate("MainWindow", "Current Hashrate", Q_NULLPTR));
        label_2->setText(QApplication::translate("MainWindow", "Estimated Income", Q_NULLPTR));
        groupBox_3->setTitle(QApplication::translate("MainWindow", "GroupBox", Q_NULLPTR));
        label_23->setText(QApplication::translate("MainWindow", "Mem\n"
"Clock", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("MainWindow", "up", Q_NULLPTR));
        pushButton_3->setText(QApplication::translate("MainWindow", "dw", Q_NULLPTR));
        label_34->setText(QApplication::translate("MainWindow", "Mem\n"
"Clock", Q_NULLPTR));
        pushButton_4->setText(QApplication::translate("MainWindow", "up", Q_NULLPTR));
        pushButton_5->setText(QApplication::translate("MainWindow", "dw", Q_NULLPTR));
        label_36->setText(QApplication::translate("MainWindow", "Mem\n"
"Clock", Q_NULLPTR));
        pushButton_8->setText(QApplication::translate("MainWindow", "up", Q_NULLPTR));
        pushButton_9->setText(QApplication::translate("MainWindow", "dw", Q_NULLPTR));
        groupBox_2->setTitle(QApplication::translate("MainWindow", "Temperature chart", Q_NULLPTR));
        groupBoxDiskInfo->setTitle(QApplication::translate("MainWindow", "Disk Info", Q_NULLPTR));
        labelCoin->setText(QApplication::translate("MainWindow", "Coin", Q_NULLPTR));
        comboBoxCoin->clear();
        comboBoxCoin->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "ETH", Q_NULLPTR)
        );
        dateTimeEditHistoryStartTime->setDisplayFormat(QApplication::translate("MainWindow", "yyyy/MM/dd", Q_NULLPTR));
        dateTimeEditHistoryEndTime->setDisplayFormat(QApplication::translate("MainWindow", "yyyy/MM/dd", Q_NULLPTR));
        labelHistoryDeviceNum->setText(QApplication::translate("MainWindow", "Device#", Q_NULLPTR));
        pushButtonPool->setText(QApplication::translate("MainWindow", "Pool", Q_NULLPTR));
        pushButtonShowHideLog->setText(QApplication::translate("MainWindow", "Hide log", Q_NULLPTR));
        groupBoxDevicesInfo->setTitle(QApplication::translate("MainWindow", "Devices Info", Q_NULLPTR));
        groupBoxHistoryInfo->setTitle(QApplication::translate("MainWindow", "History", Q_NULLPTR));
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
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H

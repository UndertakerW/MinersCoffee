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
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "hashratecharview.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QGridLayout *gridLayout_10;
    QLineEdit *lineEditArgs;
    QPushButton *pushButtonPool;
    QSplitter *splitter_2;
    QGroupBox *groupBoxDevicesInfo;
    QGridLayout *gridLayout_9;
    QGridLayout *gridLayoutDevicesInfo;
    QSplitter *splitter;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout_2;
    QGroupBox *groupBox;
    QGridLayout *gridLayout_5;
    hashrateCharView *graphicsView;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout_6;
    hashrateCharView *graphicsViewTemp;
    QGroupBox *groupBoxEffectiveness;
    QGridLayout *gridLayout_7;
    QGridLayout *gridLayoutEff;
    hashrateCharView *graphicsViewEff;
    QGroupBox *groupBoxHistoryInfo;
    QGridLayout *gridLayout_8;
    hashrateCharView *graphicsViewHistoryInfo;
    QLineEdit *lineEditWorker;
    QPushButton *pushButtonShowHideLog;
    QCheckBox *checkBoxAutoStart;
    QPushButton *pushButton;
    QGroupBox *groupBoxWatchdog;
    QGridLayout *gridLayout;
    QSpinBox *spinBoxDelay0MHs;
    QSpinBox *spinBoxMax0MHs;
    QSpinBox *spinBoxDelayNoHash;
    QLabel *label_5;
    QVBoxLayout *verticalLayout;
    QLabel *label_23;
    QTextEdit *debugBox;
    QSpinBox *spinBoxDelay;
    QLabel *label_3;
    QLabel *label_7;
    QLabel *label_4;
    QCheckBox *checkBoxAutoShowDeviceInfo;
    QLabel *labelWallet;
    QLabel *labelWorker;
    QGroupBox *groupBoxPools;
    QGridLayout *gridLayout_4;
    QLCDNumber *lcdNumberBalance;
    QLCDNumber *lcdNumber_4;
    QPushButton *pushButtonDisplayPoolStats;
    QLabel *label_19;
    QLabel *label_20;
    QLabel *label_21;
    QRadioButton *radioButtonDwarfPool;
    QLineEdit *lineEditAccount;
    QRadioButton *radioButtonNaopool;
    QLCDNumber *lcdNumberCalculatedHR;
    QLabel *label_22;
    QLCDNumber *lcdNumberAvrgHr6H;
    QRadioButton *radioButtonEthermine;
    QComboBox *comboBoxPool;
    QComboBox *comboBoxCoin;
    QTextEdit *textEdit;
    QPushButton *pushButtonEthminerBrowser;
    QCheckBox *checkBoxOnlyShare;
    QLCDNumber *lcdNumberHashRate;
    QLineEdit *lineEditMinerPath;
    QLabel *labelCoin;
    QComboBox *comboBoxCore;
    QLabel *labelPool;
    QGroupBox *groupBoxNvidia;
    QGridLayout *gridLayout_3;
    QLCDNumber *lcdNumberTotalPowerDraw;
    QLabel *label_17;
    QLabel *label_15;
    QLCDNumber *lcdNumberMinMemClock;
    QLabel *label_6;
    QLabel *label_13;
    QLabel *label_11;
    QLCDNumber *lcdNumberMaxWatt;
    QLCDNumber *lcdNumberMaxGPUClock;
    QLCDNumber *lcdNumberMaxGPUTemp;
    QLCDNumber *lcdNumberGPUCount;
    QLCDNumber *lcdNumberMinWatt;
    QLabel *label_9;
    QLCDNumber *lcdNumberMinFanSpeed;
    QLabel *label_16;
    QLCDNumber *lcdNumberMaxFanSpeed;
    QLabel *label_8;
    QLabel *label_14;
    QLabel *label_12;
    QLCDNumber *lcdNumberMinGPUTemp;
    QPushButton *pushButtonOC;
    QLabel *label_18;
    QLCDNumber *lcdNumberMinGPUClock;
    QLCDNumber *lcdNumberMaxMemClock;
    QLabel *label_10;
    QLabel *labelCore;
    QGroupBox *groupBoxAMD;
    QGridLayout *gridLayout_2;
    QLabel *label_28;
    QLCDNumber *lcdNumber_AMD_MaxTemp;
    QLabel *label_31;
    QLCDNumber *lcdNumber_AMD_MinPoxer;
    QLCDNumber *lcdNumber_AMD_MaxMemClock;
    QLabel *label_AMD_GPUCount;
    QLCDNumber *lcdNumber_AMD_MinClock;
    QLabel *label_30;
    QLCDNumber *lcdNumber_AMD_MinMemClock;
    QLCDNumber *lcdNumber_AMD_MaxFan;
    QLabel *label_33;
    QLCDNumber *lcdNumber_AMD_GPUCount;
    QLCDNumber *lcdNumber_AMD_MaxClock;
    QLabel *label_24;
    QLabel *label_25;
    QLabel *label_27;
    QLCDNumber *lcdNumber_AMD_MinFan;
    QLabel *label_29;
    QLCDNumber *lcdNumber_AMD_MinTemp;
    QLabel *label_32;
    QLCDNumber *lcdNumber_AMD_MaxPower;
    QLabel *label_26;
    QCheckBox *checkBoxShowHistoryInfo;
    QLineEdit *lineEditWallet;
    QPushButton *pushButtonHelp;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1238, 1060);
        QFont font;
        font.setFamily(QStringLiteral("Tahoma"));
        font.setPointSize(10);
        MainWindow->setFont(font);
        QIcon icon;
        icon.addFile(QStringLiteral(":/icons/eth_miner_lamp.ico"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindow->setWindowIcon(icon);
        MainWindow->setStyleSheet(QLatin1String("QWidget {\n"
"\n"
"color: white;\n"
"  background-color:  black;\n"
"\n"
" }\n"
"\n"
"QSlider::groove:horizontal {\n"
"    border: 1px solid #999999;\n"
"    height: 8px; /* the groove expands to the size of the slider by default. by giving it a height, it has a fixed size */\n"
"    background: qlineargradient(x1:0, y1:0, x2:0, y2:1, stop:0 #B1B1B1, stop:1 #c4c4c4);\n"
"    margin: 2px 0;\n"
"}\n"
"\n"
"QSlider::handle:horizontal {\n"
"    background: qlineargradient(x1:0, y1:0, x2:1, y2:1, stop:0 #00b400, stop:1 #8f8f8f);\n"
"    border: 1px solid #5c5c5c;\n"
"    width: 18px;\n"
"    margin: -2px 0; /* handle is placed by default on the contents rect of the groove. Expand outside the groove */\n"
"    border-radius: 3px;\n"
"}\n"
"\n"
"QLabel\n"
"{\n"
"  background-color: black;\n"
"  color: white;\n"
"\n"
"}\n"
"\n"
"QGroupBox {\n"
"    background-color: black;\n"
"    border: 2px solid gray;\n"
"    border-radius: 5px;\n"
"    margin-top: 1ex; /* leave space at the top for the title */\n"
"}\n"
"\n"
"QGro"
                        "upBox::title {\n"
"    subcontrol-origin: margin;\n"
"    subcontrol-position: top center; /* position at the top center */\n"
"    padding: 0 3px;\n"
"    background-color: black;\n"
"}\n"
"\n"
"\n"
"QLineEdit {\n"
" padding: 1px;\n"
" border-style: solid;\n"
" border: 2px solid gray;\n"
" border-radius: 4px;\n"
" }\n"
"\n"
"QTextEdit {\n"
"  border: 2px solid gray;\n"
"  border-radius: 4px;\n"
"}\n"
"\n"
"\n"
"QLineEdit#lineEditDonate\n"
"{\n"
"border-style: no-border;\n"
"color: yellow;\n"
"}\n"
"\n"
"\n"
"QDateTimeEdit {\n"
"  padding: 1px;\n"
"  border-style: solid;\n"
"  border: 2px solid gray;\n"
"  border-radius: 4px;\n"
"}\n"
"\n"
"QTimeEdit {\n"
"  padding: 1px;\n"
"  border-style: solid;\n"
"  border: 2px solid gray;\n"
"  border-radius: 4px;\n"
"}\n"
"\n"
"QComboBox {\n"
"  border: 2px solid gray;\n"
"  border-radius: 4px;\n"
"}\n"
"\n"
"QTreeView {\n"
"  border: 2px solid gray;\n"
"  border-radius: 4px;\n"
"}\n"
"\n"
"\n"
"QListView {\n"
"    alternate-background-color: gray;\n"
"}\n"
"\n"
"\n"
"\n"
""
                        "QCheckBox {\n"
"color: white;\n"
"\n"
" }\n"
"\n"
"QSpinBox {\n"
"color: white;\n"
" padding: 1px;\n"
" border-style: solid;\n"
" border: 2px solid gray;\n"
" border-radius: 2px;\n"
" }\n"
"\n"
"QPushButton {\n"
" color: white;\n"
" background-color: QLinearGradient( x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                    stop: 0 #808080, stop: 0.1 #909090,\n"
"                    stop: 0.49 #505050, stop: 0.5 #666666, stop: 1 #909090);\n"
" border-width: 1px;\n"
" border-color: black;\n"
" border-style: solid;\n"
" border-radius: 4;\n"
" padding: 3px;\n"
" font-size: 13px;\n"
" padding-left: 5px;\n"
" padding-right: 5px;\n"
" min-width: 50px;\n"
" max-width: 200px;\n"
" min-height: 13px;\n"
" max-height: 40px;\n"
" }\n"
"\n"
"QPushButton:pressed\n"
"{\n"
" color: white;\n"
" background-color: QLinearGradient( x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 #88d, stop: 0.1 #77e, stop: 0.49 #12c, stop: 0.5 #33b, stop: 1 #22c);\n"
" border-width: 1px;\n"
" border-color: black;\n"
" border-style: solid;\n"
" border-radius: 4;\n"
""
                        " padding: 3px;\n"
" font-size: 13px;\n"
" padding-left: 5px;\n"
" padding-right: 5px;\n"
" min-width: 50px;\n"
" max-width: 200px;\n"
" min-height: 13px;\n"
" max-height: 40px;\n"
"}\n"
"\n"
"QPushButton:hover\n"
"{\n"
" color: white;\n"
" background-color: QLinearGradient( x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 #505050, stop: 0.1 #707070, stop: 0.49 #12c, stop: 0.5 #aaaaaa, stop: 1 #33c);\n"
" border-width: 1px;\n"
" border-color: black;\n"
" border-style: solid;\n"
" border-radius: 4;\n"
" padding: 3px;\n"
" font-size: 13px;\n"
" padding-left: 5px;\n"
" padding-right: 5px;\n"
" min-width: 50px;\n"
" max-width: 200px;\n"
" min-height: 13px;\n"
" max-height: 40px;\n"
"}\n"
"\n"
"QPushButton:checked\n"
"{\n"
" color: white;\n"
" background-color: QLinearGradient( x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 #88d, stop: 0.1 #77e, stop: 0.49 #12c, stop: 0.5 #44b, stop: 1 #ddc);\n"
" border-width: 1px;\n"
" border-color: black;\n"
" border-style: solid;\n"
" border-radius: 4;\n"
" padding: 3px;\n"
" font-size: 13px;\n"
" padd"
                        "ing-left: 5px;\n"
" padding-right: 5px;\n"
" min-width: 50px;\n"
" max-width: 200px;\n"
" min-height: 13px;\n"
" max-height: 40px;\n"
"}\n"
"\n"
"QPushButton:disabled\n"
"{\n"
" color: white;\n"
" background-color: QLinearGradient( x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                    stop: 0 #CCCCCC, stop: 0.1 #EEEEEE,\n"
"                    stop: 0.49 #AAAAAA, stop: 0.5 #BBBBBB, stop: 1 #CCCCCC);\n"
" border-width: 1px;\n"
" border-color: black;\n"
" border-style: solid;\n"
" border-radius: 4;\n"
" padding: 3px;\n"
" font-size: 13px;\n"
" padding-left: 5px;\n"
" padding-right: 5px;\n"
" min-width: 50px;\n"
" max-width: 200px;\n"
" min-height: 13px;\n"
" max-height: 40px;\n"
"}"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        centralWidget->setEnabled(true);
        gridLayout_10 = new QGridLayout(centralWidget);
        gridLayout_10->setSpacing(6);
        gridLayout_10->setContentsMargins(11, 11, 11, 11);
        gridLayout_10->setObjectName(QStringLiteral("gridLayout_10"));
        lineEditArgs = new QLineEdit(centralWidget);
        lineEditArgs->setObjectName(QStringLiteral("lineEditArgs"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(lineEditArgs->sizePolicy().hasHeightForWidth());
        lineEditArgs->setSizePolicy(sizePolicy);
        lineEditArgs->setMaximumSize(QSize(0, 0));

        gridLayout_10->addWidget(lineEditArgs, 2, 10, 1, 1);

        pushButtonPool = new QPushButton(centralWidget);
        pushButtonPool->setObjectName(QStringLiteral("pushButtonPool"));
        pushButtonPool->setEnabled(true);
        QFont font1;
        font1.setFamily(QStringLiteral("Arial"));
        pushButtonPool->setFont(font1);
        pushButtonPool->setCheckable(true);

        gridLayout_10->addWidget(pushButtonPool, 8, 14, 1, 1);

        splitter_2 = new QSplitter(centralWidget);
        splitter_2->setObjectName(QStringLiteral("splitter_2"));
        splitter_2->setOrientation(Qt::Vertical);
        groupBoxDevicesInfo = new QGroupBox(splitter_2);
        groupBoxDevicesInfo->setObjectName(QStringLiteral("groupBoxDevicesInfo"));
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

        splitter_2->addWidget(groupBoxDevicesInfo);
        splitter = new QSplitter(splitter_2);
        splitter->setObjectName(QStringLiteral("splitter"));
        splitter->setOrientation(Qt::Horizontal);
        layoutWidget = new QWidget(splitter);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        verticalLayout_2 = new QVBoxLayout(layoutWidget);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        groupBox = new QGroupBox(layoutWidget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setFont(font1);
        gridLayout_5 = new QGridLayout(groupBox);
        gridLayout_5->setSpacing(6);
        gridLayout_5->setContentsMargins(11, 11, 11, 11);
        gridLayout_5->setObjectName(QStringLiteral("gridLayout_5"));
        graphicsView = new hashrateCharView(groupBox);
        graphicsView->setObjectName(QStringLiteral("graphicsView"));
        graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);

        gridLayout_5->addWidget(graphicsView, 0, 0, 1, 1);


        verticalLayout_2->addWidget(groupBox);

        groupBox_2 = new QGroupBox(layoutWidget);
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


        verticalLayout_2->addWidget(groupBox_2);

        splitter->addWidget(layoutWidget);
        groupBoxEffectiveness = new QGroupBox(splitter);
        groupBoxEffectiveness->setObjectName(QStringLiteral("groupBoxEffectiveness"));
        groupBoxEffectiveness->setFont(font1);
        gridLayout_7 = new QGridLayout(groupBoxEffectiveness);
        gridLayout_7->setSpacing(6);
        gridLayout_7->setContentsMargins(11, 11, 11, 11);
        gridLayout_7->setObjectName(QStringLiteral("gridLayout_7"));
        gridLayoutEff = new QGridLayout();
        gridLayoutEff->setSpacing(6);
        gridLayoutEff->setObjectName(QStringLiteral("gridLayoutEff"));
        graphicsViewEff = new hashrateCharView(groupBoxEffectiveness);
        graphicsViewEff->setObjectName(QStringLiteral("graphicsViewEff"));

        gridLayoutEff->addWidget(graphicsViewEff, 0, 0, 1, 1);

        groupBoxHistoryInfo = new QGroupBox(groupBoxEffectiveness);
        groupBoxHistoryInfo->setObjectName(QStringLiteral("groupBoxHistoryInfo"));
        groupBoxHistoryInfo->setFont(font1);
        gridLayout_8 = new QGridLayout(groupBoxHistoryInfo);
        gridLayout_8->setSpacing(6);
        gridLayout_8->setContentsMargins(11, 11, 11, 11);
        gridLayout_8->setObjectName(QStringLiteral("gridLayout_8"));
        graphicsViewHistoryInfo = new hashrateCharView(groupBoxHistoryInfo);
        graphicsViewHistoryInfo->setObjectName(QStringLiteral("graphicsViewHistoryInfo"));
        graphicsViewHistoryInfo->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);

        gridLayout_8->addWidget(graphicsViewHistoryInfo, 0, 0, 1, 1);


        gridLayoutEff->addWidget(groupBoxHistoryInfo, 1, 0, 1, 1);


        gridLayout_7->addLayout(gridLayoutEff, 1, 0, 1, 1);

        splitter->addWidget(groupBoxEffectiveness);
        splitter_2->addWidget(splitter);

        gridLayout_10->addWidget(splitter_2, 7, 0, 1, 15);

        lineEditWorker = new QLineEdit(centralWidget);
        lineEditWorker->setObjectName(QStringLiteral("lineEditWorker"));
        sizePolicy.setHeightForWidth(lineEditWorker->sizePolicy().hasHeightForWidth());
        lineEditWorker->setSizePolicy(sizePolicy);
        lineEditWorker->setMinimumSize(QSize(0, 31));
        QFont font2;
        font2.setPointSize(12);
        lineEditWorker->setFont(font2);

        gridLayout_10->addWidget(lineEditWorker, 1, 12, 1, 2);

        pushButtonShowHideLog = new QPushButton(centralWidget);
        pushButtonShowHideLog->setObjectName(QStringLiteral("pushButtonShowHideLog"));
        pushButtonShowHideLog->setFont(font1);
        pushButtonShowHideLog->setCheckable(true);

        gridLayout_10->addWidget(pushButtonShowHideLog, 8, 13, 1, 1);

        checkBoxAutoStart = new QCheckBox(centralWidget);
        checkBoxAutoStart->setObjectName(QStringLiteral("checkBoxAutoStart"));
        checkBoxAutoStart->setFont(font1);

        gridLayout_10->addWidget(checkBoxAutoStart, 2, 0, 1, 2);

        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setFont(font1);

        gridLayout_10->addWidget(pushButton, 3, 11, 1, 1);

        groupBoxWatchdog = new QGroupBox(centralWidget);
        groupBoxWatchdog->setObjectName(QStringLiteral("groupBoxWatchdog"));
        sizePolicy.setHeightForWidth(groupBoxWatchdog->sizePolicy().hasHeightForWidth());
        groupBoxWatchdog->setSizePolicy(sizePolicy);
        groupBoxWatchdog->setFont(font1);
        groupBoxWatchdog->setCheckable(true);
        groupBoxWatchdog->setChecked(false);
        gridLayout = new QGridLayout(groupBoxWatchdog);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        spinBoxDelay0MHs = new QSpinBox(groupBoxWatchdog);
        spinBoxDelay0MHs->setObjectName(QStringLiteral("spinBoxDelay0MHs"));
        spinBoxDelay0MHs->setFont(font1);
        spinBoxDelay0MHs->setMinimum(1);
        spinBoxDelay0MHs->setMaximum(600);
        spinBoxDelay0MHs->setValue(20);

        gridLayout->addWidget(spinBoxDelay0MHs, 1, 1, 1, 1);

        spinBoxMax0MHs = new QSpinBox(groupBoxWatchdog);
        spinBoxMax0MHs->setObjectName(QStringLiteral("spinBoxMax0MHs"));
        spinBoxMax0MHs->setFont(font1);
        spinBoxMax0MHs->setMinimum(1);

        gridLayout->addWidget(spinBoxMax0MHs, 0, 1, 1, 1);

        spinBoxDelayNoHash = new QSpinBox(groupBoxWatchdog);
        spinBoxDelayNoHash->setObjectName(QStringLiteral("spinBoxDelayNoHash"));
        spinBoxDelayNoHash->setFont(font1);
        spinBoxDelayNoHash->setMinimum(30);
        spinBoxDelayNoHash->setMaximum(600);
        spinBoxDelayNoHash->setValue(60);

        gridLayout->addWidget(spinBoxDelayNoHash, 1, 3, 1, 1);

        label_5 = new QLabel(groupBoxWatchdog);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setFont(font1);

        gridLayout->addWidget(label_5, 0, 2, 1, 1);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        label_23 = new QLabel(groupBoxWatchdog);
        label_23->setObjectName(QStringLiteral("label_23"));
        label_23->setFont(font1);
        label_23->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label_23);

        debugBox = new QTextEdit(groupBoxWatchdog);
        debugBox->setObjectName(QStringLiteral("debugBox"));

        verticalLayout->addWidget(debugBox);


        gridLayout->addLayout(verticalLayout, 0, 4, 2, 1);

        spinBoxDelay = new QSpinBox(groupBoxWatchdog);
        spinBoxDelay->setObjectName(QStringLiteral("spinBoxDelay"));
        spinBoxDelay->setFont(font1);
        spinBoxDelay->setMinimum(1);

        gridLayout->addWidget(spinBoxDelay, 0, 3, 1, 1);

        label_3 = new QLabel(groupBoxWatchdog);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setFont(font1);

        gridLayout->addWidget(label_3, 1, 0, 1, 1);

        label_7 = new QLabel(groupBoxWatchdog);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setFont(font1);

        gridLayout->addWidget(label_7, 1, 2, 1, 1);

        label_4 = new QLabel(groupBoxWatchdog);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setFont(font1);

        gridLayout->addWidget(label_4, 0, 0, 1, 1);


        gridLayout_10->addWidget(groupBoxWatchdog, 3, 0, 2, 9);

        checkBoxAutoShowDeviceInfo = new QCheckBox(centralWidget);
        checkBoxAutoShowDeviceInfo->setObjectName(QStringLiteral("checkBoxAutoShowDeviceInfo"));
        checkBoxAutoShowDeviceInfo->setFont(font1);

        gridLayout_10->addWidget(checkBoxAutoShowDeviceInfo, 2, 2, 1, 2);

        labelWallet = new QLabel(centralWidget);
        labelWallet->setObjectName(QStringLiteral("labelWallet"));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(labelWallet->sizePolicy().hasHeightForWidth());
        labelWallet->setSizePolicy(sizePolicy1);
        labelWallet->setMaximumSize(QSize(60, 16777215));
        QFont font3;
        font3.setFamily(QStringLiteral("Arial"));
        font3.setPointSize(12);
        font3.setBold(true);
        font3.setWeight(75);
        labelWallet->setFont(font3);

        gridLayout_10->addWidget(labelWallet, 1, 7, 1, 1);

        labelWorker = new QLabel(centralWidget);
        labelWorker->setObjectName(QStringLiteral("labelWorker"));
        sizePolicy1.setHeightForWidth(labelWorker->sizePolicy().hasHeightForWidth());
        labelWorker->setSizePolicy(sizePolicy1);
        labelWorker->setMinimumSize(QSize(0, 31));
        labelWorker->setMaximumSize(QSize(100, 16777215));
        labelWorker->setFont(font3);

        gridLayout_10->addWidget(labelWorker, 1, 11, 1, 1);

        groupBoxPools = new QGroupBox(centralWidget);
        groupBoxPools->setObjectName(QStringLiteral("groupBoxPools"));
        groupBoxPools->setEnabled(true);
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(groupBoxPools->sizePolicy().hasHeightForWidth());
        groupBoxPools->setSizePolicy(sizePolicy2);
        groupBoxPools->setFont(font1);
        gridLayout_4 = new QGridLayout(groupBoxPools);
        gridLayout_4->setSpacing(6);
        gridLayout_4->setContentsMargins(11, 11, 11, 11);
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        lcdNumberBalance = new QLCDNumber(groupBoxPools);
        lcdNumberBalance->setObjectName(QStringLiteral("lcdNumberBalance"));
        lcdNumberBalance->setSmallDecimalPoint(false);
        lcdNumberBalance->setDigitCount(12);

        gridLayout_4->addWidget(lcdNumberBalance, 3, 2, 1, 1);

        lcdNumber_4 = new QLCDNumber(groupBoxPools);
        lcdNumber_4->setObjectName(QStringLiteral("lcdNumber_4"));
        lcdNumber_4->setDigitCount(6);

        gridLayout_4->addWidget(lcdNumber_4, 4, 5, 1, 1);

        pushButtonDisplayPoolStats = new QPushButton(groupBoxPools);
        pushButtonDisplayPoolStats->setObjectName(QStringLiteral("pushButtonDisplayPoolStats"));
        pushButtonDisplayPoolStats->setFont(font1);

        gridLayout_4->addWidget(pushButtonDisplayPoolStats, 2, 6, 1, 1);

        label_19 = new QLabel(groupBoxPools);
        label_19->setObjectName(QStringLiteral("label_19"));
        label_19->setFont(font1);

        gridLayout_4->addWidget(label_19, 3, 0, 1, 1);

        label_20 = new QLabel(groupBoxPools);
        label_20->setObjectName(QStringLiteral("label_20"));
        label_20->setFont(font1);

        gridLayout_4->addWidget(label_20, 4, 0, 1, 1);

        label_21 = new QLabel(groupBoxPools);
        label_21->setObjectName(QStringLiteral("label_21"));
        label_21->setFont(font1);

        gridLayout_4->addWidget(label_21, 4, 2, 1, 1);

        radioButtonDwarfPool = new QRadioButton(groupBoxPools);
        radioButtonDwarfPool->setObjectName(QStringLiteral("radioButtonDwarfPool"));
        radioButtonDwarfPool->setEnabled(false);
        radioButtonDwarfPool->setFont(font1);

        gridLayout_4->addWidget(radioButtonDwarfPool, 0, 4, 1, 1);

        lineEditAccount = new QLineEdit(groupBoxPools);
        lineEditAccount->setObjectName(QStringLiteral("lineEditAccount"));
        lineEditAccount->setFont(font1);

        gridLayout_4->addWidget(lineEditAccount, 2, 0, 1, 5);

        radioButtonNaopool = new QRadioButton(groupBoxPools);
        radioButtonNaopool->setObjectName(QStringLiteral("radioButtonNaopool"));
        radioButtonNaopool->setFont(font1);
        radioButtonNaopool->setChecked(true);

        gridLayout_4->addWidget(radioButtonNaopool, 0, 0, 1, 1);

        lcdNumberCalculatedHR = new QLCDNumber(groupBoxPools);
        lcdNumberCalculatedHR->setObjectName(QStringLiteral("lcdNumberCalculatedHR"));
        lcdNumberCalculatedHR->setDigitCount(6);

        gridLayout_4->addWidget(lcdNumberCalculatedHR, 4, 1, 1, 1);

        label_22 = new QLabel(groupBoxPools);
        label_22->setObjectName(QStringLiteral("label_22"));
        label_22->setFont(font1);

        gridLayout_4->addWidget(label_22, 4, 4, 1, 1);

        lcdNumberAvrgHr6H = new QLCDNumber(groupBoxPools);
        lcdNumberAvrgHr6H->setObjectName(QStringLiteral("lcdNumberAvrgHr6H"));
        lcdNumberAvrgHr6H->setDigitCount(6);

        gridLayout_4->addWidget(lcdNumberAvrgHr6H, 4, 3, 1, 1);

        radioButtonEthermine = new QRadioButton(groupBoxPools);
        radioButtonEthermine->setObjectName(QStringLiteral("radioButtonEthermine"));
        radioButtonEthermine->setEnabled(false);
        radioButtonEthermine->setFont(font1);

        gridLayout_4->addWidget(radioButtonEthermine, 0, 2, 1, 1);


        gridLayout_10->addWidget(groupBoxPools, 10, 0, 1, 9);

        comboBoxPool = new QComboBox(centralWidget);
        comboBoxPool->setObjectName(QStringLiteral("comboBoxPool"));
        comboBoxPool->setMinimumSize(QSize(0, 31));
        comboBoxPool->setFont(font2);

        gridLayout_10->addWidget(comboBoxPool, 1, 6, 1, 1);

        comboBoxCoin = new QComboBox(centralWidget);
        comboBoxCoin->setObjectName(QStringLiteral("comboBoxCoin"));
        sizePolicy.setHeightForWidth(comboBoxCoin->sizePolicy().hasHeightForWidth());
        comboBoxCoin->setSizePolicy(sizePolicy);
        comboBoxCoin->setMinimumSize(QSize(0, 31));
        comboBoxCoin->setMaximumSize(QSize(90, 16777215));
        comboBoxCoin->setFont(font2);

        gridLayout_10->addWidget(comboBoxCoin, 1, 1, 1, 1);

        textEdit = new QTextEdit(centralWidget);
        textEdit->setObjectName(QStringLiteral("textEdit"));
        textEdit->setFont(font1);
        textEdit->setReadOnly(true);

        gridLayout_10->addWidget(textEdit, 9, 0, 1, 15);

        pushButtonEthminerBrowser = new QPushButton(centralWidget);
        pushButtonEthminerBrowser->setObjectName(QStringLiteral("pushButtonEthminerBrowser"));
        QSizePolicy sizePolicy3(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(pushButtonEthminerBrowser->sizePolicy().hasHeightForWidth());
        pushButtonEthminerBrowser->setSizePolicy(sizePolicy3);
        pushButtonEthminerBrowser->setFont(font1);

        gridLayout_10->addWidget(pushButtonEthminerBrowser, 4, 12, 1, 1);

        checkBoxOnlyShare = new QCheckBox(centralWidget);
        checkBoxOnlyShare->setObjectName(QStringLiteral("checkBoxOnlyShare"));
        checkBoxOnlyShare->setFont(font1);

        gridLayout_10->addWidget(checkBoxOnlyShare, 8, 0, 1, 3);

        lcdNumberHashRate = new QLCDNumber(centralWidget);
        lcdNumberHashRate->setObjectName(QStringLiteral("lcdNumberHashRate"));
        QSizePolicy sizePolicy4(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(lcdNumberHashRate->sizePolicy().hasHeightForWidth());
        lcdNumberHashRate->setSizePolicy(sizePolicy4);
        lcdNumberHashRate->setFont(font1);
        lcdNumberHashRate->setDigitCount(7);

        gridLayout_10->addWidget(lcdNumberHashRate, 3, 12, 1, 1);

        lineEditMinerPath = new QLineEdit(centralWidget);
        lineEditMinerPath->setObjectName(QStringLiteral("lineEditMinerPath"));
        lineEditMinerPath->setMaximumSize(QSize(0, 0));

        gridLayout_10->addWidget(lineEditMinerPath, 0, 9, 1, 1);

        labelCoin = new QLabel(centralWidget);
        labelCoin->setObjectName(QStringLiteral("labelCoin"));
        sizePolicy1.setHeightForWidth(labelCoin->sizePolicy().hasHeightForWidth());
        labelCoin->setSizePolicy(sizePolicy1);
        labelCoin->setMinimumSize(QSize(0, 31));
        labelCoin->setMaximumSize(QSize(50, 16777215));
        labelCoin->setFont(font3);

        gridLayout_10->addWidget(labelCoin, 1, 0, 1, 1);

        comboBoxCore = new QComboBox(centralWidget);
        comboBoxCore->setObjectName(QStringLiteral("comboBoxCore"));
        comboBoxCore->setMinimumSize(QSize(0, 31));
        comboBoxCore->setFont(font2);

        gridLayout_10->addWidget(comboBoxCore, 1, 3, 1, 2);

        labelPool = new QLabel(centralWidget);
        labelPool->setObjectName(QStringLiteral("labelPool"));
        sizePolicy1.setHeightForWidth(labelPool->sizePolicy().hasHeightForWidth());
        labelPool->setSizePolicy(sizePolicy1);
        labelPool->setMinimumSize(QSize(0, 31));
        labelPool->setMaximumSize(QSize(50, 16777215));
        labelPool->setFont(font3);

        gridLayout_10->addWidget(labelPool, 1, 5, 1, 1);

        groupBoxNvidia = new QGroupBox(centralWidget);
        groupBoxNvidia->setObjectName(QStringLiteral("groupBoxNvidia"));
        sizePolicy.setHeightForWidth(groupBoxNvidia->sizePolicy().hasHeightForWidth());
        groupBoxNvidia->setSizePolicy(sizePolicy);
        QFont font4;
        font4.setFamily(QStringLiteral("Arial"));
        font4.setPointSize(8);
        font4.setBold(false);
        font4.setWeight(50);
        groupBoxNvidia->setFont(font4);
        gridLayout_3 = new QGridLayout(groupBoxNvidia);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        lcdNumberTotalPowerDraw = new QLCDNumber(groupBoxNvidia);
        lcdNumberTotalPowerDraw->setObjectName(QStringLiteral("lcdNumberTotalPowerDraw"));
        lcdNumberTotalPowerDraw->setDigitCount(5);

        gridLayout_3->addWidget(lcdNumberTotalPowerDraw, 2, 13, 1, 1);

        label_17 = new QLabel(groupBoxNvidia);
        label_17->setObjectName(QStringLiteral("label_17"));
        label_17->setFont(font1);

        gridLayout_3->addWidget(label_17, 1, 8, 1, 1);

        label_15 = new QLabel(groupBoxNvidia);
        label_15->setObjectName(QStringLiteral("label_15"));
        label_15->setFont(font1);

        gridLayout_3->addWidget(label_15, 1, 12, 1, 1);

        lcdNumberMinMemClock = new QLCDNumber(groupBoxNvidia);
        lcdNumberMinMemClock->setObjectName(QStringLiteral("lcdNumberMinMemClock"));

        gridLayout_3->addWidget(lcdNumberMinMemClock, 1, 11, 1, 1);

        label_6 = new QLabel(groupBoxNvidia);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setFont(font1);

        gridLayout_3->addWidget(label_6, 0, 2, 1, 1);

        label_13 = new QLabel(groupBoxNvidia);
        label_13->setObjectName(QStringLiteral("label_13"));
        label_13->setFont(font1);

        gridLayout_3->addWidget(label_13, 1, 2, 1, 1);

        label_11 = new QLabel(groupBoxNvidia);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setFont(font1);

        gridLayout_3->addWidget(label_11, 1, 5, 1, 1);

        lcdNumberMaxWatt = new QLCDNumber(groupBoxNvidia);
        lcdNumberMaxWatt->setObjectName(QStringLiteral("lcdNumberMaxWatt"));

        gridLayout_3->addWidget(lcdNumberMaxWatt, 0, 13, 1, 1);

        lcdNumberMaxGPUClock = new QLCDNumber(groupBoxNvidia);
        lcdNumberMaxGPUClock->setObjectName(QStringLiteral("lcdNumberMaxGPUClock"));

        gridLayout_3->addWidget(lcdNumberMaxGPUClock, 0, 9, 1, 1);

        lcdNumberMaxGPUTemp = new QLCDNumber(groupBoxNvidia);
        lcdNumberMaxGPUTemp->setObjectName(QStringLiteral("lcdNumberMaxGPUTemp"));
        lcdNumberMaxGPUTemp->setDigitCount(3);

        gridLayout_3->addWidget(lcdNumberMaxGPUTemp, 0, 3, 1, 1);

        lcdNumberGPUCount = new QLCDNumber(groupBoxNvidia);
        lcdNumberGPUCount->setObjectName(QStringLiteral("lcdNumberGPUCount"));
        lcdNumberGPUCount->setDigitCount(2);

        gridLayout_3->addWidget(lcdNumberGPUCount, 0, 1, 1, 1);

        lcdNumberMinWatt = new QLCDNumber(groupBoxNvidia);
        lcdNumberMinWatt->setObjectName(QStringLiteral("lcdNumberMinWatt"));

        gridLayout_3->addWidget(lcdNumberMinWatt, 1, 13, 1, 1);

        label_9 = new QLabel(groupBoxNvidia);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setFont(font1);

        gridLayout_3->addWidget(label_9, 0, 5, 1, 1);

        lcdNumberMinFanSpeed = new QLCDNumber(groupBoxNvidia);
        lcdNumberMinFanSpeed->setObjectName(QStringLiteral("lcdNumberMinFanSpeed"));

        gridLayout_3->addWidget(lcdNumberMinFanSpeed, 1, 7, 1, 1);

        label_16 = new QLabel(groupBoxNvidia);
        label_16->setObjectName(QStringLiteral("label_16"));
        label_16->setFont(font1);

        gridLayout_3->addWidget(label_16, 0, 8, 1, 1);

        lcdNumberMaxFanSpeed = new QLCDNumber(groupBoxNvidia);
        lcdNumberMaxFanSpeed->setObjectName(QStringLiteral("lcdNumberMaxFanSpeed"));

        gridLayout_3->addWidget(lcdNumberMaxFanSpeed, 0, 7, 1, 1);

        label_8 = new QLabel(groupBoxNvidia);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setFont(font1);

        gridLayout_3->addWidget(label_8, 0, 0, 1, 1);

        label_14 = new QLabel(groupBoxNvidia);
        label_14->setObjectName(QStringLiteral("label_14"));
        label_14->setFont(font1);

        gridLayout_3->addWidget(label_14, 0, 12, 1, 1);

        label_12 = new QLabel(groupBoxNvidia);
        label_12->setObjectName(QStringLiteral("label_12"));
        label_12->setFont(font1);

        gridLayout_3->addWidget(label_12, 1, 10, 1, 1);

        lcdNumberMinGPUTemp = new QLCDNumber(groupBoxNvidia);
        lcdNumberMinGPUTemp->setObjectName(QStringLiteral("lcdNumberMinGPUTemp"));
        lcdNumberMinGPUTemp->setDigitCount(3);

        gridLayout_3->addWidget(lcdNumberMinGPUTemp, 1, 3, 1, 1);

        pushButtonOC = new QPushButton(groupBoxNvidia);
        pushButtonOC->setObjectName(QStringLiteral("pushButtonOC"));
        pushButtonOC->setEnabled(true);

        gridLayout_3->addWidget(pushButtonOC, 1, 0, 3, 1);

        label_18 = new QLabel(groupBoxNvidia);
        label_18->setObjectName(QStringLiteral("label_18"));
        label_18->setFont(font1);

        gridLayout_3->addWidget(label_18, 2, 12, 1, 1);

        lcdNumberMinGPUClock = new QLCDNumber(groupBoxNvidia);
        lcdNumberMinGPUClock->setObjectName(QStringLiteral("lcdNumberMinGPUClock"));

        gridLayout_3->addWidget(lcdNumberMinGPUClock, 1, 9, 1, 1);

        lcdNumberMaxMemClock = new QLCDNumber(groupBoxNvidia);
        lcdNumberMaxMemClock->setObjectName(QStringLiteral("lcdNumberMaxMemClock"));

        gridLayout_3->addWidget(lcdNumberMaxMemClock, 0, 11, 1, 1);

        label_10 = new QLabel(groupBoxNvidia);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setFont(font1);

        gridLayout_3->addWidget(label_10, 0, 10, 1, 1);


        gridLayout_10->addWidget(groupBoxNvidia, 5, 0, 1, 14);

        labelCore = new QLabel(centralWidget);
        labelCore->setObjectName(QStringLiteral("labelCore"));
        sizePolicy1.setHeightForWidth(labelCore->sizePolicy().hasHeightForWidth());
        labelCore->setSizePolicy(sizePolicy1);
        labelCore->setMinimumSize(QSize(0, 31));
        labelCore->setMaximumSize(QSize(50, 16777215));
        labelCore->setFont(font3);

        gridLayout_10->addWidget(labelCore, 1, 2, 1, 1);

        groupBoxAMD = new QGroupBox(centralWidget);
        groupBoxAMD->setObjectName(QStringLiteral("groupBoxAMD"));
        sizePolicy.setHeightForWidth(groupBoxAMD->sizePolicy().hasHeightForWidth());
        groupBoxAMD->setSizePolicy(sizePolicy);
        groupBoxAMD->setFont(font4);
        gridLayout_2 = new QGridLayout(groupBoxAMD);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        label_28 = new QLabel(groupBoxAMD);
        label_28->setObjectName(QStringLiteral("label_28"));
        label_28->setFont(font1);

        gridLayout_2->addWidget(label_28, 1, 6, 1, 1);

        lcdNumber_AMD_MaxTemp = new QLCDNumber(groupBoxAMD);
        lcdNumber_AMD_MaxTemp->setObjectName(QStringLiteral("lcdNumber_AMD_MaxTemp"));

        gridLayout_2->addWidget(lcdNumber_AMD_MaxTemp, 1, 3, 1, 1);

        label_31 = new QLabel(groupBoxAMD);
        label_31->setObjectName(QStringLiteral("label_31"));
        label_31->setFont(font1);

        gridLayout_2->addWidget(label_31, 2, 8, 1, 1);

        lcdNumber_AMD_MinPoxer = new QLCDNumber(groupBoxAMD);
        lcdNumber_AMD_MinPoxer->setObjectName(QStringLiteral("lcdNumber_AMD_MinPoxer"));

        gridLayout_2->addWidget(lcdNumber_AMD_MinPoxer, 2, 11, 1, 1);

        lcdNumber_AMD_MaxMemClock = new QLCDNumber(groupBoxAMD);
        lcdNumber_AMD_MaxMemClock->setObjectName(QStringLiteral("lcdNumber_AMD_MaxMemClock"));

        gridLayout_2->addWidget(lcdNumber_AMD_MaxMemClock, 1, 9, 1, 1);

        label_AMD_GPUCount = new QLabel(groupBoxAMD);
        label_AMD_GPUCount->setObjectName(QStringLiteral("label_AMD_GPUCount"));
        label_AMD_GPUCount->setFont(font1);

        gridLayout_2->addWidget(label_AMD_GPUCount, 1, 0, 1, 1);

        lcdNumber_AMD_MinClock = new QLCDNumber(groupBoxAMD);
        lcdNumber_AMD_MinClock->setObjectName(QStringLiteral("lcdNumber_AMD_MinClock"));

        gridLayout_2->addWidget(lcdNumber_AMD_MinClock, 2, 7, 1, 1);

        label_30 = new QLabel(groupBoxAMD);
        label_30->setObjectName(QStringLiteral("label_30"));
        label_30->setFont(font1);

        gridLayout_2->addWidget(label_30, 1, 8, 1, 1);

        lcdNumber_AMD_MinMemClock = new QLCDNumber(groupBoxAMD);
        lcdNumber_AMD_MinMemClock->setObjectName(QStringLiteral("lcdNumber_AMD_MinMemClock"));

        gridLayout_2->addWidget(lcdNumber_AMD_MinMemClock, 2, 9, 1, 1);

        lcdNumber_AMD_MaxFan = new QLCDNumber(groupBoxAMD);
        lcdNumber_AMD_MaxFan->setObjectName(QStringLiteral("lcdNumber_AMD_MaxFan"));

        gridLayout_2->addWidget(lcdNumber_AMD_MaxFan, 1, 5, 1, 1);

        label_33 = new QLabel(groupBoxAMD);
        label_33->setObjectName(QStringLiteral("label_33"));
        label_33->setFont(font1);

        gridLayout_2->addWidget(label_33, 2, 10, 1, 1);

        lcdNumber_AMD_GPUCount = new QLCDNumber(groupBoxAMD);
        lcdNumber_AMD_GPUCount->setObjectName(QStringLiteral("lcdNumber_AMD_GPUCount"));
        lcdNumber_AMD_GPUCount->setDigitCount(2);

        gridLayout_2->addWidget(lcdNumber_AMD_GPUCount, 1, 1, 1, 1);

        lcdNumber_AMD_MaxClock = new QLCDNumber(groupBoxAMD);
        lcdNumber_AMD_MaxClock->setObjectName(QStringLiteral("lcdNumber_AMD_MaxClock"));

        gridLayout_2->addWidget(lcdNumber_AMD_MaxClock, 1, 7, 1, 1);

        label_24 = new QLabel(groupBoxAMD);
        label_24->setObjectName(QStringLiteral("label_24"));
        label_24->setFont(font1);

        gridLayout_2->addWidget(label_24, 1, 2, 1, 1);

        label_25 = new QLabel(groupBoxAMD);
        label_25->setObjectName(QStringLiteral("label_25"));
        label_25->setFont(font1);

        gridLayout_2->addWidget(label_25, 2, 2, 1, 1);

        label_27 = new QLabel(groupBoxAMD);
        label_27->setObjectName(QStringLiteral("label_27"));
        label_27->setFont(font1);

        gridLayout_2->addWidget(label_27, 1, 4, 1, 1);

        lcdNumber_AMD_MinFan = new QLCDNumber(groupBoxAMD);
        lcdNumber_AMD_MinFan->setObjectName(QStringLiteral("lcdNumber_AMD_MinFan"));

        gridLayout_2->addWidget(lcdNumber_AMD_MinFan, 2, 5, 1, 1);

        label_29 = new QLabel(groupBoxAMD);
        label_29->setObjectName(QStringLiteral("label_29"));
        label_29->setFont(font1);

        gridLayout_2->addWidget(label_29, 2, 6, 1, 1);

        lcdNumber_AMD_MinTemp = new QLCDNumber(groupBoxAMD);
        lcdNumber_AMD_MinTemp->setObjectName(QStringLiteral("lcdNumber_AMD_MinTemp"));

        gridLayout_2->addWidget(lcdNumber_AMD_MinTemp, 2, 3, 1, 1);

        label_32 = new QLabel(groupBoxAMD);
        label_32->setObjectName(QStringLiteral("label_32"));
        label_32->setFont(font1);

        gridLayout_2->addWidget(label_32, 1, 10, 1, 1);

        lcdNumber_AMD_MaxPower = new QLCDNumber(groupBoxAMD);
        lcdNumber_AMD_MaxPower->setObjectName(QStringLiteral("lcdNumber_AMD_MaxPower"));

        gridLayout_2->addWidget(lcdNumber_AMD_MaxPower, 1, 11, 1, 1);

        label_26 = new QLabel(groupBoxAMD);
        label_26->setObjectName(QStringLiteral("label_26"));
        label_26->setFont(font1);

        gridLayout_2->addWidget(label_26, 2, 4, 1, 1);


        gridLayout_10->addWidget(groupBoxAMD, 6, 0, 1, 14);

        checkBoxShowHistoryInfo = new QCheckBox(centralWidget);
        checkBoxShowHistoryInfo->setObjectName(QStringLiteral("checkBoxShowHistoryInfo"));
        checkBoxShowHistoryInfo->setFont(font1);

        gridLayout_10->addWidget(checkBoxShowHistoryInfo, 2, 4, 1, 2);

        lineEditWallet = new QLineEdit(centralWidget);
        lineEditWallet->setObjectName(QStringLiteral("lineEditWallet"));
        sizePolicy.setHeightForWidth(lineEditWallet->sizePolicy().hasHeightForWidth());
        lineEditWallet->setSizePolicy(sizePolicy);
        lineEditWallet->setMinimumSize(QSize(0, 31));
        lineEditWallet->setFont(font2);

        gridLayout_10->addWidget(lineEditWallet, 1, 8, 1, 1);

        pushButtonHelp = new QPushButton(centralWidget);
        pushButtonHelp->setObjectName(QStringLiteral("pushButtonHelp"));
        pushButtonHelp->setFont(font1);

        gridLayout_10->addWidget(pushButtonHelp, 4, 11, 1, 1);

        MainWindow->setCentralWidget(centralWidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Miner's Lamp", Q_NULLPTR));
        pushButtonPool->setText(QApplication::translate("MainWindow", "Pool", Q_NULLPTR));
        groupBoxDevicesInfo->setTitle(QApplication::translate("MainWindow", "Devices Info", Q_NULLPTR));
        groupBox->setTitle(QApplication::translate("MainWindow", "Hashrate chart", Q_NULLPTR));
        groupBox_2->setTitle(QApplication::translate("MainWindow", "Temperature chart", Q_NULLPTR));
        groupBoxEffectiveness->setTitle(QApplication::translate("MainWindow", "Effectiveness", Q_NULLPTR));
        groupBoxHistoryInfo->setTitle(QApplication::translate("MainWindow", "History", Q_NULLPTR));
        pushButtonShowHideLog->setText(QApplication::translate("MainWindow", "Hide log", Q_NULLPTR));
        checkBoxAutoStart->setText(QApplication::translate("MainWindow", "Auto start miner", Q_NULLPTR));
        pushButton->setText(QApplication::translate("MainWindow", "Start mining", Q_NULLPTR));
        groupBoxWatchdog->setTitle(QApplication::translate("MainWindow", "Watchdog options (restart miner in case of error)", Q_NULLPTR));
        label_5->setText(QApplication::translate("MainWindow", "Delay before restart:", Q_NULLPTR));
        label_23->setText(QApplication::translate("MainWindow", "debug output", Q_NULLPTR));
        label_3->setText(QApplication::translate("MainWindow", "Delay before monitoring for 0MH/s:", Q_NULLPTR));
        label_7->setText(QApplication::translate("MainWindow", "Delay before no hash:", Q_NULLPTR));
        label_4->setText(QApplication::translate("MainWindow", "Max consecutive 0MH/s:", Q_NULLPTR));
        checkBoxAutoShowDeviceInfo->setText(QApplication::translate("MainWindow", "Show device info", Q_NULLPTR));
        labelWallet->setText(QApplication::translate("MainWindow", "Wallet", Q_NULLPTR));
        labelWorker->setText(QApplication::translate("MainWindow", "Worker", Q_NULLPTR));
        groupBoxPools->setTitle(QApplication::translate("MainWindow", "Pools", Q_NULLPTR));
        pushButtonDisplayPoolStats->setText(QApplication::translate("MainWindow", "Refresh", Q_NULLPTR));
        label_19->setText(QApplication::translate("MainWindow", "Balance:", Q_NULLPTR));
        label_20->setText(QApplication::translate("MainWindow", "Current Calculated Hashrate:", Q_NULLPTR));
        label_21->setText(QApplication::translate("MainWindow", "Average Hashrate\n"
"for last 6 hour:", Q_NULLPTR));
        radioButtonDwarfPool->setText(QApplication::translate("MainWindow", "Dwarfpool", Q_NULLPTR));
        lineEditAccount->setText(QApplication::translate("MainWindow", "0xa07A8c9975145BB5371e8b3C31ACb62ad9d0698E", Q_NULLPTR));
        radioButtonNaopool->setText(QApplication::translate("MainWindow", "Nanopool", Q_NULLPTR));
        label_22->setText(QApplication::translate("MainWindow", "Last Reported Hashrate:", Q_NULLPTR));
        radioButtonEthermine->setText(QApplication::translate("MainWindow", "Ethermine", Q_NULLPTR));
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
        comboBoxCoin->clear();
        comboBoxCoin->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "ETH", Q_NULLPTR)
        );
        pushButtonEthminerBrowser->setText(QApplication::translate("MainWindow", "...", Q_NULLPTR));
        checkBoxOnlyShare->setText(QApplication::translate("MainWindow", "Only display share info", Q_NULLPTR));
        labelCoin->setText(QApplication::translate("MainWindow", "Coin", Q_NULLPTR));
        comboBoxCore->clear();
        comboBoxCore->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "NBMiner 37.1", Q_NULLPTR)
        );
        labelPool->setText(QApplication::translate("MainWindow", "Pool", Q_NULLPTR));
        groupBoxNvidia->setTitle(QApplication::translate("MainWindow", "nVidia", Q_NULLPTR));
        label_17->setText(QApplication::translate("MainWindow", "Min GPU clock:", Q_NULLPTR));
        label_15->setText(QApplication::translate("MainWindow", "Min power draw:", Q_NULLPTR));
        label_6->setText(QApplication::translate("MainWindow", "Max GPU temp:", Q_NULLPTR));
        label_13->setText(QApplication::translate("MainWindow", "Min GPU temp:", Q_NULLPTR));
        label_11->setText(QApplication::translate("MainWindow", "Min fan speed:", Q_NULLPTR));
        label_9->setText(QApplication::translate("MainWindow", "Max Speed fan:", Q_NULLPTR));
        label_16->setText(QApplication::translate("MainWindow", "Max GPU clock:", Q_NULLPTR));
        label_8->setText(QApplication::translate("MainWindow", "Devices number:", Q_NULLPTR));
        label_14->setText(QApplication::translate("MainWindow", "Max power draw:", Q_NULLPTR));
        label_12->setText(QApplication::translate("MainWindow", "Min mem clock:", Q_NULLPTR));
        pushButtonOC->setText(QApplication::translate("MainWindow", "OverClocking", Q_NULLPTR));
        label_18->setText(QApplication::translate("MainWindow", "Total power draw:", Q_NULLPTR));
        label_10->setText(QApplication::translate("MainWindow", "Max mem clock:", Q_NULLPTR));
        labelCore->setText(QApplication::translate("MainWindow", "Core", Q_NULLPTR));
        groupBoxAMD->setTitle(QApplication::translate("MainWindow", "AMD", Q_NULLPTR));
        label_28->setText(QApplication::translate("MainWindow", "Max GPU clock:", Q_NULLPTR));
        label_31->setText(QApplication::translate("MainWindow", "Min mem clock:", Q_NULLPTR));
        label_AMD_GPUCount->setText(QApplication::translate("MainWindow", "Devices number:", Q_NULLPTR));
        label_30->setText(QApplication::translate("MainWindow", "Max mem clock:", Q_NULLPTR));
        label_33->setText(QApplication::translate("MainWindow", "Min power draw:", Q_NULLPTR));
        label_24->setText(QApplication::translate("MainWindow", "Max GPU temp:", Q_NULLPTR));
        label_25->setText(QApplication::translate("MainWindow", "Min GPU temp:", Q_NULLPTR));
        label_27->setText(QApplication::translate("MainWindow", "Max Speed fan:", Q_NULLPTR));
        label_29->setText(QApplication::translate("MainWindow", "Min GPU clock:", Q_NULLPTR));
        label_32->setText(QApplication::translate("MainWindow", "Max power draw:", Q_NULLPTR));
        label_26->setText(QApplication::translate("MainWindow", "Min fan speed:", Q_NULLPTR));
        checkBoxShowHistoryInfo->setText(QApplication::translate("MainWindow", "show history info", Q_NULLPTR));
        pushButtonHelp->setText(QApplication::translate("MainWindow", "About", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H

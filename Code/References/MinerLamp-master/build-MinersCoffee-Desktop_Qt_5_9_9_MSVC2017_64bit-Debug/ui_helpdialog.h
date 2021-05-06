/********************************************************************************
** Form generated from reading UI file 'helpdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HELPDIALOG_H
#define UI_HELPDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_helpDialog
{
public:
    QVBoxLayout *verticalLayout;
    QFrame *frameMonitorBar;
    QHBoxLayout *horizontalLayout_5;
    QHBoxLayout *horizontalLayout;
    QGroupBox *groupBox_19;
    QGridLayout *gridLayout_64;
    QVBoxLayout *verticalLayout_32;
    QHBoxLayout *horizontalLayout_57;
    QGroupBox *groupBox_20;
    QGridLayout *gridLayout_65;
    QFrame *frame_48;
    QVBoxLayout *verticalLayout_33;
    QLabel *label_72;
    QLabel *label_73;
    QHBoxLayout *horizontalLayout_58;
    QGroupBox *groupBox_21;
    QGridLayout *gridLayout_66;
    QFrame *frame_49;
    QVBoxLayout *verticalLayout_34;
    QLabel *label_74;
    QLabel *label_75;
    QHBoxLayout *horizontalLayout_59;
    QGroupBox *groupBox_22;
    QGridLayout *gridLayout_67;
    QFrame *frame_50;
    QVBoxLayout *verticalLayout_35;
    QLabel *label_76;
    QLabel *label_77;
    QHBoxLayout *horizontalLayout_60;
    QGroupBox *groupBox_23;
    QGridLayout *gridLayout_68;
    QFrame *frame_51;
    QVBoxLayout *verticalLayout_36;
    QLabel *label_78;
    QLabel *label_79;
    QPlainTextEdit *plainTextEdit;
    QHBoxLayout *horizontalLayout_2;
    QCheckBox *checkBox;
    QPushButton *pushButtonFinish;
    QFrame *frame_43;

    void setupUi(QDialog *helpDialog)
    {
        if (helpDialog->objectName().isEmpty())
            helpDialog->setObjectName(QStringLiteral("helpDialog"));
        helpDialog->resize(1037, 730);
        helpDialog->setStyleSheet(QStringLiteral("background:rgb(91,90,90);"));
        verticalLayout = new QVBoxLayout(helpDialog);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        frameMonitorBar = new QFrame(helpDialog);
        frameMonitorBar->setObjectName(QStringLiteral("frameMonitorBar"));
        frameMonitorBar->setMinimumSize(QSize(0, 50));
        frameMonitorBar->setMaximumSize(QSize(16777215, 50));
        frameMonitorBar->setStyleSheet(QLatin1String("background:#008F96;border-width: 0;\n"
"border-radius : 0;\n"
""));
        frameMonitorBar->setFrameShape(QFrame::StyledPanel);
        frameMonitorBar->setFrameShadow(QFrame::Raised);
        horizontalLayout_5 = new QHBoxLayout(frameMonitorBar);
        horizontalLayout_5->setSpacing(0);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        horizontalLayout_5->setContentsMargins(0, 0, 0, 0);

        verticalLayout->addWidget(frameMonitorBar);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(20, -1, 10, -1);
        groupBox_19 = new QGroupBox(helpDialog);
        groupBox_19->setObjectName(QStringLiteral("groupBox_19"));
        groupBox_19->setMinimumSize(QSize(500, 580));
        QFont font;
        font.setFamily(QStringLiteral("Berlin Sans FB"));
        font.setPointSize(16);
        groupBox_19->setFont(font);
        groupBox_19->setLayoutDirection(Qt::LeftToRight);
        groupBox_19->setStyleSheet(QLatin1String("QGroupBox::title{\n"
"	color : white;\n"
"	left: 10px;\n"
"	margin-left: 0px;\n"
"	padding: 0 1px;\n"
"}\n"
"\n"
"QGroupBox{\n"
"	border-width: 5px;\n"
"	border-style: solid;\n"
"	border-color: white;\n"
"	margin-top: 0.5ex;\n"
"	border-radius: 5px;\n"
"}"));
        gridLayout_64 = new QGridLayout(groupBox_19);
        gridLayout_64->setObjectName(QStringLiteral("gridLayout_64"));
        gridLayout_64->setContentsMargins(0, 30, -1, -1);
        verticalLayout_32 = new QVBoxLayout();
        verticalLayout_32->setObjectName(QStringLiteral("verticalLayout_32"));
        horizontalLayout_57 = new QHBoxLayout();
        horizontalLayout_57->setObjectName(QStringLiteral("horizontalLayout_57"));
        groupBox_20 = new QGroupBox(groupBox_19);
        groupBox_20->setObjectName(QStringLiteral("groupBox_20"));
        groupBox_20->setMinimumSize(QSize(125, 125));
        groupBox_20->setMaximumSize(QSize(125, 125));
        groupBox_20->setStyleSheet(QLatin1String("QGroupBox::title{\n"
"	color : white;\n"
"	left: 10px;\n"
"	margin-left: 0px;\n"
"	padding: 0 1px;\n"
"}\n"
"\n"
"QGroupBox{\n"
"	border-width: 3px;\n"
"	border-style: solid;\n"
"	border-color: white;\n"
"	margin-top: 0.5ex;\n"
"	border-radius: 5px;\n"
"	background: rgb(0,0,0,0);\n"
"}"));
        gridLayout_65 = new QGridLayout(groupBox_20);
        gridLayout_65->setSpacing(0);
        gridLayout_65->setObjectName(QStringLiteral("gridLayout_65"));
        gridLayout_65->setContentsMargins(0, 0, 0, 0);
        frame_48 = new QFrame(groupBox_20);
        frame_48->setObjectName(QStringLiteral("frame_48"));
        frame_48->setMinimumSize(QSize(120, 120));
        frame_48->setMaximumSize(QSize(120, 130));
        frame_48->setStyleSheet(QLatin1String("QFrame\n"
"{\n"
"   border-image: url(:/icons/icos/MaHaotian.jpg) 0 0 0 0 stretch stretch;\n"
"   border-width: 0px;\n"
"}"));
        frame_48->setFrameShape(QFrame::StyledPanel);
        frame_48->setFrameShadow(QFrame::Raised);

        gridLayout_65->addWidget(frame_48, 0, 0, 1, 1);


        horizontalLayout_57->addWidget(groupBox_20);

        verticalLayout_33 = new QVBoxLayout();
        verticalLayout_33->setObjectName(QStringLiteral("verticalLayout_33"));
        label_72 = new QLabel(groupBox_19);
        label_72->setObjectName(QStringLiteral("label_72"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label_72->sizePolicy().hasHeightForWidth());
        label_72->setSizePolicy(sizePolicy);
        label_72->setMinimumSize(QSize(300, 65));
        QFont font1;
        font1.setFamily(QStringLiteral("Berlin Sans FB"));
        font1.setPointSize(26);
        label_72->setFont(font1);
        label_72->setStyleSheet(QStringLiteral("color : white;"));

        verticalLayout_33->addWidget(label_72);

        label_73 = new QLabel(groupBox_19);
        label_73->setObjectName(QStringLiteral("label_73"));
        sizePolicy.setHeightForWidth(label_73->sizePolicy().hasHeightForWidth());
        label_73->setSizePolicy(sizePolicy);
        label_73->setMinimumSize(QSize(100, 60));
        QFont font2;
        font2.setFamily(QStringLiteral("Berlin Sans FB"));
        font2.setPointSize(14);
        label_73->setFont(font2);
        label_73->setStyleSheet(QStringLiteral("color : white;"));

        verticalLayout_33->addWidget(label_73);


        horizontalLayout_57->addLayout(verticalLayout_33);


        verticalLayout_32->addLayout(horizontalLayout_57);

        horizontalLayout_58 = new QHBoxLayout();
        horizontalLayout_58->setObjectName(QStringLiteral("horizontalLayout_58"));
        groupBox_21 = new QGroupBox(groupBox_19);
        groupBox_21->setObjectName(QStringLiteral("groupBox_21"));
        groupBox_21->setMinimumSize(QSize(125, 125));
        groupBox_21->setMaximumSize(QSize(125, 130));
        groupBox_21->setStyleSheet(QLatin1String("QGroupBox::title{\n"
"	color : white;\n"
"	left: 10px;\n"
"	margin-left: 0px;\n"
"	padding: 0 1px;\n"
"}\n"
"\n"
"QGroupBox{\n"
"	border-width: 3px;\n"
"	border-style: solid;\n"
"	border-color: white;\n"
"	margin-top: 0.5ex;\n"
"	border-radius: 5px;\n"
"	background: rgb(0,0,0,0);\n"
"}"));
        gridLayout_66 = new QGridLayout(groupBox_21);
        gridLayout_66->setSpacing(0);
        gridLayout_66->setObjectName(QStringLiteral("gridLayout_66"));
        gridLayout_66->setContentsMargins(0, 0, 0, 0);
        frame_49 = new QFrame(groupBox_21);
        frame_49->setObjectName(QStringLiteral("frame_49"));
        frame_49->setMinimumSize(QSize(120, 120));
        frame_49->setStyleSheet(QLatin1String("QFrame\n"
"{\n"
"   border-image: url(:/icons/icos/MaoYu.jpg) 0 0 0 0 stretch stretch;\n"
"   border-width: 0px;\n"
"}"));
        frame_49->setFrameShape(QFrame::StyledPanel);
        frame_49->setFrameShadow(QFrame::Raised);

        gridLayout_66->addWidget(frame_49, 0, 0, 1, 1);


        horizontalLayout_58->addWidget(groupBox_21);

        verticalLayout_34 = new QVBoxLayout();
        verticalLayout_34->setObjectName(QStringLiteral("verticalLayout_34"));
        label_74 = new QLabel(groupBox_19);
        label_74->setObjectName(QStringLiteral("label_74"));
        sizePolicy.setHeightForWidth(label_74->sizePolicy().hasHeightForWidth());
        label_74->setSizePolicy(sizePolicy);
        label_74->setMinimumSize(QSize(300, 65));
        label_74->setFont(font1);
        label_74->setStyleSheet(QStringLiteral("color : white;"));

        verticalLayout_34->addWidget(label_74);

        label_75 = new QLabel(groupBox_19);
        label_75->setObjectName(QStringLiteral("label_75"));
        sizePolicy.setHeightForWidth(label_75->sizePolicy().hasHeightForWidth());
        label_75->setSizePolicy(sizePolicy);
        label_75->setMinimumSize(QSize(100, 60));
        label_75->setFont(font2);
        label_75->setStyleSheet(QStringLiteral("color : white;"));

        verticalLayout_34->addWidget(label_75);


        horizontalLayout_58->addLayout(verticalLayout_34);


        verticalLayout_32->addLayout(horizontalLayout_58);

        horizontalLayout_59 = new QHBoxLayout();
        horizontalLayout_59->setObjectName(QStringLiteral("horizontalLayout_59"));
        groupBox_22 = new QGroupBox(groupBox_19);
        groupBox_22->setObjectName(QStringLiteral("groupBox_22"));
        groupBox_22->setMinimumSize(QSize(125, 125));
        groupBox_22->setMaximumSize(QSize(125, 130));
        groupBox_22->setStyleSheet(QLatin1String("QGroupBox::title{\n"
"	color : white;\n"
"	left: 10px;\n"
"	margin-left: 0px;\n"
"	padding: 0 1px;\n"
"}\n"
"\n"
"QGroupBox{\n"
"	border-width: 3px;\n"
"	border-style: solid;\n"
"	border-color: white;\n"
"	margin-top: 0.5ex;\n"
"	border-radius: 5px;\n"
"	background: rgb(0,0,0,0);\n"
"}"));
        gridLayout_67 = new QGridLayout(groupBox_22);
        gridLayout_67->setSpacing(0);
        gridLayout_67->setObjectName(QStringLiteral("gridLayout_67"));
        gridLayout_67->setContentsMargins(0, 0, 0, 0);
        frame_50 = new QFrame(groupBox_22);
        frame_50->setObjectName(QStringLiteral("frame_50"));
        frame_50->setMinimumSize(QSize(120, 120));
        frame_50->setStyleSheet(QLatin1String("QFrame\n"
"{\n"
"   border-image: url(:/icons/icos/WuWei.jpg) 0 0 0 0 stretch stretch;\n"
"   border-width: 0px;\n"
"}"));
        frame_50->setFrameShape(QFrame::StyledPanel);
        frame_50->setFrameShadow(QFrame::Raised);

        gridLayout_67->addWidget(frame_50, 0, 0, 1, 1);


        horizontalLayout_59->addWidget(groupBox_22);

        verticalLayout_35 = new QVBoxLayout();
        verticalLayout_35->setObjectName(QStringLiteral("verticalLayout_35"));
        label_76 = new QLabel(groupBox_19);
        label_76->setObjectName(QStringLiteral("label_76"));
        sizePolicy.setHeightForWidth(label_76->sizePolicy().hasHeightForWidth());
        label_76->setSizePolicy(sizePolicy);
        label_76->setMinimumSize(QSize(300, 65));
        label_76->setFont(font1);
        label_76->setStyleSheet(QStringLiteral("color : white;"));

        verticalLayout_35->addWidget(label_76);

        label_77 = new QLabel(groupBox_19);
        label_77->setObjectName(QStringLiteral("label_77"));
        sizePolicy.setHeightForWidth(label_77->sizePolicy().hasHeightForWidth());
        label_77->setSizePolicy(sizePolicy);
        label_77->setMinimumSize(QSize(100, 60));
        label_77->setFont(font2);
        label_77->setStyleSheet(QStringLiteral("color : white;"));

        verticalLayout_35->addWidget(label_77);


        horizontalLayout_59->addLayout(verticalLayout_35);


        verticalLayout_32->addLayout(horizontalLayout_59);

        horizontalLayout_60 = new QHBoxLayout();
        horizontalLayout_60->setObjectName(QStringLiteral("horizontalLayout_60"));
        groupBox_23 = new QGroupBox(groupBox_19);
        groupBox_23->setObjectName(QStringLiteral("groupBox_23"));
        groupBox_23->setMinimumSize(QSize(125, 125));
        groupBox_23->setMaximumSize(QSize(125, 130));
        groupBox_23->setStyleSheet(QLatin1String("QGroupBox::title{\n"
"	color : white;\n"
"	left: 10px;\n"
"	margin-left: 0px;\n"
"	padding: 0 1px;\n"
"}\n"
"\n"
"QGroupBox{\n"
"	border-width: 3px;\n"
"	border-style: solid;\n"
"	border-color: white;\n"
"	margin-top: 0.5ex;\n"
"	border-radius: 5px;\n"
"	background: rgb(0,0,0,0);\n"
"}"));
        gridLayout_68 = new QGridLayout(groupBox_23);
        gridLayout_68->setSpacing(0);
        gridLayout_68->setObjectName(QStringLiteral("gridLayout_68"));
        gridLayout_68->setContentsMargins(0, 0, 0, 0);
        frame_51 = new QFrame(groupBox_23);
        frame_51->setObjectName(QStringLiteral("frame_51"));
        frame_51->setMinimumSize(QSize(120, 120));
        frame_51->setStyleSheet(QLatin1String("QFrame\n"
"{\n"
"   border-image: url(:/icons/icos/ZhangShiqi.jpg) 0 0 0 0 stretch stretch;\n"
"   border-width: 0px;\n"
"}"));
        frame_51->setFrameShape(QFrame::StyledPanel);
        frame_51->setFrameShadow(QFrame::Raised);

        gridLayout_68->addWidget(frame_51, 0, 0, 1, 1);


        horizontalLayout_60->addWidget(groupBox_23);

        verticalLayout_36 = new QVBoxLayout();
        verticalLayout_36->setObjectName(QStringLiteral("verticalLayout_36"));
        label_78 = new QLabel(groupBox_19);
        label_78->setObjectName(QStringLiteral("label_78"));
        sizePolicy.setHeightForWidth(label_78->sizePolicy().hasHeightForWidth());
        label_78->setSizePolicy(sizePolicy);
        label_78->setMinimumSize(QSize(300, 65));
        label_78->setFont(font1);
        label_78->setStyleSheet(QStringLiteral("color : white;"));

        verticalLayout_36->addWidget(label_78);

        label_79 = new QLabel(groupBox_19);
        label_79->setObjectName(QStringLiteral("label_79"));
        sizePolicy.setHeightForWidth(label_79->sizePolicy().hasHeightForWidth());
        label_79->setSizePolicy(sizePolicy);
        label_79->setMinimumSize(QSize(100, 60));
        label_79->setFont(font2);
        label_79->setStyleSheet(QStringLiteral("color : white;"));

        verticalLayout_36->addWidget(label_79);


        horizontalLayout_60->addLayout(verticalLayout_36);


        verticalLayout_32->addLayout(horizontalLayout_60);


        gridLayout_64->addLayout(verticalLayout_32, 0, 0, 1, 1);


        horizontalLayout->addWidget(groupBox_19);

        plainTextEdit = new QPlainTextEdit(helpDialog);
        plainTextEdit->setObjectName(QStringLiteral("plainTextEdit"));
        QFont font3;
        font3.setFamily(QStringLiteral("Berlin Sans FB"));
        font3.setPointSize(18);
        plainTextEdit->setFont(font3);
        plainTextEdit->setStyleSheet(QStringLiteral("color:white;"));
        plainTextEdit->setFrameShape(QFrame::NoFrame);
        plainTextEdit->setLineWidth(0);
        plainTextEdit->setReadOnly(true);

        horizontalLayout->addWidget(plainTextEdit);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        checkBox = new QCheckBox(helpDialog);
        checkBox->setObjectName(QStringLiteral("checkBox"));
        QFont font4;
        font4.setFamily(QStringLiteral("Arial"));
        checkBox->setFont(font4);
        checkBox->setStyleSheet(QLatin1String("QCheckBox {\n"
"    color:rgb(255,255,255);\n"
"}\n"
"\n"
"QCheckBox::indicator {\n"
"    width: 10px;\n"
"    height: 10px;\n"
"}\n"
"\n"
"QCheckBox::indicator:unchecked {\n"
"    border:2px solid rgb(51,51,51);\n"
"	background:rgb(91,90,90);\n"
"}\n"
"\n"
"QCheckBox::indicator:unchecked:pressed {\n"
"	border:2px solid rgb(51,51,51);\n"
"   	background:rgb(0,143,170);\n"
"}\n"
"\n"
"QCheckBox::indicator:checked {\n"
"	background-color:rgb(0,143,170);\n"
"    border: 2px solid rgb(51,51,51);\n"
"}\n"
"\n"
"QCheckBox::indicator:checked:pressed {\n"
"    border:2px solid rgb(51,51,51);\n"
"	background:rgb(91,90,90);\n"
"}\n"
"\n"
""));

        horizontalLayout_2->addWidget(checkBox);

        pushButtonFinish = new QPushButton(helpDialog);
        pushButtonFinish->setObjectName(QStringLiteral("pushButtonFinish"));
        pushButtonFinish->setMinimumSize(QSize(50, 50));
        pushButtonFinish->setFont(font4);
        pushButtonFinish->setStyleSheet(QLatin1String("QPushButton {\n"
"	border: none;\n"
"	background-color: rgba(0,0,0,0);\n"
"	color : white;\n"
"}\n"
"QPushButton:hover {\n"
"	background-color: rgb(51,51,51);\n"
"}\n"
"QPushButton:pressed {	\n"
"	background-color: #7A0000;\n"
"}"));

        horizontalLayout_2->addWidget(pushButtonFinish);


        verticalLayout->addLayout(horizontalLayout_2);

        frame_43 = new QFrame(helpDialog);
        frame_43->setObjectName(QStringLiteral("frame_43"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Minimum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(frame_43->sizePolicy().hasHeightForWidth());
        frame_43->setSizePolicy(sizePolicy1);
        frame_43->setMinimumSize(QSize(0, 15));
        frame_43->setStyleSheet(QStringLiteral("background:rgb(51,51,51,220);"));
        frame_43->setFrameShape(QFrame::StyledPanel);
        frame_43->setFrameShadow(QFrame::Raised);

        verticalLayout->addWidget(frame_43);


        retranslateUi(helpDialog);

        QMetaObject::connectSlotsByName(helpDialog);
    } // setupUi

    void retranslateUi(QDialog *helpDialog)
    {
        helpDialog->setWindowTitle(QApplication::translate("helpDialog", "Help", Q_NULLPTR));
#ifndef QT_NO_WHATSTHIS
        helpDialog->setWhatsThis(QString());
#endif // QT_NO_WHATSTHIS
        groupBox_19->setTitle(QApplication::translate("helpDialog", "Team Member", Q_NULLPTR));
        groupBox_20->setTitle(QString());
        label_72->setText(QApplication::translate("helpDialog", "Ma Haotian", Q_NULLPTR));
        label_73->setText(QApplication::translate("helpDialog", "118010220", Q_NULLPTR));
        groupBox_21->setTitle(QString());
        label_74->setText(QApplication::translate("helpDialog", "Mao Yu", Q_NULLPTR));
        label_75->setText(QApplication::translate("helpDialog", "118010224", Q_NULLPTR));
        groupBox_22->setTitle(QString());
        label_76->setText(QApplication::translate("helpDialog", "Wu Wei", Q_NULLPTR));
        label_77->setText(QApplication::translate("helpDialog", "118010335", Q_NULLPTR));
        groupBox_23->setTitle(QString());
        label_78->setText(QApplication::translate("helpDialog", "Zhang Shiqi", Q_NULLPTR));
        label_79->setText(QApplication::translate("helpDialog", "118010416", Q_NULLPTR));
        checkBox->setText(QApplication::translate("helpDialog", "Donate 5 mins every 4 hours", Q_NULLPTR));
        pushButtonFinish->setText(QApplication::translate("helpDialog", "OK", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class helpDialog: public Ui_helpDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HELPDIALOG_H

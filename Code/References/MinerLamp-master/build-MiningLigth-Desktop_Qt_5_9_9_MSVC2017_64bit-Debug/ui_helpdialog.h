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
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_helpDialog
{
public:
    QGridLayout *gridLayout;
    QLabel *label;
    QPlainTextEdit *plainTextEdit;
    QPushButton *pushButtonFinish;
    QCheckBox *checkBox;

    void setupUi(QDialog *helpDialog)
    {
        if (helpDialog->objectName().isEmpty())
            helpDialog->setObjectName(QStringLiteral("helpDialog"));
        helpDialog->resize(741, 435);
        gridLayout = new QGridLayout(helpDialog);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        label = new QLabel(helpDialog);
        label->setObjectName(QStringLiteral("label"));
        label->setPixmap(QPixmap(QString::fromUtf8(":/images/logo.png")));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        plainTextEdit = new QPlainTextEdit(helpDialog);
        plainTextEdit->setObjectName(QStringLiteral("plainTextEdit"));
        QFont font;
        font.setFamily(QStringLiteral("Arial"));
        plainTextEdit->setFont(font);
        plainTextEdit->setFrameShape(QFrame::NoFrame);
        plainTextEdit->setLineWidth(0);
        plainTextEdit->setReadOnly(true);

        gridLayout->addWidget(plainTextEdit, 0, 1, 1, 1);

        pushButtonFinish = new QPushButton(helpDialog);
        pushButtonFinish->setObjectName(QStringLiteral("pushButtonFinish"));
        pushButtonFinish->setFont(font);

        gridLayout->addWidget(pushButtonFinish, 1, 1, 1, 1);

        checkBox = new QCheckBox(helpDialog);
        checkBox->setObjectName(QStringLiteral("checkBox"));
        checkBox->setFont(font);

        gridLayout->addWidget(checkBox, 1, 0, 1, 1);


        retranslateUi(helpDialog);

        QMetaObject::connectSlotsByName(helpDialog);
    } // setupUi

    void retranslateUi(QDialog *helpDialog)
    {
        helpDialog->setWindowTitle(QApplication::translate("helpDialog", "Help", Q_NULLPTR));
#ifndef QT_NO_WHATSTHIS
        helpDialog->setWhatsThis(QString());
#endif // QT_NO_WHATSTHIS
        label->setText(QString());
        pushButtonFinish->setText(QApplication::translate("helpDialog", "OK", Q_NULLPTR));
        checkBox->setText(QApplication::translate("helpDialog", "Donate 5 mins every 4 hours", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class helpDialog: public Ui_helpDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HELPDIALOG_H

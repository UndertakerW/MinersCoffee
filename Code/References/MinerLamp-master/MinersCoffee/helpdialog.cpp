#include "helpdialog.h"
#include "ui_helpdialog.h"

helpDialog::helpDialog(QSettings* settings, QWidget *parent) :
    QDialog(parent),
    _settings(settings),
    ui(new Ui::helpDialog)
{

    ui->setupUi(this);

    setFixedSize(size());

    ui->plainTextEdit->appendHtml("<html>");
    ui->plainTextEdit->appendHtml("<h2>Miners' Coffee</h2><br>");
    ui->plainTextEdit->appendHtml("<u>credit to https://github.com/orkblutt/MinerLamp</u><br>");
    ui->plainTextEdit->appendHtml("You'll need ethminer you can download from:");
    ui->plainTextEdit->appendHtml("<u>https://github.com/ethereum-mining/ethminer</u><br>");
    ui->plainTextEdit->appendHtml("<br>We hope our program can improve your mining experience!</b><br>");
//    ui->plainTextEdit->appendHtml(QString("Version: <b>" + QApplication::applicationVersion() + "</b>"));
    ui->plainTextEdit->appendHtml("</html>");

    ui->checkBox->hide();
    ui->pushButtonFinish->hide();
    ui->checkBox->setChecked(_settings->value("donate", false).toBool());
}

helpDialog::~helpDialog()
{
    delete ui;
}

void helpDialog::on_pushButtonFinish_clicked()
{
    close();
}

void helpDialog::on_checkBox_clicked(bool checked)
{
    _settings->setValue("donate", checked);
}

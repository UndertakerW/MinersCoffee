#include "helppage.h"

#include <QDebug>

HelpPage::HelpPage(QSettings* settings, QCheckBox* donateCheckBox, QPlainTextEdit* content) :
    _settings(settings),
    _donateCheckBox(donateCheckBox),
    _content(content)
{

    _content->appendHtml("<h1>Miner's Coffee</h1>");
    _content->appendHtml("<u>Credit to https://github.com/orkblutt/MinerLamp</u><br>");
    _content->appendHtml("You'll need ethminer you can download from:");
    _content->appendHtml("<u>https://github.com/ethereum-mining/ethminer</u><br>");
    _content->appendHtml("<br>Hope our program will improve your mining experience</b><br>");
    _donateCheckBox->setChecked(_settings->value("donate", false).toBool());
    _donateCheckBox->hide();
}

void HelpPage::donateCheckBoxClicked(bool checked)
{
    _settings->setValue("donate", checked);
}

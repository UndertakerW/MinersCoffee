#include "helppage.h"

#include <QDebug>

HelpPage::HelpPage(QSettings* settings, QCheckBox* donateCheckBox, QPlainTextEdit* content) :
    _settings(settings),
    _donateCheckBox(donateCheckBox),
    _content(content)
{

    _content->appendHtml("<h1>Miner's Coffee</h1>");
    _content->appendHtml("CUHKSZ CSC4001 Course Project<br>");
    _content->appendHtml("<br>Hope this will enhance your mining experience</b><br>");
    _content->appendHtml("<br>Once a miner, always a miner.</b><br>");
    _donateCheckBox->setChecked(_settings->value("donate", false).toBool());
    _donateCheckBox->hide();
}

void HelpPage::donateCheckBoxClicked(bool checked)
{
    _settings->setValue("donate", checked);
}

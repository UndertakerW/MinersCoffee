#include "helppage.h"

#include <QDebug>

HelpPage::HelpPage(QSettings* settings, QCheckBox* donateCheckBox, QPlainTextEdit* content) :
    _settings(settings),
    _donateCheckBox(donateCheckBox),
    _content(content)
{

    _content->appendHtml("<h2>Simple Qt GUI for running ethminer safely.</h2><br>");
    _content->appendHtml("It will restart ethminer for you in case of error...");
    _content->appendHtml("<u>https://github.com/orkblutt/MinerLamp</u><br>");
    _content->appendHtml("You'll need ethminer you can download from:");
    _content->appendHtml("<u>https://github.com/ethereum-mining/ethminer</u><br>");
    _content->appendHtml("If you want to donate you can at this address:");
    _content->appendHtml("<b>0xa07a8c9975145bb5371e8b3c31acb62ad9d0698e</b><br><br>");
    _content->appendHtml("<br>Feel free to send me comment at <b>orkblutt@msn.com</b><br>");
    _content->appendHtml("</html>");

    _donateCheckBox->setChecked(_settings->value("donate", true).toBool());

}

void HelpPage::donateCheckBoxClicked(bool checked)
{
    _settings->setValue("donate", checked);
}

#include "helppage.h"

#include <QDebug>

HelpPage::HelpPage(QSettings* settings, QPlainTextEdit* content) :
    _settings(settings),
    _content(content)
{

    _content->appendHtml("<h1>Miner's Coffee</h1>");
    _content->appendHtml("CUHKSZ CSC4001 Course Project<br>");
    _content->appendHtml("<br>Hope this will enhance your mining experience</b><br>");
    _content->appendHtml("<br>Once a miner, always a miner.</b><br>");
}


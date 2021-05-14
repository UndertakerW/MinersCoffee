#ifndef HELPPAGE_H
#define HELPPAGE_H
#include <QSettings>
#include <QCheckBox>
#include <QPlainTextEdit>

class HelpPage
{
public:
    HelpPage(QSettings* settings, QPlainTextEdit* content);

private:
    QSettings* _settings;
    QPlainTextEdit* _content;

};

#endif // HELPPAGE_H

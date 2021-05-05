#ifndef HELPPAGE_H
#define HELPPAGE_H
#include <QSettings>
#include <QCheckBox>
#include <QPlainTextEdit>

class HelpPage
{
public:
    HelpPage(QSettings* settings, QCheckBox* donateCheckBox,
                                  QPlainTextEdit* content);

    void donateCheckBoxClicked(bool checked);

private:
    QSettings* _settings;
    QCheckBox* _donateCheckBox;
    QPlainTextEdit* _content;

};

#endif // HELPPAGE_H

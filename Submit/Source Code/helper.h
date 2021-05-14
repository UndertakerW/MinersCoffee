#ifndef HELPER_H
#define HELPER_H

#include <QList>
#include <QString>
#include <QFile>
#include <QMessageBox>
#include <QTextStream>

class Helper
{
public:
    Helper();
    QList<QString> GetStringData(QString path);
};

#endif // HELPER_H

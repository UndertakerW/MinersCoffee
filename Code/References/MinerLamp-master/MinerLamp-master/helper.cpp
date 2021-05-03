#include "helper.h"

Helper::Helper()
{

}

QList<QString> Helper::GetStringData(QString path)
{
    QFile file(path);

    if (!file.exists())
    {
        QMessageBox::warning(NULL, "warning", QString("File %1 does not exist!").arg(path));
    }

    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        QMessageBox::warning(NULL, "warning", QString("Unable to open file：%1 (%2)").arg(path).arg(file.errorString()));
    }

    QTextStream in(&file);

    QList<QString> data;

    QString line;

    while (1)
    {
        line = in.readLine();
        if (line == "")
            break;

        data.append(line);
    }

    file.close();

    return data;
}


#include "mainwindow.h"

#include <QApplication>
#include <QtSql/QSqlDatabase>
#include <QtTest>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    a.setAttribute(Qt::AA_UseHighDpiPixmaps);
    MainWindow w;
    QFontDatabase::addApplicationFont(":/fonts/fonts/BRLNSB.TTF");
    QFontDatabase::addApplicationFont(":/fonts/fonts/BRLNSDB.TTF");
    QFontDatabase::addApplicationFont(":/fonts/fonts/BRLNSR.TTF");
    w.show();
    return a.exec();
}

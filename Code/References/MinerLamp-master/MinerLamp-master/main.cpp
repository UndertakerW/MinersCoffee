#include "mainwindow.h"
#include "database.h"
#include <QApplication>
#include <QtSql/QSqlDatabase>
int main(int argc, char *argv[])
{
    qDebug() << "loading fonts";
    QFontDatabase::addApplicationFont(":/fonts/BRLNSB.TTF");
    qDebug() << "loading fonts 1";
    QFontDatabase::addApplicationFont(":/fonts/BRLNSDB.TTF");
    qDebug() << "loading fonts 2";
    QFontDatabase::addApplicationFont(":/fonts/BRLNSR.TTF");
    qDebug() << "finishing fonts";

    QApplication a(argc, argv);
    a.setAttribute(Qt::AA_UseHighDpiPixmaps);
    MainWindow w;
    w.show();
    return a.exec();
}

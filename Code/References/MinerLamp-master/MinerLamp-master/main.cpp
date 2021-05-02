#include "mainwindow.h"
#include "database.h"
#include <QApplication>
#include <QtSql/QSqlDatabase>
int main(int argc, char *argv[])
{
    // load fonts
    QFontDatabase::addApplicationFont(":/Berlin_Sans/fonts/BRLNSB.TTF");
    QFontDatabase::addApplicationFont(":/Berlin_Sans/fonts/BRLNSDB.TTF");
    QFontDatabase::addApplicationFont(":/Berlin_Sans/fonts/BRLNSR.TTF");

    QApplication a(argc, argv);
    a.setAttribute(Qt::AA_UseHighDpiPixmaps);
    MainWindow w;
    w.show();
    return a.exec();
}

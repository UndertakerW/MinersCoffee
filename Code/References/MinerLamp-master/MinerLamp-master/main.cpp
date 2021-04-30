#include "mainwindow.h"
#include "database.h"
#include <QApplication>
#include <QtSql/QSqlDatabase>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    a.setAttribute(Qt::AA_UseHighDpiPixmaps);
    MainWindow w;
    // close window hint
    // w.setWindowFlag(Qt::FramelessWindowHint);
    w.show();
    return a.exec();
}

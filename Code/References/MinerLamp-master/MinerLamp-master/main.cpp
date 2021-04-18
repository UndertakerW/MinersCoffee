#include "mainwindow.h"
#include "mysql.h"
#include <QApplication>
#include <QtSql/QSqlDatabase>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    a.setAttribute(Qt::AA_UseHighDpiPixmaps);
    MainWindow w;
    w.show();
    MYSQLcon db;
    qDebug() << "testing";
    db.ConnectDatabase();
    return a.exec();
}

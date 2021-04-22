#ifndef MYSQL_H
#define MYSQL_H

#include <QtSql/QSqlDatabase>
#include <QDebug>
#include <QMessageBox>
#include <QApplication>
#include <QSqlQuery>
#include <QSqlError>
#include <stdio.h>
#include <QThread>
#include <nvidianvml.h>
#include "gpumonitor.h"
#include <Windows.h>
#include <QtCharts/QLineSeries>

class MYSQLcon:public QThread{

private:
    QSqlDatabase _db;

public:
    MYSQLcon();
    ~MYSQLcon();
    QStringList getAdvice(const char* type);
    void run() override;
    void Get_HistoryNew(const char* date1,const char* date2,int num);
    void InsertDataNew();

    QStringList * searchResultBuffer;
    QStringList * searchConditionBuffer;

    int _insert;
    int _retrieve;
    int _insertBusy;
    int _retrieveBusy;
    QList<GPUInfo> * _gpusInfoBuffer;
    QList<QtCharts::QLineSeries *> * _seriesPtr;
    QtCharts::QChart* _chartHistory;
};


#endif // MYSQL_H

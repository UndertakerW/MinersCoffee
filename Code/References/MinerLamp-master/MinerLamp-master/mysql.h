#ifndef MYSQL_H
#define MYSQL_H

#include <QtSql/QSqlDatabase>
#include <QDebug>
#include <QMessageBox>
#include <QApplication>
#include <QSqlQuery>
//#include <QSqlError>
#include <stdio.h>
#include <nvidianvml.h>
#include <WinSock.h>
#include "gpumonitor.h"
#include "C:/Program Files/MySQL/MySQL Server 8.0/include/mysql.h"
#include <Windows.h>

#pragma comment(lib,"wsock32.lib")

#pragma comment(lib,"libmysql.lib")
class MYSQLcon{

private:
    MYSQL mysql; //mysql连接

    MYSQL_FIELD *fd;  //字段列数组
    QSqlQuery query;


    char field[32][32];  //存字段名二维数组

    MYSQL_RES *res; //这个结构代表返回行的一个查询结果集

    MYSQL_ROW column; //一个行数据的类型安全(type-safe)的表示，表示数据行的列
public:
    MYSQLcon();
    void ConnectDatabase();
    void FreeConnect();
    QStringList getAdvice(char* type);
    void InsertData();
    void run();
    std::vector<GPUInfo> Get_History(char *date1,char *date2,int num);
};


#endif // MYSQL_H

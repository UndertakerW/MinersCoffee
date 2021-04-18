#include "mysql.h"
#include <QtSql/QSqlDatabase>
#include <QDebug>
#include <QMessageBox>
#include <QFile>
#include <QSqlQueryModel>
#include <QApplication>
#include <QSqlError>#include <stdio.h>
#include <nvidianvml.h>
#include <WinSock.h>
//一定要包含这个，或者winsock2.h

#include "C:/Program Files/MySQL/MySQL Server 8.0/include/mysql.h"    //引入mysql头文件(一种方式是在vc目录里面设置，一种是文件夹拷到工程目录，然后这样包含)

#include <Windows.h>

#pragma comment(lib,"wsock32.lib")

#pragma comment(lib,"libmysql.lib")

MYSQLcon::MYSQLcon(){

}
void MYSQLcon::ConnectDatabase(){
    mysql_init(&mysql);  //连接mysql，数据库

    //返回false则连接失败，返回true则连接成功

    if (!(mysql_real_connect(&mysql,"localhost", "root", "1020zxc..", "minercoffee",0,NULL,0))) //中间分别是主机，用户名，密码，数据库名，端口号（可以写默认0或者3306等），可以先写成参数再传进去
    {

       qDebug()<<"Error connecting to database:%s\n",mysql_error(&mysql);
       mysql_close(&mysql);
       mysql_init(&mysql);
       if(mysql_real_connect(&mysql,"localhost", "root", "1020zxc..", "mysql",0,NULL,0)){
           mysql_query(&mysql, "use sys");
           mysql_query(&mysql, "drop database if exists minercoffee");
           mysql_query(&mysql, "create database minercoffee");
           qDebug() << "mysqlhere"<<endl;
           mysql_query(&mysql, "use minercoffee");
           qDebug() << "mysqlhere"<<endl;
           mysql_query(&mysql, "create table gpu_table(gpu_id int PRIMARY KEY,GPU_TMP int not null,GPU_cLOCK int not null,FanSpeed int not null,PowerDraw int not null,Drawsum int not null)");
           mysql_query(&mysql, "create table hash_table(gpu_id int PRIMARY KEY,hashrate float4 not null,accepted_shares int not null,invalid_shares int not null,rejected_shares int not null)");
           mysql_query(&mysql, "create table main_table(Date1 date not null,Time1 time not null,gpu_id int PRIMARY KEY not null,gpu_name varchar(8) not null,FOREIGN KEY(gpu_id) REFERENCES gpu_table(gpu_id),FOREIGN KEY(gpu_id) REFERENCES hash_table(gpu_id))");
           mysql_query(&mysql, "create table advise(gpu_type varchar(10) PRIMARY KEY,gpu_clock int,mem_clock int not null,power int not null,prediction int not null)");
           qDebug() << "mysqlhere"<<endl;
           mysql_query(&mysql, "insert into advise values('3090',-300,1000,285,120)");
           mysql_query(&mysql, "insert into advise values('3080',-150,900,220,98)");
           mysql_query(&mysql, "insert into advise values('3070',-500,1100,130,60)");
           qDebug() << "mysqlhere"<<endl;
           mysql_query(&mysql,"insert into advise values('3060Ti',-500,1200,130,60)");
           mysql_query(&mysql,"insert into advise values('2080Ti',-200,1100,150,57)");
           mysql_query(&mysql,"insert into advise values('2080super',-50,1000,175,42)");
           mysql_query(&mysql,"insert into advise values('2080',-50,800,155,42)");
           mysql_query(&mysql,"insert into advise values('2070super',-50,800,150,40)");
           mysql_query(&mysql,"insert into advise values('2070',-50,800,125,39)");
           mysql_query(&mysql,"insert into advise values('2060super',-50,850,125,39)");
           mysql_query(&mysql,"insert into advise values('2060',-50,700,115,31)");
           mysql_query(&mysql,"insert into advise values('1080Ti',null,800,175,45)");
           mysql_query(&mysql,"insert into advise values('1080',null,800,125,43)");
           mysql_query(&mysql,"insert into advise values('1070Ti',null,500,135,30)");
           mysql_query(&mysql,"insert into advise values('1070',null,450,115,30)");
           mysql_query(&mysql,"insert into advise values('1060',null,900,80,23)");
       }

    }
    else
    {
        qDebug()<<"Connected...\n";
        char* s=(char*)"2070";
        getAdvice(s);
    }
}
QStringList MYSQLcon::getAdvice(char* type){
    char* q=(char*)"select gpu_clock,mem_clock,power,prediction from advice where gpu_type=\'";
    char str3[100];
    sprintf(str3,"%s%s%s",q,type,"\'");
    qDebug()<<str3<<endl;
    mysql_query(&mysql,"select gpu_clock,mem_clock,power,prediction from advise where gpu_type='2070'");
    res=mysql_store_result(&mysql);
    mysql_free_result(res);
    MYSQL_ROW   row;
    QStringList l;
    while((row=mysql_fetch_row(res))) {
        for(int i=0 ; i <mysql_num_fields(res);i++){
            qDebug()<<row[i]<<endl;
            l.append(row[i]);
        }
    }
    return l;
}

void MYSQLcon::FreeConnect(){
    mysql_free_result(res);

    mysql_close(&mysql);
}



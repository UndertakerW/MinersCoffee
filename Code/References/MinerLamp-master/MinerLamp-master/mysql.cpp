#include "mysql.h"
#include <QtSql/QSqlDatabase>
#include <QDebug>
#include <QMessageBox>
#include <QFile>
#include <QSqlQueryModel>
#include <QApplication>
#include <QSqlError>
#include <QThread>
#include <stdio.h>
#include <ctime>
#include <nvidianvml.h>
#include <WinSock.h>
#include "gpumonitor.h"
#include "minerprocess.h"

//一定要包含这个，或者winsock2.h

#include "C:/Program Files/MySQL/MySQL Server 8.0/include/mysql.h"    //引入mysql头文件(一种方式是在vc目录里面设置，一种是文件夹拷到工程目录，然后这样包含)

#include <Windows.h>

#pragma comment(lib,"wsock32.lib")

#pragma comment(lib,"libmysql.lib")

MYSQLcon::MYSQLcon(){
    mysql_init(&mysql);
    if (!(mysql_real_connect(&mysql,"localhost", "root", "1020zxc..", "minercoffee",0,NULL,0))) {
        mysql_close(&mysql);
    }
    ConnectDatabase();
    char* l=(char*)"2021-04-18";
    QStringList info;
    info=Get_History(l,l,0);

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
           mysql_query(&mysql, "create table main_table(Date1 date not null,Time1 time not null,hashrate float4 not null,accepted_shares int not null,invalid_shares int not null,rejected_shares int not null,gpu_name VARCHAR(9) not null,TMP int not null,gpu_clock int not null,mem_clock int not null,FanSpeed int not null,PowerDraw int not null,gpu_id int PRIMARY KEY not null)");
           mysql_query(&mysql, "create table advise(gpu_type varchar(10) PRIMARY KEY,gpu_clock int,mem_clock int not null,power int not null,prediction int not null)");
           mysql_query(&mysql, "insert into advise values('3090',-300,1000,285,120)");
           mysql_query(&mysql, "insert into advise values('3080',-150,900,220,98)");
           mysql_query(&mysql, "insert into advise values('3070',-500,1100,130,60)");
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
QStringList MYSQLcon::getAdvice(const char* type){
    char* q=(char*)"select gpu_clock,mem_clock,power,prediction from advice where gpu_type=\'";
    char str3[100];
    sprintf(str3,"%s%s%s",q,type,"\'");
    mysql_query(&mysql,"select gpu_clock,mem_clock,power,prediction from advise where gpu_type='2070'");
    res=mysql_store_result(&mysql);
    mysql_free_result(res);
    MYSQL_ROW   row;
    QStringList l;
    while((row=mysql_fetch_row(res))) {
        for(int i=0 ; i<mysql_num_fields(res);i++){
            l.append(row[i]);
        }
    }
    return l;
}
void MYSQLcon::InsertData(){

    QList<GPUInfo> gpuInfos;
    nvMonitorThrd nvMonitorThrd;
    gpuInfos=nvMonitorThrd.getStatus();
    char* Ins_main=(char*)"insert into main_table values(";
    time_t now = time(0);
    tm *ltm = localtime(&now);
    int year=1900 + ltm->tm_year;
    int month=1+ltm->tm_mon;
    char date[15];
    sprintf(date,"%d%c%d%c%d",year,'-',month,'-',ltm->tm_mday);
    char time[10];
    sprintf(time,"%d%c%d%c%d",ltm->tm_hour,':',ltm->tm_min,':',ltm->tm_sec);
    char mainline[100];
    qDebug()<<date<<endl;
    qDebug()<<time<<endl;

    //TODO
    MiningInfo miningInfo;
    MinerProcess* mp;
    miningInfo = mp->getStatus();
    for (int i = 0; i < gpuInfos.size(); i++) {
        //std::string na=gpuInfos[i].name;
        //std::size_t pos =na.find("2070");
        //std::string str3 = na.substr (pos,pos+4);
        std::string str3="2070";
        sprintf(mainline,"%s%c%s%c%c%c%s%c%c%f%c%d%c%d%c%d%c%c%s%c%c%d%c%d%c%d%c%d%c%d%c%d%c",Ins_main,'\'',date,'\'',',','\'',time,'\'',',',miningInfo.gpuMiningInfos[i].hashrate,',',miningInfo.gpuMiningInfos[i].accepted_shares,',',miningInfo.gpuMiningInfos[i].invalid_shares,',',miningInfo.gpuMiningInfos[i].rejected_shares,',','\'',str3.c_str(),'\'',',',gpuInfos[i].temp,',',gpuInfos[i].gpuclock,',',gpuInfos[i].memclock,',',gpuInfos[i].fanspeed,',',gpuInfos[i].power,',',gpuInfos[i].num,')');
        qDebug()<<mainline<<endl;
        mysql_query(&mysql,mainline);
    }
    mysql_close(&mysql);


}
void MYSQLcon::run()
{
    while(1){
        QThread::sleep(6);
        InsertData();
    }
}
void MYSQLcon::FreeConnect(){
    mysql_free_result(res);

    mysql_close(&mysql);
}
QStringList MYSQLcon::Get_History(char* date1,char* date2,int num){
    char* Ins_main=(char*)"select avg(TMP),avg(gpu_clock),avg(mem_clock),avg(FanSpeed),avg(PowerDraw),avg(hashrate) from main_table where Date1<=";
    char* i=(char*)" and Date1>=";
    char* w=(char*)" and gpu_id=";
    char lp[250];
    //char li[250]="select avg(TMP),avg(gpu_clock),avg(mem_clock),avg(FanSpeed),avg(PowerDraw),avg(hashrate),gpu_name,avg(accepted_shares),avg(invalid_shares),avg(rejected_shares) from main_table where Date1<='2021-04-18' and Date1>='2021-04-18' and gpu_id=0";
    sprintf(lp,"%s%c%s%c%s%c%s%c%s%d",Ins_main,'\'',date2,'\'',i,'\'',date1,'\'',w,num);
    qDebug()<<lp<<endl;
    mysql_query(&mysql,lp);
    res=mysql_store_result(&mysql);
    mysql_free_result(res);
    MYSQL_ROW   row;
    QStringList l;
    while((row=mysql_fetch_row(res))) {
        for(int i=0 ; i<mysql_num_fields(res);i++){
            l.append(row[i]);
        }
    }
    return l;
}


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
#include <QList>
#include <nvidianvml.h>
#include <WinSock.h>
#include "gpumonitor.h"

//一定要包含这个，或者winsock2.h

#include "C:/Program Files/MySQL/MySQL Server 8.0/include/mysql.h"    //引入mysql头文件(一种方式是在vc目录里面设置，一种是文件夹拷到工程目录，然后这样包含)

#include <Windows.h>

#pragma comment(lib,"wsock32.lib")

#pragma comment(lib,"libmysql.lib")

MYSQLcon::MYSQLcon(){
    mysql_init(&mysql);
    if (!(mysql_real_connect(&mysql,"localhost", "root", "MaoYu", "minercoffee",0,NULL,0))) {
        mysql_close(&mysql);
    }
    ConnectDatabase();

}
void MYSQLcon::ConnectDatabase(){
    mysql_init(&mysql);  //连接mysql，数据库

    //返回false则连接失败，返回true则连接成功

    if (!(mysql_real_connect(&mysql,"localhost", "root", "MaoYu", "minercoffee",0,NULL,0))) //中间分别是主机，用户名，密码，数据库名，端口号（可以写默认0或者3306等），可以先写成参数再传进去
    {

       qDebug()<<"Error connecting to database:%s\n",mysql_error(&mysql);
       mysql_close(&mysql);
       mysql_init(&mysql);
       if(mysql_real_connect(&mysql,"localhost", "root", "MaoYu", "mysql",0,NULL,0)){
           mysql_query(&mysql, "use sys");
           mysql_query(&mysql, "drop database if exists minercoffee");
           mysql_query(&mysql, "create database minercoffee");
           qDebug() << "mysqlhere"<<endl;
           mysql_query(&mysql, "use minercoffee");
           qDebug() << "mysqlhere"<<endl;
           mysql_query(&mysql, "create table main_table(Date1 date not null,Time1 time not null,hashrate float4 not null,accepted_shares int not null,invalid_shares int not null,rejected_shares int not null,gpu_name VARCHAR(9) not null,TMP int not null,gpu_clock int not null,mem_clock int not null,FanSpeed int not null,PowerDraw int not null,gpu_id int PRIMARY KEY not null)");
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

    }
}
QStringList MYSQLcon::getAdvice(const char* type){
    char* q=(char*)"select gpu_clock,mem_clock,power,prediction from advice where gpu_type=\'";
    char str3[100];
    sprintf(str3,"%s%s%s",q,type,"\'");
    mysql_query(&mysql,str3);
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
void MYSQLcon::InsertData(QList<GPUInfo> gpuInfos,QList<GPUMiningInfo> GPUMiningInfo,std::string name){
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
    for (int i = 0; i < gpuInfos.size(); i++) {
        std::string n="";
        for(int i=0;i<name.length();i++){
            if(name[i]=='T'&&name[i+1]=='i')
                n+="Ti";
            if(name[i]!='1'&&name[i]!='2'&&name[i]!='3'&&name[i]!='4'&&name[i]!='5'&&name[i]!='6'&&name[i]!='7'&&name[i]!='8'&&name[i]!='9'&&name[i]!='0')
                continue;
            n+=name[i];
        }
        const char *p;
        p=n.c_str();
        sprintf(mainline,"%s%c%s%c%c%c%s%c%c%f%c%d%c%d%c%d%c%c%s%c%c%d%c%d%c%d%c%d%c%d%c%d%c",Ins_main,'\'',date,'\'',',','\'',time,'\'',',',GPUMiningInfo[i].hashrate,',',GPUMiningInfo[i].accepted_shares,',',GPUMiningInfo[i].invalid_shares,',',GPUMiningInfo[i].rejected_shares,',','\'',p,'\'',',',gpuInfos[i].temp,',',gpuInfos[i].gpuclock,',',gpuInfos[i].memclock,',',gpuInfos[i].fanspeed,',',gpuInfos[i].power,',',gpuInfos[i].num,')');
        qDebug()<<mainline<<endl;
        mysql_query(&mysql,mainline);
    }
    mysql_close(&mysql);


}
/*void MYSQLcon::run()
{
    while(1){
        QThread::sleep(60);
        InsertData();
    }
}*/
void MYSQLcon::FreeConnect(){
    mysql_free_result(res);

    mysql_close(&mysql);
}
QStringList MYSQLcon::Get_History(const char* date1,const char* date2,int num){
    char* Ins_main=(char*)"select avg(TMP),avg(gpu_clock),avg(mem_clock),avg(FanSpeed),avg(PowerDraw),avg(hashrate) from main_table where Date1<=";
    char* i=(char*)" and Date1>=";
    char* w=(char*)" and gpu_id=";
    char lp[100];
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

#include "mysql.h"
#include <QtSql/QSqlDatabase>
#include <QDebug>
#include <QMessageBox>
#include <QFile>
#include <QSqlQueryModel>
#include <QApplication>
#include <QSqlError>
#include <stdio.h>
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

    if (!(mysql_real_connect(&mysql,"localhost", "root", "CPTBTPTP", "minercoffee",0,NULL,0))) //中间分别是主机，用户名，密码，数据库名，端口号（可以写默认0或者3306等），可以先写成参数再传进去
    {

       qDebug()<<"Error connecting to database:%s\n",mysql_error(&mysql);
       mysql_close(&mysql);
       mysql_init(&mysql);
       if(mysql_real_connect(&mysql,"localhost", "root", "CPTBTPTP", "mysql",0,NULL,0)){
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
        //getAdvice(s);
    }
}
QStringList MYSQLcon::getAdvice(const char* type){
    char* q=(char*)"select gpu_clock,mem_clock,power,prediction from advise where gpu_type=\'";
    char str3[100];
    sprintf(str3,"%s%s%s",q,type,"\'");
    qDebug()<<str3<<endl;
    mysql_query(&mysql,("select gpu_clock,mem_clock,power,prediction from advise where gpu_type='%s'",str3));
    res=mysql_store_result(&mysql);
    mysql_free_result(res);
    MYSQL_ROW   row;
    QStringList l;
    while((row=mysql_fetch_row(res))) {
         for(unsigned int i=0 ; i <mysql_num_fields(res);i++){
             //qDebug()<<"info    "<<row[i]<<endl;
             l.append(row[i]);
         }
    }
    return l;

}
void MYSQLcon::FreeConnect(){
    mysql_free_result(res);

    mysql_close(&mysql);
}
/*
bool MYSQLcon::QueryDatabase1(){
    query.exec("select * from minercoffee"); //执行查询语句，这里是查询所有，user是表名，不用加引号，用strcpy也可以

    query.exec("set names gbk"); //设置编码格式（SET NAMES GBK也行），否则cmd下中文乱码

    //返回0 查询成功，返回1查询失败

    if(mysql_query(&mysql, query))        //执行SQL语句

    {

        printf("Query failed (%s)\n",mysql_error(&mysql));

        return false;

    }

    else

    {

        printf("query success\n");

    }

    //获取结果集

    if (!(res=mysql_store_result(&mysql)))    //获得sql语句结束后返回的结果集

    {

        printf("Couldn't get result from %s\n", mysql_error(&mysql));

        return false;

    }



    //打印数据行数

    printf("number of dataline returned: %d\n",mysql_affected_rows(&mysql));



    //获取字段的信息

    char *str_field[32];  //定义一个字符串数组存储字段信息

    for(int i=0;i<4;i++)   //在已知字段数量的情况下获取字段名

    {

        str_field[i]=mysql_fetch_field(res)->name;

    }

    for(int i=0;i<4;i++)   //打印字段

        printf("%10s\t",str_field[i]);

    printf("\n");

    //打印获取的数据

    while (column = mysql_fetch_row(res))   //在已知字段数量情况下，获取并打印下一行

    {

        printf("%10s\t%10s\t%10s\t%10s\n", column[0], column[1], column[2],column[3]);  //column是列数组

    }

    return true;
}
bool MYSQLcon::QueryDatabase2(){
    mysql_query(&mysql,"set names gbk");

    //返回0 查询成功，返回1查询失败

    if(mysql_query(&mysql, "select * from minercoffee"))        //执行SQL语句

    {

        printf("Query failed (%s)\n",mysql_error(&mysql));

        return false;

    }

    else

    {

        printf("query success\n");

    }

    res=mysql_store_result(&mysql);

    //打印数据行数

    printf("number of dataline returned: %d\n",mysql_affected_rows(&mysql));

    for(int i=0;fd=mysql_fetch_field(res);i++)  //获取字段名

        strcpy(field[i],fd->name);

    int j=mysql_num_fields(res);  // 获取列数

    for(int i=0;i<j;i++)  //打印字段

        printf("%10s\t",field[i]);

    printf("\n");

    while(column=mysql_fetch_row(res))

    {

        for(int i=0;i<j;i++)

            printf("%10s\t",column[i]);

        printf("\n");

    }

    return true;
}
bool InsertData(){
    sprintf(query, "insert into user values (NULL, 'Lilei', 'wyt2588zs','lilei23@sina.cn');");  //可以想办法实现手动在控制台手动输入指令

    if(mysql_query(&mysql, query))        //执行SQL语句

    {

        printf("Query failed (%s)\n",mysql_error(&mysql));

        return false;

    }

    else

    {

        printf("Insert success\n");

        return true;

    }

}
bool DeleteData(){
    char query[100];

    printf("please input the sql:\n");


    if(mysql_query(&mysql, query))        //执行SQL语句

    {

        printf("Query failed (%s)\n",mysql_error(&mysql));

        return false;

    }

    else

    {

        printf("Insert success\n");

        return true;

    }
}*/

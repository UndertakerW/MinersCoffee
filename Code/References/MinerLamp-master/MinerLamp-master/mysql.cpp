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
#include <QDateTime>
#include "gpumonitor.h"

MYSQLcon::MYSQLcon(){
    searchResultBuffer = new QStringList();
    searchConditionBuffer = new QStringList();
    _gpusInfoBuffer = nullptr;
    _miningInfoBuffer = nullptr;
    _seriesPtr = nullptr;

    // 0 stands for idle/complete
    // 1 stands for working
    _insert = 0;
    _retrieve = 0;
    _insertBusy = 0;
    _retrieveBusy = 0;

    _db = QSqlDatabase::addDatabase("QSQLITE");
    _db.setDatabaseName("./minerDatabase/minerDatabase.db");
    qDebug() << _db.tables();

    if(!_db.open()){
        QMessageBox::critical(0, QObject::tr("Database error"),
                _db.lastError().text());
                qDebug() << "sql: connect fail";
    }
    else{
        qDebug() << "sql: connection success";
    }


}


QStringList MYSQLcon::getAdvice(const char* type){
    char* q=(char*)"select gpu_clock,mem_clock,power,prediction from advise where gpu_type=\'";
    char str3[150];
    sprintf(str3,"%s%s%s",q,type,"\'");
    qDebug() << "get advice query: " << str3;
    QStringList l;

    QString retrieveQuery(str3);
    QSqlQuery sql_query(_db);
    sql_query.exec(retrieveQuery);
    QStringList retrieveHistory;
    qDebug() << "the query is: " << str3;

    int newCnt = 0;

    // size row size = 4
    int row_size = 4;
    while(sql_query.next()){
        newCnt++;
        qDebug() << "row: "<< sql_query.value(0).toString() << " " << sql_query.value(1).toString() << " " << sql_query.value(2).toString();
        for(int i=0;i<row_size;i++){
            l.append(sql_query.value(i).toString());
        }
    }


    return l;
}


void MYSQLcon::InsertDataNew(){
    // insert gpuInfo
    if(_gpusInfoBuffer == nullptr){
        return;
    }

    char* Ins_main=(char*)"insert into main_table values(";
    time_t now = time(0);
    tm *ltm = localtime(&now);
    int year=1900 + ltm->tm_year;
    int month=1+ltm->tm_mon;
    char date[15];


    sprintf(date,"%d%c%d%c%d",year,'/',month,'/',ltm->tm_mday);
    char time[10];
    sprintf(time,"%d%c%d%c%d",ltm->tm_hour,':',ltm->tm_min,':',ltm->tm_sec);
    char mainline[100];


    QString currentDate = QDate().currentDate().toString("yyyy/MM/dd");
    QString currentTime = QTime().currentTime().toString("hh:mm:ss");


    qDebug()<<"current time: " << currentTime;
    qDebug()<<time<<endl;
    for (int i = 0; i < _gpusInfoBuffer->size(); i++) {
        std::string name=_gpusInfoBuffer->at(i).name.toStdString();
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

        sprintf(mainline,"%s%c%s%c%c%c%s%c%c%f%c%d%c%d%c%d%c%c%s%c%c%d%c%d%c%d%c%d%c%d%c%d%c;",Ins_main,'\'',currentDate.toStdString().c_str(),'\'',',','\'',time,'\'',',',3.5,',',6,',',6,',',6,',','\'',p,'\'',',',_gpusInfoBuffer->at(i).temp,',',_gpusInfoBuffer->at(i).gpuclock,',',_gpusInfoBuffer->at(i).memclock,',',_gpusInfoBuffer->at(i).fanspeed,',',_gpusInfoBuffer->at(i).power,',',_gpusInfoBuffer->at(i).num,')');
        qDebug() << "new mainline: " << mainline;


        QString insertQuery_maintable("insert into main_table values( '" + currentDate +"', "
                                      +"'"+currentTime+"', "
                                      +"'"+QString(p)+"', "
                                      +QString::number(_gpusInfoBuffer->at(i).temp)+", "
                                      +QString::number(_gpusInfoBuffer->at(i).gpuclock)+", "
                                      +QString::number(_gpusInfoBuffer->at(i).memclock)+", "
                                      +QString::number(_gpusInfoBuffer->at(i).fanspeed)+", "
                                      +QString::number(_gpusInfoBuffer->at(i).power)+", "
                                      +QString::number(_gpusInfoBuffer->at(i).num)
                                      +")"
                    );


        qDebug() << "insert to maintable: " << insertQuery_maintable;

        QString insertQuery(insertQuery_maintable);
        QSqlQuery sql_query(_db);
        sql_query.exec(insertQuery);
    }

    // insert miningInfo
    if(_miningInfoBuffer == nullptr){
        return;
    }

    qDebug() << "processing insert mining info";
    qDebug() << "mingInfo latency: " << _miningInfoBuffer->latency;

    // not valid miningInfo then return
    if(_miningInfoBuffer->latency <= 0){
        return;
    }

    // insert data into miningInfoOverall
    QString insertQuery("insert into miningInfoOverall values( '" +currentDate + "', "
                        +"'"+currentTime + "', "
                        +QString::number(_miningInfoBuffer->accepted_shares)+", "
                        +QString::number(_miningInfoBuffer->invalid_shares)+", "
                        +QString::number(_miningInfoBuffer->rejected_shares)+", "
                        +QString::number(_miningInfoBuffer->latency)
                        +");"
    );

    QSqlQuery sql_query(_db);
    sql_query.exec(insertQuery);

    // insert data into miningInfoDevices
    for(int i=0;i<_miningInfoBuffer->gpuMiningInfos.size();i++){
        qDebug() << "device id: " << _miningInfoBuffer->gpuMiningInfos.at(i).num;
        QList<GPUMiningInfo>* deviceInfo = &_miningInfoBuffer->gpuMiningInfos;
        QString insertQuery_device("insert into miningInfoDevices values( '" +currentDate + "', "
                            +"'"+currentTime + "', "
                            +QString::number(deviceInfo->at(i).num)+", "
                            +QString::number(deviceInfo->at(i).hashrate)+", "
                            +QString::number(deviceInfo->at(i).rejected_shares)+", "
                            +QString::number(deviceInfo->at(i).rejected_shares)
                            +");"
        );

        sql_query.exec(insertQuery_device);

    }

    qDebug() << "insert miningInfo query: " << insertQuery << " size: " << _miningInfoBuffer->gpuMiningInfos.size();


}

void MYSQLcon::run()
{
    while(1){
        qDebug() << "test mysql thread";
        QThread::sleep(2);

        if(_retrieve==1){
            _retrieveBusy = 1;
            Get_HistoryNew(searchConditionBuffer->at(0).toStdString().c_str(),
                           searchConditionBuffer->at(1).toStdString().c_str(),
                           searchConditionBuffer->at(2).toInt());
            _retrieveBusy = 0;
            _retrieve = 0;
            qDebug() << "retrieve success";
        }

        if(_insert==1){
            _insertBusy = 1;
            InsertDataNew();
            _insertBusy = 0;
            qDebug() << "insert success";
        }
    }
}


void MYSQLcon::Get_HistoryNew(const char* date1,const char* date2,int num){
    QString retrieveQueryline("select gpu_id, gpu_name, Date1,avg(TMP), avg(gpu_clock), avg(mem_clock), "
                               "avg(FanSpeed), avg(PowerDraw) "
                               "from main_table group by Date1 having Date1<= '"
                               +QString(date2)+"' and Date1>='"
                               +QString(date1)+"' and gpu_id="
                               +QString::number(num)
                );

    QString retrieveQuery(retrieveQueryline);
    QSqlQuery sql_query(_db);
    sql_query.exec(retrieveQuery);
    QStringList retrieveHistory;
    qDebug() << "the query is: " << retrieveQueryline;

    // column size = 8
    int column_size = 8;
    while(sql_query.next()){
        for(int j=0;j<column_size;j++){
            searchResultBuffer->push_back(sql_query.value(j).toString());
        }
        qDebug() << "row: "<< sql_query.value(0).toString() << " " << sql_query.value(1).toString() << " " << sql_query.value(2).toString();
    }

    int gpuInfoListSize = searchResultBuffer->size();

    if(gpuInfoListSize == 0){
        return;
    }

    double maxValue = 0;
    double minValue = 999;

    // graphing
    // clear points
    // there are 5 line in the graph
    for(int j =0; j<5; j++){
        _seriesPtr->at(j)->clear();
    }


    // append points
    for(int k=0; k<gpuInfoListSize/8; k++){
        // gpu_name 1, Date1 2, avg(TMP) 3, avg(gpu_clock) 4, avg(mem_clock) 5, avg(FanSpeed) 6, avg(PowerDraw) 7
        QDateTime x_coordinate = QDateTime::fromString(searchResultBuffer->at(k*8+2)+" 00:00:00","yyyy/MM/dd HH:mm:ss");

        // plot 5 line from TMP to PowerDraw
        for(int j =0; j<5; j++){
            double value = searchResultBuffer->at(k*8+3+j).toDouble();
            if(value > maxValue){
                maxValue = value;
            }
            if(value < minValue){
                minValue = value;
            }
            _seriesPtr->at(j)->append(x_coordinate.toMSecsSinceEpoch(), value);
            qDebug() << searchResultBuffer->at(k*8+3+j) << "with i:" << k << " j: " << j;
        }
    }

    qDebug() << "end graphing";
    _chartHistory->axisY()->setRange(minValue-5, maxValue+5);
    qDebug() << "complete";

    QDateTime x_startTime = QDateTime::fromString(searchResultBuffer->at(2)+" 00:00:00","yyyy/MM/dd HH:mm:ss");
    QDateTime x_endTime = QDateTime::fromString(searchResultBuffer->at(gpuInfoListSize-8+2)+" 00:00:00","yyyy/MM/dd HH:mm:ss");

    if(x_startTime > x_endTime){
        QDateTime temp = x_startTime;
        x_startTime = x_endTime;
        x_endTime = temp;
    }

    qDebug() << "start time: " << searchResultBuffer->at(2) << " -> " <<searchResultBuffer->at(gpuInfoListSize-8+2);

    _chartHistory->axisX()->setRange(x_startTime.addDays(-1), x_endTime.addDays(1));

    searchResultBuffer->clear();
}

MYSQLcon::~MYSQLcon(){
    _db.commit();
    _db.close();

//    delete some ptrs
    delete _gpusInfoBuffer;

}

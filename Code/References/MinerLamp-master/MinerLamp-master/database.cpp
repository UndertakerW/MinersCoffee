#include "database.h"
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

Database::Database(){
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


QStringList Database::getAdvice(const char* type){
    char* q=(char*)"select gpu_clock,mem_clock,power,prediction from advise where gpu_type=\'";
    char str3[150];
    sprintf(str3,"%s%s%s",q,type,"\'");
    QStringList l;

    QString retrieveQuery(str3);
    QSqlQuery sql_query(_db);
    sql_query.exec(retrieveQuery);
    QStringList retrieveHistory;
    qDebug() << str3;

    int newCnt = 0;

    // size row size = 4
    int row_size = 4;
    while(sql_query.next()){
        newCnt++;
        for(int i=0;i<row_size;i++){
            l.append(sql_query.value(i).toString());
        }
    }


    return l;
}


void Database::InsertDataNew(){
    // insert gpuInfo
    if(_gpusInfoBuffer == nullptr){
        return;
    }

    QString currentDate = QDate().currentDate().toString("yyyy/MM/dd");
    QString currentTime = QTime().currentTime().toString("hh:mm:ss");

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


        QString insertQuery(insertQuery_maintable);
        QSqlQuery sql_query(_db);
        sql_query.exec(insertQuery);
        qDebug() << insertQuery_maintable;
    }

    // insert miningInfo
    if(_miningInfoBuffer == nullptr){
        return;
    }


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
    qDebug() << insertQuery;

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
        qDebug() << insertQuery_device;

    }

}

void Database::run()
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


void Database::Get_HistoryNew(const char* date1,const char* date2,int num){
    QString retrieveQueryline;
    int column_size;
    int line_num;
    int plot_start_index;
    int date_index;
    // show overall mining information
    if(num==999){
        column_size = 5;
        line_num = 4;
        plot_start_index = 1;
        date_index = 0;
        retrieveQueryline = QString("select Date, avg(accepted_shares), avg(invalid_shares), "
                                   "avg(rejected_shares), avg(latency) "
                                   "from miningInfoOverall group by Date having Date <= '"
                                   +QString(date2)+"' and Date >='"
                                   +QString(date1)+"'"
                    );
    }
    // show gpu mining information
    else if(num<0){
        num = -num-1;
        column_size = 5;
        line_num = 4;
        plot_start_index = 1;
        date_index = 0;
        retrieveQueryline = QString("select Date, avg(accepted_shares), avg(hashrate), "
                                   "avg(invalid_shares), avg(rejected_shares) "
                                   "from miningInfoDevices group by Date, device_id having Date <= '"
                                   +QString(date2)+"' and Date >='"
                                   +QString(date1)+"' and device_id = "
                                   +QString::number(num)
                    );
    }
    // show gpu information
    else{
        column_size = 8;
        line_num = 5;
        plot_start_index = 3;
        date_index = 2;
        retrieveQueryline = QString("select gpu_id, gpu_name, Date1,avg(TMP), avg(gpu_clock), avg(mem_clock), "
                                   "avg(FanSpeed), avg(PowerDraw) "
                                   "from main_table group by Date1, gpu_id having Date1<= '"
                                   +QString(date2)+"' and Date1>='"
                                   +QString(date1)+"' and gpu_id="
                                   +QString::number(num)
                    );
    }



    QString retrieveQuery(retrieveQueryline);
    QSqlQuery sql_query(_db);
    sql_query.exec(retrieveQuery);
    QStringList retrieveHistory;
    qDebug() << retrieveQueryline;


    while(sql_query.next()){
        for(int j=0;j<column_size;j++){
            searchResultBuffer->push_back(sql_query.value(j).toString());
        }
    }

    int gpuInfoListSize = searchResultBuffer->size();

    if(gpuInfoListSize == 0){
        return;
    }

    double maxValue = 0;
    double minValue = 999;

    // graphing
    // clear points
    // there are 5 line in the series of the graph
    for(int j =0; j<5; j++){
        _seriesPtr->at(j)->clear();
    }


    // append points
    for(int k=0; k<gpuInfoListSize/column_size; k++){
        // gpu_name 1, Date1 2, avg(TMP) 3, avg(gpu_clock) 4, avg(mem_clock) 5, avg(FanSpeed) 6, avg(PowerDraw) 7
        QDateTime x_coordinate = QDateTime::fromString(searchResultBuffer->at(k*column_size+date_index)+" 00:00:00","yyyy/MM/dd HH:mm:ss");
        qDebug() << "date: " << x_coordinate.toString();
        for(int j =0; j<line_num; j++){
            double value = searchResultBuffer->at(k*column_size+plot_start_index+j).toDouble();
            if(value > maxValue){
                maxValue = value;
            }
            if(value < minValue){
                minValue = value;
            }
            _seriesPtr->at(j)->append(x_coordinate.toMSecsSinceEpoch(), value);
            qDebug() << searchResultBuffer->at(k*column_size+plot_start_index+j) << "with i:" << k << " j: " << j;
        }
    }

    qDebug() << "end graphing";
    _chartHistory->axisY()->setRange(minValue-5, maxValue+5);
    qDebug() << "complete";

    QDateTime x_startTime = QDateTime::fromString(searchResultBuffer->at(date_index)+" 00:00:00","yyyy/MM/dd HH:mm:ss");
    QDateTime x_endTime = QDateTime::fromString(searchResultBuffer->at(gpuInfoListSize-column_size+date_index)+" 00:00:00","yyyy/MM/dd HH:mm:ss");

    if(x_startTime > x_endTime){
        QDateTime temp = x_startTime;
        x_startTime = x_endTime;
        x_endTime = temp;
    }

    qDebug() << "start time: " << searchResultBuffer->at(date_index) << " -> " <<searchResultBuffer->at(gpuInfoListSize-column_size+date_index);

    _chartHistory->axisX()->setRange(x_startTime.addDays(-1), x_endTime.addDays(1));

    searchResultBuffer->clear();
}

Database::~Database(){
    _db.commit();
    _db.close();

//    delete some ptrs
    delete _gpusInfoBuffer;

}

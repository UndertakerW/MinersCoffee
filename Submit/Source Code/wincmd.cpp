#include "wincmd.h"
#include <iostream>
#include <memory>
#include <stdexcept>
#include <string>
#include <array>
#include <vector>
#include <QFile>
#include <QDir>
#include <QStorageInfo>
#include <QProcess>
using namespace std;

std::string Wincmd::UseCmd(const char* cmd) {
    std::array<char, 128> buffer;
    std::string result;
    std::unique_ptr<FILE, decltype(&_pclose)> pipe(_popen(cmd, "r"), _pclose);
    if (!pipe) {
        throw std::runtime_error("popen() failed!");
    }
    while (fgets(buffer.data(), buffer.size(), pipe.get()) != nullptr) {
        result += buffer.data();
    }
    return result;
}

// Check current settings
vector<QString> Wincmd::SeeSetting(){
    vector<QString> result;
    QString cmd="wmic pagefile list /format:list";
    QProcess process(0);
    process.start("cmd", QStringList()<<"/c"<<cmd);
    process.waitForStarted();
    process.waitForFinished();
    QString strTemp=QString::fromLocal8Bit(process.readAllStandardOutput());
    QStringList qlist =strTemp.split("=");
    //qDebug()<<QString::fromLocal8Bit(p.readAllStandardError());
    while (!qlist.empty()) {
        QString a1=qlist.front();
        qlist.pop_front();
        QStringList l2=a1.split("\n");
        while(!l2.empty()){
            QString ElementResult=l2.front().trimmed();

            if(!result.empty()&&result.back().toStdString()=="Status"&&ElementResult.toStdString()=="TempPageFile"){
                result.push_back(QString("None"));
            }
            if(ElementResult.toStdString()!=""){
                result.push_back(ElementResult);
            }
            l2.pop_front();
        }
    }
    return result;
}


// Cancel auto page management
void Wincmd::AutoManagePage(){
    QString cmd="wmic computersystem where name=\"%computername%\" set AutomaticManagedPagefile=False";
    //const char *command=cmd.c_str();
    QProcess p(0);
    p.start("cmd", QStringList()<<"/c"<<cmd);
    p.waitForStarted();
    p.waitForFinished();
    QString strTemp=QString::fromLocal8Bit(p.readAllStandardOutput());
    //qDebug()<<QString::fromLocal8Bit(p.readAllStandardError());
}
//wmic computersystem where name="%computername%" set AutomaticManagedPagefile=False

// Change Page Size
void Wincmd::ChangePageSize(QString a,QString max,QString min){
    QString cmd="wmic pagefileset where name=\""+a+":\pagefile.sys\" set InitialSize="+min+",MaximumSize="+max;
    QProcess p(0);
    p.start("cmd", QStringList()<<"/c"<<cmd);
    p.waitForStarted();
    p.waitForFinished();
    QString strTemp=QString::fromLocal8Bit(p.readAllStandardOutput());
    //qDebug()<<QString::fromLocal8Bit(p.readAllStandardError());
}
//
//wmic pagefileset where name="C:\pagefile.sys" set InitialSize=1024,MaximumSize=4096


vector<vector<QString>> Wincmd::LocalDisk(){
    vector<QString> disknames;
    vector<QString> diskinfo;
    foreach( QFileInfo drive, QDir::drives() )
    {
      QDir dir = drive.dir();
      dir.setFilter( QDir::Dirs );
      QStorageInfo storage(drive.absolutePath());
      disknames.push_back(storage.rootPath());
      QString totalSpaceGB = QString::number(storage.bytesTotal()/1024/1024/1024);
      QString freeSpaceGB = QString::number(storage.bytesAvailable()/1024/1024/1024);
      diskinfo.push_back(freeSpaceGB+"/"+totalSpaceGB);
    }
    vector<vector<QString> > result;
    result.push_back(disknames);
    result.push_back(diskinfo);
    return result;
}


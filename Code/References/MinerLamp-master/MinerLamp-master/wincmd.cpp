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

//查看当前设置
QString Wincmd::SeeSetting(){
    QString cmd="wmic pagefile list /format:list";
    QProcess p(0);
    p.start("cmd", QStringList()<<"/c"<<cmd);
    p.waitForStarted();
    p.waitForFinished();
    QString strTemp=QString::fromLocal8Bit(p.readAllStandardOutput());
    //qDebug()<<QString::fromLocal8Bit(p.readAllStandardError());
    return strTemp;
}


//取消自动管理分页文件大小
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

//修改页面文件大小 最小1024MB，最大4096MB
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
    vector<vector<QString>> result;
    result.push_back(disknames);
    result.push_back(diskinfo);
    return result;
}


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
std::string Wincmd::SeeSetting(){
    std::string cmd="wmic pagefile list /format:list";
    const char *command=cmd.c_str();
    return UseCmd(command);
}


//取消自动管理分页文件大小
void Wincmd::AutoManagePage(){
    std::string cmd="wmic computersystem where name=\"%computername%\" set AutomaticManagedPagefile=False";
    const char *command=cmd.c_str();
    UseCmd(command);
}
//wmic computersystem where name="%computername%" set AutomaticManagedPagefile=False

//修改页面文件大小 最小1024MB，最大4096MB
void Wincmd::ChangePageSize(std::string a,std::string max,std::string min){

}
//


vector<vector<QString>> Wincmd::LocalDisk(){
    vector<QString> v1;
    vector<QString> v2;
    foreach( QFileInfo drive, QDir::drives() )
    {
      qDebug() << "Drive: " << drive.absolutePath();

      QDir dir = drive.dir();
      dir.setFilter( QDir::Dirs );

//      foreach( QFileInfo rootDirs, dir.entryInfoList() )
//        qDebug() << "  " << rootDirs.fileName();

      QStorageInfo storage(drive.absolutePath());

      qDebug() << storage.rootPath();
      if (storage.isReadOnly())
         qDebug() << "isReadOnly:" << storage.isReadOnly();

      qDebug() << "name:" << storage.name();
      v1.push_back(storage.name());
      qDebug() << "filesystem type:" << storage.fileSystemType();
      qDebug() << "size:" << storage.bytesTotal()/1024/1024/1024 << "GB";
      qDebug() << "free space:" << storage.bytesAvailable()/1024/1024/1024 << "GB";
      QString str1 = QString::number(storage.bytesTotal()/1024/1024/1024);
      QString str2 = QString::number(storage.bytesAvailable()/1024/1024/1024);
      v2.push_back(str1+"/"+str2);

    }
    vector<vector<QString>> q1;
    q1.push_back(v1);
    q1.push_back(v2);
    return q1;
}


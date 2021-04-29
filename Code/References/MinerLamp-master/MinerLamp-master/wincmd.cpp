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


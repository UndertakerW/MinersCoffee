#ifndef WINCMD_H
#define WINCMD_H
#include <string>
#include <QDebug>

class Wincmd
{
public:
    Wincmd();
    std::string command;
    std::string result;
    std::string UseCmd(const char* cmd);
    void getDiskStorage(const char* N);
//查看当前设置
    void SeeSetting();
    //wmic pagefile list /format:list

//取消自动管理分页文件大小
    void AutoManagePage();
//wmic computersystem where name="%computername%" set AutomaticManagedPagefile=False

//修改页面文件大小 最小1024MB，最大4096MB
    void ChangePageSize();
//wmic pagefileset where name="C:\pagefile.sys" set InitialSize=1024,MaximumSize=4096

    void CheckDisk(std::string a);
};

#endif // WINCMD_H

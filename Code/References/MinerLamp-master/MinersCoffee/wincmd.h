#ifndef WINCMD_H
#define WINCMD_H
#include <string>
#include <QDebug>
#include <vector>
#include <QFile>
#include <QDir>
#include <QStorageInfo>
#include <QProcess>
using namespace std;
class Wincmd
{
public:
//    Wincmd();
    std::string command;
    std::string result;
    std::string UseCmd(const char* cmd);
    void getDiskStorage(const char* N);

    vector<QString> SeeSetting();
    //wmic pagefile list /format:list

    void AutoManagePage();
//wmic computersystem where name="%computername%" set AutomaticManagedPagefile=False

    void ChangePageSize(QString a,QString max,QString min);
//wmic pagefileset where name="C:\pagefile.sys" set InitialSize=1024,MaximumSize=4096

    int CheckDisk(std::string a);
//    wmic LogicalDisk where "Caption='C:'" get FreeSpace,Size /value
    vector<vector<QString>> LocalDisk();

};

#endif // WINCMD_H

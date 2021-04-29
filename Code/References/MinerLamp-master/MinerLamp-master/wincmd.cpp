#include "Wincmd.h"
#include <iostream>
#include <memory>
#include <stdexcept>
#include <string>
#include <array>
std::string UseCmd(const char* cmd) {
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
void SeeSetting(){
    std::string cmd="wmic pagefile list /format:list";
    const char *command=cmd.c_str();
    UseCmd(command);
}


//取消自动管理分页文件大小
void AutoManagePage(){
    std::string cmd="wmic computersystem where name=\"%computername%\" set AutomaticManagedPagefile=False";
    const char *command=cmd.c_str();
    UseCmd(command);
}
//wmic computersystem where name="%computername%" set AutomaticManagedPagefile=False

//修改页面文件大小 最小1024MB，最大4096MB
void ChangePageSize(std::string a,std::string max,std::string min){
    std::string cmd="wmic pagefileset where name=\""+a+":\\pagefile.sys\" set InitialSize="+max+",MaximumSize="+min;
    const char *command=cmd.c_str();
    UseCmd(command);
}

void CheckDisk(std::string a){
    std::string cmd="wmic LogicalDisk where \"Caption='"+a+":'\" get FreeSpace,Size /value";
    const char *command=cmd.c_str();
    std::string res=UseCmd(command);

}
//


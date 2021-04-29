#include "Wincmd.h"
#include <iostream>
#include <memory>
#include <stdexcept>
#include <string>
#include <array>
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
    std::string cmd="wmic pagefileset where name=\""+a+":\\pagefile.sys\" set InitialSize="+max+",MaximumSize="+min;
    const char *command=cmd.c_str();
    UseCmd(command);
}

int Wincmd::CheckDisk(std::string a){
    std::string cmd="wmic LogicalDisk where \"Caption='"+a+":'\" get FreeSpace,Size /value";
    const char *command=cmd.c_str();
    int Fsize=0,size=0;
    std::string res=UseCmd(command);
    for(int i=0;i<res.length();i++){
        if(i<res.length()-10){
            if(res.substr(i,10)=="FreeSpace=") {
                int c=i+10;
                std::string b;
                while (res[c]!='\n') {
                    b+=res[c];
                }
                int Fsize=atoi(b.c_str());
            }
        }
        if(i<res.length()-4){
            if(res.substr(i,4)=="Size=") {
                int c=i+4;
                std::string b;
                while (res[c]!='\n') {
                    b+=res[c];
                }
                int size=atoi(b.c_str());
            }
        }
    }
    int fraction=Fsize*100/size;
    return fraction;
}
//

#ifndef URLAPI_H
#define URLAPI_H

#include <string>
#include <shlwapi.h>
#include <wininet.h>
#pragma comment(lib,"Wininet.lib")

class UrlAPI
{
public:
    UrlAPI();
    int GetURLInternal(LPCSTR lpszUrl, std::string& content);
};

#endif // URLAPI_H

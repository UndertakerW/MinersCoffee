#include "url_api.h"

UrlAPI::UrlAPI() {}


int UrlAPI::GetURLInternal(LPCSTR lpszUrl, std::string& content)
{
    int result = -1;
    HINTERNET hSession = InternetOpenA(NULL, INTERNET_OPEN_TYPE_DIRECT, NULL, NULL, 0);
    if (NULL != hSession)
    {
        HINTERNET hHttp = InternetOpenUrlA(hSession,lpszUrl, NULL, 0,
            INTERNET_FLAG_DONT_CACHE|INTERNET_FLAG_RELOAD|INTERNET_FLAG_NO_CACHE_WRITE, 0);
        if (NULL != hHttp)
        {
            DWORD num = 0;
            const DWORD BUFFER_SIZE = 8192;
            char buffer[BUFFER_SIZE];
            do
            {
                if(InternetReadFile(hHttp, buffer, BUFFER_SIZE, &num))
                {
                    content.append(buffer, num);
                    result = 0;
                }
            } while (num > 0);
            InternetCloseHandle(hHttp);
            hHttp = NULL;
        }

        InternetCloseHandle(hSession);
        hSession = NULL;
    }
    return result;
}

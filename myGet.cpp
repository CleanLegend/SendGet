
#include "myGet.h"
void MyGet::Init(const char* site)
{
	hIntSession = InternetOpenA("Test", INTERNET_OPEN_TYPE_DIRECT, NULL, NULL, 0);
	if (hIntSession != NULL) 
		hHttpSession = InternetConnectA(hIntSession, site, 80, 0, 0, INTERNET_SERVICE_HTTP, 0, NULL);
	
}
void MyGet::DeInit()
{
	InternetCloseHandle(hHttpRequest);
	InternetCloseHandle(hHttpSession);
	InternetCloseHandle(hIntSession);
}
void MyGet::SendGet(const char* Url,std::string &Buffer)
{
	hHttpRequest = HttpOpenRequestA(hHttpSession, "GET", Url, 0, 0, 0, INTERNET_FLAG_RELOAD, 0);
	CHAR* szHeaders = "Content-Type: text/html\nMyHeader: Check text"; CHAR szReq[1024] = "";
	HttpSendRequestA(hHttpRequest, szHeaders, strlen(szHeaders), szReq, strlen(szReq));
	CHAR szBuffer[1025]; DWORD dwRead = 0;
	while (InternetReadFile(hHttpRequest, szBuffer, sizeof(szBuffer) - 1, &dwRead) && dwRead)
	{
		szBuffer[dwRead] = 0;
		dwRead = 0;
	}
	Buffer.append(szBuffer, sizeof(szBuffer));
}

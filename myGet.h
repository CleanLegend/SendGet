#pragma once

#include <windows.h>
#include <wininet.h>
#pragma comment(lib,"wininet")
#include <string>



class MyGet
{
public:
	void Init(const char* site);
	void DeInit();
	void SendGet(const char* Url, std::string &Buffer);
private:
	HINTERNET hIntSession;
	HINTERNET hHttpSession;
	HINTERNET hHttpRequest;
};

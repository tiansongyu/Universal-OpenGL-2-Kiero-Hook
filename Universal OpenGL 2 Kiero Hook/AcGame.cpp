#include "AcGame.h"

void AcGame::init()
{
	setModuleBaseAddress((WCHAR*)L"ac_client.exe");
}

void AcGame::setModuleBaseAddress(WCHAR* str)
{
	DWORD id = GetCurrentProcessId();
	this->BaseAddress = UTIL::dwGetModuleBaseAddress(id, (TCHAR*)str);
}

#include "AcGame.h"

void AcGame::init()
{
	setModuleBaseAddress((WCHAR*)L"ac_client.exe");
	init_base_address();
}

void AcGame::init_base_address()
{
	this->entiylist = *(entiyList**)GAME_OFFSET(0x187C10);
	this->local_player = *(player**)GAME_OFFSET(0x17B0B8);
	AC::Base::MatrixAddress = (Matrixf*)GAME_OFFSET(0x17afd8+8);
}

void AcGame::setModuleBaseAddress(WCHAR* str)
{
	DWORD id = GetCurrentProcessId();
	baseAddress = UTIL::dwGetModuleBaseAddress(id, (TCHAR*)str);
}

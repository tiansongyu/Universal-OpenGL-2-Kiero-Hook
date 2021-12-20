#pragma once
#include "datastruct.h"
#include "Util.h"
#include <Windows.h>
class AcGame
{
public:
	void init();

	inline void update()
	{
		this->entiylist = *(entiyList**)		GAME_OFFSET(0x187C10);
		this->numPlayers = *(int*)				GAME_OFFSET(0x18EFE4);
		this->local_player = *(player**)		GAME_OFFSET(0x17B0B8);
	}

public:
	int BaseAddress = 0;
	int numPlayers = 0;
	player* local_player = nullptr;
	entiyList* entiylist = nullptr;

private:
	void setModuleBaseAddress(WCHAR* str);


};


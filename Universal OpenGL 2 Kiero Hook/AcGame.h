#ifndef AcGame__
#define AcGame__

#include "gamestruct.h"
#include <cstdint>
#include <Windows.h>
#include "Util.h"
#include "include/imgui/imgui.h"
#include "AcGame.h"
#include "base.h"
#include <vector>
using namespace std;
class playerinfo_t
{
public:
	bool isValid = false;
	player* ent = nullptr;
	vec pos2D{};
	vec pos3D{};
	vec headpos3D{};
	vec headpos2D{};

	playerinfo_t(player* ent, float width, float height);
};

class AcGame
{
public:
	void Init();

	void Update()
	{
		this->numPlayers = *(int*)GAME_OFFSET(0x18EFE4);
		this->entiylist = *(entiyList**)GAME_OFFSET(0x187C10);
		this->local_player = *(player**)GAME_OFFSET(0x17B0B8);
	}
	void DrawBox();

	void DrawOnePlayer(playerinfo_t* playerinfo);

public:
	// init once
	int baseAddress = 0;
	player* local_player = nullptr;
	entiyList* entiylist = nullptr;
	// need to update
	int numPlayers = 0;

private:
	void SetModuleBaseAddress(WCHAR* str);
	void Init_base_address();


};



#endif // AcGame__

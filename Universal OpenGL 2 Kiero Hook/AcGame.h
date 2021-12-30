#ifndef AcGame__
#define AcGame__

#include "datastruct.h"
#include <cstdint>
#include <Windows.h>
#include "Util.h"
#include "include/imgui/imgui.h"
#include "AcGame.h"
#include "varAddress.h"

class playerinfo_t
{
public:
	bool isValid = false;
	player* ent = nullptr;
	vec pos2D{};
	vec pos3D{};
	vec headpos3D{};
	vec headpos2D{};

	playerinfo_t(player* ent, float width, float height)
	{
		bool check = true;


		this->ent = ent;
		// ÅÐ¶ÏÉúËÀ
		if (check)
		{
			this->headpos3D = this->ent->head;
			this->pos3D = this->ent->pos;
			check &= WorldToScreen(this->pos3D, &this->pos2D);
			check &= WorldToScreen(this->headpos3D, &this->headpos2D);
			this->isValid = check;
		}
	}


};

class AcGame
{
public:
	void init();

	inline void update()
	{
		this->numPlayers = *(int*)GAME_OFFSET(0x18EFE4);
	}
	void drawBox()
	{
		for (int i = 0; i < this->numPlayers; i++)
		{
			player* ent = entiylist->player_ptr[i];
			playerinfo_t playerinfo(ent, (float)AC::Base::WindowWidth, (float)AC::Base::WindowHeigth);
			if (playerinfo.isValid)
			{
				drawOnePlayer(&playerinfo);
			}
		}
	}

	void drawOnePlayer(playerinfo_t* playerinfo)
	{
		ImDrawList* Draw = ImGui::GetBackgroundDrawList();

		float Height = playerinfo->pos2D.y - playerinfo->headpos2D.y;

		float BoxWidth = Height / 2;
		float BoxHeigth = Height;

		ImVec2 TopLeft = { playerinfo->headpos2D.x - BoxWidth / 2,playerinfo->headpos2D.y };
		ImVec2 BottomLeft = { playerinfo->headpos2D.x - BoxWidth / 2 ,playerinfo->pos2D.y };
		ImVec2 BottomRight = { playerinfo->headpos2D.x + BoxWidth / 2 ,playerinfo->pos2D.y };
		ImVec2 TopRight = { playerinfo->headpos2D.x + BoxWidth / 2,playerinfo->headpos2D.y };

		ImColor BoxColor = { 0xff,0,0,0xff };

		Draw->AddQuad(TopLeft, BottomLeft, BottomRight, TopRight, BoxColor, 2.0f);
		Draw->AddQuad({ 11,11 }, { 11,200 }, { 200,200 }, { 200,11 }, BoxColor, 2.0f);

	}

public:
	// init once
	int baseAddress = 0;
	player* local_player = nullptr;
	entiyList* entiylist = nullptr;
	// need to update
	int numPlayers = 0;

private:
	void setModuleBaseAddress(WCHAR* str);
	void init_base_address();

};



#endif // AcGame__

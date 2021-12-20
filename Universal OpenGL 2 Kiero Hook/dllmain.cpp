#include <Windows.h>
#include "include/imgui_hook.h"
#include "include/imgui/imgui.h"
#include "datastruct.h"
#include "Util.h"
#include "AcGame.h"
bool isDisplay = false;
bool isFirst = true;

AcGame* acgame;
void RenderMain()
{
	if (isFirst)
	{
		acgame = new AcGame();
		acgame->init();
		isFirst = false;
	}

	if (ImGui::IsKeyPressed(ImGui::GetKeyIndex(ImGuiKey_Z)))
		isDisplay = !isDisplay;

	if (isDisplay)
	{
		acgame->update();

		ImGui::Begin("ac hack");


		ImGui::Text("player angle: %f %f %f", acgame->local_player->angle.x,  acgame->local_player->angle.y, acgame->local_player->angle.z);
		// ImGui::Text("current weapon name: %s", local_player->current_weapon_ptr->weapon_name_ptr);
		ImGui::Text("player number is %d", acgame->numPlayers);
		for (int i = 0; i < acgame->numPlayers; i++)
		{
			ImGui::Text("%d is %s", i + 1, (char*)&(acgame->entiylist->player_ptr[i]->player_name));
		}

		ImGui::End();
	}
}

BOOL WINAPI DllMain(HMODULE hMod, DWORD dwReason, LPVOID lpReserved)
{
	switch (dwReason)
	{
	case DLL_PROCESS_ATTACH:
		DisableThreadLibraryCalls(hMod);
		ImGuiHook::Load(RenderMain);
		break;
	case DLL_PROCESS_DETACH:
		delete acgame;
		ImGuiHook::Unload();
		
		break;
	}
	return TRUE;
}
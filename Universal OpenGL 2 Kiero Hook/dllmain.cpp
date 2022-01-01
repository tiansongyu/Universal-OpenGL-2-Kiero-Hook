#include <stdarg.h>
#include <Windows.h>
#include <TlHelp32.h>
#include <tchar.h>
#include <cstdint>
#include <cstdio>
#include <iostream>
#include "include/imgui/imgui.h"
#include "include/imgui_hook.h"

#include "AcGame.h"
#include "base.h"
using namespace std;
bool isDisplay = true;
bool isFirst = true;
bool isBox = true;
AcGame* acgame;
void RenderMain()
{
	if (isFirst)
	{
		acgame = new AcGame();
		acgame->Init();
		isFirst = false;

		/*AllocConsole();
		FILE* f = new FILE();
		freopen_s(&f, "CONOUT$", "w", stdout);*/
	}

	if (ImGui::IsKeyPressed(ImGui::GetKeyIndex(ImGuiKey_Z)))
		isDisplay = !isDisplay;

	if (ImGui::IsKeyPressed(ImGui::GetKeyIndex(ImGuiKey_Z)))
		isBox = !isBox;

	if (isDisplay)
	{
		acgame->Update();
		if(acgame->numPlayers > 0 && acgame->numPlayers < 50 && isBox)
			acgame->DrawBox();
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
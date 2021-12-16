#include <Windows.h>
#include "include/imgui_hook.h"
#include "include/imgui/imgui.h"
#include "Util.h"
static int number = 1;


void RenderMain() 
{
	ImGui::Begin("Window Title");
	if (ImGui::Button("health button"))
	{
		(*(UTIL::get_offset_pointer(4,0x400000,0x1880C4,0,0x408)))++;
	}
	if (ImGui::Button("bullet button"))
	{
		(*(UTIL::get_offset_pointer(3, 0x400000, 0x187C0C, 0xEC + 0x54)))++;
	}
	if ( ImGui::IsKeyPressed(ImGui::GetKeyIndex(ImGuiKey_Z)))
	{
		(*(UTIL::get_offset_pointer(3, 0x400000, 0x187C0C, 0xEC + 0x54)))++;
	}
	ImGui::Text("health = %x", *(UTIL::get_offset_pointer(4, 0x400000, 0x1880C4, 0, 0x408)));
	ImGui::Text("bullet = %x", *(UTIL::get_offset_pointer(3, 0x400000, 0x187C0C, 0xEC + 0x54)));

	ImGui::End();
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
		ImGuiHook::Unload();
		break;
	}
	return TRUE;
}
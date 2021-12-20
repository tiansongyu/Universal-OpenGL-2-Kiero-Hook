#pragma once
#pragma once
#include <cstdint>
struct Vector3 { float x, y, z; };

// BaseAddress + offset 
#define GAME_OFFSET(offset) (&((char*)this->BaseAddress)[offset])
// Created with ReClass.NET 1.2 by KN4CK3R

class player
{
public:
	char pad_0000[40]; //0x0000
	Vector3 pos; //0x0028
	Vector3 angle; //0x0034
	char pad_0040[220]; //0x0040
	int32_t ammo_1_retain; //0x011C
	char pad_0120[12]; //0x0120
	int32_t ammo_2; //0x012C
	char pad_0130[16]; //0x0130
	int32_t ammo_1; //0x0140
	char pad_0144[193]; //0x0144
	char player_name[16]; //0x0205
	char pad_0215[259]; //0x0215
	bool team; //0x0318
	char pad_0319[75]; //0x0319
	class current_weapon* current_weapon_ptr; //0x0364
}; //Size: 0x0368

class current_weapon
{
public:
	char pad_0000[8]; //0x0000
	class player* player_ptr; //0x0008
	char* weapon_name_ptr; //0x000C
	void* current_weapon_ammo_retaion_ptr; //0x0010
	int32_t* current_weapon_ammo_ptr; //0x0014
}; //Size: 0x0018

class entiyList
{
public:
	char pad_0000[4]; //0x0000
	class player* player_ptr[31]; //0x0004
	char pad_0080[1228]; //0x0080
}; //Size: 0x054C
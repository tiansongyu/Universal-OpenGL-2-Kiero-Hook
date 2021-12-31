#ifndef datastruct__
#define datastruct__

#include <cstdint>


struct vec
{
	union {
		struct { float x, y, z; };
		float v[3];
		int i[3];
	};
};

struct vec4
{
	union {
		struct { float x, y, z, w; };
		float v[4];
		int i[4];
	};
};

struct Matrixf
{
	float v[16];

	float operator[](int i)const { return v[i]; }
	float& operator[](int i) { return v[i]; }

	float transformx(const vec& p) const
	{
		return p.x * v[0] + p.y * v[4] + p.z * v[8] + v[12];
	}

	float transformy(const vec& p) const
	{
		return p.x * v[1] + p.y * v[5] + p.z * v[9] + v[13];
	}

	float transformz(const vec& p) const
	{
		return p.x * v[2] + p.y * v[6] + p.z * v[10] + v[14];
	}

	float transformw(const vec& p) const
	{
		return p.x * v[3] + p.y * v[7] + p.z * v[11] + v[15];
	}

	void transform(const vec& in, vec4& out) const
	{
		out.x = transformx(in);
		out.y = transformy(in);
		out.z = transformz(in);
		out.w = transformw(in);
	}
};
// BaseAddress + offset 
#define GAME_OFFSET(offset) (&((char*)this->baseAddress)[offset])
// Created with ReClass.NET 1.2 by KN4CK3R

class player
{
public:
	char pad_0000[1]; //0x0000
	vec head;
	char pad_0001[24];
	vec pos; //0x0028
	vec angle; //0x0034
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





#endif // datastdatastruct__ruct



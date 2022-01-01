#ifndef datastruct__
#define datastruct__

#include <cstdint>


class entiyList
{
public:
	char pad_0000[4]; //0x0000
	class player* player_ptr[31]; //0x0004
	char pad_0080[1228]; //0x0080
}; //Size: 0x054C

class weapon_info
{
public:
	char N0000077C[16]; //0x0000
	char pad_0010[86]; //0x0010
	bool isAutoGun; //0x0066
	char pad_0067[9]; //0x0067
}; //Size: 0x0070


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

// Created with ReClass.NET 1.2 by KN4CK3R

using Vector3 = vec;


class player
{
public:
	char pad_0000[4]; //0x0000
	Vector3 head; //0x0004
	char pad_0010[24]; //0x0010
	Vector3 pos; //0x0028
	Vector3 angle; //0x0034
	char pad_0040[37]; //0x0040
	bool is_not_Attacked; //0x0065
	char pad_0066[16]; //0x0066
	bool isDied; //0x0076
	char pad_0077[117]; //0x0077
	uint32_t health; //0x00EC
	int32_t armor; //0x00F0
	char pad_00F4[272]; //0x00F4
	bool isAttacking; //0x0204
	char name[16]; //0x0205
	char pad_0215[247]; //0x0215
	int8_t team; //0x030C
	char pad_030D[87]; //0x030D
	class current_weapon* current_weapon_ptr; //0x0364
	char pad_0368[80]; //0x0368
}; //Size: 0x03B8




class current_weapon
{
public:
	char pad_0000[8]; //0x0000
	class player* player_ptr; //0x0008
	class weapon_info* weapon_info_ptr; //0x000C
	void* current_weapon_ammo_retaion_ptr; //0x0010
	int32_t* current_weapon_ammo_ptr; //0x0014
	char pad_0018[4]; //0x0018
	int32_t shots_numbers; //0x001C
	char pad_0020[120]; //0x0020
}; //Size: 0x0098



#endif // datastdatastruct__ruct



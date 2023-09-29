#pragma once
#include "../../dependencies/utilities/crc32.hpp"

enum cmd_buttons {
	in_attack = (1 << 0),
	in_jump = (1 << 1),
	in_duck = (1 << 2),
	in_forward = (1 << 3),
	in_back = (1 << 4),
	in_use = (1 << 5),
	in_cancel = (1 << 6),
	in_left = (1 << 7),
	in_right = (1 << 8),
	in_moveleft = (1 << 9),
	in_moveright = (1 << 10),
	in_attack2 = (1 << 11),
	in_run = (1 << 12),
	in_reload = (1 << 13),
	in_alt1 = (1 << 14),
	in_alt2 = (1 << 15),
	in_score = (1 << 16),
	in_speed = (1 << 17),
	in_walk = (1 << 18),
	in_zoom = (1 << 19),
	in_weapon1 = (1 << 20),
	in_weapon2 = (1 << 21),
	in_bullrush = (1 << 22),
	in_grenade1 = (1 << 23),
	in_grenade2 = (1 << 24)
};

struct c_usercmd {
	[[nodiscard]] CRC32_t get_checksum() const
	{
		CRC32_t uHashCRC = 0UL;

		CRC32::Init(&uHashCRC);
		CRC32::ProcessBuffer(&uHashCRC, &command_number, sizeof(command_number));
		CRC32::ProcessBuffer(&uHashCRC, &tick_count, sizeof(tick_count));
		CRC32::ProcessBuffer(&uHashCRC, &viewangles, sizeof(viewangles));
		CRC32::ProcessBuffer(&uHashCRC, &aimdirection, sizeof(aimdirection));
		CRC32::ProcessBuffer(&uHashCRC, &forwardmove, sizeof(forwardmove));
		CRC32::ProcessBuffer(&uHashCRC, &sidemove, sizeof(sidemove));
		CRC32::ProcessBuffer(&uHashCRC, &upmove, sizeof(upmove));
		CRC32::ProcessBuffer(&uHashCRC, &buttons, sizeof(buttons));
		CRC32::ProcessBuffer(&uHashCRC, &impulse, sizeof(impulse));
		CRC32::ProcessBuffer(&uHashCRC, &weaponselect, sizeof(weaponselect));
		CRC32::ProcessBuffer(&uHashCRC, &weaponsubtype, sizeof(weaponsubtype));
		CRC32::ProcessBuffer(&uHashCRC, &randomseed, sizeof(randomseed));
		CRC32::ProcessBuffer(&uHashCRC, &mousedx, sizeof(mousedx));
		CRC32::ProcessBuffer(&uHashCRC, &mousedy, sizeof(mousedy));
		CRC32::Final(&uHashCRC);

		return uHashCRC;
	}

	int pad;
	int command_number;
	int tick_count;
	vec3_t viewangles;
	vec3_t aimdirection;
	float forwardmove;
	float sidemove;
	float upmove;
	int buttons;
	char impulse;
	int weaponselect;
	int weaponsubtype;
	int randomseed;
	short mousedx;
	short mousedy;
	bool predicted;
	char pad_0x4C[0x18];
};

class c_verified_user_cmd
{
public:
	c_usercmd user_cmd;
	CRC32_t u_hash_crc;
};
#pragma once
#include "../../source-sdk/classes/c_usercmd.hpp"

class i_input {
public:
    std::byte            pad0[0xC];            // 0x0
    bool                bTrackIRAvailable;        // 0xC
    bool                bMouseInitialized;        // 0xD
    bool                bMouseActive;            // 0xE
    std::byte            pad1[0x9A];            // 0xF
    bool                bCameraInThirdPerson;    // 0xA9
    std::byte            pad2[0x2];            // 0xAA
    vec3_t                vecCameraOffset;        // 0xAC
    std::byte            pad3[0x38];            // 0xB8
    c_usercmd* m_pCommands;            // 0xF0
	c_verified_user_cmd* p_verified_commands;		//0xF8

	c_usercmd* get_user_cmd(int slot, int sequence_num) {
		using fn = c_usercmd * (__thiscall*)(void*, int, int);
		return (*(fn**)this)[8](this, slot, sequence_num);
	}

	[[nodiscard]] c_verified_user_cmd* get_verified_cmd(const int sequence_num) const
	{
		return &p_verified_commands[sequence_num % 150];
	}
};

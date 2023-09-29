#include "../../features.hpp"
// https://youtu.be/Y0FEnfp7y8g
void antiaim::legitaa::update_lowerbody_breaker() {

	if (!variables::legit_aa_enable)
		return;

	if (!variables::legit_aa)
		return;

	if (!csgo::local_player || !csgo::local_player->is_alive())
		return;

	float speed = csgo::local_player->velocity().length_2d_sqr();

	if (speed > 0.1)
		variables::next_update = csgo::server_time() + 0.22;

	variables::break_lby = false;

	if (variables::next_update <= csgo::server_time()) {
		variables::next_update = csgo::server_time() + 1.1;
		variables::break_lby = true;
	}

	if (!(csgo::local_player->flags() & fl_onground))
		variables::break_lby = false;
}

void antiaim::legitaa::legit_antiaim_run(c_usercmd* cmd, bool& send_packet) {
	if (!variables::legit_aa_enable)
		return;

	if (!variables::legit_aa)
		return;

	if (!csgo::local_player || !csgo::local_player->is_alive())
		return;

	if (csgo::local_player->move_type() == movetype_ladder)
		return;

	if (cmd->buttons & in_attack)
		return;

	auto net_channel = interfaces::clientstate->net_channel;

	if (!net_channel)
		return;

	send_packet = net_channel->choked_packets >= 3;

	auto weapon = csgo::local_player->active_weapon();

	if (!weapon || weapon->is_nade())
		return;

	if (GetAsyncKeyState(VK_LBUTTON) || GetAsyncKeyState(VK_RBUTTON) || (GetAsyncKeyState(0x45)))
		return;

	if (variables::break_lby) {
		send_packet = false;
		cmd->viewangles.y += 120.f;
	}
	else if (!send_packet)
		cmd->viewangles.y -= 120.f;

	cmd->viewangles.clamp();
}

// thanks solidhax for this amazing thing (my eyes hurt, every time i look at this feature in game) (thanks tho, helped alot)
#define sig_player_by_index "85 C9 7E 32 A1"
#define sig_draw_server_hitboxes "55 8B EC 81 EC ? ? ? ? 53 56 8B 35 ? ? ? ? 8B D9 57 8B CE"

void antiaim::legitaa::show_hitbox() {
	if (!variables::server_hitbox)
		return;

	if (!interfaces::engine->is_connected() || !interfaces::engine->is_in_game())
		return;

	if (!csgo::local_player || !csgo::local_player->is_alive())
		return;

	if (!interfaces::input->bCameraInThirdPerson)
		return;

	auto get_player_by_index = [](int index) -> player_t* {
		typedef player_t* (__fastcall* player_by_index)(int);
		static auto player_index = reinterpret_cast<player_by_index>(utilities::pattern_scan("server.dll", sig_player_by_index));

		if (!player_index)
			return false;

		return player_index(index);
	};

	static auto fn = reinterpret_cast<uintptr_t>(utilities::pattern_scan("server.dll", sig_draw_server_hitboxes));
	auto duration = -1.f;
	PVOID entity = nullptr;

	entity = get_player_by_index(csgo::local_player->index());

	if (!entity)
		return;

	__asm {
		pushad
		movss xmm1, duration
		push 0 // 0 - colored, 1 - blue
		mov ecx, entity
		call fn
		popad
	}
}
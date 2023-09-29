#include "../../features.hpp"

int random(int min, int max) {
	static bool first = true;
	if (first) {
		srand(time(NULL));
		first = false;
	}
	return min + rand() % ((max + 1) - min);
}
// yeah wtf is this 💀
using random_float = float(__cdecl*)(float, float);
random_float randomf;

void antiaim::rageaa::ideal_pitch(c_usercmd* cmd) {
	anim_state* state = csgo::local_player->get_anim_state();

	if (!state)
		return;

	cmd->viewangles.x = state->min_pitch;
}

void antiaim::rageaa::run(c_usercmd* cmd, bool& send_packet) {
	if (!csgo::local_player)
		return;

	if (!variables::rage_aa_enable)
		return;

	weapon_t* active_weapon = csgo::local_player->active_weapon();
	if (!active_weapon) return;

	if (cmd->buttons & in_attack ||
		cmd->buttons & in_use ||
		csgo::local_player->move_type() == movetype_ladder ||
		csgo::local_player->move_type() == movetype_noclip ||
		active_weapon->is_knife() && (cmd->buttons & in_attack || cmd->buttons & in_attack2) ||
		active_weapon->is_c4() && cmd->buttons & in_attack)
		return;

	if (active_weapon->is_nade() && !active_weapon->pin_pulled()) {
		float throw_time = active_weapon->throw_time();
		if (throw_time > 0) {
			send_packet = false;
			return;
		}
	}
	// pitch "Ideal", "Up", "Down", "Random"
	switch (variables::rage_aa_opt1) {
	case 1:
		ideal_pitch(cmd); // ideal/minimal
		break;
	case 2:
		cmd->viewangles.x -= 89.f; // up
		break;
	case 3:
		cmd->viewangles.x += 89.f; // down
		break;
	case 4:
		cmd->viewangles.x += random(-89, 89);
		break;
	default: break;
	}
	// yaw "Backwards", "Spin", "Static", "180z"
	switch (variables::rage_aa_opt2) {
	case 1:
		cmd->viewangles.y += variables::backwards_deg; // backwards/name - 180 + degree slider
		break;
	case 2:
		cmd->viewangles.y -= random(-360, 360); // spin
		break;
	case 3:
		cmd->viewangles.y += variables::static_deg; // static + deg slider
		break;
	case 4: break; // 180z aa?
	}

	// yaw jitter
	switch (variables::rage_aa_opt3) {
	case 1:
		cmd->viewangles.y += random(-35, 35); // jitter
		break;
	case 2:
		cmd->viewangles.y += random(-360, 360); // random
		break;
	default: break;
	}
}

float anglediff(float destAngle, float srcAngle) {
	float delta;

	delta = fmodf(destAngle - srcAngle, 360.0f);
	if (destAngle > srcAngle) {
		if (delta >= 180)
			delta -= 360;
	}
	else {
		if (delta <= -180)
			delta += 360;
	}
	return delta;
}

static float next_lby;
static float side;

void antiaim::rageaa::update_lby()
{
	anim_state* local_animation_state = csgo::local_player->get_anim_state();

	if (local_animation_state->speed_2d > 0.1f || std::fabsf(local_animation_state->up_velocity)) {
		next_lby = interfaces::globals->cur_time + 0.22f;
	}
	else if (interfaces::globals->cur_time > next_lby) {
		if (std::fabsf(anglediff(local_animation_state->goal_feet_yaw, local_animation_state->eye_yaw)) > 35.0f) {
			next_lby = interfaces::globals->cur_time + 1.1f;
		}
	}
}

void antiaim::rageaa::desync(c_usercmd* cmd, bool& send_packet) {
	if (!variables::desync_antiaim)
		return;
	// dsync when? desync who? desync WHYYYY 
	weapon_t* active_weapon = csgo::local_player->active_weapon();
	if (!active_weapon) return;

	if (cmd->buttons & in_attack ||
		cmd->buttons & in_use ||
		csgo::local_player->move_type() == movetype_ladder ||
		csgo::local_player->move_type() == movetype_noclip ||
		active_weapon->is_knife() && (cmd->buttons & in_attack || cmd->buttons & in_attack2) ||
		active_weapon->is_c4() && cmd->buttons & in_attack)
		return;

	if (active_weapon->is_nade() && !active_weapon->pin_pulled()) {
		float throw_time = active_weapon->throw_time();
		if (throw_time > 0) {
			send_packet = false;
			return;
		}
	}

	// shawty came from mexico she want that swetso??????? 🤔💃💃💃💃
	if (variables::desync_option == 0) {
		if (!send_packet) {
			cmd->viewangles.y += 120.f; // random
		}
		else {
			cmd->viewangles.y -= 120.f; // random
		}
	}

	if (variables::desync_option == 1) {
		// add smthng dud
	}
}

/* customhooks more like cusotm noose around my fucking neck :)
// TODO: test this shit... - how do i even test this shit? maybe fake local_player chams huh? yeah time to code fake angle chams
void antiaim::rageaa::fake_angles(bool& send_packet, c_usercmd* cmd) {
	send_packet = true;

	if (!csgo::local_player)
		return;

	if (!variables::rage_aa_enable)
		return;

	// get fake jitter range from variable - used in relative jitter
	//float range = variables::aa_range_relative_jitter / 2.f;

	switch (variables::rage_aa_fake_enable) {
	case 1: // default
		// set base to opposite of direction.
		cmd->viewangles.y = direction + 180.f;

		// apply 45 degree jitter.
		cmd->viewangles.y += random(-90.f, 90.f);
		break;
	case 2: // relative jitter
		// set base to opposite of direction
	//	cmd->viewangles.y = direction + 180.f;

		// apply jitter
	//	cmd->viewangles.y += randomf(-range, range);
		break;
	case 3: // random
		// dont worry, my retarded ass cant understand this too, or i can because i coded it but i aint explainin shit to your ass (excuses)
		cmd->viewangles.y = direction + 90.f + std::fmod(interfaces::globals->cur_time * 360.f, 180.f);
		break;
	case 4: // local
		cmd->viewangles.y = cmd->viewangles.y;
		break;
	default: break;
	}

	// normalize fake angle.
	math::normalize_angle(cmd->viewangles.y);
}

// alien antiaim (wont antiaim for shit :))
void antiaim::rageaa::test_aa(bool& send_packet, c_usercmd* cmd) {
	if (!variables::test_aaa)
		return;

	send_packet = true;

	if (!csgo::local_player || !csgo::local_player->is_alive() || !csgo::local_player->get_anim_state())
		return;
	// i love this animation fix, but dropping a toaster into a bath is very tempting
	anim_state* local_animation_state = csgo::local_player->get_anim_state();

	csgo::local_player->update_animation_state(local_animation_state, csgo::fake_angles);

	static float realangle = 90.f;
	realangle = cmd->viewangles.z;

	local_animation_state->goal_feet_yaw = csgo::fake_angles.y;

	float server_time = csgo::local_player->get_tick_base() * interfaces::globals->interval_per_tick;
	float time = TIME_TO_TICKS(server_time);

	while (time >= server_time)
		time = 0.f;

	if (time >= server_time / 2)
	{
		auto net_channel = interfaces::clientstate->net_channel;

		if (!net_channel)
			return;

		send_packet = net_channel->choked_packets >= 3;

		cmd->viewangles.y = realangle - variables::test_aa;
		cmd->viewangles.z += 80.f;
		ideal_pitch(cmd);
	}
}
*/
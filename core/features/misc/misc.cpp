#include "../features.hpp"

void misc::loop_misc() {
	if (!variables::misc_enable)
		return;

	misc::world::disable_post_processing();
	misc::client::recoil_crosshair();
	misc::client::force_crosshair();
}

void misc::loop_movement(c_usercmd* cmd) {
	if (!variables::movement_enable)
		return;

	misc::movement::adv_bhop(cmd);
	misc::movement::bunny_hop(cmd);
	misc::movement::strafe(cmd);
}

void misc::movement::bunny_hop(c_usercmd* cmd) {

	if (!variables::bhop)
		return;

	auto move_type = csgo::local_player->move_type();

	if (move_type == movetype_ladder)
		return;

	if (!(csgo::local_player->flags() & fl_onground))
		cmd->buttons &= ~in_jump;
};

void misc::movement::strafe(c_usercmd* cmd) {

	if (!variables::strafe)
		return;

	if (!csgo::local_player || !csgo::local_player->is_alive())
		return;

	if (!interfaces::inputsystem->is_button_down(button_code_t::KEY_SPACE))
		return;

	if (interfaces::inputsystem->is_button_down(button_code_t::KEY_S) || interfaces::inputsystem->is_button_down(button_code_t::KEY_D) || interfaces::inputsystem->is_button_down(button_code_t::KEY_A) || interfaces::inputsystem->is_button_down(button_code_t::KEY_W))
		return;

	if (csgo::local_player->move_type() == movetype_noclip || csgo::local_player->move_type() == movetype_ladder)
		return;

	if (!(csgo::local_player->flags() & fl_onground))
	{
		if (cmd->mousedx > 1 || cmd->mousedx < -1)
			cmd->sidemove = cmd->mousedx < 0.f ? -450.0f : 450.0f;
		else
		{
			cmd->forwardmove = std::clamp(10000.f / csgo::local_player->velocity().length_2d(), -450.f, 450.f);
			cmd->sidemove = cmd->command_number % 2 == 0 ? -450.f : 450.f;
		}
	}
}
// do it so if i enable adv_bhop, disable normal bhop + strafe
void misc::movement::adv_bhop(c_usercmd* cmd) {
	if (!variables::adv_bhop)
		return;

	auto local_player = reinterpret_cast<player_t*>(interfaces::entity_list->get_client_entity(interfaces::engine->get_local_player()));
	const float hitchance = variables::bhop_hits;
	const float restrict_limit = 12;
	const float hop_limit = variables::bhop_maxv;
	const float min_hop = variables::bhop_minv;
	static float hops_restricted = 0;
	static float hops_hit = 0;

	if (!local_player)
		return;

	if (local_player->move_type() == movetype_ladder || local_player->move_type() == movetype_noclip)
		return;

	if (cmd->buttons & in_jump && !(local_player->flags() & fl_onground)) {
		cmd->buttons &= ~in_jump;
		hops_restricted = 0;
	}

	else if ((rand() % 100 > hitchance && hops_restricted < restrict_limit) || (hop_limit > 0 && hops_hit > hop_limit && min_hop > 0 && hops_hit > min_hop)) {
		cmd->buttons &= ~in_jump;
		hops_restricted++;
		hops_hit = 0;
	}
	else {
		hops_hit++;
	}
};

void misc::world::disable_post_processing() noexcept {
	static auto mat_postprocess_enable = interfaces::console->get_convar("mat_postprocess_enable");
	mat_postprocess_enable->set_value(variables::disable_post_processing ? 0 : 1);
}

void misc::client::recoil_crosshair() noexcept {
	static auto cl_crosshair_recoil = interfaces::console->get_convar("cl_crosshair_recoil");
	cl_crosshair_recoil->set_value(variables::recoil_crosshair ? 1 : 0);
}

void misc::client::force_crosshair() noexcept {
	auto local_player = reinterpret_cast<player_t*>(interfaces::entity_list->get_client_entity(interfaces::engine->get_local_player()));
	static auto weapon_debug_spread_show = interfaces::console->get_convar("weapon_debug_spread_show");

	if (local_player && local_player->health() > 0) {
		weapon_debug_spread_show->set_value(local_player->is_scoped() || !variables::force_crosshair ? 0 : 3);
	}
}
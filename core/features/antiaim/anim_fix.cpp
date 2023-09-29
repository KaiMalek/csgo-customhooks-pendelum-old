#include "../features.hpp"

void antiaim::animation::animation_fix(bool& send_packet, c_usercmd* cmd) {
	if (!csgo::local_player || !csgo::local_player->is_alive() || !csgo::local_player->get_anim_state())
		return;
	// i love this animation fix, but dropping a toaster into a bath is very tempting
	anim_state* local_animation_state = csgo::local_player->get_anim_state();
	
	csgo::local_player->update_animation_state(local_animation_state, csgo::fake_angles);

	local_animation_state->goal_feet_yaw = csgo::real_angles.y;
}
// i need this, i think... yes i definately need it (how do i write the eight word in this sentence?)
void antiaim::animation::animation_sec(bool& send_packet, c_usercmd* cmd) {
	if (send_packet) {
		csgo::fake_angles = cmd->viewangles;
		csgo::real_angles = csgo::real_angles_stored;
	}

	if (!variables::break_lby)
		csgo::real_angles_stored = cmd->viewangles;
}
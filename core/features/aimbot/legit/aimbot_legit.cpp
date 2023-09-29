#include "../../features.hpp"


int aimbot::legit::get_nearest_bone(player_t* entity, c_usercmd* user_cmd) {
	auto local_player = reinterpret_cast<player_t*>(interfaces::entity_list->get_client_entity(interfaces::engine->get_local_player()));
	if (!local_player)
		return false;

	float best_dist = 360.f;


	matrix_t matrix[MAXSTUDIOBONES];

	if (!entity->setup_bones(matrix, 128, BONE_USED_BY_HITBOX, 0.0f))
		return -1;

	studio_hdr_t* studio_model = interfaces::model_info->get_studio_model(entity->model());
	if (!studio_model)
		return -1;

	studio_hitbox_set_t* set = studio_model->hitbox_set(entity->hitbox_set());
	if (!set)
		return -1;

	for (int i = 0; i < set->hitbox_count; i++) {
		if (i >= hitbox_max)
			continue;

		studio_box_t* hitbox = set->hitbox(i);

		if (!hitbox)
			continue;

		auto angle = math::calculate_angle2(local_player->get_eye_pos(), vec3_t(matrix[hitbox->bone][0][3], matrix[hitbox->bone][1][3], matrix[hitbox->bone][2][3]), user_cmd->viewangles);
		auto this_dist = std::hypotf(angle.x, angle.y);

		if (best_dist > this_dist) {
			best_dist = this_dist;
			aimbone = hitbox->bone;
			continue;
		}
	}
	return aimbone;
}

void aimbot::legit::weapon_settings(weapon_t* weapon) {
	if (!weapon)
		return;

	if (weapon->get_type() == IS_PISTOL) {
		switch (variables::aim_bone_pistol) {
		case 0:
			hitbox_id = hitbox_head;
			break;
		case 1:
			hitbox_id = hitbox_neck;
			break;
		case 2:
			hitbox_id = hitbox_chest;
			break;
		case 3:
			hitbox_id = hitbox_stomach;
			break;
		case 4:
			hitbox_id = hitbox_pelvis;
			break;
		}

		aim_smooth = variables::aim_smooth_pistol;
		aim_fov = variables::aim_fov_pistol;
		rcs_x = variables::rcs_x_pistol;
		rcs_y = variables::rcs_y_pistol;
	}
	if (weapon->get_type() == IS_RIFLE) {
		switch (variables::aim_bone_rifle) {
		case 0:
			hitbox_id = hitbox_head;
			break;
		case 1:
			hitbox_id = hitbox_neck;
			break;
		case 2:
			hitbox_id = hitbox_chest;
			break;
		case 3:
			hitbox_id = hitbox_stomach;
			break;
		case 4:
			hitbox_id = hitbox_pelvis;
			break;
		}

		aim_smooth = variables::aim_smooth_rifle;
		aim_fov = variables::aim_fov_rifle;
		rcs_x = variables::rcs_x_rifle;
		rcs_y = variables::rcs_y_rifle;
	}
	if (weapon->get_type() == IS_SNIPER) {
		switch (variables::aim_bone_sniper) {
		case 0:
			hitbox_id = hitbox_head;
			break;
		case 1:
			hitbox_id = hitbox_neck;
			break;
		case 2:
			hitbox_id = hitbox_chest;
			break;
		case 3:
			hitbox_id = hitbox_stomach;
			break;
		case 4:
			hitbox_id = hitbox_pelvis;
			break;
		}

		aim_smooth = variables::aim_smooth_sniper;
		aim_fov = variables::aim_fov_sniper;
		rcs_x = variables::rcs_x_sniper;
		rcs_y = variables::rcs_y_sniper;
	}
	if (weapon->get_type() == IS_HEAVY) {
		switch (variables::aim_bone_heavy) {
		case 0:
			hitbox_id = hitbox_head;
			break;
		case 1:
			hitbox_id = hitbox_neck;
			break;
		case 2:
			hitbox_id = hitbox_chest;
			break;
		case 3:
			hitbox_id = hitbox_stomach;
			break;
		case 4:
			hitbox_id = hitbox_pelvis;
			break;
		}

		aim_smooth = variables::aim_smooth_heavy;
		aim_fov = variables::aim_fov_heavy;
		rcs_x = variables::rcs_x_heavy;
		rcs_y = variables::rcs_y_heavy;
	}
	if (weapon->get_type() == IS_SMG) {
		switch (variables::aim_bone_smg) {
		case 0:
			hitbox_id = hitbox_head;
			break;
		case 1:
			hitbox_id = hitbox_neck;
			break;
		case 2:
			hitbox_id = hitbox_chest;
			break;
		case 3:
			hitbox_id = hitbox_stomach;
			break;
		case 4:
			hitbox_id = hitbox_pelvis;
			break;
		}

		aim_smooth = variables::aim_smooth_smg;
		aim_fov = variables::aim_fov_smg;
		rcs_x = variables::rcs_x_smg;
		rcs_y = variables::rcs_y_smg;
	}
}

int aimbot::legit::find_target(c_usercmd* user_cmd) {
	auto local_player = reinterpret_cast<player_t*>(interfaces::entity_list->get_client_entity(interfaces::engine->get_local_player()));
	if (!local_player)
		return false;

	auto best_fov = aim_fov;
	auto best_target = 0;

	for (int i = 1; i <= interfaces::globals->max_clients; i++) {
		auto entity = reinterpret_cast<player_t*>(interfaces::entity_list->get_client_entity(i));
		auto entity_bone_pos = entity->get_bone_position(get_nearest_bone(entity, user_cmd));
		auto local_eye_pos = local_player->get_eye_pos();
		auto distance = local_eye_pos.distance_to(entity_bone_pos);

		if (!entity || entity == local_player || entity->dormant() || !entity->is_alive() || entity->has_gun_game_immunity())
			continue;

		angle = math::calculate_angle2(local_eye_pos, entity_bone_pos, user_cmd->viewangles);
		auto fov = variables::aim_distance_based_fov ? math::distance_based_fov(distance, math::calculate_angle(local_eye_pos, entity_bone_pos), user_cmd) : std::hypotf(angle.x, angle.y);
		if (fov < best_fov) {
			best_fov = fov;
			best_target = i;
		}
	}
	return best_target;
}

void aimbot::legit::event_player_death(i_game_event* event) {
	if (!interfaces::engine->is_connected() && !interfaces::engine->is_in_game())
		return;

	auto local_player = reinterpret_cast<player_t*>(interfaces::entity_list->get_client_entity(interfaces::engine->get_local_player()));
	if (!local_player || !local_player->is_alive())
		return;

	auto attacker = interfaces::entity_list->get_client_entity(interfaces::engine->get_player_for_user_id(event->get_int("attacker")));
	if (!attacker)
		return;

	if (attacker == local_player)
		kill_delay = interfaces::globals->tick_count + variables::aimbot_delay_after_kill;
}

void aimbot::legit::run(c_usercmd* user_cmd) {
	auto local_player = reinterpret_cast<player_t*>(interfaces::entity_list->get_client_entity(interfaces::engine->get_local_player()));
	if (!local_player)
		return;

	if (kill_delay >= interfaces::globals->tick_count)
		return;

	auto weapon = local_player->active_weapon();
	weapon_settings(weapon);

	if (variables::aim_enabled && user_cmd->buttons & in_attack) {
		if (auto target = find_target(user_cmd)) {
			auto entity = reinterpret_cast<player_t*>(interfaces::entity_list->get_client_entity(target));

			if (!weapon || !weapon->clip1_count())
				return;

			if (!local_player->can_see_player_pos(entity, entity->get_eye_pos()))
				return;

			if (!variables::aim_team_check && !entity->is_enemy())
				return;

			if (!variables::smoke_check && utilities::is_behind_smoke(local_player->get_eye_pos(), entity->get_hitbox_position(hitbox_head)))
				return;

			if (weapon->get_type() == IS_KNIFE || weapon->get_type() == IS_GRENADE || weapon->get_type() == IS_MISC)
				return;

			if (weapon->get_type() == IS_SNIPER && !local_player->is_scoped() && !variables::scope_aim)
				return;

			auto recoil_scale = interfaces::console->get_convar("weapon_recoil_scale");
			auto aim_punch = local_player->aim_punch_angle() * recoil_scale->get_float(); //auto aim_punch = local_player->aim_punch_angle() * 2;
			aim_punch.x *= rcs_x;
			aim_punch.y *= rcs_y;

			switch (variables::aim_mode) {
			case 0:
				angle = math::calculate_angle2(local_player->get_eye_pos(), entity->get_hitbox_position(hitbox_id), user_cmd->viewangles + aim_punch);
				break;
			case 1:
				angle = math::calculate_angle2(local_player->get_eye_pos(), entity->get_bone_position(get_nearest_bone(entity, user_cmd)), user_cmd->viewangles + aim_punch);
				break;
			}

			angle /= aim_smooth;
			user_cmd->viewangles += angle;

			if (!variables::aim_silent) {
				interfaces::engine->set_view_angles2(user_cmd->viewangles);
			}
		}
	}
}
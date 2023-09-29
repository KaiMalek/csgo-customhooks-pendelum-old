#include "../features.hpp"

void visuals::loop_visuals() {
	if (!variables::enable_player_visuals)
		return;

	visuals::world::fog();
	visuals::world::remove_3dsky();
}

void visuals::client::watermark() {
	// TODO: put watermark on the bottom of the menu corner (outside the window) (im going insane) - (dont do that)
	if (!variables::watermark)
		return;

	int x, y;
	interfaces::engine->get_screen_size(x, y);

	if (std::strstr(GetCommandLineA(), "-insecure")) {
		render::draw_line(x - 13, 7, x - 269, 7, color(229, 137, 226, 245));
		render::draw_fade(x - 269, 8, 257, 14, color(0, 0, 0, 230), color(0, 0, 0, 0), false);
		render::text(x - 266, 8, render::fonts::watermark_font, "customhooks | [ALPHA] | Build: " __DATE__ " | -insecure", false, color(255, 255, 255, 190));
	}
	else {
		render::draw_line(x - 13, 7, x - 269, 7, color(229, 137, 226, 245));
		render::draw_fade(x - 269, 8, 257, 14, color(0, 0, 0, 230), color(0, 0, 0, 0), false);
		render::text(x - 266, 8, render::fonts::watermark_font, "customhooks | [ALPHA] | Build: " __DATE__ " | -insecure", false, color(255, 255, 255, 190));
	}
} 

void visuals::client::fov_changer() {
	if (!variables::fov_changer)
		return;

	if (!interfaces::engine->is_connected() || !interfaces::engine->is_in_game())
		return;

	if (!csgo::local_player || !csgo::local_player->is_alive())
		return;

	const auto view_model = reinterpret_cast<player_t*>(interfaces::entity_list->get_client_entity_handle(csgo::local_player->view_model()));

	if (!view_model)
		return;

	vec3_t forward{}, right{}, up{};
	math::angle_vectors_alternative(view_model->abs_angles(), &forward, &right, &up);

	view_model->set_abs_origin(view_model->abs_origin() + forward * variables::z_fov + up * variables::y_fov + right * variables::x_fov);
}

void visuals::world::remove_3dsky() {
	static auto mat_postprocess_enable = interfaces::console->get_convar("r_3dsky");
	mat_postprocess_enable->set_value(variables::remove_3dsky ? 0 : 1);
}

void visuals::world::fog() {
	interfaces::console->get_convar("fog_enable")->set_value(false);
	interfaces::console->get_convar("fog_enableskybox")->set_value(false);
	interfaces::console->get_convar("fog_override")->set_value(false);
	interfaces::console->get_convar("fog_end")->set_value(false);
	interfaces::console->get_convar("fog_start")->set_value(false);
	interfaces::console->get_convar("fog_maxdensity")->set_value(false);
	interfaces::console->get_convar("fog_colorskybox")->set_value(false);
	interfaces::console->get_convar("fog_endskybox")->set_value(false);
	interfaces::console->get_convar("fog_startskybox")->set_value(false);
	interfaces::console->get_convar("fog_maxdensityskybox")->set_value(false);
	interfaces::console->get_convar("fog_colorskybox")->set_value(false);
	interfaces::console->get_convar("fog_enable")->set_value(variables::fogenable);
	interfaces::console->get_convar("fog_enableskybox")->set_value(variables::fogenable);
	interfaces::console->get_convar("fog_override")->set_value(variables::fogenable);
	if (variables::fogenable) {
		interfaces::console->get_convar("fog_end")->set_value((float)variables::fogend);
		interfaces::console->get_convar("fog_start")->set_value((float)variables::fogstart);
		interfaces::console->get_convar("fog_maxdensity")->set_value(variables::fogmaxdensity);
		interfaces::console->get_convar("fog_endskybox")->set_value((float)variables::fogend);
		interfaces::console->get_convar("fog_startskybox")->set_value((float)variables::fogstart);
		interfaces::console->get_convar("fog_maxdensityskybox")->set_value(variables::fogmaxdensity);	}
}

// TODO: axiom method for sky changer

// im crying
void visuals::world::sky_changer() {
	if (!variables::sky_changer)
		return;

	static auto r_3dsky = interfaces::console->get_convar("r_3dsky");

	r_3dsky->set_value("0");

	static auto sv_skyname = interfaces::console->get_convar("sv_skyname");

	switch (variables::sky) {
	case 1: sv_skyname->set_value("cs_tibet"); 
		break;
	case 2: sv_skyname->set_value("cs_baggage_skybox_"); 
		break;
	case 3: sv_skyname->set_value("embassy");
		break;
	case 4: sv_skyname->set_value("italy");
		break;
	case 5: sv_skyname->set_value("jungle");
		break;
	case 6: sv_skyname->set_value("office");
		break;
	case 7: sv_skyname->set_value("sky_cs15_daylight01_hdr");
		break;
	case 8: sv_skyname->set_value("vertigoblue_hdr");
		break;
	case 9: sv_skyname->set_value("sky_cs15_daylight02_hdr");
		break;
	case 10: sv_skyname->set_value("vertigo");
		break;
	case 12: sv_skyname->set_value("sky_day02_05_hdr");
		break;
	case 13: sv_skyname->set_value("nukeblank");
		break;
	case 14: sv_skyname->set_value("sky_venice");
		break;
	case 15: sv_skyname->set_value("sky_cs15_daylight03_hdr");
		break;
	case 16: sv_skyname->set_value("sky_cs15_daylight04_hdr");
		break;
	case 17: sv_skyname->set_value("sky_csgo_cloudy01");
		break;
	case 18: sv_skyname->set_value("sky_csgo_night02");
		break;
	case 19: sv_skyname->set_value("sky_csgo_night02b");
		break;
	case 20: sv_skyname->set_value("sky_csgo_night_flat");
		break;
	case 21: sv_skyname->set_value("sky_lunacy");
		break;
	case 22: sv_skyname->set_value("sky_dust");
		break;
	case 23: sv_skyname->set_value("vietnam");
		break;
	case 24: sv_skyname->set_value("amethyst");
		break;
	case 25: sv_skyname->set_value("sky_descent");
		break;
	case 26: sv_skyname->set_value("clear_night_sky");
		break;
	case 27: sv_skyname->set_value("otherworld");
		break;
	case 28: sv_skyname->set_value("cloudynight");
		break;
	case 29: sv_skyname->set_value("dreamyocean");
		break;
	case 30: sv_skyname->set_value("grimmnight");
		break;
	case 31: sv_skyname->set_value("sky051");
		break;
	case 32: sv_skyname->set_value("sky081");
		break;
	case 33: sv_skyname->set_value("sky091");
		break;
	case 34: sv_skyname->set_value("sky561");
		break;
	default: sv_skyname->set_value("0"); 
		break;
	}
}

void visuals::client::information_client() {
	if (!variables::information_client)
		return;
	
	if (variables::menu::opened == !variables::information_client)
		return;

	int w = 80;
	int h = 250;

	render::draw_filled_rect(variables::menu::x + 355, variables::menu::y, w, h, color(15, 15, 15, 230));
	render::text(variables::menu::x + 359, variables::menu::y + 3, render::fonts::gui_font, "CLIENT INFO", false, color(255, 255, 255, 255));

	if (variables::aim_enabled)
		render::text(variables::menu::x + 360, variables::menu::y + 20, render::fonts::gui_font, "Aimbot: on", false, color(0, 255, 0, 255));
	else
		render::text(variables::menu::x + 360, variables::menu::y + 20, render::fonts::gui_font, "Aimbot: off", false, color(255, 0, 0, 255));

	if (variables::legit_aa_enable)
		render::text(variables::menu::x + 360, variables::menu::y + 40, render::fonts::gui_font, "Legit AA: on", false, color(0, 255, 0, 255));
	else
		render::text(variables::menu::x + 360, variables::menu::y + 40, render::fonts::gui_font, "Legit AA: off", false, color(255, 0, 0, 255));

	if (variables::rage_aa_enable)
		render::text(variables::menu::x + 360, variables::menu::y + 60, render::fonts::gui_font, "Rage AA: on", false, color(0, 255, 0, 255));
	else
		render::text(variables::menu::x + 360, variables::menu::y + 60, render::fonts::gui_font, "Rage AA: off", false, color(255, 0, 0, 255));

	if (variables::enable_player_visuals)
		render::text(variables::menu::x + 360, variables::menu::y + 80, render::fonts::gui_font, "Visuals: on", false, color(0, 255, 0, 255));
	else
		render::text(variables::menu::x + 360, variables::menu::y + 80, render::fonts::gui_font, "Visuals: off", false, color(255, 0, 0, 255));

	if (variables::chams_enable)
		render::text(variables::menu::x + 360, variables::menu::y + 100, render::fonts::gui_font, "Chams: on", false, color(0, 255, 0, 255));
	else
		render::text(variables::menu::x + 360, variables::menu::y + 100, render::fonts::gui_font, "Chams: off", false, color(255, 0, 0, 255));

	if (variables::misc_enable)
		render::text(variables::menu::x + 360, variables::menu::y + 120, render::fonts::gui_font, "Misc: on", false, color(0, 255, 0, 255));
	else
		render::text(variables::menu::x + 360, variables::menu::y + 120, render::fonts::gui_font, "Misc: off", false, color(255, 0, 0, 255));

	if (variables::movement_enable)
		render::text(variables::menu::x + 360, variables::menu::y + 140, render::fonts::gui_font, "Move: on", false, color(0, 255, 0, 255));
	else
		render::text(variables::menu::x + 360, variables::menu::y + 140, render::fonts::gui_font, "Move: off", false, color(255, 0, 0, 255));

	if (variables::knife_enabled || variables::glove_enabled)
		render::text(variables::menu::x + 360, variables::menu::y + 160, render::fonts::gui_font, "Changer: on", false, color(0, 255, 0, 255));
	else
		render::text(variables::menu::x + 360, variables::menu::y + 160, render::fonts::gui_font, "Changer: off", false, color(255, 0, 0, 255));
}

void visuals::client::indicators(c_usercmd* cmd) {
	if (!variables::indicators)
		return;
	// https://imgur.com/qwdJduD
	// see how much we fakelagging - make it so its dark green going from 5 to 10 ticks - green from 10 to 15 - 0, 0, 0, 230 from 0 to 5 ticks
	if (variables::fake_lag_enable) {
		auto net_channel = interfaces::engine->get_net_channel_info();
		if (!net_channel)
			return;

		int packets = net_channel->choked_packets;

		std::string packet_count = tfm::format("%i", packets);

		if (packets <= 2)
			render::text(10, 650, render::fonts::indi_font, packet_count, false, color::red());
		else 
			render::text(10, 650, render::fonts::indi_font, packet_count, false, color::green());

		//if (packets < 1)
			//render::text(10, 800, render::fonts::indi_font, packet_count, false, color::red());
	}
	else 
		render::text(10, 650, render::fonts::indi_font, "0", false, color::red());

	// see when we use LBY - fix this shit - work on it some time 2023 06 12
	if (variables::legit_aa_enable) {
		render::text(10, 675, render::fonts::indi_font, "LBY", false, color::red());
		if (cmd->viewangles.y > 110.f)
			render::text(10, 675, render::fonts::indi_font, "LBY", false, color::green());
	}
	else
		render::text(10, 675, render::fonts::indi_font, "LBY", false, color::red());

	if (csgo::send_packet) {
		render::text(10, 700, render::fonts::indi_font, "send packet", false, color::green());
	}
	else
		render::text(10, 700, render::fonts::indi_font, "send packet", false, color::red());
}
// note 2023 05 21 https://imgur.com/hBj47c2 -- nvm the fps drops were caused by my shitty potato Lenovo laptop (its shit)

// color(147, 147, 147, 255) // grey
// 
// 
//
#include "menu.hpp"

#ifdef _DEBUG
void menu::render() {
	if (!variables::menu::opened)
		return;

	pendelum::begin(variables::menu::x, variables::menu::y, variables::menu::w, variables::menu::h);

	pendelum::tab("Aimbot", menu::tab_count, 0, variables::menu::x - 19, variables::menu::y + 326);
	pendelum::tab("Anti-A", menu::tab_count, 1, variables::menu::x + 39, variables::menu::y + 326);
	pendelum::tab("Visuals", menu::tab_count, 2, variables::menu::x + 97, variables::menu::y + 326);
	pendelum::tab("Misc", menu::tab_count, 3, variables::menu::x + 155, variables::menu::y + 326);
	pendelum::tab("Changer", menu::tab_count, 4, variables::menu::x + 213, variables::menu::y + 326);
	pendelum::tab("Config", menu::tab_count, 5, variables::menu::x + 271, variables::menu::y + 326);

	switch (tab_count) {
	case 0:
		pendelum::groupbox("Aimbot", variables::menu::x + 110, variables::menu::y + 35, 330, 310); {
			pendelum::child("Legit", variables::menu::x + 10, variables::menu::y + 10, 157, 155); {
				pendelum::checkbox("Aimbot enable", variables::aim_enabled, variables::menu::x + 20, variables::menu::y + 15);
				pendelum::combo("", &variables::aim_mode, variables::menu::x + 20, variables::menu::y + 45, { "Hitbox", "Nearest hitbox" });
				pendelum::checkbox("Dynamic", variables::aim_distance_based_fov, variables::menu::x + 20, variables::menu::y + 60);
				pendelum::checkbox("Silent aim", variables::aim_silent, variables::menu::x + 20, variables::menu::y + 75);
				pendelum::checkbox("Scope aim", variables::scope_aim, variables::menu::x + 20, variables::menu::y + 90);
				pendelum::checkbox("Smoke aim", variables::smoke_check, variables::menu::x + 20, variables::menu::y + 105);
				pendelum::checkbox("Friendly fire", variables::aim_team_check, variables::menu::x + 20, variables::menu::y + 120);
				// pistol rifle sniper smg heavy
				pendelum::tab_second("Y", menu::weapons_tab, 0, variables::menu::x - 85, variables::menu::y + 10);
				pendelum::tab_second("B", menu::weapons_tab, 1, variables::menu::x - 85, variables::menu::y + 50);
				pendelum::tab_second("N", menu::weapons_tab, 2, variables::menu::x - 85, variables::menu::y + 90);
				pendelum::tab_second("L", menu::weapons_tab, 3, variables::menu::x - 85, variables::menu::y + 130);
				pendelum::tab_second("Z", menu::weapons_tab, 4, variables::menu::x - 85, variables::menu::y + 170);
				// 14 // 7
				switch (weapons_tab)
				{
				case 0:
					pendelum::child("Pistol", variables::menu::x + 10, variables::menu::y + 170, 157, 138); {
						if (variables::aim_mode == 0) {
							pendelum::combo("", &variables::aim_bone_pistol, variables::menu::x + 20, variables::menu::y + 185, { "Head", "Neck", "Chest", "Stomach", "Pelvis" });
						}
						pendelum::slider("Fov", 125, variables::menu::x + 20, variables::menu::y + 215, variables::aim_fov_pistol, 0.f, 180.f);
						pendelum::slider("Smooth", 125, variables::menu::x + 20, variables::menu::y + 240, variables::aim_smooth_pistol, 1.f, 10.f);
						pendelum::slider("Rcs x", 125, variables::menu::x + 20, variables::menu::y + 265, variables::rcs_x_pistol, 0.f, 1.f);
						pendelum::slider("Rcs y", 125, variables::menu::x + 20, variables::menu::y + 290, variables::rcs_y_pistol, 0.f, 1.f);
					}
					break;
				case 1:
					pendelum::child("Rifle", variables::menu::x + 10, variables::menu::y + 170, 157, 138); {
						if (variables::aim_mode == 0) {
							pendelum::combo("", &variables::aim_bone_rifle, variables::menu::x + 20, variables::menu::y + 185, { "Head", "Neck", "Chest", "Stomach", "Pelvis" });
						}
						pendelum::slider("Fov", 125, variables::menu::x + 20, variables::menu::y + 215, variables::aim_fov_rifle, 0.f, 180.f);
						pendelum::slider("Smooth", 125, variables::menu::x + 20, variables::menu::y + 240, variables::aim_smooth_rifle, 1.f, 10.f);
						pendelum::slider("Rcs x", 125, variables::menu::x + 20, variables::menu::y + 265, variables::rcs_x_rifle, 0.f, 1.f);
						pendelum::slider("Rcs y", 125, variables::menu::x + 20, variables::menu::y + 290, variables::rcs_y_rifle, 0.f, 1.f);
					}
					break;
				case 2:
					pendelum::child("Sniper", variables::menu::x + 10, variables::menu::y + 170, 157, 138); {
						if (variables::aim_mode == 0) {
							pendelum::combo("", &variables::aim_bone_sniper, variables::menu::x + 20, variables::menu::y + 185, { "Head", "Neck", "Chest", "Stomach", "Pelvis" });
						}
						pendelum::slider("Fov", 125, variables::menu::x + 20, variables::menu::y + 215, variables::aim_fov_sniper, 0.f, 180.f);
						pendelum::slider("Smooth", 125, variables::menu::x + 20, variables::menu::y + 240, variables::aim_smooth_sniper, 1.f, 10.f);
						pendelum::slider("Rcs x", 125, variables::menu::x + 20, variables::menu::y + 265, variables::rcs_x_sniper, 0.f, 1.f);
						pendelum::slider("Rcs y", 125, variables::menu::x + 20, variables::menu::y + 290, variables::rcs_y_sniper, 0.f, 1.f);
					}
					break;
				case 3:
					pendelum::child("Smg", variables::menu::x + 10, variables::menu::y + 170, 157, 138); {
						if (variables::aim_mode == 0) {
							pendelum::combo("", &variables::aim_bone_smg, variables::menu::x + 20, variables::menu::y + 185, { "Head", "Neck", "Chest", "Stomach", "Pelvis" });
						}
						pendelum::slider("Fov", 125, variables::menu::x + 20, variables::menu::y + 215, variables::aim_fov_smg, 0.f, 180.f);
						pendelum::slider("Smooth", 125, variables::menu::x + 20, variables::menu::y + 240, variables::aim_smooth_smg, 1.f, 10.f);
						pendelum::slider("Rcs x", 125, variables::menu::x + 20, variables::menu::y + 265, variables::rcs_x_smg, 0.f, 1.f);
						pendelum::slider("Rcs y", 125, variables::menu::x + 20, variables::menu::y + 290, variables::rcs_y_smg, 0.f, 1.f);
					}
					break;
				case 4:
					pendelum::child("Heavy", variables::menu::x + 10, variables::menu::y + 170, 157, 138); {
						if (variables::aim_mode == 0) {
							pendelum::combo("", &variables::aim_bone_heavy, variables::menu::x + 20, variables::menu::y + 185, { "Head", "Neck", "Chest", "Stomach", "Pelvis" });
						}
						pendelum::slider("Fov", 125, variables::menu::x + 20, variables::menu::y + 215, variables::aim_fov_heavy, 0.f, 180.f);
						pendelum::slider("Smooth", 125, variables::menu::x + 20, variables::menu::y + 240, variables::aim_smooth_heavy, 1.f, 10.f);
						pendelum::slider("Rcs x", 125, variables::menu::x + 20, variables::menu::y + 265, variables::rcs_x_heavy, 0.f, 1.f);
						pendelum::slider("Rcs y", 125, variables::menu::x + 20, variables::menu::y + 290, variables::rcs_y_heavy, 0.f, 1.f);
					}
					break;
				}
			}
			pendelum::child("Rage", variables::menu::x + 170, variables::menu::y + 10, 157, 298); {
				pendelum::checkbox("Backtrack enable", variables::backtrack_enable, variables::menu::x + 180, variables::menu::y + 15); // fix pos
				pendelum::slider("Range (ms)", 125, variables::menu::x + 180, variables::menu::y + 45, variables::backtrack_range, 0.f, 200.f); // fix pos
			}
		}
		break;
	case 1:
		pendelum::groupbox("Legit", variables::menu::x + 110, variables::menu::y + 35, 330, 310); {
			pendelum::child("Legit", variables::menu::x + 10, variables::menu::y + 10, 157, 298); {
				pendelum::checkbox("Legit anti-aim enable", variables::legit_aa_enable, variables::menu::x + 20, variables::menu::y + 15);
				pendelum::checkbox("Legit anti-aim", variables::legit_aa, variables::menu::x + 20, variables::menu::y + 45);
				pendelum::slider("Lby", 125, variables::menu::x + 20, variables::menu::y + 75, variables::next_update, 0.f, 200.f); // NOTE: do we really need this?
			}
			pendelum::child("Rage", variables::menu::x + 170, variables::menu::y + 10, 157, 298); {
				pendelum::checkbox("Rage anti-aim enable", variables::rage_aa_enable, variables::menu::x + 180, variables::menu::y + 15);//ideal up down random
				pendelum::combo("Pitch", &variables::rage_aa_opt1, variables::menu::x + 180, variables::menu::y + 55, { "Deafult", "Ideal", "Up", "Down", "Random" });
				pendelum::combo("Yaw", &variables::rage_aa_opt2, variables::menu::x + 180, variables::menu::y + 85, { "Default", "Backwards", "Spin", "Static", "180z" });
				if (variables::rage_aa_opt2 == 1)
					pendelum::slider("Angle", 125, variables::menu::x + 180, variables::menu::y + 110, variables::backwards_deg, -180.f, 180.f);
				if (variables::rage_aa_opt2 == 3)
					pendelum::slider("Angle", 125, variables::menu::x + 180, variables::menu::y + 110, variables::static_deg, -180.f, 180.f);

				if (variables::rage_aa_opt2 == 1 || variables::rage_aa_opt2 == 3) {
					pendelum::combo("Yaw jitter", &variables::rage_aa_opt3, variables::menu::x + 180, variables::menu::y + 140, { "Mode", "Jitter", "Random" });
					pendelum::checkbox("Fakelag enable", variables::fake_lag_enable, variables::menu::x + 180, variables::menu::y + 155);
					pendelum::checkbox("Disable on shot/holding c4", variables::disable_fl_onshot_c4, variables::menu::x + 180, variables::menu::y + 170);
					pendelum::sliderint("Amount", 125, variables::menu::x + 180, variables::menu::y + 200, variables::fake_lag_amount, 0, 15);
					pendelum::combo("Lag type", &variables::fake_lag_type, variables::menu::x + 180, variables::menu::y + 230, { "Deafult", "Random" });
					pendelum::checkbox("Desync enable", variables::desync_antiaim, variables::menu::x + 180, variables::menu::y + 245);
					pendelum::slider("Angle", 125, variables::menu::x + 180, variables::menu::y + 275, variables::desync_range, 0.f, 59.f);
					pendelum::combo("Desync type", &variables::desync_option, variables::menu::x + 180, variables::menu::y + 305, { "Option 1", "Option 2" });
				}
				else {
					pendelum::combo("Yaw jitter", &variables::rage_aa_opt3, variables::menu::x + 180, variables::menu::y + 115, { "Mode", "Jitter", "Random" });

					pendelum::checkbox("Fakelag enable", variables::fake_lag_enable, variables::menu::x + 180, variables::menu::y + 130);
					pendelum::checkbox("Disable on shot/holding c4", variables::disable_fl_onshot_c4, variables::menu::x + 180, variables::menu::y + 145);
					pendelum::sliderint("Amount", 125, variables::menu::x + 180, variables::menu::y + 175, variables::fake_lag_amount, 0, 15);
					pendelum::combo("Lag type", &variables::fake_lag_type, variables::menu::x + 180, variables::menu::y + 205, { "Deafult", "Random" });

					pendelum::checkbox("Desync enable", variables::desync_antiaim, variables::menu::x + 180, variables::menu::y + 220);
					pendelum::slider("Angle", 125, variables::menu::x + 180, variables::menu::y + 250, variables::desync_range, 0.f, 59.f);
					pendelum::combo("Desync type", &variables::desync_option, variables::menu::x + 180, variables::menu::y + 280, { "Option 1", "Option 2" });
				}
			}
		}
		break;
	case 2:
		pendelum::groupbox("Visuals", variables::menu::x + 110, variables::menu::y + 35, 330, 310); {
			pendelum::child("Players", variables::menu::x + 10, variables::menu::y + 10, 157, 298); {
				pendelum::checkbox("Visuals enable", variables::enable_player_visuals, variables::menu::x + 20, variables::menu::y + 15);
				pendelum::checkbox("Visible only", variables::visible_check, variables::menu::x + 20, variables::menu::y + 45);
				pendelum::checkbox("Bounding box", variables::draw_box, variables::menu::x + 20, variables::menu::y + 60);
				pendelum::checkbox("Health", variables::draw_hp, variables::menu::x + 20, variables::menu::y + 75);
				pendelum::checkbox("Flags", variables::flags_esp, variables::menu::x + 20, variables::menu::y + 90);
				pendelum::checkbox("Fov enable", variables::fov_changer, variables::menu::x + 20, variables::menu::y + 105);
				pendelum::slider("X", 125, variables::menu::x + 20, variables::menu::y + 135, variables::x_fov, -50.f, 15.f);
				pendelum::slider("Y", 125, variables::menu::x + 20, variables::menu::y + 160, variables::y_fov, -50.f, 15.f);
				pendelum::slider("Z", 125, variables::menu::x + 20, variables::menu::y + 185, variables::z_fov, -50.f, 15.f);
			}
			pendelum::child("Chams", variables::menu::x + 170, variables::menu::y + 10, 157, 148); { 
				pendelum::tab("Enemy", menu::visuals_tab, 0, variables::menu::x + 160, variables::menu::y + 23);
				pendelum::tab("Team", menu::visuals_tab, 1, variables::menu::x + 207, variables::menu::y + 23);
				pendelum::tab("Local", menu::visuals_tab, 2, variables::menu::x + 255, variables::menu::y + 23);

				switch (visuals_tab)
				{
				case 0:
					pendelum::checkbox("Chams enable", variables::chams_enable, variables::menu::x + 180, variables::menu::y + 35);
					pendelum::checkbox("Visible", variables::ememy_chams, variables::menu::x + 180, variables::menu::y + 65);
					pendelum::checkbox("Hidden", variables::chams_xqz, variables::menu::x + 180, variables::menu::y + 80);
					pendelum::checkbox("Wireframe", variables::wireframe_chams, variables::menu::x + 180, variables::menu::y + 95);
					pendelum::combo("", &variables::chams_type, variables::menu::x + 180, variables::menu::y + 120, { "Regular", "Flat", "Ghost", "OT overlay", "Pearlescent", "Animated", "Water test", "Test" });
					break;
				case 1:
					pendelum::checkbox("Team enable", variables::team_check_chams, variables::menu::x + 180, variables::menu::y + 35);
					break;
				case 2:
					pendelum::checkbox("Local enable", variables::local_chams, variables::menu::x + 180, variables::menu::y + 35);
					pendelum::checkbox("Local fake angles", variables::local_fake_chams, variables::menu::x + 180, variables::menu::y + 65);
					pendelum::checkbox("Sleeves", variables::sleeve_chams, variables::menu::x + 180, variables::menu::y + 80);
					pendelum::checkbox("Arms", variables::arms_chams, variables::menu::x + 180, variables::menu::y + 95);
					pendelum::checkbox("Weapons", variables::weapon_chams, variables::menu::x + 180, variables::menu::y + 110);
					break;
				}
			}
			pendelum::child("World", variables::menu::x + 170, variables::menu::y + 163, 157, 145); {  
				pendelum::checkbox("Fog enable", variables::fogenable, variables::menu::x + 180, variables::menu::y + 168);
				pendelum::slider("Start", 125, variables::menu::x + 180, variables::menu::y + 198, variables::fogstart, 0.f, 1000.f);
				pendelum::slider("End", 125, variables::menu::x + 180, variables::menu::y + 223, variables::fogend, 0.f, 1000.f);
				pendelum::slider("Density", 125, variables::menu::x + 180, variables::menu::y + 248, variables::fogmaxdensity, 0.f, 1.f);
				pendelum::checkbox("Remove 3d sky", variables::remove_3dsky, variables::menu::x + 180, variables::menu::y + 263); 
			}
		}
		break;
	case 3:
		pendelum::groupbox("Misc", variables::menu::x + 110, variables::menu::y + 35, 330, 310); {
			pendelum::child("Client", variables::menu::x + 10, variables::menu::y + 10, 157, 298); {
				pendelum::checkbox("Misc enable", variables::misc_enable, variables::menu::x + 20, variables::menu::y + 15);
				pendelum::checkbox("Disable post-processing", variables::disable_post_processing, variables::menu::x + 20, variables::menu::y + 45);
				pendelum::checkbox("Force corsshair", variables::force_crosshair, variables::menu::x + 20, variables::menu::y + 60);
				pendelum::checkbox("Recoil crosshair", variables::recoil_crosshair, variables::menu::x + 20, variables::menu::y + 75);
				pendelum::checkbox("Watermark", variables::watermark, variables::menu::x + 20, variables::menu::y + 90);
				pendelum::checkbox("Health player logs", variables::log_health, variables::menu::x + 20, variables::menu::y + 105);
				pendelum::checkbox("Buy player logs", variables::log_buys, variables::menu::x + 20, variables::menu::y + 120);
				pendelum::checkbox("Indicators", variables::indicators, variables::menu::x + 20, variables::menu::y + 260);
				pendelum::checkbox("Player list", variables::player_list, variables::menu::x + 20, variables::menu::y + 275);
				pendelum::checkbox("Client information", variables::information_client, variables::menu::x + 20, variables::menu::y + 290);
			}
			pendelum::child("Movement", variables::menu::x + 170, variables::menu::y + 10, 157, 298); {
				pendelum::checkbox("Movement enable", variables::movement_enable, variables::menu::x + 180, variables::menu::y + 15);
				pendelum::checkbox("Bhop", variables::bhop, variables::menu::x + 180, variables::menu::y + 45);
				pendelum::checkbox("Strafe", variables::strafe, variables::menu::x + 180, variables::menu::y + 60);
				pendelum::checkbox("Advanced bhop", variables::adv_bhop, variables::menu::x + 180, variables::menu::y + 75);
				pendelum::slider("Chance", 125, variables::menu::x + 180, variables::menu::y + 105, variables::bhop_hits, 0.f, 100.f);
				pendelum::slider("Max", 125, variables::menu::x + 180, variables::menu::y + 130, variables::bhop_maxv, 0.f, 20.f);
				pendelum::slider("Min", 125, variables::menu::x + 180, variables::menu::y + 155, variables::bhop_minv, 0.f, 20.f);
			}
		}
		break;
	case 4: 
		pendelum::groupbox("Changer", variables::menu::x + 110, variables::menu::y + 35, 330, 310); {
			pendelum::child("Knifes", variables::menu::x + 10, variables::menu::y + 10, 157, 148); {
				pendelum::checkbox("Knife enable", variables::knife_enabled, variables::menu::x + 20, variables::menu::y + 15);
				if (!variables::knife_enabled)
					interfaces::clientstate->full_update();

				pendelum::combo("", &variables::knife_model, variables::menu::x + 20, variables::menu::y + 55, { "Default knife", "Bayonet knife", "Flip knife", "Gut knife", "Karambit knife", "M9 Bayonet knife", "Huntsman knife", "Falchion knife", "Bowie knife", "Butterfly knife", "Shadow Daggers", "Ursus knife", "Navaja knife", "Stiletto knife", "Talon knife", "Nomad knife", "Skeleton knife", "Survival knife", "Paracord knife", "Classic knife" });
				if (variables::knife_model == 1 || variables::knife_model == 2 || variables::knife_model == 3 || variables::knife_model == 4 || variables::knife_model == 5)
					pendelum::combo("", &variables::knife_skin, variables::menu::x + 20, variables::menu::y + 75, { "Vanilla", "Lore", "Gamma Doppler", "Autotronic", "Black Laminate", "Freehand", "Bright Water", "Marble Fade", "Tiger Tooth", "Doppler", "Ultraviolet", "Damascus Steel", "Rust Coat", "Fade", "Slaughter", "Case Hardened", "Crimson Web", "Blue Steel", "Night", "Safari Mesh", "Forest DDPAT", "Stained", "Scorched", "Boreal Forest", "Urban Masked" });
				if (variables::knife_model == 6 || variables::knife_model == 7 || variables::knife_model == 8 || variables::knife_model == 9 || variables::knife_model == 10 || variables::knife_model == 11 || variables::knife_model == 12 || variables::knife_model == 13 || variables::knife_model == 14 || variables::knife_model == 15 || variables::knife_model == 16 || variables::knife_model == 17 || variables::knife_model == 18 || variables::knife_model == 19)
					pendelum::combo("", &variables::knife_skin, variables::menu::x + 20, variables::menu::y + 75, { "Vanilla", "Marble Fade", "Tiger Tooth", "Doppler", "Ultraviolet", "Damascus Steel", "Rust Coat", "Fade", "Slaughter", "Case Hardened", "Crimson Web", "Blue Steel", "Night", "Safari Mesh", "Forest DDPAT", "Stained", "Scorched", "Boreal Forest", "Urban Masked" });
				skins::skinchanger::list(); // wear + stattrak
			}
			// TODO: auto element x y, make this shit simetrical
			pendelum::child("Gloves", variables::menu::x + 10, variables::menu::y + 163, 157, 145); {
				pendelum::checkbox("Glove enable", variables::glove_enabled, variables::menu::x + 20, variables::menu::y + 168);
				if (!variables::glove_enabled)
					interfaces::clientstate->full_update();

				pendelum::combo("", &variables::glove_model, variables::menu::x + 20, variables::menu::y + 208, { "Default gloves", "Bloodhound gloves", "Sport gloves", "Driver gloves", "Hand Wraps", "Moto gloves", "Specialist gloves", "Hydra gloves" });

				switch (variables::glove_model) {
				case 1:
					pendelum::combo("", &variables::bloodhound_skin, variables::menu::x + 20, variables::menu::y + 228, { "Snakebite", "Guerrilla", "Charred", "Bronzed" });
					break;
				case 2:
					pendelum::combo("", &variables::sport_skin, variables::menu::x + 20, variables::menu::y + 228, { "Vice", "Amphibious", "Omega", "Bronze Morph", "Pandora's Box", "Superconductor", "Hedge Maze", "Arid" });
					break;
				case 3:
					pendelum::combo("", &variables::driver_skin, variables::menu::x + 20, variables::menu::y + 228, { "King Snake", "Imperial Plaid", "Overtake", "Racing Green", "Crimson Weave", "Diamondback", "Lunar Weave", "Convoy", "Black Tie" });
					break;
				case 4:
					pendelum::combo("", &variables::handwrap_skin, variables::menu::x + 20, variables::menu::y + 228, { "Cobalt Skulls", "Overprint", "Arboreal", "Duct Tape", "Slaughter", "Badlands", "Leather", "Spruce DDPAT" });
					break;
				case 5:
					pendelum::combo("", &variables::moto_skin, variables::menu::x + 20, variables::menu::y + 228, { "POW!", "Turtle", "Polygon", "Transport", "Spearmint", "Boom!", "Cool Mint", "Eclipse" });
					break;
				case 6:
					pendelum::combo("", &variables::specialist_skin, variables::menu::x + 20, variables::menu::y + 228, { "Fade", "Crimson Web", "Mogul", "Buckshot", "Crimson Kimono", "Emerald Web", "Foundation", "Forest DDPAT" });
					break;
				case 7:
					pendelum::combo("", &variables::hydra_skin, variables::menu::x + 20, variables::menu::y + 228, { "Emerald", "Mangrove", "Case Hardened", "Rattler" });
					break;
				}
				pendelum::slider("Glove wear", 125, variables::menu::x + 20, variables::menu::y + 253, variables::glove_wear, 0.f, 1.f);
			}
			pendelum::child("Changer", variables::menu::x + 170, variables::menu::y + 10, 157, 148); {
				pendelum::checkbox("Weapon skins enable", variables::weapon_enabled, variables::menu::x + 180, variables::menu::y + 15);
				if (!variables::weapon_enabled)
					interfaces::clientstate->full_update();

				pendelum::combo("", &variables::weapon_skin, variables::menu::x + 180, variables::menu::y + 55, { "Usp", "P2000", "Glock-18", "P250", "Five-seven", "Tec-9", "Cz-75 auto", "Dual berettas", "Desert eagle", "Revolver", "Famas", "Galil-AR", "M4A4", "M4A1-s", "Ak-47", "Sg 553", "Aug", "Ssg 08", "AWP", "Scar-20", "G3SG1", "Sawed-off", "M249", "Negev", "Mag7", "XM1014", "Nova", "Bizon", "MP5SD", "Mp7", "Mp9", "Mac10", "P90", "Ump45" });
				skins::weaponchanger::list();// wear + stattrak
			}
			// just examples for upcoming skin changer list, will display skin in [these brackets] for example Karambit knife - [Fade] for gloves, its the same thing, Driver gloves - [Black tie]
			pendelum::child("Skin list", variables::menu::x + 170, variables::menu::y + 163, 157, 145); {
				skins::skinchanger::skin_list();
			}
		}
		break;
	case 5: 
		pendelum::groupbox("Config&Lua", variables::menu::x + 110, variables::menu::y + 35, 330, 310); {
			pendelum::child("Configuration", variables::menu::x + 10, variables::menu::y + 10, 157, 298); {
				pendelum::button("Button", variables::test, variables::menu::x + 20, variables::menu::y + 20);
				pendelum::checbox2(variables::menu::x + 20, variables::menu::y + 50, &variables::information_client, "Bruhhh");
			}
			pendelum::child("Lua scipts", variables::menu::x + 170, variables::menu::y + 10, 157, 298); {
			}
		}
		break;
	}
}

void menu::render_playerlist() {
	if (!variables::player_list)
		return;

	if (variables::menu::opened == !variables::player_list)
		return;

	pendelum::begin_pl(variables::menu::x_pl, variables::menu::y_pl, variables::menu::w_pl, 400);
	// fix width/height bullshit :)
	pendelum::groupbox("Playerlist", variables::menu::x_pl + 110, variables::menu::y_pl + 35, 330, 379); {
		pendelum::child("Player list", variables::menu::x_pl + 10, variables::menu::y_pl + 10, 318, 367); { // -12
			render::text(variables::menu::x_pl + 50, variables::menu::y_pl + 22, render::fonts::gui_font, "Name", false, color(225, 225, 225, 255));
			render::text(variables::menu::x_pl + 155, variables::menu::y_pl + 22, render::fonts::gui_font, "Health", false, color(225, 225, 225, 255));
			render::text(variables::menu::x_pl + 268, variables::menu::y_pl + 22, render::fonts::gui_font, "CH User", false, color(225, 225, 225, 255));
			if (interfaces::engine->is_in_game() && csgo::local_player) {
				for (int i = 1; i < interfaces::globals->max_clients; i++) {
					player_t* p = (player_t*)interfaces::entity_list->get_client_entity(i);
					if (p) {
						player_info_t info;
						interfaces::engine->get_player_info(i, &info);
						std::string name = ("%s", info.name);
						if (name.length() > 15)
							name = name.substr(0, 15) + "...";
						std::string health = ("%i", std::to_string(p->health()));
						std::string armor = ("%t", std::to_string(p->armor()));
						//std::string ch_user = ("%s", info.ch_user);
						pendelum::pl_text(name.c_str(), variables::menu::x_pl + 20, variables::menu::y_pl + 35 + (i - 1) * 14, p->team() == 2 ? color(230, 230, 0, 255) : color(229, 137, 226, 255));
						pendelum::pl_text(health, variables::menu::x_pl + 148, variables::menu::y_pl + 35 + (i - 1) * 14, color(0, 255, 0, 255));
						pendelum::pl_text(armor, variables::menu::x_pl + 172, variables::menu::y_pl + 35 + (i - 1) * 14, color(137, 170, 245, 255));
						//pendelum::pl_text(ch_user, variables::menu::x_pl + 295, variables::menu::y_pl + 35, color(255, 255, 255, 255));
					}
				}
			}
		}
	}
}
#endif // DEBUG

// combo - 25
// enable - normal 20 // checkboxes
// between normal checkboxes 15
// items and sliders 25

// pendelum::multicombo("Shoot at", variables::menu::x + 20, variables::menu::y + 85, { "Head", "Neck", "Chest", "Arms", "Legs" }, &variables::test);
// pendelum::combo("", variables::menu::x + 480, variables::menu::y + 140, { "Fake", "Default", "Relative jitter", "Random", "Local" }, &variables::rage_aa_fake_enable);
// pendelum::slider("relative jitter angle", 125, variables::menu::x + 180, variables::menu::y + 200, variables::aa_range_relative_jitter, 0.f, 180.f);
// pendelum::checkbox("test aa", variables::test_aaa, variables::menu::x + 260, variables::menu::y + 120);
// pendelum::slider("angle", 125, variables::menu::x + 260, variables::menu::y + 140, variables::test_aa, 0.f, 120.f);
//
// sky changer done
// 
// new item? Enable + 20y + supposed items default y.

// TODO:
// hud update (skin changer)
// vector pushback for menu elements
// show knife model on the kill feed
// slider that goes to - and + 
// pendelum::button
// pendelum::colorpicker
// fix math for aimbot
// disable arms or sleeves
// DISPLAY SKIN IDS ON SKIN LIST <- tmrw 2023 07 04
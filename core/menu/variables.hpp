#pragma once

namespace variables {
	inline bool test = false;
	inline bool blink_switch = false;
	namespace menu {
		inline bool opened = false;
		inline int x = 250;
		inline int y = 250;
		inline int w = 350;
		inline int h = 350;

		inline int x_pl = 250;
		inline int y_pl = 150;
		inline int w_pl = 350;
		inline int h_pl = 150;
	}
	inline bool player_list = false;

	inline bool information_game = false;
	inline bool information_client = false;

	inline bool aim_enabled{ false };
	inline bool scope_aim{ false };
	inline bool smoke_check{ false };
	inline bool aim_silent{ false };
	inline bool aim_distance_based_fov{ false };
	inline float aim_fov_pistol{ 0.0f };
	inline float rcs_x_pistol{ 0.0f };
	inline float rcs_y_pistol{ 0.0f };
	inline float rcs_x_rifle{ 0.0f };
	inline float rcs_y_rifle{ 0.0f };
	inline float rcs_x_sniper{ 0.0f };
	inline float rcs_y_sniper{ 0.0f };
	inline float rcs_x_heavy{ 0.0f };
	inline float rcs_y_heavy{ 0.0f };
	inline float rcs_x_smg{ 0.0f };
	inline float rcs_y_smg{ 0.0f };
	inline float aim_smooth_pistol{ 5.f };
	inline float aim_fov_rifle{ 0.0f };
	inline float aim_smooth_rifle{ 5.f };
	inline float aim_fov_sniper{ 0.0f };
	inline float aim_smooth_sniper{ 5.f };
	inline float aim_fov_heavy{ 0.0f };
	inline float aim_smooth_heavy{ 5.f };
	inline float aim_fov_smg{ 0.0f };
	inline float aim_smooth_smg{ 5.f };
	inline int aim_bone_smg{ 0 };
	inline int aim_bone_sniper{ 0 };
	inline int aim_bone_pistol{ 0 };
	inline int aim_mode{ 0 };
	inline int aim_bone_rifle{ 0 };
	inline int aim_bone_heavy{ 0 };
	inline int aim_weapon{ 0 };
	inline bool aim_team_check = false;
	inline int aimbot_delay_after_kill{ 0 };

	inline bool rage_aa_enable = false;
	inline bool legit_aa_enable = false;

	inline int rage_aa_opt1 = 0; // pitch

	inline int rage_aa_opt2 = 0; // yaw
	inline float backwards_deg = 180.f; 
	inline float static_deg = 0.f;

	inline int rage_aa_opt3 = 0;
	inline bool desync_antiaim = false;
	inline float desync_range = 0.f;
	inline int desync_option = 0;

	inline bool legit_aa = false;
	inline bool break_lby = false;
	inline float next_update = 0.f;
	inline bool server_hitbox = true;

	inline bool fake_lag_enable = false;
	inline bool disable_fl_onshot_c4 = false;
	inline int fake_lag_amount = 0;
	inline int fake_lag_type = 0;

	inline bool backtrack_enable = false;
	inline float backtrack_range = 0.f;

	inline bool enable_player_visuals = false;
	inline bool visible_check = false;
	inline bool draw_box = false;
	inline bool draw_hp = false;
	inline bool draw_hk = false;
	inline bool flags_esp = false;

	inline bool chams_enable = false;
	inline bool chams_xqz = false;
	inline bool ememy_chams = false;
	inline bool team_check_chams = false;
	inline bool local_chams = false;
	inline bool local_fake_chams = false;
	inline bool wireframe_chams = false;

	inline int chams_type = 0;

	inline bool sleeve_chams = false;
	inline bool arms_chams = false;
	inline bool weapon_chams = false;
	inline bool glove_chams = false;

	inline float f_chams_clr[4] = { 0.5f, 1.f, 0.5f, 1.0f }; // done
	inline color chams_clr = color(255, 105, 180);
	inline float f_chams_local_clr[4] = { 1.f, 0.f, 0.f, 0.6f }; // done
	inline color chams_local_clr = color(255, 105, 180);
	inline float f_chams_local_fake_clr[4] = { 1.f, 0.f, 0.f, 0.6f }; // done
	inline color chams_local_fake_clr = color(255, 105, 180);
	inline float f_chams_team_clr[4] = { 0.37f, 0.41f, 0.75f, 1.0f }; // done
	inline color chams_team_clr = color(255, 105, 180);
	inline float f_sleeve_chams[4] = { 0.78f, 0.25f, 0.78f, 0.6f }; // done
	inline color sleeve_chams_clr = color(255, 105, 255);
	inline float f_arms_chams[4] = { 1.f, 1.f, 1.f, 1.f };
	inline color arms_chams_clr = color(255, 105, 255);
	inline float f_weapon_chams[4] = { 1.f, 1.f, 1.f, 1.f };
	inline color weapon_chams_clr = color(255, 105, 255);
	inline float f_glove_chams[4] = { 1.f, 1.f, 1.f, 1.f };
	inline color glove_chams_clr = color(255, 105, 255);
	inline float f_xqz_clr[4] = { 1.f, 1.f, 0.f, 1.0f }; // done
	inline color xqz_clr = color(255, 105, 255);

	inline bool fov_changer = false;
	inline float x_fov = 5.f;
	inline float y_fov = 5.f;
	inline float z_fov = 5.f;

	inline bool fogenable = false;
	inline color fogcolor = color(0, 0, 0, 160);
	inline float fogend = 0.f;
	inline float fogstart = 0.f;
	inline float fogmaxdensity = 0.9f;

	inline bool misc_enable = false;

	inline bool remove_3dsky = false;
	inline bool disable_post_processing = false;
	inline bool recoil_crosshair = false;
	inline bool force_crosshair = false;

	inline bool sky_changer = false;
	inline int sky = 0;

	inline bool movement_enable = false;

	inline bool bhop = false;
	inline bool strafe = false;

	inline bool adv_bhop = false;
	inline float bhop_hits = 0.f;
	inline float bhop_maxv = 0.f;
	inline float bhop_minv = 0.f;

	inline bool watermark = true;
	inline bool indicators = false;

	inline float logger_clr[4]{ 0.37f, 0.41f, 0.75f, 1.0f };
	inline bool log_health = false;
	inline bool log_buys = false;


	inline bool knife_enabled = false;
	inline bool glove_enabled = false;
	inline bool weapon_enabled = false;

	inline float glove_wear = 0.f;

	inline int knife_model = 0;
	inline int knife_skin = 0;

	inline bool default_stattrak = 0;
	inline int index_default_stattrak = 0;
	inline float default_wear = 0.f;

	inline bool bayonet_stattrak = 0;
	inline int index_bayonet_stattrak = 0;
	inline float bayonet_wear = 0.f;

	inline bool flip_stattrak = 0;
	inline int index_flip_stattrak = 0;
	inline float flip_wear = 0.f;

	inline bool gut_stattrak = 0;
	inline int index_gut_stattrak = 0;
	inline float gut_wear = 0.f;

	inline bool karambit_stattrak = 0;
	inline int index_karambit_stattrak = 0;
	inline float karambit_wear = 0.f;

	inline bool m9bayo_stattrak = 0;
	inline int index_m9bayo_stattrak = 0;
	inline float m9bayo_wear = 0.f;

	inline bool tactical_stattrak = 0;
	inline int index_tactical_stattrak = 0;
	inline float tactical_wear = 0.f;

	inline bool falchion_stattrak = 0;
	inline int index_falchion_stattrak = 0;
	inline float falchion_wear = 0.f;

	inline bool bowie_stattrak = 0;
	inline int index_bowie_stattrak = 0;
	inline float bowie_wear = 0.f;

	inline bool butterfly_stattrak = 0;
	inline int index_butterfly_stattrak = 0;
	inline float butterfly_wear = 0.f;

	inline bool push_stattrak = 0;
	inline int index_push_stattrak = 0;
	inline float push_wear = 0.f;

	inline bool ursus_stattrak = 0;
	inline int index_ursus_stattrak = 0;
	inline float ursus_wear = 0.f;

	inline bool jackknife_stattrak = 0;
	inline int index_jackknife_stattrak = 0;
	inline float jackknife_wear = 0.f;

	inline bool stiletto_stattrak = 0;
	inline int index_stiletto_stattrak = 0;
	inline float stiletto_wear = 0.f;

	inline bool widowmaker_stattrak = 0;
	inline int index_widowmaker_stattrak = 0;
	inline float widowmaker_wear = 0.f;

	inline bool outdoor_stattrak = 0;
	inline int index_outdoor_stattrak = 0;
	inline float outdoor_wear = 0.f;

	inline bool skeleton_stattrak = 0;
	inline int index_skeleton_stattrak = 0;
	inline float skeleton_wear = 0.f;

	inline bool canis_stattrak = 0;
	inline int index_canis_stattrak = 0;
	inline float canis_wear = 0.f;

	inline bool cord_stattrak = 0;
	inline int index_cord_stattrak = 0;
	inline float cord_wear = 0.f;

	inline bool css_stattrak = 0;
	inline int index_css_stattrak = 0;
	inline float css_wear = 0.f;

	inline int glove_model = 0;
	inline int hydra_skin = 0;
	inline int bloodhound_skin = 0;
	inline int driver_skin = 0;
	inline int handwrap_skin = 0;
	inline int moto_skin = 0;
	inline int specialist_skin = 0;
	inline int sport_skin = 0;

	inline int weapon_skin = 0;

	inline bool usp_stattrak = false;
	inline int index_usp_stattrak = 0;
	inline int paint_kit_index_usp = 0;
	inline float usp_wear = 0.f;

	inline bool p2000_stattrak = false;
	inline int index_p2000_stattrak = 0;
	inline int paint_kit_index_p2000 = 0;
	inline float p2000_wear = 0.f;

	inline bool glock_stattrak = false;
	inline int index_glock_stattrak = 0;
	inline int paint_kit_index_glock = 0;
	inline float glock_wear = 0.f;

	inline bool p250_stattrak = false;
	inline int index_p250_stattrak = 0;
	inline int paint_kit_index_p250 = 0;
	inline float p250_wear = 0.f;

	inline bool fiveseven_stattrak = false;
	inline int index_fiveseven_stattrak = 0;
	inline int paint_kit_index_fiveseven = 0;
	inline float fiveseven_wear = 0.f;

	inline bool tec_stattrak = false;
	inline int index_tec_stattrak = 0;
	inline int paint_kit_index_tec = 0;
	inline float tec_wear = 0.f;

	inline bool cz_stattrak = false;
	inline int index_cz_stattrak = 0;
	inline int paint_kit_index_cz = 0;
	inline float cz_wear = 0.f;

	inline bool duals_stattrak = false;
	inline int index_duals_stattrak = 0;
	inline int paint_kit_index_duals = 0;
	inline float duals_wear = 0.f;

	inline bool deagle_stattrak = false;
	inline int index_deagle_stattrak = 0;
	inline int paint_kit_index_deagle = 0;
	inline float deagle_wear = 0.f;

	inline bool revolver_stattrak = false;
	inline int index_revolver_stattrak = 0;
	inline int paint_kit_index_revolver = 0;
	inline float revolver_wear = 0.f;

	inline bool famas_stattrak = false;
	inline int index_famas_stattrak = 0;
	inline int paint_kit_index_famas = 0;
	inline float famas_wear = 0.f;

	inline bool galil_stattrak = false;
	inline int index_galil_stattrak = 0;
	inline int paint_kit_index_galil = 0;
	inline float galil_wear = 0.f;

	inline bool m4a4_stattrak = false;
	inline int index_m4a4_stattrak = 0;
	inline int paint_kit_index_m4a4 = 0;
	inline float m4a4_wear = 0.f;

	inline bool m4a1_stattrak = false;
	inline int index_m4a1_stattrak = 0;
	inline int paint_kit_index_m4a1 = 0;
	inline float m4a1_wear = 0.f;

	inline bool ak47_stattrak = false;
	inline int index_ak47_stattrak = 0;
	inline int paint_kit_index_ak47 = 0;
	inline float ak47_wear = 0.f;

	inline bool sg553_stattrak = false;
	inline int index_sg553_stattrak = 0;
	inline int paint_kit_index_sg553 = 0;
	inline float sg553_wear = 0.f;

	inline bool aug_stattrak = false;
	inline int index_aug_stattrak = 0;
	inline int paint_kit_index_aug = 0;
	inline float aug_wear = 0.f;

	inline bool ssg08_stattrak = false;
	inline int index_ssg08_stattrak = 0;
	inline int paint_kit_index_ssg08 = 0;
	inline float ssg08_wear = 0.f;

	inline bool awp_stattrak = false;
	inline int index_awp_stattrak = 0;
	inline int paint_kit_index_awp = 0;
	inline float awp_wear = 0.f;

	inline bool scar_stattrak = false;
	inline int index_scar_stattrak = 0;
	inline int paint_kit_index_scar = 0;
	inline float scar_wear = 0.f;

	inline bool g3sg1_stattrak = false;
	inline int index_g3sg1_stattrak = 0;
	inline int paint_kit_index_g3sg1 = 0;
	inline float g3sg1_wear = 0.f;

	inline bool sawoff_stattrak = false;
	inline int index_sawoff_stattrak = 0;
	inline int paint_kit_index_sawoff = 0;
	inline float sawoff_wear = 0.f;

	inline bool m249_stattrak = false;
	inline int index_m249_stattrak = 0;
	inline int paint_kit_index_m249 = 0;
	inline float m249_wear = 0.f;

	inline bool negev_stattrak = false;
	inline int index_negev_stattrak = 0;
	inline int paint_kit_index_negev = 0;
	inline float negev_wear = 0.f;

	inline bool mag7_stattrak = false;
	inline int index_mag7_stattrak = 0;
	inline int paint_kit_index_mag7 = 0;
	inline float mag7_wear = 0.f;

	inline bool xm1014_stattrak = false;
	inline int index_xm1014_stattrak = 0;
	inline int paint_kit_index_xm1014 = 0;
	inline float xm1014_wear = 0.f;

	inline bool nova_stattrak = false;
	inline int index_nova_stattrak = 0;
	inline int paint_kit_index_nova = 0;
	inline float nova_wear = 0.f;

	inline bool bizon_stattrak = false;
	inline int index_bizon_stattrak = 0;
	inline int paint_kit_index_bizon = 0;
	inline float bizon_wear = 0.f;

	inline bool mp5sd_stattrak = false;
	inline int index_mp5sd_stattrak = 0;
	inline int paint_kit_index_mp5sd = 0;
	inline float mp5sd_wear = 0.f;

	inline bool mp7_stattrak = false;
	inline int index_mp7_stattrak = 0;
	inline int paint_kit_index_mp7 = 0;
	inline float mp7_wear = 0.f;
	
	inline bool mp9_stattrak = false;
	inline int index_mp9_stattrak = 0;
	inline int paint_kit_index_mp9 = 0;
	inline float mp9_wear = 0.f;

	inline bool mac10_stattrak = false;
	inline int index_mac10_stattrak = 0;
	inline int paint_kit_index_mac10 = 0;
	inline float mac10_wear = 0.f;

	inline bool p90_stattrak = false;
	inline int index_p90_stattrak = 0;
	inline int paint_kit_index_p90 = 0;
	inline float p90_wear = 0.f;

	inline bool ump45_stattrak = false;
	inline int index_ump45_stattrak = 0;
	inline int paint_kit_index_ump45 = 0;
	inline float ump45_wear = 0.f;
}
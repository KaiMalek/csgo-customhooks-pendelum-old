#include "../features.hpp"

bool apply_knife_model(attributable_item_t* weapon, const char* model, player_t* local) noexcept 
{
	auto viewmodel = reinterpret_cast<base_view_model_t*>(interfaces::entity_list->get_client_entity_handle(local->view_model()));
	if (!viewmodel)
		return false;

	auto h_view_model_weapon = viewmodel->weapon();
	if (!h_view_model_weapon)
		return false;

	auto view_model_weapon = reinterpret_cast<attributable_item_t*>(interfaces::entity_list->get_client_entity_handle(h_view_model_weapon));
	if (view_model_weapon != weapon)
		return false;

	viewmodel->model_index() = interfaces::model_info->get_model_index(model);

	return true;
}

bool apply_knife_skin(attributable_item_t* weapon, int item_definition_index, int model_index) noexcept 
{
	weapon->model_index() = model_index;
	weapon->item_definition_index() = item_definition_index;

	return true;
}

void skins::skinchanger::run()
{
	if (!interfaces::engine->is_in_game() || !interfaces::engine->is_connected())
		return;

	auto local_ent = reinterpret_cast<player_t*>(interfaces::entity_list->get_client_entity(interfaces::engine->get_local_player()));

	if (!local_ent || !local_ent->is_alive())
		return;

	static const auto model_default_t = "models/weapons/v_knife_default_t.mdl";
	static const auto model_default_ct = "models / weapons / v_knife_default_ct.mdl";
	static const auto model_bayonet = "models/weapons/v_knife_bayonet.mdl";
	static const auto model_m9 = "models/weapons/v_knife_m9_bay.mdl";
	static const auto model_karambit = "models/weapons/v_knife_karam.mdl";
	static const auto model_bowie = "models/weapons/v_knife_survival_bowie.mdl";
	static const auto model_butterfly = "models/weapons/v_knife_butterfly.mdl";
	static const auto model_falchion = "models/weapons/v_knife_falchion_advanced.mdl";
	static const auto model_flip = "models/weapons/v_knife_flip.mdl";
	static const auto model_gut = "models/weapons/v_knife_gut.mdl";
	static const auto model_huntsman = "models/weapons/v_knife_tactical.mdl";
	static const auto model_shadow_daggers = "models/weapons/v_knife_push.mdl";
	static const auto model_navaja = "models/weapons/v_knife_gypsy_jackknife.mdl";
	static const auto model_stiletto = "models/weapons/v_knife_stiletto.mdl";
	static const auto model_talon = "models/weapons/v_knife_widowmaker.mdl";
	static const auto model_ursus = "models/weapons/v_knife_ursus.mdl";
	static const auto model_nomad = "models/weapons/v_knife_outdoor.mdl";
	static const auto model_skeleton = "models/weapons/v_knife_skeleton.mdl";
	static const auto model_survival = "models/weapons/v_knife_canis.mdl";
	static const auto model_paracord = "models/weapons/v_knife_cord.mdl";
	static const auto model_css = "models/weapons/v_knife_css.mdl";

	static const auto index_bayonet = interfaces::model_info->get_model_index("models/weapons/v_knife_bayonet.mdl");
	static const auto index_m9 = interfaces::model_info->get_model_index("models/weapons/v_knife_m9_bay.mdl");
	static const auto index_karambit = interfaces::model_info->get_model_index("models/weapons/v_knife_karam.mdl");
	static const auto index_bowie = interfaces::model_info->get_model_index("models/weapons/v_knife_survival_bowie.mdl");
	static const auto index_butterfly = interfaces::model_info->get_model_index("models/weapons/v_knife_butterfly.mdl");
	static const auto index_falchion = interfaces::model_info->get_model_index("models/weapons/v_knife_falchion_advanced.mdl");
	static const auto index_flip = interfaces::model_info->get_model_index("models/weapons/v_knife_flip.mdl");
	static const auto index_gut = interfaces::model_info->get_model_index("models/weapons/v_knife_gut.mdl");
	static const auto index_huntsman = interfaces::model_info->get_model_index("models/weapons/v_knife_tactical.mdl");
	static const auto index_shadow_daggers = interfaces::model_info->get_model_index("models/weapons/v_knife_push.mdl");
	static const auto index_navaja = interfaces::model_info->get_model_index("models/weapons/v_knife_gypsy_jackknife.mdl");
	static const auto index_stiletto = interfaces::model_info->get_model_index("models/weapons/v_knife_stiletto.mdl");
	static const auto index_talon = interfaces::model_info->get_model_index("models/weapons/v_knife_widowmaker.mdl");
	static const auto index_ursus = interfaces::model_info->get_model_index("models/weapons/v_knife_ursus.mdl");
	static const auto index_nomad = interfaces::model_info->get_model_index("models/weapons/v_knife_outdoor.mdl");
	static const auto index_skeleton = interfaces::model_info->get_model_index("models/weapons/v_knife_skeleton.mdl");
	static const auto index_survival = interfaces::model_info->get_model_index("models/weapons/v_knife_canis.mdl");
	static const auto index_paracord = interfaces::model_info->get_model_index("models/weapons/v_knife_cord.mdl");
	static const auto index_css = interfaces::model_info->get_model_index("models/weapons/v_knife_css.mdl");

	auto active_weapon = local_ent->active_weapon();
	if (!active_weapon)
		return;

	auto my_weapons = local_ent->get_weapons();
	for (size_t i = 0; my_weapons[i] != 0xFFFFFFFF; i++) {
		auto weapon_atr = reinterpret_cast<attributable_item_t*>(interfaces::entity_list->get_client_entity_handle(my_weapons[i]));
		auto weapon = reinterpret_cast<weapon_t*>(interfaces::entity_list->get_client_entity_handle(my_weapons[i]));

		if (!weapon_atr || !weapon || weapon->is_c4() || weapon->is_nade() || weapon->is_taser())
			return;

		if (weapon->is_knife()) {
			switch (variables::knife_model) {
			case 0:
				break;
			case 1:
				apply_knife_model(weapon_atr, model_bayonet, local_ent);
				break;
			case 2:
				apply_knife_model(weapon_atr, model_flip, local_ent);
				break;
			case 3:
				apply_knife_model(weapon_atr, model_gut, local_ent);
				break;
			case 4:
				apply_knife_model(weapon_atr, model_karambit, local_ent);
				break;
			case 5:
				apply_knife_model(weapon_atr, model_m9, local_ent);
				break;
			case 6:
				apply_knife_model(weapon_atr, model_huntsman, local_ent);
				break;
			case 7:
				apply_knife_model(weapon_atr, model_falchion, local_ent);
				break;
			case 8:
				apply_knife_model(weapon_atr, model_bowie, local_ent);
				break;
			case 9:
				apply_knife_model(weapon_atr, model_butterfly, local_ent);
				break;
			case 10:
				apply_knife_model(weapon_atr, model_shadow_daggers, local_ent);
				break;
			case 11:
				apply_knife_model(weapon_atr, model_ursus, local_ent);
				break;
			case 12:
				apply_knife_model(weapon_atr, model_navaja, local_ent);
				break;
			case 13:
				apply_knife_model(weapon_atr, model_stiletto, local_ent);
				break;
			case 14:
				apply_knife_model(weapon_atr, model_talon, local_ent);
				break;
			case 15:
				apply_knife_model(weapon_atr, model_nomad, local_ent);
				break;
			case 16:
				apply_knife_model(weapon_atr, model_skeleton, local_ent);
				break;
			case 17:
				apply_knife_model(weapon_atr, model_survival, local_ent);
				break;
			case 18:
				apply_knife_model(weapon_atr, model_paracord, local_ent);
				break;
			case 19:
				apply_knife_model(weapon_atr, model_css, local_ent);
				break;
			}

			switch (variables::knife_model) {
			case 0:
				break;
			case 1:
				apply_knife_skin(weapon_atr, WEAPON_KNIFE_BAYONET, index_bayonet);
				break;
			case 2:
				apply_knife_skin(weapon_atr, WEAPON_KNIFE_FLIP, index_flip);
				break;
			case 3:
				apply_knife_skin(weapon_atr, WEAPON_KNIFE_GUT, index_gut);
				break;
			case 4:
				apply_knife_skin(weapon_atr, WEAPON_KNIFE_KARAMBIT, index_karambit);
				break;
			case 5:
				apply_knife_skin(weapon_atr, WEAPON_KNIFE_M9_BAYONET, index_m9);
				break;
			case 6:
				apply_knife_skin(weapon_atr, WEAPON_KNIFE_TACTICAL, index_huntsman);
				break;
			case 7:
				apply_knife_skin(weapon_atr, WEAPON_KNIFE_FALCHION, index_falchion);
				break;
			case 8:
				apply_knife_skin(weapon_atr, WEAPON_KNIFE_SURVIVAL_BOWIE, index_bowie);
				break;
			case 9:
				apply_knife_skin(weapon_atr, WEAPON_KNIFE_BUTTERFLY, index_butterfly);
				break;
			case 10:
				apply_knife_skin(weapon_atr, WEAPON_KNIFE_PUSH, index_shadow_daggers);
				break;
			case 11:
				apply_knife_skin(weapon_atr, WEAPON_KNIFE_URSUS, index_ursus);
				break;
			case 12:
				apply_knife_skin(weapon_atr, WEAPON_KNIFE_GYPSY_JACKKNIFE, index_navaja);
				break;
			case 13:
				apply_knife_skin(weapon_atr, WEAPON_KNIFE_STILETTO, index_stiletto);
				break;
			case 14:
				apply_knife_skin(weapon_atr, WEAPON_KNIFE_WIDOWMAKER, index_talon);
				break;
			case 15:
				apply_knife_skin(weapon_atr, WEAPON_KNIFE_OUTDOOR, index_nomad);
				break;
			case 16:
				apply_knife_skin(weapon_atr, WEAPON_KNIFE_SKELETON, index_skeleton);
				break;
			case 17:
				apply_knife_skin(weapon_atr, WEAPON_KNIFE_CANIS, index_survival);
				break;
			case 18:
				apply_knife_skin(weapon_atr, WEAPON_KNIFE_CORD, index_paracord);
				break;
			case 19:
				apply_knife_skin(weapon_atr, WEAPON_KNIFE_CSS, index_css);
				break;
			}
		}
		weapon_atr->item_id_high() = 1;
		weapon_atr->fallback_wear() = 0.0000001f;
		weapon_atr->fallback_seed() = 420;
		switch (weapon->item_definition_index()) {
		case WEAPON_KNIFE_BAYONET:
			if (variables::bayonet_stattrak)
				weapon_atr->fallback_stattrak() = variables::index_bayonet_stattrak;

			weapon_atr->fallback_wear() = variables::bayonet_wear;
			switch (variables::knife_skin) {
			case 0:
				weapon_atr->fallback_paint_kit() = 0; break;
			case 1:
				weapon_atr->fallback_paint_kit() = 558; break;
			case 2:
				weapon_atr->fallback_paint_kit() = 568; break;
			case 3:
				weapon_atr->fallback_paint_kit() = 573; break;
			case 4:
				weapon_atr->fallback_paint_kit() = 563; break;
			case 5:
				weapon_atr->fallback_paint_kit() = 580; break;
			case 6:
				weapon_atr->fallback_paint_kit() = 578; break;
			case 7:
				weapon_atr->fallback_paint_kit() = 856; break;
			case 8:
				weapon_atr->fallback_paint_kit() = 409; break;
			case 9:
				weapon_atr->fallback_paint_kit() = 415; break;
			case 10:
				weapon_atr->fallback_paint_kit() = 98; break;
			case 11:
				weapon_atr->fallback_paint_kit() = 857; break;
			case 12:
				weapon_atr->fallback_paint_kit() = 203; break;
			case 13:
				weapon_atr->fallback_paint_kit() = 38; break;
			case 14:
				weapon_atr->fallback_paint_kit() = 59; break;
			case 15:
				weapon_atr->fallback_paint_kit() = 44; break;
			case 16:
				weapon_atr->fallback_paint_kit() = 12; break;
			case 17:
				weapon_atr->fallback_paint_kit() = 42; break;
			case 18:
				weapon_atr->fallback_paint_kit() = 40; break;
			case 19:
				weapon_atr->fallback_paint_kit() = 72; break;
			case 20:
				weapon_atr->fallback_paint_kit() = 5; break;
			case 21:
				weapon_atr->fallback_paint_kit() = 43; break;
			case 22:
				weapon_atr->fallback_paint_kit() = 175; break;
			case 23:
				weapon_atr->fallback_paint_kit() = 77; break;
			case 24:
				weapon_atr->fallback_paint_kit() = 143; break;
			}
			break;
		case WEAPON_KNIFE_FLIP:
			if (variables::flip_stattrak)
				weapon_atr->fallback_stattrak() = variables::index_flip_stattrak;

			weapon_atr->fallback_wear() = variables::flip_wear;
			switch (variables::knife_skin)
			{
			case 0:
				weapon_atr->fallback_paint_kit() = 0; break;
			case 1:
				weapon_atr->fallback_paint_kit() = 559; break;
			case 2:
				weapon_atr->fallback_paint_kit() = 568; break;
			case 3:
				weapon_atr->fallback_paint_kit() = 574; break;
			case 4:
				weapon_atr->fallback_paint_kit() = 564; break;
			case 5:
				weapon_atr->fallback_paint_kit() = 581; break;
			case 6:
				weapon_atr->fallback_paint_kit() = 579; break;
			case 7:
				weapon_atr->fallback_paint_kit() = 856; break;
			case 8:
				weapon_atr->fallback_paint_kit() = 409; break;
			case 9:
				weapon_atr->fallback_paint_kit() = 415; break;
			case 10:
				weapon_atr->fallback_paint_kit() = 98; break;
			case 11:
				weapon_atr->fallback_paint_kit() = 857; break;
			case 12:
				weapon_atr->fallback_paint_kit() = 203; break;
			case 13:
				weapon_atr->fallback_paint_kit() = 38; break;
			case 14:
				weapon_atr->fallback_paint_kit() = 59; break;
			case 15:
				weapon_atr->fallback_paint_kit() = 44; break;
			case 16:
				weapon_atr->fallback_paint_kit() = 12; break;
			case 17:
				weapon_atr->fallback_paint_kit() = 42; break;
			case 18:
				weapon_atr->fallback_paint_kit() = 40; break;
			case 19:
				weapon_atr->fallback_paint_kit() = 72; break;
			case 20:
				weapon_atr->fallback_paint_kit() = 5; break;
			case 21:
				weapon_atr->fallback_paint_kit() = 43; break;
			case 22:
				weapon_atr->fallback_paint_kit() = 175; break;
			case 23:
				weapon_atr->fallback_paint_kit() = 77; break;
			case 24:
				weapon_atr->fallback_paint_kit() = 143; break;
			}
			break;
		case WEAPON_KNIFE_GUT:
			if (variables::gut_stattrak)
				weapon_atr->fallback_stattrak() = variables::index_gut_stattrak;

			weapon_atr->fallback_wear() = variables::gut_wear;
			switch (variables::knife_skin)
			{
			case 0:
				weapon_atr->fallback_paint_kit() = 0; break;
			case 1:
				weapon_atr->fallback_paint_kit() = 560; break;
			case 2:
				weapon_atr->fallback_paint_kit() = 568; break;
			case 3:
				weapon_atr->fallback_paint_kit() = 575; break;
			case 4:
				weapon_atr->fallback_paint_kit() = 565; break;
			case 5:
				weapon_atr->fallback_paint_kit() = 580; break;
			case 6:
				weapon_atr->fallback_paint_kit() = 578; break;
			case 7:
				weapon_atr->fallback_paint_kit() = 856; break;
			case 8:
				weapon_atr->fallback_paint_kit() = 409; break;
			case 9:
				weapon_atr->fallback_paint_kit() = 415; break;
			case 10:
				weapon_atr->fallback_paint_kit() = 98; break;
			case 11:
				weapon_atr->fallback_paint_kit() = 857; break;
			case 12:
				weapon_atr->fallback_paint_kit() = 203; break;
			case 13:
				weapon_atr->fallback_paint_kit() = 38; break;
			case 14:
				weapon_atr->fallback_paint_kit() = 59; break;
			case 15:
				weapon_atr->fallback_paint_kit() = 44; break;
			case 16:
				weapon_atr->fallback_paint_kit() = 12; break;
			case 17:
				weapon_atr->fallback_paint_kit() = 42; break;
			case 18:
				weapon_atr->fallback_paint_kit() = 40; break;
			case 19:
				weapon_atr->fallback_paint_kit() = 72; break;
			case 20:
				weapon_atr->fallback_paint_kit() = 5; break;
			case 21:
				weapon_atr->fallback_paint_kit() = 43; break;
			case 22:
				weapon_atr->fallback_paint_kit() = 175; break;
			case 23:
				weapon_atr->fallback_paint_kit() = 77; break;
			case 24:
				weapon_atr->fallback_paint_kit() = 143; break;
			}
			break;
		case WEAPON_KNIFE_KARAMBIT:
			if (variables::karambit_stattrak)
				weapon_atr->fallback_stattrak() = variables::index_karambit_stattrak;

			weapon_atr->fallback_wear() = variables::karambit_wear;
			switch (variables::knife_skin)
			{
			case 0:
				weapon_atr->fallback_paint_kit() = 0; break;
			case 1:
				weapon_atr->fallback_paint_kit() = 561; break;
			case 2:
				weapon_atr->fallback_paint_kit() = 568; break;
			case 3:
				weapon_atr->fallback_paint_kit() = 576; break;
			case 4:
				weapon_atr->fallback_paint_kit() = 566; break;
			case 5:
				weapon_atr->fallback_paint_kit() = 580; break;
			case 6:
				weapon_atr->fallback_paint_kit() = 578; break;
			case 7:
				weapon_atr->fallback_paint_kit() = 856; break;
			case 8:
				weapon_atr->fallback_paint_kit() = 409; break;
			case 9:
				weapon_atr->fallback_paint_kit() = 415; break;
			case 10:
				weapon_atr->fallback_paint_kit() = 98; break;
			case 11:
				weapon_atr->fallback_paint_kit() = 857; break;
			case 12:
				weapon_atr->fallback_paint_kit() = 203; break;
			case 13:
				weapon_atr->fallback_paint_kit() = 38; break;
			case 14:
				weapon_atr->fallback_paint_kit() = 59; break;
			case 15:
				weapon_atr->fallback_paint_kit() = 44; break;
			case 16:
				weapon_atr->fallback_paint_kit() = 12; break;
			case 17:
				weapon_atr->fallback_paint_kit() = 42; break;
			case 18:
				weapon_atr->fallback_paint_kit() = 40; break;
			case 19:
				weapon_atr->fallback_paint_kit() = 72; break;
			case 20:
				weapon_atr->fallback_paint_kit() = 5; break;
			case 21:
				weapon_atr->fallback_paint_kit() = 43; break;
			case 22:
				weapon_atr->fallback_paint_kit() = 175; break;
			case 23:
				weapon_atr->fallback_paint_kit() = 77; break;
			case 24:
				weapon_atr->fallback_paint_kit() = 143; break;
			}
			break;
		case WEAPON_KNIFE_M9_BAYONET:
			if (variables::m9bayo_stattrak)
				weapon_atr->fallback_stattrak() = variables::index_m9bayo_stattrak;

			weapon_atr->fallback_wear() = variables::m9bayo_wear;
			switch (variables::knife_skin)
			{
			case 0:
				weapon_atr->fallback_paint_kit() = 0; break;
			case 1:
				weapon_atr->fallback_paint_kit() = 562; break;
			case 2:
				weapon_atr->fallback_paint_kit() = 568; break;
			case 3:
				weapon_atr->fallback_paint_kit() = 577; break;
			case 4:
				weapon_atr->fallback_paint_kit() = 567; break;
			case 5:
				weapon_atr->fallback_paint_kit() = 580; break;
			case 6:
				weapon_atr->fallback_paint_kit() = 578; break;
			case 7:
				weapon_atr->fallback_paint_kit() = 856; break;
			case 8:
				weapon_atr->fallback_paint_kit() = 409; break;
			case 9:
				weapon_atr->fallback_paint_kit() = 415; break;
			case 10:
				weapon_atr->fallback_paint_kit() = 98; break;
			case 11:
				weapon_atr->fallback_paint_kit() = 857; break;
			case 12:
				weapon_atr->fallback_paint_kit() = 203; break;
			case 13:
				weapon_atr->fallback_paint_kit() = 38; break;
			case 14:
				weapon_atr->fallback_paint_kit() = 59; break;
			case 15:
				weapon_atr->fallback_paint_kit() = 44; break;
			case 16:
				weapon_atr->fallback_paint_kit() = 12; break;
			case 17:
				weapon_atr->fallback_paint_kit() = 42; break;
			case 18:
				weapon_atr->fallback_paint_kit() = 40; break;
			case 19:
				weapon_atr->fallback_paint_kit() = 72; break;
			case 20:
				weapon_atr->fallback_paint_kit() = 5; break;
			case 21:
				weapon_atr->fallback_paint_kit() = 43; break;
			case 22:
				weapon_atr->fallback_paint_kit() = 175; break;
			case 23:
				weapon_atr->fallback_paint_kit() = 77; break;
			case 24:
				weapon_atr->fallback_paint_kit() = 143; break;
			}
			break;
		case WEAPON_KNIFE_TACTICAL:
			if (variables::tactical_stattrak)
				weapon_atr->fallback_stattrak() = variables::index_tactical_stattrak;

			weapon_atr->fallback_wear() = variables::tactical_wear;
			switch (variables::knife_skin)
			{
			case 0:
				weapon_atr->fallback_paint_kit() = 0; break;
			case 1:
				weapon_atr->fallback_paint_kit() = 856; break;
			case 2:
				weapon_atr->fallback_paint_kit() = 409; break;
			case 3:
				weapon_atr->fallback_paint_kit() = 415; break;
			case 4:
				weapon_atr->fallback_paint_kit() = 98; break;
			case 5:
				weapon_atr->fallback_paint_kit() = 857; break;
			case 6:
				weapon_atr->fallback_paint_kit() = 203; break;
			case 7:
				weapon_atr->fallback_paint_kit() = 38; break;
			case 8:
				weapon_atr->fallback_paint_kit() = 59; break;
			case 9:
				weapon_atr->fallback_paint_kit() = 44; break;
			case 10:
				weapon_atr->fallback_paint_kit() = 12; break;
			case 11:
				weapon_atr->fallback_paint_kit() = 42; break;
			case 12:
				weapon_atr->fallback_paint_kit() = 40; break;
			case 13:
				weapon_atr->fallback_paint_kit() = 72; break;
			case 14:
				weapon_atr->fallback_paint_kit() = 5; break;
			case 15:
				weapon_atr->fallback_paint_kit() = 43; break;
			case 16:
				weapon_atr->fallback_paint_kit() = 175; break;
			case 17:
				weapon_atr->fallback_paint_kit() = 77; break;
			case 18:
				weapon_atr->fallback_paint_kit() = 143; break;
			}
			break;
		case WEAPON_KNIFE_FALCHION:
			if (variables::falchion_stattrak)
				weapon_atr->fallback_stattrak() = variables::index_falchion_stattrak;

			weapon_atr->fallback_wear() = variables::falchion_wear;
			switch (variables::knife_skin)
			{
			case 0:
				weapon_atr->fallback_paint_kit() = 0; break;
			case 1:
				weapon_atr->fallback_paint_kit() = 856; break;
			case 2:
				weapon_atr->fallback_paint_kit() = 409; break;
			case 3:
				weapon_atr->fallback_paint_kit() = 415; break;
			case 4:
				weapon_atr->fallback_paint_kit() = 98; break;
			case 5:
				weapon_atr->fallback_paint_kit() = 857; break;
			case 6:
				weapon_atr->fallback_paint_kit() = 203; break;
			case 7:
				weapon_atr->fallback_paint_kit() = 38; break;
			case 8:
				weapon_atr->fallback_paint_kit() = 59; break;
			case 9:
				weapon_atr->fallback_paint_kit() = 44; break;
			case 10:
				weapon_atr->fallback_paint_kit() = 12; break;
			case 11:
				weapon_atr->fallback_paint_kit() = 42; break;
			case 12:
				weapon_atr->fallback_paint_kit() = 40; break;
			case 13:
				weapon_atr->fallback_paint_kit() = 72; break;
			case 14:
				weapon_atr->fallback_paint_kit() = 5; break;
			case 15:
				weapon_atr->fallback_paint_kit() = 43; break;
			case 16:
				weapon_atr->fallback_paint_kit() = 175; break;
			case 17:
				weapon_atr->fallback_paint_kit() = 77; break;
			case 18:
				weapon_atr->fallback_paint_kit() = 143; break;
			}
			break;
		case WEAPON_KNIFE_SURVIVAL_BOWIE:
			if (variables::bowie_stattrak)
				weapon_atr->fallback_stattrak() = variables::index_bowie_stattrak;

			weapon_atr->fallback_wear() = variables::bowie_wear;
			switch (variables::knife_skin)
			{
			case 0:
				weapon_atr->fallback_paint_kit() = 0; break;
			case 1:
				weapon_atr->fallback_paint_kit() = 856; break;
			case 2:
				weapon_atr->fallback_paint_kit() = 409; break;
			case 3:
				weapon_atr->fallback_paint_kit() = 415; break;
			case 4:
				weapon_atr->fallback_paint_kit() = 98; break;
			case 5:
				weapon_atr->fallback_paint_kit() = 857; break;
			case 6:
				weapon_atr->fallback_paint_kit() = 203; break;
			case 7:
				weapon_atr->fallback_paint_kit() = 38; break;
			case 8:
				weapon_atr->fallback_paint_kit() = 59; break;
			case 9:
				weapon_atr->fallback_paint_kit() = 44; break;
			case 10:
				weapon_atr->fallback_paint_kit() = 12; break;
			case 11:
				weapon_atr->fallback_paint_kit() = 42; break;
			case 12:
				weapon_atr->fallback_paint_kit() = 40; break;
			case 13:
				weapon_atr->fallback_paint_kit() = 72; break;
			case 14:
				weapon_atr->fallback_paint_kit() = 5; break;
			case 15:
				weapon_atr->fallback_paint_kit() = 43; break;
			case 16:
				weapon_atr->fallback_paint_kit() = 175; break;
			case 17:
				weapon_atr->fallback_paint_kit() = 77; break;
			case 18:
				weapon_atr->fallback_paint_kit() = 143; break;
			}
			break;
		case WEAPON_KNIFE_BUTTERFLY:
			if (variables::butterfly_stattrak)
				weapon_atr->fallback_stattrak() = variables::index_butterfly_stattrak;

			weapon_atr->fallback_wear() = variables::butterfly_wear;
			switch (variables::knife_skin)
			{
			case 0:
				weapon_atr->fallback_paint_kit() = 0; break;
			case 1:
				weapon_atr->fallback_paint_kit() = 856; break;
			case 2:
				weapon_atr->fallback_paint_kit() = 409; break;
			case 3:
				weapon_atr->fallback_paint_kit() = 415; break;
			case 4:
				weapon_atr->fallback_paint_kit() = 98; break;
			case 5:
				weapon_atr->fallback_paint_kit() = 857; break;
			case 6:
				weapon_atr->fallback_paint_kit() = 203; break;
			case 7:
				weapon_atr->fallback_paint_kit() = 38; break;
			case 8:
				weapon_atr->fallback_paint_kit() = 59; break;
			case 9:
				weapon_atr->fallback_paint_kit() = 44; break;
			case 10:
				weapon_atr->fallback_paint_kit() = 12; break;
			case 11:
				weapon_atr->fallback_paint_kit() = 42; break;
			case 12:
				weapon_atr->fallback_paint_kit() = 40; break;
			case 13:
				weapon_atr->fallback_paint_kit() = 72; break;
			case 14:
				weapon_atr->fallback_paint_kit() = 5; break;
			case 15:
				weapon_atr->fallback_paint_kit() = 43; break;
			case 16:
				weapon_atr->fallback_paint_kit() = 175; break;
			case 17:
				weapon_atr->fallback_paint_kit() = 77; break;
			case 18:
				weapon_atr->fallback_paint_kit() = 143; break;
			}
			break;
		case WEAPON_KNIFE_PUSH:
			if (variables::push_stattrak)
				weapon_atr->fallback_stattrak() = variables::index_push_stattrak;

			weapon_atr->fallback_wear() = variables::push_wear;
			switch (variables::knife_skin)
			{
			case 0:
				weapon_atr->fallback_paint_kit() = 0; break;
			case 1:
				weapon_atr->fallback_paint_kit() = 856; break;
			case 2:
				weapon_atr->fallback_paint_kit() = 409; break;
			case 3:
				weapon_atr->fallback_paint_kit() = 415; break;
			case 4:
				weapon_atr->fallback_paint_kit() = 98; break;
			case 5:
				weapon_atr->fallback_paint_kit() = 857; break;
			case 6:
				weapon_atr->fallback_paint_kit() = 203; break;
			case 7:
				weapon_atr->fallback_paint_kit() = 38; break;
			case 8:
				weapon_atr->fallback_paint_kit() = 59; break;
			case 9:
				weapon_atr->fallback_paint_kit() = 44; break;
			case 10:
				weapon_atr->fallback_paint_kit() = 12; break;
			case 11:
				weapon_atr->fallback_paint_kit() = 42; break;
			case 12:
				weapon_atr->fallback_paint_kit() = 40; break;
			case 13:
				weapon_atr->fallback_paint_kit() = 72; break;
			case 14:
				weapon_atr->fallback_paint_kit() = 5; break;
			case 15:
				weapon_atr->fallback_paint_kit() = 43; break;
			case 16:
				weapon_atr->fallback_paint_kit() = 175; break;
			case 17:
				weapon_atr->fallback_paint_kit() = 77; break;
			case 18:
				weapon_atr->fallback_paint_kit() = 143; break;
			}
			break;
		case WEAPON_KNIFE_URSUS:
			if (variables::ursus_stattrak)
				weapon_atr->fallback_stattrak() = variables::index_ursus_stattrak;

			weapon_atr->fallback_wear() = variables::ursus_wear;
			switch (variables::knife_skin)
			{
			case 0:
				weapon_atr->fallback_paint_kit() = 0; break;
			case 1:
				weapon_atr->fallback_paint_kit() = 856; break;
			case 2:
				weapon_atr->fallback_paint_kit() = 409; break;
			case 3:
				weapon_atr->fallback_paint_kit() = 415; break;
			case 4:
				weapon_atr->fallback_paint_kit() = 98; break;
			case 5:
				weapon_atr->fallback_paint_kit() = 857; break;
			case 6:
				weapon_atr->fallback_paint_kit() = 203; break;
			case 7:
				weapon_atr->fallback_paint_kit() = 38; break;
			case 8:
				weapon_atr->fallback_paint_kit() = 59; break;
			case 9:
				weapon_atr->fallback_paint_kit() = 44; break;
			case 10:
				weapon_atr->fallback_paint_kit() = 12; break;
			case 11:
				weapon_atr->fallback_paint_kit() = 42; break;
			case 12:
				weapon_atr->fallback_paint_kit() = 40; break;
			case 13:
				weapon_atr->fallback_paint_kit() = 72; break;
			case 14:
				weapon_atr->fallback_paint_kit() = 5; break;
			case 15:
				weapon_atr->fallback_paint_kit() = 43; break;
			case 16:
				weapon_atr->fallback_paint_kit() = 175; break;
			case 17:
				weapon_atr->fallback_paint_kit() = 77; break;
			case 18:
				weapon_atr->fallback_paint_kit() = 143; break;
			}
			break;
		case WEAPON_KNIFE_GYPSY_JACKKNIFE:
			if (variables::jackknife_stattrak)
				weapon_atr->fallback_stattrak() = variables::index_jackknife_stattrak;

			weapon_atr->fallback_wear() = variables::jackknife_wear;
			switch (variables::knife_skin)
			{
			case 0:
				weapon_atr->fallback_paint_kit() = 0; break;
			case 1:
				weapon_atr->fallback_paint_kit() = 856; break;
			case 2:
				weapon_atr->fallback_paint_kit() = 409; break;
			case 3:
				weapon_atr->fallback_paint_kit() = 415; break;
			case 4:
				weapon_atr->fallback_paint_kit() = 98; break;
			case 5:
				weapon_atr->fallback_paint_kit() = 857; break;
			case 6:
				weapon_atr->fallback_paint_kit() = 203; break;
			case 7:
				weapon_atr->fallback_paint_kit() = 38; break;
			case 8:
				weapon_atr->fallback_paint_kit() = 59; break;
			case 9:
				weapon_atr->fallback_paint_kit() = 44; break;
			case 10:
				weapon_atr->fallback_paint_kit() = 12; break;
			case 11:
				weapon_atr->fallback_paint_kit() = 42; break;
			case 12:
				weapon_atr->fallback_paint_kit() = 40; break;
			case 13:
				weapon_atr->fallback_paint_kit() = 72; break;
			case 14:
				weapon_atr->fallback_paint_kit() = 5; break;
			case 15:
				weapon_atr->fallback_paint_kit() = 43; break;
			case 16:
				weapon_atr->fallback_paint_kit() = 175; break;
			case 17:
				weapon_atr->fallback_paint_kit() = 77; break;
			case 18:
				weapon_atr->fallback_paint_kit() = 143; break;
			}
			break;
		case WEAPON_KNIFE_STILETTO:
			if (variables::stiletto_stattrak)
				weapon_atr->fallback_stattrak() = variables::index_stiletto_stattrak;

			weapon_atr->fallback_wear() = variables::stiletto_wear;
			switch (variables::knife_skin)
			{
			case 0:
				weapon_atr->fallback_paint_kit() = 0; break;
			case 1:
				weapon_atr->fallback_paint_kit() = 856; break;
			case 2:
				weapon_atr->fallback_paint_kit() = 409; break;
			case 3:
				weapon_atr->fallback_paint_kit() = 415; break;
			case 4:
				weapon_atr->fallback_paint_kit() = 98; break;
			case 5:
				weapon_atr->fallback_paint_kit() = 857; break;
			case 6:
				weapon_atr->fallback_paint_kit() = 203; break;
			case 7:
				weapon_atr->fallback_paint_kit() = 38; break;
			case 8:
				weapon_atr->fallback_paint_kit() = 59; break;
			case 9:
				weapon_atr->fallback_paint_kit() = 44; break;
			case 10:
				weapon_atr->fallback_paint_kit() = 12; break;
			case 11:
				weapon_atr->fallback_paint_kit() = 42; break;
			case 12:
				weapon_atr->fallback_paint_kit() = 40; break;
			case 13:
				weapon_atr->fallback_paint_kit() = 72; break;
			case 14:
				weapon_atr->fallback_paint_kit() = 5; break;
			case 15:
				weapon_atr->fallback_paint_kit() = 43; break;
			case 16:
				weapon_atr->fallback_paint_kit() = 175; break;
			case 17:
				weapon_atr->fallback_paint_kit() = 77; break;
			case 18:
				weapon_atr->fallback_paint_kit() = 143; break;
			}
			break;
		case WEAPON_KNIFE_WIDOWMAKER:
			if (variables::widowmaker_stattrak)
				weapon_atr->fallback_stattrak() = variables::index_widowmaker_stattrak;

			weapon_atr->fallback_wear() = variables::widowmaker_wear;
			switch (variables::knife_skin)
			{
			case 0:
				weapon_atr->fallback_paint_kit() = 0; break;
			case 1:
				weapon_atr->fallback_paint_kit() = 856; break;
			case 2:
				weapon_atr->fallback_paint_kit() = 409; break;
			case 3:
				weapon_atr->fallback_paint_kit() = 415; break;
			case 4:
				weapon_atr->fallback_paint_kit() = 98; break;
			case 5:
				weapon_atr->fallback_paint_kit() = 857; break;
			case 6:
				weapon_atr->fallback_paint_kit() = 203; break;
			case 7:
				weapon_atr->fallback_paint_kit() = 38; break;
			case 8:
				weapon_atr->fallback_paint_kit() = 59; break;
			case 9:
				weapon_atr->fallback_paint_kit() = 44; break;
			case 10:
				weapon_atr->fallback_paint_kit() = 12; break;
			case 11:
				weapon_atr->fallback_paint_kit() = 42; break;
			case 12:
				weapon_atr->fallback_paint_kit() = 40; break;
			case 13:
				weapon_atr->fallback_paint_kit() = 72; break;
			case 14:
				weapon_atr->fallback_paint_kit() = 5; break;
			case 15:
				weapon_atr->fallback_paint_kit() = 43; break;
			case 16:
				weapon_atr->fallback_paint_kit() = 175; break;
			case 17:
				weapon_atr->fallback_paint_kit() = 77; break;
			case 18:
				weapon_atr->fallback_paint_kit() = 143; break;
			}
			break;
		case WEAPON_KNIFE_OUTDOOR:
			if (variables::outdoor_stattrak)
				weapon_atr->fallback_stattrak() = variables::index_outdoor_stattrak;

			weapon_atr->fallback_wear() = variables::outdoor_wear;
			switch (variables::knife_skin)
			{
			case 0:
				weapon_atr->fallback_paint_kit() = 0; break;
			case 1:
				weapon_atr->fallback_paint_kit() = 856; break;
			case 2:
				weapon_atr->fallback_paint_kit() = 409; break;
			case 3:
				weapon_atr->fallback_paint_kit() = 415; break;
			case 4:
				weapon_atr->fallback_paint_kit() = 98; break;
			case 5:
				weapon_atr->fallback_paint_kit() = 857; break;
			case 6:
				weapon_atr->fallback_paint_kit() = 203; break;
			case 7:
				weapon_atr->fallback_paint_kit() = 38; break;
			case 8:
				weapon_atr->fallback_paint_kit() = 59; break;
			case 9:
				weapon_atr->fallback_paint_kit() = 44; break;
			case 10:
				weapon_atr->fallback_paint_kit() = 12; break;
			case 11:
				weapon_atr->fallback_paint_kit() = 42; break;
			case 12:
				weapon_atr->fallback_paint_kit() = 40; break;
			case 13:
				weapon_atr->fallback_paint_kit() = 72; break;
			case 14:
				weapon_atr->fallback_paint_kit() = 5; break;
			case 15:
				weapon_atr->fallback_paint_kit() = 43; break;
			case 16:
				weapon_atr->fallback_paint_kit() = 175; break;
			case 17:
				weapon_atr->fallback_paint_kit() = 77; break;
			case 18:
				weapon_atr->fallback_paint_kit() = 143; break;
			}
			break;
		case WEAPON_KNIFE_SKELETON:
			if (variables::skeleton_stattrak)
				weapon_atr->fallback_stattrak() = variables::index_skeleton_stattrak;

			weapon_atr->fallback_wear() = variables::skeleton_wear;
			switch (variables::knife_skin)
			{
			case 0:
				weapon_atr->fallback_paint_kit() = 0; break;
			case 1:
				weapon_atr->fallback_paint_kit() = 856; break;
			case 2:
				weapon_atr->fallback_paint_kit() = 409; break;
			case 3:
				weapon_atr->fallback_paint_kit() = 415; break;
			case 4:
				weapon_atr->fallback_paint_kit() = 98; break;
			case 5:
				weapon_atr->fallback_paint_kit() = 857; break;
			case 6:
				weapon_atr->fallback_paint_kit() = 203; break;
			case 7:
				weapon_atr->fallback_paint_kit() = 38; break;
			case 8:
				weapon_atr->fallback_paint_kit() = 59; break;
			case 9:
				weapon_atr->fallback_paint_kit() = 44; break;
			case 10:
				weapon_atr->fallback_paint_kit() = 12; break;
			case 11:
				weapon_atr->fallback_paint_kit() = 42; break;
			case 12:
				weapon_atr->fallback_paint_kit() = 40; break;
			case 13:
				weapon_atr->fallback_paint_kit() = 72; break;
			case 14:
				weapon_atr->fallback_paint_kit() = 5; break;
			case 15:
				weapon_atr->fallback_paint_kit() = 43; break;
			case 16:
				weapon_atr->fallback_paint_kit() = 175; break;
			case 17:
				weapon_atr->fallback_paint_kit() = 77; break;
			case 18:
				weapon_atr->fallback_paint_kit() = 143; break;
			}
			break;
		case WEAPON_KNIFE_CANIS:
			if (variables::canis_stattrak)
				weapon_atr->fallback_stattrak() = variables::index_canis_stattrak;

			weapon_atr->fallback_wear() = variables::canis_wear;
			switch (variables::knife_skin)
			{
			case 0:
				weapon_atr->fallback_paint_kit() = 0; break;
			case 1:
				weapon_atr->fallback_paint_kit() = 856; break;
			case 2:
				weapon_atr->fallback_paint_kit() = 409; break;
			case 3:
				weapon_atr->fallback_paint_kit() = 415; break;
			case 4:
				weapon_atr->fallback_paint_kit() = 98; break;
			case 5:
				weapon_atr->fallback_paint_kit() = 857; break;
			case 6:
				weapon_atr->fallback_paint_kit() = 203; break;
			case 7:
				weapon_atr->fallback_paint_kit() = 38; break;
			case 8:
				weapon_atr->fallback_paint_kit() = 59; break;
			case 9:
				weapon_atr->fallback_paint_kit() = 44; break;
			case 10:
				weapon_atr->fallback_paint_kit() = 12; break;
			case 11:
				weapon_atr->fallback_paint_kit() = 42; break;
			case 12:
				weapon_atr->fallback_paint_kit() = 40; break;
			case 13:
				weapon_atr->fallback_paint_kit() = 72; break;
			case 14:
				weapon_atr->fallback_paint_kit() = 5; break;
			case 15:
				weapon_atr->fallback_paint_kit() = 43; break;
			case 16:
				weapon_atr->fallback_paint_kit() = 175; break;
			case 17:
				weapon_atr->fallback_paint_kit() = 77; break;
			case 18:
				weapon_atr->fallback_paint_kit() = 143; break;
			}
			break;
		case WEAPON_KNIFE_CORD:
			if (variables::cord_stattrak)
				weapon_atr->fallback_stattrak() = variables::index_cord_stattrak;

			weapon_atr->fallback_wear() = variables::cord_wear;
			switch (variables::knife_skin)
			{
			case 0:
				weapon_atr->fallback_paint_kit() = 0; break;
			case 1:
				weapon_atr->fallback_paint_kit() = 856; break;
			case 2:
				weapon_atr->fallback_paint_kit() = 409; break;
			case 3:
				weapon_atr->fallback_paint_kit() = 415; break;
			case 4:
				weapon_atr->fallback_paint_kit() = 98; break;
			case 5:
				weapon_atr->fallback_paint_kit() = 857; break;
			case 6:
				weapon_atr->fallback_paint_kit() = 203; break;
			case 7:
				weapon_atr->fallback_paint_kit() = 38; break;
			case 8:
				weapon_atr->fallback_paint_kit() = 59; break;
			case 9:
				weapon_atr->fallback_paint_kit() = 44; break;
			case 10:
				weapon_atr->fallback_paint_kit() = 12; break;
			case 11:
				weapon_atr->fallback_paint_kit() = 42; break;
			case 12:
				weapon_atr->fallback_paint_kit() = 40; break;
			case 13:
				weapon_atr->fallback_paint_kit() = 72; break;
			case 14:
				weapon_atr->fallback_paint_kit() = 5; break;
			case 15:
				weapon_atr->fallback_paint_kit() = 43; break;
			case 16:
				weapon_atr->fallback_paint_kit() = 175; break;
			case 17:
				weapon_atr->fallback_paint_kit() = 77; break;
			case 18:
				weapon_atr->fallback_paint_kit() = 143; break;
			}
			break;
		case WEAPON_KNIFE_CSS:
			if (variables::css_stattrak)
				weapon_atr->fallback_stattrak() = variables::index_css_stattrak;

			weapon_atr->fallback_wear() = variables::css_wear;
			switch (variables::knife_skin)
			{
			case 0:
				weapon_atr->fallback_paint_kit() = 0; break;
			case 1:
				weapon_atr->fallback_paint_kit() = 856; break;
			case 2:
				weapon_atr->fallback_paint_kit() = 409; break;
			case 3:
				weapon_atr->fallback_paint_kit() = 415; break;
			case 4:
				weapon_atr->fallback_paint_kit() = 98; break;
			case 5:
				weapon_atr->fallback_paint_kit() = 857; break;
			case 6:
				weapon_atr->fallback_paint_kit() = 203; break;
			case 7:
				weapon_atr->fallback_paint_kit() = 38; break;
			case 8:
				weapon_atr->fallback_paint_kit() = 59; break;
			case 9:
				weapon_atr->fallback_paint_kit() = 44; break;
			case 10:
				weapon_atr->fallback_paint_kit() = 12; break;
			case 11:
				weapon_atr->fallback_paint_kit() = 42; break;
			case 12:
				weapon_atr->fallback_paint_kit() = 40; break;
			case 13:
				weapon_atr->fallback_paint_kit() = 72; break;
			case 14:
				weapon_atr->fallback_paint_kit() = 5; break;
			case 15:
				weapon_atr->fallback_paint_kit() = 43; break;
			case 16:
				weapon_atr->fallback_paint_kit() = 175; break;
			case 17:
				weapon_atr->fallback_paint_kit() = 77; break;
			case 18:
				weapon_atr->fallback_paint_kit() = 143; break;
			}
			break;
		}
	}	
}

void skins::weaponchanger::run() {
	if (!interfaces::engine->is_in_game() || !interfaces::engine->is_connected())
		return;

	auto local_ent = reinterpret_cast<player_t*>(interfaces::entity_list->get_client_entity(interfaces::engine->get_local_player()));

	if (!local_ent || !local_ent->is_alive())
		return;

	auto active_weapon = local_ent->active_weapon();
	if (!active_weapon)
		return;

	auto my_weapons = local_ent->get_weapons();
	for (size_t i = 0; my_weapons[i] != 0xFFFFFFFF; i++) {
		auto weapon_atr = reinterpret_cast<attributable_item_t*>(interfaces::entity_list->get_client_entity_handle(my_weapons[i]));
		auto weapon = reinterpret_cast<weapon_t*>(interfaces::entity_list->get_client_entity_handle(my_weapons[i]));

		if (!weapon_atr || !weapon || weapon->is_c4() || weapon->is_nade() || weapon->is_taser())
			return;

		switch (weapon->item_definition_index()) {
		case WEAPON_USP_SILENCER:
			if (variables::usp_stattrak)
				weapon_atr->fallback_stattrak() = variables::index_usp_stattrak;

			weapon_atr->fallback_wear() = variables::usp_wear;
			weapon_atr->fallback_paint_kit() = variables::paint_kit_index_usp;
			break;
		case WEAPON_HKP2000:
			if (variables::p2000_stattrak)
				weapon_atr->fallback_stattrak() = variables::index_p2000_stattrak;

			weapon_atr->fallback_wear() = variables::p2000_wear;
			weapon_atr->fallback_paint_kit() = variables::paint_kit_index_p2000;
			break;
		case WEAPON_GLOCK:
			if (variables::glock_stattrak)
				weapon_atr->fallback_stattrak() = variables::index_glock_stattrak;

			weapon_atr->fallback_wear() = variables::glock_wear;
			weapon_atr->fallback_paint_kit() = variables::paint_kit_index_glock;
			break;
		case WEAPON_P250:
			if (variables::p250_stattrak)
				weapon_atr->fallback_stattrak() = variables::index_p250_stattrak;

			weapon_atr->fallback_wear() = variables::p250_wear;
			weapon_atr->fallback_paint_kit() = variables::paint_kit_index_p250;
			break;
		case WEAPON_FIVESEVEN:
			if (variables::fiveseven_stattrak)
				weapon_atr->fallback_stattrak() = variables::index_fiveseven_stattrak;

			weapon_atr->fallback_wear() = variables::fiveseven_wear;
			weapon_atr->fallback_paint_kit() = variables::paint_kit_index_fiveseven;
			break;
		case WEAPON_TEC9:
			if (variables::tec_stattrak)
				weapon_atr->fallback_stattrak() = variables::index_tec_stattrak;

			weapon_atr->fallback_wear() = variables::tec_wear;
			weapon_atr->fallback_paint_kit() = variables::paint_kit_index_tec;
			break;
		case WEAPON_CZ75A:
			if (variables::cz_stattrak)
				weapon_atr->fallback_stattrak() = variables::index_cz_stattrak;

			weapon_atr->fallback_wear() = variables::cz_wear;
			weapon_atr->fallback_paint_kit() = variables::paint_kit_index_cz;
			break;
		case WEAPON_ELITE:
			if (variables::duals_stattrak)
				weapon_atr->fallback_stattrak() = variables::index_duals_stattrak;

			weapon_atr->fallback_wear() = variables::duals_wear;
			weapon_atr->fallback_paint_kit() = variables::paint_kit_index_duals;
			break;
		case WEAPON_DEAGLE:
			if (variables::deagle_stattrak)
				weapon_atr->fallback_stattrak() = variables::index_deagle_stattrak;

			weapon_atr->fallback_wear() = variables::deagle_wear;
			weapon_atr->fallback_paint_kit() = variables::paint_kit_index_deagle;
			break;
		case WEAPON_REVOLVER:
			if (variables::revolver_stattrak)
				weapon_atr->fallback_stattrak() = variables::index_revolver_stattrak;

			weapon_atr->fallback_wear() = variables::revolver_wear;
			weapon_atr->fallback_paint_kit() = variables::paint_kit_index_revolver;
			break;
		case WEAPON_FAMAS:
			if (variables::famas_stattrak)
				weapon_atr->fallback_stattrak() = variables::index_famas_stattrak;

			weapon_atr->fallback_wear() = variables::famas_wear;
			weapon_atr->fallback_paint_kit() = variables::paint_kit_index_famas;
			break;
		case WEAPON_GALILAR:
			if (variables::galil_stattrak)
				weapon_atr->fallback_stattrak() = variables::index_galil_stattrak;

			weapon_atr->fallback_wear() = variables::galil_wear;
			weapon_atr->fallback_paint_kit() = variables::paint_kit_index_galil;
			break;
		case WEAPON_M4A1:
			if (variables::m4a4_stattrak)
				weapon_atr->fallback_stattrak() = variables::index_m4a4_stattrak;

			weapon_atr->fallback_wear() = variables::m4a4_wear;
			weapon_atr->fallback_paint_kit() = variables::paint_kit_index_m4a4;
			break;
		case WEAPON_M4A1_SILENCER:
			if (variables::m4a1_stattrak)
				weapon_atr->fallback_stattrak() = variables::index_m4a1_stattrak;

			weapon_atr->fallback_wear() = variables::m4a1_wear;
			weapon_atr->fallback_paint_kit() = variables::paint_kit_index_m4a1;
			break;
		case WEAPON_AK47:
			if (variables::ak47_stattrak)
				weapon_atr->fallback_stattrak() = variables::index_ak47_stattrak;

			weapon_atr->fallback_wear() = variables::ak47_wear;
			weapon_atr->fallback_paint_kit() = variables::paint_kit_index_ak47;
			break;
		case WEAPON_SG556:
			if (variables::sg553_stattrak)
				weapon_atr->fallback_stattrak() = variables::index_sg553_stattrak;

			weapon_atr->fallback_wear() = variables::sg553_wear;
			weapon_atr->fallback_paint_kit() = variables::paint_kit_index_sg553;
			break;
		case WEAPON_AUG:
			if (variables::aug_stattrak)
				weapon_atr->fallback_stattrak() = variables::index_aug_stattrak;

			weapon_atr->fallback_wear() = variables::aug_wear;
			weapon_atr->fallback_paint_kit() = variables::paint_kit_index_aug;
			break;
		case WEAPON_SSG08:
			if (variables::ssg08_stattrak)
				weapon_atr->fallback_stattrak() = variables::index_ssg08_stattrak;

			weapon_atr->fallback_wear() = variables::ssg08_wear;
			weapon_atr->fallback_paint_kit() = variables::paint_kit_index_ssg08;
			break;
		case WEAPON_AWP:
			if (variables::awp_stattrak)
				weapon_atr->fallback_stattrak() = variables::index_awp_stattrak;

			weapon_atr->fallback_wear() = variables::awp_wear;
			weapon_atr->fallback_paint_kit() = variables::paint_kit_index_awp;
			break;
		case WEAPON_SCAR20:
			if (variables::scar_stattrak)
				weapon_atr->fallback_stattrak() = variables::index_scar_stattrak;

			weapon_atr->fallback_wear() = variables::scar_wear;
			weapon_atr->fallback_paint_kit() = variables::paint_kit_index_scar;
			break;
		case WEAPON_G3SG1:
			if (variables::g3sg1_stattrak)
				weapon_atr->fallback_stattrak() = variables::index_g3sg1_stattrak;
			
			weapon_atr->fallback_wear() = variables::g3sg1_wear;
			weapon_atr->fallback_paint_kit() = variables::paint_kit_index_g3sg1;
			break;
		case WEAPON_SAWEDOFF:
			if (variables::sawoff_stattrak)
				weapon_atr->fallback_stattrak() = variables::index_sawoff_stattrak;

			weapon_atr->fallback_wear() = variables::sawoff_wear;
			weapon_atr->fallback_paint_kit() = variables::paint_kit_index_sawoff;
			break;
		case WEAPON_M249:
			if (variables::m249_stattrak)
				weapon_atr->fallback_stattrak() = variables::index_m249_stattrak;

			weapon_atr->fallback_wear() = variables::m249_wear;
			weapon_atr->fallback_paint_kit() = variables::paint_kit_index_m249;
			break;
		case WEAPON_NEGEV:
			if (variables::negev_stattrak)
				weapon_atr->fallback_stattrak() = variables::index_negev_stattrak;

			weapon_atr->fallback_wear() = variables::negev_wear;
			weapon_atr->fallback_paint_kit() = variables::paint_kit_index_negev;
			break;
		case WEAPON_MAG7:
			if (variables::mag7_stattrak)
				weapon_atr->fallback_stattrak() = variables::index_mag7_stattrak;

			weapon_atr->fallback_wear() = variables::mag7_wear;
			weapon_atr->fallback_paint_kit() = variables::paint_kit_index_mag7;
			break;
		case WEAPON_XM1014:
			if (variables::xm1014_stattrak)
				weapon_atr->fallback_stattrak() = variables::index_xm1014_stattrak;

			weapon_atr->fallback_wear() = variables::xm1014_wear;
			weapon_atr->fallback_paint_kit() = variables::paint_kit_index_xm1014;
			break;
		case WEAPON_NOVA:
			if (variables::nova_stattrak)
				weapon_atr->fallback_stattrak() = variables::index_nova_stattrak;

			weapon_atr->fallback_wear() = variables::nova_wear;
			weapon_atr->fallback_paint_kit() = variables::paint_kit_index_nova;
			break;
		case WEAPON_BIZON:
			if (variables::bizon_stattrak)
				weapon_atr->fallback_stattrak() = variables::index_bizon_stattrak;

			weapon_atr->fallback_wear() = variables::bizon_wear;
			weapon_atr->fallback_paint_kit() = variables::paint_kit_index_bizon;
			break;
		case WEAPON_MP5SD:
			if (variables::mp5sd_stattrak)
				weapon_atr->fallback_stattrak() = variables::index_mp5sd_stattrak;

			weapon_atr->fallback_wear() = variables::mp5sd_wear;
			weapon_atr->fallback_paint_kit() = variables::paint_kit_index_mp5sd;
			break;
		case WEAPON_MP7:
			if (variables::mp7_stattrak)
				weapon_atr->fallback_stattrak() = variables::index_mp7_stattrak;

			weapon_atr->fallback_wear() = variables::mp7_wear;
			weapon_atr->fallback_paint_kit() = variables::paint_kit_index_mp7;
			break;
		case WEAPON_MP9:
			if (variables::mp9_stattrak)
				weapon_atr->fallback_stattrak() = variables::index_mp9_stattrak;

			weapon_atr->fallback_wear() = variables::mp9_wear;
			weapon_atr->fallback_paint_kit() = variables::paint_kit_index_mp9;
			break;
		case WEAPON_MAC10:
			if (variables::mac10_stattrak)
				weapon_atr->fallback_stattrak() = variables::index_mac10_stattrak;

			weapon_atr->fallback_wear() = variables::mac10_wear;
			weapon_atr->fallback_paint_kit() = variables::paint_kit_index_mac10;
			break;
		case WEAPON_P90:
			if (variables::p90_stattrak)
				weapon_atr->fallback_stattrak() = variables::index_p90_stattrak;

			weapon_atr->fallback_wear() = variables::p90_wear;
			weapon_atr->fallback_paint_kit() = variables::paint_kit_index_p90;
			break;
		case WEAPON_UMP45:
			if (variables::ump45_stattrak)
				weapon_atr->fallback_stattrak() = variables::index_ump45_stattrak;

			weapon_atr->fallback_wear() = variables::ump45_wear;
			weapon_atr->fallback_paint_kit() = variables::paint_kit_index_ump45;
			break;
		}
	}
}

#define SEQUENCE_DEFAULT_DRAW 0
#define SEQUENCE_DEFAULT_IDLE1 1
#define SEQUENCE_DEFAULT_IDLE2 2
#define SEQUENCE_DEFAULT_LIGHT_MISS1 3
#define SEQUENCE_DEFAULT_LIGHT_MISS2 4
#define SEQUENCE_DEFAULT_HEAVY_MISS1 9
#define SEQUENCE_DEFAULT_HEAVY_HIT1 10
#define SEQUENCE_DEFAULT_HEAVY_BACKSTAB 11
#define SEQUENCE_DEFAULT_LOOKAT01 12

#define SEQUENCE_BUTTERFLY_DRAW 0
#define SEQUENCE_BUTTERFLY_DRAW2 1
#define SEQUENCE_BUTTERFLY_LOOKAT01 13
#define SEQUENCE_BUTTERFLY_LOOKAT03 15

#define SEQUENCE_FALCHION_IDLE1 1
#define SEQUENCE_FALCHION_HEAVY_MISS1 8
#define SEQUENCE_FALCHION_HEAVY_MISS1_NOFLIP 9
#define SEQUENCE_FALCHION_LOOKAT01 12
#define SEQUENCE_FALCHION_LOOKAT02 13

#define SEQUENCE_DAGGERS_IDLE1 1
#define SEQUENCE_DAGGERS_LIGHT_MISS1 2
#define SEQUENCE_DAGGERS_LIGHT_MISS5 6
#define SEQUENCE_DAGGERS_HEAVY_MISS2 11
#define SEQUENCE_DAGGERS_HEAVY_MISS1 12

#define SEQUENCE_BOWIE_IDLE1 1
#define RandomInt(nMin, nMax) (rand() % (nMax - nMin + 1) + nMin);

typedef void(*RecvVarProxyFn)(const c_recv_proxy_data* pData, void* pStruct, void* pOut);
RecvVarProxyFn fnSequenceProxyFn = nullptr;
RecvVarProxyFn oRecvnModelIndex;

void Hooked_RecvProxy_Viewmodel(c_recv_proxy_data* pData, void* pStruct, void* pOut)
{
	static int default_t = interfaces::model_info->get_model_index("models/weapons/v_knife_default_t.mdl");
	static int default_ct = interfaces::model_info->get_model_index("models/weapons/v_knife_default_ct.mdl");
	static int iBayonet = interfaces::model_info->get_model_index("models/weapons/v_knife_bayonet.mdl");
	static int iButterfly = interfaces::model_info->get_model_index("models/weapons/v_knife_butterfly.mdl");
	static int iFlip = interfaces::model_info->get_model_index("models/weapons/v_knife_flip.mdl");
	static int iGut = interfaces::model_info->get_model_index("models/weapons/v_knife_gut.mdl");
	static int iKarambit = interfaces::model_info->get_model_index("models/weapons/v_knife_karam.mdl");
	static int iM9Bayonet = interfaces::model_info->get_model_index("models/weapons/v_knife_m9_bay.mdl");
	static int iHuntsman = interfaces::model_info->get_model_index("models/weapons/v_knife_tactical.mdl");
	static int iFalchion = interfaces::model_info->get_model_index("models/weapons/v_knife_falchion_advanced.mdl");
	static int iDagger = interfaces::model_info->get_model_index("models/weapons/v_knife_push.mdl");
	static int iBowie = interfaces::model_info->get_model_index("models/weapons/v_knife_survival_bowie.mdl");
	static int iUrsus = interfaces::model_info->get_model_index("models/weapons/v_knife_ursus.mdl");
	static int iNavaja = interfaces::model_info->get_model_index("models/weapons/v_knife_gypsy_jackknife.mdl");
	static int iStiletto = interfaces::model_info->get_model_index("models/weapons/v_knife_stiletto.mdl");
	static int iTalon = interfaces::model_info->get_model_index("models/weapons/v_knife_widowmaker.mdl");
	static int iNomad = interfaces::model_info->get_model_index("models/weapons/v_knife_outdoor.mdl");
	static int iSkeleton = interfaces::model_info->get_model_index("models/weapons/v_knife_skeleton.mdl");
	static int iSurvival = interfaces::model_info->get_model_index("models/weapons/v_knife_canis.mdl");
	static int iParacord = interfaces::model_info->get_model_index("models/weapons/v_knife_cord.mdl");
	static int iClassic = interfaces::model_info->get_model_index("models/weapons/v_knife_css.mdl");

	if (csgo::local_player)
	{
		if (csgo::local_player->is_alive() && (pData->value.m_int == default_ct
			|| pData->value.m_int == default_t
			|| pData->value.m_int == iGut
			|| pData->value.m_int == iKarambit
			|| pData->value.m_int == iM9Bayonet
			|| pData->value.m_int == iHuntsman
			|| pData->value.m_int == iFalchion
			|| pData->value.m_int == iDagger
			|| pData->value.m_int == iBowie
			|| pData->value.m_int == iButterfly
			|| pData->value.m_int == iFlip
			|| pData->value.m_int == iBayonet
			|| pData->value.m_int == iUrsus
			|| pData->value.m_int == iNavaja
			|| pData->value.m_int == iStiletto
			|| pData->value.m_int == iTalon
			|| pData->value.m_int == iNomad
			|| pData->value.m_int == iSkeleton
			|| pData->value.m_int == iSurvival
			|| pData->value.m_int == iParacord
			|| pData->value.m_int == iClassic))
		{
			if (variables::knife_model == 1)
				pData->value.m_int = iBayonet;
			else if (variables::knife_model == 2)
				pData->value.m_int = iFlip;
			else if (variables::knife_model == 3)
				pData->value.m_int = iGut;
			else if (variables::knife_model == 4)
				pData->value.m_int = iKarambit;
			else if (variables::knife_model == 5)
				pData->value.m_int = iM9Bayonet;
			else if (variables::knife_model == 6)
				pData->value.m_int = iHuntsman;
			else if (variables::knife_model == 7)
				pData->value.m_int = iFalchion;
			else if (variables::knife_model == 8)
				pData->value.m_int = iBowie;
			else if (variables::knife_model == 9)
				pData->value.m_int = iButterfly;
			else if (variables::knife_model == 10)
				pData->value.m_int = iDagger;
			else if (variables::knife_model == 11)
				pData->value.m_int = iUrsus;
			else if (variables::knife_model == 12)
				pData->value.m_int = iNavaja;
			else if (variables::knife_model == 13)
				pData->value.m_int = iStiletto;
			else if (variables::knife_model == 14)
				pData->value.m_int = iTalon;
			else if (variables::knife_model == 15)
				pData->value.m_int = iNomad;
			else if (variables::knife_model == 16)
				pData->value.m_int = iSkeleton;
			else if (variables::knife_model == 17)
				pData->value.m_int = iSurvival;
			else if (variables::knife_model == 18)
				pData->value.m_int = iParacord;
			else if (variables::knife_model == 19)
				pData->value.m_int = iClassic;


		}
	}


	oRecvnModelIndex(pData, pStruct, pOut);
}


void SetViewModelSequence2(const c_recv_proxy_data* pDataConst, void* pStruct, void* pOut)
{
	c_recv_proxy_data* pData = const_cast<c_recv_proxy_data*>(pDataConst);

	// Confirm that we are replacing our view model and not someone elses.
	base_view_model_t* pViewModel = (base_view_model_t*)pStruct;

	if (pViewModel) {
		auto pOwner = reinterpret_cast<player_t*>(interfaces::entity_list->get_client_entity_handle(pViewModel->owner()));

		// Compare the owner entity of this view model to the local player entity.
		if (pOwner && pOwner->index() == interfaces::engine->get_local_player()) {
			// Get the filename of the current view model.
			const model_t* pModel = interfaces::model_info->get_model(pViewModel->model_index());
			const char* szModel = interfaces::model_info->get_model_name(pModel);

			// Store the current sequence.
			int m_nSequence = pData->value.m_int;

			if (!strcmp(szModel, "models/weapons/v_knife_butterfly.mdl")) {
				// Fix animations for the Butterfly Knife.
				switch (m_nSequence) {
				case SEQUENCE_DEFAULT_DRAW:
					m_nSequence = RandomInt(SEQUENCE_BUTTERFLY_DRAW, SEQUENCE_BUTTERFLY_DRAW2); break;
				case SEQUENCE_DEFAULT_LOOKAT01:
					m_nSequence = RandomInt(SEQUENCE_BUTTERFLY_LOOKAT01, SEQUENCE_BUTTERFLY_LOOKAT03); break;
				default:
					m_nSequence++;
				}
			}
			else if (!strcmp(szModel, "models/weapons/v_knife_falchion_advanced.mdl")) {
				// Fix animations for the Falchion Knife.
				switch (m_nSequence) {
				case SEQUENCE_DEFAULT_IDLE2:
					m_nSequence = SEQUENCE_FALCHION_IDLE1; break;
				case SEQUENCE_DEFAULT_HEAVY_MISS1:
					m_nSequence = RandomInt(SEQUENCE_FALCHION_HEAVY_MISS1, SEQUENCE_FALCHION_HEAVY_MISS1_NOFLIP); break;
				case SEQUENCE_DEFAULT_LOOKAT01:
					m_nSequence = RandomInt(SEQUENCE_FALCHION_LOOKAT01, SEQUENCE_FALCHION_LOOKAT02); break;
				case SEQUENCE_DEFAULT_DRAW:
				case SEQUENCE_DEFAULT_IDLE1:
					break;
				default:
					m_nSequence--;
				}
			}
			else if (!strcmp(szModel, "models/weapons/v_knife_push.mdl")) {
				// Fix animations for the Shadow Daggers.
				switch (m_nSequence) {
				case SEQUENCE_DEFAULT_IDLE2:
					m_nSequence = SEQUENCE_DAGGERS_IDLE1; break;
				case SEQUENCE_DEFAULT_LIGHT_MISS1:
				case SEQUENCE_DEFAULT_LIGHT_MISS2:
					m_nSequence = RandomInt(SEQUENCE_DAGGERS_LIGHT_MISS1, SEQUENCE_DAGGERS_LIGHT_MISS5); break;
				case SEQUENCE_DEFAULT_HEAVY_MISS1:
					m_nSequence = RandomInt(SEQUENCE_DAGGERS_HEAVY_MISS2, SEQUENCE_DAGGERS_HEAVY_MISS1); break;
				case SEQUENCE_DEFAULT_HEAVY_HIT1:
				case SEQUENCE_DEFAULT_HEAVY_BACKSTAB:
				case SEQUENCE_DEFAULT_LOOKAT01:
					m_nSequence += 3; break;
				case SEQUENCE_DEFAULT_DRAW:
				case SEQUENCE_DEFAULT_IDLE1:
					break;
				default:
					m_nSequence += 2;
				}
			}
			else if (!strcmp(szModel, "models/weapons/v_knife_survival_bowie.mdl")) {
				// Fix animations for the Bowie Knife.
				switch (m_nSequence) {
				case SEQUENCE_DEFAULT_DRAW:
				case SEQUENCE_DEFAULT_IDLE1:
					break;
				case SEQUENCE_DEFAULT_IDLE2:
					m_nSequence = SEQUENCE_BOWIE_IDLE1; break;
				default:
					m_nSequence--;
				}
			}
			else if (!strcmp(szModel, "models/weapons/v_knife_ursus.mdl"))
			{
				switch (m_nSequence)
				{
				case SEQUENCE_DEFAULT_DRAW:
					m_nSequence = RandomInt(SEQUENCE_BUTTERFLY_DRAW, SEQUENCE_BUTTERFLY_DRAW2);
					break;
				case SEQUENCE_DEFAULT_LOOKAT01:
					m_nSequence = RandomInt(SEQUENCE_BUTTERFLY_LOOKAT01, 14);
					break;
				default:
					m_nSequence++;
					break;
				}
			}
			else if (!strcmp(szModel, "models/weapons/v_knife_stiletto.mdl"))
			{
				switch (m_nSequence)
				{
				case SEQUENCE_DEFAULT_LOOKAT01:
					m_nSequence = RandomInt(12, 13);
					break;
				}
			}
			else if (!strcmp(szModel, "models/weapons/v_knife_widowmaker.mdl"))
			{
				switch (m_nSequence)
				{
				case SEQUENCE_DEFAULT_LOOKAT01:
					m_nSequence = RandomInt(14, 15);
					break;
				}
			}
			else if (!strcmp(szModel, "models/weapons/v_knife_css.mdl"))
			{
				switch (m_nSequence)
				{
				case SEQUENCE_DEFAULT_LOOKAT01:
					m_nSequence = 15;
					break;
				}
			}
			else if (!strcmp(szModel, "models/weapons/v_knife_cord.mdl") ||
				!strcmp(szModel, "models/weapons/v_knife_canis.mdl") ||
				!strcmp(szModel, "models/weapons/v_knife_outdoor.mdl") ||
				!strcmp(szModel, "models/weapons/v_knife_skeleton.mdl"))
			{
				switch (m_nSequence)
				{
				case SEQUENCE_DEFAULT_DRAW:
					m_nSequence = RandomInt(SEQUENCE_BUTTERFLY_DRAW, SEQUENCE_BUTTERFLY_DRAW2);
					break;
				case SEQUENCE_DEFAULT_LOOKAT01:
					m_nSequence = RandomInt(SEQUENCE_BUTTERFLY_LOOKAT01, 14);
					break;
				default:
					m_nSequence++;
				}
			}
			// Set the fixed sequence.
			pData->value.m_int = m_nSequence;
		}
	}

	// Call original function with the modified data.
	fnSequenceProxyFn(pData, pStruct, pOut);
}

void skins::skinchanger::animfix_hook()
{
	for (c_client_class* pClass = interfaces::client->get_client_classes(); pClass; pClass = pClass->next_ptr) {
		if (!strcmp(pClass->network_name, "CBaseViewModel")) {
			// Search for the 'm_nModelIndex' property.
			recv_table* pClassTable = pClass->recvtable_ptr;

			for (int nIndex = 0; nIndex < pClassTable->props_count; nIndex++) {
				recv_prop* pProp = &pClassTable->props[nIndex];

				if (!pProp || strcmp(pProp->prop_name, "m_nSequence"))
					continue;

				// Store the original proxy function.
				fnSequenceProxyFn = static_cast<RecvVarProxyFn>(pProp->proxy_fn);

				// Replace the proxy function with our sequence changer.
				pProp->proxy_fn = static_cast<RecvVarProxyFn>(SetViewModelSequence2);

				break;
			}
			break;
		}
	}
}

void skins::skinchanger::animfix_unhook()
{
	for (c_client_class* pClass = interfaces::client->get_client_classes(); pClass; pClass = pClass->next_ptr) {
		if (!strcmp(pClass->network_name, "CBaseViewModel")) {
			// Search for the 'm_nModelIndex' property.
			recv_table* pClassTable = pClass->recvtable_ptr;

			for (int nIndex = 0; nIndex < pClassTable->props_count; nIndex++) {
				recv_prop* pProp = &pClassTable->props[nIndex];

				if (!pProp || strcmp(pProp->prop_name, "m_nSequence"))
					continue;

				// Replace the proxy function with our sequence changer.
				pProp->proxy_fn = fnSequenceProxyFn;

				break;
			}
			break;
		}
	}
}
// skin list displayed in tab - Changer
void skins::skinchanger::skin_list() {
	render::draw_filled_rect(variables::menu::x + 180, variables::menu::y + 180, 149, 14, color(100, 0, 0, 160));
	render::draw_filled_rect(variables::menu::x + 180, variables::menu::y + 198, 149, 14, color(100, 0, 0, 160));

	if (variables::knife_model == 0 || variables::knife_model == 1 || variables::knife_model == 2 || variables::knife_model == 3 || variables::knife_model == 4) {
		const char* knife[] = { "Deafult", "Bayonet", "Flip", "Gut Knife", "Karambit", "M9 Bayonet", "Huntsman Knife", "Falchion Knife", "Bowie Knife", "Butterfly Knife", "Shadow Daggers", "Ursus Knife", "Navaja Knife", "Stiletto Knife", "Talon Knife", "Nomad Knife", "Skeleton Knife", "Survival Knife", "Paracord Knife", "Classic Knife" };
		const char* knife_skin[] = { "Vanilla", "Lore", "Gamma Doppler", "Autotronic", "Black Laminate", "Freehand", "Bright Water", "Marble Fade", "Tiger Tooth", "Doppler", "Ultraviolet", "Damascus Steel", "Rust Coat", "Fade", "Slaughter", "Case Hardened", "Crimson Web", "Blue Steel", "Night", "Safari Mesh", "Forest DDPAT", "Stained", "Scorched", "Boreal Forest", "Urban Masked" };
		std::string text = tfm::format("%s - %i", knife[variables::knife_model], knife_skin[variables::knife_skin]);
		render::text(variables::menu::x + 182, variables::menu::y + 180, render::fonts::gui_font, text, false, color::white());
	}

	if (variables::knife_model == 6 || variables::knife_model == 7 || variables::knife_model == 8 || variables::knife_model == 9 || variables::knife_model == 10 || variables::knife_model == 11 || variables::knife_model == 12 || variables::knife_model == 13 || variables::knife_model == 14 || variables::knife_model == 15 || variables::knife_model == 16 || variables::knife_model == 17 || variables::knife_model == 18 || variables::knife_model == 19) {
		const char* knife[] = { "Deafult", "Bayonet", "Flip", "Gut Knife", "Karambit", "M9 Bayonet", "Huntsman Knife", "Falchion Knife", "Bowie Knife", "Butterfly Knife", "Shadow Daggers", "Ursus Knife", "Navaja Knife", "Stiletto Knife", "Talon Knife", "Nomad Knife", "Skeleton Knife", "Survival Knife", "Paracord Knife", "Classic Knife" };
		const char* knife_skin[] = { "Vanilla", "Marble Fade", "Tiger Tooth", "Doppler", "Ultraviolet", "Damascus Steel", "Rust Coat", "Fade", "Slaughter", "Case Hardened", "Crimson Web", "Blue Steel", "Night", "Safari Mesh", "Forest DDPAT", "Stained", "Scorched", "Boreal Forest", "Urban Masked" };
		std::string text = tfm::format("%s - %i", knife[variables::knife_model], knife_skin[variables::knife_skin]);
		render::text(variables::menu::x + 182, variables::menu::y + 181, render::fonts::gui_font, text, false, color::white());
	}

	
	switch (variables::glove_model) {
	case 0:	
		render::text(variables::menu::x + 182, variables::menu::y + 198, render::fonts::gui_font, "Default gloves - Vanilla", false, color::white()); 
		break;
		{
	case 1:
		const char* glove_skin[] = { "Snakebite", "Guerrilla", "Charred", "Bronzed" };
		std::string text = tfm::format("Bloodhound gloves - %i", glove_skin[variables::bloodhound_skin]);
		render::text(variables::menu::x + 182, variables::menu::y + 198, render::fonts::gui_font, text, false, color::white());
		break;
		}
		{
	case 2:
		const char* glove_skin[] = { "Vice", "Amphibious", "Omega", "Bronze Morph", "Pandora's Box", "Superconductor", "Hedge Maze", "Arid" };
		std::string text = tfm::format("Sport gloves - %i", glove_skin[variables::sport_skin]);
		render::text(variables::menu::x + 182, variables::menu::y + 198, render::fonts::gui_font, text, false, color::white());
		break;
		}
		{
	case 3:
		const char* glove_skin[] = { "King Snake", "Imperial Plaid", "Overtake", "Racing Green", "Crimson Weave", "Diamondback", "Lunar Weave", "Convoy", "Black Tie" };
		std::string text = tfm::format("Driver gloves - %i", glove_skin[variables::driver_skin]);
		render::text(variables::menu::x + 182, variables::menu::y + 198, render::fonts::gui_font, text, false, color::white());
		break;
		}
		{
	case 4:
		const char* glove_skin[] = { "Cobalt Skulls", "Overprint", "Arboreal", "Duct Tape", "Slaughter", "Badlands", "Leather", "Spruce DDPAT" };
		std::string text = tfm::format("Handwrap gloves - %i", glove_skin[variables::handwrap_skin]);
		render::text(variables::menu::x + 182, variables::menu::y + 198, render::fonts::gui_font, text, false, color::white());
		break;
		}
		{
	case 5:
		const char* glove_skin[] = { "POW!", "Turtle", "Polygon", "Transport", "Spearmint", "Boom!", "Cool Mint", "Eclipse" };
		std::string text = tfm::format("Moto gloves - %i", glove_skin[variables::moto_skin]);
		render::text(variables::menu::x + 182, variables::menu::y + 198, render::fonts::gui_font, text, false, color::white());
		break;
		}
		{
	case 6:
		const char* glove_skin[] = { "Fade", "Crimson Web", "Mogul", "Buckshot", "Crimson Kimono", "Emerald Web", "Foundation", "Forest DDPAT" };
		std::string text = tfm::format("Specialist gloves - %i", glove_skin[variables::specialist_skin]);
		render::text(variables::menu::x + 182, variables::menu::y + 198, render::fonts::gui_font, text, false, color::white());
		break;
		}
		{
	case 7:
		const char* glove_skin[] = { "Emerald", "Mangrove", "Case Hardened", "Rattler" };
		std::string text = tfm::format("Hydra gloves - %i", glove_skin[variables::hydra_skin]);
		render::text(variables::menu::x + 182, variables::menu::y + 198, render::fonts::gui_font, text, false, color::white());
		break;
		}
	}
}
void skins::skinchanger::list() { 

}

// im going to die doing this // almost died editing this shit - 2023 09 29 note before release
void skins::weaponchanger::list() {
	switch (variables::weapon_skin) {
	case 0:
		pendelum::input_box("Usp ID input", variables::paint_kit_index_usp, variables::menu::x + 180, variables::menu::y + 65);
		pendelum::checkbox("Usp stattrak", variables::usp_stattrak, variables::menu::x + 180, variables::menu::y + 85);
		pendelum::input_box("Usp stattrak", variables::index_usp_stattrak, variables::menu::x + 180, variables::menu::y + 99);
		pendelum::slider("Usp wear", 125, variables::menu::x + 180, variables::menu::y + 135, variables::usp_wear, 0.f, 1.f);
		break;
	case 1:
		pendelum::input_box("P2000 ID input", variables::paint_kit_index_p2000, variables::menu::x + 180, variables::menu::y + 65);
		pendelum::checkbox("P2000 stattrak", variables::p2000_stattrak, variables::menu::x + 180, variables::menu::y + 85);
		pendelum::input_box("P2000 stattrak", variables::index_p2000_stattrak, variables::menu::x + 180, variables::menu::y + 99);
		pendelum::slider("P2000 wear", 125, variables::menu::x + 180, variables::menu::y + 135, variables::p2000_wear, 0.f, 1.f);
		break;
	case 2:
		pendelum::input_box("Glock-18 ID input", variables::paint_kit_index_glock, variables::menu::x + 180, variables::menu::y + 65);
		pendelum::checkbox("Glock-18 stattrak", variables::glock_stattrak, variables::menu::x + 180, variables::menu::y + 85);
		pendelum::input_box("Glock-18 stattrak", variables::index_glock_stattrak, variables::menu::x + 180, variables::menu::y + 99);
		pendelum::slider("Glock-18 wear", 125, variables::menu::x + 180, variables::menu::y + 135, variables::glock_wear, 0.f, 1.f);;
		break;
	case 3:
		pendelum::input_box("P250 ID input", variables::paint_kit_index_p250, variables::menu::x + 180, variables::menu::y + 65);
		pendelum::checkbox("P250 stattrak", variables::p250_stattrak, variables::menu::x + 180, variables::menu::y + 85);
		pendelum::input_box("P250 stattrak", variables::index_p250_stattrak, variables::menu::x + 180, variables::menu::y + 99);
		pendelum::slider("P250 wear", 125, variables::menu::x + 180, variables::menu::y + 135, variables::p250_wear, 0.f, 1.f);
		break;
	case 4:
		pendelum::input_box("Five-seven ID input", variables::paint_kit_index_fiveseven, variables::menu::x + 180, variables::menu::y + 65);
		pendelum::checkbox("Five-seven stattrak", variables::fiveseven_stattrak, variables::menu::x + 180, variables::menu::y + 85);
		pendelum::input_box("Five-seven stattrak", variables::index_fiveseven_stattrak, variables::menu::x + 180, variables::menu::y + 99);
		pendelum::slider("Five-seven wear", 125, variables::menu::x + 180, variables::menu::y + 135, variables::fiveseven_wear, 0.f, 1.f);
		break;
	case 5:
		pendelum::input_box("Tec-9 ID input", variables::paint_kit_index_tec, variables::menu::x + 180, variables::menu::y + 65);
		pendelum::checkbox("Tec-9 stattrak", variables::tec_stattrak, variables::menu::x + 180, variables::menu::y + 85);
		pendelum::input_box("Tec-9 stattrak", variables::index_tec_stattrak, variables::menu::x + 180, variables::menu::y + 99);
		pendelum::slider("Tec-9 wear", 125, variables::menu::x + 180, variables::menu::y + 135, variables::tec_wear, 0.f, 1.f);
		break;
	case 6:
		pendelum::input_box("Cz-75 ID input", variables::paint_kit_index_cz, variables::menu::x + 180, variables::menu::y + 65);
		pendelum::checkbox("Cz-75 stattrak", variables::cz_stattrak, variables::menu::x + 180, variables::menu::y + 85);
		pendelum::input_box("Cz-75 stattrak", variables::index_cz_stattrak, variables::menu::x + 180, variables::menu::y + 99);
		pendelum::slider("Cz-75 wear", 125, variables::menu::x + 180, variables::menu::y + 135, variables::cz_wear, 0.f, 1.f);
		break;
	case 7:
		pendelum::input_box("Duals ID input", variables::paint_kit_index_duals, variables::menu::x + 180, variables::menu::y + 65);
		pendelum::checkbox("Duals stattrak", variables::duals_stattrak, variables::menu::x + 180, variables::menu::y + 85);
		pendelum::input_box("Duals stattrak", variables::index_duals_stattrak, variables::menu::x + 180, variables::menu::y + 99);
		pendelum::slider("Duals wear", 125, variables::menu::x + 180, variables::menu::y + 135, variables::duals_wear, 0.f, 1.f);
		break;
	case 8:
		pendelum::input_box("Deagle ID input", variables::paint_kit_index_deagle, variables::menu::x + 180, variables::menu::y + 65);
		pendelum::checkbox("Deagle stattrak", variables::deagle_stattrak, variables::menu::x + 180, variables::menu::y + 85);
		pendelum::input_box("Deagle stattrak", variables::index_deagle_stattrak, variables::menu::x + 180, variables::menu::y + 99);
		pendelum::slider("Deagle wear", 125, variables::menu::x + 180, variables::menu::y + 135, variables::deagle_wear, 0.f, 1.f);
		break;
	case 9:
		pendelum::input_box("Revolver ID input", variables::paint_kit_index_revolver, variables::menu::x + 180, variables::menu::y + 65);
		pendelum::checkbox("Revolver stattrak", variables::revolver_stattrak, variables::menu::x + 180, variables::menu::y + 85);
		pendelum::input_box("Revolver stattrak", variables::index_revolver_stattrak, variables::menu::x + 180, variables::menu::y + 99);
		pendelum::slider("Revolver wear", 125, variables::menu::x + 180, variables::menu::y + 135, variables::revolver_wear, 0.f, 1.f);
		break;
	case 10:
		pendelum::input_box("Famas ID input", variables::paint_kit_index_famas, variables::menu::x + 180, variables::menu::y + 65);
		pendelum::checkbox("Famas stattrak", variables::famas_stattrak, variables::menu::x + 180, variables::menu::y + 85);
		pendelum::input_box("Famas stattrak", variables::index_famas_stattrak, variables::menu::x + 180, variables::menu::y + 99);
		pendelum::slider("Famas wear", 125, variables::menu::x + 180, variables::menu::y + 135, variables::famas_wear, 0.f, 1.f);
		break;
	case 11:
		pendelum::input_box("Galil-AR ID input", variables::paint_kit_index_galil, variables::menu::x + 180, variables::menu::y + 65);
		pendelum::checkbox("Galil-AR stattrak", variables::galil_stattrak, variables::menu::x + 180, variables::menu::y + 85);
		pendelum::input_box("Galil-AR stattrak", variables::index_galil_stattrak, variables::menu::x + 180, variables::menu::y + 99);
		pendelum::slider("Galil-AR wear", 125, variables::menu::x + 180, variables::menu::y + 135, variables::galil_wear, 0.f, 1.f);
		break;
	case 12:
		pendelum::input_box("M4A4 ID input", variables::paint_kit_index_m4a4, variables::menu::x + 180, variables::menu::y + 65);
		pendelum::checkbox("M4A4 stattrak", variables::m4a4_stattrak, variables::menu::x + 180, variables::menu::y + 85);
		pendelum::input_box("M4A4 stattrak", variables::index_m4a4_stattrak, variables::menu::x + 180, variables::menu::y + 99);
		pendelum::slider("M4A4 wear", 125, variables::menu::x + 180, variables::menu::y + 135, variables::m4a4_wear, 0.f, 1.f);
		break;
	case 13:
		pendelum::input_box("M4A1-s ID input", variables::paint_kit_index_m4a1, variables::menu::x + 180, variables::menu::y + 65);
		pendelum::checkbox("M4A1-s stattrak", variables::m4a1_stattrak, variables::menu::x + 180, variables::menu::y + 85);
		pendelum::input_box("M4A1-s stattrak", variables::index_m4a1_stattrak, variables::menu::x + 180, variables::menu::y + 99);
		pendelum::slider("M4A1-s wear", 125, variables::menu::x + 180, variables::menu::y + 135, variables::m4a1_wear, 0.f, 1.f);
		break;
	case 14:
		pendelum::input_box("Ak-47 ID input", variables::paint_kit_index_ak47, variables::menu::x + 180, variables::menu::y + 65);
		pendelum::checkbox("Ak-47 stattrak", variables::ak47_stattrak, variables::menu::x + 180, variables::menu::y + 85);
		pendelum::input_box("Ak-47 stattrak", variables::index_ak47_stattrak, variables::menu::x + 180, variables::menu::y + 99);
		pendelum::slider("Ak-47 wear", 125, variables::menu::x + 180, variables::menu::y + 135, variables::ak47_wear, 0.f, 1.f);
		break;
	case 15:
		pendelum::input_box("Sg 553 ID input", variables::paint_kit_index_sg553, variables::menu::x + 180, variables::menu::y + 65);
		pendelum::checkbox("Sg 553 stattrak", variables::sg553_stattrak, variables::menu::x + 180, variables::menu::y + 85);
		pendelum::input_box("Sg 553 stattrak", variables::index_sg553_stattrak, variables::menu::x + 180, variables::menu::y + 99);
		pendelum::slider("Sg 553 wear", 125, variables::menu::x + 180, variables::menu::y + 135, variables::sg553_wear, 0.f, 1.f);
		break;
	case 16:
		pendelum::input_box("Aug ID input", variables::paint_kit_index_aug, variables::menu::x + 180, variables::menu::y + 65);
		pendelum::checkbox("Aug stattrak", variables::aug_stattrak, variables::menu::x + 180, variables::menu::y + 85);
		pendelum::input_box("Aug stattrak", variables::index_aug_stattrak, variables::menu::x + 180, variables::menu::y + 99);
		pendelum::slider("Aug wear", 125, variables::menu::x + 180, variables::menu::y + 135, variables::aug_wear, 0.f, 1.f);
		break;
	case 17:
		pendelum::input_box("Ssg 08 ID input", variables::paint_kit_index_ssg08, variables::menu::x + 180, variables::menu::y + 65);
		pendelum::checkbox("Ssg 08 stattrak", variables::ssg08_stattrak, variables::menu::x + 180, variables::menu::y + 85);
		pendelum::input_box("Ssg 08 stattrak", variables::index_ssg08_stattrak, variables::menu::x + 180, variables::menu::y + 99);
		pendelum::slider("Ssg 08 wear", 125, variables::menu::x + 180, variables::menu::y + 135, variables::ssg08_wear, 0.f, 1.f);
		break;
	case 18:
		pendelum::input_box("AWP ID input", variables::paint_kit_index_awp, variables::menu::x + 180, variables::menu::y + 65);
		pendelum::checkbox("AWP stattrak", variables::awp_stattrak, variables::menu::x + 180, variables::menu::y + 85);
		pendelum::input_box("AWP stattrak", variables::index_awp_stattrak, variables::menu::x + 180, variables::menu::y + 99);
		pendelum::slider("AWP wear", 125, variables::menu::x + 180, variables::menu::y + 135, variables::awp_wear, 0.f, 1.f);
		break;
	case 19:
		pendelum::input_box("Scar-20 ID input", variables::paint_kit_index_scar, variables::menu::x + 180, variables::menu::y + 65);
		pendelum::checkbox("Scar-20 stattrak", variables::scar_stattrak, variables::menu::x + 180, variables::menu::y + 85);
		pendelum::input_box("Scar-20 stattrak", variables::index_scar_stattrak, variables::menu::x + 180, variables::menu::y + 99);
		pendelum::slider("Scar-20 wear", 125, variables::menu::x + 180, variables::menu::y + 135, variables::scar_wear, 0.f, 1.f);
		break;
	case 20:
		pendelum::input_box("G3SG1 ID input", variables::paint_kit_index_g3sg1, variables::menu::x + 180, variables::menu::y + 65);
		pendelum::checkbox("G3SG1 stattrak", variables::g3sg1_stattrak, variables::menu::x + 180, variables::menu::y + 85);
		pendelum::input_box("G3SG1 stattrak", variables::index_g3sg1_stattrak, variables::menu::x + 180, variables::menu::y + 99);
		pendelum::slider("G3SG1 wear", 125, variables::menu::x + 180, variables::menu::y + 135, variables::g3sg1_wear, 0.f, 1.f);
		break;
	case 21:
		pendelum::input_box("Sawed-off ID input", variables::paint_kit_index_sawoff, variables::menu::x + 180, variables::menu::y + 65);
		pendelum::checkbox("Sawed-off stattrak", variables::sawoff_stattrak, variables::menu::x + 180, variables::menu::y + 85);
		pendelum::input_box("Sawed-off stattrak", variables::index_sawoff_stattrak, variables::menu::x + 180, variables::menu::y + 99);
		pendelum::slider("Sawed-off wear", 125, variables::menu::x + 180, variables::menu::y + 135, variables::sawoff_wear, 0.f, 1.f);
		break;
	case 22:
		pendelum::input_box("M249 ID input", variables::paint_kit_index_m249, variables::menu::x + 180, variables::menu::y + 65);
		pendelum::checkbox("M249 stattrak", variables::m249_stattrak, variables::menu::x + 180, variables::menu::y + 85);
		pendelum::input_box("M249 stattrak", variables::index_m249_stattrak, variables::menu::x + 180, variables::menu::y + 99);
		pendelum::slider("M249 wear", 125, variables::menu::x + 180, variables::menu::y + 135, variables::m249_wear, 0.f, 1.f);
		break;
	case 23:
		pendelum::input_box("Negev ID input", variables::paint_kit_index_negev, variables::menu::x + 180, variables::menu::y + 65);
		pendelum::checkbox("Negev stattrak", variables::negev_stattrak, variables::menu::x + 180, variables::menu::y + 85);
		pendelum::input_box("Negev stattrak", variables::index_negev_stattrak, variables::menu::x + 180, variables::menu::y + 99);
		pendelum::slider("Negev wear", 125, variables::menu::x + 180, variables::menu::y + 135, variables::negev_wear, 0.f, 1.f);
		break;
	case 24:
		pendelum::input_box("Mag7 ID input", variables::paint_kit_index_mag7, variables::menu::x + 180, variables::menu::y + 65);
		pendelum::checkbox("Mag7 stattrak", variables::mag7_stattrak, variables::menu::x + 180, variables::menu::y + 85);
		pendelum::input_box("Mag7 stattrak", variables::index_mag7_stattrak, variables::menu::x + 180, variables::menu::y + 99);
		pendelum::slider("Mag7 wear", 125, variables::menu::x + 180, variables::menu::y + 135, variables::mag7_wear, 0.f, 1.f);
		break;
	case 25:
		pendelum::input_box("XM1014 08 ID input", variables::paint_kit_index_xm1014, variables::menu::x + 180, variables::menu::y + 65);
		pendelum::checkbox("XM1014 stattrak", variables::xm1014_stattrak, variables::menu::x + 180, variables::menu::y + 85);
		pendelum::input_box("XM1014 stattrak", variables::index_xm1014_stattrak, variables::menu::x + 180, variables::menu::y + 99);
		pendelum::slider("XM1014 wear", 125, variables::menu::x + 180, variables::menu::y + 135, variables::xm1014_wear, 0.f, 1.f);
		break;
	case 26:
		pendelum::input_box("Nova ID input", variables::paint_kit_index_nova, variables::menu::x + 180, variables::menu::y + 65);
		pendelum::checkbox("Nova stattrak", variables::nova_stattrak, variables::menu::x + 180, variables::menu::y + 85);
		pendelum::input_box("Nova stattrak", variables::index_nova_stattrak, variables::menu::x + 180, variables::menu::y + 99);
		pendelum::slider("Nova wear", 125, variables::menu::x + 180, variables::menu::y + 135, variables::nova_wear, 0.f, 1.f);
		break;
	case 27:
		pendelum::input_box("Bizon ID input", variables::paint_kit_index_bizon, variables::menu::x + 180, variables::menu::y + 65);
		pendelum::checkbox("Bizon stattrak", variables::bizon_stattrak, variables::menu::x + 180, variables::menu::y + 85);
		pendelum::input_box("Bizon stattrak", variables::index_bizon_stattrak, variables::menu::x + 180, variables::menu::y + 99);
		pendelum::slider("Bizon wear", 125, variables::menu::x + 180, variables::menu::y + 135, variables::bizon_wear, 0.f, 1.f);
		break;
	case 28:
		pendelum::input_box("MP5SD ID input", variables::paint_kit_index_mp5sd, variables::menu::x + 180, variables::menu::y + 65);
		pendelum::checkbox("MP5SD stattrak", variables::mp5sd_stattrak, variables::menu::x + 180, variables::menu::y + 85);
		pendelum::input_box("MP5SD stattrak", variables::index_mp5sd_stattrak, variables::menu::x + 180, variables::menu::y + 99);
		pendelum::slider("MP5SD wear", 125, variables::menu::x + 180, variables::menu::y + 135, variables::mp5sd_wear, 0.f, 1.f);
		break;
	case 29:
		pendelum::input_box("Mp7 ID input", variables::paint_kit_index_mp7, variables::menu::x + 180, variables::menu::y + 65);
		pendelum::checkbox("Mp7 stattrak", variables::mp7_stattrak, variables::menu::x + 180, variables::menu::y + 85);
		pendelum::input_box("Mp7 stattrak", variables::index_mp7_stattrak, variables::menu::x + 180, variables::menu::y + 99);
		pendelum::slider("Mp7 wear", 125, variables::menu::x + 180, variables::menu::y + 135, variables::mp7_wear, 0.f, 1.f);
		break;
	case 30:
		pendelum::input_box("Mp9 ID input", variables::paint_kit_index_mp9, variables::menu::x + 180, variables::menu::y + 65);
		pendelum::checkbox("Mp9 stattrak", variables::mp9_stattrak, variables::menu::x + 180, variables::menu::y + 85);
		pendelum::input_box("Mp9 stattrak", variables::index_mp9_stattrak, variables::menu::x + 180, variables::menu::y + 99);
		pendelum::slider("Mp9 wear", 125, variables::menu::x + 180, variables::menu::y + 135, variables::mp9_wear, 0.f, 1.f);
		break;
	case 31:
		pendelum::input_box("Mp9 ID input", variables::paint_kit_index_mp9, variables::menu::x + 180, variables::menu::y + 65);
		pendelum::checkbox("Mp9 stattrak", variables::mp9_stattrak, variables::menu::x + 180, variables::menu::y + 85);
		pendelum::input_box("Mp9 stattrak", variables::index_mp9_stattrak, variables::menu::x + 180, variables::menu::y + 99);
		pendelum::slider("Mp9 wear", 125, variables::menu::x + 180, variables::menu::y + 135, variables::mp9_wear, 0.f, 1.f);
		break;
	case 32:
		pendelum::input_box("Mac10 ID input", variables::paint_kit_index_mac10, variables::menu::x + 180, variables::menu::y + 65);
		pendelum::checkbox("Mac10 stattrak", variables::mac10_stattrak, variables::menu::x + 180, variables::menu::y + 85);
		pendelum::input_box("Mac10 stattrak", variables::index_mac10_stattrak, variables::menu::x + 180, variables::menu::y + 99);
		pendelum::slider("Mac10 wear", 125, variables::menu::x + 180, variables::menu::y + 135, variables::mac10_wear, 0.f, 1.f);
		break;
	case 33:
		pendelum::input_box("P90 ID input", variables::paint_kit_index_p90, variables::menu::x + 180, variables::menu::y + 65);
		pendelum::checkbox("P90 stattrak", variables::p90_stattrak, variables::menu::x + 180, variables::menu::y + 85);
		pendelum::input_box("P90 stattrak", variables::index_p90_stattrak, variables::menu::x + 180, variables::menu::y + 99);
		pendelum::slider("P90 wear", 125, variables::menu::x + 180, variables::menu::y + 135, variables::p90_wear, 0.f, 1.f);
		break;
	case 34:
		pendelum::input_box("Ump45 ID input", variables::paint_kit_index_ump45, variables::menu::x + 180, variables::menu::y + 65);
		pendelum::checkbox("Ump45 stattrak", variables::ump45_stattrak, variables::menu::x + 180, variables::menu::y + 85);
		pendelum::input_box("Ump45 stattrak", variables::index_ump45_stattrak, variables::menu::x + 180, variables::menu::y + 99);
		pendelum::slider("Ump45 wear", 125, variables::menu::x + 180, variables::menu::y + 135, variables::ump45_wear, 0.f, 1.f);
		break;
	}

	switch (variables::knife_model) {
	case 0:
		pendelum::checkbox("Default stattrak", variables::bayonet_stattrak, variables::menu::x + 20, variables::menu::y + 85);
		pendelum::input_box("Default stattrak", variables::index_bayonet_stattrak, variables::menu::x + 20, variables::menu::y + 99);
		pendelum::slider("Default wear", 125, variables::menu::x + 20, variables::menu::y + 135, variables::bayonet_wear, 0.f, 1.f);
		break;
	case 1:
		pendelum::checkbox("Bayonet stattrak", variables::bayonet_stattrak, variables::menu::x + 20, variables::menu::y + 85);
		pendelum::input_box("Bayonet stattrak", variables::index_bayonet_stattrak, variables::menu::x + 20, variables::menu::y + 99);
		pendelum::slider("Bayonet wear", 125, variables::menu::x + 20, variables::menu::y + 135, variables::bayonet_wear, 0.f, 1.f);
		break;
	case 2:
		pendelum::checkbox("Flip stattrak", variables::flip_stattrak, variables::menu::x + 20, variables::menu::y + 85);
		pendelum::input_box("Flip stattrak", variables::index_flip_stattrak, variables::menu::x + 20, variables::menu::y + 99);
		pendelum::slider("Flip wear", 125, variables::menu::x + 20, variables::menu::y + 135, variables::flip_wear, 0.f, 1.f);
		break;
	case 3:
		pendelum::checkbox("Gut stattrak", variables::gut_stattrak, variables::menu::x + 20, variables::menu::y + 85);
		pendelum::input_box("Gut stattrak", variables::index_gut_stattrak, variables::menu::x + 20, variables::menu::y + 99);
		pendelum::slider("Gut wear", 125, variables::menu::x + 20, variables::menu::y + 135, variables::gut_wear, 0.f, 1.f);
		break;
	case 4:
		pendelum::checkbox("Karambit stattrak", variables::karambit_stattrak, variables::menu::x + 20, variables::menu::y + 85);
		pendelum::input_box("Karambit stattrak", variables::index_karambit_stattrak, variables::menu::x + 20, variables::menu::y + 99);
		pendelum::slider("Karambit wear", 125, variables::menu::x + 20, variables::menu::y + 135, variables::karambit_wear, 0.f, 1.f);
		break;
	case 5:
		pendelum::checkbox("M9 bayonet stattrak", variables::m9bayo_stattrak, variables::menu::x + 20, variables::menu::y + 85);
		pendelum::input_box("M9 bayonet stattrak", variables::index_m9bayo_stattrak, variables::menu::x + 20, variables::menu::y + 99);
		pendelum::slider("M9 bayonet wear", 125, variables::menu::x + 20, variables::menu::y + 135, variables::m9bayo_wear, 0.f, 1.f);
		break;
	case 6:
		pendelum::checkbox("Huntsman stattrak", variables::tactical_stattrak, variables::menu::x + 20, variables::menu::y + 85);
		pendelum::input_box("Huntsman stattrak", variables::index_tactical_stattrak, variables::menu::x + 20, variables::menu::y + 99);
		pendelum::slider("Huntsman wear", 125, variables::menu::x + 20, variables::menu::y + 135, variables::tactical_wear, 0.f, 1.f);
		break;
	case 7:
		pendelum::checkbox("Falchion stattrak", variables::falchion_stattrak, variables::menu::x + 20, variables::menu::y + 85);
		pendelum::input_box("Falchion stattrak", variables::index_falchion_stattrak, variables::menu::x + 20, variables::menu::y + 99);
		pendelum::slider("Falchion wear", 125, variables::menu::x + 20, variables::menu::y + 135, variables::falchion_wear, 0.f, 1.f);
		break;
	case 8:
		pendelum::checkbox("Bowie stattrak", variables::bowie_stattrak, variables::menu::x + 20, variables::menu::y + 85);
		pendelum::input_box("Bowie stattrak", variables::index_bowie_stattrak, variables::menu::x + 20, variables::menu::y + 99);
		pendelum::slider("Bowie wear", 125, variables::menu::x + 20, variables::menu::y + 135, variables::bowie_wear, 0.f, 1.f);
		break;
	case 9:
		pendelum::checkbox("Butterfly stattrak", variables::butterfly_stattrak, variables::menu::x + 20, variables::menu::y + 85);
		pendelum::input_box("Butterfly stattrak", variables::index_butterfly_stattrak, variables::menu::x + 20, variables::menu::y + 99);
		pendelum::slider("Butterfly wear", 125, variables::menu::x + 20, variables::menu::y + 135, variables::butterfly_wear, 0.f, 1.f);
		break;
	case 10:
		pendelum::checkbox("Daggers stattrak", variables::push_stattrak, variables::menu::x + 20, variables::menu::y + 85);
		pendelum::input_box("Daggers stattrak", variables::index_push_stattrak, variables::menu::x + 20, variables::menu::y + 99);
		pendelum::slider("Daggers wear", 125, variables::menu::x + 20, variables::menu::y + 135, variables::push_wear, 0.f, 1.f);
		break;
	case 11:
		pendelum::checkbox("Ursus stattrak", variables::ursus_stattrak, variables::menu::x + 20, variables::menu::y + 85);
		pendelum::input_box("Ursus stattrak", variables::index_ursus_stattrak, variables::menu::x + 20, variables::menu::y + 99);
		pendelum::slider("Ursus wear", 125, variables::menu::x + 20, variables::menu::y + 135, variables::ursus_wear, 0.f, 1.f);
		break;
	case 12:
		pendelum::checkbox("Navaja stattrak", variables::jackknife_stattrak, variables::menu::x + 20, variables::menu::y + 85);
		pendelum::input_box("Navaja stattrak", variables::index_jackknife_stattrak, variables::menu::x + 20, variables::menu::y + 99);
		pendelum::slider("Navaja wear", 125, variables::menu::x + 20, variables::menu::y + 135, variables::jackknife_wear, 0.f, 1.f);
		break;
	case 13:
		pendelum::checkbox("Stiletto stattrak", variables::stiletto_stattrak, variables::menu::x + 20, variables::menu::y + 85);
		pendelum::input_box("Stiletto stattrak", variables::index_stiletto_stattrak, variables::menu::x + 20, variables::menu::y + 99);
		pendelum::slider("Stiletto wear", 125, variables::menu::x + 20, variables::menu::y + 135, variables::stiletto_wear, 0.f, 1.f);
		break;
	case 14:
		pendelum::checkbox("Talon stattrak", variables::widowmaker_stattrak, variables::menu::x + 20, variables::menu::y + 85);
		pendelum::input_box("Talon stattrak", variables::index_widowmaker_stattrak, variables::menu::x + 20, variables::menu::y + 99);
		pendelum::slider("Talon wear", 125, variables::menu::x + 20, variables::menu::y + 135, variables::widowmaker_wear, 0.f, 1.f);
		break;
	case 15:
		pendelum::checkbox("Nomad stattrak", variables::outdoor_stattrak, variables::menu::x + 20, variables::menu::y + 85);
		pendelum::input_box("Nomad stattrak", variables::index_outdoor_stattrak, variables::menu::x + 20, variables::menu::y + 99);
		pendelum::slider("Nomad wear", 125, variables::menu::x + 20, variables::menu::y + 135, variables::outdoor_wear, 0.f, 1.f);
		break;
	case 16:
		pendelum::checkbox("Skeleton stattrak", variables::skeleton_stattrak, variables::menu::x + 20, variables::menu::y + 85);
		pendelum::input_box("Skeleton stattrak", variables::index_skeleton_stattrak, variables::menu::x + 20, variables::menu::y + 99);
		pendelum::slider("Skeleton wear", 125, variables::menu::x + 20, variables::menu::y + 135, variables::skeleton_wear, 0.f, 1.f);
		break;
	case 17:
		pendelum::checkbox("Survival stattrak", variables::canis_stattrak, variables::menu::x + 20, variables::menu::y + 85);
		pendelum::input_box("Survival stattrak", variables::index_canis_stattrak, variables::menu::x + 20, variables::menu::y + 99);
		pendelum::slider("Survival wear", 125, variables::menu::x + 20, variables::menu::y + 135, variables::canis_wear, 0.f, 1.f);
		break;
	case 18:
		pendelum::checkbox("Paracord stattrak", variables::cord_stattrak, variables::menu::x + 20, variables::menu::y + 85);
		pendelum::input_box("Paracord stattrak", variables::index_cord_stattrak, variables::menu::x + 20, variables::menu::y + 99);
		pendelum::slider("Paracord wear", 125, variables::menu::x + 20, variables::menu::y + 135, variables::cord_wear, 0.f, 1.f);
		break;
	case 19:
		pendelum::checkbox("Classic stattrak", variables::css_stattrak, variables::menu::x + 20, variables::menu::y + 85);
		pendelum::input_box("Classic stattrak", variables::index_css_stattrak, variables::menu::x + 20, variables::menu::y + 99);
		pendelum::slider("Classic wear", 125, variables::menu::x + 20, variables::menu::y + 135, variables::css_wear, 0.f, 1.f);
		break;
	}
}

// TODO: for gloves we need, wear only
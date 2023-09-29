#include "../features.hpp"

#define clamp(val, min, max) (((val) > (max)) ? (max) : (((val) < (min)) ? (min) : (val)))

void visuals::esp::player_esp_enable(player_t* entity) {

	if (!variables::enable_player_visuals)
		return;

	if (!entity
		|| !csgo::local_player
		|| !entity->is_alive()
		|| entity == csgo::local_player
		|| entity->team() == csgo::local_player->team())
		return;

	box bbox;
	if (!visuals::esp::get_playerbox(entity, bbox))
		return;

	if (variables::visible_check && csgo::local_player->can_see_player_pos(entity, entity->get_hitbox_position(hitbox_chest))) {
		visuals::esp::draw_box(entity, bbox);
		visuals::esp::draw_hp(entity, bbox);
		visuals::esp::draw_info(entity, bbox);
	}
	else if (!variables::visible_check) {
		visuals::esp::draw_box(entity, bbox);
		visuals::esp::draw_hp(entity, bbox);
		visuals::esp::draw_info(entity, bbox);
	}
}

void visuals::esp::player_loop() {
	for (int i = 1; i <= interfaces::globals->max_clients; ++i) {

		player_t* entity = reinterpret_cast<player_t*>(interfaces::entity_list->get_client_entity(i));

		player_esp_enable(entity);
	}
}

bool visuals::esp::get_playerbox(player_t* ent, box& in) {

	vec3_t origin, min, max, flb, brt, blb, frt, frb, brb, blt, flt;
	int left, top, right, bottom;

	origin = ent->abs_origin();
	min = ent->collideable()->mins() + origin;
	max = ent->collideable()->maxs() + origin;

	vec3_t points[] = {
		vec3_t(min.x, min.y, min.z),
		vec3_t(min.x, max.y, min.z),
		vec3_t(max.x, max.y, min.z),
		vec3_t(max.x, min.y, min.z),
		vec3_t(max.x, max.y, max.z),
		vec3_t(min.x, max.y, max.z),
		vec3_t(min.x, min.y, max.z),
		vec3_t(max.x, min.y, max.z)
	};
	if (!interfaces::debug_overlay->world_to_screen(points[3], flb) || !interfaces::debug_overlay->world_to_screen(points[5], brt)
		|| !interfaces::debug_overlay->world_to_screen(points[0], blb) || !interfaces::debug_overlay->world_to_screen(points[4], frt)
		|| !interfaces::debug_overlay->world_to_screen(points[2], frb) || !interfaces::debug_overlay->world_to_screen(points[1], brb)
		|| !interfaces::debug_overlay->world_to_screen(points[6], blt) || !interfaces::debug_overlay->world_to_screen(points[7], flt))
		return false;

	vec3_t arr[] = { flb, brt, blb, frt, frb, brb, blt, flt };

	left = flb.x;
	top = flb.y;
	right = flb.x;
	bottom = flb.y;

	for (int i = 1; i < 8; i++) {
		if (left > arr[i].x)
			left = arr[i].x;
		if (bottom < arr[i].y)
			bottom = arr[i].y;
		if (right < arr[i].x)
			right = arr[i].x;
		if (top > arr[i].y)
			top = arr[i].y;
	}
	in.x = (int)left;
	in.y = (int)top;
	in.w = int(right - left);
	in.h = int(bottom - top);


	return true;
}

void visuals::esp::draw_box(player_t* ent, box bbox) {
	if (!variables::draw_box) 
		return;

	render::draw_rect(bbox.x, bbox.y, bbox.w, bbox.h, color(255, 255, 255, 255)); // For Corner Boxes: render::draw_rect(bbox.x, bbox.y, bbox.w * 0.25, bbox.h * 0.25, color(255, 255, 255, 255));
	render::draw_rect(bbox.x - 1, bbox.y - 1, bbox.w + 2, bbox.h + 2, color(0, 0, 0, 170)); // For Corner Boxes: render::draw_rect(bbox.x - 1, bbox.y - 1, (bbox.w + 2) * 0.25, (bbox.h + 2) * 0.25, color(0, 0, 0, 170)); 
	render::draw_rect(bbox.x + 1, bbox.y + 1, bbox.w - 2, bbox.h - 2, color(0, 0, 0, 170)); // For Corner Boxes: render::draw_rect(bbox.x + 1, bbox.y + 1, (bbox.w - 2) * 0.25, (bbox.h - 2) * 0.25, color(0, 0, 0, 170));
}

void visuals::esp::draw_hp(player_t* entity, box bbox) {
	if (!variables::draw_hp)
		return;

	float alpha[65] = { 255 };

	static float lastDormantTime[65] = { 0 }, lastNonDormantTime[65] = { 0 }; // 64 maxplayers so 1-65 as entindex
	float fadespeed = 2.0; // adding this so you can modify it, fadeout speed in seconds 1.0 = 1s 0.5 = 0.5s etc
	int eid = entity->index(); // calling it once would be a better option
	if (entity->dormant())
	{
		lastDormantTime[eid] = interfaces::globals->realtime;
		alpha[eid] = clamp((lastNonDormantTime[eid] - interfaces::globals->realtime) * (255.f / fadespeed), 0, 255);
	}
	else // you don't need an if here since its either true or false
	{
		lastNonDormantTime[eid] = interfaces::globals->realtime + fadespeed;
		alpha[eid] = clamp((interfaces::globals->realtime - lastDormantTime[eid]) * (255.f / fadespeed), 0, 255);
	}

	int entity_health = entity->health();

	int hp_bar = bbox.h * (entity_health / 100.f);


	color hp_color = color(0, 0, 0, alpha[eid]);

	if (entity_health >= 51)
		hp_color = color(0, 255, 0, alpha[eid]);
	else if (entity_health <= 50 && entity_health > 10)
		hp_color = color(255, 205, 1, alpha[eid]);
	else if (entity_health <= 10)
		hp_color = color(255, 0, 0, alpha[eid]);

	render::draw_filled_rect(bbox.x - 7, bbox.y - 1, 4, bbox.h + 2, color(35, 35, 35, alpha[eid]));
	render::draw_filled_rect(bbox.x - 6, bbox.y + bbox.h - hp_bar, 2, hp_bar, hp_color);

	if (entity_health < 100)
		render::text(bbox.x - 8, bbox.y + bbox.h - hp_bar - 12, render::fonts::watermark_font, std::to_string(entity->health()), false, color(255, 255, 255, alpha[eid]));
}
// make combo box for these flags, but im stupid so i cant make it so all the comboboxes dont open when i open one :.(
void visuals::esp::draw_info(player_t* entity, box bbox) {
	static int offset;
	offset = 0;

	float alpha[65] = { 255 };

	static float lastDormantTime[65] = { 0 }, lastNonDormantTime[65] = { 0 }; // 64 maxplayers so 1-65 as entindex
	float fadespeed = 1.0; // adding this so you can modify it, fadeout speed in seconds 1.0 = 1s 0.5 = 0.5s etc
	int eid = entity->index(); // calling it once would be a better option
	if (entity->dormant())
	{
		lastDormantTime[eid] = interfaces::globals->realtime;
		alpha[eid] = clamp((lastNonDormantTime[eid] - interfaces::globals->realtime) * (255.f / fadespeed), 0, 255);
	}
	else // you don't need an if here since its either true or false
	{
		lastNonDormantTime[eid] = interfaces::globals->realtime + fadespeed;
		alpha[eid] = clamp((interfaces::globals->realtime - lastDormantTime[eid]) * (255.f / fadespeed), 0, 255);
	}


	player_info_t info;
	interfaces::engine->get_player_info(entity->index(), &info);

	if (variables::flags_esp && info.fakeplayer) {
		render::text(bbox.x + bbox.w + 5, bbox.y, render::fonts::watermark_font, "bot", false, color(255, 255, 255, alpha[eid]));
		offset += 11;
	}

	if (variables::flags_esp) {
		if (entity->is_scoped()) {
			render::text(bbox.x + bbox.w + 5, bbox.y + offset, render::fonts::watermark_font, "zoom", false, color(255, 255, 255, alpha[eid]));
			offset += 11;
		}
	}

	if (variables::flags_esp) {
		std::string money = std::to_string(entity->money()) + "$";
		render::text(bbox.x + bbox.w + 5, bbox.y + offset, render::fonts::watermark_font, money, false, color(255, 200, 0, alpha[eid]));
		offset += 11;
	}

	if (variables::flags_esp) { 
		if (entity->armor() > 0 && !entity->has_helmet())
			render::text(bbox.x + bbox.w + 5, bbox.y + offset, render::fonts::watermark_font, "k", false, color(255, 255, 255, alpha[eid]));
		else if (entity->armor() > 0 && entity->has_helmet())
			render::text(bbox.x + bbox.w + 5, bbox.y + offset, render::fonts::watermark_font, "hk", false, color(255, 255, 255, alpha[eid]));
	}

	if (variables::flags_esp && !entity->is_flashed() > 75.0) {
		render::text(bbox.x + (bbox.w / 2), bbox.y - 25, render::fonts::watermark_font, "flashed", true, color(255, 255, 255, alpha[eid]));
	}
}
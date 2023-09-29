#include "pendelum.hpp"

coordinates cursor;
coordinates cursor_corrected;

void pendelum::begin(std::int32_t& x, std::int32_t& y, std::int32_t w, std::int32_t h) {
	interfaces::surface->surface_get_cursor_pos(cursor.x, cursor.y);

	render::draw_filled_rect(x, y, w, h, color(15, 15, 15, 230));
	render::draw_filled_rect(x + 5, y + 5, 340, 340, color(25, 25, 25, 255));

	int w_item = 60;
	int h_item = 203;

	if (menu::tab_count == 0)
		render::draw_filled_rect(variables::menu::x - 65, variables::menu::y, w_item, h_item, color(15, 15, 15, 230));

	if (GetAsyncKeyState(VK_LBUTTON) < 0 && (cursor.x > x && cursor.x < x + w && cursor.y > y && cursor.y < y + h)) {
		should_drag = true;

		if (!should_move) {
			cursor_corrected.x = cursor.x - x;
			cursor_corrected.y = cursor.y - y;
			should_move = true;
		}
	}

	if (should_drag) {
		x = cursor.x - cursor_corrected.x;
		y = cursor.y - cursor_corrected.y;
	}

	if (GetAsyncKeyState(VK_LBUTTON) == 0) {
		should_drag = false;
		should_move = false;
	}
}

void pendelum::groupbox(const std::string string, std::int32_t x, std::int32_t y, std::int32_t w, std::int32_t h) {
	render::draw_rect(x - 100, y - 25, w, h, color(0, 0, 0, 255));
}

void pendelum::child(const std::string string, std::int32_t x, std::int32_t y, std::int32_t w, std::int32_t h) {
	render::draw_rect(x + 6, y + 6, w, h, color(0, 0, 0, 255));
	render::text(x + 11, y + 0, render::fonts::gui_font, string, false, color::white());
}

void pendelum::tab(const std::string string, std::int32_t& tab, std::int32_t count, std::int32_t x, std::int32_t y) {
	interfaces::surface->surface_get_cursor_pos(cursor.x, cursor.y);

	int w = 40, h = 15;

	if ((cursor.x > x + 30) && (cursor.x < x + 30 + w) && (cursor.y > y) && (cursor.y < y + h) && GetAsyncKeyState(VK_LBUTTON)) {
		tab = count;
		should_drag = false;
		should_move = false;
	}

	render::text(x - render::get_text_size(render::fonts::gui_font, string).x / 2 + 50, y + h / 2 - 8, render::fonts::gui_font, string, false, tab == count ? color(229, 137, 226, 245) : color::white());
}

void pendelum::tab_second(const std::string string, std::int32_t& tab, std::int32_t count, std::int32_t x, std::int32_t y) {
	interfaces::surface->surface_get_cursor_pos(cursor.x, cursor.y);

	int w = 40, h = 15;

	if ((cursor.x > x + 30) && (cursor.x < x + 30 + w) && (cursor.y > y) && (cursor.y < y + h) && GetAsyncKeyState(VK_LBUTTON)) {
		tab = count;
		should_drag = false;
		should_move = false;
	}

	render::text(x - render::get_text_size(render::fonts::cs_font, string).x / 2 + 50, y + h / 2 - 8, render::fonts::cs_font, string, false, tab == count ? color(229, 137, 226, 245) : color::white());
}

void pendelum::checkbox(const std::string string, bool& open, std::int32_t x, std::int32_t y) {
	interfaces::surface->surface_get_cursor_pos(cursor.x, cursor.y);

	int w = 15, h = 15;

	for (int i = 0; i < w; i++) {
		if ((cursor.x > x) && (cursor.x < x + w + 20) && (cursor.y > y) && (cursor.y < y + h + 2) && GetAsyncKeyState(VK_LBUTTON)) {
			open = !open;
			should_drag = false;
			should_move = false;
		}

		if (open) {
			render::draw_fade(x + 2, y + 10, w - 8, h - 8, color(100, 100, 0, 255), color(229, 137, 226, 255), false);
			render::draw_rect(x + 1, y + 9, w - 6, h - 6, color(0, 0, 0, 200));
		}
		else {
			render::draw_filled_rect(x + 2, y + 10, w - 8, h - 8, color(60, 60, 60, 200));
			render::draw_fade(x + 2, y + 10, w - 8, h - 8, color(20, 20, 20, 255), color(229, 137, 226, 0), false);
			render::draw_rect(x + 1, y + 9, w - 6, h - 6, color(0, 0, 0, 200));
		}
	}
	render::text(x + 14, y + 7, render::fonts::gui_font, string, false, color::white());
}

void pendelum::combo(const std::string string, int* values, std::int32_t x, std::int32_t y, const std::vector<std::string> elements) {
	interfaces::surface->surface_get_cursor_pos(cursor.x, cursor.y);

	int w = 100, h = 15;

	const bool is_active = blocking_ctx == std::hash<std::string>()(string);
	static bool selected_opened = false;
	static bool rest;
	static std::string name_selected;
	std::size_t size = elements.size();
	const bool hovered = (cursor.x > x) && (cursor.x < x + w) && (cursor.y > y) && (cursor.y < y + h);
	const bool clicked = hovered && GetAsyncKeyState(VK_LBUTTON);
	if (clicked && !blocking_ctx) {
		blocking_ctx = std::hash<std::string>()(string);
		should_drag = false;
		should_move = false;
	}

	if (hovered && is_active && GetAsyncKeyState(VK_LBUTTON))
		blocking_ctx = 0;

	render::draw_filled_rect(x + 1, y - 1, w, is_active ? 15 + (size * 15) : h, color(60, 60, 60, 255));
	render::draw_fade(x + 1, y - 1, w, h, color(20, 20, 20, 255), color(229, 137, 226, 0), false); // brain aint braining on this one
	render::draw_outline(x + 1, y - 1, w, is_active ? 15 + (size * 15) : h, color(0, 0, 0, 200));
	render::text(x + 5, y - 13, render::fonts::gui_font, string, false, color::white());

	if (is_active) {
		for (int i = 0; i < size; i++) {
			if ((cursor.x > x) && (cursor.x < x + w + 20) && (cursor.y > y) && (cursor.y < y + h + 15 + (i * 15)) && GetAsyncKeyState(VK_LBUTTON) & 1) {
				*values = i;
				selected_opened = !selected_opened;
				return;
			}
			// arrow - up
			render::draw_line(x + 92, y + 5, x + 93, y + 5, color(255, 255, 255, 180));
			render::draw_line(x + 91, y + 6, x + 94, y + 6, color(255, 255, 225, 180));
			render::draw_line(x + 90, y + 7, x + 95, y + 7, color(255, 255, 225, 180));
			if (i == *values) {
				render::text(x + 5, (y - 1) + 15 + (i * 15), render::fonts::gui_font, elements[i].c_str(), false, color(255, 255, 0, 255));
			}
			else {
				render::text(x + 5, (y - 1) + 15 + (i * 15), render::fonts::gui_font, elements[i].c_str(), false, color::white(100));
			}
		}
	}
	else {
		// arrow - down
		render::draw_line(x + 90, y + 5, x + 95, y + 5, color(255, 255, 255, 180));
		render::draw_line(x + 91, y + 6, x + 94, y + 6, color(255, 255, 225, 180));
		render::draw_line(x + 92, y + 7, x + 93, y + 7, color(255, 255, 225, 180));
	}
	render::text(x + 5, y, render::fonts::gui_font, elements[*values], false, color(255, 255, 255, 255));
}

void pendelum::multicombo(const std::string string, std::int32_t x, std::int32_t y, const std::vector<std::string> elements, bool* values) {
	static bool open_mcombo = false;

	int w = 100, h = 15;
	int m_combo_id = 0;

	if ((cursor.x > x) && (cursor.x < x + w) && (cursor.y > y) && (cursor.y < y + h) && GetAsyncKeyState(VK_LBUTTON)) 
		open_mcombo = !open_mcombo;

	std::size_t size = elements.size();

	render::draw_filled_rect(x + 1, y - 1, w, open_mcombo ? 15 + (size * 15) : h, color(60, 60, 60, 200));
	render::draw_outline(x + 1, y - 1, w, open_mcombo ? 15 + (size * 15) : h, color(0, 0, 0, 200));

	std::string display;
	for (int i = 0; i < size; i++) {
		if (values[i]) {
			if (!(render::get_text_size(render::fonts::gui_font, display).x > w))
				display += elements[i] + ", ";
			else
				display = elements[i] + ", ...";
		}
	}
	render::draw_fade(x + 1, y - 1, w, h, color(20, 20, 20, 255), color(229, 137, 226, 0), false);
	render::text(x + 20, y, render::fonts::gui_font, display.empty() ? "None" : display, true, color::white(255));

	if (open_mcombo) {
		// arrow - up
		render::draw_line(x + 92, y + 5, x + 93, y + 5, color(255, 255, 255, 180));
		render::draw_line(x + 91, y + 6, x + 94, y + 6, color(255, 255, 225, 180));
		render::draw_line(x + 90, y + 7, x + 95, y + 7, color(255, 255, 225, 180));
		for (int i = 0; i < size; i++) {
			if ((cursor.x > x) && (cursor.x < x + w + 20) && (cursor.y > y) && (cursor.y < y + h + 15 + (i * 15)) && GetAsyncKeyState(VK_LBUTTON) & 1)
				values[i] = !values[i];

			render::text(x + 20, (y - 1) + 15 + (i * 15), render::fonts::gui_font, elements[i], true, values[i] == true ? color(255, 255, 0, 255) : color(255, 255, 255, 255));
		}
	}
	else {
		// arrow - down
		render::draw_line(x + 90, y + 5, x + 95, y + 5, color(255, 255, 255, 180));
		render::draw_line(x + 91, y + 6, x + 94, y + 6, color(255, 255, 225, 180));
		render::draw_line(x + 92, y + 7, x + 93, y + 7, color(255, 255, 225, 180));
	}

	if (open_mcombo = true)
		m_combo_id == 1;

	if (open_mcombo = false)
		m_combo_id == 0;

	if (m_combo_id == 1)
		open_mcombo = false;
}

void pendelum::slider(const std::string string, std::int32_t position, std::int32_t x, std::int32_t y, float& value, float min_value, float max_value) {
	interfaces::surface->surface_get_cursor_pos(cursor.x, cursor.y);

	int ix = x + 1;
	int iy = y + 4;

	//slider label
	if ((cursor.x > ix) && (cursor.x < ix + position) && (cursor.y > iy) && (cursor.y < iy + 6) && (GetAsyncKeyState(VK_LBUTTON))) {
		value = (cursor.x - ix) / (float(position) / float(max_value));
		should_drag = false;
		should_move = false;
	}

	//slider background
	render::draw_filled_rect(ix, iy, position, 6, color(60, 60, 60, 200));
	render::draw_rect(ix - 1, iy - 1, 127, 8, color(0, 0, 0, 200));
	render::draw_fade(ix, iy, position, 6, color(20, 20, 20, 255), color(229, 137, 226, 0), false);
	render::draw_fade(ix, iy, value * (float(position) / float(max_value)), 6, color(100, 100, 0, 255), color(229, 137, 226, 255), false);

	//slider percent
	render::text(ix + value * (float(120) / float(max_value)), iy, render::fonts::gui_font, (std::stringstream{ } << std::setprecision(3) << value << "%").str(), false, color::white());

	//slider label
	render::text(ix + 4,iy - 13, render::fonts::gui_font, string, false, color::white());
}

void pendelum::sliderint(const std::string string, std::int32_t position, std::int32_t x, std::int32_t y, int& value, int min_value, int max_value) {
	interfaces::surface->surface_get_cursor_pos(cursor.x, cursor.y);

	int ix = x + 1;
	int iy = y + 4;

	//slider label
	if ((cursor.x > ix) && (cursor.x < ix + position) && (cursor.y > iy) && (cursor.y < iy + 6) && (GetAsyncKeyState(VK_LBUTTON))) {
		value = (cursor.x - ix) / (int(position) / int(max_value));
		should_drag = false;
		should_move = false;
	}

	//slider background
	render::draw_filled_rect(ix, iy, position, 6, color(60, 60, 60, 200));
	render::draw_rect(ix - 1, iy - 1, 127, 8, color(0, 0, 0, 200));
	render::draw_fade(ix, iy, position, 6, color(20, 20, 20, 255), color(229, 137, 226, 0), false);
	render::draw_fade(ix, iy, value * (int(position) / int(max_value)), 6, color(100, 100, 0, 255), color(229, 137, 226, 255), false);

	//slider label
	render::text(ix + value * (int(120) / int(max_value)), iy, render::fonts::gui_font, (std::stringstream{ } << std::setprecision(3) << value << "%").str(), false, color::white());

	//slider label
	render::text(ix + 4, iy - 13, render::fonts::gui_font, string, false, color::white());
}

void pendelum::item_tab(const std::string string, std::int32_t& item_tab, std::int32_t item_count, std::int32_t x, std::int32_t y) {
	interfaces::surface->surface_get_cursor_pos(cursor.x, cursor.y);

	int w = 40, h = 15;

	if ((cursor.x > x) && (cursor.x < x + w - 20) && (cursor.y > y) && (cursor.y < y + h) && GetAsyncKeyState(VK_LBUTTON)) {
		item_tab = item_count;
		should_drag = false;
		should_move = false;
	}

	render::text(x - render::get_text_size(render::fonts::gui_font, string).x / 2 + 50, y + h / 2 - 8, render::fonts::gui_font, string, false, item_tab == item_count ? color(229, 137, 226, 245) : color::white());
}

void pendelum::begin_pl(std::int32_t& x, std::int32_t& y, std::int32_t w, std::int32_t h) {
	interfaces::surface->surface_get_cursor_pos(cursor.x, cursor.y);

	render::draw_filled_rect(x, y, w, h, color(15, 15, 15, 230));
	render::draw_filled_rect(x + 5, y + 5, 340, 390, color(25, 25, 25, 255));

	if (GetAsyncKeyState(VK_LBUTTON) < 0 && (cursor.x > x && cursor.x < x + w && cursor.y > y && cursor.y < y + h)) {
		should_drag_pl = true;

		if (!should_move_pl) {
			cursor_corrected.x = cursor.x - x;
			cursor_corrected.y = cursor.y - y;
			should_move_pl = true;
		}
	}

	if (should_drag_pl) {
		x = cursor.x - cursor_corrected.x;
		y = cursor.y - cursor_corrected.y;
	}

	if (GetAsyncKeyState(VK_LBUTTON) == 0) {
		should_drag_pl = false;
		should_move_pl = false;
	}
}

void pendelum::pl_text(const std::string string, std::int32_t x, std::int32_t y, color color) {
	render::text(x, y, render::fonts::gui_font, string, false, color);
}

void pendelum::input_box(const std::string string, int& id_value, std::int32_t x, std::int32_t y) {
	interfaces::surface->surface_get_cursor_pos(cursor.x, cursor.y);

	static bool typing = false;
	static bool active = false;
	int w = 50, h = 21;
	//static int input_id = 0;

	// makes int display as std::string and displays with "%s"
	static std::string value = tfm::format("%s", id_value);

	for (int i = 0; i < w; i++) {
		if ((cursor.x > x) && (cursor.x < x + w + 20) && (cursor.y > y) && (cursor.y < y + h + 2) && GetAsyncKeyState(VK_LBUTTON)) {
			active = true;
			should_drag = false;
			should_move = false;
		}

		if (active) {
			// text size
			render::get_text_size(render::fonts::gui_font, value);
			render::draw_fade(x + 2, y + 10, w - 8, h - 8, color(100, 100, 0, 255), color(229, 137, 226, 255), false);
			render::draw_rect(x + 1, y + 9, w - 6, h - 6, color(0, 0, 0, 200));
		}
		else {
			render::draw_filled_rect(x + 2, y + 10, w - 8, h - 8, color(60, 60, 60, 200));
			render::draw_rect(x + 1, y + 9, w - 6, h - 6, color(0, 0, 0, 200));
			render::draw_fade(x + 2, y + 10, w - 8, h - 8, color(20, 20, 20, 255), color(229, 137, 226, 0), false);
		}
	}
	// input_box string "name" displayed on the right side of the box
	render::text(x + 49, y + 10, render::fonts::gui_font, string, false, color::white());

	if (active) {
		// if !typing the buffer is value
		// input::buffer should check the WM_CHAR and assign the value to it, but whats going on :/?
		if (!typing)
			input::buffer = value; // input::buffer should get what key is pressed

		// else its value = buffer
		else
			value = input::buffer;

		// max characters we can input into the input_box (10)
		if (value.size() >= 10)
			value = value.substr(0, 10);

		typing = true;

		// if vkescape or vkreturn pressed, we deactivate the input_box
		if (GetAsyncKeyState(VK_ESCAPE) || GetAsyncKeyState(VK_RETURN)) {
			active = false;
			interfaces::clientstate->full_update();
		}

		// if backspace, we erase everything from the box (values and stuff), if value is empty dont do shit
		if (GetAsyncKeyState(VK_BACK) && !value.empty()) {
			input::buffer.pop_back();
		}

		if (value.empty())
			value = "0";
	}
	else {
		// if input_box not active dont do WM_CHAR
		typing = false;
		// convert string to int, pass it to id_value, id_value = variable in menu
		id_value = std::stoi(value);
#ifdef _DEBUG
		//console::log("%i - id_value (input_box)\n", id_value);
#endif
	}
	// display value
	render::text(x + 4, y + 10, render::fonts::gui_font, value, false, color::white());

	//if (active = true)
		//input_id == 1;

	//if (active = false)
		//input_id == 0;

	//if (input_id == 1)
		///active = false;
}

void pendelum::button(const std::string string, bool active, std::int32_t x, std::int32_t y) {
	interfaces::surface->surface_get_cursor_pos(cursor.x, cursor.y);

	int w = 100, h = 21;

	for (int i = 0; i < w; i++) {
		if ((cursor.x > x) && (cursor.x < x + w + 20) && (cursor.y > y) && (cursor.y < y + h + 2) && GetAsyncKeyState(VK_LBUTTON)) {
			active = true;
			should_drag = false;
			should_move = false;
		}

		if (active) {
			render::draw_fade(x + 2, y + 10, w - 8, h - 8, color(100, 100, 0, 255), color(229, 137, 226, 255), false);
			render::draw_rect(x + 1, y + 9, w - 6, h - 6, color(0, 0, 0, 200));
		}
		else {
			render::draw_filled_rect(x + 2, y + 10, w - 8, h - 8, color(60, 60, 60, 200));
			render::draw_rect(x + 1, y + 9, w - 6, h - 6, color(0, 0, 0, 200));
			render::draw_fade(x + 2, y + 10, w - 8, h - 8, color(20, 20, 20, 255), color(229, 137, 226, 0), false);
		}
	}
	render::text(x + 47, y + 10, render::fonts::gui_font, string, true, color::white());
}

void pendelum::checbox2(std::int32_t x, std::int32_t y, bool* option, std::string text) {
	int mouse_cursor_pos[2];
	interfaces::surface->surface_get_cursor_pos(mouse_cursor_pos[0], mouse_cursor_pos[1]);
	std::string checkbox_text = "[";
	checkbox_text += *option ? "x" : " ";
	checkbox_text += "] " + text;
	vec2_t checkbox_text_size = render::get_text_size(render::fonts::gui_font, checkbox_text);
	int bounds[] = { x, y, checkbox_text_size.x, checkbox_text_size.y };
	if (utilities::cursor_in_box(mouse_cursor_pos, bounds) && GetAsyncKeyState(VK_LBUTTON) & TRUE)
		*option = !(*option);
	render::draw_filled_rect(x, y, checkbox_text_size.x, checkbox_text_size.y, utilities::cursor_in_box(mouse_cursor_pos, bounds) ? (variables::blink_switch ? color(20, 20, 20, 255) : color(20, 20, 20, 255)) : color(20, 20, 20, 255));
	render::text(x, y, render::fonts::gui_font, checkbox_text, false, utilities::cursor_in_box(mouse_cursor_pos, bounds) ? (variables::blink_switch ? color(20, 20, 20, 255) : color(20, 20, 20, 255)) : color(20, 20, 20, 255));
	y += checkbox_text_size.y + 5;
}
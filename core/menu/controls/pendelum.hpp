#pragma once
#include "../../../dependencies/utilities/csgo.hpp"
#include "input.hpp"
#include "../menu.hpp"

struct coordinates {
	int x;
	int y;
};

// define keys for input
#define VK_0 0x30
#define VK_1 0x31
#define VK_2 0x32
#define VK_3 0x33
#define VK_4 0x34
#define VK_5 0x35
#define VK_6 0x36
#define VK_7 0x37
#define VK_8 0x38
#define VK_9 0x39

namespace pendelum {
	void groupbox(const std::string string, std::int32_t x, std::int32_t y, std::int32_t w, std::int32_t h);
	void tab(const std::string string, std::int32_t& tab, std::int32_t count, std::int32_t x, std::int32_t y);
	void tab_second(const std::string string, std::int32_t& tab, std::int32_t count, std::int32_t x, std::int32_t y);
	void begin(std::int32_t& x, std::int32_t& y, std::int32_t w, std::int32_t h);
	void checkbox(const std::string string, bool& open, std::int32_t x, std::int32_t y);
	void child(const std::string string, std::int32_t x, std::int32_t y, std::int32_t w, std::int32_t h);
	void combo(const std::string string, int* values, std::int32_t x, std::int32_t y, const std::vector<std::string> elements);
	void multicombo(const std::string string, std::int32_t x, std::int32_t y, const std::vector<std::string> elements, bool* values);
	void slider(const std::string string, std::int32_t position, std::int32_t x, std::int32_t y, float& value, float min_value, float max_value);
	void sliderint(const std::string string, std::int32_t position, std::int32_t x, std::int32_t y, int& value, int min_value, int max_value);
	void item_tab(const std::string string, std::int32_t& tab, std::int32_t count, std::int32_t x, std::int32_t y);
	void begin_pl(std::int32_t& x, std::int32_t& y, std::int32_t w, std::int32_t h);
	void pl_text(const std::string string, std::int32_t x, std::int32_t y, color color);
	void input_box(const std::string string, int& id_value, std::int32_t x, std::int32_t y);
	void button(const std::string string, bool active, std::int32_t x, std::int32_t y);

	void checbox2(std::int32_t x, std::int32_t y, bool* option, std::string text);


	inline bool should_drag_pl = false;
	inline bool should_move_pl = false;
	inline bool should_drag = false;
	inline bool should_move = false;
	inline bool open_combo = false;
	inline bool int_tab = true;
	inline unsigned int blocking_ctx = 0;
};

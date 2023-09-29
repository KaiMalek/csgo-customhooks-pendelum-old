#pragma once
#include "../../dependencies/utilities/csgo.hpp"
#include "controls/pendelum.hpp"
#include "variables.hpp"
#include "../features/features.hpp"

namespace menu {
	inline int tab_count = 2;
	inline int visuals_tab = 0;
	inline int weapons_tab = 0;

	void render();
	void render_playerlist();
};

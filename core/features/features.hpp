#pragma once
#include "../../dependencies/utilities/csgo.hpp"
#include "../menu/variables.hpp"
#include "events/events.hpp"
#include "../menu/controls/pendelum.hpp"
#include "exploits/backtrack.h"
#include "../../dependencies/utilities/xor.h"

class player_log : public singleton<player_log>
{
public:
	player_log_t& get_log(const int index);
private:
	player_log_t logs[65];

};

namespace aimbot {
	namespace awall {
	}
	namespace resolver {
		void resolver(player_t* player);
	}
	namespace legit {
		int get_nearest_bone(player_t* entity, c_usercmd* user_cmd);
		void weapon_settings(weapon_t* weapon);
		int find_target(c_usercmd* user_cmd);

		static inline int aimbone;
		static inline float aim_smooth;
		static inline float aim_fov;
		static inline float rcs_x;
		static inline float rcs_y;
		static inline int hitbox_id;
		static inline vec3_t angle;
		static inline int kill_delay;

		void event_player_death(i_game_event* event);
		void auto_pistol(c_usercmd* user_cmd);
		void run(c_usercmd* user_cmd);
	}
	namespace rage {
	}
}

namespace antiaim {
	namespace legitaa {
		void update_lowerbody_breaker();
		void legit_antiaim_run(c_usercmd* cmd, bool& send_packet);
		void show_hitbox();
	}
	namespace rageaa {
		void ideal_pitch(c_usercmd* cmd);
		void run(c_usercmd* cmd, bool& send_packet);
		void update_lby();
		void desync(c_usercmd* cmd, bool& send_packet);
	}

	namespace animation {
#define Q_ASSERT(EXPRESSION) static_cast<void>(0)

		void animation_fix(bool& send_packet, c_usercmd* cmd);
		void animation_sec(bool& send_packet, c_usercmd* cmd);
		std::add_lvalue_reference_t<matrix_t[MAXSTUDIOBONES]> get_client_bone_matrices();
		void convert_bones_pos_to_local_space(matrix_t(&bones_to_world)[MAXSTUDIOBONES], const int player_index, const vec3_t& player_origin);
		void convert_bones_position_to_world_space(matrix_t(&bones_to_local)[MAXSTUDIOBONES], const int player_index, const vec3_t& player_origin);
	}
}

namespace exploits {
	namespace fakelag {
		void do_fakelag(bool& send_packet, c_usercmd* cmd);
	}
}

struct box {
	int x, y, w, h;
	box() = default;
	box(int x, int y, int w, int h) {
		this->x = x;
		this->y = y;
		this->w = w;
		this->h = h;
	}
};

namespace visuals {
	namespace esp {
		void player_esp_enable(player_t* entity);
		void player_loop();
		bool get_playerbox(player_t* ent, box& in);
		void draw_box(player_t* ent, box bbox);
		void draw_hp(player_t* entity, box bbox);
		void draw_info(player_t* entity, box bbox);
	}
	namespace chams {
		void dme_chams_run(hooks::dme::fn original, void* thisptr, void* context, void* state, const model_render_info_t& info, matrix_t* custom_bone_to_world);
		void dme_misc(hooks::dme::fn original, void* thisptr, void* context, void* state, const model_render_info_t& info, matrix_t* custom_bone_to_world);
		void custom_materials();
	}
	namespace world {
		void remove_3dsky();
		void fog();
		void sky_changer();
	}
	namespace client {
		void watermark();
		void fov_changer();
		void information_client();
		void indicators(c_usercmd* cmd);
	}
	void loop_visuals();
}

namespace misc {
	namespace movement {
		void bunny_hop(c_usercmd* cmd);
		void strafe(c_usercmd* cmd);
		void adv_bhop(c_usercmd* cmd);
	}
	namespace world {
		void disable_post_processing() noexcept;
	}
	namespace client {
		void recoil_crosshair() noexcept;
		void force_crosshair() noexcept;

		namespace logger {
			void events(i_game_event* event);
		}
		
		namespace notification_system {
			struct notify_t {
				std::string text;
				float time;
				color _color;
				notify_t(std::string _text, color __color) {
					text = _text;
					_color = __color;
					time = interfaces::globals->cur_time;
				}
			};

			inline std::vector<notify_t> notify_list;

			void draw();
			void notify(std::string text, color _color);
		}
	}
	void loop_misc();
	void loop_movement(c_usercmd* cmd);
}

namespace skins {
	namespace skinchanger {
		void run();
		void animfix_hook();
		void animfix_unhook();
		void skin_list();
		void list();
	}

	namespace weaponchanger {
		void run();
		void list();
	}

	namespace glovechanger {
		bool apply_glove_model(attributable_item_t* glove, const char* model);
		bool apply_glove_skin(attributable_item_t* glove, int item_definition_index, int paint_kit, int model_index, int entity_quality, float fallback_wear);
		void run();
	}
}
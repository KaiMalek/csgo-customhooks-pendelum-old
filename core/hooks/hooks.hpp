#pragma once

namespace hooks {
	bool initialize();
	void release();

	extern WNDPROC wndproc_original;
	extern HWND window;

	inline unsigned int get_virtual(void* _class, unsigned int index) { return static_cast<unsigned int>((*static_cast<int**>(_class))[index]); }
	LRESULT __stdcall wndproc(HWND hwnd, UINT message, WPARAM wparam, LPARAM lparam);

	namespace alloc_key_values {
		using fn = void* (__thiscall*)(void*, const std::int32_t);
		void* __stdcall hook(const std::int32_t size);
	}

	namespace create_move_proxy {
		using fn = void(__stdcall*)(int, float, bool);
		void __stdcall hook(int sequence_number, float input_sample_time, bool is_active);
	};

	namespace frame_stage_notify {
		using fn = void(__thiscall*)(i_base_client_dll*, int);
		void __stdcall hook(int frame_stage);
	}

	namespace paint_traverse {
		using fn = void(__thiscall*)(i_panel*, unsigned int, bool, bool);
		void __stdcall hook(unsigned int panel, bool force_repaint, bool allow_force);
	}

	namespace override_view {
		using fn = void* (__fastcall*)(i_client_mode*, void* _this, view_setup_t* setup);
		void __fastcall hook(void* _this, void* _edx, view_setup_t* setup);
	}

	namespace dme {
		using fn = void(__thiscall*)(void*, void*, void*, const model_render_info_t&, matrix_t*);
		void __fastcall hook(void* thisptr, void* edx, void* ctx, void* state, const model_render_info_t& info, matrix_t* custom_bone_to_world);
	}
}

#include "../../dependencies/utilities/csgo.hpp"
#include "../features/features.hpp"
#include "../features/misc/engine_prediction.hpp"
#include "../menu/menu.hpp"
#include "web/api.h" 
#include "../menu/controls/input.hpp"

HWND hooks::window;
WNDPROC hooks::wndproc_original = NULL;

hooks::alloc_key_values::fn alloc_key_values_original = nullptr;
hooks::create_move_proxy::fn create_move_proxy_original = nullptr;
hooks::frame_stage_notify::fn frame_stage_notify_original = nullptr;
hooks::paint_traverse::fn paint_traverse_original = nullptr;
hooks::override_view::fn override_view_original = nullptr;
hooks::dme::fn dme_original = nullptr;

bool hooks::initialize() {
	const auto alloc_key_values_target = reinterpret_cast<void*>(get_virtual(interfaces::key_values_system, 2));
	const auto create_move_proxy_target = reinterpret_cast<void*>(get_virtual(interfaces::client, 22));
	const auto frame_stage_notify_target = reinterpret_cast<void*>(get_virtual(interfaces::client, 37));
	const auto paint_traverse_target = reinterpret_cast<void*>(get_virtual(interfaces::panel, 41));
	const auto override_view_target = reinterpret_cast<void*>(get_virtual(interfaces::clientmode, 18));
	const auto dme_target = reinterpret_cast<void*>(get_virtual(interfaces::model_render, 21));

	if (MH_Initialize() != MH_OK)
		throw std::runtime_error("failed to initialize MH_Initialize.");

	if (MH_CreateHook(alloc_key_values_target, &alloc_key_values::hook, reinterpret_cast<void**>(&alloc_key_values_original)) != MH_OK)
		throw std::runtime_error("failed to initialize alloc_key_values. (outdated index?)");

	if (MH_CreateHook(create_move_proxy_target, &create_move_proxy::hook, reinterpret_cast<void**>(&create_move_proxy_original)) != MH_OK)
		throw std::runtime_error("failed to initialize create_move_proxy. (outdated index?)");

	if (MH_CreateHook(paint_traverse_target, &paint_traverse::hook, reinterpret_cast<void**>(&paint_traverse_original)) != MH_OK)
		throw std::runtime_error("failed to initialize paint_traverse. (outdated index?)");

	if (MH_CreateHook(frame_stage_notify_target, &frame_stage_notify::hook, reinterpret_cast<void**>(&frame_stage_notify_original)) != MH_OK)
		throw std::runtime_error("failed to initialize frame_stage_notify. (outdated index?)");

	if (MH_CreateHook(override_view_target, &override_view::hook, reinterpret_cast<void**>(&override_view_original)) != MH_OK)
		throw std::runtime_error(("failed to initialize override_view."));

	if (MH_CreateHook(dme_target, &dme::hook, reinterpret_cast<void**>(&dme_original)) != MH_OK)
		throw std::runtime_error("failed to initialize dme. (outdated index?)");


	if (MH_EnableHook(MH_ALL_HOOKS) != MH_OK)
		throw std::runtime_error("failed to enable hooks.");

	window = FindWindowW((L"Valve001"), NULL);
	
	if (!window)
		throw std::runtime_error(("failed to initialize game window."));

	wndproc_original = reinterpret_cast<WNDPROC>(SetWindowLongW(window, GWL_WNDPROC, reinterpret_cast<LONG>(wndproc)));

	skins::skinchanger::animfix_hook();

	console::log("[setup] hooks initialized!\n");
	return true;
}

void hooks::release() {
	// unhook wndproc
	SetWindowLongPtrW(window, GWLP_WNDPROC, LONG(hooks::wndproc_original));

	event_listener.release();
	skins::skinchanger::animfix_unhook();

	MH_DisableHook(MH_ALL_HOOKS);
	MH_RemoveHook(MH_ALL_HOOKS);
	MH_Uninitialize();
}

std::uint8_t* key_values_engine = utilities::pattern_scan("engine.dll", sig_key_values_engine);
std::uint8_t* key_values_client = utilities::pattern_scan("client.dll", sig_key_values_client);

void* __stdcall hooks::alloc_key_values::hook(const std::int32_t size) {
	if (const std::uint32_t address = reinterpret_cast<std::uint32_t>(_ReturnAddress());
		address == reinterpret_cast<std::uint32_t>(key_values_engine) || address == reinterpret_cast<std::uint32_t>(key_values_client))
		return nullptr;

	return alloc_key_values_original(interfaces::key_values_system, size);
}

static bool __stdcall create_move(float input_sample_frametime, c_usercmd* cmd, bool& send_packet) {
	csgo::local_player = static_cast<player_t*>(interfaces::entity_list->get_client_entity(interfaces::engine->get_local_player()));

	csgo::cmd = cmd;

	auto net_channel = interfaces::clientstate->net_channel;
	auto old_viewangles = cmd->viewangles;
	auto old_forwardmove = cmd->forwardmove;
	auto old_sidemove = cmd->sidemove;

	misc::loop_movement(cmd);
	visuals::loop_visuals();
	misc::loop_misc();

	prediction::start(cmd); {
		aimbot::legit::run(cmd);
		antiaim::rageaa::run(cmd, send_packet);
		antiaim::legitaa::update_lowerbody_breaker();
		antiaim::legitaa::legit_antiaim_run(cmd, send_packet);

		antiaim::rageaa::desync(cmd, send_packet);
		exploits::fakelag::do_fakelag(send_packet, cmd);

		backtrack.backtrack_run(cmd);

		antiaim::animation::animation_sec(send_packet, cmd);
	} prediction::end();

	csgo::send_packet = send_packet;

	math::correct_movement(old_viewangles, cmd, old_forwardmove, old_sidemove);

	cmd->forwardmove = std::clamp(cmd->forwardmove, -450.0f, 450.0f);
	cmd->sidemove = std::clamp(cmd->sidemove, -450.0f, 450.0f);
	cmd->upmove = std::clamp(cmd->upmove, -320.0f, 320.0f);

	cmd->viewangles.normalize();
	cmd->viewangles.x = std::clamp(cmd->viewangles.x, -89.0f, 89.0f);
	cmd->viewangles.y = std::clamp(cmd->viewangles.y, -180.0f, 180.0f);
	cmd->viewangles.z = 0.0f;

	csgo::real_angles_vector = cmd->viewangles;

	return false;
}

static void __stdcall chl_create_move(int sequence_number, float input_sample_time, bool active, bool& send_packet) {
	create_move_proxy_original(sequence_number, input_sample_time, active);

	c_usercmd* cmd = interfaces::input->get_user_cmd(0, sequence_number);
	if (!cmd || !cmd->command_number)
		return;

	c_verified_user_cmd* verified_cmd = interfaces::input->get_verified_cmd(sequence_number);
	if (!verified_cmd)
		return;

	bool create_move_active = create_move(input_sample_time, cmd, send_packet);

	verified_cmd->user_cmd = *cmd;
	verified_cmd->u_hash_crc = cmd->get_checksum();
}

__declspec(naked) void __stdcall hooks::create_move_proxy::hook(int sequence_number, float input_sample_time, bool active) {
	__asm
	{
		push ebp
		mov  ebp, esp
		push ebx;
		push esp
		push dword ptr[active]
		push dword ptr[input_sample_time]
		push dword ptr[sequence_number]
		call chl_create_move
		pop  ebx
		pop  ebp
		retn 0Ch
	}
}

void __stdcall hooks::paint_traverse::hook(unsigned int panel, bool force_repaint, bool allow_force) {
	auto panel_to_draw = fnv::hash(interfaces::panel->get_panel_name(panel));

	switch (panel_to_draw) {
	case fnv::hash("MatSystemTopPanel"):
		visuals::client::watermark();

#ifdef _DEBUG
		menu::render();
		menu::render_playerlist();
#endif // _DEBUG

		visuals::esp::player_loop();
		visuals::client::information_client();
		visuals::client::indicators(csgo::cmd);
		misc::client::notification_system::draw();

		if (GetAsyncKeyState(VK_INSERT) & 1)
			variables::menu::opened = !variables::menu::opened;

		break;

	case fnv::hash("FocusOverlayPanel"):
		interfaces::panel->set_keyboard_input_enabled(panel, variables::menu::opened);
		interfaces::panel->set_mouse_input_enabled(panel, variables::menu::opened);
		break;
	}

	paint_traverse_original(interfaces::panel, panel, force_repaint, allow_force);
}

void __stdcall hooks::frame_stage_notify::hook(int frame_stage) {
	static auto backtrack_init = (backtrack.initialize_backtrack(), false);
	antiaim::legitaa::show_hitbox();
	aimbot::resolver::resolver(csgo::local_player);
	switch (frame_stage) {
	case FRAME_UNDEFINED:
		break;
	case FRAME_START:
		break;
	case FRAME_NET_UPDATE_START:
		break;
	case FRAME_NET_UPDATE_POSTDATAUPDATE_START:
		if (variables::knife_enabled)
			skins::skinchanger::run();

		if (variables::glove_enabled)
			skins::glovechanger::run();

		if (variables::weapon_enabled)
			skins::weaponchanger::run();
		break;
	case FRAME_NET_UPDATE_POSTDATAUPDATE_END:
		break;
	case FRAME_NET_UPDATE_END:
		//backtrack.update();
		break;
	case FRAME_RENDER_START:
		antiaim::animation::animation_fix(csgo::send_packet, csgo::cmd);
		break;
	case FRAME_RENDER_END:
		break;
	default: break;
	}

	frame_stage_notify_original(interfaces::client, frame_stage);
}

void __fastcall hooks::override_view::hook(void* _this, void* _edx, view_setup_t* setup) {
	visuals::client::fov_changer();
	override_view_original(interfaces::clientmode, _this, setup);
}

LRESULT __stdcall hooks::wndproc(HWND hwnd, UINT message, WPARAM wparam, LPARAM lparam) {
	interfaces::inputsystem->enable_input(!variables::menu::opened);

	switch (message) {
	case WM_CHAR:
		switch (wparam) {
		default:
			// std::isdigit check its the inputted thing is from 0 to 9 (numbers on keyboard)
			if (std::isdigit(static_cast<char>(wparam))) {
				// convert bits to string or char at this point
				input::buffer += static_cast<char>(wparam);
#ifdef _DEBUG
				//console::log("WM_CHAR checked! - WndProc hook\n"); // simple check if VM_CHAR works (debug only)
#endif // DEBUG
			}
		break;
		}
		break;
	default:
		break;
	}
	//input::input_listener(message, wparam);
	return CallWindowProcW(wndproc_original, hwnd, message, wparam, lparam);
}

void __fastcall hooks::dme::hook(void* thisptr, void* edx, void* ctx, void* state, const model_render_info_t& info, matrix_t* custom_bone_to_world) {
	visuals::chams::dme_misc(dme_original, thisptr, ctx, state, info, custom_bone_to_world);
	visuals::chams::dme_chams_run(dme_original, thisptr, ctx, state, info, custom_bone_to_world);
}
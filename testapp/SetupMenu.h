#pragma once

#include "Menulist.h"

class SetupMenu {
public:
	SetupMenu(SDL_Renderer* renderer);
	~SetupMenu();

	Menulist menulist;

	Menu main_menu;
	Menu choose_savestate_menu;
	Menu create_world_menu;
	Menu settings_menu;
	Menu pause_menu;

	Button play_button;

	void add_main_menu();
	void add_choose_savestate_menu();
	void add_create_world_menu();
	void add_settings_menu();
	void add_pause_menu();
};
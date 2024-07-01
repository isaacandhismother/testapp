#pragma once

#include "Menulist.h"

class SetupMenu {
public:
	SetupMenu(SDL_Renderer* renderer);
	~SetupMenu();

	SDL_Color black = { 0, 0, 0, 255 };

	SDL_Color white = { 255, 255, 255,255 };

	SDL_Color grey = { 150, 150, 150, 255 };

	Menulist menulist;

	Menu main_menu;
	Menu choose_savestate_menu;
	//Menu create_world_menu;
	Menu settings_menu;
	//Menu pause_menu;

	Button play_button;
	Button savestate1_button;
	Button savestate2_button;
	Button savestate3_button;
	Button settings_button;
	Button quit_button;
	Button back_button;

	void add_main_menu();
	void add_choose_savestate_menu();
	void add_create_world_menu();
	void add_settings_menu();
	void add_pause_menu();
	
	bool is_paused;

private:
	void start_game();
	void go_back();
	void quit();
};
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
	Menu choose_savestate_menu(SDL_Renderer* renderer);
	Menu create_world_menu(SDL_Renderer* renderer);
	Menu settings_menu;
	Menu pause_menu(SDL_Renderer* renderer);

	Button play_button;
	Button settings_button;

	void add_main_menu();
	void add_choose_savestate_menu();
	void add_create_world_menu();
	void add_settings_menu();
	void add_pause_menu();
};
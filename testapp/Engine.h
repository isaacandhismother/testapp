#pragma once

#include "SetupMenu.h"
#include "World.h"
#include "Player.h"

class Engine
{
public:
	Engine(SDL_Renderer* renderer, int rows, int columns);
	~Engine();

	void run_engine(SDL_Renderer* renderer);
	void create_world();

private:
	bool left_clicked;
	bool isLeftMouseClicked();
	SetupMenu setup_menu;
	World world;
	Player player;
	SDL_Rect minimap_viewport = { 20, 20, 200, 200 };
	SDL_Rect default_viewport = { 0, 0, width, height };
};

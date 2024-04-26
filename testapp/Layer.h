#pragma once

#include "Tile.h"
#include "Player.h"
#include "Settings.h"

using namespace std;

class Layer
{
public:
	Layer();
	void add_tile(Tile tile);
	void remove_tile(Tile tile);
	void draw(SDL_Renderer* renderer);
	vector<vector<Tile>> tiles;
};


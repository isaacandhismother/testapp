#pragma once

#include "Tile.h"

using namespace std;

class Layer
{
public:
	Layer(int rows, int columns);
	~Layer();
	void add_tile(Tile tile);
	void remove_tile(Tile tile);
	void generate_layer(SDL_Renderer* renderer);
	void draw(SDL_Renderer* renderer, int x, int y, int player_x, int player_y);
	vector<vector<Tile*>> tiles;
	vector<int> layer_size;
};


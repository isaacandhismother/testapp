#pragma once

#include "Layer.h"

using namespace std;

class World
{
public:
	World(int rows, int columns);
	void add_layer(Layer layer);
	void remove_layer(Layer layer);
	void generate_world(SDL_Renderer* renderer);
	void draw(SDL_Renderer* renderer, int row, int column, int player_x, int player_y);
	vector<Layer> layers;
	vector<int> world_size;
};


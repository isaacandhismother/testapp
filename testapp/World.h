#pragma once

#include "Layer.h"

using namespace std;

class World
{
	World();
	void create_world(int rows, int columns);
	void add_layer(Layer layer);
	void remove_layer(Layer layer);
	void draw(SDL_Renderer* renderer);
	vector<Layer> layers;
};


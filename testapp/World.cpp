#include "World.h"

World::World(int rows, int columns) {
	world_size = { rows, columns };
}

void World::add_layer(Layer layer)
{
	layers.push_back(layer);
}

void World::remove_layer(Layer layer)
{
}

void World::generate_world(SDL_Renderer* renderer)
{
	Layer layer_1(world_size[0], world_size[1]);
	layer_1.generate_layer(renderer);
	add_layer(layer_1);
	Layer layer_2(world_size[0], world_size[1]);
	add_layer(layer_2);
}

void World::draw(SDL_Renderer* renderer, int row, int column, int player_x, int player_y)
{
	for (int layer_num = 0; layer_num < layers.size(); layer_num++) {
		layers[layer_num].draw(renderer, row, column, player_x, player_y);
	}
}

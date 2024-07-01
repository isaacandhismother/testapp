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
	//  Change a world generation method so the world generates tiles and then
	// serializes them into chunks.

	Layer background_layer(world_size[0], world_size[1]);
	background_layer.generate_layer(renderer);
	Chunk first_chunk(0, 0);
	first_chunk.add_layer(background_layer);
	first_chunk.save();

	add_layer(background_layer);
	Layer object_layer(world_size[0], world_size[1]);
	add_layer(object_layer);
}

void World::draw(SDL_Renderer* renderer, int row, int column, int player_x, int player_y)
{
	for (int layer_num = 0; layer_num < layers.size(); layer_num++) {
		Layer *layer = &layers[layer_num];
		layer->draw(renderer, row, column, player_x, player_y);
	}
}

#include "World.h"

void World::draw(SDL_Renderer* renderer)
{
	for (int layer_num = 0; layer_num < layers.size(); layer_num++) {
		layers[layer_num].draw(renderer);
	}
}

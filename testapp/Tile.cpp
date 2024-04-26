#include "Tile.h"

Tile::Tile(SDL_Renderer* renderer, int width, int height, const char* image) : GameObject(renderer, width, height, image)
{

}

Tile::~Tile()
{
}

void Tile::add_object(GameObject object)
{
	objects.push_back(object);
}

void Tile::remove_object(GameObject object)
{
    //auto it = std::find(objects.begin(), objects.end(), object);
    //if (it != objects.end()) {
    //    objects.erase(it);
    //}
}


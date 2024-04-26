#pragma once

#include "GameObject.h"

#include<vector>
#include<algorithm>

class Tile : public GameObject
{
public:
	using GameObject::GameObject;
	Tile(SDL_Renderer* renderer, int width, int height, const char* image);
	~Tile();
	void add_object(GameObject object);
	void remove_object(GameObject object);
private:
	std::vector<GameObject> objects;
};


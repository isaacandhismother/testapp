#pragma once

#include "GameObject.h"

#include<algorithm>

class Tile : public GameObject
{
public:
	using GameObject::GameObject;
	Tile(SDL_Renderer* renderer, int width, int height, const char* image);
	~Tile();
	void draw(SDL_Renderer* renderer, int row, int column, int player_x, int player_y);
	void add_object(GameObject* object);
	void remove_object(GameObject* object);
	vector<GameObject*> objects;
};


#pragma once

#include "GameObject.h"

#include<SDL.h>
#include<SDL_image.h>

#include<iostream>

class Player : public GameObject
{
public:
	using GameObject::GameObject;
	Player(SDL_Renderer* renderer, int width, int height, const char* image);
	void draw(SDL_Renderer* renderer, int x, int y, double rotation_angle, SDL_Point* center);
	void go_left();
	void go_right();
	void go_up();
	void go_down();
	void save();
	void load();
	int speed = 5;
	short row, column;
};



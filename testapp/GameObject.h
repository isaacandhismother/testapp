#pragma once

#include<SDL.h>
#include<SDL_image.h>

#include<iostream>

class GameObject
{
public:
	GameObject(SDL_Renderer* renderer, int width, int height, const char* image);
	~GameObject();
	void draw(SDL_Renderer* renderer, int x, int y, double rotation_angle, SDL_Point* center);
	void place(int x, int y);
	SDL_Texture* loadtexture(SDL_Renderer* renderer, const char* image);
	void rotate_left(double angle);
	void rotate_right(double angle);
	int x, y;
	int row, column;
	int width, height;
	int hitbox_height, hitbox_width;
	int hitbox_x, hitbox_y;
	SDL_Point* texture_center;
	SDL_Point pivot;
	double rotation_angle = 0.0;
private:
	const char* image;
	SDL_Surface* surface;
	SDL_Texture* texture;
	SDL_Rect hitbox;
	SDL_Rect rect;
};


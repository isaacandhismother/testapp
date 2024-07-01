#pragma once

#include<SDL.h>
#include<SDL_image.h>

#include<iostream>
#include<string>
#include<iostream>
#include<fstream>
#include "Settings.h"

class GameObject
{
public:
	GameObject(SDL_Renderer* renderer, int width, int height, const string& image_path);
	~GameObject();
	virtual void draw(SDL_Renderer* renderer, int x, int y, double rotation_angle, SDL_Point* center);
	void place(int x, int y);
	SDL_Texture* loadtexture(SDL_Renderer* renderer);
	void rotate_left(double angle);
	void rotate_right(double angle);
	SDL_Rect get_hitbox();
	SDL_Texture* get_texture();

	int x, y;
	int row, column;
	int width, height;
	int hitbox_height, hitbox_width;
	int hitbox_x, hitbox_y;
	SDL_Point pivot;
	double rotation_angle = 0.0;

	virtual void save(ofstream& file) const;
	virtual void load(ifstream& file);
private:
	string image_path;
	SDL_Surface* surface;
	SDL_Texture* texture;
	SDL_Rect hitbox;
	SDL_Rect rect;
};


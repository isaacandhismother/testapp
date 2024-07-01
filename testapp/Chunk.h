#pragma once

#include "Layer.h"

#include<SDL.h>
#include<SDL_image.h>

#include<iostream>
#include<vector>
#include<string>
#include<fstream>

class Chunk
{
public:
	Chunk(int row, int column);
	~Chunk();
	vector <Layer> layers;
	void add_layer(Layer layer);
	void remove_layer(Layer layer);

	void draw(int x, int y);

	void save();
	void load(SDL_Renderer* renderer);
private:
	int row, column;
};

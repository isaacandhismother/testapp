#pragma once

#include "Tile.h"

#include<SDL.h>
#include<SDL_image.h>

#include<iostream>
#include<vector>

class Chunk
{
public:
	Chunk();
	std::vector<std::vector<Tile>> objects;
	int size;
};


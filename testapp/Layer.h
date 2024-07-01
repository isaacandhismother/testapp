#pragma once

#include "Tile.h"

using namespace std;

class Layer
{
public:
	Layer(int rows, int columns);
	~Layer();
	void add_tile(Tile tile);
	void remove_tile(Tile tile);

	void generate_layer(SDL_Renderer* renderer);

	void save(ofstream& file);
	void load(SDL_Renderer* renderer, ifstream& file);
	void draw(SDL_Renderer* renderer, int x, int y, int player_x, int player_y);
private:
	vector<vector<Tile*>> tiles;
	int rows, columns;
};


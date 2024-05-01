#include "Layer.h"

Layer::Layer(int rows, int columns){
    this->layer_size = { rows, columns };
    this->tiles.resize(this->layer_size[0]);
    for (int i = 0; i < this->layer_size[0]; i++) {
        this->tiles[i].resize(this->layer_size[1]);
    }
}

Layer::~Layer() {
}

void Layer::add_tile(Tile tile)
{
}

void Layer::generate_layer(SDL_Renderer* renderer)
{   

    for (int row = 0; row < this->layer_size[0]; row++) {
        for (int column = 0; column < this->layer_size[1]; column++) {

            this->tiles[row][column] = new Tile(renderer, tile_width, tile_height, "Images/grasstop.png");
            this->tiles[row][column]->place(row * tile_width, column * tile_height);
        }
    }
}

void Layer::draw(SDL_Renderer* renderer, int row, int column, int player_x, int player_y)
{
    if (0 <= row && row < this->layer_size[0] && 0 <= column && column < this->layer_size[1]) {
        if (this->tiles.size() > row && this->tiles.size() > column){
            Tile* tile = tiles[row][column];
            if (tile){
                tile->draw(renderer, row, column, player_x, player_y);
            }
        }
    }
}

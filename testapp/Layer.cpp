#include "Layer.h"

Layer::Layer(int rows, int columns){
    layer_size = { rows, columns };
    tiles.resize(layer_size[0]);
    for (int i = 0; i < layer_size[0]; i++) {
        tiles[i].resize(layer_size[1]);
    }
}

void Layer::add_tile(Tile tile)
{
}

void Layer::generate_layer(SDL_Renderer* renderer)
{   

    for (int row = 0; row < layer_size[0]; row++) {
        for (int column = 0; column < layer_size[1]; column++) {

            tiles[row][column] = new Tile(renderer, tile_width, tile_height, "Images/grasstop.png");
            tiles[row][column]->place(row * tile_width, column * tile_height);
            
        }
    }
}

void Layer::draw(SDL_Renderer* renderer, int row, int column, int player_x, int player_y)
{
    if (0 <= row < layer_size[0] && 0 <= column < layer_size[1]) {
        if (tiles.size() > row && this->tiles.size() > column){
            Tile* tile = tiles[row][column];
            if (tile){
                tile->draw(renderer, row, column, player_x, player_y);
            }
        }
    }
}

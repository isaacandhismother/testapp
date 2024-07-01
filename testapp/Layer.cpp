#include "Layer.h"

Layer::Layer(int rows, int columns) : rows(rows), columns(columns){
    this->tiles.resize(this->rows);
    for (int i = 0; i < this->rows; i++) {
        this->tiles[i].resize(this->columns);
    }
}

Layer::~Layer() {
    cout << "layer destroyed" << endl;
}

void Layer::add_tile(Tile tile)
{
}

void Layer::generate_layer(SDL_Renderer* renderer)
{   

    for (int row = 0; row < this->rows; row++) {
        for (int column = 0; column < this->columns; column++) {

            this->tiles[row][column] = new Tile(renderer, tile_width, tile_height, "Images/grasstop.png");
            this->tiles[row][column]->place(row * tile_width, column * tile_height);
        }
    }
}

void Layer::save(ofstream& file) {
    file.write(reinterpret_cast<const char*>(&this->rows), sizeof(this->rows));
    file.write(reinterpret_cast<const char*>(&this->columns), sizeof(this->columns));

    for (int row = 0; row < rows; row++) {
        for (int column = 0; column < columns; column++) {
            bool hasTile = (tiles[row][column] != nullptr);
            file.write(reinterpret_cast<const char*>(&hasTile), sizeof(hasTile));

            if (hasTile) {
                tiles[row][column]->save(file);
            }            
        }
    }
}

void Layer::load(SDL_Renderer* renderer, ifstream& file) {
    int width, height;

    for (int row = 0; row < rows; row++) {
        for (int column = 0; column < columns; column++) {
            bool hasTile;
            file.read(reinterpret_cast<char*>(&hasTile), sizeof(hasTile));

            if (hasTile) {
                file.read(reinterpret_cast<char*>(&width), sizeof(width));
                file.read(reinterpret_cast<char*>(&height), sizeof(height));

                size_t length;
                file.read(reinterpret_cast<char*>(&length), sizeof(length));

                string image_path;
                image_path.resize(length);

                file.read(&image_path[0], length);
                
                cout << image_path << endl;

                tiles[row][column] = new Tile(renderer, width, height, image_path);
                tiles[row][column]->load(renderer, file);
            }
            else {
                tiles[row][column] = nullptr;
            }
        }
    }
}

void Layer::draw(SDL_Renderer* renderer, int row, int column, int player_x, int player_y)
{
    if (0 <= row && row < this->rows && 0 <= column && column < this->columns) {
        if (this->tiles.size() > row && this->tiles.size() > column){
            Tile* tile = tiles[row][column];
            if (tile){
                tile->draw(renderer, row, column, player_x, player_y);
            }
        }
    }
}

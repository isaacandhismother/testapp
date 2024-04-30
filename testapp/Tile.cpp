#include "Tile.h"

Tile::Tile(SDL_Renderer* renderer, int width, int height, const char* image) : GameObject(renderer, width, height, image)
{

}

Tile::~Tile()
{
    cout << "1" << endl;
}

void Tile::draw(SDL_Renderer* renderer, int row, int column, int player_x, int player_y) {

    GameObject::draw(renderer, screen_center[0] + this->x - player_x, screen_center[1] + this->y - player_y, 0, NULL);
    for (size_t i = 0; i < objects.size(); i++) {
        GameObject object = objects[i];
        vector<int> pos_on_screen = {screen_center[0] + object.x - player_x, screen_center[1] + object.y - player_y};
        
        object.draw(renderer, pos_on_screen[0], pos_on_screen[1], 0, NULL);

        // if obj.is_hover() :
        //    selected_object = obj
    }
}

void Tile::add_object(GameObject object)
{
	objects.push_back(object);
}

void Tile::remove_object(GameObject object)
{
    //auto it = std::find(objects.begin(), objects.end(), object);
    //if (it != objects.end()) {
    //    objects.erase(it);
    //}
}


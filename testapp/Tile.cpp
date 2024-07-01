#include "Tile.h"

Tile::Tile(SDL_Renderer* renderer, int width, int height, const char* image) : GameObject(renderer, width, height, image)
{

}

Tile::~Tile()
{
    cout << "tile destroyed" << endl;
    GameObject::~GameObject();
}

void Tile::save(ofstream& file) const {
    GameObject::save(file);

    size_t objects_count = objects.size();
    file.write(reinterpret_cast<const char*>(&objects_count), sizeof(objects_count));

    if (objects_count != 0) {
        for (size_t i{ 0 }; i < objects_count; i++) {
            objects[i]->save(file);
        }
    }
}

void Tile::load(SDL_Renderer* renderer, ifstream& file) {
    GameObject::load(file);

    size_t objects_count = objects.size();
    file.read(reinterpret_cast<char*>(&objects_count), sizeof(objects_count));

    objects.resize(objects_count);

    if (objects_count != 0) {
        int width, height;

        for (size_t i{ 0 }; i < objects_count; i++) {
            file.read(reinterpret_cast<char*>(&width), sizeof(width));
            file.read(reinterpret_cast<char*>(&height), sizeof(height));

            size_t length;
            file.read(reinterpret_cast<char*>(&length), sizeof(length));

            string image_path;
            image_path.resize(length);
            
            file.read(&image_path[0], length);

            objects[i] = new GameObject(renderer, width, height, image_path);
            objects[i]->load(file);
        }
    }
}

void Tile::draw(SDL_Renderer* renderer, int row, int column, int player_x, int player_y) {

    GameObject::draw(renderer, screen_center[0] + this->x - player_x, screen_center[1] + this->y - player_y, 0, NULL);

    for (size_t i = 0; i < objects.size(); i++) {
        GameObject* object = objects[i];
        vector<int> pos_on_screen = {screen_center[0] + object->x - player_x, screen_center[1] + object->y - player_y};
        
        object->draw(renderer, pos_on_screen[0], pos_on_screen[1], 0, NULL);

        // if obj.is_hover() :
        //    selected_object = obj
    }
}

void Tile::add_object(GameObject* object)
{
	objects.push_back(object);
}

void Tile::remove_object(GameObject* object)
{
    //auto it = std::find(objects.begin(), objects.end(), object);
    //if (it != objects.end()) {
    //    objects.erase(it);
    //}
}


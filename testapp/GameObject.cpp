#include "GameObject.h"

GameObject::GameObject(SDL_Renderer* renderer, int width, int height, const string& image_path) : width(width), height(height), image_path(image_path)
{
	texture = loadtexture(renderer);

	if (texture == NULL) {
		std::cout << "Failed to load texture: " << SDL_GetError() << std::endl;
	}
}

GameObject::~GameObject()
{
	cout << "GameObject destroyed" << endl;
}

void GameObject::save(ofstream& file) const{
	file.write(reinterpret_cast<const char*>(&width), sizeof(width));
	file.write(reinterpret_cast<const char*>(&height), sizeof(height));

	size_t length = image_path.size();
	file.write(reinterpret_cast<const char*>(&length), sizeof(length));
	file.write(image_path.c_str(), length);

	file.write(reinterpret_cast<const char*>(&x), sizeof(x));
	file.write(reinterpret_cast<const char*>(&y), sizeof(y));

	file.write(reinterpret_cast<const char*>(&hitbox_height), sizeof(hitbox_height));
	file.write(reinterpret_cast<const char*>(&hitbox_width), sizeof(hitbox_width));

	file.write(reinterpret_cast<const char*>(&hitbox_x), sizeof(hitbox_x));
	file.write(reinterpret_cast<const char*>(&hitbox_y), sizeof(hitbox_y));

	file.write(reinterpret_cast<const char*>(&pivot), sizeof(pivot));

	file.write(reinterpret_cast<const char*>(&rotation_angle), sizeof(rotation_angle));
}

void GameObject::load(ifstream& file) {
	file.read(reinterpret_cast<char*>(&x), sizeof(x));
	file.read(reinterpret_cast<char*>(&y), sizeof(y));

	file.read(reinterpret_cast<char*>(&hitbox_height), sizeof(hitbox_height));
	file.read(reinterpret_cast<char*>(&hitbox_width), sizeof(hitbox_width));

	file.read(reinterpret_cast<char*>(&hitbox_x), sizeof(hitbox_x));
	file.read(reinterpret_cast<char*>(&hitbox_y), sizeof(hitbox_y));

	file.read(reinterpret_cast<char*>(&pivot), sizeof(pivot));

	file.read(reinterpret_cast<char*>(&rotation_angle), sizeof(rotation_angle));

	cout << x << ", " << y << endl;
}

void GameObject::draw(SDL_Renderer* renderer, int x, int y, double rotation_angle, SDL_Point* center) {

	rect = { x, y, this->width, this->height };

	SDL_RenderCopyEx(renderer, texture, NULL, &rect, rotation_angle, center, SDL_FLIP_NONE);

}

void GameObject::place(int x, int y) {
	this->x = x;
	this->y = y;
	this->hitbox_x = x;
	this->hitbox_y = y;
}

SDL_Texture* GameObject::loadtexture(SDL_Renderer* renderer) {
	
	surface = IMG_Load(image_path.c_str());
	if (surface == nullptr) {
		std::cout << "Can't load image: " << IMG_GetError() << std::endl;
	}
	else {
		texture = SDL_CreateTextureFromSurface(renderer, surface);
	}

	SDL_FreeSurface(surface);

	return texture;
}

void GameObject::rotate_left(double angle)
{
	this->rotation_angle -= angle;
}

void GameObject::rotate_right(double angle)
{
	this->rotation_angle += angle;
}

SDL_Rect GameObject::get_hitbox()
{
	return hitbox;
}

SDL_Texture* GameObject::get_texture()
{
	return texture;
}

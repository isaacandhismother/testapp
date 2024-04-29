#include "GameObject.h"

GameObject::GameObject(SDL_Renderer* renderer, int width, int height, const char* image) : width(width), height(height), image(image)
{
	texture = loadtexture(renderer, image);

	if (texture == NULL) {
		std::cout << "Failed to load texture: " << SDL_GetError() << std::endl;
	}
}

GameObject::~GameObject()
{
	SDL_DestroyTexture(texture);	
}

void GameObject::draw(SDL_Renderer* renderer, int x, int y, double rotation_angle, SDL_Point* center) {

	rect = { x, y, width, height };

	SDL_RenderCopyEx(renderer, texture, NULL, &rect, rotation_angle, center, SDL_FLIP_NONE);

}

void GameObject::place(int nX, int nY) {
	x = nX;
	y = nY;
	hitbox_x = nX;
	hitbox_y = nY;
}

SDL_Texture* GameObject::loadtexture(SDL_Renderer* renderer, const char* image) {

	surface = IMG_Load(image);
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
	rotation_angle -= angle;
}

void GameObject::rotate_right(double angle)
{
	rotation_angle += angle;
}

SDL_Rect GameObject::get_hitbox()
{
	return hitbox;
}

SDL_Texture* GameObject::get_texture()
{
	return texture;
}

#include "Player.h"

Player::Player(SDL_Renderer* renderer, int width, int height, const char* image) : GameObject(renderer, width, height, image)
{
	hitbox_width = width;
	hitbox_height = height / 4;

	pivot.x = hitbox_width - (width / 2);
	pivot.y = hitbox_height - (height / 2);
}

void Player::draw(SDL_Renderer* renderer, int x, int y, double rotation_angle, SDL_Point* center) 
{
	row = this->x / tile_width;
	column = this->y / tile_height;
	x -= this->width / 2;
	y -= this->height / 2;
	GameObject::draw(renderer, x, y, rotation_angle, center);

	SDL_Rect hitbox = GameObject::get_hitbox();

	hitbox_x = this->x;
	hitbox_y = this->y;

	hitbox = { x, y + height - hitbox_height, hitbox_width, hitbox_height };

	SDL_Texture* texture = GameObject::get_texture();

	SDL_RenderCopyEx(renderer, NULL, NULL, &hitbox, rotation_angle, &pivot, SDL_FLIP_NONE);
}

void Player::go_left() {
	x -= speed;
}

void Player::go_right() {
	x += speed;
}

void Player::go_up() {
	y -= speed;
}

void Player::go_down() {
	y += speed;
}

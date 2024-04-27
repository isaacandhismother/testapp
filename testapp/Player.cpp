#include "Player.h"

Player::Player(SDL_Renderer* renderer, int width, int height, const char* image) : GameObject(renderer, width, height, image)
{
	hitbox_width = width;
	hitbox_height = height / 4;
}

void Player::draw(SDL_Renderer* renderer, int x, int y, double rotation_angle, SDL_Point* center) 
{
	row = this->x / tile_width;
	column = this->y / tile_height;
	x -= this->width / 2;
	y -= this->height / 2;
	GameObject::draw(renderer, x, y, rotation_angle, center);
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

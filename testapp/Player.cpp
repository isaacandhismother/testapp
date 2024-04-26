#include "Player.h"

Player::Player(SDL_Renderer* renderer, int width, int height, const char* image) : GameObject(renderer, width, height, image)
{
	hitbox_width = width;
	hitbox_height = height / 4;

	pivot.x = hitbox_width / 2;
	pivot.y = hitbox_height - (height / 2);
	texture_center = &pivot;
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

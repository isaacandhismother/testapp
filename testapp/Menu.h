#pragma once

#include "Button.h"

class Menu
{
public:
	Menu(int width, int height);
	~Menu();
	void place(int x, int y);
	SDL_Texture* loadtexture(SDL_Renderer* renderer, const char* image);
	void add_background(SDL_Renderer* renderer, string background_type, SDL_Color color = { 255, 255, 255, 255 }, const char* image = "");
	void draw(SDL_Renderer* renderer, int  x, int y, bool clicked);
	void add_button(Button button);
	int x, y;
	int width, height;
private:
	vector<Button> buttons;
	string background_type;
	SDL_Rect rect;
	SDL_Surface* surface;
	SDL_Texture* texture;
	SDL_Color background_color;
};
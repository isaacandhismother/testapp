#pragma once

#include "Menu.h"

class Menulist
{
public:
	Menulist();
	~Menulist();
	void add(Menu* menu);
	void remove_last();
	bool is_empty();
	void clear();
	void draw(SDL_Renderer* renderer, bool clicked);
private:
	vector<Menu*> menus;
};


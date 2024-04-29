#include "Menulist.h"

Menulist::Menulist()
{
}

Menulist::~Menulist()
{
}

void Menulist::add(Menu menu)
{
	menus.push_back(menu);
}

void Menulist::remove_last()
{
	menus.pop_back();
}

bool Menulist::is_empty()
{
	return menus.empty();
}

void Menulist::draw(SDL_Renderer* renderer, bool clicked)
{
	if (menus.size() != 0) {
		Menu menu = menus[menus.size() - 1];
		menu.draw(renderer, menu.x, menu.y, clicked);
	}
}


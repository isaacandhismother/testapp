#include "Menulist.h"

Menulist::Menulist()
{
}

Menulist::~Menulist()
{
	cout << "menulist destroyed" << endl;
}

void Menulist::add(Menu* menu)
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

void Menulist::clear() {
	if (!is_empty()) {
		for (size_t i = 0; i < menus.size() + 1; i++) {
			menus.pop_back();
		}
		cout << "Menulist clear!" << endl;
	}
}

void Menulist::draw(SDL_Renderer* renderer, bool clicked)
{
	if (menus.size() != 0) {
		Menu* menu = menus[menus.size() - 1];
		menu->draw(renderer, menu->x, menu->y, clicked);
	}
}


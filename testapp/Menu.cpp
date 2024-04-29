#include "Menu.h"

Menu::Menu(int width, int height)
{
	this->width = width;
	this->height = height;
}

Menu::~Menu()
{
	    for (Button button : buttons) {
        delete &button;
    }
    buttons.clear();
}

void Menu::place(int x, int y)
{
	this->x = x;
	this->y = y;
}

SDL_Texture* Menu::loadtexture(SDL_Renderer* renderer, const char *image) {

	surface = IMG_Load(image);
	if (surface == nullptr) {
		cout << "Can't load image: " << IMG_GetError() << endl;
	}
	else {
		texture = SDL_CreateTextureFromSurface(renderer, surface);
	}

	SDL_FreeSurface(surface);

	return texture;
}


void Menu::add_background(SDL_Renderer* renderer, string background_type, SDL_Color color, const char* image)
{
	if (background_type == "color") {
		background_color = color;
	}
	else if (background_type == "texture") {
		texture = loadtexture(renderer, image);
	}
	this->background_type = background_type;
}

void Menu::draw(SDL_Renderer* renderer, int x, int y, bool clicked)
{
	if (background_type == "color") {
		SDL_SetRenderDrawColor(renderer, background_color.r, background_color.g, background_color.b, background_color.a);

		rect = { x, y, width, height };

		SDL_RenderFillRect(renderer, &rect);
	}
	else if (background_type == "texture") {
		rect = { x, y, width, height };

		SDL_RenderCopy(renderer, texture, NULL, &rect);
	}

	if (buttons.size() != 0) {
		
		for (int i = 0; i < buttons.size(); i++) {
			Button button = buttons[i];
			button.draw(renderer, button.x, button.y, clicked);
		}
	}
}

void Menu::add_button(Button button)
{
	cout << buttons.size() << " ";
	buttons.push_back(button);
}

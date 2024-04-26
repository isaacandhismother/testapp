#include<SDL.h>
#include<SDL_image.h>

#include "Settings.h"
#include "Tile.h"
#include "Player.h"

#include<iostream>

SDL_Window* window = SDL_CreateWindow("Window", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, SDL_WINDOW_SHOWN);
SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

bool videoInitialised() {
	if (SDL_Init(SDL_INIT_VIDEO) <= 0)
		return true;
	std::cout << "Failed to initiate video" << SDL_GetError() << std::endl;
	return false;
}

bool windowCreatedSuccessfuly(SDL_Window* window) {
	if (window != NULL)
		return true;
	return false;
}

bool createdRenderer(SDL_Renderer* renderer) {
	if (renderer == NULL)
		return false;
	return true;
}

bool initImage() {
	int flags = IMG_INIT_PNG;
	if (!(IMG_Init(flags) & flags)) {
		std::cout << "Can't init image: " << IMG_GetError() << std::endl;
		return false;
	}
}


int main(int argc, char* args[]) {
	bool running = true;

	SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
	SDL_Surface* screenSurface = SDL_GetWindowSurface(window);

	// Creating payer object
	Player player(renderer, 100, 100, "Images/Isaac.png");
	player.place(100, 10);

	// Declaring viewprots
	SDL_Rect minimap_viewport = {20, 20, 200, 200};
	SDL_Rect default_viewport = { 0, 0, width, height };

	SDL_Event e;

	Uint32 frameStart, frameTime;

	SDL_Point point = { 1, 1 };

	while (running) {

		frameStart = SDL_GetTicks();

		while (SDL_PollEvent(&e)) {
			if (e.type == SDL_QUIT) running = false;

						
		}

		const Uint8* keys = SDL_GetKeyboardState(NULL);

		if (keys[SDL_SCANCODE_Q]) {
			player.rotate_left(1);
		}
		else if (keys[SDL_SCANCODE_E]) {
			player.rotate_right(1);
		}

		if (keys[SDL_SCANCODE_A]) { 
			player.go_left();
		}
		else if (keys[SDL_SCANCODE_D]) {
			player.go_right();
		}

		if (keys[SDL_SCANCODE_W]) {
			player.go_up();
		}
		else if (keys[SDL_SCANCODE_S]) {
			player.go_down();
		}

		// rendering the scene
			SDL_RenderClear(renderer);

			SDL_RenderSetViewport(renderer, &minimap_viewport);
		
				// Render here minimap
		
			SDL_RenderSetViewport(renderer, &default_viewport);

				// Render here all objects on the main screen space

				player.draw(renderer, player.x, player.y, player.rotation_angle, NULL);

			SDL_RenderPresent(renderer);

		// setting the framerate ??
		frameTime = SDL_GetTicks() - frameStart;
		if (frameTime < 1000) {
			SDL_Delay(1000 / fps);
		}
	}

	SDL_DestroyRenderer(renderer);
	renderer = NULL;

	SDL_DestroyWindow(window);
	window = NULL;

	SDL_Quit();
	IMG_Quit();

	return 0;
}

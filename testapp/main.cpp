#include "World.h"
#include "Player.h"

#include "Engine.h"

#include<iostream>

using namespace std;

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
	if (TTF_Init() == -1)
	{
		printf("SDL_ttf could not initialize! SDL_ttf Error: %s\n", TTF_GetError());
		return false;
	}
	bool running = true;

	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
	SDL_Surface* screenSurface = SDL_GetWindowSurface(window);

	// Creating game world
	//World world(32, 32);
	//world.generate_world(renderer);

	// Creating payer object
	//Player player(renderer, 100, 100, "Images/Isaac.png");
	//player.row = world.world_size[0] / 2;
	//player.column = world.world_size[1] / 2;
	//player.place((world.world_size[0] / 2) * tile_height, (world.world_size[1] / 2) * tile_width);

	// Declaring viewprots
	//SDL_Rect minimap_viewport = {20, 20, 200, 200};
	//SDL_Rect default_viewport = { 0, 0, width, height };

	Engine engine(renderer, 12, 12);

	SDL_Event e;

	Uint32 frameStart, frameTime;

	while (running) {

		frameStart = SDL_GetTicks();

		while (SDL_PollEvent(&e)) {
			if (e.type == SDL_QUIT) running = false;

						
		}

		// rendering the scene

		engine.run_engine(renderer);


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
	TTF_Quit();

	return 0;
}

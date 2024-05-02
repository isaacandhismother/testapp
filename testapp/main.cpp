#include "SetupMenu.h"
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

bool isLeftMouseClicked() {
	int x, y;
	Uint32 state = SDL_GetMouseState(&x, &y);
	return (state & SDL_BUTTON(SDL_BUTTON_LEFT)) != 0;
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

	SetupMenu setup_menu(renderer);

	// Creating game world
	World world(12, 12);
	world.generate_world(renderer);

	// Creating payer object
	Player player(renderer, 100, 100, "Images/Isaac.png");
	player.row = world.world_size[0] / 2;
	player.column = world.world_size[1] / 2;
	player.place((world.world_size[0] / 2) * tile_height, (world.world_size[1] / 2) * tile_width);

	// Declaring viewprots
	SDL_Rect minimap_viewport = {20, 20, 200, 200};
	SDL_Rect default_viewport = { 0, 0, width, height };

	Engine engine(renderer, 12, 12);

	SDL_Event e;

	bool left_clicked;

	Uint32 frameStart, frameTime;

	while (running) {

		frameStart = SDL_GetTicks();

		while (SDL_PollEvent(&e)) {
			if (e.type == SDL_QUIT) running = false;

						
		}

		const Uint8* keys = SDL_GetKeyboardState(NULL);

		left_clicked = isLeftMouseClicked();

		// rendering the scene
			
		SDL_RenderClear(renderer);

		if (setup_menu.menulist.is_empty()) {
		//	if (keys[SDL_SCANCODE_Q]) {
		//		player.rotate_left(1);
		//	}
		//	else if (keys[SDL_SCANCODE_E]) {
		//		player.rotate_right(1);
		//	}

		//	if (keys[SDL_SCANCODE_A]) {
		//		player.go_left();
		//		if (player.x - player.width / 2 < 0) {
		//			player.x = player.width / 2;
		//		}
		//	}
		//	else if (keys[SDL_SCANCODE_D]) {
		//		player.go_right();
		//		if (player.x - player.width / 2 > (world.world_size[0] - 1) * tile_width) {
		//			player.x = ((world.world_size[0] - 1) * tile_width) + player.width / 2;
		//		}
		//	}

		//	if (keys[SDL_SCANCODE_W]) {
		//		player.go_up();
		//		if (player.y < 0) {
		//			player.y = 0;
		//		}
		//	}
		//	else if (keys[SDL_SCANCODE_S]) {
		//		player.go_down();
		//		if (player.y > (world.world_size[1] - 1) * tile_height) {
		//			player.y = ((world.world_size[1] - 1) * tile_height);
		//		}
		//	}

		//	SDL_RenderSetViewport(renderer, &minimap_viewport);

		//	// Render here a minimap

		//	SDL_RenderSetViewport(renderer, &default_viewport);

		//	vector<int> first_tile = { player.row - tiles_per_screen[0] / 2, player.column - tiles_per_screen[1] / 2 };

		//	// cout << first_tile[0] << ", " << first_tile[1] << endl;

		//	for (int row = first_tile[0] - 1; row < (first_tile[0] + tiles_per_screen[0] + 1); row++) {
		//		for (int column = first_tile[1] - 1; column < (first_tile[1] + tiles_per_screen[1] + 1); column++) {
		//			world.draw(renderer, row, column, player.x, player.y);
		//		}
		//	}

		//	player.draw(renderer, screen_center[0], screen_center[1], player.rotation_angle, NULL);
		engine.run_engine(renderer);

		}

			SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
				setup_menu.menulist.draw(renderer, left_clicked);

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
	TTF_Quit();

	return 0;
}

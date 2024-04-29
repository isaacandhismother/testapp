#include "Engine.h"

Engine::Engine(SDL_Renderer* renderer, int rows, int columns)
{
	// Creating game world
	World world(rows, columns);
	//world.generate_world(renderer);

	// Creating payer object
	player = new Player(renderer, 100, 100, "Images/Isaac.png");
	player->row = world.world_size[0] / 2;
	player->column = world.world_size[1] / 2;
	player->place((world.world_size[0] / 2)* tile_height, (world.world_size[1] / 2)* tile_width);
}

Engine::~Engine()
{
}

void Engine::run_engine(SDL_Renderer* renderer)
{
	const Uint8* keys = SDL_GetKeyboardState(NULL);

	if (keys[SDL_SCANCODE_Q]) {
		player->rotate_left(1);
	}
	else if (keys[SDL_SCANCODE_E]) {
		player->rotate_right(1);
	}

	if (keys[SDL_SCANCODE_A]) {
		player->go_left();
		if (player->x - player->width / 2 < 0) {
			player->x = player->width / 2;
		}
	}
	else if (keys[SDL_SCANCODE_D]) {
		player->go_right();
		if (player->x - player->width / 2 > (world->world_size[0] - 1) * tile_width) {
			player->x = ((world->world_size[0] - 1) * tile_width) + player->width / 2;
		}
	}

	if (keys[SDL_SCANCODE_W]) {
		player->go_up();
		if (player->y < 0) {
			player->y = 0;
		}
	}
	else if (keys[SDL_SCANCODE_S]) {
		player->go_down();
		if (player->y > (world->world_size[1] - 1) * tile_height) {
			player->y = ((world->world_size[1] - 1) * tile_height);
		}
	}
	SDL_RenderClear(renderer);
	SDL_RenderSetViewport(renderer, &minimap_viewport);

	// Render here minimap

	SDL_RenderSetViewport(renderer, &default_viewport);

	vector<int> first_tile = { player->row - tiles_per_screen[0] / 2, player->column - tiles_per_screen[1] / 2 };

	// cout << first_tile[0] << ", " << first_tile[1] << endl;

	for (int row = first_tile[0] - 1; row < (first_tile[0] + tiles_per_screen[0] + 2); row++) {
		for (int column = first_tile[1] - 1; column < (first_tile[1] + tiles_per_screen[1] + 2); column++) {
			world->draw(renderer, row, column, player->x, player->y);
		}
	}

	player->draw(renderer, screen_center[0], screen_center[1], player->rotation_angle, NULL);
	SDL_RenderPresent(renderer);
}

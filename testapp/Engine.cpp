#include "Engine.h"

Engine::Engine(SDL_Renderer* renderer, int rows, int columns) :
	player(renderer, 100, 100, "Images/Isaac.png"),
	world(rows, columns),
	setup_menu(renderer)
{
	world.generate_world(renderer);

	// Creating payer object
	player.row = world.world_size[0] / 2;
	player.column = world.world_size[1] / 2;
	player.place((world.world_size[0] / 2)* tile_height, (world.world_size[1] / 2)* tile_width);
}

Engine::~Engine()
{
	cout << "engine destroyed" << endl;
}


bool Engine::isLeftMouseClicked() {
	int x, y;
	Uint32 state = SDL_GetMouseState(&x, &y);
	return (state & SDL_BUTTON(SDL_BUTTON_LEFT)) != 0;
}

void Engine::run_engine(SDL_Renderer* renderer)
{
	left_clicked = isLeftMouseClicked();

	const Uint8* keys = SDL_GetKeyboardState(NULL);

	if (keys[SDL_SCANCODE_Q]) {
		this->player.rotate_left(1);
	}
	else if (keys[SDL_SCANCODE_E]) {
		this->player.rotate_right(1);
	}

	if (keys[SDL_SCANCODE_A]) {
		this->player.go_left();
		if (this->player.x - this->player.width / 2 < 0) {
			this->player.x = this->player.width / 2;
		}
	}
	else if (keys[SDL_SCANCODE_D]) {
		player.go_right();
		if (this->player.x - this->player.width / 2 > (this->world.world_size[0] - 1) * tile_width) {
			this->player.x = ((this->world.world_size[0] - 1) * tile_width) + this->player.width / 2;
		}
	}

	if (keys[SDL_SCANCODE_W]) {
		this->player.go_up();
		if (this->player.y < 0) {
			this->player.y = 0;
		}
	}
	else if (keys[SDL_SCANCODE_S]) {
		this->player.go_down();
		if (this->player.y > (this->world.world_size[1] - 1) * tile_height) {
			this->player.y = ((this->world.world_size[1] - 1) * tile_height);
		}
	}
	else if (keys[SDL_SCANCODE_H]) {
		Chunk second_chunk(0, 0);
		second_chunk.load(renderer);
	}

	SDL_RenderClear(renderer);
	
	if (setup_menu.menulist.is_empty()) {

		SDL_RenderSetViewport(renderer, &minimap_viewport);

		// Render here minimap

		SDL_RenderSetViewport(renderer, &default_viewport);

		vector<int> first_tile = { this->player.row - tiles_per_screen[0] / 2, this->player.column - tiles_per_screen[1] / 2 };

		for (int row = first_tile[0] - 1; row < (first_tile[0] + tiles_per_screen[0] + 2); row++) {
			for (int column = first_tile[1] - 1; column < (first_tile[1] + tiles_per_screen[1] + 2); column++) {
				this->world.draw(renderer, row, column, this->player.x, this->player.y);
			}
		}

		this->player.draw(renderer, screen_center[0], screen_center[1], this->player.rotation_angle, NULL);

	}

	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
		setup_menu.menulist.draw(renderer, left_clicked);

	SDL_RenderPresent(renderer);
}

#include "SetupMenu.h"

SetupMenu::SetupMenu(SDL_Renderer* renderer):
{
	// Creating menus

	SDL_Color black = {0, 0, 0, 255};

	SDL_Color white = { 255, 255, 255,255 };

	SDL_Color grey = { 150, 150, 150, 255 };

	Menu main_menu.add_background(renderer, "color", white);
	main_menu.place(0, 0);
	menulist.add(main_menu);

	//Menu choose_savestate_menu(width, height);
	//choose_savestate_menu.place(0, 0);
	//Menu create_world_menu(width, height);
	//create_world_menu.place(0, 0);
	//Menu settings_menu(width, height);
	//settings_menu.place(0, 0);
	//Menu pause_menu(width, height);
	//pause_menu.place(0, 0);

	//menulist.add(&main_menu);

	Button play_button(renderer, 300, 50, black, white, 32);
	play_button.place((width / 2) - play_button.width / 2, 200);
	play_button.set_text(renderer, "Singleplayer");
	
	//main_menu.add_button(play_button);
	//play_button.set_function(add_create_world_menu);

		/*# savestates and savestate buttons
		savestate1 = SaveState('saves/save1')

		savestate1_button = Button(150, 220, 100, 120, 'Save \n1', 'black', 'white', 32)
		savestate1_button.type = 'savestate'
		savestate1_button.set_function(function = load_savestate_state, args = (savestate1, 1))

		delete_savestate1_button = Button(150, 320, 100, 50, 'Delete', 'black', 'white', 32)
		delete_savestate1_button.set_function(function = savestate1.delete_savestate, args = ())

		savestate2 = SaveState('saves/save2')

		savestate2_button = Button(350, 220, 100, 120, 'Save \n2', 'black', 'white', 32)
		savestate2_button.type = 'savestate'
		savestate2_button.set_function(function = load_savestate_state, args = (savestate2, 2))

		delete_savestate2_button = Button(350, 320, 100, 50, 'Delete', 'black', 'white', 32)
		delete_savestate2_button.set_function(function = savestate2.delete_savestate, args = ())

		savestate3 = SaveState('saves/save3')

		savestate3_button = Button(550, 220, 100, 120, 'Save \n3', 'black', 'white', 32)
		savestate3_button.type = 'savestate'
		savestate3_button.set_function(function = load_savestate_state, args = (savestate3, ))

		delete_savestate3_button = Button(550, 320, 100, 50, 'Delete', 'black', 'white', 32)
		delete_savestate3_button.set_function(function = savestate3.delete_savestate, args = ())*/

	//Button world_type_button(300, 50, black, white, 32);
	//world_type_button.place((width / 2) - play_button.width / 2, 320);
	//world_type_button.set_text("World type : ");
	//world_type_button.set_function(add_menu, create_world_menu);

	//Button create_world_button(220, 50, black, white, 32);
	//create_world_button.place(170, 530);
	//create_world_button.set_text("Create world");

		//resume_button = Button(pause_menu.width / 2, 200, 200, 50, 'Resume', 'black', 'white', 32)

		//settings_button = Button(main_menu.width / 2, 320, 200, 50, 'Settings', 'black', 'white', 32)
		//settings_button.set_function(function = add_menu, args = (settings_menu, ))

		//quit_button = Button(main_menu.width / 2, 420, 200, 50, 'Quit', 'black', 'white', 32)
		//quit_button.set_function(function = exit_game, args = ())

		//back_button = Button(650, 530, 200, 50, 'Back', 'black', 'white', 32)
		//back_button.set_function(function = remove_menu, args = ())

		//graphics_button = Button(main_menu.width / 2, 400, 200, 50, 'Graphics', 'black', 'white', 32)

		//back_to_game_button = Button(pause_menu.width / 2, 280, 250, 45, 'Back to game', 'black', 'white', 28)
		//back_to_game_button.set_function(function = unpause_game, args = (False, ))

		//quit_to_menu_button = Button(pause_menu.width / 2, 350, 250, 45, 'Main menu', 'black', 'white', 28)
		//quit_to_menu_button.set_function(function = quit_to_menu, args = ());

		// Main menu

	//main_menu.add_background(renderer, "color", grey);
	//main_menu.add_button(&play_button);
	//main_menu.add(settings_button);
	//main_menu.add(quit_button);

		// Play menu

	//choose_savestate_menu.add_background(renderer, 'color', 'lightblue');
	//choose_savestate_menu.add(savestate1_button);
	//choose_savestate_menu.add(delete_savestate1_button);
	//choose_savestate_menu.add(savestate2_button);
	//choose_savestate_menu.add(delete_savestate2_button);
	//choose_savestate_menu.add(savestate3_button);
	//choose_savestate_menu.add(delete_savestate3_button);
	//choose_savestate_menu.add(back_button);

		// World creation menu

	//create_world_menu.add_background(renderer, "color", { 50, 10, 10, 255 });
	//create_world_menu.add(back_button);
	//create_world_menu.add(create_world_button);
	//create_world_menu.add(world_type_button);

		// Settings menu

	//settings_menu.add_background(renderer, "color", { 0, 0, 255, 255 });
	//settings_menu.add(back_button);
	//settings_menu.add(graphics_button);

		// Pause menu

	//pause_menu.add_background(renderer, "color", { 0, 0, 0, 200 });
	//pause_menu.add(back_to_game_button);
	//pause_menu.add(quit_to_menu_button);
}

SetupMenu::~SetupMenu()
{
}

//void add_main_menu() {
//	Menu main_menu = main_menu;
//	menulist.add(&main_menu);
//};
//
//void add_create_world_menu() {
//	Menu create_world_menu = create_world_menu;
//	menulist.add(&create_world_menu);
//}

//void add_settings_menu() {
//	Menu setting_menu = settings_menu;
//	menulist.add(&settings_menu);
//};
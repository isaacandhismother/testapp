#pragma once

#include<SDL.h>
#include<SDL_image.h>
#include<SDL_ttf.h>
#include "Settings.h"

#include<iostream>
#include<string>
#include<vector>
#include<functional>
#include<tuple>

using namespace std;

class Button
{
public:
	Button(SDL_Renderer* renderer, int width, int height, SDL_Color background_color, SDL_Color text_color, int font_size);
	~Button();
    void place(int x, int y);
    void draw(SDL_Renderer* renderer, int x, int y, bool clicked);
    void set_text(const char* text);
    //void set_function(void (*func)());
    void set_function(function<void()> func);
    SDL_Texture* load_texttexture(SDL_Renderer* renderer, const char *text, SDL_Color text_color);
    int x, y, width, height;
    bool active = true;
    bool is_pressed = false;
    bool hover = false;
    const char* text;
private:
    int font_size;
    TTF_Font* font;
    SDL_Color background_color, default_background_color, text_color;
    SDL_Texture* text_texture;
    SDL_Surface* text_surface;
    SDL_Rect rect, text_rect;
    function<void()> callback_function;
    //void (*callback_function)();
};


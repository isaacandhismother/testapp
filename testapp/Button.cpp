#include "Button.h"

Button::Button(SDL_Renderer* renderer, int width, int height, SDL_Color background_color, SDL_Color text_color, int font_size)
    : width(width), height(height), background_color(background_color), text_color(text_color), font_size(font_size) 
{
    if (TTF_Init() == -1)
    {
        printf("SDL_ttf could not initialize! SDL_ttf Error: %s\n", TTF_GetError());
    }

    font = TTF_OpenFont("fonts/HmKeokuk.ttf", font_size);

    if (font == nullptr) {
        cout << TTF_GetError();
    }

    default_background_color = background_color;
}

Button::~Button()
{
    SDL_DestroyTexture(text_texture);
}

void Button::place(int x, int y)
{
    this->x = x;
    this->y = y;
}

SDL_Texture* Button::load_texttexture(SDL_Renderer* renderer, const char *text, SDL_Color text_color)
{
    text_surface = TTF_RenderText_Blended(font, text, text_color);
    if (text_surface == NULL) {
        cout << "Can't load texture: " << TTF_GetError() << endl;
    }
    else {
        text_texture = SDL_CreateTextureFromSurface(renderer, text_surface);
        if (text_texture == NULL) {
            cout << "Can't load texture: "<< SDL_GetError() << endl;
        }
    }

    SDL_FreeSurface(text_surface);

    return text_texture;
}

void Button::draw(SDL_Renderer* renderer, int x, int y, bool clicked)
{
    int mouse_x, mouse_y;
    SDL_GetMouseState(&mouse_x, &mouse_y);

    background_color = default_background_color;

    hover = false;
    background_color = default_background_color;

    if ((x < mouse_x && mouse_x < x + width) && (y < mouse_y && mouse_y < y + height)) {
        hover = true;
        background_color = { 128 ,128, 128, 255 };
    }

    if (!hover && clicked) {
        active = false;
    }

    if (hover && clicked) {
        is_pressed = false;
        cout<<"10"<<endl;
    }

    if (active) {

        if (is_pressed && !clicked) {
            cout << "2" <<endl;
        }
        //if (hover && !clicked) {
        //    cout<<"2";
        //    is_pressed = false;
        //}
        //if (!clicked && hover && is_pressed) {
        //    
        //    if (function) {
        //        cout << "Clicked" << endl;
        //        function();
        //        is_pressed = false;
        //    }
        //}
    }

    if (!clicked) {
        active = true;
    }

    SDL_SetRenderDrawColor(renderer, background_color.r, background_color.g, background_color.b, background_color.a);

    rect = { x, y, width, height };

    SDL_RenderFillRect(renderer, &rect);

    text_texture = load_texttexture(renderer, text, text_color);

    text_rect = { x, y, width, height};

    SDL_QueryTexture(text_texture, nullptr, nullptr, NULL, NULL);

    SDL_RenderCopy(renderer, text_texture, NULL, &text_rect);
    
    SDL_DestroyTexture(text_texture);
}

void Button::set_text(SDL_Renderer* renderer, const char *text)
{
    this->text = text;
}

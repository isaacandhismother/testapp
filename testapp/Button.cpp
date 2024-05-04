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
    cout << "button destroyed" << endl;
    SDL_DestroyTexture(text_texture);
}

void Button::place(int x, int y)
{
    this->x = x;
    this->y = y;
}

void Button::set_function(function<void()> func) {
    callback_function = func;
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

    this->hover = false;
    background_color = default_background_color;

    if ((x < mouse_x && mouse_x < x + width) && (y < mouse_y && mouse_y < y + height)) {
        this->hover = true;
        background_color = { 128 ,128, 128, 255 };
    }

    if (!this->hover && clicked) {
        this->active = false;
    }

    if (this->active) {
        if (this->hover && clicked) {
            this->is_pressed = true;
        }
        else if (!clicked && this->is_pressed && this->hover) {
            this->is_pressed = false;
            if (callback_function) {
                callback_function();
            }
        }
        else {
            this->is_pressed = false;
        }
    }

    if (!clicked) {
        this->active = true;
    }

    SDL_SetRenderDrawColor(renderer, background_color.r, background_color.g, background_color.b, background_color.a);

    rect = { x, y, width, height };

    SDL_RenderFillRect(renderer, &rect);

    text_texture = load_texttexture(renderer, text, text_color);

    text_rect = { x, y, width, height};

    SDL_QueryTexture(text_texture, nullptr, nullptr, &text_rect.w, &text_rect.h);

    text_rect.x += width / 2 - text_rect.w / 2;
    text_rect.y += height / 2 - text_rect.h / 2;

    SDL_RenderCopy(renderer, text_texture, NULL, &text_rect);
    
    SDL_DestroyTexture(text_texture);
}

void Button::set_text(const char *text)
{
    this->text = text;
}

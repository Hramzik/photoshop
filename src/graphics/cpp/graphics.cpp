

//--------------------------------------------------


#include "../hpp/graphics.hpp"
#include "../../lib/logs.hpp"


//--------------------------------------------------


Graphic_Window::Graphic_Window (void):
        window_   (nullptr),
        renderer_ (nullptr) {

    window_ = SDL_CreateWindow (
            "", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
            DEFAULT_WINDOW_WIDTH, DEFAULT_WINDOW_HEIGHT, 
            OUTPUT_FLAGS); // empty header

    if(!window_) {

        LOG_MESSAGE ("Window could not be created!\n");
        return;
    }

    //--------------------------------------------------

    renderer_ = SDL_CreateRenderer(window_, -1, SDL_RENDERER_ACCELERATED);

    if (!renderer_) {

        LOG_MESSAGE ("Renderer could not be created!");
        return;
    }
}


//--------------------------------------------------

int Graphic_Window::get_width (void) const {

    int width = 0;


    SDL_GetWindowSize (window_, &width, nullptr);


    return width;
}


int Graphic_Window::get_height (void) const {

    int height = 0;


    SDL_GetWindowSize (window_, nullptr, &height);


    return height;
}

//--------------------------------------------------

void Graphic_Window::set_drawcolor (My_RGB color) {

    SDL_SetRenderDrawColor (renderer_, color.r, color.g, color.b, 0);
}


void Graphic_Window::clear_screen (void) {

    set_drawcolor   (DEFAULT_BACKGROUND_COLOR);
    SDL_RenderClear (renderer_);
}


void Graphic_Window::update_screen (void) {

    SDL_RenderPresent (renderer_);
}

//--------------------------------------------------

void Graphic_Window::draw_point (int x, int y) {

    SDL_RenderDrawPoint (renderer_, x, y);
}


void Graphic_Window::draw_line (int x1, int y1, int x2, int y2) {

    SDL_RenderDrawLine (renderer_, x1, y1, x2, y2);
}


void Graphic_Window::draw_rect (SDL_Rect rect) {

    SDL_RenderFillRect (renderer_, &rect);
}

//--------------------------------------------------

void Graphic_Window::render_texture (SDL_Texture* texture, SDL_Rect render_rect) {

    render_texture (texture, &render_rect);
}


void Graphic_Window::render_texture (SDL_Texture* texture, SDL_Rect* render_rect) {

    SDL_RenderCopy (renderer_, texture, nullptr, render_rect);
}

//--------------------------------------------------



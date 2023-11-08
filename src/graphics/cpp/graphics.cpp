

//--------------------------------------------------

#include "../hpp/graphics.hpp"
#include "../../lib/logs.hpp"

//--------------------------------------------------

Graphic_Window::Graphic_Window (Uint32 sdl_flags):
        window_   (nullptr),
        renderer_ (nullptr),
        surface_  (nullptr),

        current_coordinates_ (CARTESIAN_COORDS),

        background_color_ (DEFAULT_BACKGROUND_COLOR)
{
    window_ = SDL_CreateWindow (
            "", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
            DEFAULT_WINDOW_WIDTH, DEFAULT_WINDOW_HEIGHT, 
            OUTPUT_FLAGS | sdl_flags); // empty header

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

    //--------------------------------------------------

    surface_ = SDL_GetWindowSurface (window_);

    if (!surface_) {

        LOG_MESSAGE ("Surface could not be created!");
        return;
    }
}


Graphic_Window::Graphic_Window (void):
        Graphic_Window (0) {}

//--------------------------------------------------

void Graphic_Window::set_fullscreen (bool is_fullscreen) {

    if (!is_fullscreen) {

        SDL_SetWindowFullscreen (window_, 0);
        return;
    }

    //--------------------------------------------------

    SDL_SetWindowFullscreen (window_, SDL_WINDOW_FULLSCREEN_DESKTOP);
}

//--------------------------------------------------

void Graphic_Window::convert_to_sdl_coords (int& x, int& y) { (void) x, (void) y;

    if (current_coordinates_ == SDL_COORDS) return;

    //--------------------------------------------------

    y = get_height () - y;
}


void Graphic_Window::convert_to_sdl_coords (SDL_Rect& rect) {

    if (current_coordinates_ == SDL_COORDS) return;

    //--------------------------------------------------

    convert_to_sdl_coords (rect.x, rect.y); // correct left bottom
    rect.y -= rect.h;                       // correct left top
}


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


void Graphic_Window::set_background_color (My_RGB color) {

    background_color_ = color;
}


void Graphic_Window::clear_screen (void) {

    set_drawcolor   (background_color_);
    SDL_RenderClear (renderer_);
}


void Graphic_Window::update_screen (void) {

    SDL_RenderPresent (renderer_);
}

//--------------------------------------------------

void Graphic_Window::draw_point (int x, int y) {

    convert_to_sdl_coords (x, y);

    //--------------------------------------------------

    SDL_RenderDrawPoint (renderer_, x, y);
}


void Graphic_Window::draw_line (int x1, int y1, int x2, int y2) {

    convert_to_sdl_coords (x1, y1);
    convert_to_sdl_coords (x2, y2);

    //--------------------------------------------------

    SDL_RenderDrawLine (renderer_, x1, y1, x2, y2);
}


void Graphic_Window::draw_rect (SDL_Rect rect, bool is_filled) {

    if (is_filled) draw_rect (rect);

    //--------------------------------------------------

    draw_rect_outline (rect);
}


void Graphic_Window::draw_rect (SDL_Rect rect) {

    convert_to_sdl_coords (rect);

    //--------------------------------------------------

    SDL_RenderFillRect (renderer_, &rect);
}


void Graphic_Window::draw_rect_outline (SDL_Rect rect) {

    convert_to_sdl_coords (rect);

    //--------------------------------------------------

    SDL_RenderDrawRect (renderer_, &rect);
}

//--------------------------------------------------

void Graphic_Window::render_texture_sdl_coords
(SDL_Texture* texture, SDL_Rect* render_rect)
{
    SDL_RenderCopy (renderer_, texture, nullptr, render_rect);
}


// все происходит именно в этой версии функции, поскольку
// для конвертации нужна копия прямоугольника
void Graphic_Window::render_texture (SDL_Texture* texture, SDL_Rect render_rect) {

    convert_to_sdl_coords (render_rect);

    //--------------------------------------------------

    SDL_RenderCopy (renderer_, texture, nullptr, &render_rect);
}


void Graphic_Window::render_texture (SDL_Texture* texture, SDL_Rect* render_rect) {

    // рисуем в sdl-овских координатах на весь экран
    if (!render_rect) render_texture_sdl_coords (texture);

    //--------------------------------------------------

    // переводим координаты, используя копию прямоугольника
    render_texture (texture, *render_rect);
}


void Graphic_Window::render_texture (My_Texture& texture, SDL_Rect render_rect) {

    render_texture (texture, &render_rect);
}


void Graphic_Window::render_texture (My_Texture& texture, SDL_Rect* render_rect) {

    SDL_Surface* surface = texture.get_surface ();
    SDL_Texture* sdl_texture = SDL_CreateTextureFromSurface (renderer_, surface);

    //--------------------------------------------------

    // coords conversation happens inside
    render_texture (sdl_texture, render_rect);

    //--------------------------------------------------

    SDL_DestroyTexture (sdl_texture);
}

//--------------------------------------------------


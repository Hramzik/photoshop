

//--------------------------------------------------

#include "../hpp/graphics.hpp"

//--------------------------------------------------

const My_RGB My_Texture::DEFAULT_FILL_COLOR = C_WHITE;

//--------------------------------------------------

My_Texture::My_Texture (Vector2D size):
        surface_       (nullptr),
        sdl_drawcolor_ (0),

        current_coordinates_ (CARTESIAN_COORDS)
{
    // first argument is always 0
    // 32 = bits per pixel
    // last 4 zeroes = default pixel mask
    surface_ = SDL_CreateRGBSurface (0, (int) size.x, (int) size.y, 32, 0, 0, 0, 0);

    //--------------------------------------------------

    set_drawcolor (DEFAULT_FILL_COLOR);
    draw_rect (Point2D (0), Point2D (surface_->w, surface_->h));
}

//--------------------------------------------------

void My_Texture::convert_to_sdl_coords (int& x, int& y) {

    (void) x;

    //--------------------------------------------------

    if (current_coordinates_ == SDL_COORDS) return;

    //--------------------------------------------------

    y = surface_->h - y;
}

//--------------------------------------------------

SDL_Surface* My_Texture::get_surface (void) {

    return surface_;
}

//--------------------------------------------------

void My_Texture::set_drawcolor (My_RGB color) {

    sdl_drawcolor_ = SDL_MapRGB (surface_->format, color.r, color.g, color.b);
}


void My_Texture::draw_point (Point2D point) {

    SDL_Point sdl_point;
    sdl_point.x = (int) point.x;
    sdl_point.y = (int) point.y;

    convert_to_sdl_coords (sdl_point.x, sdl_point.y);

    //--------------------------------------------------

    SDL_Rect draw_rect;
    draw_rect.x = sdl_point.x;
    draw_rect.y = sdl_point.y;
    draw_rect.w = 1;
    draw_rect.h = 1;

    //--------------------------------------------------

    SDL_FillRect (surface_, &draw_rect, sdl_drawcolor_);
}


void My_Texture::draw_rect (Point2D point1, Point2D point2) {

    SDL_Point sdl_point1;
    SDL_Point sdl_point2;
    sdl_point1.x = (int) point1.x;
    sdl_point1.y = (int) point1.y;
    sdl_point2.x = (int) point2.x;
    sdl_point2.y = (int) point2.y;

    convert_to_sdl_coords (sdl_point1.x, sdl_point1.y);
    convert_to_sdl_coords (sdl_point2.x, sdl_point2.y);

    //--------------------------------------------------

    SDL_Rect draw_rect;
    draw_rect.x = std::min (sdl_point1.x,  sdl_point2.x);
    draw_rect.y = std::min (sdl_point1.y,  sdl_point2.y);
    draw_rect.w = std::abs (sdl_point1.x - sdl_point2.x);
    draw_rect.h = std::abs (sdl_point1.y - sdl_point2.y);

    //--------------------------------------------------

    SDL_FillRect (surface_, &draw_rect, sdl_drawcolor_);
}
//--------------------------------------------------


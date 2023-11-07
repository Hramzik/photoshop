

//--------------------------------------------------

#include "../../lib/my_math.hpp"

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


My_RGB My_Texture::get_pixel (int x, int y) {

    convert_to_sdl_coords (x, y);

    //--------------------------------------------------

    const char bytes_per_pixel = surface_->format->BytesPerPixel;
    char* pixel_ptr = (char*) surface_->pixels + y * surface_->pitch + x * bytes_per_pixel;
    Uint32 pixel = *(Uint32*) pixel_ptr;

    //--------------------------------------------------

    My_RGB pixel_color;
    SDL_GetRGB (pixel, surface_->format, &pixel_color.r, &pixel_color.g, &pixel_color.b);


    return pixel_color;
}

//--------------------------------------------------

void My_Texture::set_drawcolor (My_RGB color) {

    sdl_drawcolor_ = SDL_MapRGB (surface_->format, color.r, color.g, color.b);
}


void My_Texture::draw_point (Point2D point) {

    draw_point ((int) point.x, (int) point.y);
}


void My_Texture::draw_point (int x, int y) {

    convert_to_sdl_coords (x, y);

    //--------------------------------------------------

    SDL_Rect draw_rect;
    draw_rect.x = x;
    draw_rect.y = y;
    draw_rect.w = 1;
    draw_rect.h = 1;

    //--------------------------------------------------

    SDL_FillRect (surface_, &draw_rect, sdl_drawcolor_);
}


void My_Texture::draw_rect (Point2D point1, Point2D point2, bool is_filled) {

    if (is_filled) draw_rect (point1, point2);

    //--------------------------------------------------

    draw_rect_outline (point1, point2);
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

    ensure_is_not_less_than (draw_rect.w, 1);
    ensure_is_not_less_than (draw_rect.h, 1);

    //--------------------------------------------------

    SDL_FillRect (surface_, &draw_rect, sdl_drawcolor_);
}


void My_Texture::draw_rect_outline (Point2D point1, Point2D point2) {

    // 4 points = 4 rectangle angles

    Point2D point3 (point1.x, point2.y);
    Point2D point4 (point2.x, point1.y);

    //--------------------------------------------------

    draw_rect (point1, point3);
    draw_rect (point1, point4);
    draw_rect (point2, point3);
    draw_rect (point2, point4);
}

//--------------------------------------------------

void My_Texture::load_from_file (const char* path) {

    if (!path) return;

    //--------------------------------------------------

    SDL_Surface* temp_surface = IMG_Load (path);

    if(!temp_surface) {

        LOG_MESSAGE ("Unable to load image!\n");
        return;
    }

    //--------------------------------------------------

    SDL_BlitScaled (temp_surface, nullptr, surface_, nullptr);

    //--------------------------------------------------

    SDL_FreeSurface (temp_surface);
}

//--------------------------------------------------


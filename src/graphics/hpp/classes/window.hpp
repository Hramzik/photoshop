#ifndef GRAPHICS_CLASSES_WINDOW_HPP_INCLUDED
#define GRAPHICS_CLASSES_WINDOW_HPP_INCLUDED
//--------------------------------------------------

#include "../../../my_rgb/hpp/my_rgb.hpp"

#include "../sdl.hpp"
#include "../enums.hpp"

#include "texture.hpp"

//--------------------------------------------------


class Graphic_Window {

    static inline const My_RGB DEFAULT_BACKGROUND_COLOR = C_GRAY;

    //--------------------------------------------------

    SDL_Window*   window_;
    SDL_Renderer* renderer_;
    SDL_Surface*  surface_;

    Coordinate_System current_coordinates_;

    My_RGB background_color_;

//--------------------------------------------------

    void convert_to_sdl_coords (int& x, int& y);
    void convert_to_sdl_coords (SDL_Rect& rect);

    void render_texture_sdl_coords
            (SDL_Texture* texture, SDL_Rect* render_rect = nullptr);

//--------------------------------------------------

  public:

    Graphic_Window (void);

//--------------------------------------------------

    SDL_Texture* load_texture
            (const char* path, bool transparent_flag = false, My_RGB clr = C_WHITE) const;

//--------------------------------------------------

    int get_width  (void) const;
    int get_height (void) const;

    void set_drawcolor (My_RGB color);
    void set_background_color (My_RGB color);
    void clear_screen  (void);
    void update_screen (void);

// все рисование происходит в текущих координатах (current_coordinates_)
    void draw_point (int x,  int y);
    void draw_line  (int x1, int y1, int x2, int y2);
    void draw_rect  (SDL_Rect rect);

    void render_texture (SDL_Texture* texture, SDL_Rect  render_rect);
    void render_texture (SDL_Texture* texture, SDL_Rect* render_rect = nullptr);
    void render_texture (My_Texture&  texture, SDL_Rect  render_rect);
    void render_texture (My_Texture&  texture, SDL_Rect* render_rect = nullptr);
};


//--------------------------------------------------
#endif
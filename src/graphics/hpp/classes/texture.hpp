#ifndef GRAPHICS_CLASS_MY_TEXTURE_HPP_INCLUDED
#define GRAPHICS_CLASS_MY_TEXTURE_HPP_INCLUDED
//--------------------------------------------------

#include "../../../my_rgb/hpp/my_rgb.hpp"
#include "../../../vector/hpp/vector.hpp"

#include "../sdl.hpp"
#include "../enums.hpp"

//--------------------------------------------------


class My_Texture {

  public:

    static const My_RGB DEFAULT_FILL_COLOR;

    //--------------------------------------------------

    My_Texture (Vector2D size);

    //--------------------------------------------------

    void set_drawcolor (My_RGB color);
    void draw_point    (Point2D point);
    void draw_point    (int x, int y);

    // as in sdl, minimal width and height is 1
    void draw_rect         (Point2D point1, Point2D point2, bool is_filled);
    void draw_rect         (Point2D point1, Point2D point2);
    void draw_rect_outline (Point2D point1, Point2D point2);

    void load_from_file (const char* path);

    SDL_Surface* get_surface (void);
    My_RGB       get_pixel   (int x, int y);

//--------------------------------------------------

  private:

    SDL_Surface* surface_;
    Uint32 sdl_drawcolor_;

    Coordinate_System current_coordinates_;

    //--------------------------------------------------

    void convert_to_sdl_coords (int& x, int& y);
};


//--------------------------------------------------
#endif
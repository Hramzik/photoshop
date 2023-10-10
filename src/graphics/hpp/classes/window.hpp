#ifndef GRAPHICS_CLASSES_WINDOW_HPP_INCLUDED
#define GRAPHICS_CLASSES_WINDOW_HPP_INCLUDED
//--------------------------------------------------


#include "../sdl.hpp"
#include "../../../my_rgb/hpp/my_rgb.hpp"


//--------------------------------------------------


class Graphic_Window {

    SDL_Window*   window_;
    SDL_Renderer* renderer_;

//--------------------------------------------------

    static inline const My_RGB DEFAULT_BACKGROUND_COLOR = C_GRAY;

//--------------------------------------------------

  public:
    Graphic_Window (void);

//--------------------------------------------------

    SDL_Texture* load_texture (const char* path, bool transparent_flag = false, My_RGB clr = C_WHITE);

//--------------------------------------------------

    int get_width  (void);
    int get_height (void);

    void set_drawcolor (My_RGB color);
    void clear_screen  (void);
    void update_screen (void);

    void draw_point (int x,  int y);
    void draw_line  (int x1, int y1, int x2, int y2);
    void draw_rect  (SDL_Rect rect);

    void render_texture (SDL_Texture* texture, SDL_Rect render_rect);
};


//--------------------------------------------------
#endif
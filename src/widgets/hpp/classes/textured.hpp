#ifndef WIDGETS_CLASSES_TEXTURED_HPP_INCLUDED
#define WIDGETS_CLASSES_TEXTURED_HPP_INCLUDED
//--------------------------------------------------

#include "window.hpp"

#include "../../../graphics/hpp/graphics.hpp"

//--------------------------------------------------


class Textured_Window: public Window {

  public:

    Textured_Window (double width, double height);

    void load_texture (const char* path, const Graphic_Window& loader);
    void render (Graphic_Window& window, Transform_Stack& transform);

    SDL_Texture* get_texture (void);
    void         set_texture (SDL_Texture* texture);

    //--------------------------------------------------

    Textured_Window (const Textured_Window&) = delete;
    void  operator= (const Textured_Window&) = delete;

  protected:

    SDL_Texture* texture_;
};


//--------------------------------------------------
#endif
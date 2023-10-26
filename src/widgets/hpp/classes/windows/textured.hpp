#ifndef WIDGETS_CLASS_TEXTURED_WINDOW_HPP_INCLUDED
#define WIDGETS_CLASS_TEXTURED_WINDOW_HPP_INCLUDED
//--------------------------------------------------

#include "window.hpp"

#include "../../../../graphics/hpp/graphics.hpp"

//--------------------------------------------------


class Textured_Window: public Window {

  public:

    Textured_Window (double width, double height);

    void load_texture (const char* path, const Graphic_Window& loader);

    SDL_Texture* get_texture (void);
    void         set_texture (SDL_Texture* texture);

    //--------------------------------------------------

    Textured_Window (const Textured_Window&) = delete;
    void  operator= (const Textured_Window&) = delete;

//--------------------------------------------------

  protected:

    void render_with_final_transform
            (Graphic_Window& window, const Transform& result_transform) override;

    //--------------------------------------------------

    SDL_Texture* texture_;
};


//--------------------------------------------------
#endif
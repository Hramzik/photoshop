#ifndef WIDGETS_CLASS_TEXTURED_WINDOW_HPP_INCLUDED
#define WIDGETS_CLASS_TEXTURED_WINDOW_HPP_INCLUDED
//--------------------------------------------------

#include "window.hpp"

#include "../../../../graphics/hpp/graphics.hpp"

//--------------------------------------------------


class Textured_Window: public Window {

  public:

    Textured_Window (Point2D position, Vector2D size, const char* path);

    //--------------------------------------------------

    SDL_Texture* get_texture (void);
    void         set_texture (SDL_Texture* texture);

    //--------------------------------------------------

    Textured_Window (const Textured_Window&) = delete;
    void  operator= (const Textured_Window&) = delete;

//--------------------------------------------------

  protected:

    void render_with_final_transform
    (Graphic_Window& window, const Transform& result_transform)
    override;

    Processing_result on_mouse_pressed
    (Point2D mouse_position, Transform_Stack& stack)
    override;

    //--------------------------------------------------

    My_Texture texture_;
};


//--------------------------------------------------
#endif
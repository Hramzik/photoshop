#ifndef WIDGETS_CLASS_COLORED_WINDOW_HPP_INCLUDED
#define WIDGETS_CLASS_COLORED_WINDOW_HPP_INCLUDED
//--------------------------------------------------

#include "window.hpp"

#include "../../../../graphics/hpp/graphics.hpp"
#include "../../../../my_rgb/hpp/my_rgb.hpp"

//--------------------------------------------------


class Colored_Window: public Window {

  public:

    Colored_Window (Vector2D position, Vector2D size, My_RGB color);

    void render (Graphic_Window& window, Transform_Stack& transform);

    //--------------------------------------------------

  protected:

    My_RGB color_;
};


//--------------------------------------------------
#endif
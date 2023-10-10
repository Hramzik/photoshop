#ifndef WIDGETS_CLASS_WIDGET_HPP_INCLUDED
#define WIDGETS_CLASS_WIDGET_HPP_INCLUDED
//--------------------------------------------------

#include "../../../graphics/hpp/graphics.hpp"

//--------------------------------------------------

#include "../enums.hpp"

//--------------------------------------------------


class Widget {

  public:

    virtual void render (Graphic_Window window/*, Stack transform*/);

    virtual Processing_result on_mouse_move    (int mouse_x, int mouse_y);
    virtual Processing_result on_mouse_press   (int mouse_x, int mouse_y);
    virtual Processing_result on_mouse_release (int mouse_x, int mouse_y);

    virtual Processing_result on_keyboard_press   (SDL_Keycode key);
    virtual Processing_result on_keyboard_release (SDL_Keycode key);

    virtual Processing_result on_timer (clock_t current_time);
};


//--------------------------------------------------
#endif
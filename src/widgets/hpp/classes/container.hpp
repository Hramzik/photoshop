#ifndef WIDGETS_CLASS_CONTAINER_HPP_INCLUDED
#define WIDGETS_CLASS_CONTAINER_HPP_INCLUDED
//--------------------------------------------------

#include <vector>
#include <list>

//--------------------------------------------------

#include "widget.hpp"

//--------------------------------------------------


class Widget_Container: public Widget {

    std::list <Widget> widgets_;

  public:

    Processing_result on_mouse_move    (int mouse_x, int mouse_y) override;
    Processing_result on_mouse_press   (int mouse_x, int mouse_y) override;
    Processing_result on_mouse_release (int mouse_x, int mouse_y) override;

    Processing_result on_keyboard_press   (SDL_Keycode key) override;
    Processing_result on_keyboard_release (SDL_Keycode key) override;

    Processing_result on_timer (clock_t current_time) override;
};


//--------------------------------------------------
#endif
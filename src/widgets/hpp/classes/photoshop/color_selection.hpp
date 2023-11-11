#ifndef WIDGETS_CLASS_COLOR_SELECTION_HPP_INCLUDED
#define WIDGETS_CLASS_COLOR_SELECTION_HPP_INCLUDED
//--------------------------------------------------

#include "../../../../my_rgb/hpp/my_rgb.hpp"

#include "../framed_window/framed_window.hpp"
#include "../buttons/button_manager.hpp"

//--------------------------------------------------


class Color_Selection_Widget: public Framed_Window {

  public:

    Color_Selection_Widget (Point2D position, Vector2D size, Tool_Palette& palette);

    //--------------------------------------------------

    void add_color_selection_button (My_RGB color);

//--------------------------------------------------

  private:

    Tool_Palette&  palette_;
    Button_Manager buttons_;
};

//--------------------------------------------------
#endif
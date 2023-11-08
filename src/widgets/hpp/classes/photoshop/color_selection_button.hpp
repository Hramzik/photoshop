#ifndef WIDGETS_CLASS_COLOR_SELECTION_BUTTON_HPP_INCLUDED
#define WIDGETS_CLASS_COLOR_SELECTION_BUTTON_HPP_INCLUDED
//--------------------------------------------------

#include "../buttons/button.hpp"

//--------------------------------------------------

class Tool_Palette;

//--------------------------------------------------

class Color_Selection_Button: public Button {

  public:

    Color_Selection_Button
    (Point2D position, Vector2D size, My_RGB color, Tool_Palette& palette);

    //--------------------------------------------------

    void do_when_pressed (void) override;

//--------------------------------------------------

  private:

    My_RGB color_;
    Tool_Palette& palette_;
};


//--------------------------------------------------
#endif
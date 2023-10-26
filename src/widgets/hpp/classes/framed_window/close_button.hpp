#ifndef WIDGET_CLASS_CLOSE_BUTTON_HPP_INCLUDED
#define WIDGET_CLASS_CLOSE_BUTTON_HPP_INCLUDED
//--------------------------------------------------

#include "../buttons/buttons.hpp"

//--------------------------------------------------


// CURRENTLY NOT USED, LEFT AS A PROTOTYPE
class Close_Button: public Button {

  public:

    static const double DEFAULT_COLOR;

    static const double DEFAULT_WIDTH;
 // static const double DEFAULT_HEIGHT = FRAME_HEIGHT

    //--------------------------------------------------

    Close_Button (Widget* controlled);

    //--------------------------------------------------

    Processing_result on_mouse_pressed (int mouse_x, int mouse_y) override;

//--------------------------------------------------

  private:

    Widget* controlled;
};


//--------------------------------------------------
#endif
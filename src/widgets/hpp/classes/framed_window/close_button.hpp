#ifndef WIDGET_CLASS_CLOSE_BUTTON_HPP_INCLUDED
#define WIDGET_CLASS_CLOSE_BUTTON_HPP_INCLUDED
//--------------------------------------------------

#include "../buttons/colored.hpp"

//--------------------------------------------------


class Close_Button: public Colored_Button {

  public:

    static const double DEFAULT_WIDTH;
    //                  DEFAULT_HEIGHT = FRAME_HEIGHT

    //--------------------------------------------------

    Close_Button (Widget* controlled);

    //--------------------------------------------------

    void on_mouse_pressed (int mouse_x, int mouse_y) override;

//--------------------------------------------------

  private:

    Widget* controlled;
};


//--------------------------------------------------
#endif
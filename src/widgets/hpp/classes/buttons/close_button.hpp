#ifndef WIDGET_CLASS_CLOSE_BUTTON_HPP_INCLUDED
#define WIDGET_CLASS_CLOSE_BUTTON_HPP_INCLUDED
//--------------------------------------------------

#include "button.hpp"

//--------------------------------------------------

class Close_Button: public Button {

  public:

    static const My_RGB DEFAULT_COLOR;
    static const double DEFAULT_WIDTH;
    static const double DEFAULT_HEIGHT;

    //--------------------------------------------------

    Close_Button (Point2D position, Widget& controlled);

    Close_Button (Close_Button&) = delete;
    operator=    (Close_Button&) = delete;

    //--------------------------------------------------

    void do_when_pressed (void) override;

//--------------------------------------------------

  private:

    Widget& controlled_;
};


//--------------------------------------------------
#endif
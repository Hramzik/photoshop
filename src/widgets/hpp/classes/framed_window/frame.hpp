#ifndef WIDGETS_CLASS_WINDOW_FRAME_HPP_INCLUDED
#define WIDGETS_CLASS_WINDOW_FRAME_HPP_INCLUDED
//--------------------------------------------------

#include "my_rgb/hpp/my_rgb.hpp"

#include "widgets/hpp/classes/container.hpp"
#include "widgets/hpp/classes/buttons/button.hpp"

//--------------------------------------------------


class Window_Frame: public Widget_Container {

  public:

    static const My_RGB DEFAULT_FRAME_COLOR;
    static const My_RGB DEFAULT_CLOSE_BUTTON_COLOR;
    static const double DEFAULT_FRAME_HEIGHT;
    static const double DEFAULT_CLOSE_BUTTON_WIDTH;

    //--------------------------------------------------

    // !controlled must have matching global scale!
    Window_Frame (My_Widget& controlled, My_Widget& model);

    Window_Frame (const Window_Frame&) = delete;
    operator=    (const Window_Frame&) = delete;

//--------------------------------------------------

  private:

    Button* close_button_;
    Button* top_frame_;
};


//--------------------------------------------------
#endif
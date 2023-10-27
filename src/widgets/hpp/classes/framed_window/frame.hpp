#ifndef WIDGETS_CLASS_WINDOW_FRAME_HPP_INCLUDED
#define WIDGETS_CLASS_WINDOW_FRAME_HPP_INCLUDED
//--------------------------------------------------

#include "../windows/windows.hpp"
#include "../container.hpp"
#include "../buttons/buttons.hpp"

#include "movement_frame.hpp"

//--------------------------------------------------


class Window_Frame: public Widget_Container {

  public:

    static const My_RGB DEFAULT_FRAME_COLOR;
    static const double DEFAULT_FRAME_HEIGHT;

    //--------------------------------------------------

    // !controlled must have matching global scale!
    Window_Frame (Widget& controlled, Window& model);

    Window_Frame (const Window_Frame&) = delete;
    operator=    (const Window_Frame&) = delete;

//--------------------------------------------------

  private:

    Button*         close_button_;
    Movement_Frame* top_frame_;
};


//--------------------------------------------------
#endif
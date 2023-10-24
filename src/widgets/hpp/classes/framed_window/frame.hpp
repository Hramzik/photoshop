#ifndef WIDGETS_CLASS_FRAMED_WINDOW_HPP_INCLUDED
#define WIDGETS_CLASS_FRAMED_WINDOW_HPP_INCLUDED
//--------------------------------------------------

#include "../windows/windows.hpp"
#include "../container.hpp"

#include "close_button.hpp"

//--------------------------------------------------


class Window_Frame: public Widget_Container {

  public:

    Window_Frame (Window model);

  private:

    Button& close_button;
    Colored_Window& top_frame;
};


//--------------------------------------------------
#endif
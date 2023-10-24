#ifndef WIDGETS_CLASS_FRAMED_WINDOW_HPP_INCLUDED
#define WIDGETS_CLASS_FRAMED_WINDOW_HPP_INCLUDED
//--------------------------------------------------

#include "window.hpp"
#include "container.hpp"
#include "buttons/buttons.hpp"

//--------------------------------------------------


class Framed_Window: public Widget_Container {

  public:

    static const double FRAME_HEIGHT;

    //--------------------------------------------------

    Framed_Window (Window* window);

//--------------------------------------------------

  protected:

    Window*       window_;
    Window_Frame* frame_;
};


class Window_Frame: public Widget_Container {

  public:

    Window_Frame (const Window& model);

  protected:

    Button& close_button;
};







//--------------------------------------------------
#endif
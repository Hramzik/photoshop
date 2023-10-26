#ifndef WIDGETS_CLASS_FRAMED_WINDOW_HPP_INCLUDED
#define WIDGETS_CLASS_FRAMED_WINDOW_HPP_INCLUDED
//--------------------------------------------------

#include "../container.hpp"
#include "../windows/windows.hpp"

#include "frame.hpp"

//--------------------------------------------------


class Framed_Window: public Widget_Container {

  public:

    //model - "модель", для которой делается рамочка
    Framed_Window (Window& window);

    Framed_Window (const Framed_Window&) = delete;
    operator=     (const Framed_Window&) = delete;

//--------------------------------------------------

  protected:

    Window&       window_;
    Window_Frame* frame_;
};


//--------------------------------------------------
#endif
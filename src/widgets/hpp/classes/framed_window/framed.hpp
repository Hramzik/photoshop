#ifndef WIDGETS_CLASS_FRAMED_WINDOW_HPP_INCLUDED
#define WIDGETS_CLASS_FRAMED_WINDOW_HPP_INCLUDED
//--------------------------------------------------

#include "frame.hpp"

//--------------------------------------------------


class Framed_Window: public Widget_Container {

  public:

    // model - "модель", для которой делается рамочка
    // верхняя часть model по умолчанию перекрывается рамочкой
    Framed_Window (My_Widget& controlled, bool overlapping_frame = true);

    Framed_Window (const Framed_Window&) = delete;
    operator=     (const Framed_Window&) = delete;

//--------------------------------------------------

  protected:

    My_Widget&    controlled_;
    Window_Frame* frame_;
};


//--------------------------------------------------
#endif
#ifndef WIDGETS_CLASS_WINDOW_HPP_INCLUDED
#define WIDGETS_CLASS_WINDOW_HPP_INCLUDED
//--------------------------------------------------

#include "widget.hpp"

//--------------------------------------------------


class Window: public Widget {

  public:

    Window (double width, double height);

    

  protected:

    double width_;
    double height_;
};


//--------------------------------------------------
#endif
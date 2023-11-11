#ifndef CLASS_SCROLLBAR_HPP_INCLUDED
#define CLASS_SCROLLBAR_HPP_INCLUDED
//--------------------------------------------------

#include "../windows/window.hpp"

#include "moving_scrollbar.hpp"

//--------------------------------------------------

// scrollbar - декоратор для окна
class Scrollbar: public Window {

  public:

    Scrollbar (Point2D position, Vector2D size, Window& controlled);

//--------------------------------------------------

  private:

    Window& controlled;
};


//--------------------------------------------------
#endif
#ifndef WIDGETS_CLASS_PHOTOSHOP_HPP_INCLUDED
#define WIDGETS_CLASS_PHOTOSHOP_HPP_INCLUDED
//--------------------------------------------------

#include "../../../tools/hpp/tools.hpp"

#include "framed_window/framed_window.hpp"
#include "canvas.hpp"

//--------------------------------------------------


class Photoshop: public Framed_Window {

  public:

    Photoshop (Vector2D size);
    Photoshop (Point2D position, Vector2D size);

//--------------------------------------------------

  private:

    Tool_Palette palette_;
    Canvas       canvas_;
};

//--------------------------------------------------
#endif
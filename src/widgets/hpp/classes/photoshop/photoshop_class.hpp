#ifndef WIDGETS_CLASS_PHOTOSHOP_HPP_INCLUDED
#define WIDGETS_CLASS_PHOTOSHOP_HPP_INCLUDED
//--------------------------------------------------

#include "../framed_window/framed_window.hpp"

#include "canvas.hpp"
#include "tool_selection.hpp"

//--------------------------------------------------


class Photoshop: public Framed_Window {

  public:

    Photoshop (Vector2D size);
    Photoshop (Point2D position, Vector2D size);

//--------------------------------------------------

  private:

    Tool_Selection_Widget tool_selection_;
    Canvas                canvas_;
};

//--------------------------------------------------
#endif
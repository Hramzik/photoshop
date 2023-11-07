#ifndef WIDGETS_CLASS_PHOTOSHOP_HPP_INCLUDED
#define WIDGETS_CLASS_PHOTOSHOP_HPP_INCLUDED
//--------------------------------------------------

#include "../framed_window/framed_window.hpp"

#include "canvas.hpp"
#include "tool_selection.hpp"
#include "filter_selection.hpp"

//--------------------------------------------------


class Photoshop: public Framed_Window {

  public:

    static const char* const DEFAULT_CANVAS_IMAGE_PATH;

    //--------------------------------------------------

    Photoshop (Vector2D size);
    Photoshop (Point2D position, Vector2D size);

//--------------------------------------------------

  private:

    Tool_Selection_Widget   tool_selection_;
    Filter_Selection_Widget filter_selection_;

    Canvas canvas_;
};

//--------------------------------------------------
#endif
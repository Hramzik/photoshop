#ifndef WIDGETS_CLASS_PHOTOSHOP_HPP_INCLUDED
#define WIDGETS_CLASS_PHOTOSHOP_HPP_INCLUDED
//--------------------------------------------------

#include "widgets/hpp/classes/framed_window/framed_window.hpp"

#include "widgets/hpp/classes/canvas/canvas.hpp"

//--------------------------------------------------


class Photoshop: public Framed_Window {

  public:

    static const char* const DEFAULT_CANVAS_IMAGE_PATH;

    //--------------------------------------------------

    Photoshop (plug::LayoutBox box);

//--------------------------------------------------

  private:

    Tool_Selection_Widget   tool_selection_;
    Filter_Selection_Widget filter_selection_;

    Canvas canvas_;
};

//--------------------------------------------------
#endif
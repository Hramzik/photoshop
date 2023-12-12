#ifndef WIDGETS_CLASS_PHOTOSHOP_HPP_INCLUDED
#define WIDGETS_CLASS_PHOTOSHOP_HPP_INCLUDED
//--------------------------------------------------

#include "widgets/hpp/widgets.hpp"

//--------------------------------------------------

class Photoshop: public Framed_Window {

  public:

    static const char* const DEFAULT_CANVAS_IMAGE_PATH;

    //--------------------------------------------------

    Photoshop (plug::LayoutBox& box);

//--------------------------------------------------

  private:

    //Tool_Selection_Widget   tool_selection_;
    //Filter_Selection_Widget filter_selection_;

    Tool_Palette  tool_palette_;
    Color_Palette color_palette_;
    Canvas_Viewer* canvas_;
};

//--------------------------------------------------
#endif
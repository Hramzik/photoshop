#ifndef WIDGETS_CLASS_PHOTOSHOP_HPP_INCLUDED
#define WIDGETS_CLASS_PHOTOSHOP_HPP_INCLUDED
//--------------------------------------------------

#include "widgets/hpp/widgets.hpp"

#include "filters/hpp/filters.hpp"

//--------------------------------------------------

class Photoshop: public Framed_Window {

  public:

    static const char* const DEFAULT_CANVAS_IMAGE_PATH;

    //--------------------------------------------------

    Photoshop (plug::LayoutBox& box);

    //--------------------------------------------------

    void add_tool   (plug::Tool&   tool);
    void add_filter (plug::Filter& filter);

//--------------------------------------------------

  private:

    Color_Palette  color_palette_;
    Tool_Palette   tool_palette_;
    Filter_Palette filter_palette_;

    Canvas_Viewer* canvas_;

    void init_colors   (void);
    void init_tools    (void);
    void init_filters  (void);
    void init_canvases (void);
};

//--------------------------------------------------
#endif
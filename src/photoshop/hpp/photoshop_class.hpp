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

    void add_tool (plug::Tool& tool);

//--------------------------------------------------

  private:

    Tool_Palette  tool_palette_;
    Color_Palette color_palette_;
    Canvas_Viewer* canvas_;

    void init_tools    (void);
    void init_colors   (void);
    void init_canvases (void);
};

//--------------------------------------------------
#endif
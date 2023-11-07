#ifndef TOOLS_CLASS_PALETTE_HPP_INCLUDED
#define TOOLS_CLASS_PALETTE_HPP_INCLUDED
//--------------------------------------------------

#include "brush.hpp"
#include "rect/rect.hpp"

//--------------------------------------------------


class Tool_Palette {

  public:

    static const My_RGB DEFAULT_ACTIVE_COLOR;

    //--------------------------------------------------

    Tool_Palette (void);

    //--------------------------------------------------

    Tool* get_active_tool (void);

    My_RGB get_active_color (void) const;

    void select_brush_tool    (void);
    void select_line_tool     (void);
    void select_rect_tool     (void);
    void select_polyline_tool (void);

//--------------------------------------------------

  private:

    Brush_Tool* brush_tool_;
    Rect_Tool*  rect_tool_;

    Tool* active_tool_;

    My_RGB active_color_;
};


//--------------------------------------------------
#endif
#ifndef TOOLS_CLASS_PALETTE_HPP_INCLUDED
#define TOOLS_CLASS_PALETTE_HPP_INCLUDED
//--------------------------------------------------

#include "brush.hpp"

//--------------------------------------------------


class Tool_Palette {

  public:

    Tool_Palette (void);

    //--------------------------------------------------

    Tool* get_active_tool (void);

    My_RGB get_active_color (void);

    void select_brush_tool     (void);
    void select_line_tool      (void);
    void select_rectangle_tool (void);
    void select_ellipse_tool   (void);
    void select_polyline_tool  (void);
    void select_fill_tool      (void);

//--------------------------------------------------

  private:

    Brush_Tool* brush_tool_;

    Tool* active_tool_;

    My_RGB active_color_;
};


//--------------------------------------------------
#endif
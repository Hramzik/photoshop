

//--------------------------------------------------

#include "../hpp/tools.hpp"

//--------------------------------------------------


Tool_Palette::Tool_Palette (void):
        brush_tool_  (nullptr),
        rect_tool_   (nullptr),
        active_tool_ (nullptr),

        active_color_ (C_BLACK)
{
    brush_tool_ = new Brush_Tool (*this);
    rect_tool_  = new Rect_Tool  (*this);

    //--------------------------------------------------

    select_rect_tool ();
}

//--------------------------------------------------

Tool* Tool_Palette::get_active_tool (void) {

    return active_tool_;
}


My_RGB Tool_Palette::get_active_color (void) const {

    return active_color_;
}

//--------------------------------------------------
// TOOL SELECTION

void Tool_Palette::select_brush_tool (void) {

    active_tool_ = brush_tool_;
}


void Tool_Palette::select_rect_tool (void) {

    active_tool_ = rect_tool_;
}


//--------------------------------------------------

#include "../hpp/tools.hpp"

//--------------------------------------------------

const My_RGB Tool_Palette::DEFAULT_ACTIVE_COLOR = C_GRAY;

//--------------------------------------------------

Tool_Palette::Tool_Palette (void):
        brush_tool_  (nullptr),
        rect_tool_   (nullptr),
        active_tool_ (nullptr),

        active_color_ (DEFAULT_ACTIVE_COLOR)
{
    brush_tool_ = new Brush_Tool (*this);
    rect_tool_  = new Rect_Tool  (*this);

    //--------------------------------------------------

    select_brush_tool ();
}

//--------------------------------------------------

Tool* Tool_Palette::get_active_tool (void) {

    return active_tool_;
}


My_RGB Tool_Palette::get_active_color (void) const {

    return active_color_;
}


void Tool_Palette::set_active_color (My_RGB color) {

    active_color_ = color;
}

//--------------------------------------------------
// TOOL SELECTION

void Tool_Palette::select_brush_tool (void) {

    active_tool_ = brush_tool_;
}


void Tool_Palette::select_rect_tool (void) {

    active_tool_ = rect_tool_;
}
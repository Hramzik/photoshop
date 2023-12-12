

//--------------------------------------------------

#include "photoshop/hpp/photoshop.hpp"

//--------------------------------------------------

Photoshop::Photoshop (plug::LayoutBox& box):
    Framed_Window (*new Colored_Window (box, C_GRAY)),

    tool_palette_  (),
    color_palette_ (),

    canvas_ (nullptr)
{

    //--------------------------------------------------
    // tool palette

    Tool& brush = *new Brush_Tool ();
    brush.setColorPalette (color_palette_);
    tool_palette_.add_tool (brush);

    tool_palette_.set_active_tool (0);

    //--------------------------------------------------
    // color palette

    LayoutBox colors_box (Length (200, Unit::Pixel),
                          Length (200, Unit::Pixel));
    colors_box.setPosition (plug::Vec2d (-150, 0));

    Color_Selection_Widget& colors = *new Color_Selection_Widget (colors_box, color_palette_);
    colors.add_color (C_RED);
    colors.add_color (C_GREEN);
    colors.add_color (C_BLUE);
    colors.add_color (C_YELLOW);

    register_widget (&colors);

    //--------------------------------------------------
    // canvases

    LayoutBox canvas_box (Length (400, Unit::Pixel),
                          Length (400, Unit::Pixel));
    canvas_box.setPosition (plug::Vec2d (200, 0));

    Canvas& canvas = *new Canvas (100, 100);
    canvas_ = new Canvas_Viewer (canvas_box, canvas);
    canvas_->set_tool_palette (tool_palette_);
    canvas_->set_is_focused (true);

    register_widget (new Framed_Window (*canvas_));
}



//--------------------------------------------------

#include "photoshop/hpp/photoshop.hpp"

//--------------------------------------------------

Photoshop::Photoshop (plug::LayoutBox& box):
    Framed_Window (*new Colored_Window (box, C_GRAY)),

    tool_palette_  (),
    color_palette_ (),

    canvas_ (nullptr)
{
    init_tools ();
    init_colors ();
    init_canvases (); std::cout << "created photoshop" << "\n";
}

//--------------------------------------------------

void Photoshop::init_tools (void) {

    Plugin_Loader loader (*this);
    loader.load_plugin ("dll/pencil.dll");

    //--------------------------------------------------

    LayoutBox box (Length (200, Unit::Pixel), Length (150, Unit::Pixel));
    box.setPosition (plug::Vec2d (-200, 100));

    My_Widget& tools = *new Tool_Selection_Widget (box, tool_palette_);

    //--------------------------------------------------

    register_widget (new Framed_Window (tools, false));
}

void Photoshop::init_colors (void) {

    LayoutBox colors_box (Length (200, Unit::Pixel), Length (155, Unit::Pixel));
    colors_box.setPosition (plug::Vec2d (-200, -100));

    Color_Selection_Widget& colors = *new Color_Selection_Widget (colors_box, color_palette_);

    //--------------------------------------------------

    colors.add_color (C_RED);
    colors.add_color (C_GREEN);
    colors.add_color (C_YELLOW);
    colors.add_color (C_BLUE);
    colors.add_color (C_BLACK);
    colors.add_color (C_DARK_GRAY);
    colors.add_color (C_GRAY);
    colors.add_color (C_WHITE);
    colors.add_color (C_BROWN);
    colors.add_color (C_ORANGE);
    colors.add_color (C_PINK);
    colors.add_color (C_PURPLE);

    //--------------------------------------------------

    register_widget (new Framed_Window (colors, false));
}

void Photoshop::init_canvases (void) {

    LayoutBox canvas_box (Length (400, Unit::Pixel),
                          Length (400, Unit::Pixel));
    canvas_box.setPosition (plug::Vec2d (175, 0));

    Canvas& canvas = *new Canvas (100, 100);
    canvas_ = new Canvas_Viewer (canvas_box, canvas);
    canvas_->set_tool_palette (tool_palette_);
    canvas_->set_is_focused (true);

    register_widget (new Framed_Window (*canvas_));
}

//--------------------------------------------------

void Photoshop::add_tool (plug::Tool& tool) {

    tool.setColorPalette (color_palette_);
    tool_palette_.add_tool (tool);
}

//--------------------------------------------------


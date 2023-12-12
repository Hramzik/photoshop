

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
    init_canvases ();
}

void Photoshop::init_tools (void) {

    Tool& brush = *new Brush_Tool ();
    brush.setColorPalette (color_palette_);
    tool_palette_.add_tool (brush);

    //--------------------------------------------------

    //tool_palette_.set_active_tool (0);

    //--------------------------------------------------

    LayoutBox box (Length (200, Unit::Pixel), Length (150, Unit::Pixel));
    box.setPosition (plug::Vec2d (-150, 50));

    My_Widget& tools = *new Tool_Selection_Widget (box, tool_palette_);

    //--------------------------------------------------

    register_widget (new Framed_Window (tools, false));
}

void Photoshop::init_colors (void) {

    LayoutBox colors_box (Length (200, Unit::Pixel), Length (150, Unit::Pixel));
    colors_box.setPosition (plug::Vec2d (-150, -200));

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
    canvas_box.setPosition (plug::Vec2d (200, 0));

    Canvas& canvas = *new Canvas (100, 100);
    canvas_ = new Canvas_Viewer (canvas_box, canvas);
    canvas_->set_tool_palette (tool_palette_);
    canvas_->set_is_focused (true);

    register_widget (new Framed_Window (*canvas_));

    //--------------------------------------------------

    MyRenderTexture true_cat_texture; true_cat_texture.loadFromFile ("media/cat.jpeg");
    plug::Texture cat_texture = getTexture (true_cat_texture);

    register_widget (new Textured_Window (getLayoutBox (), cat_texture));
}

//--------------------------------------------------


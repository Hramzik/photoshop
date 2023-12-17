

//--------------------------------------------------

#include "photoshop/hpp/photoshop.hpp"

//--------------------------------------------------

Photoshop::Photoshop (plug::LayoutBox& box):
    Framed_Window (*new Colored_Window (box, C_GRAY)),

    tool_palette_  (),
    color_palette_ (),

    canvas_ (nullptr)
{
    init_colors ();
    init_tools ();
    init_canvases ();

    // filters need canvas
    init_filters ();

    //--------------------------------------------------

    std::cout << "created photoshop" << "\n";
}

//--------------------------------------------------

void Photoshop::init_colors (void) {

    LayoutBox colors_box (250_px, 190_px);
    colors_box.setPosition (plug::Vec2d (-500, -120));

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

void Photoshop::init_tools (void) {

    Plugin_Loader loader (*this);
    loader.load_plugin ("dll/pencil.dll");

    tool_palette_.set_active_tool (0);

    //--------------------------------------------------

    LayoutBox box (250_px, 210_px);
    box.setPosition (plug::Vec2d (-500, 200));

    My_Widget& tools = *new Tool_Selection_Widget (box, tool_palette_);

    //--------------------------------------------------

    register_widget (new Framed_Window (tools, false));
}

#include "filters/hpp/plugins/monochrome.hpp"
#include "filters/hpp/plugins/black_and_white.hpp"
void Photoshop::init_filters (void) {

    LayoutBox filters_box (250_px, 125_px);
    filters_box.setPosition (plug::Vec2d (-500, -350));

    Filter_Applying_Widget& filters = *new Filter_Applying_Widget (filters_box, canvas_->access_canvas ());

    //--------------------------------------------------

    filters.add_filter (*new Monochrome_Filter ());
    filters.add_filter (*new Black_And_White_Filter ());

    //--------------------------------------------------

    register_widget (&filters);
}

void Photoshop::init_canvases (void) {

    LayoutBox canvas_box (800_px, 800_px);
    canvas_box.setPosition (plug::Vec2d (100, 0));

    Canvas& canvas = *new Canvas ("media/cat.jpeg");
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


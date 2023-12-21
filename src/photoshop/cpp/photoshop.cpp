

//--------------------------------------------------

#include "photoshop/hpp/photoshop.hpp"

//--------------------------------------------------

Photoshop::Photoshop (plug::LayoutBox& box):
    Widget_Manager (box),

    color_palette_ (),
    tool_palette_  (),
    filter_palette_  (),

    canvas_manager_ ()
{

    My_Widget& background = *new Colored_Window (box, C_GRAY);

    register_background_widget (&background);

    //--------------------------------------------------

    init_colors ();

    //--------------------------------------------------

    load_plugins ();

    // idk why tools must be inited before canvases
    init_tools ();

    //--------------------------------------------------
    // to init canvas, tool_palette must be set

    init_canvases ();

    //--------------------------------------------------
    // to init filters, canvas must be created

    init_filters ();

    //--------------------------------------------------

    std::cout << "created photoshop" << "\n";
}

//--------------------------------------------------

void Photoshop::load_plugins (void) {

    Plugin_Loader loader (*this);

    //--------------------------------------------------

    loader.load_plugins ();
}

void Photoshop::init_colors (void) {

    LayoutBox colors_box (250_px, 190_px);
    colors_box.setPosition (plug::Vec2d (-500, -60));

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

    tool_palette_.set_active_tool (0);

    //--------------------------------------------------

    LayoutBox box (250_px, 180_px);
    box.setPosition (plug::Vec2d (-500, 200));

    My_Widget& tools = *new Tool_Selection_Widget (box, tool_palette_);

    //--------------------------------------------------

    register_widget (new Framed_Window (tools, false));
}

void Photoshop::init_filters (void) {

    LayoutBox filters_box (150_px, 125_px);
    filters_box.setPosition (plug::Vec2d (-500, -350));

    Filter_Applying_Widget& filters = // todo rewrite with add_paletet
            *new Filter_Applying_Widget (filters_box, filter_palette_, canvas_manager_);

    //--------------------------------------------------

    LayoutBox menu_box (1400_px, 30_px);
    menu_box.setPosition (plug::Vec2d (0, -500 + 15));
    Menu& menu = *new Menu (menu_box);
    menu.add_widget (filters, "Filters");

    register_widget (&menu);
}

void Photoshop::init_canvases (void) {

    LayoutBox viewer1_box (800_px, 800_px);
    viewer1_box.setPosition (plug::Vec2d (100, 0));

    Canvas&        canvas1 = *new Canvas (500, 500, "media/cat.jpeg");
    Canvas_Viewer& viewer1 = *new Canvas_Viewer (viewer1_box, canvas1);
    viewer1.set_tool_palette (tool_palette_);

    //--------------------------------------------------

    canvas_manager_.register_canvas_viewer (viewer1);
    register_widget (new Framed_Window (viewer1));
}

//--------------------------------------------------

void Photoshop::add_tool (plug::Tool& tool) {

    tool.setColorPalette (color_palette_);
    tool_palette_.add_tool (tool);
}

void Photoshop::add_filter (plug::Filter& filter) {

    filter_palette_.add_filter (filter);
}

//--------------------------------------------------


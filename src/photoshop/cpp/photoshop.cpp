

//--------------------------------------------------

#include "canvas/hpp/canvas.hpp"

#include "photoshop/hpp/photoshop.hpp"

//--------------------------------------------------

Photoshop::Photoshop (plug::LayoutBox& box):
    Widget_Manager (box),

    color_palette_ (),
    tool_palette_  (),
    filter_palette_  (),

    canvas_manager_ (),
    menu_           (nullptr)
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
    // to init filter buttons, canvas must be created

    init_menu ();

    //--------------------------------------------------

    std::cout << "created photoshop" << "\n";
}

//--------------------------------------------------

plug::ColorPalette& Photoshop::access_color_palette (void) {

    return color_palette_;
}

Canvas_Manager& Photoshop::access_canvas_manager (void) {

    return canvas_manager_;
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

void Photoshop::init_canvases (void) {

    add_canvas (*new Canvas (500, 500, "media/cat.jpeg"));
}

//--------------------------------------------------

void Photoshop::add_tool (plug::Tool& tool) {

    tool.setColorPalette (color_palette_);
    tool_palette_.add_tool (tool);
}

void Photoshop::add_filter (plug::Filter& filter) {

    filter_palette_.add_filter (filter);
}

void Photoshop::add_canvas (plug::Canvas& canvas) {

    //--------------------------------------------------
    // finding viewer position

    LayoutBox viewer_box   (800_px, 800_px);
    viewer_box.setPosition (plug::Vec2d (100, 0));

    Canvas_Viewer* active_viewer = canvas_manager_.get_active_canvas_viewer ();
    if (active_viewer) {

        plug::Vec2d new_position = active_viewer->getLayoutBox ().getPosition ();
        new_position += plug::Vec2d (40, 40);
        viewer_box.setPosition (new_position);
    }

    //--------------------------------------------------
    // crreating viewer

    Canvas_Viewer& viewer = *new Canvas_Viewer (viewer_box, canvas);
    viewer.set_tool_palette (tool_palette_);
    viewer.set_is_focused (true);

    //--------------------------------------------------

    canvas_manager_.register_canvas_viewer (viewer);
    register_widget (new Framed_Window (viewer), true);
}

//--------------------------------------------------

void Photoshop::init_menu (void) {

    //--------------------------------------------------
    // menu

    LayoutBox menu_box (1400_px, 30_px);
    menu_box.setPosition (plug::Vec2d (0, -500 + 15));
    menu_ = new Menu (menu_box);

    register_widget (menu_);

    //--------------------------------------------------
    // file entry

    LayoutBox  file_box     (100_px, 1_px);
    My_Widget& file_entry = *new File_Menu_Entry (file_box, *this);

    menu_->add_widget (file_entry, "File");

    //--------------------------------------------------

    init_filters_button ();
}

void Photoshop::init_filters_button (void) {

    if (!menu_) return;

    //--------------------------------------------------

    LayoutBox               filters_box (150_px, 1_px);
    Filter_Applying_Widget& filters = // todo rewrite with add_paletet
            *new Filter_Applying_Widget (filters_box, filter_palette_, canvas_manager_);

    menu_->add_widget (filters, "Filters");
}

//--------------------------------------------------


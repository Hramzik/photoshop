

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

void Photoshop::init_menu (void) {

    LayoutBox menu_box (1400_px, 30_px);
    menu_box.setPosition (plug::Vec2d (0, -500 + 15));

    //--------------------------------------------------

    menu_ = new Menu (menu_box);
    register_widget (menu_);

    //--------------------------------------------------

    init_file_button    ();
    init_filters_button ();
}

void Photoshop::init_file_button (void) {

    if (!menu_) return;

    //--------------------------------------------------
    // file button

    LayoutBox       file_box (150_px, 1_px);
    My_Widget&      file_button_background = *new Colored_Window (file_box, C_DARK_GRAY);
    Widget_Aligner& file_buttons           = *new Column_Aligner (file_button_background, plug::Vec2d (0.05, 0.05));

    //--------------------------------------------------
    // clear button

    LayoutBox   box (1_px, 30_px);
    const char* text = "Clear";
    My_RGB      text_color (255, 255, 255);
    My_Widget&  model  = *new Texted_Window (box, text, text_color, C_DARK_GRAY);

    Button& button = *new Button (model);
    Action& action = *new Canvas_Clear_Action (canvas_manager_, color_palette_);
    button.set_pressed_action (&action);

    file_buttons.add_widget (button);

    //--------------------------------------------------

    menu_->add_widget (file_buttons, "File");

    //--------------------------------------------------
    // move file buttons to the left

    plug::LayoutBox& file_buttons_box = file_buttons.getLayoutBox ();
    plug::Vec2d new_position = file_buttons_box.getPosition ();
    new_position.x -= 12;
    file_buttons_box.setPosition (new_position);
    file_buttons.setLayoutBox (file_buttons_box);
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




//--------------------------------------------------

#include "widgets/hpp/widgets.hpp"

//--------------------------------------------------

const char* const Photoshop::DEFAULT_CANVAS_IMAGE_PATH = "media/cat.jpeg";

//--------------------------------------------------

Photoshop::Photoshop (Vector2D size):
        Photoshop (0, size) {}


Photoshop::Photoshop (Point2D position, Vector2D size):
        Framed_Window (*new Colored_Window (position, size, C_DARK_GRAY)),

        tool_selection_   ({50, 400}, {200, 135}),
        filter_selection_ ({250, 150}, canvas_),

        canvas_ ({400, 100}, 800, tool_selection_.access_palette (),
                                filter_selection_.access_palette ())
{
    register_widget (&tool_selection_);
    register_widget (&filter_selection_);

    //--------------------------------------------------
    // tool selection

    tool_selection_.add_tool_selection_button (Tool_Selection_Button::PENCIL);
    tool_selection_.add_tool_selection_button (Tool_Selection_Button::RECT);

    //--------------------------------------------------
    // color selection

    Point2D  cs_position (50, 100);
    Vector2D cs_size     (300, 260);
    Color_Selection_Widget* cs = new Color_Selection_Widget (cs_position, cs_size, tool_selection_.access_palette ());
    register_widget (cs);

    cs->add_color_selection_button (C_RED); // line 1
    cs->add_color_selection_button (C_GREEN);
    cs->add_color_selection_button (C_YELLOW);
    cs->add_color_selection_button (C_BLUE);
    cs->add_color_selection_button (C_BLACK); // line 2
    cs->add_color_selection_button (C_DARK_GRAY);
    cs->add_color_selection_button (C_GRAY);
    cs->add_color_selection_button (C_WHITE);
    cs->add_color_selection_button (C_BROWN); // line 3
    cs->add_color_selection_button (C_ORANGE);
    cs->add_color_selection_button (C_PINK);
    cs->add_color_selection_button (C_PURPLE);

    //--------------------------------------------------
    // canvas 1

    //Point2D position1 (400, 100);
    //canvas_ = new Canvas (position1, 800, tool_selection_.access_palette (),
    //                                            filter_selection_.access_palette ());

    My_Texture& canvas_texture = canvas_.access_texture ();
    canvas_texture.load_from_file (DEFAULT_CANVAS_IMAGE_PATH);

    register_widget (new Framed_Window (canvas_));

    //--------------------------------------------------
    // scrollbar

    register_widget (new Driving_Scrollbar ({50, 50}, {500, 40}, canvas_));

    //--------------------------------------------------
    // menu

    Window_Menu* menu = new Window_Menu ({0, 940}, {1400, 30});

    menu->add_menu_button (nullptr, filter_selection_);
    filter_selection_.hide ();

    register_widget (menu);

    //--------------------------------------------------

    filter_selection_.add_filter (*new Brightness_Filter (-10));
    filter_selection_.add_filter (*new Contrast_Filter   (1));
    filter_selection_.add_filter (*new Monochrome_Filter ());
    filter_selection_.add_filter (*new Binary_Filter     ());
}


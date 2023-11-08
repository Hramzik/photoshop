

//--------------------------------------------------

#include "../hpp/widgets.hpp"

//--------------------------------------------------

const char* const Photoshop::DEFAULT_CANVAS_IMAGE_PATH = "media/cat.jpeg";

//--------------------------------------------------

Photoshop::Photoshop (Vector2D size):
        Photoshop (0, size) {}


Photoshop::Photoshop (Point2D position, Vector2D size):
        Framed_Window (*new Colored_Window (position, size, C_DARK_GRAY)),

        tool_selection_   (),
        filter_selection_ ()

        //canvas_ (size, tool_selection_.access_palette (),
        //             filter_selection_.access_palette ())
{
    register_widget (&tool_selection_);
    register_widget (&filter_selection_);

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

    Point2D position1 (400, 100);
    Canvas* canvas1 = new Canvas (position1, 800, tool_selection_.access_palette (),
                                                filter_selection_.access_palette ());

    My_Texture& canvas_texture = canvas1->access_texture ();
    canvas_texture.load_from_file (DEFAULT_CANVAS_IMAGE_PATH);

    register_widget (new Framed_Window (*canvas1));

    //--------------------------------------------------
    // canvas 2

    //Point2D position2 (900, 300);
    //Canvas* canvas2 = new Canvas (position2, 400, tool_selection_.access_palette (),
    //                                            filter_selection_.get_palette ());

    //register_widget (new Framed_Window (*canvas2));

    //--------------------------------------------------

    filter_selection_.add_filter (*new Brightness_Filter (-10));
    filter_selection_.add_filter (*new Contrast_Filter   (1));
    filter_selection_.add_filter (*new Monochrome_Filter ());
}


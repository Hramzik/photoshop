

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

        //canvas_ (size, tool_selection_.get_palette (),
        //             filter_selection_.get_palette ())
{
    register_widget (&tool_selection_);
    register_widget (&filter_selection_);

    //--------------------------------------------------
    // canvas 1

    Point2D position1 (400, 100);
    Canvas* canvas1 = new Canvas (position1, 800, tool_selection_.get_palette (),
                                                filter_selection_.get_palette ());

    My_Texture& canvas_texture = canvas1->access_texture ();
    canvas_texture.load_from_file (DEFAULT_CANVAS_IMAGE_PATH);

    register_widget (new Framed_Window (*canvas1));

    //--------------------------------------------------
    // canvas 2

    //Point2D position2 (900, 300);
    //Canvas* canvas2 = new Canvas (position2, 400, tool_selection_.get_palette (),
    //                                            filter_selection_.get_palette ());

    //register_widget (new Framed_Window (*canvas2));

    //--------------------------------------------------

    filter_selection_.add_filter (*new Brightness_Filter (-10));
    filter_selection_.add_filter (*new Contrast_Filter   (1));
    filter_selection_.add_filter (*new Monochrome_Filter ());
}


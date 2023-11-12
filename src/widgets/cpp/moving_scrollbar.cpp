

//--------------------------------------------------

#include "widgets/hpp/widgets.hpp"

//--------------------------------------------------

Moving_Scrollbar::Moving_Scrollbar
(Point2D position, Vector2D size, Widget& controlled):
        Window (position, size),

        controlled_ (controlled),

        button_ratio_ (DEFAULT_BUTTON_RATIO),
        slider_ratio_ (DEFAULT_SLIDER_RATIO),

        subwidgets_ (0),
        left_button_  (nullptr),
        right_button_ (nullptr),
        slider_       (nullptr),
        background_   (nullptr)
{
    //--------------------------------------------------
    // buttons

    Vector2D button_size          (size.y * button_ratio_, size.y);
    Point2D right_button_position (size.x - button_size.x, 0);
    Point2D left_button_position  (0);

    left_button_  = new Colored_Window (left_button_position,  button_size, C_RED);
    right_button_ = new Colored_Window (right_button_position, button_size, C_RED);

    subwidgets_.register_widget (left_button_);
    subwidgets_.register_widget (right_button_);

    //--------------------------------------------------
    //slider

    Vector2D slider_size     (size.y * slider_ratio_,         size.y);
    Point2D  slider_position (size.x / 2 - slider_size.x / 2, 0);

    slider_ = new Colored_Window (slider_position, slider_size, C_RED);

    subwidgets_.register_widget (slider_);

    //--------------------------------------------------
    // background

    background_ = new Colored_Window (0, size, C_GREEN);
    subwidgets_.register_widget (background_);
}

//--------------------------------------------------

void Moving_Scrollbar::render_with_local_stack
(Graphic_Window& window, Transform_Stack& local_stack) {

    subwidgets_.render (window, local_stack);
}


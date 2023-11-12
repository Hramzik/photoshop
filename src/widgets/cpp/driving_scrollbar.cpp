

//--------------------------------------------------

#include "widgets/hpp/widgets.hpp"

//--------------------------------------------------

Driving_Scrollbar::Driving_Scrollbar
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
    Point2D  slider_min_position (button_size.x, 0);
    Point2D  slider_max_position (size.x - button_size.x - slider_size.x, 0);
    Window*  slider_model = new Colored_Window (slider_position, slider_size, C_RED);

    slider_ = new Driving_Button (*slider_model, controlled_);
    slider_->follow_target ();
    slider_->set_bottom_left_border (slider_min_position);
    slider_->set_top_right_border   (slider_max_position);

    subwidgets_.register_widget (slider_);

    //--------------------------------------------------
    // background

    background_ = new Colored_Window (0, size, C_GREEN);
    subwidgets_.register_widget (background_);
}

//--------------------------------------------------

void Driving_Scrollbar::render_with_local_stack
(Graphic_Window& window, Transform_Stack& local_stack) {

    subwidgets_.render (window, local_stack);
}


Processing_result Driving_Scrollbar::on_mouse_moved (Point2D mouse_position, Transform_Stack& stack) {

    stack.push (my_transform_);
    Processing_result result = slider_->on_mouse_moved (mouse_position, stack);
    stack.pop ();


    return result;
}


Processing_result Driving_Scrollbar::on_mouse_pressed (Point2D mouse_position, Transform_Stack& stack) {

    stack.push (my_transform_);
    Processing_result result = slider_->on_mouse_pressed (mouse_position, stack);
    stack.pop ();


    return result;
}


Processing_result Driving_Scrollbar::on_mouse_released (Point2D mouse_position, Transform_Stack& stack) {

    stack.push (my_transform_);
    Processing_result result = slider_->on_mouse_released (mouse_position, stack);
    stack.pop ();


    return result;
}



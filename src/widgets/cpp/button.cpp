

//--------------------------------------------------

#include "../hpp/widgets.hpp"

//--------------------------------------------------


Button::Button (Point2D position, Vector2D size, My_RGB color):
        Window (position, size),
        visible_part (new Colored_Window (position, size, color)) {}

//--------------------------------------------------

Button::State Button::get_state (void) {

    return state_;
}


void Button::render (Graphic_Window& window, Transform_Stack& stack) {

    visible_part->render (window, stack);
}


Processing_result Button::on_mouse_pressed (Point2D mouse_position, Transform_Stack& stack) {

    Point2D local_mouse_position = convert_copy_to_local (mouse_position, stack);
    if (!is_mouse_in_me (local_mouse_position)) return PR_LEFT;

    //--------------------------------------------------

    state_ = PRESSED;
    do_when_pressed ();

    //--------------------------------------------------

    return PR_PROCESSED;
}

//--------------------------------------------------

void Button::do_when_pressed (void) {

    return;
}

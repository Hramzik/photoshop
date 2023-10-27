

//--------------------------------------------------

#include "../hpp/widgets.hpp"

//--------------------------------------------------


Button::Button (Vector2D position, Vector2D size, My_RGB color):
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

    (void) mouse_position, (void) stack;
/*
    if (mouse_x < my_transform_.get_offset ().x)           return PR_LEFT;
    if (mouse_y < my_transform_.get_offset ().y)           return PR_LEFT;
    if (mouse_x > my_transform_.get_offset ().x + size_.x) return PR_LEFT;
    if (mouse_y > my_transform_.get_offset ().y + size_.y) return PR_LEFT;
*/

    state_ = PRESSED;


    return PR_PROCESSED;
}

//--------------------------------------------------


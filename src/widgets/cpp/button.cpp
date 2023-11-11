

//--------------------------------------------------

#include "../hpp/widgets.hpp"

//--------------------------------------------------

Button::Button (Window& model):
        Window (model.get_position (), model.get_size ()),

        model_ (model) {}

//--------------------------------------------------

Button::State Button::get_state (void) {

    return state_;
}


void Button::do_when_pressed (void) {

    return;
}


void Button::do_when_released (void) {

    return;
}


void Button::do_when_hovered (void) {

    return;
}


void Button::do_when_unhovered (void) {

    return;
}

//--------------------------------------------------

void Button::render (Graphic_Window& window, Transform_Stack& stack) {

    model_.render (window, stack);
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


Processing_result Button::on_mouse_released (Point2D mouse_position, Transform_Stack& stack) {

    (void) mouse_position; (void) stack;

    //--------------------------------------------------

    if (state_ == RELEASED) return PR_LEFT;

    //--------------------------------------------------

    state_ = RELEASED;
    do_when_released ();

    //--------------------------------------------------

    return PR_PROCESSED;
}


Processing_result Button::on_mouse_moved (Point2D mouse_position, Transform_Stack& stack) {

    convert_to_local (mouse_position, stack);

    //--------------------------------------------------

    if (state_ == PRESSED) return PR_LEFT;
    if (state_ == RELEASED && !is_mouse_in_me (mouse_position)) return PR_LEFT;
    if (state_ == HOVERED  &&  is_mouse_in_me (mouse_position)) return PR_LEFT;

    //--------------------------------------------------
    // hover ended, or started
    // я выделил эту секцию, так как в будущем тут нужно возвращать не pr_left, а pr_чтототам
    // чтобы кнопка подо мой не хаверилась

    if (is_mouse_in_me (mouse_position)) { state_ = HOVERED;  do_when_hovered ();   }
    else                                 { state_ = RELEASED; do_when_unhovered (); }


    return PR_LEFT;
}

//--------------------------------------------------


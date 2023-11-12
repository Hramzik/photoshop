

//--------------------------------------------------

#include "widgets/hpp/widgets.hpp"

//--------------------------------------------------

Widget::Widget (Point2D position):
        Widget (Transform (position)) {}


Widget::Widget (Transform transform):
        my_transform_ (transform),
        state_        (OPENED) {}

//--------------------------------------------------

bool Widget::is_closed (void) {

    if (state_ == CLOSED) return true;


    return false;
}


void Widget::close (void) {

    state_ = CLOSED;
}


void Widget::show (void) {

    if (state_ != HIDDEN) return;

    //--------------------------------------------------

    state_ = OPENED;
}


void Widget::hide (void) {

    if (state_ != OPENED) return;

    //--------------------------------------------------

    state_ = HIDDEN;
}


void Widget::inverse_visibility (void) {

    if (state_ == CLOSED) return;

    if (state_ == OPENED) hide ();
    else                  show ();
}


Point2D Widget::get_position (void) {

    Point2D position;


    position.x = my_transform_.get_offset ().x;
    position.y = my_transform_.get_offset ().y;


    return position;
}


void Widget::set_position (Point2D position) {

    my_transform_.set_offset (position);
}


Transform Widget::get_transform (void) const {

    return my_transform_;
}


void Widget::set_transform (const Transform& transform) {

    my_transform_ = transform;
}

//--------------------------------------------------

void Widget::render (Graphic_Window& window, Transform_Stack& stack) {

    if (state_ == HIDDEN) return;

    //--------------------------------------------------

    stack.push (my_transform_);


    render_with_local_stack (window, stack);


    stack.pop ();
}


void Widget::render_with_local_stack (Graphic_Window& window, Transform_Stack& local_stack) {

    render_with_final_transform (window, local_stack.get_result ());
}


void Widget::render_with_final_transform (Graphic_Window& window, const Transform& result_transform) {

    (void) window;
    (void) result_transform;
}

//--------------------------------------------------

Processing_result Widget::on_mouse_moved (Point2D mouse_position, Transform_Stack& stack) {

    (void) mouse_position;
    (void) stack;


    return PR_LEFT;
}


Processing_result Widget::on_mouse_pressed (Point2D mouse_position, Transform_Stack& stack) {

    (void) mouse_position;
    (void) stack;


    return PR_LEFT;
}


Processing_result Widget::on_mouse_released (Point2D mouse_position, Transform_Stack& stack) {

    (void) mouse_position;
    (void) stack;


    return PR_LEFT;
}


Processing_result Widget::on_keyboard_pressed (SDL_Keycode key) {

    (void) key;


    return PR_LEFT;
}


Processing_result Widget::on_keyboard_released (SDL_Keycode key) {

    (void) key;


    return PR_LEFT;
}


Processing_result Widget::on_timer (clock_t current_time) {

    (void) current_time;


    return PR_LEFT;
}

//--------------------------------------------------

void Widget::on_move (Vector2D offset) {

    my_transform_.add_offset (offset);
}

//--------------------------------------------------

void Widget::convert_to_local (Point2D& point, Transform_Stack& global_stack) {

    global_stack.push (my_transform_);


    Vector2D vector_to_local = global_stack.get_result ().get_offset ();
    vector_to_local *= -1;
    point.move (vector_to_local);


    global_stack.pop ();
}


Point2D Widget::convert_copy_to_local (Point2D point, Transform_Stack& global_stack) {

    global_stack.push (my_transform_);


    Vector2D vector_to_local = global_stack.get_result ().get_offset ();
    vector_to_local *= -1;


    global_stack.pop ();


    return point.move_copy (vector_to_local);
}


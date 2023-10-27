

//--------------------------------------------------

#include "../hpp/widgets.hpp"

//--------------------------------------------------

Widget::Widget (Vector2D position):
        Widget (Transform (position)) {}


Widget::Widget (Transform transform):
        my_transform_ (transform),
        state         (OPENED) {}


Widget::~Widget (void) {}

//--------------------------------------------------

Vector2D Widget::get_position (void) {

    return my_transform_.get_offset ();
}


void Widget::set_position (Vector2D position) {

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

Processing_result Widget::on_mouse_move (int mouse_x, int mouse_y) {

    (void) mouse_x;
    (void) mouse_y;


    return PR_LEFT;
}


Processing_result Widget::on_mouse_press (int mouse_x, int mouse_y) {

    (void) mouse_x;
    (void) mouse_y;


    return PR_LEFT;
}


Processing_result Widget::on_mouse_release (int mouse_x, int mouse_y) {

    (void) mouse_x;
    (void) mouse_y;


    return PR_LEFT;
}


Processing_result Widget::on_keyboard_press (SDL_Keycode key) {

    (void) key;


    return PR_LEFT;
}


Processing_result Widget::on_keyboard_release (SDL_Keycode key) {

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




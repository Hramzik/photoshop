

//--------------------------------------------------

#include "../hpp/widgets.hpp"

//--------------------------------------------------

Widget::Widget (Vector2D position):
        Widget (Transform (position)) {}


Widget::Widget (Transform transform):
        transform_ (transform),
        state (OPENED) {}


Widget::~Widget (void) {}

//--------------------------------------------------

void Widget::render (Graphic_Window& window, Transform_Stack& transform) {

    (void) window;
    (void) transform;
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

Transform Widget::get_transform (void) const {

    return my_transform_;
}


void Widget::set_transform (const Transform& transform) {

    my_transform_ = transform;
}




//--------------------------------------------------

#include "../hpp/widgets.hpp"

//--------------------------------------------------

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

//--------------------------------------------------

Processing_result Widget::on_keyboard_press (SDL_Keycode key) {

    (void) key;


    return PR_LEFT;
}


Processing_result Widget::on_keyboard_release (SDL_Keycode key) {

    (void) key;


    return PR_LEFT;
}

//--------------------------------------------------

Processing_result Widget::on_timer (clock_t current_time) {

    (void) current_time;


    return PR_LEFT;
}

//--------------------------------------------------


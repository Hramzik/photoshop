

//--------------------------------------------------

#include "../hpp/widgets.hpp"

//--------------------------------------------------

const My_RGB Close_Button::DEFAULT_COLOR = C_RED;
const double Close_Button::DEFAULT_WIDTH = 45;
const double Close_Button::DEFAULT_HEIGHT = Window_Frame::DEFAULT_FRAME_HEIGHT;

//--------------------------------------------------

Close_Button::Close_Button (Point2D position, Widget& controlled):
        Button (position, Vector2D (DEFAULT_WIDTH, DEFAULT_HEIGHT), DEFAULT_COLOR),

        controlled_ (controlled) {}

//--------------------------------------------------

Processing_result Close_Button::on_mouse_pressed
        (Point2D mouse_position, Transform_Stack& stack) {

    Point2D local_mouse_position = conver_copy_to_local (mouse_position, stack);
    if (!is_mouse_in_me (local_mouse_position)) return PR_LEFT;


    controlled_.close ();


    return PR_PROCESSED;
}


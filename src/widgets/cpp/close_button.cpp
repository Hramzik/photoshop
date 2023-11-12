

//--------------------------------------------------

#include "widgets/hpp/widgets.hpp"

//--------------------------------------------------

const My_RGB Close_Button::DEFAULT_COLOR = C_RED;
const double Close_Button::DEFAULT_WIDTH = 45;
const double Close_Button::DEFAULT_HEIGHT = Window_Frame::DEFAULT_FRAME_HEIGHT;

//--------------------------------------------------

Close_Button::Close_Button (Point2D position, Widget& controlled):
        Button (*new Colored_Window (position, Vector2D (DEFAULT_WIDTH, DEFAULT_HEIGHT), DEFAULT_COLOR)),

        controlled_ (controlled) {}

//--------------------------------------------------

void Close_Button::do_when_pressed (void) {

    controlled_.close ();
}


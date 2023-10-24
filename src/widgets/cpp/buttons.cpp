

//--------------------------------------------------

#include "../hpp/widgets.hpp"

//--------------------------------------------------


Button::Button (Vector2D position, Vector2D position, Vector2D size):
        Window () {}


Colored_Button::Colored_Button (Vector2D position, Vector2D size, My_RGB color):
        Button (position, size),
        color_ (color);

//--------------------------------------------------

Button::State Button::get_state (void) {

    return state_;
}


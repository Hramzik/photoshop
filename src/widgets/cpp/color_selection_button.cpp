

//--------------------------------------------------

#include "../hpp/widgets.hpp"

//--------------------------------------------------

Color_Selection_Button::Color_Selection_Button
(Point2D position, Vector2D size, My_RGB color, Tool_Palette& palette):

    Button (position, size, color),

    color_   (color),
    palette_ (palette) {}

//--------------------------------------------------

void Color_Selection_Button::do_when_pressed (void) {

    palette_.set_active_color (color_);
}

//--------------------------------------------------


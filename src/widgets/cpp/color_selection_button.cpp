

//--------------------------------------------------

#include "../hpp/widgets.hpp"

//--------------------------------------------------

Color_Selection_Button::Color_Selection_Button
(Window& model, My_RGB color, Tool_Palette& palette):

    Button (model),

    color_   (color),
    palette_ (palette) {}

//--------------------------------------------------

void Color_Selection_Button::do_when_pressed (void) {

    palette_.set_active_color (color_);
}

//--------------------------------------------------




//--------------------------------------------------

#include "photoshop/hpp/photoshop.hpp"

//--------------------------------------------------

Color_Selection_Action::Color_Selection_Action (Color_Palette& palette, My_RGB color):
        color_   (color),
        palette_ (palette) {}

//--------------------------------------------------

void Color_Selection_Action::act (void) {

    palette_.setFGColor (plug::Color (color_.r, color_.g, color_.b));
}

//--------------------------------------------------


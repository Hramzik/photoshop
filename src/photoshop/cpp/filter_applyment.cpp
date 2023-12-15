

//--------------------------------------------------

#include "Impl/LayoutBox/LayoutBox.h"

#include "photoshop/hpp/photoshop.hpp"

//--------------------------------------------------

Color_Selection_Widget::Color_Selection_Widget
(plug::LayoutBox& box, Color_Palette& palette):
        Square_Aligner (*new Colored_Window (box, C_LIGHT_GRAY), 4),

        palette_ (palette) {}

//--------------------------------------------------

void Color_Selection_Widget::add_color (My_RGB color) {

    LayoutBox  box (100_px, 100_px);
    My_Widget& model  = *new Colored_Window (box, color); // can be any size, will be resized after
    Button&    button = *new Button (model);

    //--------------------------------------------------

    Action& action = *new Color_Selection_Action (palette_, color);
    button.set_pressed_action (&action);

    //--------------------------------------------------

    Widget_Aligner::add_widget (button);
}

//--------------------------------------------------


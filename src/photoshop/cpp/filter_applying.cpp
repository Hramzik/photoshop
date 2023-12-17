

//--------------------------------------------------

#include "Impl/LayoutBox/LayoutBox.h"

#include "photoshop/hpp/photoshop.hpp"

//--------------------------------------------------

Filter_Applying_Widget::Filter_Applying_Widget
(plug::LayoutBox& box, Canvas& canvas):
        Column_Aligner (*new Colored_Window (box, C_LIGHT_GRAY), plug::Vec2d (0.1, 0.1)),

        canvas_ (canvas) {}

//--------------------------------------------------

void Filter_Applying_Widget::add_filter (plug::Filter& filter) {

    LayoutBox  box (666_px, 30_px);
    My_Widget& model  = *new Colored_Window (box, C_BLACK); // width will be resized
    Button&    button = *new Button (model);

    //--------------------------------------------------

    Action& action = *new Filter_Applying_Action (canvas_, filter);
    button.set_pressed_action (&action);

    //--------------------------------------------------

    Widget_Aligner::add_widget (button);
}

//--------------------------------------------------


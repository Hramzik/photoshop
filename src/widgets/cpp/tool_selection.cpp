

//--------------------------------------------------

#include "../hpp/widgets.hpp"

//--------------------------------------------------

Tool_Selection_Widget::Tool_Selection_Widget (void):
        Widget   (0),
        palette_ () {}

//--------------------------------------------------

Tool_Palette& Tool_Selection_Widget::get_palette (void) {

    return palette_;
}


void Tool_Selection_Widget::render
(Graphic_Window& window, Transform_Stack& stack) {

    (void) window, (void) stack;
}

//--------------------------------------------------


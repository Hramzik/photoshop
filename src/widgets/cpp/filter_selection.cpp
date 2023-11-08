

//--------------------------------------------------

#include "../hpp/widgets.hpp"

//--------------------------------------------------


Filter_Selection_Widget::Filter_Selection_Widget (void):
        Widget   (0),
        palette_ () {}

//--------------------------------------------------

Filter_Palette& Filter_Selection_Widget::access_palette (void) {

    return palette_;
}


void Filter_Selection_Widget::add_filter (Filter& filter) {

    palette_.add_filter (filter);
}

//--------------------------------------------------

void Filter_Selection_Widget::render
(Graphic_Window& window, Transform_Stack& stack) {

    (void) window, (void) stack;
}

//--------------------------------------------------


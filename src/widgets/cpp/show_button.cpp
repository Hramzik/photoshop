

//--------------------------------------------------

#include "../hpp/widgets.hpp"

//--------------------------------------------------

Show_Button::Show_Button (Window& model, Widget& controlled):
        Button (model),

        controlled_ (controlled) {}

//--------------------------------------------------

void Show_Button::do_when_pressed (void) {

    controlled_.inverse_visibility ();

    //--------------------------------------------------

    state_ = HOVERED;
}


void Show_Button::do_when_unhovered (void) {

    //controlled_.hide ();
}


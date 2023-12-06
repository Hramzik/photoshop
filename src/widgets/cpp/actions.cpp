

//--------------------------------------------------

#include "widgets/hpp/widgets.hpp"

//--------------------------------------------------
// base actions

void Action::act (void) {

    return;
}

void Action::operator() (void) {

    act ();
}

Button_Action::Button_Action (void):
        owner_ (nullptr) {}

void Button_Action::set_owner (Button& owner) {

    owner_ = &owner;
}

//--------------------------------------------------
// close action

Close_Action::Close_Action (My_Widget& controlled):
        controlled_ (controlled) {}

void Close_Action::act (void) {

    controlled_.close ();
}

//--------------------------------------------------

Drive_Action::Drive_Action (My_Widget& controlled):
        controlled_ (controlled) {}

void Drive_Action::act (void) {

    if (!owner_) return;

    //--------------------------------------------------

    plug::Vec2d mouse_position = owner_->get_last_held_position ();

    //--------------------------------------------------
    // starting driving

    if (!driving_) {

        last_mouse_position_ = mouse_position;
        driving_ = true;
        return;
    }

    //--------------------------------------------------
    // driving

    plug::Vec2d position        = controlled_.getLayoutBox ().getPosition ();
    plug::Vec2d movement_vector = mouse_position - last_mouse_position_;
    plug::Vec2d new_position    = position + movement_vector;

    controlled_.getLayoutBox ().setPosition (new_position);
}




//--------------------------------------------------

#include "widgets/hpp/widgets.hpp"

//--------------------------------------------------

Button::Button (My_Widget& model):
        My_Widget (model.getLayoutBox ()),

        model_ (model) {}

//--------------------------------------------------

void Button::render (plug::RenderTarget& target, plug::TransformStack& stack) {

    model_.render (target, stack);
}

void Button::onMousePressed (const plug::MousePressedEvent& event, plug::EHC& context){

    if (context.stopped)          return;
    if (button_state_ == PRESSED) return;

    //--------------------------------------------------

    context.stopped = covers (context.stack, event.pos);

    //--------------------------------------------------
    // not pressed

    if (!context.stopped || event.button_id != plug::MouseButton::Left) return;

    //--------------------------------------------------
    // pressed

    button_state_       = PRESSED;
    last_held_position_ = event.pos;

    call_action (pressed_action_);
}

void Button::onMouseReleased (const plug::MouseReleasedEvent& event, plug::EHC& context){

    (void) context;

    //--------------------------------------------------

    if (button_state_   != PRESSED)                 return;
    if (event.button_id != plug::MouseButton::Left) return;

    //--------------------------------------------------
    // released

    button_state_ = RELEASED;
    call_action (released_action_);
}

void Button::onMouseMove (const plug::MouseMoveEvent& event, plug::EHC& context){

    bool hovered = covers (context.stack, event.pos);

    //--------------------------------------------------
    // held

    if (button_state_ == PRESSED) {

        last_held_position_ = event.pos;
        call_action (held_action_);
        return;
    }

    //--------------------------------------------------
    // hovered

    if (hovered) {

        button_state_ = HOVERED;
        return;
    }

    //--------------------------------------------------
    // unhovered

    button_state_ = RELEASED;
}

void Button::setLayoutBox (const plug::LayoutBox& box) {

    model_.setLayoutBox (box);

    //--------------------------------------------------

    My_Widget::setLayoutBox (box);
}

//--------------------------------------------------

void Button::call_action (Action* action) {

    if (!action) return;

    //--------------------------------------------------

    action->act ();
}

void Button::set_pressed_action (Action* action) {

    pressed_action_ = action;
}

void Button::set_held_action (Button_Action* action) {

    //--------------------------------------------------
    // add action

    held_action_ = action;

    //--------------------------------------------------
    // set owner

    if (!action) return;
    action->set_owner (*this);
}

void Button::set_released_action (Action* action) {

    released_action_ = action;
}

//--------------------------------------------------

Button::Button_state Button::get_button_state (void) {

    return button_state_;
}

plug::Vec2d Button::get_last_held_position (void) {

    return last_held_position_;
}

//--------------------------------------------------


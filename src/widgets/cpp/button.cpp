

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

    //plug::Transform my_transform (getLayoutBox ().getPosition (), plug::Vec2d (1, 1));
    //context.stack.enter (my_transform);

    context.stopped = covers (context.stack, event.pos);

    std::cout << getCorner(TopLeft, context.stack).x << " " << getCorner(TopLeft, context.stack).y << "\n";
    std::cout << getCorner(BottomLeft, context.stack).x << " " << getCorner(BottomLeft, context.stack).y << "\n";
    std::cout << event.pos.x << " " << event.pos.y << "\n";
    std::cout << context.stopped << "\n";
    //context.stack.leave();

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

    if (event.button_id != plug::MouseButton::Left) return;

    //--------------------------------------------------

    button_state_ = RELEASED;
}

void Button::onMouseMove (const plug::MouseMoveEvent& event, plug::EHC& context){

    if (context.stopped) return;

    //--------------------------------------------------

    plug::Transform my_transform (getLayoutBox ().getPosition (), plug::Vec2d (1, 1));
    context.stack.enter (my_transform);

    bool hovered = covers (context.stack, event.pos);

    context.stack.leave();

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

//--------------------------------------------------

void Button::call_action (Action* action) {

    if (!action) return;

    //--------------------------------------------------

    action->act ();
}

void Button::add_pressed_action (Action* action) {

    pressed_action_ = action;
}

void Button::add_held_action (Button_Action* action) {

    //--------------------------------------------------
    // add action

    held_action_ = action;

    //--------------------------------------------------
    // set owner

    if (!action) return;
    action->set_owner (*this);
}

plug::Vec2d Button::get_last_held_position (void) {

    return last_held_position_;
}

//--------------------------------------------------


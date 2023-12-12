

//--------------------------------------------------

#include "widgets/hpp/widgets.hpp"

//--------------------------------------------------

Widget_Hider::Widget_Hider (My_Widget& widget):
        Widget_Decorator (widget) {}

//--------------------------------------------------

void Widget_Hider::show (void) {

    is_widget_hidden_ = false;
}

void Widget_Hider::hide (void) {

    is_widget_hidden_ = true;;
}

void Widget_Hider::inverse_visibility (void) {

    is_widget_hidden_ = !is_widget_hidden_;
}

bool Widget_Hider::get_is_widget_hidden (void) {

    return is_widget_hidden_;
}

//--------------------------------------------------

void Widget_Hider::render (plug::RenderTarget& target, plug::TransformStack& stack) {

    if (is_widget_hidden_) return;

    //--------------------------------------------------

    Widget_Decorator::render (target, stack);
}

void Widget_Hider::onEvent (const plug::Event& event, plug::EHC& context) {

    if (is_widget_hidden_ && event.getType () == plug::EventType::MousePressed)  return;
    if (is_widget_hidden_ && event.getType () == plug::EventType::MouseReleased) return;
    if (is_widget_hidden_ && event.getType () == plug::EventType::MouseMove)     return;

    //--------------------------------------------------

    Widget_Decorator::onEvent (event, context);
}

//--------------------------------------------------
// hider toggle action

Hider_Toggle_Action::Hider_Toggle_Action (Widget_Hider& hider):
        hider_ (hider) {}

void Hider_Toggle_Action::act (void) {

    hider_.inverse_visibility ();
}

//--------------------------------------------------


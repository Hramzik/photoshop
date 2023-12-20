
//--------------------------------------------------

#include "widgets/hpp/widgets.hpp"

//--------------------------------------------------


Visible_Window::Visible_Window (plug::LayoutBox& box):
        My_Widget (box) {}

//--------------------------------------------------

void Visible_Window::onMousePressed (const plug::MousePressedEvent& event, plug::EHC& context) {

    if (context.stopped) return;

    //--------------------------------------------------
    // click outside

    context.stopped = covers (context.stack, event.pos);
    if (!context.stopped) return;

    //--------------------------------------------------
    // click inside

    has_mouse_focus_ = true;
}

//--------------------------------------------------

void Visible_Window::onMouseReleased (const plug::MouseReleasedEvent& event, plug::EHC& context) {

    (void) event;

    //--------------------------------------------------

    if (context.stopped)   return;
    if (!has_mouse_focus_) return;

    //--------------------------------------------------

    context.stopped  = true;
    has_mouse_focus_ = false;
}

//--------------------------------------------------


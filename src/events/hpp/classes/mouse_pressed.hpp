#ifndef CLASS_MOUSE_PRESSED_EVENT_HPP_INCLUDED
#define CLASS_MOUSE_PRESSED_EVENT_HPP_INCLUDED
//--------------------------------------------------

#include "event.hpp"

//--------------------------------------------------


struct Mouse_Pressed_Event: public Event {

    Mouse_Button button_id;

    //--------------------------------------------------

    bool shift, ctrl, alt;

    //--------------------------------------------------

    Vec2d pos;
}

//--------------------------------------------------

typedef Mouse_Pressed_Event MousePressedEvent;

//--------------------------------------------------
#endif
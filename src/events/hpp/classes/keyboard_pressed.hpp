#ifndef CLASS_KEYBOARD_PRESSED_EVENT_HPP_INCLUDED
#define CLASS_KEYBOARD_PRESSED_EVENT_HPP_INCLUDED
//--------------------------------------------------

#include "event.hpp"

//--------------------------------------------------


struct Keyboard_Pressed_Event: public Event {

    Key_Code key_id;

    //--------------------------------------------------

    bool shift, ctrl, alt;
}

//--------------------------------------------------

typedef Keyboard_Pressed_Event KeyboardPressedEvent;

//--------------------------------------------------
#endif
#ifndef CLASS_KEYBOARD_RELEASED_EVENT_HPP_INCLUDED
#define CLASS_KEYBOARD_RELEASED_EVENT_HPP_INCLUDED
//--------------------------------------------------

#include "event.hpp"

//--------------------------------------------------


struct Keyboard_Released_Event: public Event {

    Key_Code key_id;

    //--------------------------------------------------

    bool shift, ctrl, alt;
}

//--------------------------------------------------

typedef Keyboard_Released_Event KeyboardReleasedEvent;

//--------------------------------------------------
#endif
#ifndef CLASS_MOUSE_RELEASED_EVENT_HPP_INCLUDED
#define CLASS_MOUSE_RELEASED_EVENT_HPP_INCLUDED
//--------------------------------------------------

#include "event.hpp"

//--------------------------------------------------


struct Mouse_Released_Event: public Event {

    Mouse_Button button_id;

    //--------------------------------------------------

    bool shift, ctrl, alt;

    //--------------------------------------------------

    Vec2d pos;
}

//--------------------------------------------------

typedef Mouse_Released_Event MouseReleasedEvent;

//--------------------------------------------------
#endif
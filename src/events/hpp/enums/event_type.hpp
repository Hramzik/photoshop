#ifndef EVENTS_ENUM_EVENT_TYPE_HPP_INCLUDED
#define EVENTS_ENUM_EVENT_TYPE_HPP_INCLUDED
//--------------------------------------------------


enum Event_Type {

    Tick             = 0,
    MouseMove        = 1,
    MousePressed     = 2,
    MouseRealesed    = 3,
    KeyboardPressed  = 4,
    KeyboardReleased = 5,
};

//--------------------------------------------------

typedef Event_Type EventType;

//--------------------------------------------------
#endif
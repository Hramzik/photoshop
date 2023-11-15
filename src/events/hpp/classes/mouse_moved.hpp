#ifndef CLASS_MOUSE_MOVED_EVENT_HPP_INCLUDED
#define CLASS_MOUSE_MOVED_EVENT_HPP_INCLUDED
//--------------------------------------------------


#include "event.hpp"

//--------------------------------------------------


struct Mouse_Move_Event: public Event {

    bool shift;
    bool ctrl;
    bool alt;

    //--------------------------------------------------

    Vec2d pos;
}


//--------------------------------------------------
#endif
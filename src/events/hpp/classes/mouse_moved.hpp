#ifndef CLASS_MOUSE_MOVED_EVENT_HPP_INCLUDED
#define CLASS_MOUSE_MOVED_EVENT_HPP_INCLUDED
//--------------------------------------------------

#include "event.hpp"

//--------------------------------------------------


struct Mouse_Moved_Event: public Event {

    bool shift, ctrl, alt;

    //--------------------------------------------------

    Vec2d pos;
}



//--------------------------------------------------
#endif
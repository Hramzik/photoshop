#ifndef CLASS_EVENT_HPP_INCLUDED
#define CLASS_EVENT_HPP_INCLUDED
//--------------------------------------------------

#include "../includes.hpp"
#include "../enums.hpp"

//--------------------------------------------------


class Event {

  public:

    Event (Event_Type type);

    //--------------------------------------------------

    Event_Type getType  (void) const;
    Event_Type get_type (void) const;

//--------------------------------------------------

  private:

    const Event_Type type_;
};


//--------------------------------------------------
#endif
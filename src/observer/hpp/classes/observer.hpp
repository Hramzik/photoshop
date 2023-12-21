#ifndef CLASS_OBSERVER_HPP_INCLUDED
#define CLASS_OBSERVER_HPP_INCLUDED
//--------------------------------------------------

class Observable;

//--------------------------------------------------

class Observer {

  public:

    virtual ~Observer ();

    //--------------------------------------------------

    virtual void get_updated (Observable& initiator);
};

//--------------------------------------------------
#endif
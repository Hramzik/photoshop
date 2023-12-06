#ifndef BUTTON_ACTION_HPP_INCLUDED
#define BUTTON_ACTION_HPP_INCLUDED
//--------------------------------------------------

#include "action.hpp"

//--------------------------------------------------

class Button;

//--------------------------------------------------

class Button_Action: public Action {

  public:

    Button_Action (void);

    //--------------------------------------------------

    void set_owner (Button& owner);

//--------------------------------------------------

  protected:

    Button* owner_;
};


//--------------------------------------------------
#endif
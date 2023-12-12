#ifndef CLASS_HIDER_TOGGLE_ACTION_HPP_INCLUDED
#define CLASS_HIDER_TOGGLE_ACTION_HPP_INCLUDED
//--------------------------------------------------

#include "widgets/hpp/classes/actions/action.hpp"

//--------------------------------------------------

class Widget_Hider;

//--------------------------------------------------

class Hider_Toggle_Action: public Action {

  public:

    Hider_Toggle_Action (Widget_Hider& hider);

    //--------------------------------------------------

    void act (void) override;

  private:

    Widget_Hider& hider_;
};

//--------------------------------------------------
#endif
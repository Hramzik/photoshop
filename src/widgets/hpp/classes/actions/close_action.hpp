#ifndef CLASS_CLOSE_ACTION_HPP_INCLUDED
#define CLASS_CLOSE_ACTION_HPP_INCLUDED
//--------------------------------------------------

#include "action.hpp"

#include "widgets/hpp/classes/my_widget.hpp"

//--------------------------------------------------

class Close_Action: public Action {

  public:

    Close_Action (My_Widget& controlled);

    //--------------------------------------------------

    void act (void) override;

//--------------------------------------------------

  private:

    My_Widget& controlled_;
};


//--------------------------------------------------
#endif
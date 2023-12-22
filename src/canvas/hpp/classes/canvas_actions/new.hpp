#ifndef CLASS_NEW_CANVAS_ACTION_HPP_INCLUDED
#define CLASS_NEW_CANVAS_ACTION_HPP_INCLUDED
//--------------------------------------------------

#include "widgets/hpp/classes/actions/action.hpp"

//--------------------------------------------------

class Photoshop;

//--------------------------------------------------

class New_Canvas_Action: public Action {

  public:

    New_Canvas_Action (Photoshop& photoshop);

    //--------------------------------------------------

    void act (void) override;

  private:

    Photoshop& photoshop_;
};

//--------------------------------------------------
#endif
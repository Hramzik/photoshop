#ifndef CLASS_DRIVE_ACTION_HPP_INCLUDED
#define CLASS_DRIVE_ACTION_HPP_INCLUDED
//--------------------------------------------------

#include "button_action.hpp"

#include "widgets/hpp/classes/my_widget.hpp"

//--------------------------------------------------

class Driving_Action: public Button_Action {

  public:

    Driving_Action (My_Widget& controlled);

    //--------------------------------------------------

    void act (void) override;

//--------------------------------------------------

  private:

    My_Widget& controlled_;

    bool        driving_             = false;
    plug::Vec2d last_mouse_position_ = plug::Vec2d ();
};


//--------------------------------------------------
#endif
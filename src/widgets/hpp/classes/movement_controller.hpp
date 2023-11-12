#ifndef CLASS_MOVEMENT_CONTROLLER_HPP_INCLUDED
#define CLASS_MOVEMENT_CONTROLLER_HPP_INCLUDED
//--------------------------------------------------

#include "widgets/hpp/classes/widget.hpp"

//--------------------------------------------------

class Movement_Controller {

  public:

    Movement_Controller (Widget& controlled);

    //--------------------------------------------------

    // returns the actual change in position
    Vector2D move (Vector2D vector);

    void set_bottom_left_border (Point2D border);
    void set_top_right_border   (Point2D border);

//--------------------------------------------------

  private:

    Widget& controlled_;

    // NAN if doesn't exist
    Point2D bottom_left_border_;
    Point2D top_right_border_;
};


//--------------------------------------------------
#endif
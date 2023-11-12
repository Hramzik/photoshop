#ifndef CLASS_DRIVING_BUTTON_HPP_INCLUDED
#define CLASS_DRIVING_BUTTON_HPP_INCLUDED
//--------------------------------------------------

#include "widgets/hpp/classes/movement_controller.hpp"

#include "button.hpp"

//--------------------------------------------------


class Driving_Button: public Button {

  public:

    enum Working_Status {

        IDLE,
        WORKING,
    };

    //--------------------------------------------------

    // !controlled must have matching global scale!
    Driving_Button (Window& model, Widget& controlled);

    //--------------------------------------------------

    void follow_target (void);
    void set_bottom_left_border (Point2D border);
    void set_top_right_border   (Point2D border);

    Processing_result on_mouse_moved
    (Point2D mouse_position, Transform_Stack& stack)
    override;

//--------------------------------------------------

  private:

    Widget& controlled_;
    bool    follow_target_;

    Working_Status      working_status_;
    Point2D             last_mouse_position_; // in global coordinates
    Movement_Controller my_movement_controller;

    //--------------------------------------------------

    void do_when_pressed_at (Point2D global_mouse_position) override;
    void do_when_released   (void)                          override;
};


//--------------------------------------------------
#endif
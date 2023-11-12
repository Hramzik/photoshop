

//--------------------------------------------------

#include "widgets/hpp/widgets.hpp"

//--------------------------------------------------


Driving_Button::Driving_Button (Window& model, Widget& controlled):
        Button (model),

        controlled_    (controlled),
        follow_target_ (false),
        working_status_      (IDLE),
        last_mouse_position_ (0) {}

//--------------------------------------------------

void Driving_Button::follow_target (void) {

    follow_target_ = true;
}


void Driving_Button::do_when_pressed_at (Point2D global_mouse_position){

    last_mouse_position_ = global_mouse_position;

    //--------------------------------------------------

    working_status_ = WORKING;
}


void Driving_Button::do_when_released (void) {

    working_status_ = IDLE;
}

//--------------------------------------------------

Processing_result Driving_Button::on_mouse_moved (Point2D mouse_position, Transform_Stack& stack) {

    if (working_status_ == IDLE) return PR_LEFT;


    stack.push (my_transform_);

    //--------------------------------------------------
    // calculations

    Vector2D movement_vector = mouse_position - last_mouse_position_;
    // если у controlled большой scale, его унесет нахуй, поэтому балансим это делением
    movement_vector / (stack.get_result ().get_scale ());

    //--------------------------------------------------
    // movement

    controlled_.on_move (movement_vector);
    if (follow_target_) on_move (movement_vector);

    //--------------------------------------------------
    // service

    last_mouse_position_ = mouse_position;

    //--------------------------------------------------

    stack.pop ();


    return PR_PROCESSED;
}




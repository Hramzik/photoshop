

//--------------------------------------------------

#include <cmath>

#include "widgets/hpp/widgets.hpp"

//--------------------------------------------------

Movement_Controller::Movement_Controller (Widget& controlled):
        controlled_ (controlled),
        bottom_left_border_ (NAN),
        top_right_border_   (NAN) {}

//--------------------------------------------------

Vector2D Movement_Controller::move (Vector2D vector) {

    Point2D position = controlled_.get_position ();

    //--------------------------------------------------

    double max_dx = top_right_border_  .x - position.x;
    double min_dx = bottom_left_border_.x - position.x;
    double max_dy = top_right_border_  .y - position.y;
    double min_dy = bottom_left_border_.y - position.y;

    if (bottom_left_border_.isnan ()) {

        min_dx = vector.x;
        min_dy = vector.y;
    }

    if (top_right_border_.isnan ()) {

        max_dx = vector.x;
        max_dy = vector.y;
    }

    //--------------------------------------------------

    vector.x = std::min (vector.x, max_dx);
    vector.x = std::max (vector.x, min_dx);
    vector.y = std::min (vector.y, max_dy);
    vector.y = std::max (vector.y, min_dy);

    //--------------------------------------------------

    controlled_.on_move (vector);


    return vector;
}


void Movement_Controller::set_bottom_left_border (Point2D border) {

    bottom_left_border_ = border;
}


void Movement_Controller::set_top_right_border (Point2D border) {

    top_right_border_ = border;
}

//--------------------------------------------------


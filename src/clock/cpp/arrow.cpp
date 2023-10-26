

//--------------------------------------------------

#include "../hpp/clock.hpp"

//--------------------------------------------------


Clock_Arrow::Clock_Arrow (Point2D origin, Vector2D direction, double rotates_per_hour):
        origin_          (origin),
        direction_       (direction),
        start_direction_ (direction),

        color_ (C_GREEN),

        rotates_per_hour_ (rotates_per_hour),
        speed_scale_      (1),
        prev_frame_time_  (0) {}

//--------------------------------------------------

void Clock_Arrow::rotate (double degrees) {

    direction_.rotate (degrees);
}


void Clock_Arrow::reset (void) {

    direction_ = start_direction_;
}


void Clock_Arrow::speed_up (double scale) {

    speed_scale_ *= scale;
}


void Clock_Arrow::render (Graphic_Window& window, Transform_Stack& stack) {

    (void) transform;

    int origin_x = (int) origin_.x;
    int origin_y = (int) origin_.y;

    int end_x = (int) origin_.move_copy (direction_).x;
    int end_y = (int) origin_.move_copy (direction_).y;


    window.set_drawcolor (color_);
    window.draw_line (origin_x, origin_y, end_x, end_y);
}


Processing_result Clock_Arrow::on_timer (clock_t current_time) {

    if (!prev_frame_time_) {

        prev_frame_time_ = current_time;
        return PR_LEFT;
    }


    clock_t time_passed = current_time - prev_frame_time_;
    double seconds_passed = (double) time_passed / (double) CLOCKS_PER_SEC;
    double rotates = 360 * rotates_per_hour_ * speed_scale_* seconds_passed / 3600;
    direction_.rotate (rotates);


    prev_frame_time_ = current_time;


    return PR_LEFT;
}


Processing_result Clock_Arrow::on_keyboard_press (SDL_Keycode key) {

    if (key == SDLK_r)     reset ();
    if (key == SDLK_SPACE) speed_scale_ = 60;


    return PR_LEFT;
}


Processing_result Clock_Arrow::on_keyboard_release (SDL_Keycode key) {

    if (key == SDLK_SPACE) speed_scale_ = 1;


    return PR_LEFT;
}


#ifndef CLOCK_CLASS_ARROW_HPP_INCLUDED
#define CLOCK_CLASS_ARROW_HPP_INCLUDED
//--------------------------------------------------

#include "../../../widgets/hpp/widgets.hpp"

#include "../../../vector/hpp/vector.hpp"

//--------------------------------------------------


class Clock_Arrow: public Widget {

  public:

    Clock_Arrow (Point2D origin, Vector2D direction, double rotates_per_hour);

    //--------------------------------------------------

    void render (Graphic_Window& window, Transform_Stack& transform) override;

    Processing_result on_timer       (clock_t current_time) override;
    Processing_result on_keyboard_press   (SDL_Keycode key) override;
    Processing_result on_keyboard_release (SDL_Keycode key) override;


  private:

    void rotate   (double degrees);
    void speed_up (double scale);
    void reset (void);

    //--------------------------------------------------

    Point2D origin_;
    Vector2D direction_;
    const Vector2D start_direction_;
    My_RGB color_;

    // degrees per second
    double rotates_per_hour_;
    double speed_scale_;

    clock_t prev_frame_time_;
};





//--------------------------------------------------
#endif
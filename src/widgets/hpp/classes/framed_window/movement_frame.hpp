#ifndef WIDGET_CLASS_MOVEMENT_FRAME_HPP_INCLUDED
#define WIDGET_CLASS_MOVEMENT_FRAME_HPP_INCLUDED
//--------------------------------------------------

#include "../../widgets.hpp"

//--------------------------------------------------


class Movement_Frame: public Window {

  public:

    enum Status {

        RESTING,
        MOVING,
    };

    //--------------------------------------------------

    // !controlled must have matching global scale!
    Movement_Frame (Widget& controlled, Window& visible_part);

    void render_with_local_stack
            (Graphic_Window& window, Transform_Stack& local_stack) override;

    Processing_result on_mouse_pressed   (Point2D mouse_position, Transform_Stack& stack) override;
    Processing_result on_mouse_move    (Point2D mouse_position, Transform_Stack& stack) override;
    Processing_result on_mouse_released (Point2D mouse_position, Transform_Stack& stack) override;

//--------------------------------------------------

  private:

    Status status_;
    Widget& controlled_;
    Window& visible_part_;

    // stored in global coordinates
    Point2D last_mouse_position_;
};


//--------------------------------------------------
#endif
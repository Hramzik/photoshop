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

    Movement_Frame (Widget& controlled, Window& visible_part);

    void render_with_local_stack
            (Graphic_Window& window, Transform_Stack& local_stack) override;

    Processing_result on_mouse_press   (int mouse_x, int mouse_y) override;
    Processing_result on_mouse_move    (int mouse_x, int mouse_y) override;
    Processing_result on_mouse_release (int mouse_x, int mouse_y) override;

//--------------------------------------------------

  private:

    Status status_;
    Widget& controlled_;
    Window& visible_part_;

    Vector2D last_mouse_position_;
};


//--------------------------------------------------
#endif
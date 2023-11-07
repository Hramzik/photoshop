

//--------------------------------------------------

#include "../hpp/widgets.hpp"

//--------------------------------------------------

const My_RGB Window_Frame::DEFAULT_FRAME_COLOR = C_LIGHT_GRAY;
const double Window_Frame::DEFAULT_FRAME_HEIGHT        = 30;

//--------------------------------------------------

Framed_Window::Framed_Window (Window& window):
        Widget_Container (window.get_position ()),
        window_ (window),
        frame_  (nullptr)
{
    // window's position is mine now
    window.set_position (0);
    frame_ = new Window_Frame (*this, window_);

    //--------------------------------------------------

    register_background_widget (&window_);
    register_priority_widget   (frame_);
}


Window_Frame::Window_Frame (Widget& controlled, Window& model):
        Widget_Container (model.get_position ()),
        close_button_    (nullptr),
        top_frame_       (nullptr)
{
    Point2D top_frame_position (0, model.get_size().y - DEFAULT_FRAME_HEIGHT);
    double top_frame_width = model.get_size ().x;

    Window* top_frame_visible_part = new Colored_Window (
            top_frame_position,
            Vector2D (top_frame_width, DEFAULT_FRAME_HEIGHT),
            DEFAULT_FRAME_COLOR);

    top_frame_ = new Movement_Frame (controlled, *top_frame_visible_part);

    //--------------------------------------------------

    Point2D close_button_position = top_frame_position;
    close_button_position.x += model.get_size().x - Close_Button::DEFAULT_WIDTH;

    close_button_ = new Close_Button (close_button_position, controlled);

    //--------------------------------------------------

    register_widget (close_button_);
    register_widget (top_frame_);
}

//--------------------------------------------------
// MOVEMENT FRAME

Movement_Frame::Movement_Frame (Widget& controlled, Window& visible_part):
        Window (visible_part.get_position (), visible_part.get_size ()),

        status_              (RESTING),
        controlled_          (controlled),
        visible_part_        (visible_part),
        last_mouse_position_ (0)
{
    visible_part_.set_position (0);
}


void Movement_Frame::render_with_local_stack
            (Graphic_Window& window, Transform_Stack& local_stack) {

    visible_part_.render (window, local_stack);
}

//--------------------------------------------------

Processing_result Movement_Frame::on_mouse_pressed (Point2D mouse_position, Transform_Stack& stack) {

    Point2D local_mouse_position = convert_copy_to_local (mouse_position, stack);
    if (!is_mouse_in_me (local_mouse_position)) return PR_LEFT;

    //--------------------------------------------------

    status_ = MOVING;
    last_mouse_position_ = mouse_position;

    //--------------------------------------------------

    return PR_PROCESSED;
}


Processing_result Movement_Frame::on_mouse_moved (Point2D mouse_position, Transform_Stack& stack) {

    if (status_ == RESTING) return PR_LEFT;


    stack.push (my_transform_);

    //--------------------------------------------------
    // where the magic happens

    Vector2D movement_vector = mouse_position - last_mouse_position_;
    // если у controlled большой scale, его унесет нахуй, поэтому балансим это делением
    movement_vector / (stack.get_result ().get_scale ());
    controlled_.on_move (movement_vector);


    last_mouse_position_ = mouse_position;

    //--------------------------------------------------

    stack.pop ();


    return PR_PROCESSED;
}


Processing_result Movement_Frame::on_mouse_released (Point2D mouse_position, Transform_Stack& stack) {

    (void) mouse_position, (void) stack;


    if (status_ == RESTING) return PR_LEFT;


    status_ = RESTING;


    return PR_PROCESSED;
}




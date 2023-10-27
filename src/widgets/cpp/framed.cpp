

//--------------------------------------------------

#include "../hpp/widgets.hpp"

//--------------------------------------------------

const My_RGB Window_Frame::CLOSE_BUTTON_COLOR = C_RED;
const double Window_Frame::CLOSE_BUTTON_WIDTH = 45;

const My_RGB Window_Frame::DEFAULT_FRAME_COLOR = C_LIGHT_GRAY;
const double Window_Frame::FRAME_HEIGHT        = 30;

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

    register_widget (frame_);
    register_widget (&window_);
}


Window_Frame::Window_Frame (Widget& controlled, Window& model):
        Widget_Container (model.get_position ()),
        close_button_    (nullptr),
        top_frame_       (nullptr)
{
    Vector2D top_frame_position (0, model.get_size().y - FRAME_HEIGHT);

    Window* top_frame_visible_part = new Colored_Window (
            top_frame_position,
            Vector2D (model.get_size ().x, FRAME_HEIGHT),
            DEFAULT_FRAME_COLOR);

    top_frame_ = new Movement_Frame (controlled, *top_frame_visible_part);

    //--------------------------------------------------

    Vector2D close_button_position = top_frame_position;
    close_button_position.x += model.get_size().x - CLOSE_BUTTON_WIDTH;

    close_button_ = new Button (
            close_button_position,
            Vector2D (CLOSE_BUTTON_WIDTH, FRAME_HEIGHT),
            CLOSE_BUTTON_COLOR);

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

Processing_result Movement_Frame::on_mouse_press (int mouse_x, int mouse_y) {

    std::cout << mouse_x << " " << mouse_y << "\n";
    if (!mouse_in_me (mouse_x, mouse_y)) return PR_LEFT;
    std::cout << "mouse in me" << "\n";

    status_ = MOVING;
    last_mouse_position_ = Vector2D (mouse_x, mouse_y);


    return PR_PROCESSED;
}


Processing_result Movement_Frame::on_mouse_move (int mouse_x, int mouse_y) {

    if (status_ == RESTING) return PR_LEFT;


    Vector2D mouse_position (mouse_x, mouse_y);
    controlled_.on_move (mouse_position - last_mouse_position_);

    //--------------------------------------------------

    last_mouse_position_ = mouse_position;


    return PR_PROCESSED;
}


Processing_result Movement_Frame::on_mouse_release (int mouse_x, int mouse_y) {

    (void) mouse_x, (void) mouse_y;


    if (status_ == RESTING) return PR_LEFT;


    status_ = RESTING;


    return PR_PROCESSED;
}




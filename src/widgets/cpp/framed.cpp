

//--------------------------------------------------

#include "widgets/hpp/widgets.hpp"

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

//--------------------------------------------------

Vector2D Framed_Window::get_size (void) {

    return window_.get_size ();
}

//--------------------------------------------------
// FRAMES CODE

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

    top_frame_ = new Driving_Button (*top_frame_visible_part, controlled);

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



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
    frame_ = new Window_Frame (window_);

    //--------------------------------------------------

    register_widget (frame_);
    register_widget (&window_);
}


Window_Frame::Window_Frame (Window model):
        Widget_Container (model.get_position ()),
        close_button_    (nullptr),
        top_frame_       (nullptr)
{
    Vector2D top_frame_position (0, model.get_size().y - FRAME_HEIGHT);

    top_frame_ = new Colored_Window (
            top_frame_position,
            Vector2D (model.get_size ().x, FRAME_HEIGHT),
            DEFAULT_FRAME_COLOR);

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


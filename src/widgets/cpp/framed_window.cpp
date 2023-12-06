

//--------------------------------------------------

#include "Impl/LayoutBox/LayoutBox.h"

#include "widgets/hpp/widgets.hpp"

//--------------------------------------------------

const My_RGB Window_Frame::DEFAULT_FRAME_COLOR        = C_LIGHT_GRAY;
const My_RGB Window_Frame::DEFAULT_CLOSE_BUTTON_COLOR = C_RED;
const double Window_Frame::DEFAULT_FRAME_HEIGHT       = 30;
const double Window_Frame::DEFAULT_CLOSE_BUTTON_WIDTH = 45;

//--------------------------------------------------
// FRAME CODE

Window_Frame::Window_Frame (My_Widget& controlled, My_Widget& model):
        Widget_Container (model.getLayoutBox ()),
        close_button_    (nullptr),
        top_frame_       (nullptr)
{
    //--------------------------------------------------
    // top frame

    plug::Vec2d top_frame_position (0, -model.getLayoutBox ().getSize ().y / 2);
    top_frame_position.y += DEFAULT_FRAME_HEIGHT / 2;

    double top_frame_width = model.getLayoutBox ().getSize ().x;
    LayoutBox top_frame_box (Length (top_frame_width,      Unit::Pixel),
                             Length (DEFAULT_FRAME_HEIGHT, Unit::Pixel));

    top_frame_box.setPosition (top_frame_position);

    My_Widget* top_frame_model = new Colored_Window (top_frame_box, DEFAULT_FRAME_COLOR);

    top_frame_ = new Button (*top_frame_model);
    top_frame_->add_pressed_action (new Drive_Action (controlled));

    //--------------------------------------------------
    // close button

    LayoutBox close_button_box (Length (DEFAULT_CLOSE_BUTTON_WIDTH, Unit::Pixel),
                                Length (DEFAULT_FRAME_HEIGHT,       Unit::Pixel));

    plug::Vec2d close_button_position = top_frame_position;
    close_button_position.x += (top_frame_width - DEFAULT_CLOSE_BUTTON_WIDTH) / 2;
    close_button_box.setPosition (close_button_position);

    My_Widget* close_button_model =
            new Colored_Window (close_button_box, DEFAULT_CLOSE_BUTTON_COLOR);

    close_button_ = new Button (*close_button_model);
    close_button_->add_pressed_action (new Close_Action (controlled));

    //--------------------------------------------------

    register_widget (close_button_);
    register_widget (top_frame_);
}

//--------------------------------------------------
// FRAMED WINDOW CODE

Framed_Window::Framed_Window (My_Widget& controlled):
        Widget_Container (controlled.getLayoutBox ()),

        controlled_ (controlled),
        frame_  (nullptr)
{
    // window's position is mine now
    controlled.getLayoutBox ().setPosition (plug::Vec2d (0, 0));
    std::cout << controlled.getLayoutBox ().getPosition ().x << "\n";
    std::cout << controlled.getLayoutBox ().getPosition ().y << "\n";

    //--------------------------------------------------
    // create frame

    frame_ = new Window_Frame (*this, controlled_);

    //--------------------------------------------------

    register_background_widget (&controlled_);
    register_priority_widget   (frame_);
}

//--------------------------------------------------



//--------------------------------------------------

#include "widgets/hpp/widgets.hpp"

//--------------------------------------------------


Filter_Selection_Widget::Filter_Selection_Widget (Vector2D size, Canvas& canvas):
        Button_Manager (*new Colored_Window (0, size, C_LIGHT_GRAY), 1, 0.02),

        palette_ (),
        canvas_  (canvas) {}

//--------------------------------------------------

Vector2D Filter_Selection_Widget::get_button_size (void) {

    Vector2D size = Button_Manager::get_button_size ();

    //--------------------------------------------------

    size.y = 30;

    //--------------------------------------------------

    return size;
}

//--------------------------------------------------

Filter_Palette& Filter_Selection_Widget::access_palette (void) {

    return palette_;
}


void Filter_Selection_Widget::add_filter (Filter& filter) {

    int filter_id = palette_.add_filter (filter);

    //--------------------------------------------------

    Point2D  position = get_new_button_position ();
    position.y += Window_Frame::DEFAULT_FRAME_HEIGHT;
    Vector2D size     = get_button_size ();

    Window* model  = new Colored_Window (position, size, C_GRAY);
    Button* button = new Filter_Selection_Button (*model, filter_id, palette_, canvas_);

    add_button (*button);
}

//--------------------------------------------------


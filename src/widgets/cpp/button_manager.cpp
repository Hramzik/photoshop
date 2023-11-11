

//--------------------------------------------------

#include <cmath>

#include "../hpp/widgets.hpp"

//--------------------------------------------------

Button_Manager::Button_Manager (Window& background, int line_size, double void_coefficient):
        Widget_Container (background.get_position ()),

        background_ (background),

        buttons_count_ (0),
        BUTTONS_IN_LINE_COUNT_            (line_size),
        VOID_BETWEEN_BUTTONS_COEFFICIENT_ (void_coefficient)
{
    background_.set_position (0);
    register_background_widget (&background_);
}


Button_Manager::Button_Manager (Window& background, int line_size):
        Button_Manager (background, line_size, 0.05) {}

//--------------------------------------------------

void Button_Manager::add_button (Button& button) {

    register_widget (&button);
    ++buttons_count_;
}

//--------------------------------------------------

Vector2D Button_Manager::get_size (void) {

    return background_.get_size ();
}

//--------------------------------------------------

Vector2D Button_Manager::get_button_size (void) {

    double width = (get_size ().x - void_in_line_size()) / BUTTONS_IN_LINE_COUNT_;

    //--------------------------------------------------

    return Vector2D (width);
}


Point2D Button_Manager::get_new_button_position (void) {

    double width_taken_by_buttons = buttons_in_last_line_count () * get_button_size ().x;
    double width_taken_by_void    = (buttons_in_last_line_count () + 1) * void_between_buttons_size ();
    double x = width_taken_by_buttons + width_taken_by_void;

    double height_taken_by_buttons = (button_lines_count () - 1) * get_button_size ().y;
    double height_taken_by_void    = (button_lines_count ()) * void_between_buttons_size ();
    double y = height_taken_by_buttons + height_taken_by_void;
           y = get_size ().y - y - get_button_size ().y; // заполняем сверху
           y -= Window_Frame::DEFAULT_FRAME_HEIGHT;  // размер рамочки

    //--------------------------------------------------

    return Point2D (x, y);
}

//--------------------------------------------------

double Button_Manager::void_between_buttons_size (void) {

    return VOID_BETWEEN_BUTTONS_COEFFICIENT_ * get_size ().x;
}


double Button_Manager::void_in_line_size (void) {

    return void_between_buttons_size () * (BUTTONS_IN_LINE_COUNT_ + 1);
}


int Button_Manager::buttons_in_last_line_count (void) {

    int on_other_lines = (button_lines_count () - 1) * BUTTONS_IN_LINE_COUNT_;

    //--------------------------------------------------

    return buttons_count_ - on_other_lines;
}


int Button_Manager::button_lines_count (void) {

    int full_lines_count = buttons_count_ / BUTTONS_IN_LINE_COUNT_;

    //--------------------------------------------------

    return full_lines_count + 1;
}

//--------------------------------------------------


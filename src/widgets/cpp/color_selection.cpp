

//--------------------------------------------------

#include <cmath>

#include "../hpp/widgets.hpp"

//--------------------------------------------------

Color_Selection_Widget::Color_Selection_Widget (Point2D position, Vector2D size, Tool_Palette& palette):
        Framed_Window (*new Colored_Window (position, size, C_LIGHT_GRAY)),

        palette_       (palette),
        buttons_count_ (0) {}

//--------------------------------------------------

Vector2D Color_Selection_Widget::button_size (void) {

    double width = (get_size ().x - void_in_line_size()) / BUTTONS_IN_LINE_COUNT;

    //--------------------------------------------------

    return Vector2D (width);
}


Point2D Color_Selection_Widget::new_button_position (void) {

    double width_taken_by_buttons = buttons_in_last_line_count () * button_size ().x;
    double width_taken_by_void    = (buttons_in_last_line_count () + 1) * void_between_buttons_size ();
    double x = width_taken_by_buttons + width_taken_by_void;

    double height_taken_by_buttons = (button_lines_count () - 1) * button_size ().y;
    double height_taken_by_void    = (button_lines_count ()) * void_between_buttons_size ();
    double y = height_taken_by_buttons + height_taken_by_void;
           y = get_size ().y - y - button_size ().y; // заполняем сверху
           y -= Window_Frame::DEFAULT_FRAME_HEIGHT;  // размер рамочки

    //--------------------------------------------------

    return Point2D (x, y);
}

//--------------------------------------------------

double Color_Selection_Widget::void_between_buttons_size (void) {

    return VOID_BETWEEN_BUTTONS_COEFFICIENT * get_size ().x;
}


double Color_Selection_Widget::void_in_line_size (void) {

    return void_between_buttons_size () * (BUTTONS_IN_LINE_COUNT + 1);
}


int Color_Selection_Widget::buttons_in_last_line_count (void) {

    int on_other_lines = (button_lines_count () - 1) * BUTTONS_IN_LINE_COUNT;

    //--------------------------------------------------

    return buttons_count_ - on_other_lines;
}


int Color_Selection_Widget::button_lines_count (void) {

    int full_lines_count = buttons_count_ / BUTTONS_IN_LINE_COUNT;

    //--------------------------------------------------

    return full_lines_count + 1;
}

//--------------------------------------------------

void Color_Selection_Widget::add_color_selection_button (My_RGB color) {

    Point2D  position = new_button_position ();
    Vector2D size     = button_size ();

    Button* new_button = new Color_Selection_Button (position, size, color, palette_);

    //--------------------------------------------------

    register_widget (new_button);
    ++buttons_count_;
}

//--------------------------------------------------


#ifndef WIDGETS_CLASS_COLOR_SELECTION_HPP_INCLUDED
#define WIDGETS_CLASS_COLOR_SELECTION_HPP_INCLUDED
//--------------------------------------------------

#include "../../../../my_rgb/hpp/my_rgb.hpp"

#include "../framed_window/framed_window.hpp"

//--------------------------------------------------


class Color_Selection_Widget: public Framed_Window {

  public:

    static constexpr int    BUTTONS_IN_LINE_COUNT = 4;
    static constexpr double VOID_BETWEEN_BUTTONS_COEFFICIENT = 0.05;

    //--------------------------------------------------

    Color_Selection_Widget (Point2D position, Vector2D size, Tool_Palette& palette);

    //--------------------------------------------------

    void add_color_selection_button (My_RGB color);

//--------------------------------------------------

  private:

    Tool_Palette& palette_;
    int           buttons_count_;

    //--------------------------------------------------

    Vector2D button_size         (void);
    Point2D  new_button_position (void);

    double void_in_line_size         (void);
    double void_between_buttons_size (void);

    // if last line is full, the next blank line is counted
    int button_lines_count         (void);
    int buttons_in_last_line_count (void);
};

//--------------------------------------------------
#endif
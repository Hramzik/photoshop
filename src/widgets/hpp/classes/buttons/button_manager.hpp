#ifndef WIDGETS_CLASS_BUTTON_MANAGER_HPP_INCLUDED
#define WIDGETS_CLASS_BUTTON_MANAGER_HPP_INCLUDED
//--------------------------------------------------

#include "../container.hpp"

//--------------------------------------------------

#include "button.hpp"

//--------------------------------------------------

class Button_Manager: public Widget_Container {

  public:

    Button_Manager (Window& background, int line_size, double void_coefficient);
    Button_Manager (Window& background, int line_size);

    //--------------------------------------------------

    Vector2D get_size (void);

    //--------------------------------------------------

    // размер и место должны быть получены моими методами
    void add_button (Button& button);

    virtual Vector2D get_button_size (void);
    Point2D  get_new_button_position (void);

//--------------------------------------------------

  private:

    Window& background_;

    int          buttons_count_;
    const int    BUTTONS_IN_LINE_COUNT_;
    const double VOID_BETWEEN_BUTTONS_COEFFICIENT_;

    //--------------------------------------------------


    //--------------------------------------------------

    double void_in_line_size         (void);
    double void_between_buttons_size (void);

    // if last line is full, the next blank line is counted
    int button_lines_count         (void);
    int buttons_in_last_line_count (void);
};

//--------------------------------------------------
#endif
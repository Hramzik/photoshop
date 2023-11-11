

//--------------------------------------------------

#include <cmath>

#include "../hpp/widgets.hpp"

//--------------------------------------------------

Color_Selection_Widget::Color_Selection_Widget (Point2D position, Vector2D size, Tool_Palette& palette):
        Framed_Window (*new Window (position, size)),

        palette_ (palette),
        buttons_ (*new Colored_Window (0, size, C_LIGHT_GRAY), 4, 0.05)
{
    register_widget (&buttons_);
}

//--------------------------------------------------

void Color_Selection_Widget::add_color_selection_button (My_RGB color) {

    Point2D  position = buttons_.get_new_button_position ();
    Vector2D size     = buttons_.get_button_size ();

    Window* button_model = new Colored_Window (position, size, color);
    Button* new_button   = new Color_Selection_Button (*button_model, color, palette_);

    //--------------------------------------------------

    buttons_.add_button (*new_button);
}

//--------------------------------------------------


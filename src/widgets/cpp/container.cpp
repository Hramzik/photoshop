

//--------------------------------------------------


#include "../hpp/widgets.hpp"


//--------------------------------------------------


Processing_result
Widget_Container::on_mouse_move (int mouse_x, int mouse_y) {

    for (auto i = widgets_.begin (); i < widgets_.end (); ++i) {

        ;
    }
}


Processing_result Widget_Container::on_mouse_press (int mouse_x, int mouse_y)
Processing_result Widget_Container::on_mouse_release (int mouse_x, int mouse_y)

Processing_result Widget_Container::on_keyboard_press   (SDL_Keycode key)
Processing_result Widget_Container::on_keyboard_release (SDL_Keycode key)

Processing_result Widget_Container::on_timer (clock_t current_time)
#ifndef WIDGETS_CLASS_BUTTON_HPP_INCLUDED
#define WIDGETS_CLASS_BUTTON_HPP_INCLUDED
//--------------------------------------------------

#include "../../../../vector/hpp/vector.hpp"
#include "../../../../transform/hpp/transform.hpp"

#include "../windows/windows.hpp"

//--------------------------------------------------


class Button: public Window {

  public:

    enum State {

        PRESSED,
        RELEASED,
    };

    //--------------------------------------------------

    Button (Vector2D position, Vector2D size, My_RGB color);

    Button    (const Button&) = delete;
    operator= (const Button&) = delete;

    //--------------------------------------------------

    State get_state (void);

    void render (Graphic_Window& window, Transform_Stack& stack) override;

    Processing_result on_mouse_press (int mouse_x, int mouse_y) override;

//--------------------------------------------------

  protected:

    // is rendered not using button transform!
    Window* visible_part;
    State  state_ = RELEASED;
};


//--------------------------------------------------
#endif
#ifndef WIDGETS_CLASS_WIDGET_HPP_INCLUDED
#define WIDGETS_CLASS_WIDGET_HPP_INCLUDED
//--------------------------------------------------

#include "../../../graphics/hpp/graphics.hpp"
#include "../../../transform/hpp/transform.hpp"
#include "../../../vector/hpp/vector.hpp"

//--------------------------------------------------

#include "../enums.hpp"

//--------------------------------------------------


class Widget {

  public:

    enum State {

        OPENED,
        CLOSED,
    };

    //--------------------------------------------------

    Widget (Transform transform);
    Widget (Vector2D  position);
    virtual ~Widget (void);

    //--------------------------------------------------

    virtual void render (Graphic_Window& window, Transform_Stack& transform);

    virtual Processing_result on_mouse_move    (int mouse_x, int mouse_y);
    virtual Processing_result on_mouse_press   (int mouse_x, int mouse_y);
    virtual Processing_result on_mouse_release (int mouse_x, int mouse_y);
    virtual Processing_result on_keyboard_press   (SDL_Keycode key);
    virtual Processing_result on_keyboard_release (SDL_Keycode key);
    virtual Processing_result on_timer (clock_t current_time);

    virtual Transform get_transform (void) const;
    virtual void      set_transform (const Transform& transform);

//--------------------------------------------------

  protected:

    Transform my_transform_;
    State     state;

};


//--------------------------------------------------
#endif
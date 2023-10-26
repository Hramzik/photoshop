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

    Vector2D  get_position  (void);
    void      set_position  (Vector2D position);
    Transform get_transform (void) const;
    void      set_transform (const Transform& transform);

    //--------------------------------------------------

    // pushes my_transform and calls protected render function
    virtual void render (Graphic_Window& window, Transform_Stack& stack);

    virtual Processing_result on_mouse_move    (int mouse_x, int mouse_y);
    virtual Processing_result on_mouse_press   (int mouse_x, int mouse_y);
    virtual Processing_result on_mouse_release (int mouse_x, int mouse_y);
    virtual Processing_result on_keyboard_press   (SDL_Keycode key);
    virtual Processing_result on_keyboard_release (SDL_Keycode key);
    virtual Processing_result on_timer (clock_t current_time);


//--------------------------------------------------

  protected:

    // used by public render function
    // transform_stack holds local transform
    virtual void render_with_local_stack
            (Graphic_Window& window, Transform_Stack& result_stack);

    virtual void render_with_final_transform
            (Graphic_Window& window, const Transform& result_transform);

    //--------------------------------------------------

    Transform my_transform_;
    State     state;

};


//--------------------------------------------------
#endif
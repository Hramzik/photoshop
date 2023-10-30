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

    bool is_closed (void);
    void close     (void);

    Vector2D  get_position  (void);
    void      set_position  (Vector2D position);
    Transform get_transform (void) const;
    void      set_transform (const Transform& transform);

    //--------------------------------------------------

    // pushes my_transform and calls protected render function
    virtual void render (Graphic_Window& window, Transform_Stack& stack);

    virtual Processing_result on_mouse_moved    (Point2D mouse_position, Transform_Stack& stack);
    virtual Processing_result on_mouse_pressed  (Point2D mouse_position, Transform_Stack& stack);
    virtual Processing_result on_mouse_released (Point2D mouse_position, Transform_Stack& stack);
    virtual Processing_result on_keyboard_pressed  (SDL_Keycode key);
    virtual Processing_result on_keyboard_released (SDL_Keycode key);
    virtual Processing_result on_timer (clock_t current_time);

    virtual void on_move (Vector2D offset);

//--------------------------------------------------

  protected:

    // used by public render function
    // transform_stack holds local transform
    virtual void render_with_local_stack
            (Graphic_Window& window, Transform_Stack& local_stack);
    virtual void render_with_final_transform
            (Graphic_Window& window, const Transform& result_transform);

    // todo: const global_stack&
    void    conver_to_local      (Point2D& point, Transform_Stack& global_stack);
    Point2D conver_copy_to_local (Point2D  point, Transform_Stack& global_stack);

    //--------------------------------------------------

    Transform my_transform_;
    State     state_;

};


//--------------------------------------------------
#endif
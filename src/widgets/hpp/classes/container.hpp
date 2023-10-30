#ifndef WIDGETS_CLASS_CONTAINER_HPP_INCLUDED
#define WIDGETS_CLASS_CONTAINER_HPP_INCLUDED
//--------------------------------------------------

#include <vector>
#include <list>

//--------------------------------------------------

#include "widget.hpp"

//--------------------------------------------------


class Widget_Container: public Widget {

  public:

    Widget_Container (Transform transform);
    Widget_Container (Vector2D position);

    Widget_Container (const Widget_Container&) = delete;
    operator=        (const Widget_Container&) = delete;

    //--------------------------------------------------

    void register_widget (Widget* widget);

    void render_with_local_stack
            (Graphic_Window& window, Transform_Stack& stack) override;

    Processing_result on_mouse_moved    (Point2D mouse_position, Transform_Stack& stack) override;
    Processing_result on_mouse_pressed   (Point2D mouse_position, Transform_Stack& stack) override;
    Processing_result on_mouse_released (Point2D mouse_position, Transform_Stack& stack) override;
    Processing_result on_keyboard_pressed   (SDL_Keycode key)                       override;
    Processing_result on_keyboard_released (SDL_Keycode key)                       override;
    Processing_result on_timer (clock_t current_time)                             override;

//--------------------------------------------------

  protected:

    Vector2D get_local_mouse_position (int mouse_x, int mouse_y);

    //--------------------------------------------------

    std::list <Widget*> widgets_;
    Widget*             active_widget_;
};


//--------------------------------------------------
#endif
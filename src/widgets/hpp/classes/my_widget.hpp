#ifndef CLASS_MY_WIDGET_HPP_INCLUDED
#define CLASS_MY_WIDGET_HPP_INCLUDED
//--------------------------------------------------

#pragma GCC diagnostic push 
#pragma GCC diagnostic ignored "-Weffc++"

#include "Impl/Widget.h"

#pragma GCC diagnostic pop

//--------------------------------------------------

class My_Widget: public Widget {

  public:

    enum State {

        OPENED,
        CLOSED,
    };

    //--------------------------------------------------

    explicit My_Widget (const plug::LayoutBox& box);
    //virtual ~My_Widget (void) = default;

    //--------------------------------------------------

    // my function
    virtual void draw (plug::RenderTarget&  target, plug::TransformStack& stack);

    // standart function
    void         draw (plug::TransformStack& stack, plug::RenderTarget&   target) override;

    //--------------------------------------------------

    bool is_closed (void);
    void close     (void);

    //Point2D   get_position  (void);
    //void      set_position  (Point2D position);
    //Transform get_transform (void) const;
    //void      set_transform (const Transform& transform);

    //--------------------------------------------------

    // pushes my_transform and calls protected render function
    //virtual void render (Graphic_Window& window, Transform_Stack& stack);
//
    //virtual Processing_result on_mouse_moved    (Point2D mouse_position, Transform_Stack& stack);
    //virtual Processing_result on_mouse_pressed  (Point2D mouse_position, Transform_Stack& stack);
    //virtual Processing_result on_mouse_released (Point2D mouse_position, Transform_Stack& stack);
    //virtual Processing_result on_keyboard_pressed  (SDL_Keycode key);
    //virtual Processing_result on_keyboard_released (SDL_Keycode key);
    //virtual Processing_result on_timer (clock_t current_time);
//
    //virtual void on_move (Vector2D offset);

//--------------------------------------------------

  protected:

    State state_;

    //--------------------------------------------------

    //used by public draw function
    //transform_stack holds local transform
    virtual void draw_with_local_stack
    (plug::RenderTarget& target, plug::TransformStack& stack);

    virtual void draw_with_final_transform
    (plug::RenderTarget& target, plug::Transform& transform);

    //--------------------------------------------------

    plug::VertexArray get_render_shape (void);
};


//--------------------------------------------------
#endif
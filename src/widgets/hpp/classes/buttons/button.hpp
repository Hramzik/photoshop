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
        HOVERED,
    };

    //--------------------------------------------------

    // model is rendered not using button transform
    Button (Window& model);

    Button    (const Button&) = delete;
    operator= (const Button&) = delete;

    //--------------------------------------------------

    State get_state (void);

    virtual void do_when_pressed  (void);
    virtual void do_when_released (void);
    virtual void do_when_hovered   (void);
    virtual void do_when_unhovered (void);

    //--------------------------------------------------

    void render (Graphic_Window& window, Transform_Stack& stack) override;

    Processing_result on_mouse_pressed  (Point2D mouse_position, Transform_Stack& stack) override;
    Processing_result on_mouse_released (Point2D mouse_position, Transform_Stack& stack) override;
    Processing_result on_mouse_moved    (Point2D mouse_position, Transform_Stack& stack) override;


//--------------------------------------------------

  protected:

    Window& model_;
    State   state_ = RELEASED;
};


//--------------------------------------------------
#endif
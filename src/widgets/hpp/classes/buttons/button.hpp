#ifndef WIDGETS_CLASS_BUTTON_HPP_INCLUDED
#define WIDGETS_CLASS_BUTTON_HPP_INCLUDED
//--------------------------------------------------

#include "widgets/hpp/classes/my_widget.hpp"

#include "widgets/hpp/classes/actions/action.hpp"
#include "widgets/hpp/classes/actions/button_action.hpp"

//--------------------------------------------------


class Button: public My_Widget {

  public:

    enum Button_state {

        PRESSED,
        RELEASED,
        HOVERED,
    };

    //--------------------------------------------------

    // model is rendered not using button transform
    Button (My_Widget& model);

    void add_pressed_action  (Action*        action);
    void add_held_action     (Button_Action* action);
    void add_released_action (Action*        action);

    Button_state get_button_state (void);
    plug::Vec2d get_last_held_position (void);

    //--------------------------------------------------

    void render (plug::RenderTarget& target, plug::TransformStack& stack) override;

    void onMousePressed  (const plug::MousePressedEvent&  event, plug::EHC& context) override;
    void onMouseReleased (const plug::MouseReleasedEvent& event, plug::EHC& context) override;
    void onMouseMove     (const plug::MouseMoveEvent&     event, plug::EHC& context) override;

//--------------------------------------------------

  private:

    My_Widget& model_;

    Action* pressed_action_  = nullptr;
    Action* held_action_     = nullptr;
    Action* released_action_ = nullptr;

    Button_state button_state_       = RELEASED;
    plug::Vec2d  last_held_position_ = plug::Vec2d ();

    //--------------------------------------------------

    void call_action (Action* action);
};


//--------------------------------------------------
#endif
#ifndef WIDGETS_CLASS_VISIBLE_WINDOW_HPP_INCLUDED
#define WIDGETS_CLASS_VISIBLE_WINDOW_HPP_INCLUDED
//--------------------------------------------------

#include "widgets/hpp/classes/my_widget.hpp"

//--------------------------------------------------

// Visible_Window is a widget, that catches clicks
class Visible_Window: public My_Widget {

  public:

    Visible_Window (plug::LayoutBox& box);

    //--------------------------------------------------

    void onMousePressed  (const plug::MousePressedEvent&  event, plug::EHC& context) override;
    void onMouseReleased (const plug::MouseReleasedEvent& event, plug::EHC& context) override;

  private:

    bool has_mouse_focus_ = false;
};


//--------------------------------------------------
#endif
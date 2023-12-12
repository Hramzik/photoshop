#ifndef WIDGET_DECORATOR_HPP_INCLUDED
#define WIDGET_DECORATOR_HPP_INCLUDED
//--------------------------------------------------

#include "my_widget.hpp"

//--------------------------------------------------

class Widget_Decorator: public My_Widget {

  public:

    Widget_Decorator (My_Widget& decorated);

    //--------------------------------------------------

    void render  (plug::RenderTarget& target, plug::TransformStack& stack) override;
    void onEvent (const plug::Event& event, plug::EHC& context)            override;

    void onParentUpdate (const plug::LayoutBox &parent_box) override;

    plug::LayoutBox&       getLayoutBox (void)                       override;
    const plug::LayoutBox& getLayoutBox (void) const                 override;
    void                   setLayoutBox (const plug::LayoutBox& box) override;

//--------------------------------------------------

  private:

    My_Widget& decorated_;
};


//--------------------------------------------------
#endif
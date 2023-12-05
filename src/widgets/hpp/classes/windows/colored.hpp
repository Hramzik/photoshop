#ifndef WIDGETS_CLASS_COLORED_WINDOW_HPP_INCLUDED
#define WIDGETS_CLASS_COLORED_WINDOW_HPP_INCLUDED
//--------------------------------------------------

#include "my_rgb/hpp/my_rgb.hpp"
#include "widgets/hpp/classes/my_widget.hpp"

//--------------------------------------------------


class Colored_Window: public My_Widget {

  public:

    Colored_Window (plug::LayoutBox box, My_RGB color);

//--------------------------------------------------

  protected:

    virtual void draw_with_local_stack
    (plug::RenderTarget& target, plug::TransformStack& stack)
    override;

    virtual void draw_with_final_transform
    (plug::RenderTarget& target, plug::Transform& transform)
    override;

    //--------------------------------------------------

    My_RGB color_;
};


//--------------------------------------------------
#endif
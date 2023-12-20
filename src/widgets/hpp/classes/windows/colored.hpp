#ifndef WIDGETS_CLASS_COLORED_WINDOW_HPP_INCLUDED
#define WIDGETS_CLASS_COLORED_WINDOW_HPP_INCLUDED
//--------------------------------------------------

#include "my_rgb/hpp/my_rgb.hpp"

#include "window.hpp"

//--------------------------------------------------


class Colored_Window: public Visible_Window {

  public:

    Colored_Window (plug::LayoutBox& box, My_RGB color);

    //--------------------------------------------------

    virtual void render (plug::RenderTarget& target, plug::TransformStack& stack) override;

//--------------------------------------------------

  private:

    My_RGB color_;
};


//--------------------------------------------------
#endif
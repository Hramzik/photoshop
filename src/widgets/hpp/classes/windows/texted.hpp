#ifndef WIDGETS_CLASS_TEXTED_WINDOW_HPP_INCLUDED
#define WIDGETS_CLASS_TEXTED_WINDOW_HPP_INCLUDED
//--------------------------------------------------

#include "widgets/hpp/classes/my_widget.hpp"

//--------------------------------------------------


class Texted_Window: public My_Widget {

  public:

    Texted_Window (plug::LayoutBox& box, const char* text, My_RGB text_color, My_RGB bg_color);

    //--------------------------------------------------

    virtual void render (plug::RenderTarget& target, plug::TransformStack& stack) override;

//--------------------------------------------------

  private:

    plug::Texture* texture_;
};


//--------------------------------------------------
#endif
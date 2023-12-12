#ifndef WIDGETS_CLASS_TEXTURED_WINDOW_HPP_INCLUDED
#define WIDGETS_CLASS_TEXTURED_WINDOW_HPP_INCLUDED
//--------------------------------------------------

#include "widgets/hpp/classes/my_widget.hpp"

//--------------------------------------------------


class Textured_Window: public My_Widget {

  public:

    Textured_Window (plug::LayoutBox& box, const char* texture_path);
    Textured_Window (plug::LayoutBox& box, plug::Texture& texture);

    //--------------------------------------------------

    virtual void render (plug::RenderTarget& target, plug::TransformStack& stack) override;

//--------------------------------------------------

  private:

    plug::Texture* texture_;
};


//--------------------------------------------------
#endif
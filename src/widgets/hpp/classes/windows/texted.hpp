#ifndef WIDGETS_CLASS_TEXTED_WINDOW_HPP_INCLUDED
#define WIDGETS_CLASS_TEXTED_WINDOW_HPP_INCLUDED
//--------------------------------------------------

#include "window.hpp"

//--------------------------------------------------

class Texted_Window: public Visible_Window {

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
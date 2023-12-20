#ifndef WIDGETS_CLASS_TEXTURED_WINDOW_HPP_INCLUDED
#define WIDGETS_CLASS_TEXTURED_WINDOW_HPP_INCLUDED
//--------------------------------------------------

#include "window.hpp"

//--------------------------------------------------

class Textured_Window: public Visible_Window {

  public:

    Textured_Window (plug::LayoutBox& box, const char* texture_path);

    //--------------------------------------------------

    virtual void render (plug::RenderTarget& target, plug::TransformStack& stack) override;

//--------------------------------------------------

  private:

    plug::Texture* texture_;
};


//--------------------------------------------------
#endif
#ifndef WIDGETS_CLASS_TEXTED_WINDOW_HPP_INCLUDED
#define WIDGETS_CLASS_TEXTED_WINDOW_HPP_INCLUDED
//--------------------------------------------------

#include "window.hpp"

//--------------------------------------------------

class Texted_Window: public Visible_Window {

  public:

    Texted_Window (plug::LayoutBox& box, const char* text, My_RGB text_color, My_RGB bg_color);

    //--------------------------------------------------

    void set_text_size_ratio   (void);
    void push_text_to_the_left (void);

    //--------------------------------------------------

    virtual void render (plug::RenderTarget& target, plug::TransformStack& stack) override;

//--------------------------------------------------

  private:

    plug::Texture* texture_;
    plug::Color    bg_color_;

    //--------------------------------------------------

    bool is_text_pushed_to_the_left_;
    void render_with_pushed_text (plug::RenderTarget& target, plug::TransformStack& stack);
};


//--------------------------------------------------
#endif
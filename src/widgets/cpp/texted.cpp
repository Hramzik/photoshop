

//--------------------------------------------------

#include "widgets/hpp/widgets.hpp"

//--------------------------------------------------

Texted_Window::Texted_Window (plug::LayoutBox& box, const char* text, My_RGB text_color, My_RGB bg_color):
        Visible_Window (box),

        texture_ (nullptr)
{
    MyRenderTexture tmp_texture;
    tmp_texture.loadText (text, text_color, bg_color);

    //--------------------------------------------------

    texture_ = &getTexture (tmp_texture);
}

//--------------------------------------------------

void Texted_Window::set_text_size_ratio (void) {

    double w_h_ratio = (double) texture_->width / (double) texture_->height;

    //--------------------------------------------------

    plug::Vec2d size = getLayoutBox ().getSize ();
    size.x = w_h_ratio * size.y;

    getLayoutBox ().setSize (size);
}

void Texted_Window::render (plug::RenderTarget& target, plug::TransformStack& stack) {

    if (!texture_) return;

    //--------------------------------------------------

    plug::VertexArray shape = get_render_shape (stack);

    //--------------------------------------------------

    target.draw (shape, *texture_);
}

//--------------------------------------------------


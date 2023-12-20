

//--------------------------------------------------

#include "widgets/hpp/widgets.hpp"

//--------------------------------------------------

Texted_Window::Texted_Window (plug::LayoutBox& box, const char* text, My_RGB text_color, My_RGB bg_color):
        My_Widget (box),

        texture_ (nullptr)
{
    MyRenderTexture tmp_texture;
    tmp_texture.loadText (text, text_color, bg_color);

    //--------------------------------------------------

    texture_ = &getTexture (tmp_texture);
}

//--------------------------------------------------

void Texted_Window::render (plug::RenderTarget& target, plug::TransformStack& stack) {

    if (!texture_) return;

    //--------------------------------------------------

    plug::VertexArray shape = get_render_shape (stack);

    //--------------------------------------------------

    target.draw (shape, *texture_);
}

//--------------------------------------------------


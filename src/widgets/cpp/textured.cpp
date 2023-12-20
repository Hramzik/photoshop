

//--------------------------------------------------

#include "widgets/hpp/widgets.hpp"

//--------------------------------------------------

Textured_Window::Textured_Window (plug::LayoutBox& box, const char* texture_path):
        Visible_Window (box),

        texture_ (nullptr)
{
    MyRenderTexture tmp_texture;
    tmp_texture.loadFromFile (texture_path);

    //--------------------------------------------------

    texture_ = &getTexture (tmp_texture);
}

//--------------------------------------------------

void Textured_Window::render (plug::RenderTarget& target, plug::TransformStack& stack) {

    if (!texture_) return;

    //--------------------------------------------------

    plug::VertexArray shape = get_render_shape (stack);

    //--------------------------------------------------

    target.draw (shape, *texture_);
}

//--------------------------------------------------


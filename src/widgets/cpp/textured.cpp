

//--------------------------------------------------

#include "widgets/hpp/widgets.hpp"

//--------------------------------------------------

Textured_Window::Textured_Window (plug::LayoutBox& box, plug::Texture& texture):
        My_Widget (box),

        texture_ (texture) {}

//--------------------------------------------------

void Textured_Window::render (plug::RenderTarget& target, plug::TransformStack& stack) {

    plug::VertexArray shape = get_render_shape (stack);

    std::cout << texture_.width << " " << texture_.height << "\n";

    //--------------------------------------------------

    target.draw (shape, texture_);
}

//--------------------------------------------------


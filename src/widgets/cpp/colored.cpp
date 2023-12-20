

//--------------------------------------------------

#include "widgets/hpp/widgets.hpp"

//--------------------------------------------------

Colored_Window::Colored_Window (plug::LayoutBox& box, My_RGB color):
        Visible_Window (box),

        color_ (color) {}

//--------------------------------------------------

void Colored_Window::render (plug::RenderTarget& target, plug::TransformStack& stack) {

    plug::VertexArray shape = get_render_shape (stack);

    for (int i = 0; i < (int) shape.getSize (); ++i) {

        shape [i].color = plug::Color (color_.r, color_.g, color_.b);
    }

    //--------------------------------------------------

    target.draw (shape);
}



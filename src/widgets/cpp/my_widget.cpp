

//--------------------------------------------------

#include "widgets/hpp/widgets.hpp"

//--------------------------------------------------

My_Widget::My_Widget (const plug::LayoutBox& box):
    Widget (box),
    state_ (OPENED) {}

//--------------------------------------------------

bool My_Widget::is_closed (void) {

    if (state_ == CLOSED) return true;


    return false;
}


void My_Widget::close (void) {

    state_ = CLOSED;
}

//--------------------------------------------------

//--------------------------------------------------
// standart draw funciton

void My_Widget::draw (plug::TransformStack& stack, plug::RenderTarget& target) {

    draw (target, stack);
}

//--------------------------------------------------
// my draw function (switched parameter places)

void My_Widget::draw (plug::RenderTarget& target, plug::TransformStack& stack) {

    plug::Transform transform (getLayoutBox ().getPosition (), plug::Vec2d (1));
    stack.enter(transform);

    //--------------------------------------------------

    draw_with_local_stack (target, stack);

    //--------------------------------------------------

    stack.leave();
}

//--------------------------------------------------

void My_Widget::draw_with_local_stack
(plug::RenderTarget& target, plug::TransformStack& stack)
{
    plug::Transform result_transform = stack.top();
    draw_with_final_transform (target, result_transform);
}

//--------------------------------------------------

void My_Widget::draw_with_final_transform
(plug::RenderTarget& target, plug::Transform& transform)
{
    (void) target;
    (void) transform;
}

//--------------------------------------------------

plug::VertexArray My_Widget::get_render_shape (plug::TransformStack& stack) {

    plug::VertexArray shape (plug::Quads, 4);

    //--------------------------------------------------

    shape [0].position = getCorner (Corner::TopLeft,     stack);
    shape [1].position = getCorner (Corner::TopRight,    stack);
    shape [2].position = getCorner (Corner::BottomRight, stack);
    shape [3].position = getCorner (Corner::BottomLeft,  stack);

    //--------------------------------------------------

    for (size_t i = 0; i < 4; ++i) {

        shape [i].color = plug::Color(255, 255, 255, 255);
    }

    //--------------------------------------------------

    return shape;
}

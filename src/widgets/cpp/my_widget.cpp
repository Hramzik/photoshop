

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

    render (target, stack);
}

//--------------------------------------------------
// my draw function (switched parameter places)

void My_Widget::render (plug::RenderTarget& target, plug::TransformStack& stack) {

    (void) target; (void) stack;
}

//--------------------------------------------------

plug::VertexArray My_Widget::get_render_shape (plug::TransformStack& stack) {

    plug::Transform transform (getLayoutBox ().getPosition (), plug::Vec2d (1, 1));
    stack.enter(transform);

    //--------------------------------------------------

    plug::Transform top_transform = stack.top ();

    plug::Vec2d position = top_transform.apply (plug::Vec2d (0));
    plug::Vec2d size     = top_transform.getScale () * getLayoutBox ().getSize ();

    //--------------------------------------------------


    plug::VertexArray shape (plug::Quads, 4);

    shape [0].position = plug::Vec2d (position.x - size.x / 2, position.y - size.y / 2);
    shape [1].position = plug::Vec2d (position.x + size.x / 2, position.y - size.y / 2);
    shape [2].position = plug::Vec2d (position.x + size.x / 2, position.y + size.y / 2);
    shape [3].position = plug::Vec2d (position.x - size.x / 2, position.y + size.y / 2);

    shape [0].tex_coords = plug::Vec2d (0, 0);
    shape [1].tex_coords = plug::Vec2d (1, 0);
    shape [2].tex_coords = plug::Vec2d (1, 1);
    shape [3].tex_coords = plug::Vec2d (0, 1);

    //--------------------------------------------------

    for (size_t i = 0; i < 4; ++i) {

        shape [i].color = plug::Color(255, 255, 255, 255);
    }

    //--------------------------------------------------

    stack.leave ();


    return shape;
}

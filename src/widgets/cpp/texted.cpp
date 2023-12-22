

//--------------------------------------------------

#include "widgets/hpp/widgets.hpp"

//--------------------------------------------------

Texted_Window::Texted_Window (plug::LayoutBox& box, const char* text, My_RGB text_color, My_RGB bg_color):
        Visible_Window (box),

        texture_  (nullptr),
        bg_color_ (plug::Color (bg_color.r, bg_color.g, bg_color.b)),

        is_text_pushed_to_the_left_ (false)
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

void Texted_Window::push_text_to_the_left (void) {

    is_text_pushed_to_the_left_ = true;
}

//--------------------------------------------------

void Texted_Window::render (plug::RenderTarget& target, plug::TransformStack& stack) {

    if (is_text_pushed_to_the_left_) return render_with_pushed_text (target, stack);
    if (!texture_) return;

    //--------------------------------------------------

    plug::VertexArray shape = get_render_shape (stack);

    //--------------------------------------------------

    target.draw (shape, *texture_);
}

void Texted_Window::render_with_pushed_text (plug::RenderTarget& target, plug::TransformStack& stack) {

    if (!texture_) return;

    //--------------------------------------------------
    // background

    plug::VertexArray background = get_render_shape (stack);

    for (int i = 0; i < (int) background.getSize (); ++i) {

        background [i].color = plug::Color (bg_color_.r, bg_color_.g, bg_color_.b);
    }

    target.draw (background);

    //--------------------------------------------------
    // actual text

    plug::VertexArray text_shape = get_render_shape (stack);

    double w_h_ratio = (double) texture_->width / (double) texture_->height;
    double text_width = getLayoutBox ().getSize ().y * w_h_ratio;

    text_shape [1].position.x = text_shape [0].position.x + text_width;
    text_shape [2].position.x = text_shape [3].position.x + text_width;

    target.draw (text_shape, *texture_);
}

//--------------------------------------------------


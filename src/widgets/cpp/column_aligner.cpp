
//--------------------------------------------------

#include "widgets/hpp/widgets.hpp"

//--------------------------------------------------

Column_Aligner::Column_Aligner (My_Widget& background):
        Column_Aligner (background, plug::Vec2d (0.3, 0.3)) {}

Column_Aligner::Column_Aligner
(My_Widget& background, plug::Vec2d relative_padding_size):
        Widget_Aligner (background),

        inner_padding_size_ (relative_padding_size),
        tl_padding_size_    (inner_padding_size_),
        br_padding_size_    (inner_padding_size_),

        next_widget_vertical_offset_ (0)
{
    //--------------------------------------------------
    // left-top coordinates

    background_.getLayoutBox ().setPosition (getLayoutBox ().getSize () / 2);

    //--------------------------------------------------

    next_widget_vertical_offset_ = tl_padding_size_.y * get_widget_width ();
}

//--------------------------------------------------

void Column_Aligner::post_adding_procedure (My_Widget& new_widget) {

    //--------------------------------------------------
    // next widget offset

    next_widget_vertical_offset_ += new_widget.getLayoutBox ().getSize ().y;
    next_widget_vertical_offset_ += inner_padding_size_.y * get_widget_width ();

    //--------------------------------------------------
    // moving and resizing

    plug::Vec2d new_size (getLayoutBox ().getSize ().x, next_widget_vertical_offset_);

    // we need to move down, otherwise we will grow up and down (and we want ONLY down XDD)
    plug::Vec2d new_position = getLayoutBox ().getPosition ();
    new_position.y += 1 / 2 * (next_widget_vertical_offset_ - getLayoutBox ().getSize ().y);

    //--------------------------------------------------

    plug::LayoutBox& new_box = getLayoutBox ();
    new_box.setSize     (new_size);
    new_box.setPosition (new_position);
    setLayoutBox (new_box);
}

//--------------------------------------------------

double Column_Aligner::get_widget_width (void) {

    double
    relative_width  = 1;
    relative_width += tl_padding_size_.x;
    relative_width += br_padding_size_.x;

    //--------------------------------------------------

    return getLayoutBox ().getSize ().x / relative_width;
}

void Column_Aligner::resize_new_widget (My_Widget& new_widget) {

    double new_width = get_widget_width ();
    plug::Vec2d new_size = plug::Vec2d (new_width, new_widget.getLayoutBox ().getSize ().y);

    //--------------------------------------------------

    plug::LayoutBox& box = new_widget.getLayoutBox ();
    box.setSize (new_size);
    new_widget.setLayoutBox (box);
}

void Column_Aligner::move_new_widget (My_Widget& new_widget) {

    double x = tl_padding_size_.x * get_widget_width ();
    double y = next_widget_vertical_offset_;

    //--------------------------------------------------

    plug::Vec2d new_position (x, y);
    plug::Vec2d widget_size = new_widget.getLayoutBox ().getSize ();
    new_position += widget_size / 2;

    //--------------------------------------------------

    plug::LayoutBox& box = new_widget.getLayoutBox ();
    box.setPosition (new_position);
    new_widget.setLayoutBox (box);
}

//--------------------------------------------------

void Column_Aligner::onEvent (const plug::Event& event, plug::EHC& context) {

    plug::Transform coordinate_switcher (-0.5 * getLayoutBox ().getSize ());
    context.stack.enter (coordinate_switcher);

    //--------------------------------------------------

    Widget_Container::onEvent (event, context);

    //--------------------------------------------------

    context.stack.leave ();
}

void Column_Aligner::render (plug::RenderTarget& target, plug::TransformStack& stack) {

    plug::Transform coordinate_switcher (-0.5 * getLayoutBox ().getSize ());
    stack.enter (coordinate_switcher);

    //--------------------------------------------------

    Widget_Container::render (target, stack);

    //--------------------------------------------------

    stack.leave ();
}

void Column_Aligner::setLayoutBox (const plug::LayoutBox& box) {

    //--------------------------------------------------
    // default

    My_Widget::setLayoutBox (box);

    //--------------------------------------------------
    // background needs a resize and move to center

    background_.setLayoutBox (box);
    background_.getLayoutBox ().setPosition (getLayoutBox ().getSize () / 2);

    //--------------------------------------------------
    // rebuild widgets (cringe)

    if (widgets_.size ()) return;
    next_widget_vertical_offset_ = tl_padding_size_.y * get_widget_width ();
}

//--------------------------------------------------


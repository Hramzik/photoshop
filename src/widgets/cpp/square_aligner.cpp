

//--------------------------------------------------

#include "widgets/hpp/widgets.hpp"

//--------------------------------------------------

Square_Aligner::Square_Aligner
(My_Widget& background, int widgets_in_line, plug::Vec2d relative_padding_size):
        Widget_Aligner (background),

        widgets_in_line_ (widgets_in_line),

        free_line_index             (0),
        widgets_in_free_line_count_ (0),

        inner_padding_size_ (relative_padding_size),
        tl_padding_size_    (inner_padding_size_),
        br_padding_size_    (inner_padding_size_)
{
    background_.getLayoutBox ().setPosition (plug::Vec2d (0, 0));
    register_background_widget (&background_);
}

Square_Aligner::Square_Aligner (My_Widget& background, int widgets_in_line):
        Square_Aligner (background, widgets_in_line, plug::Vec2d (0.15, 0.15)) {}

//--------------------------------------------------

void Square_Aligner::post_adding_procedure (void) {

    ++widgets_in_free_line_count_;

    //--------------------------------------------------

    if (widgets_in_free_line_count_ != widgets_in_line_) return;

    //--------------------------------------------------

    ++free_line_index;
    widgets_in_free_line_count_ = 0;
}


//--------------------------------------------------

double Square_Aligner::get_widget_size (void) {

    double
    relative_width  = 1                     * (widgets_in_line_);
    relative_width += inner_padding_size_.x * (widgets_in_line_ - 1);
    relative_width += tl_padding_size_.x + br_padding_size_.x;

    //--------------------------------------------------

    return getLayoutBox ().getSize ().x / relative_width;
}

void Square_Aligner::resize_new_widget (My_Widget& new_widget) {

    double new_width = get_widget_size ();
    plug::Vec2d new_size = plug::Vec2d (new_width, new_width);

    //--------------------------------------------------

    plug::LayoutBox& box = new_widget.getLayoutBox ();
    box.setSize (new_size);
    new_widget.setLayoutBox (box);
}


void Square_Aligner::move_new_widget (My_Widget& new_widget) {

    double
    taken_relative_x  = widgets_in_free_line_count_;
    taken_relative_x += widgets_in_free_line_count_ * inner_padding_size_.x;
    taken_relative_x += tl_padding_size_.x;
    double x = taken_relative_x * get_widget_size ();

    double
    taken_relative_y  = free_line_index;
    taken_relative_y += free_line_index * inner_padding_size_.y;
    taken_relative_y += tl_padding_size_.y;
    double y = taken_relative_y * get_widget_size ();

    //--------------------------------------------------

    plug::Vec2d new_position (x, y);
    plug::Vec2d widget_size = new_widget.getLayoutBox ().getSize ();
    new_position += widget_size / 2;
    new_position -= getLayoutBox ().getSize () / 2;

    //--------------------------------------------------

    plug::LayoutBox& box = new_widget.getLayoutBox ();
    box.setPosition (new_position);
    new_widget.setLayoutBox (box);
}

//--------------------------------------------------


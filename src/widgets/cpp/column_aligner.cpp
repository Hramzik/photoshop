
//--------------------------------------------------

#include "widgets/hpp/widgets.hpp"

//--------------------------------------------------

Column_Aligner::Column_Aligner
(My_Widget& background, plug::Vec2d relative_padding_size):
        Widget_Aligner (background),

        inner_padding_size_ (relative_padding_size),
        tl_padding_size_    (inner_padding_size_),
        br_padding_size_    (inner_padding_size_),

        next_widget_vertical_offset_ (0)
{
    next_widget_vertical_offset_ = tl_padding_size_.y * get_widget_width ();
}

Column_Aligner::Column_Aligner (My_Widget& background):
        Column_Aligner (background, plug::Vec2d (0.3, 0.3)) {}

//--------------------------------------------------

void Column_Aligner::post_adding_procedure (My_Widget& new_widget) {

    next_widget_vertical_offset_ += new_widget.getLayoutBox ().getSize ().y;
    next_widget_vertical_offset_ += inner_padding_size_.y * get_widget_width ();
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
    new_position -= getLayoutBox ().getSize () / 2;

    //--------------------------------------------------

    plug::LayoutBox& box = new_widget.getLayoutBox ();
    box.setPosition (new_position);
    new_widget.setLayoutBox (box);
}

//--------------------------------------------------


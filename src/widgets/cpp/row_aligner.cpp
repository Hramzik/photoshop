
//--------------------------------------------------

#include "widgets/hpp/widgets.hpp"

//--------------------------------------------------

Row_Aligner::Row_Aligner
(My_Widget& background, plug::Vec2d relative_padding_size):
        Widget_Aligner (background),

        inner_padding_size_ (relative_padding_size),
        tl_padding_size_    (inner_padding_size_),
        br_padding_size_    (inner_padding_size_),

        next_widget_horizontal_offset_ (0)
{
    next_widget_horizontal_offset_ = tl_padding_size_.x * get_widget_height ();
}

Row_Aligner::Row_Aligner (My_Widget& background):
        Row_Aligner (background, plug::Vec2d (0.3, 0.3)) {}

//--------------------------------------------------

void Row_Aligner::post_adding_procedure (My_Widget& new_widget) {

    next_widget_horizontal_offset_ += new_widget.getLayoutBox ().getSize ().x;
    next_widget_horizontal_offset_ += inner_padding_size_.x * get_widget_height ();
}

//--------------------------------------------------

double Row_Aligner::get_widget_height (void) {

    double
    relative_height  = 1;
    relative_height += tl_padding_size_.y;
    relative_height += br_padding_size_.y;

    //--------------------------------------------------

    return getLayoutBox ().getSize ().y / relative_height;
}

void Row_Aligner::resize_new_widget (My_Widget& new_widget) {

    double new_height = get_widget_height ();
    plug::Vec2d new_size = plug::Vec2d (new_widget.getLayoutBox ().getSize ().x, new_height);

    //--------------------------------------------------

    plug::LayoutBox& box = new_widget.getLayoutBox ();
    box.setSize (new_size);
    new_widget.setLayoutBox (box);
}

void Row_Aligner::move_new_widget (My_Widget& new_widget) {

    double x = next_widget_horizontal_offset_;
    double y = tl_padding_size_.y * get_widget_height ();

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

void Row_Aligner::set_top_left_padding (plug::Vec2d padding) {

    tl_padding_size_ = padding;

    //--------------------------------------------------
    // cringe

    next_widget_horizontal_offset_ = tl_padding_size_.x * get_widget_height ();
}

void Row_Aligner::set_bottom_right_padding (plug::Vec2d padding) {

    br_padding_size_ = padding;
}

//--------------------------------------------------


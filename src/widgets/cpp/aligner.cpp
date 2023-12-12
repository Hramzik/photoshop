

//--------------------------------------------------

#include "widgets/hpp/widgets.hpp"

//--------------------------------------------------


Widget_Aligner::Widget_Aligner (My_Widget& background):
        Widget_Container (background.getLayoutBox ()),

        background_ (background)
{
    background_.getLayoutBox ().setPosition (plug::Vec2d (0, 0));
    register_background_widget (&background_);
}

//--------------------------------------------------

void Widget_Aligner::add_widget (My_Widget& widget) {

    resize_new_widget (widget);
    move_new_widget   (widget);

    //--------------------------------------------------

    register_widget (&widget);

    //--------------------------------------------------

    post_adding_procedure ();
}

//--------------------------------------------------

void Widget_Aligner::resize_new_widget (My_Widget& new_widget) {

    (void) new_widget;
}

void Widget_Aligner::move_new_widget (My_Widget& new_widget) {

    (void) new_widget;
}

void Widget_Aligner::post_adding_procedure (void) {

    return;
}

//--------------------------------------------------


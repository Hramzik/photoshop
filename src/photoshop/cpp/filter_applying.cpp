

//--------------------------------------------------

#include "Impl/LayoutBox/LayoutBox.h"

#include "photoshop/hpp/photoshop.hpp"

//--------------------------------------------------

Filter_Applying_Widget::Filter_Applying_Widget
(plug::LayoutBox& box, Filter_Palette& palette, Canvas& canvas):
        Column_Aligner (*new Colored_Window (box, C_LIGHT_GRAY), plug::Vec2d (0.1, 0.1)),

        palette_ (palette),
        canvas_  (canvas)
{
    for (int i = 0; i < palette_.get_filters_count (); ++i) {

        plug::Filter* filter = palette_.get_filter (i);
        if (!filter) continue;

        //--------------------------------------------------

        add_filter (*filter);
    }
}

//--------------------------------------------------

void Filter_Applying_Widget::add_filter (plug::Filter& filter) {

    LayoutBox  box (666_px, 30_px);
    My_Widget& model  = *new Colored_Window (box, C_BLACK); // width will be resized
    Button&    button = *new Button (model);

    //--------------------------------------------------

    Action& action = *new Filter_Applying_Action (canvas_, filter);
    button.set_pressed_action (&action);

    //--------------------------------------------------

    Widget_Aligner::add_widget (button);
}

//--------------------------------------------------


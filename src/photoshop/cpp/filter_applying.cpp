

//--------------------------------------------------

#include "Impl/LayoutBox/LayoutBox.h"

#include "photoshop/hpp/photoshop.hpp"

//--------------------------------------------------

Filter_Applying_Widget::Filter_Applying_Widget
(plug::LayoutBox& box, Filter_Palette& palette, Canvas_Manager& canvas_manager):
        Column_Aligner (*new Colored_Window (box, C_DARK_GRAY), plug::Vec2d (0.05, 0.05)),

        palette_        (palette),
        canvas_manager_ (canvas_manager)
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
    const char* text = filter.getPluginData ()->getName ();
    My_RGB      text_color (255, 255, 255);
    My_Widget& model  = *new Texted_Window (box, text, text_color, C_DARK_GRAY); // width will be resized
    Button&    button = *new Button (model);

    //--------------------------------------------------

    Action& action = *new Filter_Applying_Action (canvas_manager_, filter);
    button.set_pressed_action (&action);

    //--------------------------------------------------

    Widget_Aligner::add_widget (button);
}

//--------------------------------------------------


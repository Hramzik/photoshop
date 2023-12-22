

//--------------------------------------------------

#include "Impl/LayoutBox/LayoutBox.h"

#include "photoshop/hpp/photoshop.hpp"

//--------------------------------------------------

Menu::Menu (plug::LayoutBox& box):
        Row_Aligner (*new Colored_Window (box, (unsigned char) 0x32), plug::Vec2d (0.7, 0))
{
    set_top_left_padding (plug::Vec2d (0.4, 0));
}

//--------------------------------------------------

void Menu::add_widget (My_Widget& widget, const char* name) {

    Widget_Hider& widget_hider = *new Widget_Hider (widget);
    widget_hider.hide ();

    //--------------------------------------------------
    // creating showing button

    LayoutBox      button_box (1_px, 1_px);
    My_RGB         text_color (196, 196, 196);
    Texted_Window& model       = *new Texted_Window (button_box, name, text_color, (unsigned char) 0x32);

    resize_new_widget (model);    // set height
    model.set_text_size_ratio (); // set width

    //--------------------------------------------------

    Button& button = *new Button (model);
    Action& action = *new Hider_Toggle_Action (widget_hider);
    button.set_pressed_action (&action);

    Widget_Aligner::add_widget (button);

    //--------------------------------------------------
    // moving widget

    plug::Vec2d new_position = button.getLayoutBox ().getPosition ();
    plug::Vec2d button_size  = button.getLayoutBox ().getSize ();
    new_position.x -= button_size.x / 2;
    new_position.y += button_size.y / 2;

    plug::Vec2d widget_size = widget.getLayoutBox ().getSize ();
    new_position += widget_size / 2;

    //--------------------------------------------------

    plug::LayoutBox& box = widget_hider.getLayoutBox ();
    box.setPosition (new_position);
    widget_hider.setLayoutBox (box);

    register_widget (&widget_hider);
}

//--------------------------------------------------


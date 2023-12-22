
//--------------------------------------------------

#include "photoshop/hpp/photoshop.hpp"

//--------------------------------------------------

Menu_Entry::Menu_Entry (plug::LayoutBox& box):
        Column_Aligner (*new Colored_Window (box, C_DARK_GRAY), plug::Vec2d (0.05, 0.05)),

        button_height_ (30) {}

//--------------------------------------------------

void Menu_Entry::add_button_to_menu_entry (const char* text, Action& action) {

    //--------------------------------------------------
    // model

    LayoutBox      button_box (1_px, Length (button_height_, Unit::Pixel));
    My_RGB         text_color (C_WHITE);
    Texted_Window& model      = *new Texted_Window (button_box, text, text_color, C_DARK_GRAY);
    model.push_text_to_the_left ();

    //--------------------------------------------------
    // button

    Button& button = *new Button (model);
    button.set_pressed_action (&action);

    //--------------------------------------------------

    Widget_Aligner::add_widget (button);
}

//--------------------------------------------------


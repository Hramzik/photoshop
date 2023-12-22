
//--------------------------------------------------

#include "photoshop/hpp/photoshop.hpp"

//--------------------------------------------------

File_Menu_Entry::File_Menu_Entry (plug::LayoutBox& box, Photoshop& owner):
        Menu_Entry (box),

        photoshop_ (owner)
{
    add_new_button   ();
    add_clear_button ();
    add_open_button  ();
    add_save_button  ();
}

//--------------------------------------------------

void File_Menu_Entry::add_new_button () {

    Action& new_action = *new New_Canvas_Action (photoshop_);
    add_button_to_menu_entry ("New", new_action);
}

void File_Menu_Entry::add_clear_button () {

    Canvas_Manager&      manager = photoshop_.access_canvas_manager ();
    plug::ColorPalette& palette = photoshop_.access_color_palette  ();

    //--------------------------------------------------

    Action& clear_action = *new Canvas_Clear_Action (manager, palette);
    add_button_to_menu_entry ("Clear", clear_action);
}

void File_Menu_Entry::add_open_button () {


}

void File_Menu_Entry::add_save_button () {


}

//--------------------------------------------------


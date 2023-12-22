#ifndef CLASS_FILE_MENU_ENTRY_HPP_INCLUDED
#define CLASS_FILE_MENU_ENTRY_HPP_INCLUDED
//--------------------------------------------------

#include "menu_entry.hpp"

//--------------------------------------------------

class Photoshop;

//--------------------------------------------------

class File_Menu_Entry: public Menu_Entry {

  public:

    File_Menu_Entry (plug::LayoutBox& box, Photoshop& owner);

  private:

    Photoshop& photoshop_;

    //--------------------------------------------------

    void add_new_button   ();
    void add_clear_button ();
    void add_open_button  ();
    void add_save_button  ();
};

//--------------------------------------------------
#endif
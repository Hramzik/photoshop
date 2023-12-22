#ifndef CLASS_MENU_ENTRY_HPP_INCLUDED
#define CLASS_MENU_ENTRY_HPP_INCLUDED
//--------------------------------------------------

#include "widgets/hpp/widgets.hpp"

//--------------------------------------------------

class Menu_Entry: public Column_Aligner {

  public:

    Menu_Entry (plug::LayoutBox& box);

  protected:

    void add_button_to_menu_entry (const char* text, Action& action);

  private:

    double button_height_;
};

//--------------------------------------------------
#endif
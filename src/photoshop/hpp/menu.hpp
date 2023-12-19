#ifndef CLASS_MENU_HPP_INCLUDED
#define CLASS_MENU_HPP_INCLUDED
//--------------------------------------------------

#include "widgets/hpp/widgets.hpp"

//--------------------------------------------------

class Menu: public Row_Aligner {

  public:

    Menu (plug::LayoutBox& box);

    //--------------------------------------------------

    void add_widget (My_Widget& widget);
};

//--------------------------------------------------
#endif
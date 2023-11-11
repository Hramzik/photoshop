#ifndef CLASS_WINDOW_MENU_HPP_INCLUDED
#define CLASS_WINDOW_MENU_HPP_INCLUDED
//--------------------------------------------------

#include "buttons/button_manager.hpp"

//--------------------------------------------------

class Window_Menu: public Button_Manager {

  public:

    Window_Menu (Point2D position, Vector2D size);

    //--------------------------------------------------

    void add_menu_button (const char* name, Button_Manager& controlled);

    //--------------------------------------------------

    Vector2D get_button_size (void) override;
};


//--------------------------------------------------
#endif
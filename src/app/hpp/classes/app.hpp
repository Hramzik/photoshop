#ifndef APP_CLASS_APP_HPP_INCLUDED
#define APP_CLASS_APP_HPP_INCLUDED
//--------------------------------------------------

#include "widgets/hpp/widgets.hpp"

//--------------------------------------------------


class App {

  public:

    App (void);

    void run (void);
    void open_clock (void);

//--------------------------------------------------

  private:

    Widget_Container widgets_;
    Transform_Stack  transform_stack_;
    Graphic_Window   window_;

    bool sdl_exit_;

    //--------------------------------------------------

    void populate (void);

    void update   (void);
    bool is_alive (void);
    bool exist_opened_widgets (void);
    void on_mouse_event (SDL_Event event);

    void render (void);
};





//--------------------------------------------------
#endif
#ifndef APP_CLASS_APP_HPP_INCLUDED
#define APP_CLASS_APP_HPP_INCLUDED
//--------------------------------------------------

#include "../../../graphics/hpp/sdl.hpp"
#include "../../../widgets/hpp/widgets.hpp"
#include "../../../clock/hpp/clock.hpp"
#include "../../../transform/hpp/transform.hpp"

//--------------------------------------------------


class App {

  public:

    App (void);

    void run (void);
    void open_clock (void);

//--------------------------------------------------

  private:

    Widget_Container widgets_;
    Graphic_Window   window_;

    bool exit_;

    //--------------------------------------------------

    void populate (void);

    void update (void);
    void render (void);
};





//--------------------------------------------------
#endif
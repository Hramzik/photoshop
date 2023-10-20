#ifndef CLOCK_CLASS_CLOCK_HPP_INCLUDED
#define CLOCK_CLASS_CLOCK_HPP_INCLUDED
//--------------------------------------------------

#include "../../../widgets/hpp/widgets.hpp"

#include "arrow.hpp"

//--------------------------------------------------


class Clock_Widget: public Widget_Container {

  public:

    Clock_Widget (double width, double height);
    //Clock_Widget (const Graphic_Window& loader);

    void load_textures (const Graphic_Window& loader);

  private:

    Textured_Window& face (void);
    Clock_Arrow& second_arrow (void);
    Clock_Arrow& minute_arrow (void);
    Clock_Arrow& hour_arrow   (void);
};


//--------------------------------------------------
#endif
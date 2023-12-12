#ifndef WIDGETS_CLASS_COLOR_SELECTION_HPP_INCLUDED
#define WIDGETS_CLASS_COLOR_SELECTION_HPP_INCLUDED
//--------------------------------------------------

#include "my_rgb/hpp/my_rgb.hpp"

#include "widgets/hpp/classes/widget_aligners/widget_aligners.hpp"

//--------------------------------------------------

class Color_Palette;

//--------------------------------------------------

class Color_Selection_Widget: public Square_Aligner {

  public:

    Color_Selection_Widget (plug::LayoutBox box, Color_Palette& palette);

    //--------------------------------------------------

    void add_color (My_RGB color);

//--------------------------------------------------

  private:

    Color_Palette& palette_;
};

//--------------------------------------------------
#endif
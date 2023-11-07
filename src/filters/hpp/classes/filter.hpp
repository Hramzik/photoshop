#ifndef FILTERS_CLASS_FILTER_HPP_INCLUDED
#define FILTERS_CLASS_FILTER_HPP_INCLUDED
//--------------------------------------------------

#include "../../../my_rgb/hpp/my_rgb.hpp"

#include "mask.hpp"

//--------------------------------------------------

class Canvas;

//--------------------------------------------------


class Filter {

  public:

    virtual ~Filter() = default;

    //--------------------------------------------------

    virtual void apply_filter (Canvas& canvas, const Filter_Mask& mask);

//--------------------------------------------------

  protected:

    virtual void apply_filter_to_pixel (My_RGB& pixel_color);
};


//--------------------------------------------------
#endif
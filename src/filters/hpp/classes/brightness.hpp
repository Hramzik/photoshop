#ifndef FILTERS_CLASS_BRIGHTNESS_FILTER_HPP_INCLUDED
#define FILTERS_CLASS_BRIGHTNESS_FILTER_HPP_INCLUDED
//--------------------------------------------------

#include "filter.hpp"

//--------------------------------------------------


class Brightness_Filter: public Filter {

  public:

    Brightness_Filter (double brightness_procent_increase);

    //--------------------------------------------------

    void apply_filter_to_pixel (My_RGB& pixel_color) override;

//--------------------------------------------------

  private:

    const double brightness_procent_increase_;
};


//--------------------------------------------------
#endif
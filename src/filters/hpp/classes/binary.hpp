#ifndef FILTERS_CLASS_BINARY_FILTER_HPP_INCLUDED
#define FILTERS_CLASS_BINARY_FILTER_HPP_INCLUDED
//--------------------------------------------------

#include "filter.hpp"

//--------------------------------------------------


class Binary_Filter: public Filter {

  public:

    void apply_filter_to_pixel (My_RGB& pixel_color) override;
};


//--------------------------------------------------
#endif
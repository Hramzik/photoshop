#ifndef FILTERS_CLASS_BLACK_AND_WHITE_FILTER_HPP_INCLUDED
#define FILTERS_CLASS_BLACK_AND_WHITE_FILTER_HPP_INCLUDED
//--------------------------------------------------

#include "filters/hpp/filters.hpp"

//--------------------------------------------------


class Black_And_White_Filter: public Filter {

  public:

    void apply_filter_to_pixel (plug::Color& pixel) const override;
};


//--------------------------------------------------
#endif
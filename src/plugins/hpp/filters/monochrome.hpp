#ifndef FILTERS_CLASS_MONOCHROME_FILTER_HPP_INCLUDED
#define FILTERS_CLASS_MONOCHROME_FILTER_HPP_INCLUDED
//--------------------------------------------------

#include "filters/hpp/filters.hpp"

//--------------------------------------------------

class Monochrome_Filter: public Filter {

  public:

    Monochrome_Filter (void);

    //--------------------------------------------------

    void apply_filter_to_pixel (plug::Color& color) const override;
};

//--------------------------------------------------

extern "C" plug::Plugin* loadPlugin (void);

//--------------------------------------------------
#endif
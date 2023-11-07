#ifndef FILTERS_CLASS_CONTRAST_FILTER_HPP_INCLUDED
#define FILTERS_CLASS_CONTRAST_FILTER_HPP_INCLUDED
//--------------------------------------------------

#include "filter.hpp"

//--------------------------------------------------


class Contrast_Filter: public Filter {

  public:

    Contrast_Filter (double contrast_procent_increase);

    //--------------------------------------------------

    void apply_filter_to_pixel
    (My_RGB& pixel_color)
    override;

//--------------------------------------------------

  private:

    const double contrast_procent_increase_;
};


//--------------------------------------------------
#endif
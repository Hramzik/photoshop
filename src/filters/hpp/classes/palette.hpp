#ifndef FILTERS_CLASS_PALETTE_HPP_INCLUDED
#define FILTERS_CLASS_PALETTE_HPP_INCLUDED
//--------------------------------------------------

#include <vector>

#include "filter.hpp"

//--------------------------------------------------


class Filter_Palette {

  public:

    Filter_Palette (void);

    //--------------------------------------------------

    // returns filter_id
    int           add_filter (plug::Filter& filter);
    plug::Filter* get_filter (int           filter_id);
    int           get_filters_count (void);

//--------------------------------------------------

  private:

    std::vector <plug::Filter*> filters_;
};


//--------------------------------------------------
#endif
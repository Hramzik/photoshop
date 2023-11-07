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
    int     add_filter (Filter& filter);
    Filter* get_filter (int     filter_id);

//--------------------------------------------------

  //private:

    std::vector <Filter*> filters_;
};


//--------------------------------------------------
#endif
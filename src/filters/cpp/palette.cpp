

//--------------------------------------------------

#include "filters/hpp/filters.hpp"

//--------------------------------------------------

Filter_Palette::Filter_Palette (void):
        filters_ () {}

//--------------------------------------------------

int Filter_Palette::add_filter (plug::Filter& filter) {

    filters_.push_back (&filter);

    //--------------------------------------------------

    return (int) filters_.size () - 1;
}


plug::Filter* Filter_Palette::get_filter (int filter_id) {

    if (filter_id >= (int) filters_.size ()) return nullptr;
    if (filter_id <  0)                      return nullptr;

    //--------------------------------------------------

    return filters_ [filter_id];
}

int Filter_Palette::get_filters_count (void) {

    return filters_.size ();
}

//--------------------------------------------------


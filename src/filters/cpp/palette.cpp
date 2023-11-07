

//--------------------------------------------------

#include "../hpp/filters.hpp"

//--------------------------------------------------

Filter_Palette::Filter_Palette (void):
        filters_ () {}

//--------------------------------------------------

int Filter_Palette::add_filter (Filter& filter) {

    filters_.push_back (&filter);

    //--------------------------------------------------

    return (int) filters_.size () - 1;
}


Filter* Filter_Palette::get_filter (int filter_id) {

    return filters_ [filter_id];
}


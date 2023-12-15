#ifndef FILTER_APPLYING_WIDGET_HPP_INCLUDED
#define FILTER_APPLYING_WIDGET_HPP_INCLUDED
//--------------------------------------------------

#include "widgets/hpp/widgets.hpp"

//--------------------------------------------------

class Filter_Applying_Widget: public Column_Aligner {

  public:

    Filter_Applying_Widget (plug::LayoutBox& box, Canvas& canvas);

    //--------------------------------------------------

    void add_filter (plug::Filter& filter);

//--------------------------------------------------

  private:

    Canvas& canvas_;
};


//--------------------------------------------------
#endif
#ifndef FILTERS_CLASS_FILTER_HPP_INCLUDED
#define FILTERS_CLASS_FILTER_HPP_INCLUDED
//--------------------------------------------------

#include "Plug/Filter.h"

//--------------------------------------------------

class Filter: public plug::Filter {

  public:

    void          applyFilter (plug::Canvas& canvas) override;
    plug::Widget* getWidget   (void)                 override;

  protected:

    virtual void apply_filter_to_pixel (plug::Color& pixel);
};


//--------------------------------------------------
#endif
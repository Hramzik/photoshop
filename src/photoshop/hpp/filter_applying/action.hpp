#ifndef FILTER_APPLYING_ACTION_HPP_INCLUDED
#define FILTER_APPLYING_ACTION_HPP_INCLUDED
//--------------------------------------------------

#include "Plug/Filter.h"

#include "widgets/hpp/classes/actions/action.hpp"

//--------------------------------------------------

class Filter_Applying_Action: public Action {

  public:

    Filter_Applying_Action (Canvas& canvas, plug::Filter& filter);

    //--------------------------------------------------

    void act (void) override;

  private:

    plug::Filter& filter_;
    Canvas&       canvas_;
};


//--------------------------------------------------
#endif
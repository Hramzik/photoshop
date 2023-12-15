

//--------------------------------------------------

#include "photoshop/hpp/photoshop.hpp"

//--------------------------------------------------

Filter_Applying_Action::Filter_Applying_Action (Canvas& canvas, plug::Filter& filter):
        filter_ (filter),
        canvas_ (canvas) {}

//--------------------------------------------------

void Filter_Applying_Action::act (void) {

    filter_.applyFilter (canvas_);
}

//--------------------------------------------------


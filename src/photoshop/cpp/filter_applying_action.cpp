

//--------------------------------------------------

#include "photoshop/hpp/photoshop.hpp"

//--------------------------------------------------

Filter_Applying_Action::Filter_Applying_Action (Canvas_Focus_Manager& canvas_manager, plug::Filter& filter):

        filter_         (filter),
        canvas_manager_ (canvas_manager) {}

//--------------------------------------------------

void Filter_Applying_Action::act (void) {

    plug::Canvas* active_canvas = canvas_manager_.get_active_canvas ();
    if (!active_canvas) return;

    //--------------------------------------------------

    filter_.applyFilter (*active_canvas);
}

//--------------------------------------------------


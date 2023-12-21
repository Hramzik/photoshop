

//--------------------------------------------------

#include "widgets/hpp/widgets.hpp"

//--------------------------------------------------

Canvas_Manager::Canvas_Manager (void):
    Canvas_Focus_Manager () {}

//--------------------------------------------------

void Canvas_Manager::get_updated (Observable& initiator) {

    Canvas_Viewer* updated_viewer = static_cast <Canvas_Viewer*> (&initiator);
    if (!updated_viewer) return;

    //--------------------------------------------------
    // viewer wants to close itself

    if (updated_viewer->is_closed ()) {

        close_canvas_viewer (*updated_viewer);
        return;
    }

    //--------------------------------------------------
    // just some focus shit

    Canvas_Focus_Manager::get_updated (initiator);
}

//--------------------------------------------------

void Canvas_Manager::save_active_canvas (void) {

    return;
}

void Canvas_Manager::clear_active_canvas (void) {

    return;;
}

void Canvas_Manager::close_canvas_viewer (Canvas_Viewer& viewer) {

    viewer.open ();
}

//--------------------------------------------------


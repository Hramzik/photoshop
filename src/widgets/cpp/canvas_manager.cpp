

//--------------------------------------------------

#include "widgets/hpp/widgets.hpp"

//--------------------------------------------------

Canvas_Manager::Canvas_Manager (void):

        active_canvas_viewer_ (nullptr) {}

//--------------------------------------------------

void Canvas_Manager::get_updated (Observable& initiator) {

    Canvas_Viewer* updated_viewer = static_cast <Canvas_Viewer*> (&initiator);
    if (!updated_viewer)                    return;

    //--------------------------------------------------
    // focus lost

    if (!updated_viewer->get_is_focused ()) {

        if (active_canvas_viewer_ != updated_viewer) return;
        active_canvas_viewer_ = nullptr;
    }

    //--------------------------------------------------
    // focus gained

    Canvas_Viewer* prev_active_viever_ = active_canvas_viewer_;
    active_canvas_viewer_ = updated_viewer;

    if (!prev_active_viever_)                         return;
    if (prev_active_viever_ == active_canvas_viewer_) return;
    prev_active_viever_->set_is_focused (false);
}

//--------------------------------------------------

void Canvas_Manager::register_canvas_viewer (Canvas_Viewer& viewer) {

    viewer.attach_observer (*this);
}

plug::Canvas* Canvas_Manager::get_active_canvas (void) {

    if (!active_canvas_viewer_) return nullptr;

    //--------------------------------------------------

    return &active_canvas_viewer_->access_canvas ();
}

//--------------------------------------------------


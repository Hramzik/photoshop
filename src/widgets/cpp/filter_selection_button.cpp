

//--------------------------------------------------

#include "../hpp/widgets.hpp"

//--------------------------------------------------

Filter_Selection_Button::Filter_Selection_Button
(Window& model, int filter_id, Filter_Palette& palette, Canvas& canvas):

    Button (model),

    filter_id_ (filter_id),
    palette_   (palette),
    canvas_    (canvas) {}

//--------------------------------------------------

void Filter_Selection_Button::do_when_pressed (void) {

    Filter* filter = palette_.get_filter (filter_id_);
    if (!filter) return;

    //--------------------------------------------------

    filter->apply_filter (canvas_, canvas_.access_filter_mask ());
}

//--------------------------------------------------


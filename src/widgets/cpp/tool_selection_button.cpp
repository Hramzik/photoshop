

//--------------------------------------------------

#include "widgets/hpp/widgets.hpp"

//--------------------------------------------------

Tool_Selection_Button::Tool_Selection_Button
(Window& model, Tool_type tool, Tool_Palette& palette):

    Button (model),

    tool_    (tool),
    palette_ (palette) {}

//--------------------------------------------------

void Tool_Selection_Button::do_when_pressed (void) {

    if (tool_ == PENCIL) palette_.select_brush_tool ();
    if (tool_ == RECT)   palette_.select_rect_tool  ();
}

//--------------------------------------------------


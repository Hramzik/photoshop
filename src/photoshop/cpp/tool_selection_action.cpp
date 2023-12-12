

//--------------------------------------------------

#include "photoshop/hpp/photoshop.hpp"

//--------------------------------------------------

Tool_Selection_Action::Tool_Selection_Action (Tool_Palette& palette, int tool_id):
        tool_id_ (tool_id),
        palette_ (palette) {}

//--------------------------------------------------

void Tool_Selection_Action::act (void) {

    palette_.set_active_tool (tool_id_);
}

//--------------------------------------------------


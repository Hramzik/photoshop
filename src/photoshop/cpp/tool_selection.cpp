

//--------------------------------------------------

#include "Impl/LayoutBox/LayoutBox.h"

#include "photoshop/hpp/photoshop.hpp"

//--------------------------------------------------

Tool_Selection_Widget::Tool_Selection_Widget
(plug::LayoutBox& box, Tool_Palette& palette):
        Square_Aligner (*new Colored_Window (box, C_LIGHT_GRAY), 4),

        palette_ (palette)
{
    add_tools_from_palette ();
}

//--------------------------------------------------

void Tool_Selection_Widget::add_tools_from_palette (void) {

    for (int tool_id = 0; tool_id < palette_.get_tools_count (); ++tool_id) {

        add_tool (tool_id);
    }
}

void Tool_Selection_Widget::add_tool (int tool_id) {

    plug::Tool* tool = palette_.get_tool (tool_id);
    if (!tool) return;

    //--------------------------------------------------

    const plug::PluginData* data = tool->getPluginData ();
    if (!data) return;

    //--------------------------------------------------

    const char* texture_path = data->getTexturePath ();
    //if (!texture_path) return;

    LayoutBox  box (100_px, 100_px); // can be any size, will be resized after
    My_Widget& model  = *new Textured_Window (box, texture_path);
    Button&    button = *new Button (model);

    //--------------------------------------------------

    Action& action = *new Tool_Selection_Action (palette_, tool_id);
    button.set_pressed_action (&action);

    //--------------------------------------------------

    Widget_Aligner::add_widget (button);
}

//--------------------------------------------------




//--------------------------------------------------

#include "tools/hpp/tools.hpp"

//--------------------------------------------------

Tool_Palette::Tool_Palette (void):
        tools_ (),

        active_tool_id_ (-1) {}

//--------------------------------------------------

/*
void ToolPalette::loadPlugins(Container<plug::Plugin*> &plugin_list)
{
    size_t cnt_plugins = plugin_list.getSize();
    for (size_t it = 0; it < cnt_plugins; it++)
    {
        plug::Tool *tool = static_cast<plug::Tool*>(plugin_list[it]->tryGetInterface(static_cast<size_t>(plug::PluginGuid::Tool)));
        if (tool)
        {
            m_tools.pushBack(tool);
        }
    }
}*/

int Tool_Palette::add_tool (plug::Tool& tool) {

    tools_.push_back (&tool);

    //--------------------------------------------------

    return (int) tools_.size ();
}

plug::Tool* Tool_Palette::get_tool (int tool_id) {

    if (tool_id <  0)                    return nullptr;
    if (tool_id >= (int) tools_.size ()) return nullptr;

    //--------------------------------------------------

    return tools_ [tool_id];
}

plug::Tool* Tool_Palette::get_active_tool (void) {

    return get_tool (active_tool_id_);
}

void Tool_Palette::set_active_tool (int tool_id) {

    active_tool_id_ = tool_id;
}

//--------------------------------------------------

int Tool_Palette::get_tools_count (void) {

    return (int) tools_.size ();
}

/*
plug::Tool* ToolPalette::getTool(const size_t tool_id)
{
    size_t cnt = m_tools.getSize();
    if (tool_id >= cnt) return nullptr;

    plug::Plugin *ret_tool = m_tools[tool_id]->tryGetInterface(static_cast<size_t>(plug::PluginGuid::Tool));
    return reinterpret_cast<plug::Tool*>(ret_tool);
}
*/

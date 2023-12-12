#ifndef CLASS_TOOL_PALETTE_HPP_INCLUDED
#define CLASS_TOOL_PALETTE_HPP_INCLUDED
//--------------------------------------------------

#include <vector>

#include "Plug/Tool.h"

//--------------------------------------------------

class Tool_Palette {
public:

    Tool_Palette (void);

    Tool_Palette (const Tool_Palette&) = delete;
    operator=    (const Tool_Palette&) = delete;

    //--------------------------------------------------

    //void loadPlugins (Container<plug::Plugin*> &plugin_list);

    int         add_tool (plug::Tool& tool);
    plug::Tool* get_tool (int tool_id);

    plug::Tool* get_active_tool (void);
    void        set_active_tool (int tool_id);

    int get_tools_count (void);

//--------------------------------------------------

  private:

    std::vector <plug::Tool*> tools_;
    int active_tool_id_;
};

//--------------------------------------------------
#endif
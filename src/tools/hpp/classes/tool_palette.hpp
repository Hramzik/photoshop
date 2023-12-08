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
    plug::Tool* get_tool (const int   tool_id);

    //size_t getSize(){ return m_tools.getSize(); }


//--------------------------------------------------

  private:

    std::vector <plug::Tool*> tools_;
};

//--------------------------------------------------
#endif
#ifndef TOOL_SELECTION_WIDGET_HPP_INCLUDED
#define TOOL_SELECTION_WIDGET_HPP_INCLUDED
//--------------------------------------------------

#include "my_rgb/hpp/my_rgb.hpp"

#include "widgets/hpp/widgets.hpp"

//--------------------------------------------------

class Tool_Palette;

//--------------------------------------------------

class Tool_Selection_Widget: public Square_Aligner {

  public:

    Tool_Selection_Widget (plug::LayoutBox& box, Tool_Palette& palette);

//--------------------------------------------------

  private:

    Tool_Palette& palette_;

    //--------------------------------------------------

    void add_tool (int tool_id);
    void add_tools_from_palette (void);
};


//--------------------------------------------------
#endif
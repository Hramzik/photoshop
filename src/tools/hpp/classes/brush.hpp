#ifndef TOOLS_CLASS_BRUSH_TOOL_HPP_INCLUDED
#define TOOLS_CLASS_BRUSH_TOOL_HPP_INCLUDED
//--------------------------------------------------

#include "tool.hpp"

//--------------------------------------------------

class Tool_Palette;

//--------------------------------------------------


class Brush_Tool: public Tool {

  public:

    Brush_Tool (void);

    //--------------------------------------------------

    void onMainButton (const plug::ControlState& state, const plug::Vec2d& position) override;
    void onMove                                        (const plug::Vec2d& position) override;

//--------------------------------------------------

  private:

    double brush_radius_;
    bool   is_brush_down;
};


//--------------------------------------------------
#endif
#ifndef TOOLS_CLASS_BRUSH_TOOL_HPP_INCLUDED
#define TOOLS_CLASS_BRUSH_TOOL_HPP_INCLUDED
//--------------------------------------------------

#include "tools/hpp/tools.hpp"

//--------------------------------------------------

class Pencil_Tool: public Tool {

  public:

    Pencil_Tool (void);

    //--------------------------------------------------

    void onMainButton (const plug::ControlState& state, const plug::Vec2d& position) override;
    void onMove                                        (const plug::Vec2d& position) override;

//--------------------------------------------------

  private:

    plug::Vec2d prev_mouse_position_;
    bool        is_brush_down;
};

//--------------------------------------------------

extern "C" plug::Plugin* loadPlugin (void);

//--------------------------------------------------
#endif
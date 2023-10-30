#ifndef TOOLS_CLASS_BRUSH_HPP_INCLUDED
#define TOOLS_CLASS_BRUSH_HPP_INCLUDED
//--------------------------------------------------

#include "tool.hpp"

//--------------------------------------------------

class Tool_Palette;

//--------------------------------------------------


class Brush_Tool: public Tool {

  public:

    Brush_Tool (const Tool_Palette& palette);

    //--------------------------------------------------

    void on_main_button
            (Button_state state, Point2D mouse_position, Canvas& canvas) override;

    void on_move (Point2D mouse_position, Canvas& canvas) override;

//--------------------------------------------------

  private:

    double brush_radius_;
    bool   drawing_;
    const Tool_Palette& my_palette_;
};


//--------------------------------------------------
#endif
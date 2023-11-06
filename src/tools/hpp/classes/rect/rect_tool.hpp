#ifndef TOOLS_CLASS_RECT_TOOL_HPP_INCLUDED
#define TOOLS_CLASS_RECT_TOOL_HPP_INCLUDED
//--------------------------------------------------

#include "../tool.hpp"

#include "rect_widget.hpp"

//--------------------------------------------------

class Tool_Palette;

//--------------------------------------------------


class Rect_Tool: public Tool {

  public:

    Rect_Tool (const Tool_Palette& palette);

    //--------------------------------------------------

    Widget* get_widget (void) override;

    void on_main_button
    (Button_state state, Point2D mouse_position, Canvas& canvas)
    override;

    /*void on_modifier1
    (Button_state state, Point2D mouse_position, Canvas& canvas)
    override;

    void on_modifier2
    (Button_state state, Point2D mouse_position, Canvas& canvas)
    override;*/

    void on_move   (Point2D mouse_position, Canvas& canvas) override;
    void on_cancel (Point2D mouse_position, Canvas& canvas) override;

//--------------------------------------------------

  private:

    Rect_Tool_Widget preview_;

    //--------------------------------------------------

    const Tool_Palette& my_palette_;
};


//--------------------------------------------------
#endif
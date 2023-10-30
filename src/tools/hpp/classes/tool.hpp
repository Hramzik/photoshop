#ifndef TOOLS_CLASS_TOOL_HPP_INCLUDED
#define TOOLS_CLASS_TOOL_HPP_INCLUDED
//--------------------------------------------------

#include "../../../graphics/hpp/graphics.hpp"
#include "../../../widgets/hpp/classes/widget.hpp"

#include "../enums.hpp"

//--------------------------------------------------

class Canvas;

//--------------------------------------------------


class Tool {

  public:

    virtual ~Tool (void) = default;

    //--------------------------------------------------

    virtual Widget* get_widget (void);

    virtual void on_main_button
            (Button_state state, Point2D mouse_position, Canvas& canvas);

    virtual void on_secondary_button
            (Button_state state, Point2D mouse_position, Canvas& canvas);

    virtual void on_modifier1
            (Button_state state, Point2D mouse_position, Canvas& canvas);

    virtual void on_modifier2
            (Button_state state, Point2D mouse_position, Canvas& canvas);

    virtual void on_modifier3
            (Button_state state, Point2D mouse_position, Canvas& canvas);

    virtual void on_move    (Point2D mouse_position, Canvas& canvas);
    virtual void on_confirm (Point2D mouse_position, Canvas& canvas);
    virtual void on_cancel  (Point2D mouse_position, Canvas& canvas);
};


//--------------------------------------------------
#endif
#ifndef CLASS_CANVAS_VIEWER_HPP_INCLUDED
#define CLASS_CANVAS_VIEWER_HPP_INCLUDED
//--------------------------------------------------

#include "tools/hpp/tools.hpp"

#include "widgets/hpp/classes/my_widget.hpp"

//--------------------------------------------------

class Canvas;

class Filter_Palette;

//--------------------------------------------------

class Canvas_Viewer: public My_Widget {

  public:

    Canvas_Viewer (const plug::LayoutBox& box, Canvas& canvas);

    Canvas_Viewer (const Canvas_Viewer&) = delete;
    operator=     (const Canvas_Viewer&) = delete;

    //--------------------------------------------------

    void set_is_focused (bool is_focused);
    void choose_tool    (int tool_id);
    void apply_filter   (int filter_id);

    void set_tool_palette (Tool_Palette& palette);

    //--------------------------------------------------

    void render (plug::RenderTarget& target, plug::TransformStack& stack) override;
    //void onParentUpdate (const plug::LayoutBox& parent_box) override;

    //void        setCanvasPos  (const plug::Vec2d& pos);
    //plug::Vec2d getCanvasPos  (void);
    //plug::Vec2d getCanvasSize (void);

protected:

    void onMouseMove     (const plug::MouseMoveEvent&     event, plug::EHC& context) override;
    void onMousePressed  (const plug::MousePressedEvent&  event, plug::EHC& context) override;
    void onMouseReleased (const plug::MouseReleasedEvent& event, plug::EHC& context) override;

    void onKeyboardPressed (const plug::KeyboardPressedEvent&  event, plug::EHC& context) override;

private:

    Canvas& canvas_;
    bool is_canvas_focused_;

    Tool_Palette* tool_palette_;

    //--------------------------------------------------

    plug::Tool* get_active_tool (void);
    plug::Vec2d get_canvas_position (plug::Vec2d viewer_position);
};


//--------------------------------------------------
#endif
#ifndef CLASS_CANVAS_VIEWER_HPP_INCLUDED
#define CLASS_CANVAS_VIEWER_HPP_INCLUDED
//--------------------------------------------------

#include "observer/hpp/observer.hpp"

#include "tools/hpp/tools.hpp"

#include "widgets/hpp/classes/my_widget.hpp"

//--------------------------------------------------

class Canvas;

//--------------------------------------------------

// is observed by Canvas_Focus_Manager
class Canvas_Viewer: public My_Widget, public Observable {

  public:

    Canvas_Viewer (const plug::LayoutBox& box, Canvas& canvas);

    Canvas_Viewer (const Canvas_Viewer&) = delete;
    operator=     (const Canvas_Viewer&) = delete;

    //--------------------------------------------------

    // tool palette must be set before focus
    void          set_is_focused   (bool is_focused);
    bool          get_is_focused   (void);
    void          set_tool_palette (Tool_Palette& palette);
    Tool_Palette* get_tool_palette (void);

    Canvas& access_canvas (void);

    //--------------------------------------------------

    void render (plug::RenderTarget& target, plug::TransformStack& stack) override;
    void close (void) override;

protected:

    void onMouseMove     (const plug::MouseMoveEvent&     event, plug::EHC& context) override;
    void onMousePressed  (const plug::MousePressedEvent&  event, plug::EHC& context) override;
    void onMouseReleased (const plug::MouseReleasedEvent& event, plug::EHC& context) override;

    void onKeyboardPressed  (const plug::KeyboardPressedEvent&  event, plug::EHC& context) override;
    void onKeyboardReleased (const plug::KeyboardReleasedEvent& event, plug::EHC& context) override;

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
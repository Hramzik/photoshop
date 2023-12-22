

//--------------------------------------------------

#include "tools/hpp/tools.hpp"

#include "widgets/hpp/widgets.hpp"

//--------------------------------------------------

Canvas_Viewer::Canvas_Viewer (const plug::LayoutBox& box, Canvas& canvas):
        My_Widget (box),

        canvas_ (canvas),
        is_canvas_focused_ (false),

        tool_palette_ (nullptr) {}

//--------------------------------------------------

void Canvas_Viewer::set_is_focused (bool is_focused) {

    is_canvas_focused_ = is_focused;
    notify_observers ();

    //--------------------------------------------------

    if (!is_focused) return;

    //--------------------------------------------------

    for (int i = 0; i < tool_palette_->get_tools_count (); ++i) {

        plug::Tool* tool = tool_palette_->get_tool (i);
        if (!tool) continue;

        //--------------------------------------------------

        tool->setActiveCanvas (canvas_);
    }
}

bool Canvas_Viewer::get_is_focused (void) {

    return is_canvas_focused_;
}

void Canvas_Viewer::set_tool_palette (Tool_Palette& palette) {

    tool_palette_ = &palette;
}

Tool_Palette* Canvas_Viewer::get_tool_palette (void) {

    return tool_palette_;
}

Canvas& Canvas_Viewer::access_canvas (void) {

    return canvas_;
}

//--------------------------------------------------

void Canvas_Viewer::render (plug::RenderTarget& target, plug::TransformStack& stack) {

    plug::VertexArray render_shape = get_render_shape (stack);
    target.draw (render_shape, canvas_.getTexture ());

    //--------------------------------------------------

    if (!is_canvas_focused_ || !get_active_tool ()) return;

    //--------------------------------------------------
    // tool preview

    plug::Widget* preview = get_active_tool ()->getWidget ();
    if (!preview) return;

    plug::Vec2d canvas_scaling;
    canvas_scaling.x = 1 / canvas_.getSize ().x * getLayoutBox ().getSize ().x;
    canvas_scaling.y = 1 / canvas_.getSize ().y * getLayoutBox ().getSize ().y;

    stack.enter (plug::Transform (getLayoutBox ().getPosition ()));
    stack.enter (plug::Transform (-1 * getLayoutBox ().getSize () / 2, canvas_scaling));
    preview->draw (stack, target);
    stack.leave ();
    stack.leave ();
}

void Canvas_Viewer::close (void) {

    My_Widget::close ();

    //--------------------------------------------------

    notify_observers ();
}

//--------------------------------------------------

void Canvas_Viewer::onMouseMove (const plug::MouseMoveEvent& event, plug::EHC& context) {

    if (!is_canvas_focused_) return;
    if (!get_active_tool ()) return;

    //if (!covers (context.stack, event.pos)) return;

    //--------------------------------------------------

    context.stack.enter (plug::Transform (getLayoutBox ().getPosition (), plug::Vec2d (1, 1)));
    plug::Vec2d viewer_pos = context.stack.restore (event.pos);
    context.stack.leave ();

    //--------------------------------------------------

    plug::Vec2d canvas_pos = get_canvas_position (viewer_pos);
    get_active_tool ()->onMove (canvas_pos);
}

void Canvas_Viewer::onMousePressed (const plug::MousePressedEvent& event, plug::EHC& context) {

    if (context.stopped) return;
    context.stopped = covers (context.stack, event.pos);
    if (!context.stopped) return;

    //--------------------------------------------------

    set_is_focused (true);
    if (!get_active_tool ()) return;

    //--------------------------------------------------

    context.stack.enter (plug::Transform (getLayoutBox ().getPosition (), plug::Vec2d (1, 1)));
    plug::Vec2d viewer_pos = context.stack.restore (event.pos);
    context.stack.leave ();

    //--------------------------------------------------

    plug::Vec2d canvas_pos = get_canvas_position (viewer_pos);
    if (event.button_id == plug::MouseButton::Left) get_active_tool ()->onMainButton ({plug::State::Pressed}, canvas_pos);
}

void Canvas_Viewer::onMouseReleased (const plug::MouseReleasedEvent &event, plug::EHC& context) {

    if (context.stopped)     return;
    if (!is_canvas_focused_) return;
    if (!get_active_tool ()) return;

    //--------------------------------------------------

    context.stack.enter (plug::Transform (getLayoutBox ().getPosition (), plug::Vec2d (1, 1)));
    plug::Vec2d viewer_pos = context.stack.restore (event.pos);
    context.stack.leave ();

    //--------------------------------------------------

    plug::Vec2d canvas_pos = get_canvas_position (viewer_pos);
    if (event.button_id == plug::MouseButton::Left) get_active_tool ()->onMainButton ({plug::State::Released}, canvas_pos);
}

void Canvas_Viewer::onKeyboardPressed (const plug::KeyboardPressedEvent& event, plug::EHC& context) {

    (void) context;

    //--------------------------------------------------

    if (!get_active_tool ()) return;

    //--------------------------------------------------

    // везде сделать так!
    if (event.key_id == plug::KeyCode::Escape) get_active_tool ()->onCancel();

    if (event.shift) get_active_tool ()->onModifier1 ({plug::State::Pressed});
    if (event.ctrl)  get_active_tool ()->onModifier2 ({plug::State::Pressed});
    if (event.alt)   get_active_tool ()->onModifier3 ({plug::State::Pressed});
}

void Canvas_Viewer::onKeyboardReleased (const plug::KeyboardReleasedEvent& event, plug::EHC& context) {

    (void) context;

    //--------------------------------------------------

    if (!get_active_tool ()) return;

    //--------------------------------------------------

    if (!event.shift) get_active_tool ()->onModifier1 ({plug::State::Released});
    if (!event.ctrl)  get_active_tool ()->onModifier2 ({plug::State::Released});
    if (!event.alt)   get_active_tool ()->onModifier3 ({plug::State::Released});
}

//--------------------------------------------------

plug::Vec2d Canvas_Viewer::get_canvas_position (plug::Vec2d viewer_position) {

    plug::Vec2d to_right_down_corner = getLayoutBox ().getSize () / 2;
    viewer_position += to_right_down_corner;

    //--------------------------------------------------

    plug::Vec2d scaling = canvas_.getSize () / getLayoutBox ().getSize ();

    //--------------------------------------------------

    return viewer_position * scaling;
}

plug::Tool* Canvas_Viewer::get_active_tool (void) {

    plug::Tool* active_tool = tool_palette_->get_active_tool ();
    if (!active_tool) return nullptr;

    //--------------------------------------------------

    return active_tool;
}

//--------------------------------------------------


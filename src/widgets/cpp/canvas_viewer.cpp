

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

    //--------------------------------------------------

    if (!is_focused || !get_active_tool ()) return;

    //--------------------------------------------------

    get_active_tool ()->setActiveCanvas (canvas_);
}

/*
void Canvas_Viewer::apply_filter (int filter_id) {

    plug::Filter* filter = filter_palette_.get_filter (filter_id);
    if (!filter) return;

    //--------------------------------------------------

    filter->applyFilter (canvas_);
}*/

void Canvas_Viewer::set_tool_palette (Tool_Palette& palette) {

    tool_palette_ = &palette;
}

//--------------------------------------------------

void Canvas_Viewer::render (plug::RenderTarget& target, plug::TransformStack& stack) {

    plug::VertexArray render_shape = get_render_shape (stack);
    target.draw (render_shape, canvas_.getTexture ());

    //--------------------------------------------------


    if (!is_canvas_focused_ || !get_active_tool ()) return;

    //--------------------------------------------------
    // tool preview

    plug::Widget* preview = get_active_tool ()->getWidget();
    if (!preview) return;

    stack.enter (plug::Transform (getLayoutBox ().getPosition (), plug::Vec2d (1, 1)));
    preview->draw (stack, target);
    stack.leave ();
}

void Canvas_Viewer::onMouseMove (const plug::MouseMoveEvent& event, plug::EHC& context) {

    if (!is_canvas_focused_) return;
    if (!get_active_tool ()) return;

    if (!covers (context.stack, event.pos)) return;

    //--------------------------------------------------

    context.stack.enter (plug::Transform (getLayoutBox ().getPosition (), plug::Vec2d (1, 1)));
    plug::Vec2d viewer_pos = context.stack.restore (event.pos);
    context.stack.leave ();

    //--------------------------------------------------

    plug::Vec2d canvas_pos = get_canvas_position (viewer_pos);
    get_active_tool ()->onMove (canvas_pos);
}

void Canvas_Viewer::onMousePressed (const plug::MousePressedEvent& event, plug::EHC& context) {

    if (!is_canvas_focused_) return;
    if (!get_active_tool ()) return;

    context.stopped = covers (context.stack, event.pos);
    if (!context.stopped) return;

    //--------------------------------------------------

    context.stack.enter (plug::Transform (getLayoutBox ().getPosition (), plug::Vec2d (1, 1)));
    plug::Vec2d viewer_pos = context.stack.restore (event.pos);
    context.stack.leave ();

    //--------------------------------------------------

    plug::Vec2d canvas_pos = get_canvas_position (viewer_pos);
    if (event.button_id == plug::MouseButton::Left) get_active_tool ()->onMainButton ({plug::State::Pressed}, canvas_pos);
}

void Canvas_Viewer::onMouseReleased (const plug::MouseReleasedEvent &event, plug::EHC& context) {

    (void) context;

    //--------------------------------------------------

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

    if (event.key_id == plug::KeyCode::Escape) get_active_tool ()->onCancel();
}

//--------------------------------------------------

plug::Vec2d Canvas_Viewer::get_canvas_position (plug::Vec2d viewer_position) {

    plug::Vec2d to_right_down_corner (getLayoutBox ().getSize ().x / 2, getLayoutBox ().getSize ().x / 2);
    viewer_position += to_right_down_corner;

    //--------------------------------------------------

    plug::Vec2d scaling = canvas_.getSize () / getLayoutBox ().getSize ();

    //--------------------------------------------------

    return viewer_position * scaling;
}

plug::Tool* Canvas_Viewer::get_active_tool (void) {

    return tool_palette_->get_active_tool ();
}

//--------------------------------------------------




//--------------------------------------------------

#include "tools/hpp/tools.hpp"

#include "widgets/hpp/widgets.hpp"

//--------------------------------------------------

Canvas_Viewer::Canvas_Viewer (const plug::LayoutBox& box, Canvas& canvas):
        My_Widget (box),

        canvas_ (canvas),
        is_canvas_focused_ (false),

        color_palette_  (nullptr),
        tool_palette_   (nullptr),
        filter_palette_ (nullptr),

        active_tool_ (nullptr) {}

//--------------------------------------------------

void Canvas_Viewer::set_is_focused (bool is_focused) {

    is_canvas_focused_ = is_focused;

    //--------------------------------------------------

    if (!active_tool_) return;

    //--------------------------------------------------

    active_tool_->setActiveCanvas (canvas_);

    if (!color_palette_) return;
    active_tool_->setColorPalette (*color_palette_);
}

void Canvas_Viewer::choose_tool (int tool_id) {

    if (!tool_palette_) return;

    //--------------------------------------------------

    active_tool_ = tool_palette_->get_tool (tool_id);
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

    if (!is_canvas_focused_ || !active_tool_) return;

    //--------------------------------------------------
    // tool preview

    plug::Widget* preview = active_tool_->getWidget();
    if (!preview) return;

    stack.enter (plug::Transform (getLayoutBox ().getPosition (), plug::Vec2d (1, 1)));
    preview->draw (stack, target);
    stack.leave ();
}

void Canvas_Viewer::onMouseMove (const plug::MouseMoveEvent& event, plug::EHC& context) {

    if (!is_canvas_focused_) return;
    if (!active_tool_)       return;

    if (!covers (context.stack, event.pos)) return;

    //--------------------------------------------------

    context.stack.enter (plug::Transform (getLayoutBox ().getPosition (), plug::Vec2d (1, 1)));
    plug::Vec2d viewer_pos = context.stack.restore (event.pos);
    context.stack.leave ();

    //--------------------------------------------------

    plug::Vec2d canvas_pos = get_canvas_position (viewer_pos);
    active_tool_->onMove (canvas_pos);
}

void Canvas_Viewer::onMousePressed (const plug::MousePressedEvent& event, plug::EHC& context) {

    if (!is_canvas_focused_) return;
    if (!active_tool_)       {std::cout << "shit" << "\n";return;}

    context.stopped = covers (context.stack, event.pos);
    if (!context.stopped) return;

    //--------------------------------------------------

    context.stack.enter (plug::Transform (getLayoutBox ().getPosition (), plug::Vec2d (1, 1)));
    plug::Vec2d viewer_pos = context.stack.restore (event.pos);
    context.stack.leave ();

    //--------------------------------------------------

    plug::Vec2d canvas_pos = get_canvas_position (viewer_pos);
    std::cout << canvas_pos.x << " " << canvas_pos.y << "\n";

    if (event.button_id == plug::MouseButton::Left) active_tool_->onMainButton ({plug::State::Pressed}, canvas_pos);
}

void Canvas_Viewer::onMouseReleased (const plug::MouseReleasedEvent &event, plug::EHC& context) {

    (void) context;

    //--------------------------------------------------

    if (!is_canvas_focused_) return;
    if (!active_tool_)       return;

    //--------------------------------------------------

    context.stack.enter (plug::Transform (getLayoutBox ().getPosition (), plug::Vec2d (1, 1)));
    plug::Vec2d viewer_pos = context.stack.restore (event.pos);
    context.stack.leave ();

    //--------------------------------------------------

    plug::Vec2d canvas_pos = get_canvas_position (viewer_pos);
    if (event.button_id == plug::MouseButton::Left) active_tool_->onMainButton ({plug::State::Released}, canvas_pos);
}

void Canvas_Viewer::onKeyboardPressed (const plug::KeyboardPressedEvent& event, plug::EHC& context) {

    (void) context;

    //--------------------------------------------------

    if (!active_tool_) return;

    //--------------------------------------------------

    if (event.key_id == plug::KeyCode::Escape) active_tool_->onCancel();
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

//--------------------------------------------------


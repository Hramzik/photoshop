

//--------------------------------------------------

#include <iostream>

#include "plugins/hpp/plugins.hpp"

//--------------------------------------------------

Pencil_Tool::Pencil_Tool (void):
        Tool ("pencil", "media/pencil.png"),

        prev_mouse_position_ (),
        is_brush_down (false) {}

//--------------------------------------------------

void Pencil_Tool::onMainButton (const plug::ControlState& state, const plug::Vec2d& position) {

    //--------------------------------------------------
    // finishing drawing

    if (state.state == plug::State::Released) {

        is_brush_down = false;
        return;
    }

    //--------------------------------------------------
    // starting drawing

    is_brush_down        = true;
    prev_mouse_position_ = position;
}

void Pencil_Tool::onMove (const plug::Vec2d& position) {

    if (!is_brush_down) return;

    //--------------------------------------------------

    plug::VertexArray line (plug::PrimitiveType::Lines, 2);
    plug::Color       color = color_palette_->getFGColor ();
    line [0] = {prev_mouse_position_, plug::Vec2d (), color};
    line [1] = {position,             plug::Vec2d (), color};

    canvas_->draw (line);

    //--------------------------------------------------

    prev_mouse_position_ = position;
}

//--------------------------------------------------

plug::Plugin* loadPlugin (void) {

    return new Pencil_Tool ();
}

//--------------------------------------------------




//--------------------------------------------------

#include <iostream>

#include "plugins/hpp/plugins.hpp"

//--------------------------------------------------

Pencil_Tool::Pencil_Tool (void):
        Tool ("pencil", "media/pencil.png"),

        brush_radius_ (1),
        is_brush_down (false) {}

//--------------------------------------------------

void Pencil_Tool::onMainButton (const plug::ControlState& state, const plug::Vec2d& position) {

    (void) position;

    //--------------------------------------------------

    if (state.state == plug::State::Pressed) is_brush_down = true;
    else                                     is_brush_down = false;
}

void Pencil_Tool::onMove (const plug::Vec2d& position) {

    if (!is_brush_down) return;

    //--------------------------------------------------

    plug::VertexArray point (plug::PrimitiveType::Points, 1);
    plug::Color       color = color_palette_->getFGColor ();
    point [0] = {position, plug::Vec2d (0, 0), color};
    canvas_->draw (point);
}

//--------------------------------------------------

plug::Plugin* loadPlugin (void) {

    return new Pencil_Tool ();
}

//--------------------------------------------------

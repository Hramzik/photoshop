

//--------------------------------------------------

#include <iostream>

#include "../hpp/tools.hpp"

//--------------------------------------------------

Brush_Tool::Brush_Tool (void):
        Tool (nullptr, nullptr),

        brush_radius_ (1),
        is_brush_down (false) {}

//--------------------------------------------------

void Brush_Tool::onMainButton (const plug::ControlState& state, const plug::Vec2d& position) {

    (void) position;

    //--------------------------------------------------

    if (state.state == plug::State::Pressed) is_brush_down = true;
    else                                     is_brush_down = false;
}


void Brush_Tool::onMove (const plug::Vec2d& position) {
std::cout << "brush" << "\n";
    if (!is_brush_down) return;
std::cout << "is down" << "\n";
    //--------------------------------------------------

    plug::VertexArray point (plug::PrimitiveType::Points, 1);
    plug::Color       color = color_palette_->getFGColor ();

    point [0] = {position,                                     plug::Vec2d (0, 0), color};
    //point [1] = {plug::Vec2d (position.x + 2, position.y),     plug::Vec2d (0, 0), color};
    //point [2] = {plug::Vec2d (position.x + 2, position.y + 2), plug::Vec2d (0, 0), color};
    //point [3] = {plug::Vec2d (position.x,     position.y + 2), plug::Vec2d (0, 0), color};
    canvas_->draw (point);
//std::cout << (int) canvas_->getPixel (position.x, position.y).r << "\n";
}


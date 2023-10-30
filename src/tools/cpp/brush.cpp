

//--------------------------------------------------

#include "../../widgets/hpp/classes/canvas.hpp"

#include "../hpp/tools.hpp"

//--------------------------------------------------

Brush_Tool::Brush_Tool (const Tool_Palette& palette):
        brush_radius_ (1),
        drawing_      (false),
        my_palette_   (palette) {}

//--------------------------------------------------

void Brush_Tool::on_main_button (Button_state state, Point2D mouse_position, Canvas& canvas) {

    (void) mouse_position; (void) canvas;

    //--------------------------------------------------

    if (state == BS_PRESSED) drawing_ = true;
    else                     drawing_ = false;
}


void Brush_Tool::on_move (Point2D mouse_position, Canvas& canvas) {

    if (!drawing_) return;

    //--------------------------------------------------

    My_Texture& render_texture = canvas.access_texture ();
    render_texture.draw_point (mouse_position);
}


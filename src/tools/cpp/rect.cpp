

//--------------------------------------------------

#include "../../widgets/hpp/classes/photoshop/canvas.hpp"

#include "../hpp/tools.hpp"

//--------------------------------------------------

Rect_Tool::Rect_Tool (const Tool_Palette& palette):
        preview_ (),

        my_palette_ (palette) {}

//--------------------------------------------------

Widget* Rect_Tool::get_widget (void) {

    return &preview_;
}


void Rect_Tool::on_main_button
(Button_state state, Point2D mouse_position, Canvas& canvas) {

    //--------------------------------------------------
    // кнопка нажата, начинаем тянуться

    if (state == BS_PRESSED) {

        preview_.set_origin (mouse_position);

        // это нужно, так как события on_move может не быть,
        // и тогда мы должны что-то нарисовать, рисуем точку
        preview_.set_end    (mouse_position);
        preview_.set_visibility (true);
        preview_.set_filling    (DEFAULT_RECT_FILLING);
        return;
    }

    //--------------------------------------------------
    // кнопка отжата, но мы не тянемся

    if (!preview_.is_visible ()) return;

    //--------------------------------------------------
    // кнопка отжата, применяемся

    preview_.set_visibility (false);


    My_Texture& render_texture = canvas.access_texture ();
    Point2D corner1 = preview_.get_origin ();
    Point2D corner2 = preview_.get_end ();

    render_texture.set_drawcolor (my_palette_.get_active_color ());
    render_texture.draw_rect (corner1, corner2, preview_.is_filled ());
}


void Rect_Tool::on_modifier1
(Button_state state, Canvas& canvas) {

    (void) canvas;

    //--------------------------------------------------

    if (state == BS_PRESSED) return;

    //--------------------------------------------------

    preview_.reverse_filling ();
}


void Rect_Tool::on_move (Point2D mouse_position, Canvas& canvas) {

    (void) canvas;

    //--------------------------------------------------

    if (!preview_.is_visible ()) return;

    //--------------------------------------------------

    preview_.set_end (mouse_position);
}


void Rect_Tool::on_cancel (void) {

    preview_.set_visibility (false);
}

//--------------------------------------------------


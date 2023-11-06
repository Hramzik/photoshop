

//--------------------------------------------------

#include "../../widgets/hpp/classes/canvas.hpp"

#include "../hpp/tools.hpp"

//--------------------------------------------------

void Rect_Tool::on_main_button
(Button_state state, Point2D mouse_position, Canvas& canvas) {

    //--------------------------------------------------
    // кнопка нажата, начинаем тянуться

    if (state == BS_PRESSED) {

        dragging_origin_  = mouse_position;
        is_being_dragged_ = true;
        return;0
    }

    //--------------------------------------------------
    // кнопка отжата, но мы не тянемся

    if (!is_being_dragged_) return;

    //--------------------------------------------------
    // кнопка отжата, применяемся

    is_being_dragged_ = false;

    My_Texture& render_texture = canvas.access_texture ();
    render_texture.draw_rect (mouse_position, dragging_origin_);
}


void Rect_Tool::on_modifier1
(Button_state state, Point2D mouse_position, Canvas& canvas) {


}


void Rect_Tool::on_modifier2
(Button_state state, Point2D mouse_position, Canvas& canvas) {


}


void Rect_Tool::on_move (Point2D mouse_position, Canvas& canvas) {

    if (!is_being_dragged_) return;

    //--------------------------------------------------


}


void Rect_Tool::on_cancel (Point2D mouse_position, Canvas& canvas) {

    is_being_dragged_ = false;
}

//--------------------------------------------------
// RECT TOOL WIDGET CODE

Rect_Tool_Widget::Rect_Tool_Widget (void):
        Window  (0, )
        origin_ (0),
        end_    (0),

        is_visible_ (false),
        is_filled_  (false) {}

//--------------------------------------------------

void Rect_Tool_Widget::set_origin (Point2D origin) {

    my_transform_.set_offset (origin);
}


void Rect_Tool_Widget::set_end (Point2D end) {

    end_ = end;
}


void Rect_Tool_Widget::set_visibility (bool is_visible) {

    is_visible_ = is_visible;
}


void Rect_Tool_Widget::set_filling (bool is_filled) {

    is_filled_ = is_filled;
}


void Rect_Tool_Widget::render_with_final_transform
(Graphic_Window& window, const Transform& result_transform)
{
    if (!is_visible_) return;

    //--------------------------------------------------

    SDL_Rect render_rect = get_render_rect (result_transform);

    //--------------------------------------------------

    window.draw_rect (render_rect);
}


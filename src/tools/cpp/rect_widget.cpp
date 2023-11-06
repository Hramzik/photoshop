

//--------------------------------------------------

#include "../hpp/tools.hpp"

//--------------------------------------------------


Rect_Tool_Widget::Rect_Tool_Widget (void):
        Window  (0, 0),

        is_visible_ (false),
        is_filled_  (false) {}

//--------------------------------------------------

Point2D Rect_Tool_Widget::get_origin (void) {

    return my_transform_.get_position ();
}


Point2D Rect_Tool_Widget::get_end (void) {

    Point2D end = get_origin ();
    end.move (size_);


    return end;
}


bool Rect_Tool_Widget::is_visible (void) {

    return is_visible_;
}

//--------------------------------------------------

void Rect_Tool_Widget::set_origin (Point2D origin) {

    my_transform_.set_offset (origin);
}


void Rect_Tool_Widget::set_end (Point2D end) {

    size_ = end - get_origin ();
}


void Rect_Tool_Widget::set_visibility (bool is_visible) {

    is_visible_ = is_visible;
}


void Rect_Tool_Widget::set_filling (bool is_filled) {

    is_filled_ = is_filled;
}

//--------------------------------------------------

void Rect_Tool_Widget::render_with_final_transform
(Graphic_Window& window, const Transform& result_transform)
{
    if (!is_visible_) return;

    //--------------------------------------------------

    SDL_Rect render_rect = get_render_rect (result_transform);

    //--------------------------------------------------

    window.draw_rect (render_rect);
}


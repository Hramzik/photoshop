

//--------------------------------------------------

#include "../hpp/widgets.hpp"

//--------------------------------------------------

Canvas::Canvas (Point2D position, Vector2D size /*Tool_Palette& palette*/):
        Window ({200}, size),

        texture_ (size),
        drawing_ (false),
        last_mouse_position_ (0) {


    texture_.set_drawcolor (C_BLACK);
}

//--------------------------------------------------

void Canvas::render_with_final_transform (Graphic_Window& window, const Transform& result_transform) {

    SDL_Rect render_rect = get_render_rect (result_transform);

    //--------------------------------------------------

    window.render_texture (texture_, render_rect);
};


Processing_result Canvas::on_mouse_pressed (Point2D mouse_position, Transform_Stack& stack) {

    conver_to_local (mouse_position, stack);
    if (!is_mouse_in_me (mouse_position)) return PR_LEFT;


    drawing_ = true;


    return PR_PROCESSED;
};


Processing_result Canvas::on_mouse_released (Point2D mouse_position, Transform_Stack& stack) {

    if (!drawing_) return PR_LEFT;


    drawing_ = false;


    return PR_PROCESSED;
};


Processing_result Canvas::on_mouse_moved (Point2D mouse_position, Transform_Stack& stack) {

    if (!drawing_) return PR_LEFT;


    conver_to_local (mouse_position, stack);
    texture_.draw_point (mouse_position);


    return PR_PROCESSED;
};


Processing_result Canvas::on_keyboard_pressed (SDL_Keycode key) {

    return PR_LEFT;
};


Processing_result Canvas::on_keyboard_released (SDL_Keycode key) {

    return PR_LEFT;
};


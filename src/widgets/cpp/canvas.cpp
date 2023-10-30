

//--------------------------------------------------

#include "../hpp/widgets.hpp"

//--------------------------------------------------

Canvas::Canvas (Point2D position, Vector2D size, Tool_Palette& palette):
        Window (position, size),

        texture_ (size),
        palette_ (palette),

        drawing_ (false),
        last_mouse_position_ (0) {


    texture_.set_drawcolor (C_BLACK);
}

//--------------------------------------------------

My_Texture& Canvas::access_texture (void) {

    return texture_;
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

    //--------------------------------------------------

    Tool* active_tool = palette_.get_active_tool ();
    if (!active_tool) return PR_PROCESSED;


    active_tool->on_main_button (BS_PRESSED, mouse_position, *this);


    return PR_PROCESSED;
};


Processing_result Canvas::on_mouse_released (Point2D mouse_position, Transform_Stack& stack) {

    conver_to_local (mouse_position, stack);
    if (!is_mouse_in_me (mouse_position)) return PR_LEFT;

    //--------------------------------------------------

    Tool* active_tool = palette_.get_active_tool ();
    if (!active_tool) return PR_PROCESSED;


    active_tool->on_main_button (BS_RELEASED, mouse_position, *this);


    return PR_PROCESSED;
};


Processing_result Canvas::on_mouse_moved (Point2D mouse_position, Transform_Stack& stack) {

    conver_to_local (mouse_position, stack);
    if (!is_mouse_in_me (mouse_position)) return PR_LEFT;

    //--------------------------------------------------

    Tool* active_tool = palette_.get_active_tool ();
    if (!active_tool) return PR_PROCESSED;


    active_tool->on_move (mouse_position, *this);


    return PR_PROCESSED;
};


Processing_result Canvas::on_keyboard_pressed (SDL_Keycode key) {
    (void) key;
    return PR_LEFT;
};


Processing_result Canvas::on_keyboard_released (SDL_Keycode key) {
    (void) key;
    return PR_LEFT;
};


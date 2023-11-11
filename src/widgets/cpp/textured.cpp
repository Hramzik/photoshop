

//--------------------------------------------------

#include "../hpp/widgets.hpp"

//--------------------------------------------------

Textured_Window::Textured_Window (Point2D position, Vector2D size, const char* path):
        Window (position, size),

        texture_ (size)
{
    texture_.load_from_file (path);
}

//--------------------------------------------------

void Textured_Window::render_with_final_transform (Graphic_Window& window, const Transform& result_transform) {

    SDL_Rect render_rect = get_render_rect (result_transform);

    //--------------------------------------------------

    window.render_texture (texture_, render_rect);
}


Processing_result Textured_Window::on_mouse_pressed
(Point2D mouse_position, Transform_Stack& stack) {

    convert_to_local (mouse_position, stack);

    //--------------------------------------------------

    if (is_mouse_in_me (mouse_position)) return PR_PROCESSED;

    //--------------------------------------------------

    return PR_LEFT;
}

//--------------------------------------------------


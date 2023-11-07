

//--------------------------------------------------

#include "../hpp/widgets.hpp"

//--------------------------------------------------

Textured_Window::Textured_Window (double width, double height):
        Window (width, height),
        texture_ (nullptr) {}

//--------------------------------------------------

void Textured_Window::load_texture (const char* path, const Graphic_Window& loader) {

    texture_ = loader.load_texture (path);
}


SDL_Texture* Textured_Window::get_texture (void) {

    return texture_;
}


void Textured_Window::set_texture (SDL_Texture* texture) {
    texture_ = texture;
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
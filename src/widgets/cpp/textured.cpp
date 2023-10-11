

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

void Textured_Window::render (Graphic_Window& window, Transform_Stack& transform) {

    (void) transform;

    SDL_Rect render_rect;
    render_rect.x = 0;
    render_rect.y = 0;
    render_rect.w = (int) width_;
    render_rect.h = (int) height_;

    window.render_texture (texture_, render_rect);
}


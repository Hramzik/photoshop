

//--------------------------------------------------

#include "../hpp/widgets.hpp"

//--------------------------------------------------

Window::Window (Vector2D position, double width, double height):
        Window (position, Vector2D (width, height)) {}


Window::Window (Vector2D position, Vector2D size):
        Widget (position),
        size_ (size) {}

//--------------------------------------------------

Vector2D Window::get_size (void) {

    return size_;
}


SDL_Rect Window::get_render_rect (const Transform& result_transform) {

    Vector2D result_position = result_transform.get_offset ();
    Vector2D result_size     = result_transform.apply_to_size (size_);

    //--------------------------------------------------

    SDL_Rect render_rect;

    render_rect.x = (int) result_position.x;
    render_rect.y = (int) result_position.y;
    render_rect.w = (int) result_size.x;
    render_rect.h = (int) result_size.y;


    return render_rect;
}

//--------------------------------------------------


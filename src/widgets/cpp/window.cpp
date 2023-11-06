

//--------------------------------------------------

#include "../hpp/widgets.hpp"

//--------------------------------------------------

Window::Window (Point2D position, double width, double height):
        Window (position, Vector2D (width, height)) {}


Window::Window (Point2D position, Vector2D size):
        Widget (position),
        size_ (size) {}

//--------------------------------------------------

Vector2D Window::get_size (void) {

    return size_;
}


SDL_Rect Window::get_render_rect (const Transform& result_transform) {

    Vector2D result_size = result_transform.apply_to_size (size_);
    Vector2D corner1 = result_transform.get_offset ();
    Vector2D corner2 = corner1 + result_size;

    //--------------------------------------------------

    SDL_Rect render_rect;

    render_rect.x = (int) std::min (corner1.x, corner2.x);
    render_rect.y = (int) std::min (corner1.y, corner2.y);
    render_rect.w = (int) std::abs (result_size.x);
    render_rect.h = (int) std::abs (result_size.y);


    return render_rect;
}

//--------------------------------------------------

bool Window::is_mouse_in_me (Point2D local_mouse_position) {

    if (local_mouse_position.x < 0)       return false;
    if (local_mouse_position.y < 0)       return false;
    if (local_mouse_position.x > size_.x) return false;
    if (local_mouse_position.y > size_.y) return false;


    return true;
}


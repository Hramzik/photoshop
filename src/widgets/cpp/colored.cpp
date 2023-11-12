

//--------------------------------------------------

#include "widgets/hpp/widgets.hpp"

//--------------------------------------------------


Colored_Window::Colored_Window (Point2D position, Vector2D size, My_RGB color):
        Window (position, size),
        color_ (color) {}

//--------------------------------------------------

void Colored_Window::render_with_final_transform (Graphic_Window& window, const Transform& result_transform) {

    SDL_Rect render_rect = get_render_rect (result_transform);

    //--------------------------------------------------

    window.set_drawcolor (color_);
    window.draw_rect (render_rect);
}


Processing_result Colored_Window::on_mouse_pressed
(Point2D mouse_position, Transform_Stack& stack) {

    convert_to_local (mouse_position, stack);

    //--------------------------------------------------

    if (is_mouse_in_me (mouse_position)) return PR_PROCESSED;

    //--------------------------------------------------

    return PR_LEFT;
}


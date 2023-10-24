

//--------------------------------------------------

#include "../hpp/widgets.hpp"

//--------------------------------------------------

Window::Window (Vector2D position, double width, double height):
        Window (position, Vector2D (width, height)) {}


Window::Window (Vector2D position, Vector2D size):
        Widget (position),
        size_ (size) {}


Colored_Window::Colored_Window (Vector2D position, Vector2D size, My_RGB color):
        Window (position, size),
        color_ (color) {}

//--------------------------------------------------

void Colored_Window::render (Graphic_Window& window, Transform_Stack& transform);
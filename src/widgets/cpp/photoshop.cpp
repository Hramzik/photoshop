

//--------------------------------------------------

#include "../hpp/widgets.hpp"

//--------------------------------------------------

Photoshop::Photoshop (Vector2D size):
        Photoshop (Point2D (0), size) {}


Photoshop::Photoshop (Point2D position, Vector2D size):
        Framed_Window (*new Colored_Window (position, size, C_DARK_GRAY)),

        palette_ (),
        canvas_  (position, size, palette_)
{
    register_widget (&canvas_);
}


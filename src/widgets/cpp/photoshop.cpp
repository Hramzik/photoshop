

//--------------------------------------------------

#include "../hpp/widgets.hpp"

//--------------------------------------------------

Photoshop::Photoshop (Vector2D size):
        Photoshop (0, size) {}


Photoshop::Photoshop (Point2D position, Vector2D size):
        Framed_Window (*new Colored_Window (position, size, C_DARK_GRAY)),

        tool_selection_ (),
        canvas_         (position, size, tool_selection_.get_palette ())
{
    register_widget (&tool_selection_);
    register_widget (&canvas_);
}


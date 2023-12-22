
//--------------------------------------------------

#include "widgets/hpp/widgets.hpp"

#include "canvas/hpp/canvas.hpp"

//--------------------------------------------------

Canvas_Clear_Action::Canvas_Clear_Action (Canvas_Manager& manager, plug::ColorPalette& palette):

        canvas_manager_ (manager),
        color_palette_  (palette) {}

//--------------------------------------------------

void Canvas_Clear_Action::act (void) {

    Canvas_Viewer* viewer = canvas_manager_.get_active_canvas_viewer ();
    if (!viewer) return;

    //--------------------------------------------------

    plug::Canvas& canvas      = viewer->access_canvas ();
    plug::Vec2d   canvas_size = canvas.getSize ();

    plug::VertexArray rect (plug::PrimitiveType::Quads, 4);
    plug::Color   bg_color = color_palette_.getBGColor ();

    //--------------------------------------------------

    rect [0].position = plug::Vec2d (0,             0);
    rect [1].position = plug::Vec2d (canvas_size.x, 0);
    rect [2].position = plug::Vec2d (canvas_size.x, canvas_size.y);
    rect [3].position = plug::Vec2d (0,             canvas_size.y);

    rect [0].color = bg_color;
    rect [1].color = bg_color;
    rect [2].color = bg_color;
    rect [3].color = bg_color;

    //--------------------------------------------------

    canvas.draw (rect);
}

//--------------------------------------------------


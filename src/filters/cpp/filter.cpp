

//--------------------------------------------------

#include "../../my_rgb/hpp/my_rgb.hpp"

#include "../../widgets/hpp/classes/photoshop/canvas.hpp"

#include "../hpp/filters.hpp"

//--------------------------------------------------

void Filter::apply_filter_to_pixel (My_RGB& pixel_color) {

    (void) pixel_color;
}

//--------------------------------------------------

void Filter::apply_filter (Canvas& canvas, const Filter_Mask& mask) {

    My_Texture& texture = canvas.access_texture ();

    //--------------------------------------------------

    for (int x = 0; x < mask.get_width  (); ++x) {
    for (int y = 0; y < mask.get_height (); ++y) {

        if (!mask.get_value (x, y)) continue;

        //--------------------------------------------------

        My_RGB pixel_color = texture.get_pixel (x, y);
        apply_filter_to_pixel (pixel_color);

        texture.set_drawcolor (pixel_color);
        texture.draw_point (x, y);
    }
    }
}

//--------------------------------------------------


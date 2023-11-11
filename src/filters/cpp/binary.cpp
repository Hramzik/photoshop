

//--------------------------------------------------

#include "../../my_rgb/hpp/my_rgb.hpp"

#include "../../widgets/hpp/classes/photoshop/canvas.hpp"

#include "../hpp/filters.hpp"

//--------------------------------------------------

void Binary_Filter::apply_filter_to_pixel (My_RGB& pixel_color) {

    double r = pixel_color.r;
    double g = pixel_color.g;
    double b = pixel_color.b;

    double result = (r + g + b) / 3;

    //--------------------------------------------------

    if (result >= 128) {

        pixel_color = C_WHITE;
        return;
    }

    //--------------------------------------------------

    pixel_color = C_BLACK;
}

//--------------------------------------------------


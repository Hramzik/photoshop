

//--------------------------------------------------

#include "../../my_rgb/hpp/my_rgb.hpp"

#include "../../widgets/hpp/classes/photoshop/canvas.hpp"

#include "../hpp/filters.hpp"

//--------------------------------------------------

void Monochrome_Filter::apply_filter_to_pixel (My_RGB& pixel_color) {

    double r = pixel_color.r;
    double g = pixel_color.g;
    double b = pixel_color.b;

    double result = (r + g + b) / 3;

    //--------------------------------------------------

    pixel_color.r = (unsigned char) result;
    pixel_color.g = (unsigned char) result;
    pixel_color.b = (unsigned char) result;
}

//--------------------------------------------------


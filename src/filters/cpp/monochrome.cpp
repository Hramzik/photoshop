

//--------------------------------------------------

#include "filters/hpp/plugins/monochrome.hpp"

//--------------------------------------------------

void Monochrome_Filter::apply_filter_to_pixel (plug::Color& pixel) const {

    double r = pixel.r;
    double g = pixel.g;
    double b = pixel.b;

    double result = (r + g + b) / 3;

    //--------------------------------------------------

    pixel.r = (unsigned char) result;
    pixel.g = (unsigned char) result;
    pixel.b = (unsigned char) result;
}

//--------------------------------------------------


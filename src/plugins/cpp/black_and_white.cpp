

//--------------------------------------------------

#include "plugins/hpp/plugins.hpp"

//--------------------------------------------------

Black_And_White_Filter::Black_And_White_Filter (void):
        Filter ("black & white") {}

//--------------------------------------------------

void Black_And_White_Filter::apply_filter_to_pixel (plug::Color& pixel) const {

    double r = pixel.r;
    double g = pixel.g;
    double b = pixel.b;

    double average = (r + g + b) / 3;

    //--------------------------------------------------

    if (average >= 128) {

        pixel = plug::Color (255, 255, 255);
        return;
    }

    //--------------------------------------------------

    pixel = plug::Color (0, 0, 0);
}

//--------------------------------------------------


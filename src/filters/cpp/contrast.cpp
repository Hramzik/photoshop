

//--------------------------------------------------

#include <algorithm>

#include "../../my_rgb/hpp/my_rgb.hpp"

#include "../../widgets/hpp/classes/photoshop/canvas.hpp"

#include "../hpp/filters.hpp"

//--------------------------------------------------

Contrast_Filter::Contrast_Filter
(double contrast_procent_increase):

        contrast_procent_increase_ (contrast_procent_increase) {}

//--------------------------------------------------

void Contrast_Filter::apply_filter_to_pixel (My_RGB& pixel_color) {

    double r = pixel_color.r;
    double g = pixel_color.g;
    double b = pixel_color.b;

    double procent = contrast_procent_increase_;

    //--------------------------------------------------

    r = (r * 100 - 256 * procent) / (100 - procent);
    g = (g * 100 - 256 * procent) / (100 - procent);
    b = (b * 100 - 256 * procent) / (100 - procent);

    std::clamp (r, 0., 255.);
    std::clamp (g, 0., 255.);
    std::clamp (b, 0., 255.);

    //--------------------------------------------------

    pixel_color.r = (unsigned char) r;
    pixel_color.g = (unsigned char) g;
    pixel_color.b = (unsigned char) b;
}

//--------------------------------------------------


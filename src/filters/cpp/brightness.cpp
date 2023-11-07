

//--------------------------------------------------

#include "../../my_rgb/hpp/my_rgb.hpp"

#include "../../widgets/hpp/classes/photoshop/canvas.hpp"

#include "../hpp/filters.hpp"

//--------------------------------------------------

Brightness_Filter::Brightness_Filter
(double brightness_procent_increase):

        brightness_procent_increase_ (brightness_procent_increase) {}

//--------------------------------------------------

void Brightness_Filter::apply_filter_to_pixel (My_RGB& pixel_color) {

    pixel_color += brightness_procent_increase_ * 256 / 100;
}

//--------------------------------------------------


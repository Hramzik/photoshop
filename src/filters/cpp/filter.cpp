

//--------------------------------------------------

#include "filters/hpp/filters.hpp"

//--------------------------------------------------

void Filter::applyFilter (plug::Canvas& canvas) {

    plug::Texture& texture = canvas.getTexture ();

    //--------------------------------------------------

    for (int x = 0; x < texture.width;  ++x) {
    for (int y = 0; y < texture.height; ++y) {

        if (!canvas.getSelectionMask ().getPixel (x, y)) continue;

        //--------------------------------------------------

        plug::Color pixel_color = texture.getPixel (x, y);
        apply_filter_to_pixel (pixel_color);

        texture.setPixel (x, y, pixel_color);
    }
    }
}


void Filter::apply_filter_to_pixel (plug::Color& pixel) {

    (void) pixel;
}

//--------------------------------------------------

plug::Widget* getWidget (void) {

    return nullptr;
}

//--------------------------------------------------


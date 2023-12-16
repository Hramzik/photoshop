

//--------------------------------------------------

#include "filters/hpp/filters.hpp"

//--------------------------------------------------

void Filter::applyFilter (plug::Canvas& canvas) const {

    const plug::Texture& texture = canvas.getTexture ();

    //--------------------------------------------------

    for (int x = 0; x < (int) canvas.getSize ().x; ++x) {
    for (int y = 0; y < (int) canvas.getSize ().y; ++y) {

        if (!canvas.getSelectionMask ().getPixel (x, y)) continue;

        //--------------------------------------------------

        plug::Color pixel_color = texture.getPixel (x, y);
        apply_filter_to_pixel (pixel_color);

        canvas.setPixel (x, y, pixel_color);
    }}
}


void Filter::apply_filter_to_pixel (plug::Color& pixel) const {

    (void) pixel;
}

//--------------------------------------------------

plug::Widget* Filter::getWidget (void) {

    return nullptr;
}

//--------------------------------------------------
// plugin api code

plug::Plugin* Filter::tryGetInterface (size_t interface_id) {

    (void) interface_id;

    //--------------------------------------------------

    return nullptr;
}

const plug::PluginData* Filter::getPluginData (void) const {

    return nullptr;
}

void Filter::addReference (void) {

    return;
}

void Filter::release (void) {

    return;
}

//--------------------------------------------------


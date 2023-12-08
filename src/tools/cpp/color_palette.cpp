

//--------------------------------------------------

#include "tools/hpp/tools.hpp"

//--------------------------------------------------

Color_Palette::Color_Palette (void):

    bg_color_ (plug::Color {255, 255, 255}),
    fg_color_ (plug::Color {0,   0,   0}) {}

//--------------------------------------------------

plug::Color Color_Palette::getFGColor (void) const {

    return fg_color_;
}

plug::Color Color_Palette::getBGColor (void) const {

    return bg_color_;
}

void Color_Palette::setFGColor (plug::Color new_fg_color) {

    fg_color_ = new_fg_color;
}

void Color_Palette::setBGColor (plug::Color new_bg_color) {

    bg_color_ = new_bg_color;
}

//--------------------------------------------------


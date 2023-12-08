#ifndef CLASS_COLOR_PALETTE_HPP_INCLUDED
#define CLASS_COLOR_PALETTE_HPP_INCLUDED
//--------------------------------------------------

#include "Plug/Tool/ColorPalette.h"

//--------------------------------------------------

class Color_Palette: public plug::ColorPalette {

  public:

    Color_Palette (void);

    plug::Color getFGColor (void) const override;
    plug::Color getBGColor (void) const override;

    void setFGColor (plug::Color new_fg_color) override;
    void setBGColor (plug::Color new_bg_color) override;

//--------------------------------------------------

  private:

    plug::Color bg_color_;
    plug::Color fg_color_;
};


//--------------------------------------------------
#endif
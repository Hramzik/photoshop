#ifndef CLASS_CANVAS_CLEAR_ACTION_HPP_INCLUDED
#define CLASS_CANVAS_CLEAR_ACTION_HPP_INCLUDED
//--------------------------------------------------

#include "widgets/hpp/classes/actions/action.hpp"

//--------------------------------------------------

class Canvas_Manager;
#include "Plug/Tool/ColorPalette.h"

//--------------------------------------------------

class Canvas_Clear_Action: public Action {

  public:

    Canvas_Clear_Action (Canvas_Manager& manager, plug::ColorPalette& palette);

    //--------------------------------------------------

    void act (void) override;

  private:

    Canvas_Manager&       canvas_manager_;
    plug::ColorPalette&  color_palette_;
};

//--------------------------------------------------
#endif
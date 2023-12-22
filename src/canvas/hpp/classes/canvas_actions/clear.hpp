#ifndef CLASS_CANVAS_CLEAR_ACTION_HPP_INCLUDED
#define CLASS_CANVAS_CLEAR_ACTION_HPP_INCLUDED
//--------------------------------------------------

#include "widgets/hpp/classes/actions/action.hpp"

//--------------------------------------------------

class Canvas_Manager;
class Color_Palette;

//--------------------------------------------------

class Canvas_Clear_Action: public Action {

  public:

    Canvas_Clear_Action (Canvas_Manager& manager, Color_Palette& palette);

    //--------------------------------------------------

    void act (void) override;

  private:

    Canvas_Manager& canvas_manager_;
    Color_Palette&  color_palette_;
};

//--------------------------------------------------
#endif
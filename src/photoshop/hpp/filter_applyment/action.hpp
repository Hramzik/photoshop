#ifndef FILTER_APPLYMENT_ACTION_HPP_INCLUDED
#define FILTER_APPLYMENT_ACTION_HPP_INCLUDED
//--------------------------------------------------

#include "tools/hpp/tools.hpp"

#include "my_rgb/hpp/my_rgb.hpp"

#include "widgets/hpp/classes/actions/action.hpp"

//--------------------------------------------------

class Color_Selection_Action: public Action {

  public:

    Color_Selection_Action (Color_Palette& palette, My_RGB color);

    //--------------------------------------------------

    void act (void) override;

  private:

    My_RGB color_;
    Color_Palette& palette_;
};


//--------------------------------------------------
#endif
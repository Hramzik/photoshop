#ifndef CLASS_FILTER_SELECTION_BUTTON_HPP_INCLUDED
#define CLASS_FILTER_SELECTION_BUTTON_HPP_INCLUDED
//--------------------------------------------------

#include "../buttons/button.hpp"

//--------------------------------------------------

class Filter_Palette;
class Canvas;

//--------------------------------------------------

class Filter_Selection_Button: public Button {

  public:

    Filter_Selection_Button (Window& model, int filter_id, Filter_Palette& palette, Canvas& canvas);

    //--------------------------------------------------

    void do_when_pressed (void) override;

//--------------------------------------------------

  private:

    int             filter_id_;
    Filter_Palette& palette_;
    Canvas&         canvas_;
};


//--------------------------------------------------
#endif
#ifndef CLASS_TOOL_SELECTION_BUTTON_HPP_INCLUDED
#define CLASS_TOOL_SELECTION_BUTTON_HPP_INCLUDED
//--------------------------------------------------

#include "../buttons/button.hpp"

//--------------------------------------------------

class Tool_Palette;

//--------------------------------------------------

class Tool_Selection_Button: public Button {

  public:

    enum Tool_type {

        PENCIL,
        RECT,
    };

    //--------------------------------------------------

    Tool_Selection_Button (Window& model, Tool_type tool, Tool_Palette& palette);

    //--------------------------------------------------

    void do_when_pressed (void) override;

//--------------------------------------------------

  private:

    Tool_type tool_;
    Tool_Palette& palette_;
};


//--------------------------------------------------
#endif
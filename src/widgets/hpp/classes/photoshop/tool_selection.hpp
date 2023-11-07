#ifndef WIDGETS_CLASS_TOOL_SELECTION_HPP_INCLUDED
#define WIDGETS_CLASS_TOOL_SELECTION_HPP_INCLUDED
//--------------------------------------------------

#include "../../../../tools/hpp/tools.hpp"

//--------------------------------------------------


// графическое представление палитры
// владеет своей палитрой
class Tool_Selection_Widget: public Widget {

  public:

    Tool_Selection_Widget (void);

    //--------------------------------------------------

    Tool_Palette& get_palette (void);

    //--------------------------------------------------

    void render (Graphic_Window& window, Transform_Stack& stack) override;

    Processing_result on_keyboard_released (SDL_Keycode key) override;

//--------------------------------------------------

  private:

    Tool_Palette palette_;
};

//--------------------------------------------------
#endif
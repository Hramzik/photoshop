#ifndef WIDGETS_CLASS_TOOL_SELECTION_HPP_INCLUDED
#define WIDGETS_CLASS_TOOL_SELECTION_HPP_INCLUDED
//--------------------------------------------------

#include "../../../../tools/hpp/tools.hpp"

#include "../framed_window/framed_window.hpp"

//--------------------------------------------------


// графическое представление палитры
// владеет своей палитрой
class Tool_Selection_Widget: public Framed_Window {

  public:

    Tool_Selection_Widget (/*Point2D position, Vector2D size*/);

    //--------------------------------------------------

    Tool_Palette& access_palette (void);

    //--------------------------------------------------

    void render (Graphic_Window& window, Transform_Stack& stack) override;

    Processing_result on_keyboard_released (SDL_Keycode key) override;

//--------------------------------------------------

  private:

    Tool_Palette palette_;
};

//--------------------------------------------------
#endif
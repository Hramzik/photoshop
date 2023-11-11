#ifndef CLASS_TOOL_SELECTION_HPP_INCLUDED
#define CLASS_TOOL_SELECTION_HPP_INCLUDED
//--------------------------------------------------

#include "../../../../tools/hpp/tools.hpp"

#include "../framed_window/framed_window.hpp"

#include "tool_selection_button.hpp"

//--------------------------------------------------


// графическое представление палитры
// владеет своей палитрой
class Tool_Selection_Widget: public Framed_Window {

  public:

    Tool_Selection_Widget (Point2D position, Vector2D size);

    //--------------------------------------------------

    void add_tool_selection_button (Tool_Selection_Button::Tool_type tool);
    Tool_Palette& access_palette (void);

    //--------------------------------------------------

    Processing_result on_keyboard_released (SDL_Keycode key) override;

//--------------------------------------------------

  private:

    Tool_Palette palette_;
    Button_Manager tools_;
};

//--------------------------------------------------
#endif
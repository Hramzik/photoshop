

//--------------------------------------------------

#include "../hpp/widgets.hpp"

//--------------------------------------------------

Tool_Selection_Widget::Tool_Selection_Widget (void):
        Widget   (0),
        palette_ () {}

//--------------------------------------------------

Tool_Palette& Tool_Selection_Widget::get_palette (void) {

    return palette_;
}


void Tool_Selection_Widget::render
(Graphic_Window& window, Transform_Stack& stack) {

    (void) window, (void) stack;
}

Processing_result Tool_Selection_Widget::on_keyboard_released (SDL_Keycode key) {

    switch (key) {

        case SDLK_b: palette_.select_brush_tool (); return PR_PROCESSED;
        case SDLK_r: palette_.select_rect_tool  (); return PR_PROCESSED;

        default: return PR_LEFT;
    }
}

//--------------------------------------------------


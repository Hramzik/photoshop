

//--------------------------------------------------

#include "tool.hpp"

//--------------------------------------------------


void Tool::apply_begin (SDL_Texture* texture, int mouse_x, int mouse_y) {}
void Tool::apply_continue (SDL_Texture* texture, int mouse_x, int mouse_y) {}
void Tool::apply_next (SDL_Texture* texture, int mouse_x, int mouse_y) {}
void Tool::apply_end (SDL_Texture* texture, int mouse_x, int mouse_y) {}

void Tool::draw_self (Graphic_Window& window, Transform_Stack& transforms) {}
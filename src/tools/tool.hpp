#ifndef TOOL_HPP_INCLUDED
#define TOOL_HPP_INCLUDED
//--------------------------------------------------

#include "../graphics/hpp/graphics.hpp"
#include "../transform/hpp/transform.hpp"

//--------------------------------------------------


class Tool {

  public:

    void apply_begin    (SDL_Texture* texture, int mouse_x, int mouse_y);
    void apply_continue (SDL_Texture* texture, int mouse_x, int mouse_y);
    void apply_next     (SDL_Texture* texture, int mouse_x, int mouse_y);
    void apply_end      (SDL_Texture* texture, int mouse_x, int mouse_y);

    void draw_self (Graphic_Window& window, Transform_Stack& transforms);

  private:

    
};


//--------------------------------------------------
#endif
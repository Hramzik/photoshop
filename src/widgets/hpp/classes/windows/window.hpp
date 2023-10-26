#ifndef WIDGETS_CLASS_WINDOW_HPP_INCLUDED
#define WIDGETS_CLASS_WINDOW_HPP_INCLUDED
//--------------------------------------------------

#include "../../../../vector/hpp/vector.hpp"

#include "../widget.hpp"

//--------------------------------------------------


class Window: public Widget {

  public:

    Window (Vector2D position, double width, double height);
    Window (Vector2D position, Vector2D size);

    //--------------------------------------------------

    Vector2D get_size (void);

//--------------------------------------------------

  protected:

    SDL_Rect get_render_rect (const Transform& result_transform);

    //--------------------------------------------------

    Vector2D size_;
};


//--------------------------------------------------
#endif
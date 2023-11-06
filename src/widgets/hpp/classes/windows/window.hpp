#ifndef WIDGETS_CLASS_WINDOW_HPP_INCLUDED
#define WIDGETS_CLASS_WINDOW_HPP_INCLUDED
//--------------------------------------------------

#include "../../../../vector/hpp/vector.hpp"

#include "../widget.hpp"

//--------------------------------------------------


// window - это widget, имеющий размер
// размер может быть отрицательным,
// ведь обычно это просто вектор до второго угла окна
class Window: public Widget {

  public:

    Window (Point2D position, double width, double height);
    Window (Point2D position, Vector2D size);

    //--------------------------------------------------

    Vector2D get_size (void);
    bool is_mouse_in_me (Point2D local_mouse_position);

//--------------------------------------------------

  protected:

    SDL_Rect get_render_rect (const Transform& result_transform);

    //--------------------------------------------------

    Vector2D size_;
};


//--------------------------------------------------
#endif
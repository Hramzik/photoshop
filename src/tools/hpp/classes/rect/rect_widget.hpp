#ifndef TOOLS_CLASS_RECT_TOOL_WIDGET_HPP_INCLUDED
#define TOOLS_CLASS_RECT_TOOL_WIDGET_HPP_INCLUDED
//--------------------------------------------------

#include "../../../../widgets/hpp/classes/windows/window.hpp"

//--------------------------------------------------


class Rect_Tool_Widget: public Window {

  public:

    Rect_Tool_Widget (void);

    //--------------------------------------------------

    Point2D get_origin (void);
    Point2D get_end    (void);
    bool is_visible    (void);
    bool is_filled     (void);
    void set_origin      (Point2D origin);
    void set_end         (Point2D end);
    void set_visibility  (bool is_visible);
    void set_filling     (bool is_filled);
    void reverse_filling (void);

//--------------------------------------------------

  private:

    bool is_visible_;
    bool is_filled_;

    //--------------------------------------------------

    // цвет должен быть проставлен палеткой
    void render_with_final_transform
    (Graphic_Window& window, const Transform& result_transform)
    override;
};


//--------------------------------------------------
#endif
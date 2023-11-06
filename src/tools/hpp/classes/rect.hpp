#ifndef TOOLS_CLASS_RECT_HPP_INCLUDED
#define TOOLS_CLASS_RECT_HPP_INCLUDED
//--------------------------------------------------

#include "../../../widgets/hpp/classes/windows/window.hpp"

#include "tool.hpp"

//--------------------------------------------------

class Window;

class Tool_Palette;

//--------------------------------------------------


class Rect_Tool: public Tool {

  public:

    Rect_Tool (const Tool_Palette& palette);

    //--------------------------------------------------

    void on_main_button
    (Button_state state, Point2D mouse_position, Canvas& canvas)
    override;

    void on_modifier1
    (Button_state state, Point2D mouse_position, Canvas& canvas)
    override;

    void on_modifier2
    (Button_state state, Point2D mouse_position, Canvas& canvas)
    override;

    void on_move   (Point2D mouse_position, Canvas& canvas) override;
    void on_cancel (Point2D mouse_position, Canvas& canvas) override;

//--------------------------------------------------

  private:

    bool is_being_dragged_;

    //--------------------------------------------------

    const Tool_Palette& my_palette_;
};


class Rect_Tool_Widget: public Window {

  public:

    Rect_Tool_Widget (void);

    //--------------------------------------------------

    void set_origin     (Point2D origin);
    void set_end        (Point2D end);
    void set_visibility (bool is_visible);
    void set_filling    (bool is_filled);

//--------------------------------------------------

  private:

    bool is_visible_;
    bool is_filled_;

    //--------------------------------------------------

    // цвет должен быть проставлен
    void render_with_final_transform
    (Graphic_Window& window, const Transform& result_transform)
    override;
};


//--------------------------------------------------
#endif
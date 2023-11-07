#ifndef WIDGETS_CLASS_CANVAS_HPP_INCLUDED
#define WIDGETS_CLASS_CANVAS_HPP_INCLUDED
//--------------------------------------------------

#include "../../../../filters/hpp/filters.hpp"

#include "../windows/window.hpp"

//--------------------------------------------------

class Tool_Palette;

//--------------------------------------------------

class Canvas: public Window {

  public:

    // size = pixel_size = local_size
    Canvas (Point2D       position,     Vector2D        size,
            Tool_Palette& tool_palette, Filter_Palette& filter_palette);

    Canvas (Vector2D      size,
            Tool_Palette& tool_palette, Filter_Palette& filter_palette);

    //--------------------------------------------------

    My_Texture& access_texture (void);

    Processing_result on_mouse_moved    (Point2D mouse_position, Transform_Stack& stack) override;
    Processing_result on_mouse_pressed  (Point2D mouse_position, Transform_Stack& stack) override;
    Processing_result on_mouse_released (Point2D mouse_position, Transform_Stack& stack) override;

    Processing_result on_keyboard_pressed  (SDL_Keycode key) override;
    Processing_result on_keyboard_released (SDL_Keycode key) override;

//--------------------------------------------------

private:

    My_Texture texture_;

    Tool_Palette&   my_tool_palette_;
    Filter_Mask     my_filter_mask_;
    Filter_Palette& my_filter_palette_;

    bool    drawing_;
    Point2D last_mouse_position_;

    //--------------------------------------------------

    void render_with_local_stack
    (Graphic_Window& window, Transform_Stack& local_stack)
    override;

    void render_with_final_transform
    (Graphic_Window& window, const Transform& result_transform)
    override;
};


//--------------------------------------------------
#endif
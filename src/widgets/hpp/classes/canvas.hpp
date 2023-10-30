#ifndef WIDGETS_CLASS_CANVAS_HPP_INCLUDED
#define WIDGETS_CLASS_CANVAS_HPP_INCLUDED
//--------------------------------------------------

#include "../../../vector/hpp/vector.hpp"
#include "../../../graphics/hpp/graphics.hpp"

#include "../widgets.hpp"

//--------------------------------------------------

class Canvas: public Window {

  public:

    // size = pixel_size = local_size
    Canvas (Point2D position, Vector2D size /*Tool_Palette& palette*/);

    //--------------------------------------------------

    virtual void render_with_final_transform (Graphic_Window& window, const Transform& result_transform) override;

    virtual Processing_result on_mouse_moved    (Point2D mouse_position, Transform_Stack& stack) override;
    virtual Processing_result on_mouse_pressed  (Point2D mouse_position, Transform_Stack& stack) override;
    virtual Processing_result on_mouse_released (Point2D mouse_position, Transform_Stack& stack) override;

    virtual Processing_result on_keyboard_pressed  (SDL_Keycode key) override;
    virtual Processing_result on_keyboard_released (SDL_Keycode key) override;

private:

    My_Texture texture_;
    /*tool::ToolPalette& m_palette*/;

    bool    drawing_;
    Point2D last_mouse_position_;
};


//--------------------------------------------------
#endif
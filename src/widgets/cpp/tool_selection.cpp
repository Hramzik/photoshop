

//--------------------------------------------------

#include "widgets/hpp/widgets.hpp"

//--------------------------------------------------

Tool_Selection_Widget::Tool_Selection_Widget (Point2D position, Vector2D size):

        Framed_Window (*new Window (position, size)),

        palette_ (),
        tools_   (*new Colored_Window (0, size, C_LIGHT_GRAY), 2, 0.05)
{
    register_widget (&tools_);
}

//--------------------------------------------------

void Tool_Selection_Widget::add_tool_selection_button (Tool_Selection_Button::Tool_type tool) {

    Point2D  position = tools_.get_new_button_position ();
    Vector2D size     = tools_.get_button_size ();

    const char* path = "media/pencil.png";
    if (tool == Tool_Selection_Button::RECT) path = "media/rect.png";

    //--------------------------------------------------

    Window* button_model = new Textured_Window (position, size, path);
    Button* new_button   = new Tool_Selection_Button (*button_model, tool, palette_);

    //--------------------------------------------------

    tools_.add_button (*new_button);
}


Tool_Palette& Tool_Selection_Widget::access_palette (void) {

    return palette_;
}


Processing_result Tool_Selection_Widget::on_keyboard_released (SDL_Keycode key) {

    switch (key) {

        case SDLK_b: palette_.select_brush_tool (); return PR_PROCESSED;
        case SDLK_r: palette_.select_rect_tool  (); return PR_PROCESSED;

        default: return PR_LEFT;
    }
}

//--------------------------------------------------


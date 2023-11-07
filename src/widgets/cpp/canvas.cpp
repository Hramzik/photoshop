

//--------------------------------------------------

#include "../hpp/widgets.hpp"

//--------------------------------------------------

Canvas::Canvas
(Point2D position,          Vector2D size,
Tool_Palette& tool_palette, Filter_Palette& filter_palette):

        Window (position, size),
        texture_ (size),

        my_tool_palette_   (tool_palette),
        my_filter_mask_ ((int) size.x, (int) size.y),
        my_filter_palette_ (filter_palette),

        drawing_ (false),
        last_mouse_position_ (0) {


    texture_.set_drawcolor (C_BLACK);
}

Canvas::Canvas
(Vector2D size,
Tool_Palette& tool_palette, Filter_Palette& filter_palette):

    Canvas (0, size, tool_palette, filter_palette) {}

//--------------------------------------------------

My_Texture& Canvas::access_texture (void) {

    return texture_;
}

//--------------------------------------------------


void Canvas::render_with_local_stack
    (Graphic_Window& window, Transform_Stack& local_stack) {

    //--------------------------------------------------
    // render canvas
    render_with_final_transform (window, local_stack.get_result ());

    //--------------------------------------------------
    // render tool preview

    Tool* active_tool = my_tool_palette_.get_active_tool ();
    if (!active_tool) return;

    //--------------------------------------------------

    Widget* preview = active_tool->get_widget ();
    if (!preview) return;

    //--------------------------------------------------

    window.set_drawcolor (my_tool_palette_.get_active_color ());
    preview->render (window, local_stack);
}


void Canvas::render_with_final_transform (Graphic_Window& window, const Transform& result_transform) {

    SDL_Rect render_rect = get_render_rect (result_transform);

    //--------------------------------------------------

    window.render_texture (texture_, render_rect);
};


Processing_result Canvas::on_mouse_pressed (Point2D mouse_position, Transform_Stack& stack) {

    convert_to_local (mouse_position, stack);
    if (!is_mouse_in_me (mouse_position)) return PR_LEFT;

    //--------------------------------------------------

    Tool* active_tool = my_tool_palette_.get_active_tool ();
    if (!active_tool) return PR_PROCESSED;


    active_tool->on_main_button (BS_PRESSED, mouse_position, *this);


    return PR_PROCESSED;
};


Processing_result Canvas::on_mouse_released (Point2D mouse_position, Transform_Stack& stack) {

    convert_to_local (mouse_position, stack);
    //if (!is_mouse_in_me (mouse_position)) return PR_LEFT;

    //--------------------------------------------------

    Tool* active_tool = my_tool_palette_.get_active_tool ();
    if (!active_tool) return PR_PROCESSED;


    active_tool->on_main_button (BS_RELEASED, mouse_position, *this);


    return PR_PROCESSED;
};


Processing_result Canvas::on_mouse_moved (Point2D mouse_position, Transform_Stack& stack) {

    convert_to_local (mouse_position, stack);
    //if (!is_mouse_in_me (mouse_position)) return PR_LEFT;

    //--------------------------------------------------

    Tool* active_tool = my_tool_palette_.get_active_tool ();
    if (!active_tool) return PR_PROCESSED;


    active_tool->on_move (mouse_position, *this);


    return PR_PROCESSED;
};


Processing_result Canvas::on_keyboard_pressed (SDL_Keycode key) {

    Tool* active_tool = my_tool_palette_.get_active_tool ();
    if (!active_tool) return PR_LEFT;

    //--------------------------------------------------

    switch (key) {

        case SDLK_LSHIFT: active_tool->on_modifier1 (BS_PRESSED, *this); return PR_PROCESSED;
        case SDLK_LCTRL:  active_tool->on_modifier2 (BS_PRESSED, *this); return PR_PROCESSED;
        case SDLK_LALT:   active_tool->on_modifier3 (BS_PRESSED, *this); return PR_PROCESSED;

        default: return PR_LEFT;
    }
};


Processing_result Canvas::on_keyboard_released (SDL_Keycode key) {

    // rewrite, tool_event and filter_event
    Tool* active_tool = my_tool_palette_.get_active_tool ();
    if (!active_tool) return PR_LEFT;

    Filter* filter1 = my_filter_palette_.filters_ [0]; assert (filter1);
    Filter* filter2 = my_filter_palette_.filters_ [1]; assert (filter2);
    Filter* filter3 = my_filter_palette_.filters_ [2]; assert (filter3);

    //--------------------------------------------------

    switch (key) {

        case SDLK_LSHIFT: active_tool->on_modifier1 (BS_RELEASED, *this); return PR_PROCESSED;
        case SDLK_LCTRL:  active_tool->on_modifier2 (BS_RELEASED, *this); return PR_PROCESSED;
        case SDLK_LALT:   active_tool->on_modifier3 (BS_RELEASED, *this); return PR_PROCESSED;

        case SDLK_ESCAPE: active_tool->on_cancel (); return PR_PROCESSED;

        case SDLK_z: filter1->apply_filter (*this, my_filter_mask_); return PR_PROCESSED;
        case SDLK_r: filter2->apply_filter (*this, my_filter_mask_); return PR_PROCESSED;
        case SDLK_m: filter3->apply_filter (*this, my_filter_mask_); return PR_PROCESSED;

        default: return PR_LEFT;
    }
};


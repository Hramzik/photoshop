

//--------------------------------------------------


#include "../hpp/widgets.hpp"


//--------------------------------------------------

Widget_Container::Widget_Container (Transform transform):
        Widget         (transform),
        widgets_       (),
        active_widget_ (nullptr) {}


Widget_Container::Widget_Container (Vector2D position):
        Widget_Container (Transform (position)) {}

//--------------------------------------------------

void Widget_Container::register_widget (Widget* widget) {

    widgets_.push_back (widget);
}

//--------------------------------------------------

void Widget_Container::render_with_local_stack
        (Graphic_Window& window, Transform_Stack& stack) {

    for (auto i = widgets_.rbegin (); i != widgets_.rend (); ++i) {

        Widget* widget = *i;
        widget->render (window, stack);
    }
}


Processing_result Widget_Container::on_mouse_move (int mouse_x, int mouse_y) {

    Vector2D mouse_position = get_local_mouse_position (mouse_x, mouse_y);

    for (Widget* widget : widgets_) {

        widget->on_mouse_move ((int) mouse_position.x, (int) mouse_position.y);
    }


    return PR_LEFT;
}


Processing_result Widget_Container::on_mouse_press (int mouse_x, int mouse_y) {

    Vector2D mouse_position = get_local_mouse_position (mouse_x, mouse_y);

    for (Widget* widget : widgets_) {

        widget->on_mouse_press ((int) mouse_position.x, (int) mouse_position.y);
    }


    return PR_LEFT;
}


Processing_result Widget_Container::on_mouse_release (int mouse_x, int mouse_y) {

    Vector2D mouse_position = get_local_mouse_position (mouse_x, mouse_y);

    for (Widget* widget : widgets_) {

        widget->on_mouse_release ((int) mouse_position.x, (int) mouse_position.y);
    }


    return PR_LEFT;
}


Processing_result Widget_Container::on_keyboard_press (SDL_Keycode key) {

    for (Widget* widget : widgets_) {

        widget->on_keyboard_press (key);
    }


    return PR_LEFT;
}


Processing_result Widget_Container::on_keyboard_release (SDL_Keycode key) {

    for (Widget* widget : widgets_) {

        widget->on_keyboard_release (key);
    }


    return PR_LEFT;
}


Processing_result Widget_Container::on_timer (clock_t current_time) {

    for (Widget* widget : widgets_) {

        widget->on_timer (current_time);
    }


    return PR_LEFT;
}

//--------------------------------------------------

// todo: rewrite using stack transform
Vector2D Widget_Container::get_local_mouse_position () {

    Vector2D mouse_position (mouse_x, mouse_y);


    return mouse_position - my_transform_.get_offset ();
}


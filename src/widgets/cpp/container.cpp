

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


Processing_result Widget_Container::on_mouse_moved (Point2D mouse_position, Transform_Stack& stack) {

    stack.push (my_transform_);

    for (Widget* widget : widgets_) {

        widget->on_mouse_moved (mouse_position, stack);
    }

    stack.pop ();


    return PR_LEFT;
}


Processing_result Widget_Container::on_mouse_pressed (Point2D mouse_position, Transform_Stack& stack) {

    stack.push (my_transform_);

    for (Widget* widget : widgets_) {

        widget->on_mouse_pressed (mouse_position, stack);
    }

    stack.pop ();


    return PR_LEFT;
}


Processing_result Widget_Container::on_mouse_released (Point2D mouse_position, Transform_Stack& stack) {

    stack.push (my_transform_);

    for (Widget* widget : widgets_) {

        widget->on_mouse_released (mouse_position, stack);
    }

    stack.pop ();


    return PR_LEFT;
}


Processing_result Widget_Container::on_keyboard_pressed (SDL_Keycode key) {

    for (Widget* widget : widgets_) {

        widget->on_keyboard_pressed (key);
    }


    return PR_LEFT;
}


Processing_result Widget_Container::on_keyboard_released (SDL_Keycode key) {

    for (Widget* widget : widgets_) {

        widget->on_keyboard_released (key);
    }


    return PR_LEFT;
}


Processing_result Widget_Container::on_timer (clock_t current_time) {

    for (Widget* widget : widgets_) {

        widget->on_timer (current_time);
    }


    for (auto i = widgets_.begin (); i != widgets_.end () ; ++i) {

        if ((*i)->is_closed ()) {

            free (*i);
            widgets_.erase (i);
        }
    }


    return PR_LEFT;
}

//--------------------------------------------------


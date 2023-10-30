

//--------------------------------------------------

#include "../hpp/app.hpp"

//--------------------------------------------------

App::App (void):
        widgets_         (Vector2D (0)),
        transform_stack_ (),

        window_ (),

        exit_ (false)
{
    populate ();
}

//--------------------------------------------------

void App::run (void) {

    while (!exit_) {

        update ();
        render ();
    }
}


void App::update (void) {

    SDL_Event event;

    while (SDL_PollEvent (&event)) {
    switch (event.type) {

        case SDL_QUIT: exit_ = true; break;

        case SDL_MOUSEMOTION: on_mouse_event (event, { event.motion.x, event.motion.y }); break;
        case SDL_MOUSEBUTTONDOWN:
        case SDL_MOUSEBUTTONUP: on_mouse_event (event, { event.button.x, event.button.y }); break;

        case SDL_KEYDOWN: widgets_.on_keyboard_pressed  (event.key.keysym.sym); break;
        case SDL_KEYUP:   widgets_.on_keyboard_released (event.key.keysym.sym); break;
    }}


    widgets_.on_timer (clock ());
}


void App::on_mouse_event (SDL_Event event, Point2D sdl_mouse_position) {

    Point2D mouse_position = sdl_mouse_position;
    mouse_position.y = window_.get_height () - mouse_position.y;

    switch (event.type) {

        case SDL_MOUSEMOTION:
            widgets_.on_mouse_moved (mouse_position, transform_stack_); break;

        case SDL_MOUSEBUTTONDOWN:
            widgets_.on_mouse_pressed (mouse_position, transform_stack_); break;

        case SDL_MOUSEBUTTONUP:
            widgets_.on_mouse_released (mouse_position, transform_stack_); break;

        default: LOG_ERROR (BAD_ARGS); break;
    }
}


void App::render (void) {

    window_.clear_screen ();

    //--------------------------------------------------

    Transform_Stack tmp;
    widgets_.render (window_, tmp);

    //--------------------------------------------------

    window_.update_screen ();

}

/*
void App::open_clock (void) {

    Clock_Widget* clock = new Clock_Widget (500, 540);
    clock->load_textures (window_);


    widgets_.register_widget (clock);
}
*/

void App::populate (void) {

    Colored_Window*       window = new Colored_Window ({0}, {200}, C_WHITE);
    Framed_Window* framed_window = new Framed_Window (*window);

    widgets_.register_widget (framed_window);

    //--------------------------------------------------

    Canvas* canvas = new Canvas ({200}, {200});
    widgets_.register_widget (canvas);
}

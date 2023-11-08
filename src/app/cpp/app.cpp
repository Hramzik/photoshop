

//--------------------------------------------------

#include "../hpp/app.hpp"

//--------------------------------------------------

App::App (void):
        widgets_         (Vector2D (0)),
        transform_stack_ (),

        window_ (SDL_WINDOW_FULLSCREEN_DESKTOP),

        sdl_exit_ (false)
{
    populate ();
}

//--------------------------------------------------

void App::run (void) {

    while (is_alive ()) {

        update ();
        render ();
    }
}


bool App::is_alive (void) {

    if (sdl_exit_)                return false;
    if (!exist_opened_widgets ()) return false;


    return true;
}


bool App::exist_opened_widgets (void) {

    if (!widgets_.get_widgets_count ()) return false;


    return true;
}

//--------------------------------------------------

void App::update (void) {

    SDL_Event event;

    while (SDL_PollEvent (&event)) {
    switch (event.type) {

        case SDL_QUIT: sdl_exit_ = true; break;

        case SDL_MOUSEMOTION:
        case SDL_MOUSEBUTTONDOWN:
        case SDL_MOUSEBUTTONUP: on_mouse_event (event); break;

        case SDL_KEYDOWN: widgets_.on_keyboard_pressed  (event.key.keysym.sym); break;
        case SDL_KEYUP:   widgets_.on_keyboard_released (event.key.keysym.sym); break;
    }}


    widgets_.on_timer (clock ());
}


void App::on_mouse_event (SDL_Event event) {

    //--------------------------------------------------
    // getting mouse position

    Point2D mouse_position;

    switch (event.type) {

        case SDL_MOUSEMOTION: mouse_position.x = event.motion.x;
                              mouse_position.y = event.motion.y;
                              break;

        //--------------------------------------------------

        case SDL_MOUSEBUTTONDOWN:
        case SDL_MOUSEBUTTONUP: mouse_position.x = event.motion.x;
                                mouse_position.y = event.motion.y;
                                break;

        //--------------------------------------------------

        default: LOG_ERROR (BAD_ARGS); return;
    }

    mouse_position.y = window_.get_height () - mouse_position.y;

    //--------------------------------------------------
    // handling event

    switch (event.type) {

        case SDL_MOUSEMOTION:
            widgets_.on_mouse_moved (mouse_position, transform_stack_); break;

        case SDL_MOUSEBUTTONDOWN:
            widgets_.on_mouse_pressed (mouse_position, transform_stack_); break;

        case SDL_MOUSEBUTTONUP:
            widgets_.on_mouse_released (mouse_position, transform_stack_); break;

        default: LOG_ERROR (BAD_ARGS); return;
    }
}


void App::render (void) {

    window_.clear_screen ();

    //--------------------------------------------------

    widgets_.render (window_, transform_stack_);

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

    /*Colored_Window*       window = new Colored_Window ({0}, {200}, C_DARK_GRAY);
    Framed_Window* framed_window = new Framed_Window (*window);

    widgets_.register_widget (framed_window);*/

    //--------------------------------------------------

    Point2D  position (200, 40);
    Vector2D size     (1400, 1000);

    Photoshop* photoshop = new Photoshop (position, size);

    //--------------------------------------------------

    widgets_.register_widget (photoshop);
}

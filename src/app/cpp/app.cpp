

//--------------------------------------------------

#include "../hpp/app.hpp"

//--------------------------------------------------

App::App (void):
        widgets_ (Vector2D (0)),
        window_  (),
        exit_ (false) {

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

        case SDL_MOUSEMOTION:
            widgets_.on_mouse_move (event.motion.x, window_.get_height () - event.motion.y);
            break;
        case SDL_MOUSEBUTTONDOWN:
            widgets_.on_mouse_press (event.button.x, window_.get_height () - event.button.y);
            break;
        case SDL_MOUSEBUTTONUP:
            widgets_.on_mouse_release (event.button.x, window_.get_height () - event.button.y);
            break;

        case SDL_KEYDOWN: widgets_.on_keyboard_press   (event.key.keysym.sym); break;
        case SDL_KEYUP:   widgets_.on_keyboard_release (event.key.keysym.sym); break;
    }}


    widgets_.on_timer (clock ());
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
}

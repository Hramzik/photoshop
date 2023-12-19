

//--------------------------------------------------

#include "photoshop/hpp/photoshop.hpp"

#include "app/hpp/app.hpp"

//--------------------------------------------------

const double App::DEFAULT_APP_WINDOW_WIDTH  = 800;
const double App::DEFAULT_APP_WINDOW_HEIGHT = 800;

//--------------------------------------------------

App::App (void):
        widgets_ (LayoutBox (Length (DEFAULT_APP_WINDOW_WIDTH,  Unit::Pixel),
                             Length (DEFAULT_APP_WINDOW_HEIGHT, Unit::Pixel))),
        transform_stack_ (),

        window_ (DEFAULT_APP_WINDOW_WIDTH, DEFAULT_APP_WINDOW_HEIGHT, SDL_WINDOW_FULLSCREEN_DESKTOP),
        target_ (window_),
        sdl_exit_ (false)
{
    plug::Vec2d window_size = window_.get_size ();

    //--------------------------------------------------

    plug::Transform to_screen_center (window_size / 2);
    transform_stack_.enter (to_screen_center);

    //--------------------------------------------------

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

    //--------------------------------------------------

    while (SDL_PollEvent (&event)) {
    switch (event.type) {

        case SDL_QUIT: sdl_exit_ = true; break;

        case SDL_MOUSEMOTION:
        case SDL_MOUSEBUTTONDOWN:
        case SDL_MOUSEBUTTONUP: on_mouse_event (event); break;

        case SDL_KEYDOWN: on_keyboard_event (event); break;
        case SDL_KEYUP:   on_keyboard_event (event); break;

        //--------------------------------------------------

        default: break;
    }}

    //--------------------------------------------------

    //widgets_. (clock ());
}

void App::render (void) {

    window_.clear_screen ();

    //--------------------------------------------------

    widgets_.render (target_, transform_stack_);

    //--------------------------------------------------

    window_.update_screen ();
}

//--------------------------------------------------

void App::populate (void) {

    LayoutBox box (1400_px, 1000_px);
    //box.setPosition ()

    //--------------------------------------------------

    My_Widget& photoshop = *new Photoshop (box);

    //--------------------------------------------------

    widgets_.register_widget (&photoshop);
}

//--------------------------------------------------


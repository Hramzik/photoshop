

//--------------------------------------------------

#include "Impl/LayoutBox/LayoutBox.h"

#include "tools/hpp/tools.hpp"

#include "../hpp/app.hpp"

//--------------------------------------------------

const double App::DEFAULT_APP_WINDOW_WIDTH  = 800;
const double App::DEFAULT_APP_WINDOW_HEIGHT = 800;

//--------------------------------------------------

App::App (void):
        widgets_ (LayoutBox (Length (DEFAULT_APP_WINDOW_WIDTH,  Unit::Pixel),
                             Length (DEFAULT_APP_WINDOW_HEIGHT, Unit::Pixel))),
        transform_stack_ (),

        window_ (DEFAULT_APP_WINDOW_WIDTH, DEFAULT_APP_WINDOW_HEIGHT),
        target_ (window_),
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

    //--------------------------------------------------

    while (SDL_PollEvent (&event)) {
    switch (event.type) {

        case SDL_QUIT: sdl_exit_ = true; break;

        case SDL_MOUSEMOTION:
        case SDL_MOUSEBUTTONDOWN:
        case SDL_MOUSEBUTTONUP: on_mouse_event (event); break;

        //case SDL_KEYDOWN: widgets_.on_keyboard_pressed  (event.key.keysym.sym); break;
        //case SDL_KEYUP:   widgets_.on_keyboard_released (event.key.keysym.sym); break;

        //--------------------------------------------------

        default: break;
    }}

    //--------------------------------------------------

    //widgets_. (clock ());
}


void App::on_mouse_event (SDL_Event sdl_event) {

    //--------------------------------------------------
    // getting mouse position

    plug::Event* plug_event = nullptr;
    plug::Vec2d position;

    switch (sdl_event.type) {

        case SDL_MOUSEMOTION:
            position  = plug::Vec2d (sdl_event.motion.x, sdl_event.motion.y);
            plug_event = new plug::MouseMoveEvent (position, false, false, false);
            break;

        //--------------------------------------------------

        case SDL_MOUSEBUTTONDOWN:
            position  = plug::Vec2d (sdl_event.button.x, sdl_event.button.y);
            plug_event = new plug::MousePressedEvent (plug::MouseButton::Left, position, false, false, false);
            break;

        //--------------------------------------------------

        case SDL_MOUSEBUTTONUP: 
            position  = plug::Vec2d (sdl_event.button.x, sdl_event.button.y);
            plug_event = new plug::MouseReleasedEvent (plug::MouseButton::Left, position, false, false, false);
            break;

        //--------------------------------------------------

        default: LOG_ERROR (BAD_ARGS); return;
    }

    //--------------------------------------------------
    // handling event

    plug::EHC context = { transform_stack_, false, false };
    widgets_.onEvent (*plug_event, context);
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

    /*Colored_Window*       window = new Colored_Window ({0}, {200}, C_DARK_GRAY);
    Framed_Window* framed_window = new Framed_Window (*window);

    widgets_.register_widget (framed_window);*/

    //--------------------------------------------------

    // Point2D  position (200, 40);
    // Vector2D size     (1400, 1000);

    LayoutBox box (Length (500, Unit::Pixel),
                   Length (500, Unit::Pixel));

    box.setPosition (plug::Vec2d (260, 260));

    //--------------------------------------------------

    Canvas&        canvas = *new Canvas (100, 100);
    Canvas_Viewer& viewer = *new Canvas_Viewer (box, canvas);

    Color_Palette& colors = *new Color_Palette ();
    Tool_Palette&  tools  = *new Tool_Palette ();

    Tool& brush = *new Brush_Tool ();
    brush.setActiveCanvas (canvas);
    brush.setColorPalette (colors);
    tools.add_tool (brush);

    //--------------------------------------------------

    viewer.set_tool_palette (tools);

    viewer.choose_tool    (0);
    viewer.set_is_focused (true);

    //--------------------------------------------------

    widgets_.register_widget (&viewer);
}

//--------------------------------------------------


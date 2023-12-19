
//--------------------------------------------------

#include "app/hpp/app.hpp"

//--------------------------------------------------

static plug::KeyCode get_plug_keycode (SDL_Keycode sdl_key);

//--------------------------------------------------

void App::on_mouse_event (SDL_Event sdl_event) {

    //--------------------------------------------------
    // getting mouse position

    plug::Event* plug_event = nullptr;
    plug::Vec2d position;

    switch (sdl_event.type) {

    case SDL_MOUSEMOTION:
        position  = plug::Vec2d (sdl_event.motion.x, sdl_event.motion.y);
        plug_event = new plug::MouseMoveEvent (position, shift_pressed_, ctrl_pressed_, alt_pressed_);
        break;

    //--------------------------------------------------

    case SDL_MOUSEBUTTONDOWN:
        position  = plug::Vec2d (sdl_event.button.x, sdl_event.button.y);
        plug_event = new plug::MousePressedEvent (plug::MouseButton::Left, position, shift_pressed_, ctrl_pressed_, alt_pressed_);
        break;

    //--------------------------------------------------

    case SDL_MOUSEBUTTONUP: 
        position  = plug::Vec2d (sdl_event.button.x, sdl_event.button.y);
        plug_event = new plug::MouseReleasedEvent (plug::MouseButton::Left, position, shift_pressed_, ctrl_pressed_, alt_pressed_);
        break;

    //--------------------------------------------------

    default: LOG_ERROR (BAD_ARGS); return;
    }

    //--------------------------------------------------
    // handling event

    plug::EHC context = { transform_stack_, false, false };
    widgets_.onEvent (*plug_event, context);

    delete plug_event;
}

void App::on_keyboard_event (SDL_Event sdl_event) {

    if (sdl_event.type != SDL_KEYDOWN && sdl_event.type != SDL_KEYUP) { LOG_ERROR (BAD_ARGS); return; }

    //--------------------------------------------------
    // modifiers

    bool modifier_state = (sdl_event.type == SDL_KEYDOWN);

    if (sdl_event.key.keysym.sym == SDLK_LSHIFT) shift_pressed_ = modifier_state;
    if (sdl_event.key.keysym.sym == SDLK_LCTRL)  ctrl_pressed_  = modifier_state;
    if (sdl_event.key.keysym.sym == SDLK_LALT)   alt_pressed_   = modifier_state;

    //--------------------------------------------------
    // keyboard events

    plug::KeyCode keycode = get_plug_keycode (sdl_event.key.keysym.sym);
    plug::EHC     context = { transform_stack_, false, false };

    if (sdl_event.type == SDL_KEYDOWN) {

        plug::KeyboardPressedEvent event (keycode, shift_pressed_, ctrl_pressed_, alt_pressed_);
        return widgets_.onEvent (event, context);
    }

    plug::KeyboardReleasedEvent event (keycode, shift_pressed_, ctrl_pressed_, alt_pressed_);
    return widgets_.onEvent (event, context);
}

//--------------------------------------------------

static plug::KeyCode get_plug_keycode (SDL_Keycode sdl_key) {

    switch (sdl_key) {

    case SDLK_ESCAPE:    return plug::KeyCode::Escape;
    case SDLK_BACKSPACE: return plug::KeyCode::Backspace;
    case SDLK_TAB:       return plug::KeyCode::Tab;
    case SDLK_SPACE:     return plug::KeyCode::Space;

    case SDLK_LSHIFT: return plug::KeyCode::LShift;
    case SDLK_LCTRL:  return plug::KeyCode::LControl;
    case SDLK_LALT:   return plug::KeyCode::LAlt;

    case SDLK_PLUS:   return plug::KeyCode::Add;
    case SDLK_MINUS:  return plug::KeyCode::Subtract;
    case SDLK_EQUALS: return plug::KeyCode::Equal;
    case SDLK_COMMA:  return plug::KeyCode::Comma;
    case SDLK_PERIOD: return plug::KeyCode::Period;
    case SDLK_0: return plug::KeyCode::Num0;
    case SDLK_1: return plug::KeyCode::Num1;
    case SDLK_2: return plug::KeyCode::Num2;
    case SDLK_3: return plug::KeyCode::Num3;
    case SDLK_4: return plug::KeyCode::Num4;
    case SDLK_5: return plug::KeyCode::Num5;
    case SDLK_6: return plug::KeyCode::Num6;
    case SDLK_7: return plug::KeyCode::Num7;
    case SDLK_8: return plug::KeyCode::Num8;
    case SDLK_9: return plug::KeyCode::Num9;

    case SDLK_a: return plug::KeyCode::A;
    case SDLK_b: return plug::KeyCode::B;
    case SDLK_c: return plug::KeyCode::C;
    case SDLK_d: return plug::KeyCode::D;
    case SDLK_e: return plug::KeyCode::E;
    case SDLK_f: return plug::KeyCode::F;
    case SDLK_g: return plug::KeyCode::G;
    case SDLK_h: return plug::KeyCode::H;
    case SDLK_i: return plug::KeyCode::I;
    case SDLK_j: return plug::KeyCode::J;
    case SDLK_k: return plug::KeyCode::K;
    case SDLK_l: return plug::KeyCode::L;
    case SDLK_m: return plug::KeyCode::M;
    case SDLK_n: return plug::KeyCode::N;
    case SDLK_o: return plug::KeyCode::O;
    case SDLK_p: return plug::KeyCode::P;
    case SDLK_q: return plug::KeyCode::Q;
    case SDLK_r: return plug::KeyCode::R;
    case SDLK_s: return plug::KeyCode::S;
    case SDLK_t: return plug::KeyCode::T;
    case SDLK_u: return plug::KeyCode::U;
    case SDLK_v: return plug::KeyCode::V;
    case SDLK_w: return plug::KeyCode::W;
    case SDLK_x: return plug::KeyCode::X;
    case SDLK_y: return plug::KeyCode::Y;
    case SDLK_z: return plug::KeyCode::Z;

    case SDLK_F1:  return plug::KeyCode::F1;
    case SDLK_F2:  return plug::KeyCode::F2;
    case SDLK_F3:  return plug::KeyCode::F3;
    case SDLK_F4:  return plug::KeyCode::F4;
    case SDLK_F5:  return plug::KeyCode::F5;
    case SDLK_F6:  return plug::KeyCode::F6;
    case SDLK_F7:  return plug::KeyCode::F7;
    case SDLK_F8:  return plug::KeyCode::F8;
    case SDLK_F9:  return plug::KeyCode::F9;
    case SDLK_F10: return plug::KeyCode::F10;
    case SDLK_F11: return plug::KeyCode::F11;
    case SDLK_F12: return plug::KeyCode::F12;

    case SDLK_RIGHT: return plug::KeyCode::Right;
    case SDLK_LEFT:  return plug::KeyCode::Left;
    case SDLK_DOWN:  return plug::KeyCode::Down;
    case SDLK_UP:    return plug::KeyCode::Up;

    case SDLK_KP_1: return plug::KeyCode::Numpad1;
    case SDLK_KP_2: return plug::KeyCode::Numpad2;
    case SDLK_KP_3: return plug::KeyCode::Numpad3;
    case SDLK_KP_4: return plug::KeyCode::Numpad4;
    case SDLK_KP_5: return plug::KeyCode::Numpad5;
    case SDLK_KP_6: return plug::KeyCode::Numpad6;
    case SDLK_KP_7: return plug::KeyCode::Numpad7;
    case SDLK_KP_8: return plug::KeyCode::Numpad8;
    case SDLK_KP_9: return plug::KeyCode::Numpad9;
    case SDLK_KP_0: return plug::KeyCode::Numpad0;

    default: return plug::KeyCode::Unknown;
    }
}

//--------------------------------------------------


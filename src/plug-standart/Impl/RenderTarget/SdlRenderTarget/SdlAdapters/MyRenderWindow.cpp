

//--------------------------------------------------

#include "MyRenderWindow.h"

//--------------------------------------------------

const Uint32 MyRenderWindow::DEFAULT_SDL_WINDOW_FLAGS =
        SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE | SDL_WINDOW_BORDERLESS;

//--------------------------------------------------

MyRenderWindow::MyRenderWindow (int width, int height):
        MyRenderTarget (),

        m_window (nullptr)
{
    m_window = SDL_CreateWindow ("", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
            width, height, DEFAULT_SDL_WINDOW_FLAGS);

    //--------------------------------------------------

    setRenderer (SDL_CreateRenderer (m_window, -1, SDL_RENDERER_ACCELERATED));
}

//--------------------------------------------------

void MyRenderWindow::clear_screen (void) {

    SDL_RenderClear (accessRenderer ());
}

void MyRenderWindow::update_screen (void) {

    SDL_RenderPresent (accessRenderer ());
}

//--------------------------------------------------

plug::Vec2d MyRenderWindow::get_size (void) const {

    int window_width  = 0;
    int window_height = 0;

    SDL_GetWindowSize (m_window, &window_width, &window_height);

    //--------------------------------------------------

    return plug::Vec2d (window_width, window_height);
}

//--------------------------------------------------

void MyRenderWindow::go_fullscreen (void) {

    SDL_SetWindowFullscreen (m_window, SDL_WINDOW_FULLSCREEN_DESKTOP);
}

void MyRenderWindow::exit_fullscreen (void) {

    SDL_SetWindowFullscreen (m_window, 0);
}

//--------------------------------------------------


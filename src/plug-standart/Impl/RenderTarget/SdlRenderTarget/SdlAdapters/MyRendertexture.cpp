

//--------------------------------------------------

#include <iostream>

#include "lib/SDL2/include/SDL2/SDL_image.h"
#include "lib/SDL2/include/SDL2/SDL_ttf.h"

#include "SdlAdapters.h"

//--------------------------------------------------

MyRenderTexture::MyRenderTexture (void):
        MyRenderTarget (),

        m_surface (nullptr) {}

MyRenderTexture::MyRenderTexture (int width, int height):
        MyRenderTarget (),

        m_surface (nullptr)
{
    SDL_Surface* surface = SDL_CreateRGBSurface (0, width, height, 32,0,0,0,0);
    setSdlSurface (surface);
}

MyRenderTexture::~MyRenderTexture (void) {

    SDL_FreeSurface (m_surface);
}

//--------------------------------------------------

void MyRenderTexture::loadFromFile (const char* path) {

    SDL_Surface* img_surface = IMG_Load (path);
    if (!img_surface) return;

    //--------------------------------------------------

    SDL_Surface* white_surface = SDL_CreateRGBSurface (0, img_surface->w, img_surface->h, 32,0,0,0,0);
    SDL_FillRect (white_surface, nullptr, -1);

    //--------------------------------------------------

    SDL_Surface* result_surface = white_surface;
    SDL_BlitScaled (img_surface, nullptr, result_surface, nullptr);

    //--------------------------------------------------
    // full texture size

    if (!m_surface) {

        setSdlSurface (result_surface);
        return;
    }

    //--------------------------------------------------
    // scale to original size

    SDL_BlitScaled (result_surface, nullptr, m_surface, nullptr);
}

void MyRenderTexture::saveToFile (const char* path) {

    SDL_SaveBMP (m_surface, path);
}

//--------------------------------------------------

void MyRenderTexture::loadText (const char* text, My_RGB text_color, My_RGB bg_color) {

    TTF_Font* font = TTF_OpenFont ("media/monospace.ttf", 50);
    SDL_Surface* text_surface = TTF_RenderText_Solid (font, text, {text_color.r, text_color.g, text_color.b, 255});

    //--------------------------------------------------

    SDL_Surface* background = SDL_CreateRGBSurface (0, text_surface->w, text_surface->h, 32,0,0,0,0);
    SDL_FillRect (background, nullptr, bg_color.g << 16 | bg_color.g  << 8 | bg_color.r << 0);

    //--------------------------------------------------

    SDL_Surface* result_surface = background;
    SDL_BlitScaled (text_surface, nullptr, result_surface, nullptr);

    //--------------------------------------------------
    // full texture size

    if (!m_surface) {

        setSdlSurface (result_surface);
        return;
    }

    //--------------------------------------------------
    // scale to original size

    SDL_BlitScaled (result_surface, nullptr, m_surface, nullptr);
}

//--------------------------------------------------

const SDL_Surface* MyRenderTexture::getSdlSurface (void) const {

    return m_surface;
}

void MyRenderTexture::setSdlSurface (SDL_Surface* surface) {

    //--------------------------------------------------
    // surface

    SDL_FreeSurface (m_surface);
    m_surface = surface;

    //--------------------------------------------------
    // renderer

    SDL_Renderer* renderer = SDL_CreateSoftwareRenderer (m_surface);
    setRenderer (renderer);
}

SDL_Surface* MyRenderTexture::accessSdlSurface (void) {

    return m_surface;
}

//--------------------------------------------------




//--------------------------------------------------

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

//--------------------------------------------------


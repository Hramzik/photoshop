

//--------------------------------------------------

#include "MyRenderTexture.h"

//--------------------------------------------------

MyRenderTexture::MyRenderTexture (int width, int height):
        MyRenderTarget (),

        m_surface (nullptr)
{
    m_surface              = SDL_CreateRGBSurface (0, width, height, 32,0,0,0,0);
    SDL_Renderer* renderer = SDL_CreateSoftwareRenderer (m_surface);
    setRenderer (renderer);
}

//--------------------------------------------------

const SDL_Surface* MyRenderTexture::getSdlSurface (void) const {

    return m_surface;
}

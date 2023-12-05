#ifndef __MY_RENDER_TEXTURE_H
#define __MY_RENDER_TEXTURE_H
//--------------------------------------------------

#include "MyRenderTarget.h"

//--------------------------------------------------

class MyRenderTexture: public MyRenderTarget {

  public:

    MyRenderTexture (void);
    MyRenderTexture (int width, int height);

    void loadFromFile (const char* path);

    const SDL_Surface* getSdlSurface (void) const;
    void               setSdlSurface (SDL_Surface* surface);
    SDL_Surface*       accessSdlSurface (void);

  private:

    SDL_Surface* m_surface;
};

#endif
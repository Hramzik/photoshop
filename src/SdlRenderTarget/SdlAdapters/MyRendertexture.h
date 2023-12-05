#ifndef __MY_RENDER_TEXTURE_H
#define __MY_RENDER_TEXTURE_H
//--------------------------------------------------

#include "MyRenderTarget.h"

//--------------------------------------------------

class MyRenderTexture: public MyRenderTarget {

  public:

    MyRenderTexture (int width, int height);

    const SDL_Surface* getSdlSurface (void) const;

  private:

    SDL_Surface* m_surface;
};

#endif
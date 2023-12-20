#ifndef __MY_RENDER_TEXTURE_H
#define __MY_RENDER_TEXTURE_H
//--------------------------------------------------

#include "my_rgb/hpp/my_rgb.hpp"

#include "MyRenderTarget.h"

//--------------------------------------------------

class MyRenderTexture: public MyRenderTarget {

  public:

    MyRenderTexture (void);
    MyRenderTexture (int width, int height);
    ~MyRenderTexture (void);

    void loadFromFile (const char* path);
    void loadText     (const char* text, My_RGB text_color, My_RGB bg_color);

    const SDL_Surface* getSdlSurface (void) const;
    void               setSdlSurface (SDL_Surface* surface);
    SDL_Surface*       accessSdlSurface (void);

  private:

    SDL_Surface* m_surface;
};

#endif
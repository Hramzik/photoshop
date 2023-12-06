#ifndef __MY_RENDER_TARGET_H
#define __MY_RENDER_TARGET_H
//--------------------------------------------------

#include "C:/Users/hramz_3vliuy6/Desktop/lib/SDL2/include/SDL2/SDL.h"

#include <SDL.h>

#include "MyVertexArray.h"

//--------------------------------------------------

class MyRenderTexture;

//--------------------------------------------------

class MyRenderTarget {

  public:

    void draw  (const MyVertexArray& array);
    void draw  (const MyVertexArray& array, const MyRenderTexture& texture);
    void clear (SDL_Color color);
    void setActive (bool active);

  protected:

    MyRenderTarget  (void);
    ~MyRenderTarget (void);

    void          setRenderer    (SDL_Renderer* renderer);
    SDL_Renderer* accessRenderer (void);

  private:

    SDL_Renderer* m_renderer;
};

#endif
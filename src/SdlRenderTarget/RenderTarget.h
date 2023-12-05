#ifndef __IMPL_SDL_RENDER_TARGET_H
#define __IMPL_SDL_RENDER_TARGET_H
//--------------------------------------------------

#include "Plug/Graphics.h"

#include "sdl_adapters/MyRenderTarget.h"

//--------------------------------------------------

class SdlRenderTarget: public plug::RenderTarget {

  public:

    SdlRenderTarget (MyRenderTarget &target);

    virtual void draw (const plug::VertexArray &array) override;
    virtual void draw (const plug::VertexArray &array, const plug::Texture &texture) override;

    virtual void clear (plug::Color color) override;
    virtual void setActive (bool active)   override;

  private:

    MyRenderTarget &m_target;
};

#endif
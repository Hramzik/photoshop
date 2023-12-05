#ifndef __IMPL_SDL_RENDER_TARGET_H
#define __IMPL_SDL_RENDER_TARGET_H
//--------------------------------------------------

#pragma GCC diagnostic push 
#pragma GCC diagnostic ignored "-Weffc++"

#include "Plug/Graphics/RenderTarget.h"

#pragma GCC diagnostic pop

//--------------------------------------------------

#include "SdlAdapters/MyRenderTarget.h"

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
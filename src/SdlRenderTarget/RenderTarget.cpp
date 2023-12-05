

//--------------------------------------------------

#include "SdlAdapters/SdlAdapters.h"

#include "RenderTarget.h"

//--------------------------------------------------

SdlRenderTarget::SdlRenderTarget (MyRenderTarget &target):
        plug::RenderTarget (),
        m_target (target) {}

//--------------------------------------------------

void SdlRenderTarget::draw (const plug::VertexArray& array) {

    MyVertexArray converted_array (array);

    //--------------------------------------------------

    m_target.draw (converted_array);
}

void SdlRenderTarget::draw (const plug::VertexArray& array, const plug::Texture& texture) {

    MyVertexArray   converted_array   (array);
    MyRenderTexture converted_texture;
    copyToMyTexture (converted_texture, texture);

    //--------------------------------------------------

    m_target.draw (converted_array, converted_texture);
}

void SdlRenderTarget::clear (plug::Color color) {

    SDL_Color converted_color = getSDL_Color (color);

    //--------------------------------------------------

    m_target.clear (converted_color);
}

void SdlRenderTarget::setActive (bool active) {

    (void) active;
}


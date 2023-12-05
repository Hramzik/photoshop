

//--------------------------------------------------

#include "RenderTarget.h"

//--------------------------------------------------


void SdlRenderTarget::draw (const plug::VertexArray &array) {

    // convert
    m_target.draw (array);
}

void SdlRenderTarget::draw (const plug::VertexArray &array, const plug::Texture &texture) {

    m_target.draw (array, &texture);
}

void SdlRenderTarget::clear (plug::Color color) {

    m_target.clear (color);
}

void SdlRenderTarget::setActive (bool active) {

    (void) active;
}


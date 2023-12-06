

//--------------------------------------------------

#include "SdlAdapters.h"

//--------------------------------------------------

MyRenderTarget::MyRenderTarget (void):
        m_renderer (nullptr) {}

MyRenderTarget::~MyRenderTarget (void) {

    SDL_DestroyRenderer (m_renderer);
}

//--------------------------------------------------

void MyRenderTarget::setRenderer (SDL_Renderer* renderer) {

    SDL_DestroyRenderer (m_renderer);

    //--------------------------------------------------

    m_renderer = renderer;
}

SDL_Renderer* MyRenderTarget::accessRenderer (void) {

    return m_renderer;
}

//--------------------------------------------------

void MyRenderTarget::draw (const MyVertexArray& array) {

    const SDL_Vertex* const_vertexes = array.getVertexes ();

    // vertexes are not modified, but sdl api needs non-const ptr
    SDL_Vertex* vertexes     = const_cast <SDL_Vertex*> (const_vertexes);
    int         vertex_count = array.getVertexCount ();

    //--------------------------------------------------

    SDL_RenderGeometry (m_renderer, nullptr, vertexes, vertex_count, NULL, 0);
}

void MyRenderTarget::draw (const MyVertexArray& array, const MyRenderTexture& texture) {

    const SDL_Vertex* const_vertexes = array.getVertexes ();

    // vertexes are not modified, but sdl api needs non-const ptr
    SDL_Vertex* vertexes     = const_cast <SDL_Vertex*> (const_vertexes);
    int         vertex_count = array.getVertexCount ();

    //--------------------------------------------------

    const SDL_Surface* const_sdl_surface = texture.getSdlSurface ();

    // sdl_surface is not modified, but sdl api needs non-const ptr
    SDL_Surface* sdl_surface = const_cast <SDL_Surface*>    (const_sdl_surface);
    SDL_Texture* sdl_texture = SDL_CreateTextureFromSurface (m_renderer, sdl_surface);

    //--------------------------------------------------

    SDL_RenderGeometry (m_renderer, sdl_texture, vertexes, vertex_count, NULL, 0);

    //--------------------------------------------------

    SDL_DestroyTexture (sdl_texture);
}

void MyRenderTarget::clear (SDL_Color color) {

    SDL_SetRenderDrawColor (m_renderer, color.r, color.g, color.b, color.a);
    SDL_RenderClear (m_renderer);
}

void MyRenderTarget::setActive(bool active) {

    (void) active;
}

//--------------------------------------------------


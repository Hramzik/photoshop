#ifndef __SDL_ADAPTERS_CONVERTERS_H
#define __SDL_ADAPTERS_CONVERTERS_H
//--------------------------------------------------

#include "C:/Users/hramz_3vliuy6/Desktop/lib/SDL2/include/SDL2/SDL.h"

#include <SDL.h>

#include "MyVertexArray.h"

//--------------------------------------------------

SDL_Color  getSDL_Color  (plug::Color plug_color);
SDL_FPoint getSDL_FPoint (plug::Vec2d plug_vector);

void copyToSDL_Vertex    (SDL_Vertex&    sdl_vertex, const plug::Vertex&      plug_vertex);
void copyToMyVertexArray (MyVertexArray& my_array,   const plug::VertexArray& plug_array);

//--------------------------------------------------
#endif
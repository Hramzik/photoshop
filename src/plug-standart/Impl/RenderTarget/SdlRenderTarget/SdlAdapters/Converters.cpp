

//--------------------------------------------------

#include "SdlAdapters.h"

//--------------------------------------------------
// Colors and vectors

SDL_Color getSDL_Color (plug::Color plug_color) {

    SDL_Color color;

    //--------------------------------------------------

    color.r = plug_color.r;
    color.g = plug_color.g;
    color.b = plug_color.b;
    color.a = plug_color.a;

    //--------------------------------------------------

    return color;
}

SDL_FPoint getSDL_FPoint (plug::Vec2d plug_vector) {

    SDL_FPoint point;

    //--------------------------------------------------

    point.x = (float) plug_vector.x;
    point.y = (float) plug_vector.y;

    //--------------------------------------------------

    return point;
}

//--------------------------------------------------
// Vertexes

void copyToSDL_Vertex (SDL_Vertex& sdl_vertex, const plug::Vertex& plug_vertex) {

    sdl_vertex.color     = getSDL_Color  (plug_vertex.color);
    sdl_vertex.position  = getSDL_FPoint (plug_vertex.position);
    sdl_vertex.tex_coord = getSDL_FPoint (plug_vertex.tex_coords);
}

void copyToMyVertexArray (MyVertexArray& my_array, const plug::VertexArray& plug_array) {

    int plug_array_size = (int) plug_array.getSize();

    //--------------------------------------------------
    // Triangles

    if (plug_array.getPrimitive () == plug::Triangles) {

        my_array.resize (plug_array_size);

        for (int i = 0; i < plug_array_size; ++i) {

            copyToSDL_Vertex (my_array [i], plug_array [i]);
        }

        return;
    }

    //--------------------------------------------------
    // Quads

    if (plug_array.getPrimitive () == plug::Quads) {

        // instead of one quad we have two triangles
        my_array.resize (plug_array_size * 6 / 4);

        for (int i = 0; i < plug_array_size; i += 4) {

            copyToSDL_Vertex (my_array [i],     plug_array [i]);
            copyToSDL_Vertex (my_array [i + 1], plug_array [i + 1]);
            copyToSDL_Vertex (my_array [i + 2], plug_array [i + 2]);

            copyToSDL_Vertex (my_array [i + 3], plug_array [i]);
            copyToSDL_Vertex (my_array [i + 4], plug_array [i + 2]);
            copyToSDL_Vertex (my_array [i + 5], plug_array [i + 3]);
        }

        return;
    }

    //--------------------------------------------------
    // Points

    if (plug_array.getPrimitive () == plug::Points) {

        my_array.resize (plug_array_size * 6);

        for (int i = 0; i < plug_array_size; ++i) {

            plug::Vec2d corner1 ((int) plug_array [i].position.x,     (int) plug_array [i].position.y);
            plug::Vec2d corner2 (corner1.x + 1, corner1.y);
            plug::Vec2d corner3 (corner1.x + 1, corner1.y + 1);
            plug::Vec2d corner4 (corner1.x,     corner1.y + 1);

            plug::Color color  = plug_array [i].color;

            plug::Vertex vertex1;
            vertex1.position = corner1;
            vertex1.color    = color;

            plug::Vertex vertex2;
            vertex2.position = corner2;
            vertex2.color    = color;

            plug::Vertex vertex3;
            vertex3.position = corner3;
            vertex3.color    = color;

            plug::Vertex vertex4;
            vertex4.position = corner4;
            vertex4.color    = color;

            copyToSDL_Vertex (my_array [i],     vertex1);
            copyToSDL_Vertex (my_array [i + 1], vertex2);
            copyToSDL_Vertex (my_array [i + 2], vertex3);
            copyToSDL_Vertex (my_array [i + 3], vertex3);
            copyToSDL_Vertex (my_array [i + 4], vertex4);
            copyToSDL_Vertex (my_array [i + 5], vertex1);
        }

        return;
    }
    //--------------------------------------------------
    // TODO: rest
}

//--------------------------------------------------
// Textures

void copyToMyTexture (MyRenderTexture& my_texture, const plug::Texture& plug_texture) {

    int width  = (int) plug_texture.width;
    int height = (int) plug_texture.height;

    //--------------------------------------------------

    SDL_Surface* plug_surface = SDL_CreateRGBSurfaceFrom (plug_texture.data, width, height,
            32, 4 * width, 0, 0, 0, 0);

    //--------------------------------------------------

    my_texture.setSdlSurface (plug_surface);
}

#include <iostream>

static Uint32 getpixel (const SDL_Surface* surface, int x, int y);
static Uint32 getpixel (const SDL_Surface* surface, int x, int y) {

    int bpp = surface->format->BytesPerPixel;
    /* Here p is the address to the pixel we want to retrieve */
    Uint8* p = (Uint8*) surface->pixels + y * surface->pitch + x * bpp;

    switch (bpp) {

        case 1: return *p;

        case 2: return *(Uint16*) p;

        case 3:
            if    (SDL_BYTEORDER == SDL_BIG_ENDIAN)  return p [2] << 24 | p [1] << 16 | p [0] << 8;
            else /*SDL_BYTEORDER == SDL_LIL_ENDIAN*/ return p [0] << 16 | p [1] << 8  | p [2];

        case 4: return p [3] << 24 | p [0] << 16 | p [1] << 8 | p [2];

        default: return 0;
    }
}

plug::Texture& getTexture (const MyRenderTexture& my_texture) {

    const SDL_Surface* surface = my_texture.getSdlSurface ();

    //--------------------------------------------------

    int width  = surface->w;
    int height = surface->h;

    plug::Texture& plug_texture = *new plug::Texture (width, height);

    //--------------------------------------------------

    for (int x = 0; x < width; ++x) {
    for (int y = 0; y < height; ++y) {

        Uint32 pixel = getpixel (surface, x, y);
        plug::Color color;
        SDL_GetRGBA (pixel, surface->format, &color.r, &color.g, &color.b, &color.a);

        plug_texture.setPixel (x, y, color);
    }
    }

    //--------------------------------------------------


    return plug_texture;
}

//--------------------------------------------------



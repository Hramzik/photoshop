

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

//--------------------------------------------------



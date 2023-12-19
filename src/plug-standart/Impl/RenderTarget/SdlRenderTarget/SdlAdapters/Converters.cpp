

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
    // TriangleStrip

    if (plug_array.getPrimitive () == plug::TriangleStrip) {

        my_array.resize (3 * (plug_array_size - 2));

        // i - new triangle index index
        for (int i = 0; i < plug_array_size - 2; ++i) {

            copyToSDL_Vertex (my_array [3 * i],     plug_array [i]);
            copyToSDL_Vertex (my_array [3 * i + 1], plug_array [i + 1]);
            copyToSDL_Vertex (my_array [3 * i + 2], plug_array [i + 2]);
        }

        return;
    }

    //--------------------------------------------------
    // TriangleFan

    if (plug_array.getPrimitive () == plug::TriangleFan) {

        my_array.resize (3 * (plug_array_size - 1) / 2);

        // i - triangle number
        for (int i = 0; i < (plug_array_size - 1) / 2; ++i) {

            copyToSDL_Vertex (my_array [3 * i],     plug_array [0]);
            copyToSDL_Vertex (my_array [3 * i + 1], plug_array [2 * i + 1]);
            copyToSDL_Vertex (my_array [3 * i + 2], plug_array [2 * i + 2]);
        }

        return;
    }

    //--------------------------------------------------
    // Quads

    if (plug_array.getPrimitive () == plug::Quads) {

        // instead of one quad we have two triangles
        my_array.resize (plug_array_size * 6 / 4);

        for (int i = 0; i < plug_array_size / 4; i += 1) {

            copyToSDL_Vertex (my_array [6 * i],     plug_array [4 * i]);
            copyToSDL_Vertex (my_array [6 * i + 1], plug_array [4 * i + 1]);
            copyToSDL_Vertex (my_array [6 * i + 2], plug_array [4 * i + 2]);

            copyToSDL_Vertex (my_array [6 * i + 3], plug_array [4 * i]);
            copyToSDL_Vertex (my_array [6 * i + 4], plug_array [4 * i + 2]);
            copyToSDL_Vertex (my_array [6 * i + 5], plug_array [4 * i + 3]);
        }

        return;
    }

    //--------------------------------------------------
    // Lines

    if (plug_array.getPrimitive () == plug::Lines) {

        // line is two quad with width = 1
        // (vertical and horizontal)
        int line_width = 1;
        my_array.resize (plug_array_size * 6);

        for (int i = 0; i < plug_array_size / 2; i += 1) {


            plug::Vec2d anker1   ((int) plug_array [2 * i].position.x,     (int) plug_array [2 * i].position.y);
            plug::Vec2d corner1a (anker1.x + line_width,                   anker1.y);
            plug::Vec2d corner1b (anker1.x,                                anker1.y + line_width);
            plug::Vec2d anker2   ((int) plug_array [2 * i + 1].position.x, (int) plug_array [2 * i + 1].position.y);
            plug::Vec2d corner2a (anker2.x + line_width,                   anker2.y);
            plug::Vec2d corner2b (anker2.x,                                anker2.y + line_width);

            plug::Color color1 = plug_array [i]    .color;
            plug::Color color2 = plug_array [i + 1].color;

            plug::Vertex vertex1;
            vertex1.position = anker1;
            vertex1.color    = color1;

            plug::Vertex vertex2;
            vertex2.position = corner1a;
            vertex2.color    = color1;

            plug::Vertex vertex3;
            vertex3.position = corner1b;
            vertex3.color    = color1;

            plug::Vertex vertex4;
            vertex4.position = anker2;
            vertex4.color    = color2;

            plug::Vertex vertex5;
            vertex5.position = corner2a;
            vertex5.color    = color2;

            plug::Vertex vertex6;
            vertex6.position = corner2b;
            vertex6.color    = color2;

            copyToSDL_Vertex (my_array [12*i],     vertex1);
            copyToSDL_Vertex (my_array [12*i + 1], vertex2);
            copyToSDL_Vertex (my_array [12*i + 2], vertex5);
            copyToSDL_Vertex (my_array [12*i + 3], vertex1);
            copyToSDL_Vertex (my_array [12*i + 4], vertex4);
            copyToSDL_Vertex (my_array [12*i + 5], vertex5);

            copyToSDL_Vertex (my_array [12*i + 6],  vertex1);
            copyToSDL_Vertex (my_array [12*i + 7],  vertex3);
            copyToSDL_Vertex (my_array [12*i + 8],  vertex6);
            copyToSDL_Vertex (my_array [12*i + 9],  vertex1);
            copyToSDL_Vertex (my_array [12*i + 10], vertex4);
            copyToSDL_Vertex (my_array [12*i + 11], vertex6);
        }

        return;
    }

    //--------------------------------------------------
    // LinStrip

    if (plug_array.getPrimitive () == plug::LineStrip) {

        // line is two quad with width = 1
        // (vertical and horizontal)
        int line_width = 1;
        my_array.resize ((plug_array_size - 1) * 12);

        for (int i = 0; i < plug_array_size - 1; i += 1) {


            plug::Vec2d anker1   ((int) plug_array [i].position.x,     (int) plug_array [i].position.y);
            plug::Vec2d corner1a (anker1.x + line_width,               anker1.y);
            plug::Vec2d corner1b (anker1.x,                            anker1.y + line_width);
            plug::Vec2d anker2   ((int) plug_array [i + 1].position.x, (int) plug_array [i + 1].position.y);
            plug::Vec2d corner2a (anker2.x + line_width,               anker2.y);
            plug::Vec2d corner2b (anker2.x,                            anker2.y + line_width);

            plug::Color color1 = plug_array [i]    .color;
            plug::Color color2 = plug_array [i + 1].color;

            plug::Vertex vertex1;
            vertex1.position = anker1;
            vertex1.color    = color1;

            plug::Vertex vertex2;
            vertex2.position = corner1a;
            vertex2.color    = color1;

            plug::Vertex vertex3;
            vertex3.position = corner1b;
            vertex3.color    = color1;

            plug::Vertex vertex4;
            vertex4.position = anker2;
            vertex4.color    = color2;

            plug::Vertex vertex5;
            vertex5.position = corner2a;
            vertex5.color    = color2;

            plug::Vertex vertex6;
            vertex6.position = corner2b;
            vertex6.color    = color2;

            copyToSDL_Vertex (my_array [12*i],     vertex1);
            copyToSDL_Vertex (my_array [12*i + 1], vertex2);
            copyToSDL_Vertex (my_array [12*i + 2], vertex5);
            copyToSDL_Vertex (my_array [12*i + 3], vertex1);
            copyToSDL_Vertex (my_array [12*i + 4], vertex4);
            copyToSDL_Vertex (my_array [12*i + 5], vertex5);

            copyToSDL_Vertex (my_array [12*i + 6],  vertex1);
            copyToSDL_Vertex (my_array [12*i + 7],  vertex3);
            copyToSDL_Vertex (my_array [12*i + 8],  vertex6);
            copyToSDL_Vertex (my_array [12*i + 9],  vertex1);
            copyToSDL_Vertex (my_array [12*i + 10], vertex4);
            copyToSDL_Vertex (my_array [12*i + 11], vertex6);
        }

        return;
    }

    //--------------------------------------------------
    // Points

    if (plug_array.getPrimitive () == plug::Points) {

        my_array.resize (plug_array_size * 6);

        for (int i = 0; i < plug_array_size; ++i) {

            plug::Vec2d anker1 ((int) plug_array [i].position.x, (int) plug_array [i].position.y);
            plug::Vec2d corner2 (anker1.x + 1, anker1.y);
            plug::Vec2d corner3 (anker1.x + 1, anker1.y + 1);
            plug::Vec2d anker2 (anker1.x,     anker1.y + 1);

            plug::Color color  = plug_array [i].color;

            plug::Vertex vertex1;
            vertex1.position = anker1;
            vertex1.color    = color;

            plug::Vertex vertex2;
            vertex2.position = corner2;
            vertex2.color    = color;

            plug::Vertex vertex3;
            vertex3.position = corner3;
            vertex3.color    = color;

            plug::Vertex vertex4;
            vertex4.position = anker2;
            vertex4.color    = color;

            copyToSDL_Vertex (my_array [i],     vertex1);
            copyToSDL_Vertex (my_array [i + 1], vertex2);
            copyToSDL_Vertex (my_array [i + 2], vertex3);
            copyToSDL_Vertex (my_array [i + 3], vertex1);
            copyToSDL_Vertex (my_array [i + 4], vertex4);
            copyToSDL_Vertex (my_array [i + 5], vertex3);
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
            32, 4 * width, 0, 0, 0, 0xFF000000);

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
            if (SDL_BYTEORDER == SDL_LIL_ENDIAN) return p [0] << 16 | p [1] << 8 | p [2];
            else                                 //return p [0] | p [1] << 8 | p [2] << 16;
                                                 return p [2] << 16 | p [1] << 8 | p [0];
            //if    (SDL_BYTEORDER == SDL_BIG_ENDIAN)  return p [2] << 24 | p [1] << 16 | p [0] << 8;
            //else /*SDL_BYTEORDER == SDL_LIL_ENDIAN*/ return p [0] << 16 | p [1] << 8  | p [2];

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



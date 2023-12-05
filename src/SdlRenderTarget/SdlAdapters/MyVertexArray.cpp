

//--------------------------------------------------

#include <cassert>

#include "MyVertexArray.h"

//--------------------------------------------------

static SDL_Color  getSDL_Color  (plug::Color plug_color);
static SDL_FPoint getSDL_FPoint (plug::Vec2d plug_vector);

static void copyToSDL_Vertex    (SDL_Vertex&    sdl_vertex,  const plug::Vertex&      plug_vertex);
static void copyToMyVertexArray (MyVertexArray& my_array,    const plug::VertexArray& plug_array);

//--------------------------------------------------

MyVertexArray::MyVertexArray (plug::VertexArray& array):
    m_vertexes (nullptr),
    m_size     (0),
    m_capacity (0)
{
    copyToMyVertexArray (*this, array);
}

MyVertexArray::~MyVertexArray (void) {

    delete[] m_vertexes;
}

//--------------------------------------------------

const SDL_Vertex* MyVertexArray::getVertexes (void) const {

    return m_vertexes;
}

int MyVertexArray::getVertexCount (void) const {

    return m_size;
}

void MyVertexArray::resize (int new_size) {

    if (new_size <= m_capacity) {
    
        m_size = new_size;
        return;
    }

    //--------------------------------------------------

    reserve (new_size);
    m_size = new_size;
}

void MyVertexArray::reserve (int new_capacity) {

    assert (new_capacity > m_capacity);

    //--------------------------------------------------

    SDL_Vertex* new_vertexes = new SDL_Vertex [new_capacity];

    for (int i = 0; i < m_size; ++i) {

        new_vertexes [i] = m_vertexes [i];
    }

    delete[] m_vertexes;

    //--------------------------------------------------

    m_vertexes = new_vertexes;
    m_capacity = new_capacity;
}

SDL_Vertex& MyVertexArray::operator[] (int index) {

    return m_vertexes [index];
}

const SDL_Vertex& MyVertexArray::operator[] (int index) const {

    return m_vertexes [index];
}

//--------------------------------------------------

static void copyToSDL_Vertex (SDL_Vertex& sdl_vertex, const plug::Vertex& plug_vertex) {

    sdl_vertex.color     = getSDL_Color  (plug_vertex.color);
    sdl_vertex.position  = getSDL_FPoint (plug_vertex.position);
    sdl_vertex.tex_coord = getSDL_FPoint (plug_vertex.tex_coords);
}

static void copyToMyVertexArray (MyVertexArray& my_array, const plug::VertexArray& plug_array) {

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

static SDL_Color getSDL_Color (plug::Color plug_color) {

    SDL_Color color;

    //--------------------------------------------------

    color.r = plug_color.r;
    color.g = plug_color.g;
    color.b = plug_color.b;
    color.a = plug_color.a;

    //--------------------------------------------------

    return color;
}

static SDL_FPoint getSDL_FPoint (plug::Vec2d plug_vector) {

    SDL_FPoint point;

    //--------------------------------------------------

    point.x = (float) plug_vector.x;
    point.y = (float) plug_vector.y;

    //--------------------------------------------------

    return point;
}

//--------------------------------------------------


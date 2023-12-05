

//--------------------------------------------------

#include <cassert>

#include "SdlAdapters.h"

//--------------------------------------------------

MyVertexArray::MyVertexArray (int size):
    m_vertexes (nullptr),
    m_size     (0),
    m_capacity (0)
{
    resize (size);
}

MyVertexArray::MyVertexArray (const plug::VertexArray& array):
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


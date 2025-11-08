#ifndef __MY_VERTEX_ARRAY_H
#define __MY_VERTEX_ARRAY_H
//--------------------------------------------------

#include "lib/SDL2/include/SDL2/SDL.h"

//--------------------------------------------------

#pragma GCC diagnostic push 
#pragma GCC diagnostic ignored "-Weffc++"

#include "Plug/Graphics/VertexArray.h"

#pragma GCC diagnostic pop

//--------------------------------------------------

class MyVertexArray {

  public:

    MyVertexArray (int size);
    MyVertexArray (const plug::VertexArray& array);
    ~MyVertexArray (void);

    MyVertexArray            (const MyVertexArray& other) = delete;
    MyVertexArray& operator= (const MyVertexArray& other) = delete;

    //--------------------------------------------------

    const SDL_Vertex* getVertexes    (void) const;
    int               getVertexCount (void) const;

    void resize (int new_size);
    //void appendVertex(const Vertex &vertex);

    SDL_Vertex&       operator[] (int index);
    const SDL_Vertex& operator[] (int index) const;

  private:

    SDL_Vertex* m_vertexes;
    int m_size;
    int m_capacity;

    //--------------------------------------------------

    void reserve (int new_capacity);
};

#endif
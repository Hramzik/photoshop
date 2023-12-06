#ifndef __MY_RENDER_WINDOW_H
#define __MY_RENDER_WINDOW_H
//--------------------------------------------------

#include "MyRenderTarget.h"

//--------------------------------------------------

class MyRenderWindow: public MyRenderTarget {

  public:

    static const Uint32 DEFAULT_SDL_WINDOW_FLAGS;

    //--------------------------------------------------

    MyRenderWindow (int width, int height);

    void clear_screen  (void);
    void update_screen (void);

  private:

    SDL_Window* m_window;
};

#endif
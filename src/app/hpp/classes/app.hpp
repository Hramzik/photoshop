#ifndef APP_CLASS_APP_HPP_INCLUDED
#define APP_CLASS_APP_HPP_INCLUDED
//--------------------------------------------------

#include "Impl/RenderTarget/SdlRenderTarget/SdlAdapters/SdlAdapters.h"
#include "Impl/RenderTarget/SdlRenderTarget/RenderTarget.h"
#include "Impl/TransformStack.h"

#include "widgets/hpp/widgets.hpp"

//--------------------------------------------------


class App {

  public:

    static const double DEFAULT_APP_WINDOW_WIDTH;
    static const double DEFAULT_APP_WINDOW_HEIGHT;

    App (void);

    void run (void);
    void open_clock (void);

//--------------------------------------------------

  private:

    Widget_Container widgets_;
    TransformStack   transform_stack_;

    MyRenderWindow  window_;
    SdlRenderTarget target_;

    bool sdl_exit_;

    //--------------------------------------------------

    void populate (void);

    void update   (void);
    bool is_alive (void);
    bool exist_opened_widgets (void);
    void on_mouse_event (SDL_Event event);

    void render (void);
};





//--------------------------------------------------
#endif
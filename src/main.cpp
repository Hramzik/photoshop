
//--------------------------------------------------

#include <iostream>

#include "graphics/hpp/graphics.hpp"

#include "Impl/RenderTarget/SdlRenderTarget/SdlAdapters/SdlAdapters.h"
#include "Impl/RenderTarget/SdlRenderTarget/SdlAdapters/MyRenderWindow.h"
#include "Impl/RenderTarget/SdlRenderTarget/SdlAdapters/MyRenderTexture.h"
#include "Impl/RenderTarget/SdlRenderTarget/RenderTarget.h"

#include "Impl/LayoutBox/LayoutBox.h"
#include "Impl/LayoutBox/Units.h"
#include "Impl/TransformStack.h"

#include "widgets/hpp/widgets.hpp"

//#include "app/hpp/app.hpp"

//--------------------------------------------------


int main (int argc, char** argv) { (void) argc; (void) argv;

    init_sdl ();

    MyRenderWindow true_window (500, 500);
    SdlRenderTarget target (true_window);

    LayoutBox box (200_px, 200_px);

    MyRenderTexture true_texture; true_texture.loadFromFile ("media/cat.jpeg");
    plug::Texture texture = getTexture (true_texture);
    Textured_Window widget (box, texture);

    Framed_Window window (widget);

    TransformStack stack;
    window.render (target, stack);


    true_window.show ();
    while (true);
    //App app;

//--------------------------------------------------

    //app.run ();

//--------------------------------------------------

    quit_sdl ();

    std::cout << "goodbye!\n";


    return 0;
}


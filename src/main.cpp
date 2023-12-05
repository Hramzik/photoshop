
//--------------------------------------------------

#include <iostream>

#include "app/hpp/app.hpp"

#include "SdlRenderTarget/RenderTarget.h"
#include "SdlRenderTarget/SdlAdapters/SdlAdapters.h"

//--------------------------------------------------


int main (int argc, char** argv) { (void) argc; (void) argv;

    init_sdl ();

    MyRenderWindow secret_window (500, 500);
    SdlRenderTarget window (secret_window);

    plug::Texture texture (200, 200);

    for (int i = 0; i < 200; ++i) {
    for (int j = 0; j < 200; ++j) {

        texture.setPixel (i, j, {0, 0, 0, 255});
    }
    }

    window.clear ({0, 100, 0, 255});

    plug::VertexArray shape (plug::Quads, 4);

    shape [0] =
	{
		plug::Vec2d { 25.f, 20.f },
		plug::Vec2d { 0.f, 0.f },
		{ 255, 251, 124, 0xFF }
	};
    shape [1] =
	{
		plug::Vec2d { 0.f, 80.f },
		plug::Vec2d { 0.f, 1.f },
		{ 255, 0, 0, 0xFF }
	};
    shape [2] =
	{
		plug::Vec2d { 50.f, 80.f },
		plug::Vec2d { 1.f, 0.f },
		{ 0, 251, 0, 0xFF }
	};
    shape [3] =
	{
		plug::Vec2d { 50.f, 20.f },
		plug::Vec2d { 1.f, 1.f },
		{ 0, 251, 0, 0xFF }
	};

    window.draw (shape, texture);
    //window.draw (texture);

    secret_window.show ();

    App app;

//--------------------------------------------------

    app.run ();

//--------------------------------------------------

    quit_sdl ();

    std::cout << "goodbye!\n";


    return 0;
}


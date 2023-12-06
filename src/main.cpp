
//--------------------------------------------------

#include <iostream>

#include "graphics/hpp/graphics.hpp"

#include "app/hpp/app.hpp"

//--------------------------------------------------


int main (int argc, char** argv) { (void) argc; (void) argv;

    init_sdl ();

    App app;

//--------------------------------------------------

    app.run ();

//--------------------------------------------------

    quit_sdl ();

    std::cout << "goodbye!\n";


    return 0;
}


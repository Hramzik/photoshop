
//--------------------------------------------------

#include <iostream>

#include "graphics/hpp/graphics.hpp"

#include "app/hpp/app.hpp"

//--------------------------------------------------

/*#include "windows.h"

typedef void* (CALLBACK* LPFNDLLFUNC1)(void);

HRESULT LoadAndCallSomeFunction(void);
HRESULT LoadAndCallSomeFunction(void)
{
    HINSTANCE hDLL;               // Handle to DLL
    LPFNDLLFUNC1 lpfnDllFunc1;    // Function pointer
    HRESULT hrReturnVal;

    hDLL = LoadLibrary("dll/pencil.dll");
    if (NULL != hDLL)
    {
        lpfnDllFunc1 = (LPFNDLLFUNC1)GetProcAddress(hDLL, "loadPlugin");
        if (NULL != lpfnDllFunc1)
        {
            // call the function
            std::cout <<  << "\n";lpfnDllFunc1();
        }
        else
        {
            // report the error
            hrReturnVal = ERROR_DELAY_LOAD_FAILED;
        }
        FreeLibrary(hDLL);
    }
    else
    {
        hrReturnVal = ERROR_DELAY_LOAD_FAILED;
    }
    return hrReturnVal;
}*/
int main (int argc, char** argv) { (void) argc; (void) argv;

    init_sdl ();

    //LoadAndCallSomeFunction ();
    App app;

//--------------------------------------------------

    app.run ();

//--------------------------------------------------

    quit_sdl ();

    std::cout << "goodbye!\n";


    return 0;
}


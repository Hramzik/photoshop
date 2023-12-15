#ifndef CLASS_PLUGIN_LOADER_HPP_INCLUDED
#define CLASS_PLUGIN_LOADER_HPP_INCLUDED
//--------------------------------------------------

#include <windows.h>

#include "photoshop/hpp/photoshop.hpp"

//--------------------------------------------------

class Plugin_Loader {

  public:

    Plugin_Loader (Photoshop& photoshop);

    //--------------------------------------------------

    void load_plugin (const char* path);

  private:

    Photoshop& photoshop_;
};

//--------------------------------------------------
#endif
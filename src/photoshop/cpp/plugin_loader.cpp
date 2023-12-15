
//--------------------------------------------------

#include "photoshop/hpp/photoshop.hpp"

//--------------------------------------------------

Plugin_Loader::Plugin_Loader (Photoshop& photoshop):
        photoshop_ (photoshop) {}

//--------------------------------------------------

typedef plug::Plugin* (__stdcall* Plug_Function) (void);
typedef int           (__stdcall* Test_Function) (int n);

//--------------------------------------------------

void Plugin_Loader::load_plugin (const char* path) {

    HINSTANCE dll_handle = LoadLibrary (path);
    if (!dll_handle) return;

    //--------------------------------------------------

    Plug_Function dll_function  = (Plug_Function) GetProcAddress (dll_handle, "loadPlugin");
    if (!dll_function) return;

    //--------------------------------------------------

    plug::Plugin* plugin = dll_function ();
    if (!plugin) return;

    //--------------------------------------------------

    size_t interface_id = static_cast <size_t> (plug::PluginGuid::Tool);
    plug::Tool* tool    = static_cast <plug::Tool*> (plugin->tryGetInterface (interface_id));
    //plug::Tool* tool = static_cast <plug::Tool*> (plugin);
    if (!tool) return;

    //--------------------------------------------------

    photoshop_.add_tool (*tool);
}

//--------------------------------------------------



//--------------------------------------------------

#include "photoshop/hpp/photoshop.hpp"

//--------------------------------------------------

Plugin_Loader::Plugin_Loader (Photoshop& photoshop):
        photoshop_ (photoshop) {}

//--------------------------------------------------

typedef plug::Plugin* (__stdcall* Plug_Function) (void);
typedef int           (__stdcall* Test_Function) (int n);

//--------------------------------------------------

void Plugin_Loader::load_plugins (void) {

    char            file_name [MAX_PATH];
    WIN32_FIND_DATA file_info;

    //--------------------------------------------------
    // find first file, get search describtor

    HANDLE search_describtor = FindFirstFile ("dll/*.dll", &file_info);
    if (search_describtor == INVALID_HANDLE_VALUE) return;

    //--------------------------------------------------
    // find next files

    while (true) {

        sprintf (file_name, "dll/%s", file_info.cFileName);
        load_plugin (file_name);

        //--------------------------------------------------

        if (!FindNextFile (search_describtor, &file_info)) break;
    };

    //--------------------------------------------------
    // close search describtor

    FindClose (search_describtor);
}

void Plugin_Loader::load_plugin (const char* path) {

    HINSTANCE dll_handle = LoadLibrary (path);
    if (!dll_handle) return;

    //--------------------------------------------------

    Plug_Function dll_function = (Plug_Function) (void*) GetProcAddress (dll_handle, "loadPlugin");
    if (!dll_function) return;

    //--------------------------------------------------

    plug::Plugin* plugin = dll_function ();
    if (!plugin) return;

    //--------------------------------------------------

    size_t interface_id = static_cast <size_t> (plug::PluginGuid::Tool);
    plug::Tool*    tool = static_cast <plug::Tool*> (plugin->tryGetInterface (interface_id));

    if (tool) photoshop_.add_tool (*tool);

    //--------------------------------------------------

    interface_id         = static_cast <size_t> (plug::PluginGuid::Filter);
    plug::Filter* filter = static_cast <plug::Filter*> (plugin->tryGetInterface (interface_id));

    if (filter) photoshop_.add_filter (*filter);
}

//--------------------------------------------------


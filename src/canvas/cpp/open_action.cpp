
//--------------------------------------------------

#include <windows.h>
#include <commdlg.h>

#include "photoshop/hpp/photoshop.hpp"

#include "canvas/hpp/canvas.hpp"

//--------------------------------------------------

Canvas_Open_Action::Canvas_Open_Action (Photoshop& photoshop):
        photoshop_ (photoshop) {}

//--------------------------------------------------

void Canvas_Open_Action::act (void) {

    const char* file_name = get_user_file_name ();
    if (!file_name) return;

    //--------------------------------------------------

    photoshop_.add_canvas (*new Canvas (500, 500, file_name));
}

//--------------------------------------------------

const char* Canvas_Open_Action::get_user_file_name (void) {

    OPENFILENAME ofn;
    char* file_name = new char [MAX_PATH];

    //--------------------------------------------------

    ZeroMemory (&ofn, sizeof (ofn));
    ofn.lStructSize = sizeof (ofn);
    ofn.hwndOwner = nullptr;
    ofn.lpstrFile = file_name;
    ofn.lpstrFile[0] = '\0';
    ofn.nMaxFile = MAX_PATH;

    ofn.lpstrFilter = "All\0*.*\0";
    ofn.nFilterIndex =1;

    ofn.lpstrFileTitle  = nullptr;
    ofn.nMaxFileTitle   = 0;
    ofn.lpstrInitialDir = "C:/Users/hramz_3vliuy6/Pictures/my_photoshop";

    ofn.Flags = OFN_PATHMUSTEXIST | OFN_FILEMUSTEXIST;

    //--------------------------------------------------

    if (!GetOpenFileName (&ofn)) return nullptr;

    //--------------------------------------------------

    return file_name;
}

//--------------------------------------------------


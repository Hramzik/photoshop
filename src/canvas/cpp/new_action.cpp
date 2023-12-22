
//--------------------------------------------------

#include "photoshop/hpp/photoshop.hpp"

#include "canvas/hpp/canvas.hpp"

//--------------------------------------------------

New_Canvas_Action::New_Canvas_Action (Photoshop& photoshop):
        photoshop_ (photoshop) {}

//--------------------------------------------------

void New_Canvas_Action::act (void) {

    photoshop_.add_canvas (*new Canvas (500, 500));
}

//--------------------------------------------------


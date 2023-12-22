#ifndef CANVAS_OPEN_ACRION_HPP_INCLUDED
#define CANVAS_OPEN_ACRION_HPP_INCLUDED
//--------------------------------------------------

#include "widgets/hpp/classes/actions/action.hpp"

//--------------------------------------------------

class Photoshop;

//--------------------------------------------------

class Canvas_Open_Action: public Action {

  public:

    Canvas_Open_Action (Photoshop& photoshop);

    //--------------------------------------------------

    void act (void) override;

  private:

    Photoshop& photoshop_;

    //--------------------------------------------------

    const char* get_user_file_name (void);
};

//--------------------------------------------------
#endif
#ifndef CLASS_SHOW_BUTTON_HPP_INCLUDED
#define CLASS_SHOW_BUTTON_HPP_INCLUDED
//--------------------------------------------------

#include "button.hpp"

//--------------------------------------------------

class Show_Button: public Button {

  public:

    Show_Button (Window& model, Widget& controlled);

    //--------------------------------------------------


//--------------------------------------------------

  private:

    Widget& controlled_;

    //--------------------------------------------------

    void do_when_pressed (void) override;
};


//--------------------------------------------------
#endif
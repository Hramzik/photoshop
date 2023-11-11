#ifndef CLASS_SHOW_BUTTON_HPP_INCLUDED
#define CLASS_SHOW_BUTTON_HPP_INCLUDED
//--------------------------------------------------

#include "button.hpp"

//--------------------------------------------------

class Show_Button: public Button {

  public:

    Show_Button (Window& model, Widget& controlled);

    //--------------------------------------------------

    void do_when_pressed   (void) override;
    void do_when_unhovered (void) override;

//--------------------------------------------------

  private:

    Widget& controlled_;
};


//--------------------------------------------------
#endif
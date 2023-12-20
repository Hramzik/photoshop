#ifndef WIDGETS_CLASS_WIDGET_MANAGER_HPP_INCLUDED
#define WIDGETS_CLASS_WIDGET_MANAGER_HPP_INCLUDED
//--------------------------------------------------

#include "container.hpp"

//--------------------------------------------------

class Widget_Manager: public Widget_Container {

  public:

    explicit Widget_Manager (const plug::LayoutBox& box);

    Widget_Manager (const Widget_Manager&) = delete;
    operator=      (const Widget_Manager&) = delete;

    //--------------------------------------------------

    void onEvent (const plug::Event& event, plug::EHC& context) override;

//--------------------------------------------------

  protected:

    void onMousePressed (const plug::MousePressedEvent& event, plug::EHC& context) override;
};

//--------------------------------------------------
// iterator declarations





//--------------------------------------------------
#endif
#ifndef CLASS_WIDGET_HIDER_HPP_INCLUDED
#define CLASS_WIDGET_HIDER_HPP_INCLUDED
//--------------------------------------------------

#include "widgets/hpp/classes/decorator.hpp"

//--------------------------------------------------

class Widget_Hider: public Widget_Decorator {

  public:

    Widget_Hider (My_Widget& widget);

    //--------------------------------------------------

    void show (void);
    void hide (void);
    void inverse_visibility (void);

    bool get_is_widget_hidden (void);

//--------------------------------------------------

    void render  (plug::RenderTarget& target, plug::TransformStack& stack) override;
    void onEvent (const plug::Event& event, plug::EHC& context)            override;

//--------------------------------------------------

  private:

    bool is_widget_hidden_ = false;
};


//--------------------------------------------------
#endif
#ifndef CLASS_WIDGET_ALIGNER_HPP_INCLUDED
#define CLASS_WIDGET_ALIGNER_HPP_INCLUDED
//--------------------------------------------------

#include "widgets/hpp/classes/container.hpp"

//--------------------------------------------------

// интерфейс для других aligner'ов
class Widget_Aligner: public Widget_Container {

  public:

    Widget_Aligner (My_Widget& background);

    //--------------------------------------------------

    // widget will be moved and resized
    void add_widget (My_Widget& widget);

//--------------------------------------------------

  protected:

    My_Widget& background_;

    virtual void resize_new_widget     (My_Widget& new_widget);
    virtual void   move_new_widget     (My_Widget& new_widget);
    virtual void post_adding_procedure (My_Widget& new_widget);
};

//--------------------------------------------------
#endif
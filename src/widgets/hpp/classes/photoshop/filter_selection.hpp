#ifndef WIDGETS_CLASS_FILTER_SELECTION_HPP_INCLUDED
#define WIDGETS_CLASS_FILTER_SELECTION_HPP_INCLUDED
//--------------------------------------------------

#include "../widget.hpp"
#include "../../../../filters/hpp/filters.hpp"

//--------------------------------------------------


// графическое представление палитры
// владеет своей палитрой
class Filter_Selection_Widget: public Widget {

  public:

    Filter_Selection_Widget (void);

    //--------------------------------------------------

    Filter_Palette& get_palette (void);

    void add_filter (Filter& filter);

    //--------------------------------------------------

    void render (Graphic_Window& window, Transform_Stack& stack) override;

//--------------------------------------------------

  private:

    Filter_Palette palette_;
};

//--------------------------------------------------
#endif
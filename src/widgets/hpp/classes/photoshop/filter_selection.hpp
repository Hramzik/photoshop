#ifndef WIDGETS_CLASS_FILTER_SELECTION_HPP_INCLUDED
#define WIDGETS_CLASS_FILTER_SELECTION_HPP_INCLUDED
//--------------------------------------------------

#include "../../../../filters/hpp/filters.hpp"

#include "../buttons/button_manager.hpp"

//--------------------------------------------------

class Canvas;

//--------------------------------------------------

// графическое представление палитры
// владеет своей палитрой
class Filter_Selection_Widget: public Button_Manager {

  public:

    Filter_Selection_Widget (Vector2D size, Canvas& canvas);

    //--------------------------------------------------

    Filter_Palette& access_palette (void);

    void add_filter (Filter& filter);

    //--------------------------------------------------

    Vector2D get_button_size (void) override;

//--------------------------------------------------

  private:

    Filter_Palette palette_;
    Canvas&        canvas_;
};

//--------------------------------------------------
#endif
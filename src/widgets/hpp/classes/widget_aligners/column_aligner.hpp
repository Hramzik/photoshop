#ifndef CLASS_COLUMN_ALIGNER_HPP_INCLUDED
#define CLASS_COLUMN_ALIGNER_HPP_INCLUDED
//--------------------------------------------------

#include "aligner.hpp"

//--------------------------------------------------

// распологает виджеты в столбец, растет вниз

class Column_Aligner: public Widget_Aligner {

  public:

    Column_Aligner (My_Widget& background);
    Column_Aligner (My_Widget& background, plug::Vec2d relative_padding_size);

  protected:

    void resize_new_widget     (My_Widget& new_widget) override;
    void   move_new_widget     (My_Widget& new_widget) override;
    void post_adding_procedure (My_Widget& new_widget) override;

  private:

    // relative to widget width
    const plug::Vec2d inner_padding_size_; // only y is used
    const plug::Vec2d tl_padding_size_;
    const plug::Vec2d br_padding_size_;

    double next_widget_vertical_offset_;

    //--------------------------------------------------

    double get_widget_width (void);
};

//--------------------------------------------------
#endif
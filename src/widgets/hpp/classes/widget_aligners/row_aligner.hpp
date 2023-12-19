#ifndef CLASS_ROW_ALIGNER_HPP_INCLUDED
#define CLASS_ROW_ALIGNER_HPP_INCLUDED
//--------------------------------------------------

#include "aligner.hpp"

//--------------------------------------------------

// распологает виджеты в строку, растет вправо

class Row_Aligner: public Widget_Aligner {

  public:

    Row_Aligner (My_Widget& background);
    Row_Aligner (My_Widget& background, plug::Vec2d relative_padding_size);

    //--------------------------------------------------

    void set_top_left_padding     (plug::Vec2d padding);
    void set_bottom_right_padding (plug::Vec2d padding);

  protected:

    void resize_new_widget     (My_Widget& new_widget) override;
    void   move_new_widget     (My_Widget& new_widget) override;
    void post_adding_procedure (My_Widget& new_widget) override;

  private:

    // relative to widget width
    plug::Vec2d inner_padding_size_; // only x is used
    plug::Vec2d tl_padding_size_;
    plug::Vec2d br_padding_size_;

    double next_widget_horizontal_offset_;

    //--------------------------------------------------

    double get_widget_height (void);
};

//--------------------------------------------------
#endif
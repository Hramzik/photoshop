#ifndef CLASS_SQUARE_ALIGNER_HPP_INCLUDED
#define CLASS_SQUARE_ALIGNER_HPP_INCLUDED
//--------------------------------------------------

#include "aligner.hpp"

//--------------------------------------------------

// распологает квадратые виджеты в строчки по k штук,
// растет вниз
class Square_Aligner: public Widget_Aligner {

  public:

    Square_Aligner (My_Widget& background, int widgets_in_line);
    Square_Aligner (My_Widget& background, int widgets_in_line, plug::Vec2d relative_padding_size);

  protected:

    void resize_new_widget (My_Widget& new_widget) override;
    void   move_new_widget (My_Widget& new_widget) override;
    void post_adding_procedure (void)              override;

  private:

    const int widgets_in_line_;

    //--------------------------------------------------

    int free_line_index;
    int widgets_in_free_line_count_;

    //--------------------------------------------------

    const plug::Vec2d inner_padding_size_; // from 0 to 1 in widget sizes
    const plug::Vec2d tl_padding_size_;
    const plug::Vec2d br_padding_size_;

    //--------------------------------------------------

    double get_widget_size (void);
};

//--------------------------------------------------
#endif
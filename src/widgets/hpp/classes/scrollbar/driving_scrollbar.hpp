#ifndef CLASS_MOVING_SCROLLBAR_HPP_INCLUDED
#define CLASS_MOVING_SCROLLBAR_HPP_INCLUDED
//--------------------------------------------------

#include "../windows/window.hpp"

#include "../container.hpp"

//--------------------------------------------------

class Driving_Scrollbar: public Window {

  public:

    // высота совпадает с высотой скролбара,
    // ширина умножается на этот параметр
    static constexpr double DEFAULT_BUTTON_RATIO = 1;
    static constexpr double DEFAULT_SLIDER_RATIO = 2;

    //--------------------------------------------------

    Driving_Scrollbar (Point2D position, Vector2D size, Widget& controlled);

    Driving_Scrollbar (const Driving_Scrollbar&) = delete;
    operator=         (const Driving_Scrollbar&) = delete;

    //--------------------------------------------------

    void set_button_ratio (double ration);
    void set_slider_ratio (double ration);

//--------------------------------------------------

  private:

    Widget& controlled_;

    double button_ratio_;
    double slider_ratio_;

    Widget_Container subwidgets_;
    Window*          left_button_;
    Window*          right_button_;
    Driving_Button*  slider_;
    Window* background_;

    //--------------------------------------------------

    void render_with_local_stack
    (Graphic_Window& window, Transform_Stack& local_stack)
    override;

    Processing_result on_mouse_moved    (Point2D mouse_position, Transform_Stack& stack) override;
    Processing_result on_mouse_pressed  (Point2D mouse_position, Transform_Stack& stack) override;
    Processing_result on_mouse_released (Point2D mouse_position, Transform_Stack& stack) override;
};


//--------------------------------------------------
#endif
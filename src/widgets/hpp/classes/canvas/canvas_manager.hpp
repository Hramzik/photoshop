#ifndef CLASS_CANVAS_MANAGER_HPP_INCLUDED
#define CLASS_CANVAS_MANAGER_HPP_INCLUDED
//--------------------------------------------------

#include "widgets/hpp/classes/my_widget.hpp"

//--------------------------------------------------

class Canvas_Manager: public My_Widget {

  public:

    Canvas_Manager (const plug::LayoutBox& box):
    ~Canvas_Manager ();

    Canvas_Manager (const Canvas_Manager&) = delete;
    operator=      (const Canvas_Manager&) = delete;

    //--------------------------------------------------

    virtual void draw(plug::TransformStack &stack, plug::RenderTarget &target);
    virtual void onEvent(const plug::Event &event, plug::EHC &context);

    //--------------------------------------------------

    void create_canvas (const char* iamge_path = nullptr);
    plug::Widget* get_active_canvas (void);

  protected:

    virtual void onTick             (const plug::TickEvent&             event, plug::EHC& context);
    virtual void onMouseMove        (const plug::MouseMoveEvent&        event, plug::EHC& context);
    virtual void onMousePressed     (const plug::MousePressedEvent&     event, plug::EHC& context);
    virtual void onMouseReleased    (const plug::MouseReleasedEvent&    event, plug::EHC& context);
    virtual void onKeyboardPressed  (const plug::KeyboardPressedEvent&  event, plug::EHC& context);
    virtual void onKeyboardReleased (const plug::KeyboardReleasedEvent& event, plug::EHC& context);
    
private:
    Container<Widget*> m_widgets;
    Container<plug::Canvas*> m_canvases;

    size_t m_cnt_canvas;
    bool m_delete_canvas;

    ContainerWidget *m_dialog_window;
}; 

//--------------------------------------------------
#endif
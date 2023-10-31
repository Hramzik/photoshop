#ifndef WIDGETS_CLASS_CONTAINER_HPP_INCLUDED
#define WIDGETS_CLASS_CONTAINER_HPP_INCLUDED
//--------------------------------------------------

#include <vector>
#include <list>

//--------------------------------------------------

#include "widget.hpp"

//--------------------------------------------------

typedef std::list <Widget*> Widget_List;

//--------------------------------------------------


class Widget_Container: public Widget {

  public:

class Iterator {

  public:

    Iterator (Widget_Container& container);

    //--------------------------------------------------

    void add_next_priority_list (Widget_List* list);
    void set_to_end (void);
    Widget_Container::Iterator& operator++ (void);
    Widget_Container::Iterator& operator-- (void);
    bool                        operator!= (const Iterator& other) const;

//--------------------------------------------------

  private:

    std::vector <Widget_List*> widget_lists_;
    int                        current_list_index_;

    Widget_List::iterator iterator_;

    //--------------------------------------------------

    Widget_List* get_current_list (void);
};

    friend class Iterator;

    //--------------------------------------------------

    Widget_Container (Transform transform);
    Widget_Container (Point2D position);

    Widget_Container (const Widget_Container&) = delete;
    operator=        (const Widget_Container&) = delete;

    //--------------------------------------------------

    int get_widgets_count (void);
    void register_widget            (Widget* widget);
    void register_priority_widget   (Widget* widget);
    void register_background_widget (Widget* widget);

    void render_with_local_stack
            (Graphic_Window& window, Transform_Stack& stack) override;

    Processing_result
    on_mouse_moved (Point2D mouse_position, Transform_Stack& stack) override;

    Processing_result
    on_mouse_pressed (Point2D mouse_position, Transform_Stack& stack) override;

    Processing_result
    on_mouse_released (Point2D mouse_position, Transform_Stack& stack) override;

    Processing_result
    on_keyboard_pressed (SDL_Keycode key) override;

    Processing_result
    on_keyboard_released (SDL_Keycode key) override;

    Processing_result
    on_timer (clock_t current_time) override;

//--------------------------------------------------

  protected:

    Widget_List widgets_;
    Widget_List priority_widgets_;
    Widget_List background_widgets_; // unimportant, indifferent

    Widget* active_widget_;

    //--------------------------------------------------

    Iterator begin  (void);
    Iterator end    (void);
    Iterator rbegin (void);
    Iterator rend   (void);
};

//--------------------------------------------------
// iterator declarations





//--------------------------------------------------
#endif
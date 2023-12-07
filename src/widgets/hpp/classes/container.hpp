#ifndef WIDGETS_CLASS_CONTAINER_HPP_INCLUDED
#define WIDGETS_CLASS_CONTAINER_HPP_INCLUDED
//--------------------------------------------------

#include <vector>
#include <list>

//--------------------------------------------------

#include "My_Widget.hpp"

//--------------------------------------------------

typedef std::list <My_Widget*> Widget_List;

//--------------------------------------------------


class Widget_Container: public My_Widget {

  public:

    class Iterator;
    class Reverse_Iterator;

    friend class Iterator;
    friend class Reverse_Iterator;

    //--------------------------------------------------

    // возможно, стоит переписать функции в стиле begin, true_begin, end, true_end
    class Iterator {
    friend class Reverse_Iterator;

    public:

        // sets iterator to begin of the container
        Iterator (Widget_Container& container);

        //--------------------------------------------------

        void set_to_begin (void);
        void set_to_end   (void);

        Widget_List::iterator get_iterator (void);

        Iterator&  operator++ (void);
        Iterator&  operator-- (void);
        My_Widget* operator*  (void) const;
        bool       operator!= (const Iterator& other) const;

    //--------------------------------------------------

    private:

        std::vector <Widget_List*> widget_lists_;
        int                        current_list_index_;
        Widget_List::iterator      iterator_;

        //--------------------------------------------------

        Widget_List*          get_current_list       (void) const;
        int                   get_current_list_size  (void) const;
        Widget_List::iterator get_current_list_begin (void) const;
        Widget_List::iterator get_current_list_end   (void) const;

        void add_next_priority_list (Widget_List* list);
    };

    // implemented as in stl,
    // reverse iterator contains iterator pointing to
    // the next container element
    class Reverse_Iterator {

    public:

        // sets iterator to the rbegin of the container
        Reverse_Iterator (Widget_Container& container);

        //--------------------------------------------------

        void set_to_rbegin (void);
        void set_to_rend   (void);

        Reverse_Iterator& operator++ (void);
        Reverse_Iterator& operator-- (void);

        // todo: make this function const
        // although it does -- and ++ on base_
        My_Widget* operator*  (void);
        bool       operator!= (const Reverse_Iterator& other) const;

    //--------------------------------------------------

    protected:

        // reverse_iterator points to the previous container element
        Iterator base_;
    };

    //--------------------------------------------------

    explicit Widget_Container (const plug::LayoutBox& box);

    Widget_Container (const Widget_Container&) = delete;
    operator=        (const Widget_Container&) = delete;

    //--------------------------------------------------

    int get_widgets_count (void);
    void register_widget            (My_Widget* widget);
    void register_priority_widget   (My_Widget* widget);
    void register_background_widget (My_Widget* widget);

    //--------------------------------------------------

    void onEvent (const  plug::Event& event,  plug::EHC&          context) override;
    void render  (plug::RenderTarget& target, plug::TransformStack& stack) override;

//--------------------------------------------------

  protected:

    Widget_List widgets_;
    Widget_List priority_widgets_;
    Widget_List background_widgets_; // unimportant, indifferent

    My_Widget* active_widget_;

    //--------------------------------------------------

    Iterator         begin  (void);
    Iterator         end    (void);
    Reverse_Iterator rbegin (void);
    Reverse_Iterator rend   (void);
};

//--------------------------------------------------
// iterator declarations





//--------------------------------------------------
#endif
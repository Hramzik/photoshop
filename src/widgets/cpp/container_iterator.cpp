

//--------------------------------------------------

#include "../hpp/widgets.hpp"

//--------------------------------------------------

Widget_Container::Iterator::Iterator (Widget_Container& container):
        widget_lists_       (),
        current_list_index_ (0),
        iterator_           ()
{

    add_next_priority_list (&container.priority_widgets_);
    add_next_priority_list (&container.widgets_);
    add_next_priority_list (&container.background_widgets_);

    iterator_ = widget_lists_ [0]->begin ();
}

//--------------------------------------------------

Widget_List* Widget_Container::Iterator::get_current_list (void) {

    return widget_lists_ [current_list_index_];
}


void Widget_Container::Iterator::add_next_priority_list
        (Widget_List* list) {

    widget_lists_.push_back (list);
}


void Widget_Container::Iterator::set_to_end (void) {

    iterator_ = widget_lists_ [widget_lists_.size () - 1]->end ();
}


Widget_Container::Iterator& Widget_Container::Iterator::operator++ (void) {

    Widget_List* current_list = get_current_list ();

    //--------------------------------------------------

    Widget_List::iterator current_end = current_list->end ();

    if (iterator_ != current_end) {

        iterator_++;
        return *this;
    }

    //--------------------------------------------------
    // corner case

    if (current_list_index_ == (int) widget_lists_.size ()) return *this;


    iterator_ = widget_lists_ [current_list_index_ + 1]->begin ();
    ++current_list_index_;


    return *this;
}


Widget_Container::Iterator& Widget_Container::Iterator::operator-- (void) {

    Widget_List* current_list = get_current_list ();

    //--------------------------------------------------

    Widget_List::iterator current_rend = current_list->rend ().base ();

    if (iterator_ != current_rend) {

        iterator_--;
        return *this;
    }

    //--------------------------------------------------
    // corner case

    if (current_list_index_ == 0) return *this;


    iterator_ = widget_lists_ [current_list_index_ - 1]->rbegin ().base ();
    --current_list_index_;


    return *this;
}


bool Widget_Container::Iterator::operator!= (const Iterator& other) const {

    return iterator_ != other.iterator_;
}


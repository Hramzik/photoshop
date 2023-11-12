

//--------------------------------------------------

#include "widgets/hpp/widgets.hpp"

//--------------------------------------------------

Widget_Container::Iterator::Iterator (Widget_Container& container):
        widget_lists_       (),
        current_list_index_ (0),
        iterator_           ()
{

    add_next_priority_list (&container.priority_widgets_);
    add_next_priority_list (&container.widgets_);
    add_next_priority_list (&container.background_widgets_);

    //--------------------------------------------------

    if (!widget_lists_.size ()) {

        LOG_ERROR (CRITICAL);
        return;
    }

    set_to_begin ();
}

//--------------------------------------------------

Widget_List* Widget_Container::Iterator::get_current_list (void) const {

    return widget_lists_ [current_list_index_];
}


int Widget_Container::Iterator::get_current_list_size (void) const {

    return (int) get_current_list ()->size ();
}


Widget_List::iterator
Widget_Container::Iterator::get_current_list_begin (void) const {

    return get_current_list ()->begin ();
}


Widget_List::iterator
Widget_Container::Iterator::get_current_list_end (void) const {

    return get_current_list ()->end ();
}


void Widget_Container::Iterator::add_next_priority_list
        (Widget_List* list) {

    widget_lists_.push_back (list);
}


void Widget_Container::Iterator::set_to_begin (void) {

    current_list_index_ = 0;
    iterator_           = get_current_list_begin ();

    //--------------------------------------------------

    if (!get_current_list_size ()) operator++ ();
}


void Widget_Container::Iterator::set_to_end (void) {

    current_list_index_ = (int) widget_lists_.size () - 1;
    iterator_           = get_current_list_end ();
}


Widget_Container::Iterator&
Widget_Container::Iterator::operator++ (void) {

    // moving along our list
    if (iterator_ != get_current_list_end ()) ++iterator_;
    if (iterator_ != get_current_list_end ()) return *this;

    //--------------------------------------------------
    // corner case

    while (current_list_index_ < (int) widget_lists_.size () - 1) {

        ++current_list_index_;
        iterator_ = get_current_list_begin ();

        if (get_current_list ()->size ()) break;
    }


    return *this;
}


Widget_Container::Iterator&
Widget_Container::Iterator::operator-- (void) {

    // moving along our list
    if (iterator_ != get_current_list_begin ()) {

        --iterator_;
        return *this;
    }

    //--------------------------------------------------
    // corner case

    while (current_list_index_ > 0) {

        --current_list_index_;
        iterator_ = get_current_list_end ();

        if (get_current_list ()->size ()) {

            // actually set to rbegin
            --iterator_;
            break;
        }
    }


    return *this;
}


bool Widget_Container::Iterator::operator!= (const Iterator& other) const {

    return iterator_ != other.iterator_;
}


Widget* Widget_Container::Iterator::operator* (void) const {

    if (iterator_ == get_current_list_end ()) {

        LOG_ERROR (BAD_ARGS);
        return nullptr;
    }


    return *iterator_;
}

//--------------------------------------------------
// REVERSE ITERATOR CODE


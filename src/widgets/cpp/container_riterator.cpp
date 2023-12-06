

//--------------------------------------------------

#include "widgets/hpp/widgets.hpp"

//--------------------------------------------------


Widget_Container::Reverse_Iterator::Reverse_Iterator (Widget_Container& container):
        base_ (container)
{
    set_to_rbegin ();
}

//--------------------------------------------------

void Widget_Container::Reverse_Iterator::set_to_rbegin (void) {

    base_.set_to_end ();
}


void Widget_Container::Reverse_Iterator::set_to_rend (void) {

    base_.set_to_begin ();
}


Widget_Container::Reverse_Iterator&
Widget_Container::Reverse_Iterator::operator++ (void) {

    --base_;


    return *this;
}


Widget_Container::Reverse_Iterator&
Widget_Container::Reverse_Iterator::operator-- (void) {

    ++base_;


    return *this;
}


My_Widget* Widget_Container::Reverse_Iterator::operator* (void) {

    --base_;

    //--------------------------------------------------

    My_Widget* result = *base_;
    ++base_;

    //--------------------------------------------------


    return result;
}


bool Widget_Container::Reverse_Iterator::operator!= (const Reverse_Iterator& other) const {

    return base_ != other.base_;
}


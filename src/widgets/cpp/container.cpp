

//--------------------------------------------------


#include "widgets/hpp/widgets.hpp"


//--------------------------------------------------

Widget_Container::Widget_Container (const plug::LayoutBox& box):
        My_Widget (box),

        widgets_            (),
        priority_widgets_   (),
        background_widgets_ (),
        active_widget_ (nullptr) {}

//--------------------------------------------------

int Widget_Container::get_widgets_count (void) {

    int widgets_count = 0;

    widgets_count += (int) widgets_.size ();
    widgets_count += (int) priority_widgets_.size ();
    widgets_count += (int) background_widgets_.size ();


    return widgets_count;
}


void Widget_Container::register_widget (My_Widget* widget) {

    widgets_.push_back (widget);
}


void Widget_Container::register_priority_widget (My_Widget* widget) {

    priority_widgets_.push_back (widget);
}


void Widget_Container::register_background_widget (My_Widget* widget) {

    background_widgets_.push_front (widget);
}

//--------------------------------------------------

void Widget_Container::render (plug::RenderTarget& target, plug::TransformStack& stack) {

    plug::Transform my_transform (getLayoutBox ().getPosition ());
    stack.enter (my_transform);

    //--------------------------------------------------

    for (auto i = rbegin (); i != rend (); ++i) {

        if ((*i)->is_closed ()) continue;

        //--------------------------------------------------

        (*i)->render (target, stack);
    }

    //--------------------------------------------------

    stack.leave ();
}

void Widget_Container::onEvent (const plug::Event& event, plug::EHC& context) {

    plug::Transform my_transform (getLayoutBox ().getPosition ());
    context.stack.enter (my_transform);

    //--------------------------------------------------

    for (auto i = begin (); i != end (); ++i) {

        if ((*i)->is_closed ()) {

            widgets_.erase (i.get_iterator ());
            continue;
        }

        //--------------------------------------------------

        (*i)->onEvent (event, context);
    }

    //--------------------------------------------------

    context.stack.leave ();
}

//--------------------------------------------------
// iterator code

Widget_Container::Iterator Widget_Container::begin (void) {

    return Iterator (*this);
}


Widget_Container::Iterator Widget_Container::end (void) {

    Iterator iterator (*this);


    iterator.set_to_end ();


    return iterator;
}


Widget_Container::Reverse_Iterator
Widget_Container::rbegin (void) {

    return Reverse_Iterator (*this);
}


Widget_Container::Reverse_Iterator
Widget_Container::rend (void) {

    Reverse_Iterator iterator (*this);


    iterator.set_to_rend ();


    return iterator;
}

//--------------------------------------------------


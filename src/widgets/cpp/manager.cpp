
//--------------------------------------------------

#include "widgets/hpp/widgets.hpp"

//--------------------------------------------------

Widget_Manager::Widget_Manager (const plug::LayoutBox& box):
        Widget_Container (box) {}

//--------------------------------------------------

void Widget_Manager::onEvent (const plug::Event& event, plug::EHC& context) {

    if (event.getType () != plug::EventType::MousePressed) Widget_Container::onEvent (event, context);

    //--------------------------------------------------
    // mouse pressed is handled differently

    onMousePressed ((const plug::MousePressedEvent&) event, context);
}

//--------------------------------------------------

void Widget_Manager::onMousePressed (const plug::MousePressedEvent& event, plug::EHC& context) {

    plug::Transform my_transform (getLayoutBox ().getPosition ());
    context.stack.enter (my_transform);

    //--------------------------------------------------

    for (auto i = begin (); i != end (); ++i) {

        if ((*i)->is_closed ()) {

            widgets_.erase (i.get_iterator ());
            continue;
        }

        //--------------------------------------------------
        // throw mouse event

        bool was_handled = context.stopped;
        (*i)->onEvent (event, context);
        bool is_handled = context.stopped;

        //--------------------------------------------------
        // check handling results

        if (was_handled || !is_handled) continue;
        // not normal widget list
        if (i.get_current_list_index () != 1) continue;

        //--------------------------------------------------
        // move widget to top

        widgets_.erase (i.get_iterator ());
        widgets_.push_front (*i);
    }

    //--------------------------------------------------

    context.stack.leave ();
}

//--------------------------------------------------


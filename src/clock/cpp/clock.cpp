

//--------------------------------------------------

#include "../hpp/clock.hpp"

//--------------------------------------------------

Clock_Widget::Clock_Widget (double width, double height):
        Widget_Container () {

    Textured_Window* face = new Textured_Window (width, height);
    widgets_.push_back (face);

    //--------------------------------------------------

    Point2D origin (width / 2, height / 2);
    Vector2D direction (0, -height * 0.25);

    Clock_Arrow* second_arrow = new Clock_Arrow (origin, direction, 60);
    Clock_Arrow* minute_arrow = new Clock_Arrow (origin, direction, 1);
    Clock_Arrow* hour_arrow   = new Clock_Arrow (origin, direction, 1.0 / 12);

    widgets_.push_back (second_arrow);
    widgets_.push_back (minute_arrow);
    widgets_.push_back (hour_arrow);
}

/*
Clock_Widget::Clock_Widget (const Graphic_Window& loader):
        Clock_Widget () {

    load_textures (loader);
}*/

//--------------------------------------------------

void Clock_Widget::load_textures (const Graphic_Window& loader) {

    if (face ().get_texture ()) {

        LOG_ERROR (BAD_ARGS);
        return;
    }


    face ().load_texture ("media/clock1.jpg", loader);
}

//--------------------------------------------------


Textured_Window& Clock_Widget::face (void) {

    Textured_Window* face = dynamic_cast <Textured_Window*> (widgets_.front ());
    if (!face) LOG_ERROR (CRITICAL);


    return *face;
}

Clock_Arrow& Clock_Widget::second_arrow (void) {

    auto i = widgets_.begin ();

    Clock_Arrow* arrow = dynamic_cast <Clock_Arrow*> (*(i++));
    if (!arrow) LOG_ERROR (CRITICAL);


    return *arrow;
}


Clock_Arrow& Clock_Widget::minute_arrow (void) {

    auto i = widgets_.end ();

    Clock_Arrow* arrow = dynamic_cast <Clock_Arrow*> (*(i--));
    if (!arrow) LOG_ERROR (CRITICAL);


    return *arrow;
}


Clock_Arrow& Clock_Widget::hour_arrow (void) {

    Clock_Arrow* arrow = dynamic_cast <Clock_Arrow*> (widgets_.back ());
    if (!arrow) LOG_ERROR (CRITICAL);


    return *arrow;
}


//--------------------------------------------------


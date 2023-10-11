

//--------------------------------------------------

#include "../hpp/transform.hpp"

//--------------------------------------------------

Transform_Stack::Transform_Stack (void):
        transforms_ () {}

//--------------------------------------------------

void Transform_Stack::push (const Transform& transform) {

    transforms_.push_back (transform);
}


void Transform_Stack::pop (void) {}

/*
Transform Transform_Stack::get_top (void) {}
Transform Transform_Stack::get_result (void) {}
*/
//--------------------------------------------------


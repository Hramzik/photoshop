

//--------------------------------------------------

#include "../hpp/transform.hpp"

//--------------------------------------------------

Transform_Stack::Transform_Stack (void):
        transforms_ () {}

//--------------------------------------------------

void Transform_Stack::push (const Transform& transform) {

    transforms_.push_back (transform);
}


void Transform_Stack::pop (void) {

    transforms_.pop_back ();
}


Transform Transform_Stack::get_top (void) {

    return transforms_.back ();
}


// todo: optimize calculations by storing current result
Transform Transform_Stack::get_result (void) {

    Transform result;

    for (Transform i : transforms_) {

        result.apply_after_me (i);
    }


    return result;
}

//--------------------------------------------------




//--------------------------------------------------

#include "../hpp/transform.hpp"

//--------------------------------------------------

Transform::Transform (void):
        Transform (Vector2D (0), Vector2D (1)) {}


Transform::Transform (Vector2D offset):
        Transform (offset, Vector2D (1)) {}


Transform::Transform (Vector2D offset, Vector2D scale):
        offset_ (offset),
        scale_  (scale) {}

//--------------------------------------------------

Vector2D Transform::apply_to_size (Vector2D size) const {

    return size * scale_;
}


Vector2D Transform::get_offset (void) const {

    return offset_;
}


void Transform::set_offset (Vector2D offset) {

    offset_ = offset;
}


void Transform::add_offset (Vector2D offset) {

    offset_ += offset;
}


void Transform::apply_after_me (const Transform& next_transform) {

    // offset происходит в относительных единицах
    offset_ += next_transform.offset_ * scale_;
    scale_  *= next_transform.scale_;
}

//--------------------------------------------------

std::ostream& operator<< (std::ostream& ostream, const Transform& transform) {

    ostream << "offset: " << transform.get_offset (); 
    ostream << " scale: " << transform.apply_to_size (1);


    return ostream;
}


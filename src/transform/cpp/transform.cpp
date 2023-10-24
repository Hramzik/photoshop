

//--------------------------------------------------

#include "../hpp/transform.hpp"

//--------------------------------------------------

Transform::Transform (void):
        Transform (Vector2D (1, 1), Vector2D (0, 0)) {}


Transform::Transform (Vector2D offset):
        Transform (offset, Vector2D (1, 1)) {}


Transform::Transform (Vector2D offset, Vector2D scale):
        offset_ (offset)
        scale_  (scale) {}

//--------------------------------------------------

void Transform::apply_after_me (const Transform& next_transform) {

    // offset происходит в относительных единицах
    offset_ += next_transform.offset_ * scale_;
    scale_  *= next_transform.scale_;
}


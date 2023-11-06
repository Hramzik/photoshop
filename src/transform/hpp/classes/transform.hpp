#ifndef TRANSFORM_CLASS_TRANSFORM_HPP_INCLUDED
#define TRANSFORM_CLASS_TRANSFORM_HPP_INCLUDED
//--------------------------------------------------

#include "../../../vector/hpp/vector.hpp"

//--------------------------------------------------


// in this project all transforms are performed on 2-d objects
// and are represented using scale + offset

class Transform {

  public:

    // creates identical transform
    Transform (void);
    Transform (Point2D  offset);
    Transform (Vector2D offset);
    Transform (Vector2D offset, Vector2D scale);

    //--------------------------------------------------

    Vector2D apply_to_size (Vector2D size) const;

    Vector2D get_offset   (void) const;
    Point2D  get_position (void) const; // same as get_offset (), but Point2D
    Vector2D get_scale    (void) const;

    void     set_offset (Vector2D offset);
    void     set_offset (Point2D  offset);
    void     add_offset (Vector2D offset);

    void apply_after_me (const Transform& next_transform);

//--------------------------------------------------

  private:

    Vector2D offset_;
    Vector2D scale_;
};

//--------------------------------------------------
#endif
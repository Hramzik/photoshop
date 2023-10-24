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
    Transform (Vector2D offset);
    Transform (Vector2D offset, Vector2D scale);

    //--------------------------------------------------

    void apply_after_me (const Transform& next_transform);

  private:

    Vector2D offset_;
    Vector2D scale_;
};

//--------------------------------------------------
#endif
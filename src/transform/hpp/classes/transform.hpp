#ifndef TRANSFORM_CLASS_TRANSFORM_HPP_INCLUDED
#define TRANSFORM_CLASS_TRANSFORM_HPP_INCLUDED
//--------------------------------------------------

#include "../../../matrix/hpp/classes/matrix3x3.hpp"

//--------------------------------------------------


// in this project all transforms are performed on 2-d objects
// and are represented using 3x3 matrixes

class Transform {

  public:

    // creates identical transform
    Transform (void);

  private:

    Matrix3x3 matrix_;
};





//--------------------------------------------------
#endif
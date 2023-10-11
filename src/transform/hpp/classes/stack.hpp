#ifndef TRANSFORM_CLASS_STACK_HPP_INCLUDED
#define TRANSFORM_CLASS_STACK_HPP_INCLUDED
//--------------------------------------------------

#include <vector>

#include "transform.hpp"

//--------------------------------------------------


// stores !local! transforms

class Transform_Stack {

  public:

    Transform_Stack (void);

    void push (const Transform& transform);
    void pop  (void);

    Transform get_top    (void);
    Transform get_result (void);

  private:

    std::vector <Transform> transforms_;
};





//--------------------------------------------------
#endif
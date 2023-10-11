#ifndef VECTOR_FUNCTIONS_HPP_INCLUDED
#define VECTOR_FUNCTIONS_HPP_INCLUDED
//--------------------------------------------------


#include <iostream>


//--------------------------------------------------


#include "classes2d.hpp"
#include "classes3d.hpp"


//--------------------------------------------------


std::ostream& operator<< (std::ostream& stream, const Pair2D& pair);
std::ostream& operator<< (std::ostream& stream, const Pair3D& pair);


//--------------------------------------------------
#endif


//--------------------------------------------------


#include <cmath>


//--------------------------------------------------


#include "../hpp/vector.hpp"


//--------------------------------------------------


const Pair3D Pair3D::invalid (NAN);


//--------------------------------------------------

Pair2D::Pair2D (double new_x, double new_y):
    x (new_x),
    y (new_y) {}


Pair2D::Pair2D (double both):
    Pair2D (both, both) {}


Pair2D::Pair2D (void):
    Pair2D (NAN) {}

//--------------------------------------------------

Pair3D::Pair3D (double new_x, double new_y, double new_z):
    x (new_x),
    y (new_y),
    z (new_z) {}


Pair3D::Pair3D (double all):
    Pair3D (all, all, all) {}


Pair3D::Pair3D (void):
    Pair3D (NAN) {}

//--------------------------------------------------

std::ostream& operator<< (std::ostream& stream, const Pair2D& pair) {

    stream << "(" << pair.x << ", " << pair.y << ")";


    return stream;
}


Return_code Pair2D::scale (double scale) {

    x *= scale;
    y *= scale;


    return SUCCESS;
}

//--------------------------------------------------

std::ostream& operator<< (std::ostream& stream, const Pair3D& pair) {

    stream << "(" << pair.x << ", " << pair.y << ", " << pair.z << ")";


    return stream;
}


Return_code Pair3D::scale (double scale) {

    x *= scale;
    y *= scale;
    z *= scale;


    return SUCCESS;
}

//--------------------------------------------------

bool Pair3D::is_valid (void) {

    if (std::isnan (x)) return false;
    if (std::isnan (y)) return false;
    if (std::isnan (z)) return false;


    return true;
}


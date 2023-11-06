

//--------------------------------------------------


#include <cmath>


//--------------------------------------------------


#include "../hpp/vector.hpp"


//--------------------------------------------------


static const double PI = 3.14159265358;


//--------------------------------------------------


Vector2D::Vector2D (double new_x, double new_y):
    Pair2D (new_x, new_y) {}


Vector2D::Vector2D (double both):
    Pair2D (both) {}


Vector2D::Vector2D (void):
    Pair2D () {}

//--------------------------------------------------

Return_code Vector2D::rotate (double degrees) {

    double radians = degrees / 360 * (2 * PI);


    double old_x = x;
    double old_y = y;

    x =  old_x * cos (radians) - old_y * sin (radians);
    y =  old_x * sin (radians) + old_y * cos (radians);


    return SUCCESS;
}

//--------------------------------------------------
// vector-double operators

Vector2D Vector2D::operator- (void) const {

    return {-x, -y};
}


Vector2D Vector2D::operator* (double value) const {

    Vector2D ans = *this;
    ans.scale (value);


    return ans;
}


Vector2D Vector2D::operator/ (double value) const {

    Vector2D ans = *this;
    ans.scale (1 / value);


    return ans;
}

//--------------------------------------------------
// vector-vector operators

Vector2D operator* (Vector2D left, Vector2D right) {

    return Vector2D (left.x * right.x, left.y * right.y);
}


Vector2D operator+ (Vector2D left, Vector2D right) {

    return Vector2D (left.x + right.x, left.y + right.y);
}


Vector2D operator- (Vector2D left, Vector2D right) {

    return Vector2D (left.x - right.x, left.y - right.y);
}


Vector2D operator/ (Vector2D left, Vector2D right) {

    return Vector2D (left.x / right.x, left.y / right.y);
}


void Vector2D::operator+= (Vector2D vector) {

    x += vector.x;
    y += vector.y;
}


void Vector2D::operator*= (Vector2D vector) {

    x *= vector.x;
    y *= vector.y;
}

//--------------------------------------------------
// convertation

Point2D Vector2D::as_point (void) {

    return Point2D (x, y);
}

//--------------------------------------------------


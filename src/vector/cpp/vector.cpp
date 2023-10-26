

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


Vector3D::Vector3D (double new_x, double new_y, double new_z):
    Pair3D (new_x, new_y, new_z) {}


Vector3D::Vector3D (double all):
    Pair3D (all) {}


Vector3D::Vector3D (void):
    Pair3D () {}


Vector3D Vector3D::get_copy (void) {

    Vector3D copy = *this;


    return copy;
}


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

Vector2D Vector2D::operator* (Vector2D vector) const {

    return { x * vector.x, y * vector.y };
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

Vector3D Vector3D::operator+ (Vector3D vector) {

    Vector3D temp = *this;
    temp += vector;


    return temp;
}


Vector3D& Vector3D::operator+= (Vector3D vector) {

    x += vector.x;
    y += vector.y;
    z += vector.z;


    return *this;
}

//--------------------------------------------------

Vector3D Vector3D::operator- (void) {

    return {-x, -y, -z};
}


Vector3D Vector3D::operator* (double value) {

    Vector3D ans = *this;
    ans.scale (value);


    return ans;
}


Vector3D Vector3D::operator/ (double value) {

    Vector3D ans = *this;
    ans.scale (1 / value);


    return ans;
}

//--------------------------------------------------

double Vector3D::operator^ (Vector3D vector) {

    double x_part = x * vector.x;
    double y_part = y * vector.y;
    double z_part = z * vector.z;


    return x_part + y_part + z_part;
}

//--------------------------------------------------

double Vector3D::get_len_squared (void) {

    Vector3D me = *this;


    return (me ^ me);
}


double Vector3D::get_len (void) {

    return sqrt (get_len_squared ());
}


void Vector3D::normalize (void) {

    adjust_len (1);
}


void Vector3D::adjust_len (double new_len) {

    double factor = fmax (0, new_len / get_len ());
    scale (factor);
}


Vector3D Vector3D::adjust_len_copy (double new_len) {

    Vector3D temp = get_copy ();
    temp.adjust_len (new_len);


    return temp;
}

//--------------------------------------------------

void Vector3D::rotate_left (double degrees) {

    Vector2D temp (x, y);
    temp.rotate (degrees);

    //--------------------------------------------------

    x = temp.x;
    y = temp.y;


    return;
}


void Vector3D::rotate_right (double degrees) {

    rotate_left (-degrees);
}


void Vector3D::rotate_up (double degrees) {

    double ratio = x / y;

    //--------------------------------------------------

    Vector2D temp (x + y, z);
    temp.rotate (degrees);

    //--------------------------------------------------

    z = temp.y;

    x = temp.x / (1 + 1 / ratio);
    y = temp.x / (1 + ratio);


    return;
}


void Vector3D::rotate_down (double degrees) {

    rotate_up (-degrees);
}


Vector3D Vector3D::rotate_left_copy (double degrees) const {

    Vector3D temp = *this;
    temp.rotate_left (degrees);


    return temp;
}


Vector3D Vector3D::rotate_right_copy (double degrees) const {

    Vector3D temp = *this;
    temp.rotate_right (degrees);


    return temp;
}


Vector3D Vector3D::rotate_up_copy (double degrees) const {

    Vector3D temp = *this;
    temp.rotate_up (degrees);


    return temp;
}


Vector3D Vector3D::rotate_down_copy (double degrees) const {

    Vector3D temp = *this;
    temp.rotate_down (degrees);


    return temp;
}

//--------------------------------------------------

Vector3D Vector3D::flat_projection (void) const {

    return { x, y, 0 };
}


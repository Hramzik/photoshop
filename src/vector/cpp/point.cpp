

//--------------------------------------------------


#include <cmath>


//--------------------------------------------------


#include "../hpp/vector.hpp"


//--------------------------------------------------


Point2D::Point2D (double new_x, double new_y):
    Pair2D (new_x, new_y) {}


Point2D::Point2D (int new_x, int new_y):
    Point2D ((double) new_x, (double) new_y) {}


Point2D::Point2D (double both):
    Pair2D (both) {}


Point2D::Point2D (void):
    Pair2D () {}


//--------------------------------------------------


Point3D::Point3D (double new_x, double new_y, double new_z):
    Pair3D (new_x, new_y, new_z) {}


Point3D::Point3D (double all):
    Pair3D (all) {}


Point3D::Point3D (void):
    Pair3D () {}


//--------------------------------------------------


Return_code Point2D::move (Vector2D direction) {

    move (direction.x, direction.y);


    return SUCCESS;
}


Return_code Point2D::move (double offset_x, double offset_y) {

    x += offset_x;
    y += offset_y;


    return SUCCESS;
}


Point2D Point2D::move_copy (Vector2D direction) {

    Point2D ans = *this;


    ans.move (direction);


    return ans;
}

Vector2D operator- (Point2D left, Point2D right) {

    return Vector2D (left.x - right.x, left.y - right.y);
}

//--------------------------------------------------

Point3D Point3D::move_copy (Vector2D direction) {

    Point3D ans = *this;
    ans.move (direction);


    return ans;
}


Point3D Point3D::move_copy (Vector3D direction) {

    Point3D ans = *this;
    ans.move (direction);


    return ans;
}


Point3D Point3D::move_copy (double offset_x, double offset_y, double offset_z) {

    Point3D ans = *this;
    ans.move (offset_x, offset_y, offset_z);


    return ans;
}


Return_code Point3D::move (Vector2D direction) {

    move (direction.x, direction.y, 0);


    return SUCCESS;
}


Return_code Point3D::move (Vector3D direction) {

    move (direction.x, direction.y, direction.z);


    return SUCCESS;
}


Return_code Point3D::move (double offset_x, double offset_y, double offset_z) {

    x += offset_x;
    y += offset_y;
    z += offset_z;


    return SUCCESS;
}


double Point3D::distance2_to (Point3D point) {

    double distance2_x = (x - point.x) * (x - point.x);
    double distance2_y = (y - point.y) * (y - point.y);
    double distance2_z = (z - point.z) * (z - point.z);


    return distance2_x + distance2_y + distance2_z;
}


//--------------------------------------------------


Vector3D Point3D::operator- (Point3D point) {

    return { x - point.x, y - point.y, z - point.z };
}


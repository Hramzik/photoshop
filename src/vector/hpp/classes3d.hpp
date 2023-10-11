#ifndef VECTOR_CLASSES3D_HPP_INCLUDED
#define VECTOR_CLASSES3D_HPP_INCLUDED
//--------------------------------------------------


#include "../../lib/logs.hpp"
#include "classes2d.hpp"


//--------------------------------------------------


class Vector3D;


//--------------------------------------------------


class Pair3D {

public:

    double x;
    double y;
    double z;

    //--------------------------------------------------

    static const Pair3D invalid;

    //--------------------------------------------------

    Pair3D (double new_x, double new_y, double new_z);
    Pair3D (double all);
    Pair3D (void);

    //--------------------------------------------------

    bool is_valid (void);

    //--------------------------------------------------

    Return_code scale (double scale);
    Return_code print (void);
};

//--------------------------------------------------

class Point3D: public Pair3D {

public:

    Point3D (double new_x, double new_y, double new_z);
    Point3D (double all);
    Point3D (void);

    Return_code move (Vector3D direction);
    Return_code move (Vector2D direction);
    Return_code move (double offset_x, double offset_y, double offset_z);
    Point3D move_copy (Vector2D direction);
    Point3D move_copy (Vector3D direction);
    Point3D move_copy (double offset_x, double offset_y, double offset_z);

    double distance2_to (Point3D point);

    Vector3D operator- (Point3D point);
};

//--------------------------------------------------

class Vector3D: public Pair3D {

public:

    Vector3D (double new_x, double new_y, double new_z);
    Vector3D (double all);
    Vector3D (void);

    Vector3D get_copy (void);

    //--------------------------------------------------

    Vector3D  operator+  (Vector3D vector);
    Vector3D& operator+= (Vector3D vector);
    Vector3D operator- (void);
    Vector3D operator* (double value);
    Vector3D operator/ (double value);
    double   operator^ (Vector3D vector);

    //--------------------------------------------------

    double get_len         (void);
    double get_len_squared (void);
    void   normalize  (void);
    void   adjust_len (double new_len);
    Vector3D adjust_len_copy (double new_len);

    void rotate_left  (double degrees);
    void rotate_right (double degrees);
    void rotate_up    (double degrees);
    void rotate_down  (double degrees);
    Vector3D rotate_left_copy  (double degrees) const;
    Vector3D rotate_right_copy (double degrees) const;
    Vector3D rotate_up_copy    (double degrees) const;
    Vector3D rotate_down_copy  (double degrees) const;

    Vector3D flat_projection (void) const;
};


//--------------------------------------------------
#endif
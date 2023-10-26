#ifndef VECTOR_CLASSES2D_HPP_INCLUDED
#define VECTOR_CLASSES2D_HPP_INCLUDED
//--------------------------------------------------


#include "../../lib/logs.hpp"


//--------------------------------------------------


class Vector2D;


//--------------------------------------------------


class Pair2D {

public:

    double x;
    double y;

    Pair2D (double new_x, double new_y);
    Pair2D (double both);
    Pair2D (void);

    Return_code scale (double scale);
    Return_code print (void);
};

//--------------------------------------------------

class Point2D: public Pair2D {

public:

    Point2D (double new_x, double new_y);
    Point2D (double both);
    Point2D (void);

    Return_code  move (Vector2D direction);
    Return_code  move (double offset_x, double offset_y);
    Point2D move_copy (Vector2D direction);
};

//--------------------------------------------------

class Vector2D: public Pair2D {

public:

    Vector2D (double new_x, double new_y);
    Vector2D (double both);
    Vector2D (void);

    Return_code rotate (double degrees);

    Vector2D operator- (void)            const;
    Vector2D operator* (double value)    const;
    Vector2D operator* (Vector2D vector) const;
    Vector2D operator/ (double value)    const;

    void operator+= (Vector2D vector);
    void operator*= (Vector2D vector);
};


//--------------------------------------------------
#endif
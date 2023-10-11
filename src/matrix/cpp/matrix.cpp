

//--------------------------------------------------

#include "../hpp/matrix.hpp"

//--------------------------------------------------

Matrix3x3::Matrix3x3 (void):
        a11 (1), a12 (0), a13 (0),
        a21 (0), a22 (1), a23 (0),
        a31 (0), a32 (0), a33 (1) {}

//--------------------------------------------------

Matrix3x3 operator* (const Matrix3x3& left, const Matrix3x3& right) {

    Matrix3x3 result;

    result.a11 = left.a11 * right.a11 + left.a12 * right.a21 + left.a13 * right.a31;
    result.a12 = left.a11 * right.a12 + left.a12 * right.a22 + left.a13 * right.a32;
    result.a13 = left.a11 * right.a13 + left.a12 * right.a23 + left.a13 * right.a33;
    result.a21 = left.a21 * right.a11 + left.a22 * right.a21 + left.a23 * right.a31;
    result.a22 = left.a21 * right.a12 + left.a22 * right.a22 + left.a23 * right.a32;
    result.a23 = left.a21 * right.a13 + left.a22 * right.a23 + left.a23 * right.a33;
    result.a31 = left.a31 * right.a11 + left.a32 * right.a21 + left.a33 * right.a31;
    result.a32 = left.a31 * right.a12 + left.a32 * right.a22 + left.a33 * right.a32;
    result.a33 = left.a31 * right.a13 + left.a32 * right.a23 + left.a33 * right.a33;


    return result;
}


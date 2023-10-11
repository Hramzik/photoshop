#ifndef MATRIX_CLASS_MATRIX3X3_HPP_INCLUDED
#define MATRIX_CLASS_MATRIX3X3_HPP_INCLUDED
//--------------------------------------------------


struct Matrix3x3 {

    // creates unit matrix
    Matrix3x3 (void);

    //--------------------------------------------------

    double a11;
    double a12;
    double a13;
    double a21;
    double a22;
    double a23;
    double a31;
    double a32;
    double a33;
};


Matrix3x3 operator* (const Matrix3x3& left, const Matrix3x3& right);


//--------------------------------------------------
#endif
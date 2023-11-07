#ifndef MY_RGB_CLASSES_HPP_INCLUDED
#define MY_RGB_CLASSES_HPP_INCLUDED
//--------------------------------------------------


#include "../../lib/logs.hpp"
#include "enums.hpp"
#include "../../vector/hpp/vector.hpp"


//--------------------------------------------------


class My_RGB {

public:

    static constexpr Color DEFAULT_COLOR = C_GREEN;

    //--------------------------------------------------

    unsigned char r;
    unsigned char g;
    unsigned char b;

    My_RGB (unsigned char new_r, unsigned char new_g, unsigned char new_b);
    My_RGB (unsigned char all);
    My_RGB (double all);
    My_RGB (Color color);
    My_RGB (void);

    My_RGB  operator*  (double scale);
    My_RGB  operator* (Vector3D scale);
    My_RGB  operator*  (My_RGB color);
    My_RGB& operator*= (My_RGB color);

    My_RGB  operator+  (My_RGB color);
    My_RGB& operator+= (My_RGB color);
    My_RGB& operator-= (My_RGB color);
    My_RGB& operator+= (double all);
};


//--------------------------------------------------
#endif
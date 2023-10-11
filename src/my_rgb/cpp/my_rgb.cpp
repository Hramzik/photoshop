

//--------------------------------------------------


#include "../hpp/my_rgb.hpp"
#include "../../lib/logs.hpp"


//--------------------------------------------------


static void saturation_add (unsigned char& left, unsigned char right);
static void saturation_mul (unsigned char& value, double scale);
static void saturation_mul (unsigned char& value, double scale);


//--------------------------------------------------


My_RGB::My_RGB (unsigned char new_r, unsigned char new_g, unsigned char new_b):
    r (new_r),
    g (new_g),
    b (new_b)
{}


My_RGB::My_RGB (unsigned char all):
    My_RGB (all, all, all) {}


//--------------------------------------------------
#define DEF_COLOR(name, r, g, b) case C_##name: *this = { r, g, b }; break;

My_RGB::My_RGB (Color color):
    r (0),
    g (0),
    b (0) {

    switch (color) {

        #include "../hpp/colors.hpp"
        default: LOG_ERROR (CRITICAL);
    }
}
//--------------------------------------------------


static void saturation_add (unsigned char& left, unsigned char right) {

    if (left + right < left) {

        left = 255;
        return;
    };


    left += right;
    return;
}


static void saturation_mul (unsigned char& value, double scale) {

    if (value * scale > 255) {

        value = 255;
        return;
    }


    value = (unsigned char) (value * scale);
    return;
}


static void saturation_mul (unsigned char& value, unsigned char scale) {

    if (value * scale > 255) {

        value = 255;
        return;
    }


    value *= scale;
    return;
}

//--------------------------------------------------

My_RGB My_RGB::operator* (double scale) {

    return operator* (Vector3D (scale));
}


My_RGB My_RGB::operator* (Vector3D scale) {

    My_RGB ans = *this;


    saturation_mul (ans.r, scale.x);
    saturation_mul (ans.g, scale.y);
    saturation_mul (ans.b, scale.z);


    return ans;
}

//--------------------------------------------------

My_RGB& My_RGB::operator+= (My_RGB color) {

    saturation_add (r, color.r);
    saturation_add (g, color.g);
    saturation_add (b, color.b);


    return *this;
}


My_RGB My_RGB::operator+ (My_RGB color) {

    My_RGB ans = *this;


    ans += color;


    return ans;
}


My_RGB& My_RGB::operator*= (My_RGB color) {

    saturation_mul (r, color.r);
    saturation_mul (g, color.g);
    saturation_mul (b, color.b);


    return *this;
}


My_RGB My_RGB::operator* (My_RGB color) {

    My_RGB ans = *this;


    ans *= color;


    return ans;
}

//--------------------------------------------------

std::ostream& operator<< (std::ostream& ostream, My_RGB color) {

    ostream << "(" << (int) color.r << ", " << (int) color.g << ", " << (int) color.b << ")";


    return ostream;
}


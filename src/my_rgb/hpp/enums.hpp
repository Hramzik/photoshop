#ifndef MY_RGB_ENUMS_HPP_INCLUDED
#define MY_RGB_ENUMS_HPP_INCLUDED
//--------------------------------------------------


#define DEF_COLOR(name, ...) C_##name,

enum Color {

    #include "colors.hpp"
};

#undef DEF_COLOR


//--------------------------------------------------
#endif
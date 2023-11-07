

//--------------------------------------------------

#include "../hpp/filters.hpp"

//--------------------------------------------------

Filter_Mask::Filter_Mask (int width, int height):
        width_ (width),
        height_ (height),
        buffer_ (nullptr)
{
    buffer_ = new bool [width_ * height_];

    //--------------------------------------------------

    fill (true);
}


Filter_Mask::~Filter_Mask () {

    delete buffer_;
    buffer_ = nullptr;
}

//--------------------------------------------------

int Filter_Mask::get_width () const{

    return width_;
}


int Filter_Mask::get_height () const{

    return height_;
}


bool Filter_Mask::get_value (int x, int y) const {

    return buffer_ [get_buffer_index (x, y)];
}


void Filter_Mask::set_value (int x, int y, bool value) {

    buffer_ [get_buffer_index (x, y)] = value;
}

//--------------------------------------------------

void Filter_Mask::fill (bool value) {

    for (int x = 0; x < width_;  ++x) {
    for (int y = 0; y < height_; ++y) {

        set_value (x, y, value);
    }}
}


int Filter_Mask::get_buffer_index (int x, int y) const {

    return y * height_ + x;
}

//--------------------------------------------------


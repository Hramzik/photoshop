

//--------------------------------------------------

#include "tools/hpp/tools.hpp"

//--------------------------------------------------

Texture_Data::Texture_Data (const char* texture_path):
        texture_path_ (texture_path) {}

//--------------------------------------------------

const char* Texture_Data::getName (void) const {

    return nullptr;
}

const char* Texture_Data::getTexturePath (void) const {

    return texture_path_;
}

//--------------------------------------------------


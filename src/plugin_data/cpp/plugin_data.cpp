

//--------------------------------------------------

#include "plugin_data/hpp/plugin_data.hpp"

//--------------------------------------------------

Plugin_Data::Plugin_Data (const char* name, const char* texture_path):
        name_ (name),
        texture_path_ (texture_path) {}

//--------------------------------------------------

const char* Plugin_Data::getName (void) const {

    return name_;
}

const char* Plugin_Data::getTexturePath (void) const {

    return texture_path_;
}

//--------------------------------------------------


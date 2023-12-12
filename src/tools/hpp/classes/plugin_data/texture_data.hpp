#ifndef CLASS_TEXTURE_DATA_HPP_INCLUDED
#define CLASS_TEXTURE_DATA_HPP_INCLUDED
//--------------------------------------------------

#include "Plug/Plugin.h"

//--------------------------------------------------

class Texture_Data: public plug::PluginData {

  public:

    Texture_Data (const char* texture_path);

    //--------------------------------------------------

    const char* getName        (void) const override;
    const char* getTexturePath (void) const override;

//--------------------------------------------------

  private:

    const char* texture_path_;
};


//--------------------------------------------------
#endif
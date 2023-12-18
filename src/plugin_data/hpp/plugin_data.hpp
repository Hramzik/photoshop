#ifndef CLASS_PLUGIN_DATA_HPP_INCLUDED
#define CLASS_PLUGIN_DATA_HPP_INCLUDED
//--------------------------------------------------

#include "Plug/Plugin.h"

//--------------------------------------------------

class Plugin_Data: public plug::PluginData {

  public:

    Plugin_Data (const char* name, const char* texture_path);

    //--------------------------------------------------

    const char* getName        (void) const override;
    const char* getTexturePath (void) const override;

//--------------------------------------------------

  private:

    const char* name_;
    const char* texture_path_;
};


//--------------------------------------------------
#endif
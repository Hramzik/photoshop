#ifndef FILTERS_CLASS_FILTER_HPP_INCLUDED
#define FILTERS_CLASS_FILTER_HPP_INCLUDED
//--------------------------------------------------

#include "Plug/Filter.h"

#include "plugin_data/hpp/plugin_data.hpp"

//--------------------------------------------------

class Filter: public plug::Filter {

  public:

    Filter (const char* name);

    //--------------------------------------------------

    void          applyFilter (plug::Canvas& canvas) const override;
    plug::Widget* getWidget   (void)                       override;

    //--------------------------------------------------

    plug::Plugin*           tryGetInterface (size_t interface_id) override;
    const plug::PluginData* getPluginData   (void)          const override;
    void                    addReference    (void)                override;
    void                    release         (void)                override;

  protected:

    virtual void apply_filter_to_pixel (plug::Color& pixel) const;

  private:

    Plugin_Data plugin_data_;
};


//--------------------------------------------------
#endif
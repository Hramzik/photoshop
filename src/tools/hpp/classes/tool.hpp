#ifndef TOOLS_CLASS_TOOL_HPP_INCLUDED
#define TOOLS_CLASS_TOOL_HPP_INCLUDED
//--------------------------------------------------

#include "Plug/Tool.h"
#include "Plug/Canvas.h"

#include "plugin_data/hpp/plugin_data.hpp"

//--------------------------------------------------

class Tool: public plug::Tool {

  public:

    Tool (const char* name, const char* texture_path);

    //--------------------------------------------------

    void setColorPalette (plug::ColorPalette& palette) override;
    void setActiveCanvas (plug::Canvas&       canvas)  override;

    void onMainButton      (const plug::ControlState& state, const plug::Vec2d& position) override;
    void onSecondaryButton (const plug::ControlState& state, const plug::Vec2d& position) override;

    void onModifier1 (const plug::ControlState& state) override;
    void onModifier2 (const plug::ControlState& state) override;
    void onModifier3 (const plug::ControlState& state) override;

    void onMove (const plug::Vec2d& position) override;
    void onConfirm (void) override;
    void onCancel  (void) override;

    plug:: Widget* getWidget(void) override;

    //--------------------------------------------------

    plug::Plugin*           tryGetInterface (size_t interface_id) override;
    const plug::PluginData* getPluginData   (void)          const override;

    void addReference (void) override;
    void release      (void) override;

//--------------------------------------------------

  protected:

    plug::ColorPalette* color_palette_;
    plug::Canvas*       canvas_;

    Plugin_Data plugin_data_;
};

//--------------------------------------------------
#endif
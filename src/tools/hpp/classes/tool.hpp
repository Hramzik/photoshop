#ifndef TOOLS_CLASS_TOOL_HPP_INCLUDED
#define TOOLS_CLASS_TOOL_HPP_INCLUDED
//--------------------------------------------------

#include "Plug/Tool.h"
#include "Plug/Canvas.h"

//--------------------------------------------------

class Color_Palette;

//--------------------------------------------------

class Tool: public plug::Tool {

  public:

    Tool (const char *name, const char *texture_path);

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
    //size_t m_cnt_reference;
    //const BaseData m_data;
};


/*class Tool {

  public:

    virtual ~Tool (void) = default;

    //--------------------------------------------------

    virtual Widget* get_widget (void);

    virtual void on_main_button
    (Button_state state, Point2D mouse_position, Canvas& canvas);

    virtual void on_secondary_button
    (Button_state state, Point2D mouse_position, Canvas& canvas);

    virtual void on_modifier1 // shift
    (Button_state state, Canvas& canvas);

    virtual void on_modifier2 // ctrl
    (Button_state state, Canvas& canvas);

    virtual void on_modifier3 // alt
    (Button_state state, Canvas& canvas);

    virtual void on_move    (Point2D mouse_position, Canvas& canvas);
    virtual void on_confirm (Canvas& canvas);
    virtual void on_cancel  (void);
};*/


//--------------------------------------------------
#endif
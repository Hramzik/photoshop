#ifndef WIDGETS_CLASS_PHOTOSHOP_HPP_INCLUDED
#define WIDGETS_CLASS_PHOTOSHOP_HPP_INCLUDED
//--------------------------------------------------

#include "widgets/hpp/widgets.hpp"

#include "filters/hpp/filters.hpp"

//--------------------------------------------------

class Menu;

//--------------------------------------------------

class Photoshop: public Widget_Manager {

  public:

    static const char* const DEFAULT_CANVAS_IMAGE_PATH;

    //--------------------------------------------------

    Photoshop (plug::LayoutBox& box);

    //--------------------------------------------------

    void add_tool   (plug::Tool&   tool);
    void add_filter (plug::Filter& filter);
    void add_canvas (plug::Canvas& canvas);

    //--------------------------------------------------

    plug::ColorPalette& access_color_palette  (void);
    Canvas_Manager&     access_canvas_manager (void);

//--------------------------------------------------

  private:

    Color_Palette  color_palette_;
    Tool_Palette   tool_palette_;
    Filter_Palette filter_palette_;

    Canvas_Manager canvas_manager_;
    Menu*          menu_;

    void load_plugins  (void);
    void init_colors   (void);
    void init_tools    (void);
    void init_canvases (void);

    void init_menu           (void);
    void init_file_button    (void);
    void init_filters_button (void);
};

//--------------------------------------------------
#endif
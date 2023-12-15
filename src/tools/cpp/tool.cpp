

//--------------------------------------------------

#include <iostream>

#include "../hpp/tools.hpp"

//--------------------------------------------------

Tool::Tool (const char* name, const char* texture_path):

        color_palette_ (nullptr),
        canvas_        (nullptr)
{
    (void) name; (void) texture_path;
}

//--------------------------------------------------

void Tool::setColorPalette (plug::ColorPalette& palette) {

    color_palette_ = &palette;
}

void Tool::setActiveCanvas (plug::Canvas& canvas) {

    canvas_ = &canvas;
}

//--------------------------------------------------

void Tool::onMainButton (const plug::ControlState& state, const plug::Vec2d& position) {

    (void) state; (void) position;
}

void Tool::onSecondaryButton (const plug::ControlState& state, const plug::Vec2d& position) {

    (void) state; (void) position;
}

//--------------------------------------------------

void Tool::onModifier1 (const plug::ControlState& state) {

    (void) state;
}

void Tool::onModifier2 (const plug::ControlState& state) {

    (void) state;
}

void Tool::onModifier3 (const plug::ControlState& state) {

    (void) state;
}

//--------------------------------------------------

void Tool::onMove (const plug::Vec2d& position) {

    (void) position;
}

void Tool::onConfirm (void) {

    return;
}

void Tool::onCancel  (void) {

    return;
}


plug::Widget* Tool::getWidget (void) {

    return nullptr;
}

//--------------------------------------------------

plug::Plugin* Tool::tryGetInterface (size_t interface_id) {

    switch (interface_id) {

        case static_cast <size_t> (plug::PluginGuid::Plugin):
        {
            addReference ();
            return static_cast <plug::Plugin*> (this);
        }

        case static_cast <size_t> (plug::PluginGuid::Tool):
        {
            addReference ();
            return static_cast <plug::Tool*> (this);
        }

        //--------------------------------------------------

        default: return nullptr;
    }
}

const plug::PluginData* Tool::getPluginData (void) const {

    return nullptr;
}

void Tool::addReference (void) {

    return;
}

void Tool::release (void) {

    return;
}

//--------------------------------------------------


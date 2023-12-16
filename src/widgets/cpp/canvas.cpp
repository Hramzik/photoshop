

//--------------------------------------------------

#include "Impl/RenderTarget/SdlRenderTarget/SdlAdapters/Converters.h"

#include "graphics/hpp/sdl.hpp"

#include "widgets/hpp/widgets.hpp"

//--------------------------------------------------

Canvas::Canvas (void):

        main_texture_  (nullptr),
        plug_texture_ (nullptr),

        is_plug_texture_updated_ (false),

        selection_mask_ (nullptr) {}

Canvas::Canvas (const int width, const int height):
        Canvas ()
{
    main_texture_ = new MyRenderTexture (width, height);
    main_texture_->clear (getSDL_Color (DEFAULT_CANVAS_COLOR));

    //--------------------------------------------------

    plug_texture_ = new plug::Texture (width, height);

    //--------------------------------------------------

    selection_mask_ = new SelectionMask (width, height);
    selection_mask_->fill (true);
}

Canvas::Canvas (const char* path):
        Canvas ()
{
    main_texture_ = new MyRenderTexture ();
    main_texture_->setSdlSurface (IMG_Load (path));

    int width  = main_texture_->getSdlSurface ()->w;
    int height = main_texture_->getSdlSurface ()->h;

    //--------------------------------------------------

    plug_texture_ = new plug::Texture (width, height);

    //--------------------------------------------------

    selection_mask_ = new SelectionMask (width, height);
    selection_mask_->fill (true);
}

Canvas::~Canvas (void) {

    delete main_texture_;
    delete plug_texture_;
    delete selection_mask_;
}

//--------------------------------------------------

void Canvas::draw (const plug::VertexArray& vertex_array) {

    main_texture_->draw (vertex_array);

    //--------------------------------------------------

    is_plug_texture_updated_ = false;
}

void Canvas::draw (const plug::VertexArray& vertex_array, const plug::Texture& texture) {

    MyRenderTexture tmp;
    copyToMyTexture (tmp, texture);
    main_texture_->draw (vertex_array, tmp);

    //--------------------------------------------------

    is_plug_texture_updated_ = false;
}

//--------------------------------------------------

plug::Vec2d Canvas::getSize (void) const {

    int width  = main_texture_->getSdlSurface ()->w;
    int height = main_texture_->getSdlSurface ()->h;


    return plug::Vec2d (width, height);
}

void Canvas::setSize (const plug::Vec2d& size) {

    (void) size;
    // todo
}

plug::SelectionMask& Canvas::getSelectionMask (void) {

    return *selection_mask_;
}

plug::Color Canvas::getPixel (size_t x, size_t y) const {

    const_cast <Canvas&> (*this).update_plug_texture ();

    //--------------------------------------------------

    return plug_texture_->getPixel (x, y);
}

void Canvas::setPixel (size_t x, size_t y, const plug::Color& color) {

    plug::VertexArray point (plug::PrimitiveType::Points, 1);
    point [0].position = plug::Vec2d (x, y);
    point [0].color    = color;

    draw (point);

    //--------------------------------------------------

    is_plug_texture_updated_ = false;
}

const plug::Texture& Canvas::getTexture (void) const {

    const_cast <Canvas&> (*this).update_plug_texture ();

    //--------------------------------------------------

    return *plug_texture_;
}

//--------------------------------------------------

void Canvas::update_plug_texture (void) {

    if (is_plug_texture_updated_) return;

    //--------------------------------------------------

    delete plug_texture_;
    plug_texture_ = &::getTexture (*main_texture_);

    //--------------------------------------------------

    is_plug_texture_updated_ = true;
}

//--------------------------------------------------


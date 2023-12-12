#ifndef CLASS_CANVAS_HPP_INCLUDED
#define CLASS_CANVAS_HPP_INCLUDED
//--------------------------------------------------

#include "Plug/Canvas/Canvas.h"

#include "Impl/RenderTarget/SdlRenderTarget/RenderTarget.h"
#include "Impl/Canvas/SelectionMask.h"

//--------------------------------------------------

class Canvas: public plug::Canvas {

  public:

    const plug::Color DEFAULT_CANVAS_COLOR;

    //--------------------------------------------------

    Canvas (const int width, const int height);
    Canvas (const char* path);

    ~Canvas (void);

    Canvas    (const Canvas&) = delete;
    operator= (const Canvas&) = delete;

    //--------------------------------------------------

    void draw (const plug::VertexArray& vertex_array)                               override;
    void draw (const plug::VertexArray& vertex_array, const plug::Texture& texture) override;

    plug::Vec2d getSize (void) const override;
    void        setSize (const plug::Vec2d& size) override;

    plug::SelectionMask& getSelectionMask (void) override;

    plug::Color getPixel (size_t x, size_t y)                     const override;
    void        setPixel (size_t x, size_t y, const plug::Color& color) override;

    const plug::Texture& getTexture (void) const override;

//--------------------------------------------------

  private:

    MyRenderTexture* main_texture_;
    plug::Texture*   plug_texture_;
    bool   is_plug_texture_updated;

    plug::SelectionMask* selection_mask_;

    //--------------------------------------------------

    Canvas (void);

    void update_plug_texture (void);
};



//--------------------------------------------------
#endif


//--------------------------------------------------

#include "Impl/LayoutBox/LayoutBox.h"

#include "widgets/hpp/widgets.hpp"

//--------------------------------------------------

Widget_Decorator::Widget_Decorator (My_Widget& decorated):
        My_Widget (LayoutBox ()),

        decorated_ (decorated) {}

//--------------------------------------------------

void Widget_Decorator::render (plug::RenderTarget& target, plug::TransformStack& stack) {

    decorated_.render (target, stack);
}

void Widget_Decorator::onEvent (const plug::Event& event, plug::EHC& context) {

    decorated_.onEvent (event, context);
}

//--------------------------------------------------

void Widget_Decorator::onParentUpdate (const plug::LayoutBox& parent_box) {

    onParentUpdate (parent_box);
}

//--------------------------------------------------

plug::LayoutBox& Widget_Decorator::getLayoutBox (void) {

    return decorated_.getLayoutBox ();
}

const plug::LayoutBox& Widget_Decorator::getLayoutBox (void) const {

    return decorated_.getLayoutBox ();
}

void Widget_Decorator::setLayoutBox (const plug::LayoutBox& box) {

    decorated_.setLayoutBox (box);
}

//--------------------------------------------------


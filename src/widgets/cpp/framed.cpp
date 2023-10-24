

//--------------------------------------------------

#include "../hpp/widgets.hpp"

//--------------------------------------------------

Framed_Window::Framed_Window (Window* window):
        window_ (window),
        frame_  () {}


Window_Frame::Window_Frame (const Window& model):
        
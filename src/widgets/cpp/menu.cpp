

//--------------------------------------------------

#include "widgets/hpp/widgets.hpp"

//--------------------------------------------------

Window_Menu::Window_Menu (Point2D position, Vector2D size):
        Button_Manager (*new Colored_Window (position, size, C_GRAY), 20, 0) {}

//--------------------------------------------------

void Window_Menu::add_menu_button (const char* name, Button_Manager& controlled) {

    (void) name;

    //--------------------------------------------------

    Point2D  position = get_new_button_position ();
    position.y += Window_Frame::DEFAULT_FRAME_HEIGHT;
    Vector2D size     = get_button_size ();

    Window* model  = new Colored_Window (position, size, C_DARK_GRAY);
    Button* button = new Show_Button (*model, controlled);

    add_button (*button);

    //--------------------------------------------------

    Point2D controlled_position = position.move_copy (my_transform_.get_offset ());
            controlled_position.y -= controlled.get_size ().y;

    controlled.set_position (controlled_position);
}


Vector2D Window_Menu::get_button_size (void) {

    Vector2D size = Button_Manager::get_button_size ();

    //--------------------------------------------------

    size.y = 30;

    //--------------------------------------------------

    return size;
}

//--------------------------------------------------


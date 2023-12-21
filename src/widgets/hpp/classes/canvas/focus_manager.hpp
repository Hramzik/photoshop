#ifndef CLASS_CANVAS_FOCUS_MANAGER_HPP_INCLUDED
#define CLASS_CANVAS_FOCUS_MANAGER_HPP_INCLUDED
//--------------------------------------------------

#include "observer/hpp/observer.hpp"

//--------------------------------------------------

// observer for Canvas_Viewers,
// stores active canvas
class Canvas_Focus_Manager: public Observer {

  public:

    Canvas_Focus_Manager (void);

    //--------------------------------------------------

    void register_canvas_viewer (Canvas_Viewer& viewer);
    plug::Canvas* get_active_canvas (void);

    //--------------------------------------------------

    void get_updated (Observable& initiator) override;

  private:

    Canvas_Viewer* active_canvas_viewer_; 
}; 

//--------------------------------------------------
#endif
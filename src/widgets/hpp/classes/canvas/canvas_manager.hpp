#ifndef CLASS_CANVAS_MANAGER_HPP_INCLUDED
#define CLASS_CANVAS_MANAGER_HPP_INCLUDED
//--------------------------------------------------

#include "focus_manager.hpp"

//--------------------------------------------------

// observer for Canvas_Viewers,
// handles canvas closing

// also is a Canvas_Focus_Manager
class Canvas_Manager: public Canvas_Focus_Manager {

  public:

    Canvas_Manager (void);

    //--------------------------------------------------

    void save_active_canvas  (void);
    void clear_active_canvas (void);

    void close_canvas_viewer (Canvas_Viewer& viewer);

    //--------------------------------------------------

    void get_updated (Observable& initiator) override;
};

//--------------------------------------------------
#endif
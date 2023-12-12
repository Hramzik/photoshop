#ifndef TOOL_SELECTION_ACTION_HPP_INCLUDED
#define TOOL_SELECTION_ACTION_HPP_INCLUDED
//--------------------------------------------------

#include "tools/hpp/tools.hpp"

#include "widgets/hpp/classes/actions/action.hpp"

//--------------------------------------------------

class Tool_Selection_Action: public Action {

  public:

    Tool_Selection_Action (Tool_Palette& palette, int tool_id);

    //--------------------------------------------------

    void act (void) override;

  private:

    int tool_id_;
    Tool_Palette& palette_;
};


//--------------------------------------------------
#endif
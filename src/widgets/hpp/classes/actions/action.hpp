#ifndef CLASS_ACTION_HPP_INCLUDED
#define CLASS_ACTION_HPP_INCLUDED
//--------------------------------------------------


class Action {

  public:

    virtual ~Action (void) = default;

    virtual void act        (void);
    void         operator() (void);
};


//--------------------------------------------------
#endif
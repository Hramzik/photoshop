#ifndef CLASS_OBSERVABLE_HPP_INCLUDED
#define CLASS_OBSERVABLE_HPP_INCLUDED
//--------------------------------------------------

#include <vector>

//--------------------------------------------------

class Observer;

//--------------------------------------------------

class Observable {

  public:

    void attach_observer (Observer& observer);
    //void detach (Observer& observer);

  protected:

    void notify_observers (void);

//--------------------------------------------------

  private:

    std::vector <Observer*> observers_;
};

//--------------------------------------------------
#endif
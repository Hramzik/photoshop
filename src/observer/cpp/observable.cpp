
//--------------------------------------------------

#include "observer/hpp/observer.hpp"

//--------------------------------------------------

void Observable::attach_observer (Observer& observer) {

    observers_.push_back (&observer);
}

void Observable::notify_observers (void) {

    for (auto i_observer : observers_) {

        if (!i_observer) continue;

        //--------------------------------------------------

        i_observer->get_updated (*this);
    }
}

//--------------------------------------------------


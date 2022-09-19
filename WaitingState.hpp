//
// Created by Cleonia on 18.09.2022.
//

#ifndef SLOT_MACHINE_WAITINGSTATE_HPP
#define SLOT_MACHINE_WAITINGSTATE_HPP

#include "StateInterface.hpp"

class WaitingState : public StateInterface {
public:
    WaitingState(Button *button, Drum *drum);

    int  getState();
    void render();
};


#endif //SLOT_MACHINE_WAITINGSTATE_HPP

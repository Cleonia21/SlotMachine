//
// Created by Cleonia on 18.09.2022.
//

#ifndef SLOT_MACHINE_ROTATIONSTATE_HPP
#define SLOT_MACHINE_ROTATIONSTATE_HPP

#include "StateInterface.hpp"

class RotationState : public StateInterface {
public:
    RotationState(Button *button, Drum *drum);

    int  getState();
    void render();
private:
    Uint32 timer;
    Uint32 timeForStop;
};


#endif //SLOT_MACHINE_ROTATIONSTATE_HPP

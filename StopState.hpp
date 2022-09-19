//
// Created by Cleonia on 18.09.2022.
//

#ifndef SLOT_MACHINE_STOPSTATE_HPP
#define SLOT_MACHINE_STOPSTATE_HPP

#include "StateInterface.hpp"

class StopState : public StateInterface {
public:
    StopState(Button *button, Drum *drum);

    int  getState();
    void render();

private:
    bool stopFlag;
};


#endif //SLOT_MACHINE_STOPSTATE_HPP

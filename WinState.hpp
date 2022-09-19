//
// Created by Cleonia on 18.09.2022.
//

#ifndef SLOT_MACHINE_WINSTATE_HPP
#define SLOT_MACHINE_WINSTATE_HPP

#include "StateInterface.hpp"

class WinState : public StateInterface {
public:
    WinState(Button *button, Drum *drum);

    int  getState();
    void render();
};


#endif //SLOT_MACHINE_WINSTATE_HPP

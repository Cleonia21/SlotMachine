//
// Created by Cleonia on 18.09.2022.
//

#ifndef SLOT_MACHINE_STATEINTERFACE_HPP
#define SLOT_MACHINE_STATEINTERFACE_HPP

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "slot_machine.h"
#include "Texture.hpp"
#include "Button.hpp"
#include "Drum.hpp"

class StateInterface {
public:
    StateInterface(Button *button, Drum *drum);

    virtual ~StateInterface();

    //Returns what state to enable on the next frame (next or current)
    virtual int  getState() = 0;
    //Renders elements inherent in the state
    virtual void render() = 0;

protected:
    Button *button;
    Drum *drum;
};

#endif //SLOT_MACHINE_STATEINTERFACE_HPP

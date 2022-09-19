//
// Created by Cleonia on 18.09.2022.
//

#include "StateInterface.hpp"

StateInterface::StateInterface(Button *_button, Drum *_drum) {
    button = _button;
    drum = _drum;
}

StateInterface::~StateInterface() = default;

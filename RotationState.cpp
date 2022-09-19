//
// Created by Cleonia on 18.09.2022.
//

#include "RotationState.hpp"

RotationState::RotationState(Button *button, Drum *drum)
        : StateInterface(button, drum) {}

int RotationState::getState() {
    if (button->getState())
        return 2;
    return 1;
}

void RotationState::render() {
    drum->acceleration();
}

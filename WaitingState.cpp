//
// Created by Cleonia on 18.09.2022.
//

#include "WaitingState.hpp"

WaitingState::WaitingState(Button *button, Drum *drum)
        : StateInterface(button, drum) {}

int WaitingState::getState() {
    if (button->getState())
        return 1;
    return 0;
}

void WaitingState::render() {
    drum->render();
}

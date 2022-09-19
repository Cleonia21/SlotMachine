//
// Created by Cleonia on 18.09.2022.
//

#include "WinState.hpp"

WinState::WinState(Button *button, Drum *drum)
        : StateInterface(button, drum) {}

int WinState::getState() {
    if (button->getState())
        return 0;
    return 3;
}

void WinState::render() {
    drum->renderScore();
}

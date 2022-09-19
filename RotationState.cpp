//
// Created by Cleonia on 18.09.2022.
//

#include "RotationState.hpp"

RotationState::RotationState(Button *button, Drum *drum)
        : StateInterface(button, drum) {
            timer = 0;
            timeForStop = 10 * 1000;
        }

int RotationState::getState() {
    if (timer == 0)
        timer = SDL_GetTicks();
    if (button->getState() || timer + timeForStop < SDL_GetTicks()) {
        timer = 0;
        return 2;
    }
    return 1;
}

void RotationState::render() {
    drum->acceleration();
}

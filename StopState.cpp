//
// Created by Cleonia on 18.09.2022.
//

#include "StopState.hpp"

StopState::StopState(Button *button, Drum *drum)
        : StateInterface(button, drum) {
    stopFlag = false;
}

int  StopState::getState() {
    if (stopFlag) {
        stopFlag = false;
        return 3;
    }
    return 2;
}

void StopState::render() {
    if (drum->deceleration())
        stopFlag = true;
}
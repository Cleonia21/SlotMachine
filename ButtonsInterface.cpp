//
// Created by Cleonia on 17.09.2022.
//

#include "ButtonsInterface.hpp"

ButtonsInterface::ButtonsInterface(SDL_Renderer* _render, SDL_Rect &_buttonsViewport) {
    gameRender = _render;
    buttonsViewport = _buttonsViewport;

    startTexture = nullptr;
    endTexture = nullptr;
}

void ButtonsInterface::init() {
    startTexture = new Texture(gameRender);
    endTexture = new Texture(gameRender);

    int stepX = buttonsViewport.w / 10;
    int stepY = buttonsViewport.h / 10;

    startTexture->loadFromFile("img/Start.png", stepX * 8, stepY * 3);
    endTexture->loadFromFile("img/Stop.png", stepX * 8, stepY * 3);

    startButton.init(startTexture, stepX + buttonsViewport.x, stepY + buttonsViewport.y);
    endButton.init(endTexture, stepX + buttonsViewport.x, stepY * 6 + buttonsViewport.y);
}

void ButtonsInterface::handleEvent(SDL_Event* e) {
    startButton.handleEvent(e);
    endButton.handleEvent(e);
}

void ButtonsInterface::render() {
    startButton.render();
    endButton.render();
}

Button &ButtonsInterface::getStart() {
    return startButton;
}

Button &ButtonsInterface::getEnd() {
    return endButton;
}

ButtonsInterface::~ButtonsInterface() = default;

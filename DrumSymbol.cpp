//
// Created by Cleonia on 16.09.2022.
//

#include "DrumSymbol.hpp"

DrumSymbol::DrumSymbol() {
    texture = nullptr;
}

void DrumSymbol::init(Texture *_texture, int _posX, int _posY, SDL_Rect &_viewport,
                      DrumSymbol *_beforeSymbol, int _type) {
    texture = _texture;
    posX = _posX;
    posY = _posY;
    viewport = _viewport;
    beforeSymbol = _beforeSymbol;
    type = _type;
}

void DrumSymbol::alignment() {
    if (posY <= viewport.y && posY + texture->getHeight() > viewport.y) {
        beforeSymbol->posY = posY - beforeSymbol->texture->getHeight();
    }
}

int DrumSymbol::move(int velocity) {
    render();

    posY += velocity;
    return 0;
}

void DrumSymbol::render() {
    //If the texture is in the render area
    if (posY + texture->getHeight() > viewport.y && posY < viewport.y + viewport.h) {
        //If needed to display the top of the texture
        if (posY < viewport.y) {
            SDL_Rect clip = {
                    0,
                    viewport.y - posY,
                    texture->getWidth(),
                    posY + texture->getHeight() - viewport.y,
            };
            texture->render(posX, viewport.y, &clip);
        }
        //If needed to display the bottom of the texture
        else if (posY + texture->getHeight() > viewport.y + viewport.h) {
            SDL_Rect clip = {
                    0,
                    0,
                    texture->getWidth(),
                    viewport.y + viewport.h - posY,
            };
            texture->render(posX, posY, &clip);
        }
        //If needed to display the entire texture
        else {
            texture->render(posX, posY);
        }
    }
}

int DrumSymbol::getType() const {
    return type;
}

int DrumSymbol::getPosY() const {
    return posY;
}

DrumSymbol::~DrumSymbol() = default;

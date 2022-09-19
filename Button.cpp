//
// Created by Cleonia on 15.09.2022.
//

#include "Button.hpp"

Button::Button() {
    texture = nullptr;
}

Button::Button(Texture *_texture, int x, int y)
{
    init(_texture, x, y);
}

void Button::init(Texture *_texture, int x, int y) {
    position.x = x;
    position.y = y;
    texture = _texture;

    state = false;
}

void Button::handleEvent( SDL_Event* e )
{
    state = false;

	//If mouse event happened
	if(e->type == SDL_MOUSEBUTTONDOWN) {
        //Get mouse positionController
        int x, y;
        SDL_GetMouseState(&x, &y);

        if (x < position.x)
            state = false;
        else if (x > position.x + texture->getWidth())
            state = false;
        else if (y < position.y)
            state = false;
        else if (y > position.y + texture->getHeight())
            state = false;
        else
            state = true;
    }
    if (!state)
        texture->setColor(255, 255, 255);
    if (state)
        texture->setColor(1, 1, 1);
}

void Button::render()
{
	texture->render( position.x, position.y);
}

bool Button::getState() const {
    return state;
}

Button::~Button() = default;

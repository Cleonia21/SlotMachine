//
// Created by Cleonia on 15.09.2022.
//

#ifndef SLOT_MACHINE_BUTTON_HPP
#define SLOT_MACHINE_BUTTON_HPP

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "Texture.hpp"

//The mouse button
class Button
{
public:
    //Constructor for an empty object. before using the object, you must call init() function.
    Button();

	//Initializes internal variables
	Button(Texture *texture, int x, int y);

    //Initializes internal variables
    void init(Texture *texture, int x, int y);

    //Deallocates memory
    ~Button();

	//Handles mouse event
    void handleEvent( SDL_Event* e );

	//Shows button sprite
	void render();

    //whether the button was state
    bool getState() const;

private:
	//Top left positionController
	SDL_Point position;

    //Was the button state
    bool state;

	//Texture for render
	Texture *texture;
};


#endif //SLOT_MACHINE_BUTTON_HPP

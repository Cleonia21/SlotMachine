//
// Created by Cleonia on 17.09.2022.
//

#ifndef SLOT_MACHINE_BUTTONSINTERFACE_HPP
#define SLOT_MACHINE_BUTTONSINTERFACE_HPP

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "slot_machine.h"
#include "Texture.hpp"
#include "Button.hpp"

class ButtonsInterface {
public:
    //Initializes internal variables. Before using the object, you must call init() function.
    ButtonsInterface(SDL_Renderer* _render, SDL_Rect &buttonsViewport);

    //Initializes internal variables
    void init();

    //Deallocates memory
    ~ButtonsInterface();

    //Handles mouse event
    void handleEvent(SDL_Event* e);

    //Show buttons sprite
    void render();

    //Returns the used buttons
    Button &getStart();
    Button &getEnd();

private:
    // Buttons for render
    Button startButton;
    Button endButton;

    // Texture for buttons
    Texture *startTexture;
    Texture *endTexture;

    // Button render area
    SDL_Rect buttonsViewport;

    //The window renderer
    SDL_Renderer* gameRender;
};


#endif //SLOT_MACHINE_BUTTONSINTERFACE_HPP

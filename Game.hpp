//
// Created by Cleonia on 15.09.2022.
//

#ifndef SLOT_MACHINE_GAME_HPP
#define SLOT_MACHINE_GAME_HPP

#include <iostream>
#include <chrono>
#include <thread>
#include <string>
#include <exception>

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "Texture.hpp"
#include "ButtonsInterface.hpp"
#include "Drum.hpp"
#include "StateInterface.hpp"
#include "WaitingState.hpp"
#include "RotationState.hpp"
#include "StopState.hpp"
#include "WinState.hpp"
#include "slot_machine.h"

class Game {
public:

    //Constructor for an empty object. before using the object, you must call init() function.
	Game();

    //Deallocates memory
	~Game();

    //Initializes internal variables
    void init();

    //Main game loop
    void startGame();

private:
    //Initialize windows for game elements
    void initViewports();

    //Clears and draws the window every frame
    void clearScreen();
    void updateScreen();

    //Variables needed to draw and display the window
	SDL_Window* window;
	SDL_Renderer* render;

    //Windows for game elements
    SDL_Rect buttonsViewport;
    SDL_Rect drumViewport;
};


#endif //SLOT_MACHINE_GAME_HPP

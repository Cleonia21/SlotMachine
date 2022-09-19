//
// Created by Cleonia on 16.09.2022.
//

#ifndef SLOT_MACHINE_DRUM_HPP
#define SLOT_MACHINE_DRUM_HPP

#include "/usr/local/include/SDL2/SDL.h"
#include "/usr/local/include/SDL2/SDL_image.h"
#include "Texture.hpp"
#include "slot_machine.h"
#include "DrumSymbol.hpp"

#include <unistd.h>
#include <string>
#include <cstdlib>
#include <random>
#include <algorithm>

//Represents the necessary variables for calculating the move
struct VelocityParam {
    float velocity;
    float velocityStep;
    float velocityMax;
    //To control the alignment of the drum elements along the edges
    uint positionController;
};

class Drum {
public:
    //Constructor for create object. Before using the object, you must call init() function.
    Drum(SDL_Renderer* render, SDL_Rect &_viewport);

    //Deallocates memory
    ~Drum();

    //Initializes internal variables
    void init();

    //Accelerates and render drum
    void acceleration();

    //Decelerates and render drum
    bool deceleration();

    //Displays accumulated points
    void renderScore();

    //Render drum
    void render();

private:
    //Moves elements on the drum
    void move();

    //Calculates score
    void calculateScore();

    //Initializes velocity parameters with random values
    void velocityInit();

    //Changes velocity
    void velocityChange(float direction);

    //Textures for elements by type
    Texture texture[4];

    //The window renderer
    SDL_Renderer *gameRender;

    //Window defining rendering boundaries
    SDL_Rect viewport;

    //Speed settings for each line
    VelocityParam *velocity;

    //Array of elements
    DrumSymbol *symbols;

    int lineNum;
    int elemNum;
    int elemH;
    int score;
};


#endif //SLOT_MACHINE_DRUM_HPP

//
// Created by Cleonia on 16.09.2022.
//

#ifndef SLOT_MACHINE_DRUMSYMBOL_HPP
#define SLOT_MACHINE_DRUMSYMBOL_HPP

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "Texture.hpp"
#include "slot_machine.h"

class DrumSymbol {
public:
    //Constructor for an empty object. before using the object, you must call init() function.
    DrumSymbol();

    //Deallocates memory
    ~DrumSymbol();

    //Initializes internal variables
    void init(Texture *texture, int posX, int posY, SDL_Rect &_viewport, DrumSymbol *_beforeSymbol, int type);

    //Moves the bottom object on the screen to the top of the screen for cyclic rendering
    void alignment();

    //Moves and renders an object
    int move(int velocity);

    //Renders an object
    void render();

    int getType() const;
    int getPosY() const;

private:
    //Texture for render
    Texture *texture;

    //Type of object
    int type;

    //Object position points
    int posX, posY;

    //Window defining rendering boundaries
    SDL_Rect viewport;

    //Character following an object on the screen
    DrumSymbol *beforeSymbol;
};


#endif //SLOT_MACHINE_DRUMSYMBOL_HPP

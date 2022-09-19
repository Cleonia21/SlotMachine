//
// Created by Cleonia on 15.09.2022.
//

#ifndef SLOT_MACHINE_TEXTURE_HPP
#define SLOT_MACHINE_TEXTURE_HPP

#include <iostream>
#include "/usr/local/include/SDL2/SDL.h"
#include "/usr/local/include/SDL2/SDL_image.h"

//Texture wrapper class
class Texture
{
public:
    //Constructor for an empty object. Before using the object, you must call init() function.
    Texture();

    //Initializes internal variables
    Texture(SDL_Renderer *_render);

	//Deallocates memory
	~Texture();

    //Initializes variables
    void init(SDL_Renderer *_render);

	//Loads image at specified path
	bool loadFromFile(const std::string& path, int _width, int _height);

	//Renders texture at given point
	void render( int x, int y, SDL_Rect* clip = nullptr);

    //Modulate texture
    void setColor( Uint8 red, Uint8 green, Uint8 blue );

    int getWidth() const;
	int getHeight() const;

private:
	//Deallocates texture
	void free();

	//The actual hardware texture
	SDL_Texture* texture;

	//The window renderer
	SDL_Renderer* renderer;

	//Image dimensions
	int width;
	int height;
};


#endif //SLOT_MACHINE_TEXTURE_HPP

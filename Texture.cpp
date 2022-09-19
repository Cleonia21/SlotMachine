//
// Created by Cleonia on 15.09.2022.
//

#include "Texture.hpp"

Texture::Texture() {
    texture = nullptr;
}

Texture::Texture(SDL_Renderer *_render) {
    init(_render);
}

void Texture::init(SDL_Renderer *_render) {
    renderer = _render;
    texture = nullptr;
    width = 0;
    height = 0;
}

Texture::~Texture() {
    free();
}

bool Texture::loadFromFile(const std::string& path, int _width, int _height) {
    //Get rid of preexisting texture
    free();

    //Load image at specified path
    SDL_Surface *loadedSurface = IMG_Load(path.c_str());
    if (loadedSurface == nullptr)
        throw std::runtime_error("Unable to load image " + path + "! SDL_image Error: " + std::string(IMG_GetError()));

    //Creating a surface template of the desired size
    SDL_Surface *emptySurface = SDL_CreateRGBSurfaceWithFormat(0, _width, _height, 32, SDL_PIXELFORMAT_RGBA32);
    if (emptySurface == nullptr)
        throw std::runtime_error("Unable to create texture! SDL_image Error: " + std::string(IMG_GetError()));

    //Apply the image stretched
    SDL_Rect stretchRect = {
            0,
            0,
            _width,
            _height
    };

    //Scaled copy of the surface to the target surface.
    SDL_UpperBlitScaled(loadedSurface, nullptr, emptySurface, &stretchRect);

    //Create texture from surface pixels
    texture = SDL_CreateTextureFromSurface(renderer, emptySurface);
    if (texture == nullptr)
        throw std::runtime_error("Unable to create texture from " + path + "! SDL_image Error: " + std::string(IMG_GetError()));

    //Get image dimensions
    width = emptySurface->w;
    height = emptySurface->h;

    //Get rid of old loaded surface
    SDL_FreeSurface(loadedSurface);
    SDL_FreeSurface(emptySurface);

    //Return success
    return texture != nullptr;
}

void Texture::render( int x, int y, SDL_Rect* clip)
{
	//Set rendering space and render to screen
	SDL_Rect renderQuad = { x, y, width, height };

	//Set clip rendering dimensions
	if( clip != nullptr )
	{
		renderQuad.w = clip->w;
		renderQuad.h = clip->h;
	}

	//Render to screen
	SDL_RenderCopy( renderer, texture, clip, &renderQuad);
}

void Texture::setColor( Uint8 red, Uint8 green, Uint8 blue )
{
    SDL_SetTextureColorMod( texture, red, green, blue );
}

int Texture::getWidth() const
{
	return width;
}

int Texture::getHeight() const
{
	return height;
}

void Texture::free()
{
	if( texture != nullptr ) {
		SDL_DestroyTexture( texture );
	}
}

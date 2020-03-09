#include "TextureManager.h"
#include "Window.h"

SDL_Surface* Mara::TextureManager::LoadSurface(const char* fileName) {
	
	SDL_Surface* inputImage = IMG_Load(fileName);
	return inputImage;
	SDL_FreeSurface(inputImage);
}

#include "TextureComponent.h"


Mara::TextureComponent::TextureComponent()
	: surface(nullptr), sourceRect({ 0, 0, 0, 0 }), destinationRect({ 0, 0, 0, 0 }) {

	componentID = 1;
}

SDL_Rect Mara::TextureComponent::GetSourceRect() {

	return sourceRect;
}

SDL_Rect Mara::TextureComponent::GetDestinationRect() {

	return destinationRect;
}

SDL_Surface* Mara::TextureComponent::GetSurface() {

	return surface;
	SDL_FreeSurface(surface);
}

void Mara::TextureComponent::SetSourceRect(int x, int y, int height, int width) {

	sourceRect.x = x;
	sourceRect.y = y;
	sourceRect.h = height;
	sourceRect.w = width;
}

void Mara::TextureComponent::SetDestinationRect(int x, int y, int height, int width) {

	destinationRect.x = x;
	destinationRect.y = y;
	destinationRect.h = height;
	destinationRect.w = width;
}

void Mara::TextureComponent::SetDestinationRect(SDL_Rect dRect) {

	destinationRect = dRect;
}

void Mara::TextureComponent::SetSurface(const char* fileName) {

	surface = IMG_Load(fileName);
}

void Mara::TextureComponent::Init() {
}

void Mara::TextureComponent::Update() {
}

Mara::TextureComponent::~TextureComponent() {
}

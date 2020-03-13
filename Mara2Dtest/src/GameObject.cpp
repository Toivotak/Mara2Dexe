#include "GameObject.h"

Mara::GameObject::GameObject() {
}

SDL_Rect Mara::GameObject::GetSourceRect() {
	return sourceRect;
}

SDL_Rect Mara::GameObject::GetDestinationRect() {
	return destinationRect;
}

SDL_Surface* Mara::GameObject::GetSurface() {
	return surface;
	SDL_FreeSurface(surface);
}

bool Mara::GameObject::IsPlayable() {
	return playable;
}

bool Mara::GameObject::IsMoveable()
{
	return moveable;
}

void Mara::GameObject::SetSourceRect(int x, int y, int height, int width) {

	sourceRect.x = x;
	sourceRect.y = y;
	sourceRect.h = height;
	sourceRect.w = width;
}

void Mara::GameObject::SetDestinationRect(int x, int y, int height, int width) {

	destinationRect.x = x;
	destinationRect.y = y;
	destinationRect.h = height;
	destinationRect.w = width;
}

void Mara::GameObject::SetDestinationRect(SDL_Rect dRect) {

	destinationRect = dRect;
}

void Mara::GameObject::SetSurface(const char* fileName) {

	surface = IMG_Load(fileName);
}

void Mara::GameObject::SetPlayable(bool player) {
	playable = player;
}

void Mara::GameObject::SetMoveable(bool moving) {
	moveable = moving;
}

Mara::GameObject::~GameObject() {
}

#include "InputManager.h"

Mara::InputManager* Mara::InputManager::instance = NULL;

Mara::InputManager* Mara::InputManager::Instance() {

	if (instance == NULL) {
		instance = new InputManager();
	}
	return instance;
}

void Mara::InputManager::Release() {

	delete instance;
	instance = NULL;
}

bool Mara::InputManager::KeyDown(SDL_Scancode scanCode) {

	return keyboardStates[scanCode];
}

void Mara::InputManager::Update() {

	keyboardStates = SDL_GetKeyboardState(NULL);
}

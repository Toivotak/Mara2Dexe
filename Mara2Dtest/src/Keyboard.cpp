#include "Keyboard.h"

SDL_KeyboardEvent Mara::Keyboard::KeyEvent() {

	return SDL_KeyboardEvent();
}

void Mara::Keyboard::PrintKeyInfo(SDL_KeyboardEvent* key) {
	std::cout << key->keysym.scancode;
}

void Mara::Keyboard::KeyEvent2(Uint32 key) {
	
	/*
	if(SDL_KEYDOWN) {
		std::cout << "Key Down " << "\n";
		PrintKeyInfo(&event.key);
		switch (event.key.keysym.sym)
		{
		case SDLK_LEFT:  std::cout << "Key LEFT " << "\n";; break;
		case SDLK_RIGHT: std::cout << "Key RIGHT " << "\n";; break;
		case SDLK_UP:    std::cout << "Key UP " << "\n";; break;
		case SDLK_DOWN:  std::cout << "Key DOWN " << "\n";; break;
		}
	}
	SDL_KeyboardEvent event = *key;

	switch (key) {
		case SDL_KEYDOWN:
			std::cout << "Keydown";
			*/
			switch (key) {

				case SDLK_LEFT:  std::cout << "Key LEFT " << "\n"; break;
				case SDLK_RIGHT: std::cout << "Key RIGHT " << "\n"; break;
				case SDLK_UP:    std::cout << "Key UP " << "\n"; break;
				case SDLK_DOWN:  std::cout << "Key DOWN " << "\n"; break;
			}
			/*
			break;
		case SDL_KEYUP:
			std::cout << "Keyup";
			break;
	}*/


}

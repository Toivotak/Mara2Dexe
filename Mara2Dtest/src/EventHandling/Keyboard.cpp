#include "Keyboard.h"

Mara::Keyboard::Keyboard() { 

	
}

void Mara::Keyboard::GetEvent(SDL_Event event) {

	this->event = event;
}

SDL_Rect Mara::Keyboard::KeyEvent(GameObject gameObject) {

	//Vector2 move;
	SDL_Rect move = gameObject.GetDestinationRect();

	
	if (event.type == SDL_KEYDOWN) {

		switch (event.key.keysym.sym) {
			if (gameObject.IsMoveable()) {
				case SDLK_LEFT: {
					std::cout << "Key LEFT " << "\n";
					move.x--;
					return move;
					break;
				}
				case SDLK_RIGHT: {
					std::cout << "Key RIGHT " << "\n";
					move.x++;
					return move;
					break;
				}
				case SDLK_UP: {
					std::cout << "Key UP " << "\n";
					move.y--;
					return move;
					break;
				}
				case SDLK_DOWN: {
					std::cout << "Key DOWN " << "\n";
					move.y++;
					return move;
					break;
				}
			}
		}
	}
	return move;
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

Mara::Keyboard::~Keyboard() {
}

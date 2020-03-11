#pragma once
#include "GameInstance.h"

namespace Mara {

	class Keyboard {

	private:
		SDL_Event event;

	public:
		SDL_KeyboardEvent KeyEvent();
		void PrintKeyInfo(SDL_KeyboardEvent* key);
		void KeyEvent2(Uint32 key);
		
	};
}

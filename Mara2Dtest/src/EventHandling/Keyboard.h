#pragma once
#include "../GameInstance.h"
#include "Event.h"

namespace Mara {

	class Keyboard{

	private:
		SDL_Event event;
		SDL_Rect destinationRect;

	public:
		Keyboard();

		void GetEvent(SDL_Event event);
		SDL_Rect KeyEvent(GameObject gameObject);
		void KeyEvent2(Uint32 key);
		
		~Keyboard();
	};
}
